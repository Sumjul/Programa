#pragma once

#include <exception>
#include <stdexcept>
#include <system_error>
#include <future>
#include <type_traits>

using std::cerr;
using std::endl;
using std::ios_base;
using std::system_error;
using std::future_error;
using std::bad_alloc;
using std::exception;

const int maxStud = 10000000;
extern double globalTime;

// Structure that holds student data.
struct Student {
    string name = "Vardenis", surname = "Pavardenis";
    vector<int> marks;
    int egzam = 0;
    double average = 0;
    double median = 0;
};

// Class that measures time.
class Timer {
    private:
        using hrClock = std::chrono::high_resolution_clock;
        using durationDouble = std::chrono::duration<double>;
        std::chrono::time_point<hrClock> start;
    public:
        Timer() : start { hrClock::now() } {}
        void reset() {
        start = hrClock::now();
        }
        double elapsed() const {
        return durationDouble (hrClock::now() - start).count();
        }
};

// Functions that are used in the main function.
template <typename Container> void Action(Container& group, int action); 
template <typename Container> void Calculations(Container& group);
template <typename Container> double Sort(Container& group, int& markAction);
template <typename Container> void Output(Container& group, ostream &out, int markAction);
template <typename Container> void ReadFromFile(Container& group, int action);
template <typename Container> void GenerateFile(Container& group);
template <typename Container> void SeparateStudents(Container& group, Container& passed, Container& failed);
template <typename Container> void OutputSeparated(Container& passed, Container& failed);

int NumberCheck (int min, int max);
int Menu();
void ProgramEnd();
void ProcessException();

// Global variables that hold names and surnames.
const vector<string> names = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Lukas", "Tadas", "Dainius", "Arvydas", "Vytautas", "Mindaugas", "Rokas", "Dovydas", "Paulius", "Tomas", "Andrius", "Giedrius", "Saulius", "Algirdas", "Simas", "Egidijus", "Justas", "Laurynas", "Martynas", "Edvinas", "Kestutis", "Julius", "Raimondas", "Deividas", "Arnoldas"};
const vector<string> surnames = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marciulionis", "Baltrusaitis", "Grigonis", "Kairys", "Landsbergis", "Zemaitis", "Mikalauskas", "Butkus", "Vaiciulis", "Bagdonas", "Salkauskas", "Daukantas", "Jankauskas", "Tamulevicius", "Skvernelis", "Navickas", "Kupcinskas", "Simkus", "Masiulis", "Zukauskas", "Cepaitis", "Vaitkus", "Urbsys", "Brazys", "Petrusaitis", "Daugela"};


// Function that asks the user to input data manually or generates it randomly.
template <typename Container>
void Action(Container& group, int action) {
	cout << "Iveskite studentu skaiciu (iveskite 0, jei skaicius yra nezinomas): " << endl;
	int amountStud = NumberCheck(0, maxStud);
	bool amountStudKnown = (amountStud != 0);
	if (!amountStudKnown)
		amountStud = maxStud;

	for (int i = 0; i < amountStud; i++) {
		Student temp;
		if (action == 1 || action == 2) {
			cout << "Iveskite studento varda: " << endl;
			cin >> temp.name;
			cout << "Iveskite studento pavarde: " << endl;
			cin >> temp.surname;
		}
		else if (action == 3) {
			temp.name = names[rand() % names.size()];
			temp.surname = surnames[rand() % surnames.size()];
		}

		if (action == 1) {
			cout << "Iveskite studento atliktu namu darbu kieki (iveskite 0, jei kiekis yra nezinomas): " << endl;
			int kiekPaz = NumberCheck(0, 100);
			bool pazZinomas = true;
			if (kiekPaz == 0) {
				pazZinomas = false;
				kiekPaz = 100;
			}
			if (!pazZinomas) {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus (0 - baigti ivedima): " << endl;
				while (true) {
					int pazymys = NumberCheck(0, 10);
					if (pazymys == 0) break;
					temp.marks.push_back(pazymys);
				}
			}
			else {
				cout << "Iveskite studento visus atliktu namu darbu rezultatus: " << endl;
				for (int j = 0; j < kiekPaz; j++)
				temp.marks.push_back(NumberCheck(1, 10));
			}

			cout << "Iveskite studento egzamino pazymi: " << endl;
			temp.egzam = NumberCheck(1, 10);
			group.push_back(temp);
	}
		else if (action == 2 || action == 3) {
			int amountMarks = rand() % 100 + 1;
			for (int j = 0; j < amountMarks; j++)
				temp.marks.push_back(rand() % 10 + 1);
			temp.egzam = rand() % 10 + 1;
			group.push_back(temp);
		}

		if (!amountStudKnown) {
			cout << "1 - ivesti dar vieno studento duomenis; 0 - baigti ivedima. "	<< endl;
			if (NumberCheck(0, 1) == 0)
				break;
		}
	}
}

