#pragma once
#include "BazaPodataka.h"

class Upit {
public:
	virtual void izvrsi(BazaPodataka& bp) = 0;
	virtual ~Upit() {}
};
