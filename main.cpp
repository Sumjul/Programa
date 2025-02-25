#include "global.h"
class Timer {
private:
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<double>;
	std::chrono::time_point<hrClock> start;
public:
	Timer() : start { hrClock::now() } {}
	void reset() {
	start = hrClock::now();
	}
	double elapsed() const {
	return durationDouble (hrClock::now() - start).count();
	}
};

int NumberCheck (int min, int max) {
	int number;
	while (true) {
		if (cin >> number && number >= min && number <= max) {
			break;
		} else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ivestis netinkama. Iveskite dar karta: ";
		}
	}
	return number;
}
void Calculations(vector <Studentas>& group) {
	for (auto& final :group) {
		double sum = 0;
		for (auto temp :final.marks)
			sum += temp;
		final.average = 0.4 * (sum / final.marks.size()) + 0.6 * final.egzam;
		sort(final.marks.begin(), final.marks.end());
		if (final.marks.empty()) {
			final.median = 0;
			continue;
		}
		if (final.marks.size() % 2 == 0)
			final.median = (final.marks[final.marks.size() / 2 - 1] + final.marks[final.marks.size() / 2]) / 2.0;
		else final.median = final.marks[final.marks.size() / 2];
	}
}

void Output(vector <Studentas>& group, ostream &out) {
	cout << "1 - gauti vidurkius; 2 - gauti medianas. ";
	int rezult = NumberCheck(1, 2);
	cout << "Pairinkite rezultatu rusiavimo metoda: " << endl;
	cout << "1 - rusiuoti pagal varda (A-Z); 2 - rusiuoti pagal pavarde (A-Z); 3 - rusiuoti pagal galutini markymi." << endl;
	int rusiavimas = NumberCheck(1, 3);
	Timer outputTime;
	if (rusiavimas == 1) sort(group.begin(), group.end(), [](const Studentas &a, const Studentas &b) {return a.name < b.name; });
	else if (rusiavimas == 2) sort(group.begin(), group.end(), [](const Studentas &a, const Studentas &b) {return a.surname < b.surname; });
	else if (rusiavimas == 3 && rezult == 1) sort(group.begin(), group.end(), [](const Studentas &a, const Studentas &b) {return a.average > b.average; });
	else if (rusiavimas == 3 && rezult == 2) sort(group.begin(), group.end(), [](const Studentas &a, const Studentas &b) {return a.median > b.median; });
	out << endl << left << setw(20) << "Pavarde" << setw(15) << "Vardas";
	if (rezult == 1) out << setw(20) << "Galutinis (Vid.)" << endl;
	else if (rezult == 2 ) out << setw(20) << "Galutinis (Med.)" << endl;
	out << "------------------------------------------------------------" << endl;
	for (auto& final : group) {
		out << left << setw(20) << final.surname << setw(15) << final.surname;
		if (rezult == 1) out << setw(20) << fixed << setprecision(2) << final.average << endl;
		else if (rezult == 2) out << setw(20) << fixed << setprecision(2) << final.median << endl;
	}
	cout << "Rezultatu isvedimas uztruko: " << outputTime.elapsed() << " sekundziu. ";
}

void File(vector<Studentas>& group) {
	string readName;
	string line;
	bool fileLoaded = false;
	while (!fileLoaded) {
		cout << "Iveskite failo pavadinima, is kurio bus skaitomi duomenys: ";
		cin >> readName;
		Timer inputTime;
		ifstream input(readName);
		if (!input) {
			cout << "Klaida: failas nerastas arba negali buti atidarytas. Iveskite failo pavadinima dar karta: "<< endl;
		}
		else {
			fileLoaded = true;
			getline(input, line);
			while (getline(input, line)) {
				std::istringstream iss(line);
				Studentas temp;
				iss >> temp.name >> temp.surname;
				int mark;
				vector <int> markInput;
				while (iss >> mark)
					markInput.push_back(mark);
				if(!markInput.empty()) {
					temp.egzam = markInput.back();
					markInput.pop_back();
					temp.marks = markInput;
				}
				group.push_back(temp);
			}
			input.close();
			cout << "Rezultatu skaitymas uztruko: " << inputTime.elapsed() << " sekundziu. " << endl;
		
		}
	}	
	Calculations(group);
	string writeName = "rezultatas.txt";
	ofstream output(writeName);
	Output(group, output);
	output.close();
	cout << "Duomenys nukopijuoti i faila: " << writeName << endl;
}

