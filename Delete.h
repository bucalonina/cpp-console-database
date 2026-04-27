#pragma once
#include "Upit.h"

class Delete : public Upit {
	string imeTabele;
	string whereKol;
	string whereVred;

public:
	Delete(const string& t, const string& kol, const string& vr);
	void izvrsi(BazaPodataka& bp) override;
};

