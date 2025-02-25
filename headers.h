#ifndef HEADERS_H
#define HEADERS_H
#include "global.h"

const int maxStud = 1000;

struct Studentas {
	string name = "Vardenis", surname = "Pavardenis";
	vector <int> marks;
	int markCount = 0;
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

#endif