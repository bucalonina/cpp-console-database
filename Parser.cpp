#include "Parser.h"
#include "Select.h"
#include "Insert.h"
#include "Update.h"
#include "Delete.h"
#include <regex>
#include <iostream>

Upit* Parser::parse(string& upit, BazaPodataka& bp)
{
    smatch match;
    string imeT;
    string obrada;

    regex createTab(R"(\s*CREATE\s+TABLE\s+(\w+)\s*\(([^)]*)\)\s*;?\s*(.*))", regex::icase);
    if (regex_match(upit, match, createTab)) {
        string tabelaIme = match[1];

        vector<string> kolone;
        string kolString = match[2];
        upit = match[3];

        regex kolR("\\s*(\\w+)\\s*,?");
        auto kolPocetak = sregex_iterator(kolString.begin(), kolString.end(), kolR);
        auto kolKraj = sregex_iterator();
        for (auto i = kolPocetak; i != kolKraj; ++i) {
            kolone.push_back((*i)[1]);
        }
        bp.createTable(tabelaIme, kolone);  
    }
    


    regex dropTab(R"(\s*DROP\s+TABLE\s+(\w+)\s*;?\s*(.*))", regex::icase);
    if (regex_match(upit, match, dropTab)) {
        bp.dropTable(match[1]);
        upit = match[2];
    }

    //(?:\s+WHERE\s((.|\n)*?))?
    regex selectR(R"(\s*SELECT\s+(((?:.|\n))+?\s+FROM\s+(\w+)\s*(?:\s+WHERE\s((.|\n)*?))?;?\s*(.*)))", regex::icase);
    if (regex_match(upit, match, selectR)) {
        upit = match[1];

        //cout << "Upit: " << upit << endl;
        regex prvi(R"(^(([^;]+))\s*;\s*(.*)$)", regex::icase);
        if (regex_match(upit, match, prvi)) {
            obrada = match[2];
            upit = match[3];
        }
        //cout << "Obrada: " << obrada << endl;
        //cout << "Upit: " << upit << endl;
 
        return new Select(match[1], match[2], match[3]);
    }

    regex insertR("^INSERT\\s+INTO\\s+(\\w+)\\s+VALUES\\s*\\((.+)\\)$", regex::icase);
    if (regex_match(upit, match, insertR)) {
        return new Insert(match[1], match[2]);
    }

    regex updateR("", regex::icase);
    if (regex_match(upit, match, updateR)) {
        return new Update(match[1], match[2], match[3], match[4], match[5]);
    }

    regex deleteR("", regex::icase);
    if (regex_match(upit, match, deleteR)) {
        return new Delete(match[1], match[2], match[3]);
    }

    return nullptr;
}
