#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string_view>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::string_view;
using std::sort;

const int maxStud = 1000;
struct Studentas {
	string name = "Vardenis", surname = "Pavardenis";
	vector <int> marks;
	int markCount = 0;
	int egzam = 0;
	double average = 0;
	double median = 0;
};

#endif