// Function that calculates the average and median of the students' marks.
template <typename Container>
void Calculations(Container& group) {
	for (auto& final :group) {
		double sum = 0;
		for (auto temp :final.marks)
			sum += temp;
		if (final.marks.empty()) {
			final.average = 0;
			final.median = 0;
			continue;
		}
			final.average = 0.4 * (sum / final.marks.size()) + 0.6 * final.egzam;
		sort(final.marks.begin(), final.marks.end());
		if (final.marks.size() % 2 == 0)
			final.median = (final.marks[final.marks.size() / 2 - 1] + final.marks[final.marks.size() / 2]) / 2.0;
		else final.median = final.marks[final.marks.size() / 2];
	}
}

// Function that sorts the students by name, surname or final mark.
template <typename Container>
double Sort(Container& group, int& markAction) {
	cout << "Pasirinkite rezultatu isvedimo metoda: " << endl;
	cout << "1 - gauti vidurkius; 2 - gauti medianas. " << endl;
	markAction = NumberCheck(1, 2);
	cout << "Pairinkite rezultatu rusiavimo metoda: " << endl;
	cout << "1 - rusiuoti pagal varda (A-Z); 2 - rusiuoti pagal pavarde (A-Z); 3 - rusiuoti pagal galutini pazymi." << endl;
	int sortAction = NumberCheck(1, 3);

	Timer sortTime;
    auto compare = [&](const Student& a, const Student& b) {
        if (sortAction == 1) return a.name < b.name;
        if (sortAction == 2) return a.surname < b.surname;
        if (sortAction == 3) return (markAction == 1) ? (a.average < b.average) : (a.median < b.median);
        return false;
    };
    if constexpr (std::is_same_v<Container, vector<Student>> || std::is_same_v<Container, deque<Student>>) {
        sort(group.begin(), group.end(), compare);
    } else if constexpr (std::is_same_v<Container, list<Student>>) {
        group.sort(compare);
    }
    return sortTime.elapsed();
}

// Function that outputs the results to the console or a file.
template <typename Container>
void Output(Container& group, ostream &out, int markAction) {
	Timer outputTime;
	out << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
	if (markAction == 1) out << setw(20) << "Galutinis (Vid.)" << endl;
	else if (markAction == 2 ) out << setw(20) << "Galutinis (Med.)" << endl;
	out << "------------------------------------------------------------" << endl;
	for (auto& final : group) {
		out << left << setw(20) << final.surname << setw(20) << final.name;
		if (markAction == 1) out << setw(20) << fixed << setprecision(2) << final.average << endl;
		else if (markAction == 2) out << setw(20) << fixed << setprecision(2) << final.median << endl;
	}
	globalTime += outputTime.elapsed();
	cout << " * Rezultatu isvedimas uztruko: " << outputTime.elapsed() << " sekundziu. " << endl;
}

