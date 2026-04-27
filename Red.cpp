#include "Red.h"

Red::Red(const vector<string>& s) : kljucevi(s) {}

const vector<string>& Red::vratiKljuceve() const
{
	return kljucevi;
}
