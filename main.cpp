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
		passed.reserve(maxStud);
		failed.reserve(maxStud);
		SortStudents(group, passed, failed);
		OutputSorted(passed, failed);
		ProgramEnd();
		return 0;
	}
	else Action(group, action);
	Calculations(group);
	int markAction;
	Sort(group, markAction);
	Output(group, cout, markAction);
	ProgramEnd();
	return 0;
}