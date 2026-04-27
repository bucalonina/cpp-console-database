#include "Tabela.h"

Tabela::Tabela(vector<string>& kol) : kolone(kol) {}

void Tabela::dodajRed(const Red& r) { redovi.push_back(r); }

const vector<string>& Tabela::vratiKolone() const {
	return kolone;
}

const vector<Red>& Tabela::vratiRedove() const {
	return redovi;
}
