#include "global.h"
#include "headers.h"

// Function that checks if the input is a number and if it is within the specified range.
int NumberCheck (int min, int max) {
	int number;
	while (true) {
		if (cin >> number && number >= min && number <= max)
			break;
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ivestis netinkama. Iveskite dar karta: ";
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
			int amountMarks = NumberCheck(0, 100);
			if (amountMarks == 0) amountMarks = 100;
			cout << "Iveskite studento visus atliktu namu darbu rezultatus (0 - baigti ivedima): ";
            while (amountMarks--) {
                int mark = NumberCheck(0, 10);
                if (mark == 0)
                    break;
                temp.marks.push_back(mark);
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
	cout << "1 - gauti vidurkius; 2 - gauti medianas. ";
	int markAction = NumberCheck(1, 2);
	cout << "Pairinkite rezultatu rusiavimo metoda: " << endl;
	cout << "1 - rusiuoti pagal varda (A-Z); 2 - rusiuoti pagal pavarde (A-Z); 3 - rusiuoti pagal galutini markymi." << endl;
	int sortAction = NumberCheck(1, 3);

	Timer outputTime;
	if (sortAction == 1) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.name < b.name; });
	else if (sortAction == 2) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.surname < b.surname; });
	else if (sortAction == 3) {
        if (markAction == 1) sort(group.begin(), group.end(), [](const Student& a, const Student& b) { return a.average > b.average; });
        else if (markAction == 2) sort(group.begin(), group.end(), [](const Student& a, const Student& b) { return a.median > b.median; });
    }
	out << endl << left << setw(20) << "Pavarde" << setw(15) << "Vardas";
	if (markAction == 1) out << setw(20) << "Galutinis (Vid.)" << endl;
	else if (markAction == 2 ) out << setw(20) << "Galutinis (Med.)" << endl;
	out << "------------------------------------------------------------" << endl;
	for (auto& final : group) {
		out << left << setw(20) << final.name << setw(15) << final.surname;
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
		Timer inputTime;

		ifstream input(readName);
		if (!input) {
			cout << "Klaida: failas nerastas arba negali buti atidarytas. Iveskite failo pavadinima dar karta: "<< endl;
		}
		else {
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

// Function that ends the program.
void ProgramEnd() {
	cout << "Paspauskite Enter, kad uzbaigtumete programos darba." << endl;
	cin.ignore();
	cin.get();
}