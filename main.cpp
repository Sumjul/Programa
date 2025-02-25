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
	Action(group, action);
	Calculations(group);
	Output(group, cout);
	ProgramEnd();
	return 0;
}