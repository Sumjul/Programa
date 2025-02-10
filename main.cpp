#include "headers.h"

int skaicioTikrinimas (int min, int max) {
	int skaicius;
	while (true) {
		if (cin >> skaicius && skaicius >= min && skaicius <= max) {
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
	srand(time(NULL));
	cout << "Sveiki atvyke i studentu pazymiu skaiciuokle! " << endl;
	cout << "Noredami pildyti duomenis rankiniu budu - iveskite 1;" << endl;
	cout << "Generuoti pazymius - 2;" << endl;
	cout << "Generuoti pazymius, vardus ir pavardes - 3;" << endl;
	cout << "Baigti darba - 4." << endl;
	int veiksmas = skaicioTikrinimas(1, 4);
	if (veiksmas == 4) return 0;

	//Ivedami studentu duomenis
	cout << "Iveskite studentu skaiciu. Jei skaicius nezinomas, iveskite 0: ";
	int kiekStud = skaicioTikrinimas(0, 1000);
	bool skZinomas = true;
	if (kiekStud == 0) {
		skZinomas = false;
		kiekStud = 1000;
	}

	for (int i = 0; i < kiekStud; i++) {
		Studentas laikinas;
		cout << "Iveskite studento varda: ";
		cin >> laikinas.var;
		cout << "Iveskite studento pavarde: ";
		cin >> laikinas.pav;
		if (skZinomas == false && veiksmas == 2) {
			cout << "Ar norite ivesti dar vieno studento duomenis? (1 - taip, 0 - ne): ";
			int arIvesti = skaicioTikrinimas(0, 1);
			if (arIvesti == 0) break;
		}

		if (veiksmas == 1) {
			cout << "Iveskite studento atliktu namu darbu skaiciu. Jei skaicius nezinomas - iveskite 0: ";
			int kiekPaz = skaicioTikrinimas(0, 100);
			bool pazZinomas = true;
			if (kiekPaz == 0) {
				pazZinomas = false;
				kiekPaz = 100;
			}
			if (pazZinomas == false) {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus. Noredami baigti - iveskite 0: ";
				while (true) {
					int pazymys = skaicioTikrinimas(0, 10);
					if (pazymys == 0) break;
					laikinas.paz.push_back(pazymys);
				}
			}
			else {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus: ";
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
		if (veiksmas == 2 || veiksmas == 3) {
			int kiekPaz = rand() % 100 + 1;
			for (int j = 0; j < kiekPaz; j++)
				laikinas.paz.push_back(rand() % 10 + 1);
			laikinas.egz = rand() % 10 + 1;
			grupe.push_back(laikinas);
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
	cout << "Jei norite gauti vidurkius - iveskite 1; jei medianas - iveskite 2: ";
	int rezult = skaicioTikrinimas(1, 2);
	cout << endl << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas";
	if (rezult == 1) cout << std::setw(20) << "Galutinis (Vid.)" << endl;
	else if (rezult == 2 ) cout << std::setw(20) << "Galutinis (Med.)" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (auto n :grupe) {
		cout << std::left << std::setw(15) << n.pav << std::setw(15) << n.var;
		if (rezult == 1) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.gal << endl;
		else if (rezult == 2) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.med << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}