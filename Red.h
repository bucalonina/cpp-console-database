#pragma once
#include <vector>
#include <string>

using namespace std;

class Red {
	vector<string> kljucevi;
public:
	Red() = default;
	Red(const vector<string>& s);

	const vector<string>& vratiKljuceve() const;

};