#include "global.h"
#include "headers.h"
#include "functions.cpp"

// Main function that creates a vector of students and asks the user to choose an action.
int main()
{
	vector<Student> group;
	group.reserve(maxStud);	
	srand(time(NULL));
	cout << "Sveiki atvyke i pazymiu skaiciuokle! Pasirinkite veiksma spausdami skaiciu ir tada spauskite Enter." << endl;
	cout << "1 - pildyti duomenis rankiniu budu;" << endl;
	cout << "2 - generuoti pazymius;" << endl;
	cout << "3 - generuoti pazymius, vardus ir pavardes;" << endl;
	cout << "4 - nauduoti duomenis is failo;" << endl;
	cout << "5 - sugeneruoti duomenis ir isvesti i faila;" << endl;
	cout << "6 - baigti darba." << endl;
	int action = NumberCheck(1, 6);
	if (action == 6) return 0;
	else if (action == 4) {
		File(group);
		ProgramEnd();
		return 0;
	}
	else if (action == 5) {	
		cout << "Iveskite skaiciu kiek sugeneruoti studentu: ";
		int amountStud = NumberCheck(1, maxStud);
		for (int i=0; i<amountStud; i++) {
			Student temp;
			temp.name = "VardasNr" + std::to_string(i);	
			temp.surname = "PavardeNr" + std::to_string(i);
			int amountMarks = rand() % 100 + 1;
			for (int j=0; j<amountMarks; j++)
				temp.marks.push_back(rand() % 10 + 1);
			temp.egzam = rand() % 10 + 1;
			group.push_back(temp);
		}
		cout << "Iveskite failo pavadinima, i kuri bus irasyti duomenys: ";
		string out;
		cin >> out;
		ofstream fout(out);
		Calculations(group);
		Output(group, fout);
		ProgramEnd();
		return 0;
	}
	else Action(group, action);
	Calculations(group);
	Output(group, cout);
	ProgramEnd();
	return 0;
}