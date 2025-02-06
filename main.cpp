//h failas

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct Stud {
	string var = "a", pav = "b";
	vector <int> paz;
	double gal;
	int egz;
};

//Atskiras failas cpp

int main()
{
	vector <Stud> grupe;
	for (int i = 0; i < 1; i++) {
		Stud laik;
		cout << "Iveskite studento varda: ";
		cin >> laik.var;
		cout << "Iveskite studento pavarde: ";
		cin >> laik.pav;
		cout << "Iveskite studento pazymius: ";
		int paz;
		cin >> paz;
		while (paz >0 && paz<=10) {
			laik.paz.push_back(paz);
			cin >> paz;
		}
		cout << "Iveskite studento egzamino pazymi: ";
		cin >> laik.egz;
		grupe.push_back(laik);
	}
	for (auto &n : grupe) {
		int sum = 0;
		for (auto m : n.paz) {
			sum += m;
		}
		n.gal = 0.4 * (sum / n.paz.size()) + 0.6 * n.egz;
	}

	cout << "Pavarde\t\t" << " " << "Vardas\t\t" << " " << "Galutinis (Vid.)\t\t" << endl;
	for (auto n : grupe) {
		cout << n.var << "\t\t" << n.pav << "\t\t" << n.egz << "\t\t" << n.gal << endl;
	}
	return 0;
}