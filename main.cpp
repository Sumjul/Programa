#include "global.h"
#include "headers.h"

int main()
{
	vector<Student> group;
	group.reserve(maxStud);
	srand(time(NULL));
	Menu();
	int action = NumberCheck(0, 6);
	if (action == 0) return 0;
	else if (action == 4) {
		ReadFromFile(group, action);
		ProgramEnd();
		return 0;
	}
	else if (action == 5) {
		GenerateFile(group);
		ProgramEnd();
		return 0;
	}
	else if (action == 6) {
		ReadFromFile(group, action);
		vector<Student> passed, failed;
		passed.reserve(maxStud);
		failed.reserve(maxStud);
		cout << " * Studentu skirstymas i 2 kategorijas uztruko: " << SeparateStudents(group, passed, failed) << " sekundziu. " << endl;
		OutputSeparated(passed, failed);
		ProgramEnd();
		return 0;
	}
	else Action(group, action);
	Calculations(group);
	int markAction;
	Sort(group, markAction);
	cout << " * Rezultatu isvedimas i faila uztruko: " << Output(group, cout, markAction) << " sekundziu. " << endl;
	ProgramEnd();
	return 0;
}