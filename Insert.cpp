#include "Insert.h"
#include <iostream>

Insert::Insert(const string& t, const string& vr)
:imeTab(t),vred(vr) {}

void Insert::izvrsi(BazaPodataka& bp)
{
	cout << "Izvrsen INSERT u tabelu: " << imeTab << " sa vrednostima" << vred << endl;
}
