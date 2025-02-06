#include "headers.h"

int main()
{
	vector <Studentas> grupe;
	cout << "Iveskite studentu skaiciu: ";
	int n;
	cin >> n;

	//Ivedami studentu duomenis
	for (int i = 0; i < n; i++) {
		Studentas laikinas;
		cout << "Iveskite studento varda: ";
		cin >> laikinas.var;
		cout << "Iveskite studento pavarde: ";
		cin >> laikinas.pav;
		cout << "Iveskite studento pazymius: ";
		int paz;
		cin >> paz;
		while (paz >0 && paz<=10) {
			laikinas.paz.push_back(paz);
			cin >> paz;
		}
		cout << "Iveskite studento egzamino pazymi: ";
		cin >> laikinas.egz;

		grupe.push_back(laikinas);
	}

	//Skaiciuojami galutiniai pazymiai
	for (auto& n :grupe) {
		int sum = 0;
		for (auto m :n.paz) {
			sum += m;
		}
		n.gal = 0.4 * (sum / n.paz.size()) + 0.6 * n.egz;
	}

	//Isvedami studentu duomenys
	cout << "Pavarde\t\t" << " " << "Vardas\t\t" << " " << "Galutinis (Vid.)\t\t" << endl;
	for (auto n :grupe) {
		cout << n.pav << "\t\t" << n.var << "\t\t" << n.gal << endl;
	}
	system("pause");
	return 0;
}