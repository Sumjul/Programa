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
	cout << "Iveskite studentu skaiciu. Jei skaicius nezinomas, iveskite 0: ";
	int kiekStud = skaicioTikrinimas(0, 1000);
	bool skZinomas = true;
	if (kiekStud == 0) {
		skZinomas = false;
		kiekStud = 1000;
	}

	//Ivedami studentu duomenis
	for (int i = 0; i < kiekStud; i++) {
		Studentas laikinas;
		cout << "Iveskite studento varda: ";
		cin >> laikinas.var;
		cout << "Iveskite studento pavarde: ";
		cin >> laikinas.pav;

		cout << "Iveskite studento atliktu namu darbu skaiciu. Jei skaicius nezinomas, iveskite 0: ";
		int kiekPaz = skaicioTikrinimas(0, 1000);
		bool pazZinomas = true;
		if (kiekPaz == 0) {
			pazZinomas = false;
			kiekPaz = 1000;
		}

		cout << "Iveskite studento visus atliktu namu darbu rezultatus. Noredami baigti, iveskite 0: ";
		if (pazZinomas == false) {
			while (true) {
				int pazymys = skaicioTikrinimas(0, 10);
				if (pazymys == 0) break;
				laikinas.paz.push_back(pazymys);
			}
		}
		else {
			for (int j = 0; j < kiekPaz; j++)
				laikinas.paz.push_back(skaicioTikrinimas(1, 10));
		}
		cout << "Iveskite studento egzamino pazymi: ";
		laikinas.egz = skaicioTikrinimas(1, 10);
		grupe.push_back(laikinas);
		cout << "------------------------------------------------------------" << endl;

		if (skZinomas == false) {
			cout << "Ar norite ivesti dar vieno studento duomenis? (1 - taip, 0 - ne): ";
			int arIvesti = skaicioTikrinimas(0, 1);
			if (arIvesti == 0) break;
		}
	}

	//Skaiciuojami galutiniai pazymiai
	for (auto& n :grupe) {
		double sum = 0;
		for (auto m :n.paz)
			sum += m;
		n.gal = 0.4 * (sum / n.paz.size()) + 0.6 * n.egz;

		std::sort(n.paz.begin(), n.paz.end());
		if (n.paz.size() % 2 == 0)
			n.med = (n.paz[n.paz.size() / 2 - 1] + n.paz[n.paz.size() / 2]) / 2.0;
		else n.med = n.paz[n.paz.size() / 2];
	}
	
	//Isvedami studentu duomenys
	cout << "Jei norite gauti vidurkius, iveskite 1, jei medianas - iveskite 2: ";
	int rezult = skaicioTikrinimas(1, 2);
	cout << endl << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas";
	if (rezult == 1) cout << std::setw(20) << "Galutinis (Vid.)" << endl;
	else if (rezult == 2 ) cout << std::setw(20) << "Galutinis (Med.)" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for (auto n :grupe) {
		cout << std::left << std::setw(15) << n.pav << std::setw(15) << n.var;
		if (rezult == 1) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.gal;
		else if (rezult == 2) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.med << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}