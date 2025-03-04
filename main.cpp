#include "global.h"
#include "headers.h"
#include "exceptions.h"
#include "functions.cpp"

int main()
{
	Timer totalTime;
	vector<Student> group;
	group.reserve(maxStud);
	srand(time(NULL));
	Menu();
	int action = NumberCheck(0, 6);
	if (action == 0) return 0;
	else if (action == 4) {
		InputFile(group, action);
		ProgramEnd(totalTime);
		return 0;
	}
	else if (action == 5) {	
		Generate(group);
		ProgramEnd(totalTime);
		return 0;
	}
	else if (action == 6) {
		InputFile(group, action);
		vector<Student> passed, failed;
		SortStudents(group, passed, failed);
		OutputSorted(passed, failed);
		ProgramEnd(totalTime);
		return 0;
	}
	else Action(group, action);
	Calculations(group);
	int markAction;
	Sort(group, markAction);
	Output(group, cout, markAction);
	ProgramEnd(totalTime);
	return 0;
}