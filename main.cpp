#include "headers.h"

int main()
{
	vector <Studentas> grupe;
	cout << "Iveskite studentu skaiciu: ";
	int kiek;
	cin >> kiek;

	//Ivedami studentu duomenis
	for (int i = 0; i < kiek; i++) {
		Studentas laikinas;
		cout << "Iveskite studento varda: ";
		cin >> laikinas.var;
		cout << "Iveskite studento pavarde: ";
		cin >> laikinas.pav;
		cout << "Iveskite studento namu darbu rezultatus: ";
		int paz;
		cin >> paz;
		while (paz >0 && paz<=10) {
			laikinas.paz.push_back(paz);
			cin >> paz;
		}
		cout << "Iveskite studento egzamino pazymi: ";
		cin >> laikinas.egz;

		grupe.push_back(laikinas);
		cout << "------------------------------------------------------------" << endl;
	}

	//Skaiciuojami galutiniai pazymiai
	for (auto& n :grupe) {
		double sum = 0;
		for (auto m :n.paz) {
			sum += m;
		}
		n.gal = 0.4 * (sum / n.paz.size()) + 0.6 * n.egz;
	}

	//Isvedami studentu duomenys
	cout << endl << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (auto n :grupe) {
		cout << std::left << std::setw(15) << n.pav << std::setw(15) << n.var << std::setw(15) << std::fixed << std::setprecision(2) << n.gal << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}