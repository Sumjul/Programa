#include "global.h"

int NumberCheck (int min, int max) {
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
void Calculations(vector <Studentas>& grupe) {
	for (auto& n :grupe) {
		double sum = 0;
		for (auto m :n.paz)
			sum += m;
		n.gal = 0.4 * (sum / n.paz.size()) + 0.6 * n.egz;
		sort(n.paz.begin(), n.paz.end());
		if (n.paz.empty()) {
			n.med = 0;
			continue;
		}
		if (n.paz.size() % 2 == 0)
			n.med = (n.paz[n.paz.size() / 2 - 1] + n.paz[n.paz.size() / 2]) / 2.0;
		else n.med = n.paz[n.paz.size() / 2];
	}
}

void Output(vector <Studentas>& grupe, ostream &out) {
	cout << "1 - gauti vidurkius; 2 - gauti medianas. ";
	int rezult = NumberCheck(1, 2);
	cout << "Pairinkite rezultatu rusiavimo metoda: " << endl;
	cout << "1 - rusiuoti pagal varda (A-Z); 2 - rusiuoti pagal pavarde (A-Z); 3 - rusiuoti pagal galutini pazymi." << endl;
	int rusiavimas = NumberCheck(1, 3);
	if (rusiavimas == 1) sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {return a.var < b.var; });
	else if (rusiavimas == 2) sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {return a.pav < b.pav; });
	else if (rusiavimas == 3 && rezult == 1) sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {return a.gal > b.gal; });
	else if (rusiavimas == 3 && rezult == 2) sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {return a.med > b.med; });
	out << endl << left << setw(20) << "Pavarde" << setw(15) << "Vardas";
	if (rezult == 1) out << setw(20) << "Galutinis (Vid.)" << endl;
	else if (rezult == 2 ) out << setw(20) << "Galutinis (Med.)" << endl;
	out << "------------------------------------------------------------" << endl;
	for (auto n :grupe) {
		out << left << setw(20) << n.pav << setw(15) << n.var;
		if (rezult == 1) out << setw(20) << fixed << setprecision(2) << n.gal << endl;
		else if (rezult == 2) out << setw(20) << fixed << setprecision(2) << n.med << endl;
	}
}

void File(vector<Studentas>& grupe, string file1, string file2) {
	ifstream open(file1);
	while (!open) {
        cout << "Klaida: failas nerastas arba negali buti atidarytas. Iveskite failo pavadinima dar karta: " << endl;
        cin >> file1;
		open.open(file1);
    }
	string eil;
	getline(open, eil);
	while (getline(open, eil)) {
		std::istringstream iss(eil);
		Studentas laikinas;
		iss >> laikinas.var >> laikinas.pav;
		int pazymys;
		vector <int> pazymiai;
		while (iss >> pazymys)
			pazymiai.push_back(pazymys);
		if(!pazymiai.empty()) {
			laikinas.egz = pazymiai.back();
			pazymiai.pop_back();
			laikinas.paz = pazymiai;
		}
		grupe.push_back(laikinas);
	}
	open.close();
	Calculations(grupe);
	ofstream out(file2);
	Output(grupe, out);
	out.close();
	cout << "Duomenys nukopijuoti i faila: " << file2 << endl;
	cout << endl;
}

void ProgramEnd() {
	cout << "Paspauskite Enter, kad uzbaigtumete programos darba." << endl;
	cin.ignore();
	cin.get();
}

int main()
{
	vector <string> vardai = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Lukas", "Tadas", "Dainius", "Arvydas", "Vytautas", "Mindaugas", "Rokas", "Dovydas", "Paulius", "Tomas", "Andrius", "Giedrius", "Saulius", "Algirdas", "Simas", "Egidijus", "Justas", "Laurynas", "Martynas", "Edvinas", "Kestutis", "Julius", "Raimondas", "Deividas", "Arnoldas"};
	vector <string> pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marciulionis", "Baltrusaitis", "Grigonis", "Kairys", "Landsbergis", "Zemaitis", "Mikalauskas", "Butkus", "Vaiciulis", "Bagdonas", "Salkauskas", "Daukantas", "Jankauskas", "Tamulevicius", "Skvernelis", "Navickas", "Kupcinskas", "Simkus", "Masiulis", "Zukauskas", "Cepaitis", "Vaitkus", "Urbsys", "Brazys", "Aleksandravicius", "Daugela"};
	vector <Studentas> grupe;
	srand(time(NULL));
	cout << "Sveiki atvyke i pazymiu skaiciuokle! Pasirinkite veiksma spausdami skaiciu ir tada spauskite Enter." << endl;
	cout << "1 - pildyti duomenis rankiniu budu;" << endl;
	cout << "2 - generuoti pazymius;" << endl;
	cout << "3 - generuoti pazymius, vardus ir pavardes;" << endl;
	cout << "4 - nauduoti duomenis is failo;" << endl;
	cout << "5 - baigti darba." << endl;
	int veiksmas = NumberCheck(1, 5);
	if (veiksmas == 5) return 0;

	if (veiksmas == 4) {
		cout << "Iveskite failo pavadinima, is kurio bus nuskaitomi duomenys: ";
		string failas;
		cin >> failas;
		File(grupe, failas, "rezultatas.txt");
		ProgramEnd();
		return 0;
	}

	cout << "Iveskite studentu skaiciu (iveskite 0, jei skaicius yra nezinomas): ";
	int kiekStud = NumberCheck(0, maxStud);
	bool skZinomas = true;
	if (kiekStud == 0) {
		skZinomas = false;
		kiekStud = maxStud;
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
			int kiekPaz = NumberCheck(0, 100);
			bool pazZinomas = true;
			if (kiekPaz == 0) {
				pazZinomas = false;
				kiekPaz = 100;
			}
			if (pazZinomas == false) {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus (0 - baigti ivedima): ";
				while (true) {
					int pazymys = NumberCheck(0, 10);
					if (pazymys == 0) break;
					laikinas.paz.push_back(pazymys);
				}
			}
			else {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus: ";
				for (int j = 0; j < kiekPaz; j++)
					laikinas.paz.push_back(NumberCheck(1, 10));
			}

			cout << "Iveskite studento egzamino pazymi: ";
			laikinas.egz = NumberCheck(1, 10);
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
			int arIvesti = NumberCheck(0, 1);
			if (arIvesti == 0) break;
		}
	}
	Calculations(grupe);
	Output(grupe, cout);
	ProgramEnd();
	return 0;
}