#include "BazaPodataka.h"
#include <iostream>

void BazaPodataka::createTable(const string& ime, vector<string>& kolone)
{
	tabele[ime] = Tabela(kolone);
	cout << "USPELAAA" << endl << endl;
}

void BazaPodataka::dropTable(const string& ime)
{
	tabele.erase(ime);
	cout << "Tabela " << ime << " je obrisana." << endl;
}

//Tabela& BazaPodataka::vratiTabelu(const string& ime)
//{
//	if (!postojiTabela) {
//		cout << "Tabela sa zadatim imenom ne postoji!" << endl;
//		return;
//	}
//	return tabele[ime];
//}

bool BazaPodataka::postojiTabela(const string& ime) const
{
	return tabele.find(ime) != tabele.end();
}
