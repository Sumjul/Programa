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
	cout << "6 - surusiuoti studentus i 2 failus" << endl;
	cout << "7 - baigti darba." << endl;
	int action = NumberCheck(1, 7);
	if (action == 7) return 0;
	else if (action == 4) {
		InputFile(group, action);
		ProgramEnd();
		return 0;
	}
	else if (action == 5) {	
		Generate(group);
		ProgramEnd();
		return 0;
	}
	else if (action == 6) {
		InputFile(group, action);
		vector<Student> passed, failed;
		SortStudents(group, passed, failed);
		OutputSorted(passed, failed);
		ProgramEnd();
		return 0;
	}
	else Action(group, action);
	Calculations(group);
	Output(group, cout);
	ProgramEnd();
	return 0;
}