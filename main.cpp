#include "global.h"
#include "headers.h"
#include "functions.cpp"

int main()
{
	vector<Student> group;
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