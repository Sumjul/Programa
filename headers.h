#pragma once

#include <exception>
#include <stdexcept>
#include <system_error>
#include <future>

using std::cerr;
using std::endl;
using std::ios_base;
using std::system_error;
using std::future_error;
using std::bad_alloc;
using std::exception;

double globalTime = 0;
const int maxStud = 10000000;

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
int NumberCheck (int min, int max);
void Action(vector<Student>& group, int action);
void Calculations(vector<Student>& group);
double Sort(vector<Student>& group, int& markAction);
void Output(vector<Student>& group, ostream &out, int markAction);
void ReadFromFile(vector<Student>& group, int action);
void GenerateFile(vector<Student>& group);
void SeparateStudents(vector<Student>& group, vector<Student>& passed, vector<Student>& failed);
void OutputSeparated(vector<Student>& passed, vector<Student>& failed);
int Menu();
void ProgramEnd();
void ProcessException();

// Global variables that hold names and surnames.
const vector<string> names = {"Jonas", "Petras", "Antanas", "Kazys", "Marius", "Lukas", "Tadas", "Dainius", "Arvydas", "Vytautas", "Mindaugas", "Rokas", "Dovydas", "Paulius", "Tomas", "Andrius", "Giedrius", "Saulius", "Algirdas", "Simas", "Egidijus", "Justas", "Laurynas", "Martynas", "Edvinas", "Kestutis", "Julius", "Raimondas", "Deividas", "Arnoldas"};
const vector<string> surnames = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Marciulionis", "Baltrusaitis", "Grigonis", "Kairys", "Landsbergis", "Zemaitis", "Mikalauskas", "Butkus", "Vaiciulis", "Bagdonas", "Salkauskas", "Daukantas", "Jankauskas", "Tamulevicius", "Skvernelis", "Navickas", "Kupcinskas", "Simkus", "Masiulis", "Zukauskas", "Cepaitis", "Vaitkus", "Urbsys", "Brazys", "Petrusaitis", "Daugela"};