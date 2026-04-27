#pragma once
#include <map>
#include "Tabela.h"

class BazaPodataka {
	map<string, Tabela> tabele;
	string ime;

public:
	BazaPodataka(const string& imeBaze) : ime(imeBaze) {}
	void createTable(const string& ime, vector<string>& kolone);
	void dropTable(const string& ime);
	//Tabela& vratiTabelu(const string& ime);
	bool postojiTabela(const string& ime) const;
};
