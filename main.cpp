#include "global.h"
#include "headers.h"

int main()
{
	//Uncomment the container you want to use
	//vector<Student> group, passed, failed; group.reserve(maxStud);
	//deque<Student> group, passed, failed;
	list<Student> group, passed, failed;
	
	srand(time(NULL));
	int action = Menu();
	if (action == 0) return 0;
	else if (action == 4) {
		ReadFromFile(group, action);
	}
	else if (action == 5) {
		GenerateFile(group);
	}
	else if (action == 6) {
		ReadFromFile(group, action);
		SeparateStudents(group, passed, failed);
		OutputSeparated(passed, failed);
	}
	else {
		Action(group, action);
		Calculations(group);
		int markAction;
		Sort(group, markAction);
		Output(group, cout, markAction);
	}
	ProgramEnd();
	return 0;
}