// Function that reads data from a file.
template <typename Container>
void ReadFromFile(Container& group, int action) {
	string readName;
	bool fileLoaded = false;
	while (!fileLoaded) {
		cout << "Iveskite failo pavadinima, is kurio bus skaitomi duomenys: " << endl;
		cin >> readName;
		try {
			ifstream input(readName, std::ios::binary);
			if (!input.is_open()) {
				throw std::ios_base::failure("Failas nerastas arba negali buti atidarytas.");
			}
			else fileLoaded = true;
			Timer inputTime;
			input.seekg(0, std::ios::end);
			size_t fileSize = input.tellg();
			input.seekg(0, std::ios::beg);
			string fileContent(fileSize, '\0');
			input.read(&fileContent[0], fileSize);
			input.close();
			istringstream iss(fileContent);
			string line;
			getline(iss, line);
			while (getline(iss, line)) {
				istringstream lineStream(line);
				Student temp;
				lineStream >> temp.name >> temp.surname;
				vector<int> markInput;
				int mark;
				while (lineStream >> mark)
					markInput.push_back(mark);
				if(!markInput.empty()) {
					temp.egzam = markInput.back();
					markInput.pop_back();
					temp.marks = std::move(markInput);
				}
				group.emplace_back(std::move(temp));
			}
			input.close();
			cout << " * Duomenu skaitymas uztruko: " << inputTime.elapsed() << " sekundziu. " << endl;
			globalTime += inputTime.elapsed();
		} catch (...) {
			ProcessException();
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}	
	Calculations(group);
	if (action != 6) {
		string writeName = "rezultatas.txt";
		ofstream output(writeName);
		int markAction;
		Sort(group, markAction);
		Output(group, output, markAction);
		output.close();
		cout << "Duomenys nukopijuoti i faila: " << writeName << endl;
	}
}

// Function that generates data and writes it to a file.
template <typename Container>
void GenerateFile(Container& group) {
	cout << "Iveskite failo pavadinima, i kuri bus irasyti duomenys: " << endl;
	string fout;
	cin >> fout;
	cout << "Iveskite studentu skaiciu, kuriu informacija norite sugeneruoti: " << endl;
	int amountStud = NumberCheck(1, maxStud);
	Timer generateTime;
	int amountMarks = rand() % 11 + 10;
	for (int i=1; i<=amountStud; i++) {
		Student temp;
		temp.name = "VardasNr" + std::to_string(i);	
		temp.surname = "PavardeNr" + std::to_string(i);
		for (int j=0; j<amountMarks; j++)
			temp.marks.push_back(rand() % 10 + 1);
		temp.egzam = rand() % 10 + 1;
		group.push_back(temp);
	}
	ofstream out(fout);
	out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
	for (int i=1; i<=amountMarks; i++)
		out << left << setw(10) << ("ND" + std::to_string(i));
	out << setw(10) << "Egz." << endl;
	for (auto& final : group) {
		out << left << setw(20) << final.name << setw(20) << final.surname;
		for (auto mark : final.marks)
			out << left << setw(10) << mark;
		out << setw(10) << final.egzam << endl;
	}
	out.close();
	cout << "Duomenys buvo sekmingai sukurti faile: " << fout << endl;
	cout << " * Duomenu generavimas uztruko: " << generateTime.elapsed() << " sekundziu. " << endl;
	globalTime += generateTime.elapsed();
}

// Function that sorts students into two groups - those who passed and those who failed.
template <typename Container>
void SeparateStudents(Container& group, Container& passed, Container& failed) {
	Timer separationTime;
	std::stable_partition(group.begin(), group.end(), [&](Student& final) {
		if (final.average >= 5) {
			passed.push_back(final);
			return true;
		} else {
			failed.push_back(final);
			return false;
		}
	});
	globalTime += separationTime.elapsed();
	cout << " * Studentu skirstymas i 2 kategorijas uztruko: " << separationTime.elapsed() << " sekundziu. " << endl;
}

// Function that outputs the sorted students to two files.
template <typename Container>
void OutputSeparated(Container& passed, Container& failed) {
	int markAction;
	double sortTime1 = Sort(passed, markAction);
	ofstream passedOut("kietiakai.txt");
	Timer passedTime;
	Output(passed, passedOut, markAction);
	double outTime1 = passedTime.elapsed();
	passedOut.close();
	cout << "Kietiakai surasyti i faila: kietiakai.txt." << endl;
	double sortTime2 = Sort(failed, markAction);
	cout << " * Studentu rusiavimas uztruko: " << sortTime1 + sortTime2 << " sekundziu. " << endl;
	globalTime += sortTime1 + sortTime2;
	ofstream failedOut("vargsiukai.txt");
	Timer failedTime;
	Output(failed, failedOut, markAction);
	double outTime2 = failedTime.elapsed();
	failedOut.close();
	cout << "Vargsiukai surasyti i faila: vargsiukai.txt." << endl;
	cout << " * Rezultatu isvedimas i 2 failus uztruko: " << outTime1 + outTime2 << " sekundziu. " << endl;
}