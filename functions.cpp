#include "global.h"
#include "headers.h"
#include "exceptions.h"

// Function that checks if the input is a number and if it is within the specified range.
int NumberCheck (int min, int max) {
	int number;
	while (true) {
        try {
		if (cin >> number && number >= min && number <= max)
			break;
		else {
            throw std::invalid_argument("Ivestis netinkama. Iveskite dar karta.");
        }
        } catch (...) {
            processException();
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return number;
}

// Function that asks the user to input data manually or generates it randomly.
void Action(vector<Student>& group, int action) {
    cout << "Iveskite studentu skaiciu (iveskite 0, jei skaicius yra nezinomas): ";
	int amountStud = NumberCheck(0, maxStud);
	bool amountStudKnown = (amountStud != 0);
	if (!amountStudKnown)
        amountStud = maxStud;

	for (int i = 0; i < amountStud; i++) {
		Student temp;
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
					temp.marks.push_back(pazymys);
				}
			}
			else {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus: ";
				for (int j = 0; j < kiekPaz; j++)
                temp.marks.push_back(NumberCheck(1, 10));
			}

			cout << "Iveskite studento egzamino pazymi: ";
			temp.egzam = NumberCheck(1, 10);
			group.push_back(temp);
    }
		else if (action == 2 || action == 3) {
			int amountMarks = rand() % 100 + 1;
			for (int j = 0; j < amountMarks; j++)
				temp.marks.push_back(rand() % 10 + 1);
			temp.egzam = rand() % 10 + 1;
			group.push_back(temp);
		}

		if (!amountStudKnown) {
			cout << "1 - ivesti dar vieno studento duomenis; 0 - baigti ivedima. ";
			if (NumberCheck(0, 1) == 0)
                break;
		}
	}
}

// Function that calculates the average and median of the students' marks.
void Calculations(vector<Student>& group) {
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

// Function that outputs the results to the console or a file.
void Output(vector<Student>& group, ostream &out) {
	group.shrink_to_fit();
	cout << "Pasirinkite rezultatu isvedimo metoda: " << endl;
	cout << "1 - gauti vidurkius; 2 - gauti medianas. ";
	int markAction = NumberCheck(1, 2);
	cout << "Pairinkite rezultatu rusiavimo metoda: " << endl;
	cout << "1 - rusiuoti pagal varda (A-Z); 2 - rusiuoti pagal pavarde (A-Z); 3 - rusiuoti pagal galutini pazymi." << endl;
	int sortAction = NumberCheck(1, 3);

	Timer outputTime;
	if (sortAction == 1) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.name < b.name; });
	else if (sortAction == 2) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.surname < b.surname; });
	else if (sortAction == 3) {
        if (markAction == 1) sort(group.begin(), group.end(), [](const Student& a, const Student& b) { return a.average > b.average; });
        else if (markAction == 2) sort(group.begin(), group.end(), [](const Student& a, const Student& b) { return a.median > b.median; });
    }
	out << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
	if (markAction == 1) out << setw(20) << "Galutinis (Vid.)" << endl;
	else if (markAction == 2 ) out << setw(20) << "Galutinis (Med.)" << endl;
	out << "------------------------------------------------------------" << endl;
	for (auto& final : group) {
		out << left << setw(20) << final.surname << setw(20) << final.name;
		if (markAction == 1) out << setw(20) << fixed << setprecision(2) << final.average << endl;
		else if (markAction == 2) out << setw(20) << fixed << setprecision(2) << final.median << endl;
	}
	cout << "Rezultatu isvedimas uztruko: " << outputTime.elapsed() << " sekundziu. ";
}

// Function that reads data from a file.
void File(vector<Student>& group) {
	string readName;
	string line;
	bool fileLoaded = false;
	while (!fileLoaded) {
		cout << "Iveskite failo pavadinima, is kurio bus skaitomi duomenys: ";
		cin >> readName;
        try {
            Timer inputTime;
            ifstream input(readName);
            if (!input.is_open()) {
                throw std::ios_base::failure("Failas nerastas arba negali buti atidarytas.");
            }
            fileLoaded = true;
            getline(input, line);
            while (getline(input, line)) {
                istringstream iss(line);
                Student temp;
                iss >> temp.name >> temp.surname;
                int mark;
                vector<int> markInput;
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
            cout << "Duomenu skaitymas uztruko: " << inputTime.elapsed() << " sekundziu. " << endl;
        } catch (...) {
            processException();
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }	
	Calculations(group);
	string writeName = "rezultatas.txt";
	ofstream output(writeName);
	Output(group, output);
	output.close();
	cout << "Duomenys nukopijuoti i faila: " << writeName << endl;
}

// Function that generates data and writes it to a file.
void Generate(vector<Student>& group) {
	cout << "Iveskite failo pavadinima, i kuri bus irasyti duomenys: ";
	string fout;
	cin >> fout;
	cout << "Iveskite studentu skaiciu, kuriu informacija norite sugeneruoti: ";
	int amountStud = NumberCheck(1, maxStud);
	Timer generateTime;
	int amountMarks = rand() % 11 + 10;
	for (int i=1; i<=amountStud; i++) {
		Student temp;
		temp.name = "VardasNr" + std::to_string(i);	
		temp.surname = "PavardeNr" + std::to_string(i);
		for (int j=0; j<amountMarks; j++)
			temp.marks.push_back(rand() % 10 + 1);
		temp.egzam = rand() % 10 + 1;
		group.push_back(temp);
	}
	ofstream out(fout);
	out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
	for (int i=1; i<=amountMarks; i++)
		out << left << setw(10) << ("ND" + std::to_string(i));
	out << setw(10) << "Egz." << endl;
	for (auto& final : group) {
		out << left << setw(20) << final.name << setw(20) << final.surname;
		for (auto mark : final.marks)
			out << left << setw(10) << mark;
		out << setw(10) << final.egzam << endl;
	}
	out.close();
	cout << "Duomenys buvo sekmingai sukurti faile: " << fout << endl;
	cout << "Duomenu generavimas uztruko: " << generateTime.elapsed() << " sekundziu. " << endl;
}

// Function that sorts students into two groups - those who passed and those who failed.
void SortStudents (vector<Student>& group, vector<Student>& passed, vector<Student>& failed) {
	for (auto& final : group) {
		if (final.average >= 5) passed.push_back(final);
		else failed.push_back(final);
	}
}

void OutputSorted(vector<Student>& passed, vector<Student>& failed) {
	ofstream passedOut("kietiakai.txt");
	ofstream failedOut("vargsiukai.txt");
	Output(passed, passedOut);
	Output(failed, failedOut);
	passedOut.close();
	failedOut.close();
	cout << "Studentai surusiuoti i failus: kietiakai.txt ir vargsiukai.txt." << endl;
}

// Function that ends the program.
void ProgramEnd() {
	cout << "Paspauskite Enter, kad uzbaigtumete programos darba." << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
}