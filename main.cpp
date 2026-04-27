#include <deque>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "BazaPodataka.h"
#include "Parser.h"

using namespace std;

int main() {
	int izbor;
	string input, pom;
	vector<string> kolone;
	BazaPodataka* baza=nullptr;
	Parser parser;
	smatch match;
	Upit* upit = nullptr;

	try {
		while (true) {
			cout << "Dobro dosli u moj program za upravljanje relacionim bazama podataka! Uzivajte :)" << endl;
			cout << "1. Napisi upit" << endl;
			cout << "2. Ucitavanje baze podataka" << endl;
			cout << "3. Eksportovanje baze podataka" << endl;
			cout << "4. Napustanje programa" << endl;
			cout << "Vas izbor: ";
			cin >> izbor;
			cout << endl;

			switch (izbor)
			{
			case 1:
				if (baza == nullptr) {
					cout << "Kako zelite da se zove Vasa baza podataka?  ";
					cin >> pom;
					baza = new BazaPodataka(pom);
				}

				cout << "Pisite upit" << endl;
				cin >> input;
				if (input == "EXIT") break;
				cin >> pom;
				//if (pom == "EXIT") break; greska
				
				while (pom != "EXIT") {
					input += " ";
					input += pom;
					cin >> pom;
				}

				upit = parser.parse(input,*baza);
				if (upit) {
					upit->izvrsi(*baza);
					delete upit;
				}
				
				//cout << input;
				break;
			/*case 2:
				break;
			case 3:
				break;
			case 4:
				exit(0);*/
			default:
				exit(0);
			}
		}
		cout << endl << endl;
	}
	catch (exception& e) {
		cout << endl << e.what();
	}
	return 0;
}