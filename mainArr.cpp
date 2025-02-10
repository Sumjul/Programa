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
	string* vardai = new string[30] {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Lukas", "Tadas", "Dainius", "Arvydas", "Vytautas", "Mindaugas", "Rokas", "Dovydas", "Paulius", "Tomas", "Andrius", "Giedrius", "Saulius", "Algirdas", "Simas", "Egidijus", "Justas", "Laurynas", "Martynas", "Edvinas", "Kestutis", "Julius", "Raimondas", "Deividas", "Arnoldas"};
	string* pavardes = new string[30] {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marciulionis", "Baltrusaitis", "Grigonis", "Kairys", "Landsbergis", "Zemaitis", "Mikalauskas", "Butkus", "Vaiciulis", "Bagdonas", "Salkauskas", "Daukantas", "Jankauskas", "Tamulevicius", "Skvernelis", "Navickas", "Kupcinskas", "Simkus", "Masiulis", "Zukauskas", "Cepaitis", "Vaitkus", "Urbsys", "Brazys", "Aleksandravicius", "Daugela"};
	Studentas* grupe = new Studentas[maxStud];
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
	int kiekStud = skaicioTikrinimas(0, maxStud);
	bool skZinomas = true;
	if (kiekStud == 0) {
		skZinomas = false;
		kiekStud = maxStud;
	}

	for (int i = 0; i < kiekStud; i++) {
		Studentas laikinas;
		laikinas.pazSk = 0;
		if (veiksmas == 1 || veiksmas == 2) {
			cout << "Iveskite studento varda: ";
			cin >> laikinas.var;
			cout << "Iveskite studento pavarde: ";
			cin >> laikinas.pav;
		}
		else if (veiksmas == 3) {
			laikinas.var = vardai[rand() % 30];
			laikinas.pav = pavardes[rand() % 30];
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
					laikinas.pazAr[laikinas.pazSk++] = pazymys;
				}
			}
			else {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus: ";
				for (int j = 0; j < kiekPaz; j++)
				laikinas.pazAr[laikinas.pazSk++] = skaicioTikrinimas(1, 10);
			}

			cout << "Iveskite studento egzamino pazymi: ";
			laikinas.egz = skaicioTikrinimas(1, 10);
			grupe[i] = laikinas;
			cout << "------------------------------------------------------------" << endl;
		}
		else if (veiksmas == 2 || veiksmas == 3) {
			int pazSk = rand() % 100 + 1;
			for (int j = 0; j < pazSk; j++)
				laikinas.pazAr[laikinas.pazSk++] = rand() % 10 + 1;
			laikinas.egz = rand() % 10 + 1;
			grupe[i] = laikinas;
		}

		if (skZinomas == false) {
			cout << "1 - ivesti dar vieno studento duomenis; 0 - baigti ivedima. ";
			int arIvesti = skaicioTikrinimas(0, 1);
			if (arIvesti == 0) {
				kiekStud = i + 1;
				break;
			}
		}
	}
	//Skaiciuojami galutiniai pazymiai
	for (int i = 0; i < kiekStud; i++) {
		Studentas& n = grupe[i];
		double sum = 0;
		for (int i = 0; i < n.pazSk; i++)
			sum += n.pazAr[i];
		n.gal = 0.4 * (sum / n.pazSk) + 0.6 * n.egz;

		std::sort(n.pazAr, n.pazAr + n.pazSk);
		if (n.pazSk % 2 == 0)
			n.med = (n.pazAr[n.pazSk / 2 - 1] + n.pazAr[n.pazSk / 2]) / 2.0;
		else n.med = n.pazAr[n.pazSk / 2];
	}
	//Isvedami studentu duomenys
	cout << "1 - gauti vidurkius; 2 - gauti medianas. ";
	int rezult = skaicioTikrinimas(1, 2);
	cout << endl << std::left << std::setw(20) << "Pavarde" << std::setw(15) << "Vardas";
	if (rezult == 1) cout << std::setw(20) << "Galutinis (Vid.)" << endl;
	else if (rezult == 2 ) cout << std::setw(20) << "Galutinis (Med.)" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < kiekStud; i++) {
		Studentas& n = grupe[i];
		cout << std::left << std::setw(20) << n.pav << std::setw(15) << n.var;
		if (rezult == 1) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.gal << endl;
		else if (rezult == 2) cout << std::setw(20) << std::fixed << std::setprecision(2) << n.med << endl;
	}
	cout << endl;
	system("pause");
	delete[] vardai;
    delete[] pavardes;
    delete[] grupe;
	return 0;
}