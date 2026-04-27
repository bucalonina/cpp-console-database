#include "Update.h"
#include <iostream>

Update::Update(const string& t, const string& setK, const string& setV, const string& whereK, const string& whereV)
:imeTab(t),setKol(setK), setVred(setV), whereKol(whereK), whereVred(whereV) {}

void Update::izvrsi(BazaPodataka& bp)
{
	cout << "UPDATE tabele: " << imeTab << endl;
}
