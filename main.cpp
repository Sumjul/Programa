#include "headers.h"


int skaicioTikrinimas (int min, int max) {
	int skaicius;
	while (true) {
		cin >> skaicius;
		if (skaicius >= min && skaicius <= max) {
			break;
		} else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ivestis netinkama. Iveskite dar karta: ";
		}
	}
	return skaicius;
}
int main()
{
	vector <Studentas> grupe;
	cout << "Iveskite studentu skaiciu: ";
	int kiekStud;
	kiekStud = skaicioTikrinimas(1, 100);

	//Ivedami studentu duomenis
	for (int i = 0; i < kiekStud; i++) {
		Studentas laikinas;
		cout << "Iveskite studento varda: ";
		cin >> laikinas.var;
		cout << "Iveskite studento pavarde: ";
		cin >> laikinas.pav;

		cout << "Iveskite studento atliktu namu darbu skaiciu: ";
		int kiekPaz;
		kiekPaz = skaicioTikrinimas(1, 100);

		cout << "Iveskite studento visus atliktu namu darbu rezultatus: ";
		int paz;
		for (int j = 0; j < kiekPaz; j++) {
			laikinas.paz.push_back(skaicioTikrinimas(1, 10));
		}

		cout << "Iveskite studento egzamino pazymi: ";
		int egz;
		laikinas.egz = skaicioTikrinimas(1, 10);
		
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

		std::sort(n.paz.begin(), n.paz.end());
		if (n.paz.size() % 2 == 0) {
			n.med = (n.paz[n.paz.size() / 2 - 1] + n.paz[n.paz.size() / 2]) / 2.0;
		}
		else {
			n.med = n.paz[n.paz.size() / 2];
		}
	}

	//Isvedami studentu duomenys
	cout << endl << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.) /" << "Galutinis (Med.)" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for (auto n :grupe) {
		cout << std::left << std::setw(15) << n.pav << std::setw(15) << n.var << std::setw(20) << std::fixed << std::setprecision(2) << n.gal << std::setw(20) << std::fixed << std::setprecision(2) << n.med << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}