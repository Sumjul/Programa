#ifndef HEADERS_H
#define HEADERS_H
#include "global.h"

const int maxStud = 1000;
struct Student {
	string name = "Vardenis", surname = "Pavardenis";
	vector <int> marks;
	int egzam = 0;
	double average = 0;
	double median = 0;
};

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

int NumberCheck (int min, int max);
void Calculations(vector <Student>& group);
void Output(vector <Student>& group, ostream &out);
void File(vector<Student>& group);
void ProgramEnd();

const vector<string> names = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Lukas", "Tadas", "Dainius", "Arvydas", "Vytautas", "Mindaugas", "Rokas", "Dovydas", "Paulius", "Tomas", "Andrius", "Giedrius", "Saulius", "Algirdas", "Simas", "Egidijus", "Justas", "Laurynas", "Martynas", "Edvinas", "Kestutis", "Julius", "Raimondas", "Deividas", "Arnoldas"};
const vector<string> surnames = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marciulionis", "Baltrusaitis", "Grigonis", "Kairys", "Landsbergis", "Zemaitis", "Mikalauskas", "Butkus", "Vaiciulis", "Bagdonas", "Salkauskas", "Daukantas", "Jankauskas", "Tamulevicius", "Skvernelis", "Navickas", "Kupcinskas", "Simkus", "Masiulis", "Zukauskas", "Cepaitis", "Vaitkus", "Urbsys", "Brazys", "Petrusaitis", "Daugela"};
#endif