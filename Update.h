#pragma once
#include "Upit.h"

class Update :public Upit {
	string imeTab;
	string setKol;
	string setVred;
	string whereKol;
	string whereVred;
public:
	Update(const string& t, const string& setK, const string& setV, const string& whereK, const string& whereV);
	void izvrsi(BazaPodataka& bp) override;

};