#pragma once
#include "Upit.h"
#include <string>

class Insert : public Upit {
	string imeTab;
	string vred;
public:
	Insert(const string& t, const string& vr);
	void izvrsi(BazaPodataka& bp) override;
};

