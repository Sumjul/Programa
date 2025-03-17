#include "../include/global.h"
#include "../include/headers.h"
#include "../include/templates.h"

int main()
{
	// Uncomment the container you want to use

	vector<Student> group, failed; group.reserve(maxStud);
	//deque<Student> group, failed;
	//list<Student> group, failed;

	srand(time(NULL));
	int action = Menu();
	if (action == 0)
		return 0;
	else if (action == 4)
		ReadFromFile(group, action);
	else if (action == 5)
		GenerateFile(group);
	else if (action == 6)
	{
		ReadFromFile(group, action);
		SeparateStudents(group, failed);
		OutputSeparated(group, failed);
	}
	else
	{
		Action(group, action);
		Calculations(group);
		int markAction;
		Sort(group, markAction);
		Output(group, cout, markAction);
	}
	ProgramEnd();
	return 0;
}