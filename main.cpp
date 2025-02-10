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
	vector<string> vardai = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Lukas", "Tadas", "Dainius", "Arvydas", "Vytautas", "Mindaugas", "Rokas", "Dovydas", "Paulius", "Tomas", "Andrius", "Giedrius", "Saulius", "Algirdas", "Simas", "Egidijus", "Justas", "Laurynas", "Martynas", "Edvinas", "Kestutis", "Julius", "Raimondas", "Deividas", "Arnoldas"};
	vector<string> pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marciulionis", "Baltrusaitis", "Grigonis", "Kairys", "Landsbergis", "Zemaitis", "Mikalauskas", "Butkus", "Vaiciulis", "Bagdonas", "Salkauskas", "Daukantas", "Jankauskas", "Tamulevicius", "Skvernelis", "Navickas", "Kupcinskas", "Simkus", "Masiulis", "Zukauskas", "Cepaitis", "Vaitkus", "Urbsys", "Brazys", "Aleksandravicius", "Daugela"};
	vector <Studentas> grupe;
	srand(time(NULL));
	cout << "Sveiki atvyke i pazymiu skaiciuokle! Pasirinkite veiksma spausdami skaiciu ir tada spauskite Enter." << endl;
	cout << "1 - pildyti duomenis rankiniu budu;" << endl;
	cout << "2 - generuoti pazymius;" << endl;
	cout << "3 - generuoti pazymius, vardus ir pavardes;" << endl;
	cout << "4 - baigti darba." << endl;
	int veiksmas = skaicioTikrinimas(1, 4);
	if (veiksmas == 4) return 0;

	//Ivedami studentu duomenis
	cout << "Iveskite studentu skaiciu (iveskite 0, jei skaicius yra nezinomas): ";
	int kiekStud = skaicioTikrinimas(0, 1000);
	bool skZinomas = true;
	if (kiekStud == 0) {
		skZinomas = false;
		kiekStud = 1000;
	}

	for (int i = 0; i < kiekStud; i++) {
		Studentas laikinas;
		if (veiksmas == 1 || veiksmas == 2) {
			cout << "Iveskite studento varda: ";
			cin >> laikinas.var;
			cout << "Iveskite studento pavarde: ";
			cin >> laikinas.pav;
		}
		else if (veiksmas == 3) {
			laikinas.var = vardai[rand() % vardai.size()];
			laikinas.pav = pavardes[rand() % pavardes.size()];
		}

		if (veiksmas == 1) {
			cout << "Iveskite studento atliktu namu darbu kieki (iveskite 0, jei kiekis yra nezinomas): ";
			int kiekPaz = skaicioTikrinimas(0, 100);
			bool pazZinomas = true;
			if (kiekPaz == 0) {
				pazZinomas = false;
				kiekPaz = 100;
			}
			if (pazZinomas == false) {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus (0 - baigti ivedima): ";
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
		}
		else if (veiksmas == 2 || veiksmas == 3) {
			int kiekPaz = rand() % 100 + 1;
			for (int j = 0; j < kiekPaz; j++)
				laikinas.paz.push_back(rand() % 10 + 1);
			laikinas.egz = rand() % 10 + 1;
			grupe.push_back(laikinas);
		}

		if (skZinomas == false) {
			cout << "1 - ivesti dar vieno studento duomenis; 0 - baigti ivedima. ";
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
	cout << "1 - gauti vidurkius; 2 - gauti medianas. ";
	int rezult = skaicioTikrinimas(1, 2);
	cout << endl << std::left << std::setw(20) << "Pavarde" << std::setw(15) << "Vardas";
	if (rezult == 1) cout << std::setw(20) << "Galutinis (Vid.)" << endl;
	else if (rezult == 2 ) cout << std::setw(20) << "Galutinis (Med.)" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (auto n :grupe) {
		cout << std::left << std::setw(20) << n.pav << std::setw(15) << n.var;
		if (rezult == 1) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.gal << endl;
		else if (rezult == 2) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.med << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}