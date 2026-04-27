#pragma once
#include "Red.h"

class Tabela {
	vector<string> kolone;
	vector<Red> redovi;

public:
	Tabela() = default;
	Tabela(vector<string>& kol);
	void dodajRed(const Red& r);
	const vector<string>& vratiKolone() const;
	const vector<Red>& vratiRedove() const;
};
