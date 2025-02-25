#include "global.h"
#include "headers.h"

int NumberCheck (int min, int max) {
	int number;
	while (true) {
		if (cin >> number && number >= min && number <= max) {
			break;
		} else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ivestis netinkama. Iveskite dar karta: ";
		}
	}
	return number;
}
void Calculations(vector <Student>& group) {
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

void Output(vector <Student>& group, ostream &out) {
	cout << "1 - gauti vidurkius; 2 - gauti medianas. ";
	int rezult = NumberCheck(1, 2);
	cout << "Pairinkite rezultatu rusiavimo metoda: " << endl;
	cout << "1 - rusiuoti pagal varda (A-Z); 2 - rusiuoti pagal pavarde (A-Z); 3 - rusiuoti pagal galutini markymi." << endl;
	int rusiavimas = NumberCheck(1, 3);
	Timer outputTime;
	if (rusiavimas == 1) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.name < b.name; });
	else if (rusiavimas == 2) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.surname < b.surname; });
	else if (rusiavimas == 3 && rezult == 1) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.average > b.average; });
	else if (rusiavimas == 3 && rezult == 2) sort(group.begin(), group.end(), [](const Student &a, const Student &b) {return a.median > b.median; });
	out << endl << left << setw(20) << "Pavarde" << setw(15) << "Vardas";
	if (rezult == 1) out << setw(20) << "Galutinis (Vid.)" << endl;
	else if (rezult == 2 ) out << setw(20) << "Galutinis (Med.)" << endl;
	out << "------------------------------------------------------------" << endl;
	for (auto& final : group) {
		out << left << setw(20) << final.name << setw(15) << final.surname;
		if (rezult == 1) out << setw(20) << fixed << setprecision(2) << final.average << endl;
		else if (rezult == 2) out << setw(20) << fixed << setprecision(2) << final.median << endl;
	}
	cout << "Rezultatu isvedimas uztruko: " << outputTime.elapsed() << " sekundziu. ";
}

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
				std::istringstream iss(line);
				Student temp;
				iss >> temp.name >> temp.surname;
				int mark;
				vector <int> markInput;
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

void ProgramEnd() {
	cout << "Paspauskite Enter, kad uzbaigtumete programos darba." << endl;
	cin.ignore();
	cin.get();
}