void ProgramEnd() {
	cout << "Paspauskite Enter, kad uzbaigtumete programos darba." << endl;
	cin.ignore();
	cin.get();
}

int main()
{
	vector <string> names = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Lukas", "Tadas", "Dainius", "Arvydas", "Vytautas", "Mindaugas", "Rokas", "Dovydas", "Paulius", "Tomas", "Andrius", "Giedrius", "Saulius", "Algirdas", "Simas", "Egidijus", "Justas", "Laurynas", "Martynas", "Edvinas", "Kestutis", "Julius", "Raimondas", "Deividas", "Arnoldas"};
	vector <string> surnames = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marciulionis", "Baltrusaitis", "Grigonis", "Kairys", "Landsbergis", "Zemaitis", "Mikalauskas", "Butkus", "Vaiciulis", "Bagdonas", "Salkauskas", "Daukantas", "Jankauskas", "Tamulevicius", "Skvernelis", "Navickas", "Kupcinskas", "Simkus", "Masiulis", "Zukauskas", "Cepaitis", "Vaitkus", "Urbsys", "Brazys", "Aleksandravicius", "Daugela"};
	vector <Studentas> group;
	srand(time(NULL));
	cout << "Sveiki atvyke i markymiu skaiciuokle! Pasirinkite veiksma spausdami skaiciu ir tada spauskite Enter." << endl;
	cout << "1 - pildyti duomenis rankiniu budu;" << endl;
	cout << "2 - generuoti pazymius;" << endl;
	cout << "3 - generuoti pazymius, vardus ir pavardes;" << endl;
	cout << "4 - nauduoti duomenis is failo;" << endl;
	cout << "5 - baigti darba." << endl;
	int action = NumberCheck(1, 5);
	if (action == 5) return 0;

	if (action == 4) {
		File(group);
		ProgramEnd();
		return 0;
	}

	cout << "Iveskite studentu skaiciu (iveskite 0, jei skaicius yra nezinomas): ";
	int amountStud = NumberCheck(0, maxStud);
	bool amountStudKnown = true;
	if (amountStud == 0) {
		amountStudKnown = false;
		amountStud = maxStud;
	}

	for (int i = 0; i < amountStud; i++) {
		Studentas temp;
		if (action == 1 || action == 2) {
			cout << "Iveskite studento varda: ";
			cin >> temp.name;
			cout << "Iveskite studento pavarde: ";
			cin >> temp.surname;
		}
		else if (action == 3) {
			temp.name = names[rand() % names.size()];
			temp.surname = surnames[rand() % surnames.size()];
		}

		if (action == 1) {
			cout << "Iveskite studento atliktu namu darbu kieki (iveskite 0, jei kiekis yra nezinomas): ";
			int amountMarks = NumberCheck(0, 100);
			bool amountMarksKnown = true;
			if (amountMarks == 0) {
				amountMarksKnown = false;
				amountMarks = 100;
			}
			if (amountMarksKnown == false) {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus (0 - baigti ivedima): ";
				while (true) {
					int mark = NumberCheck(0, 10);
					if (mark == 0) break;
					temp.marks.push_back(mark);
				}
			}
			else {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus: ";
				for (int j = 0; j < amountMarks; j++)
					temp.marks.push_back(NumberCheck(1, 10));
			}

			cout << "Iveskite studento egzamino pazymi: ";
			temp.egzam = NumberCheck(1, 10);
			group.push_back(temp);
			cout << "------------------------------------------------------------" << endl;
		}
		else if (action == 2 || action == 3) {
			int amountMarks = rand() % 100 + 1;
			for (int j = 0; j < amountMarks; j++)
				temp.marks.push_back(rand() % 10 + 1);
			temp.egzam = rand() % 10 + 1;
			group.push_back(temp);
		}

		if (amountStudKnown == false) {
			cout << "1 - ivesti dar vieno studento duomenis; 0 - baigti ivedima. ";
			int proceed = NumberCheck(0, 1);
			if (proceed == 0) break;
		}
	}
	Calculations(group);
	Output(group, cout);
	ProgramEnd();
	return 0;
}