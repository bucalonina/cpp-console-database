#pragma once
#include "Upit.h"

class Select : public Upit {
	string imeTabele;
	string whereKolona;
	string whereVr;
public:
	Select(const string& imeT, const string& kol = "", const string& vred = "");
	void izvrsi(BazaPodataka& bp) override;
};