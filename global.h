#ifndef HEADERS_H
#define HEADERS_H

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
	string var = "Vardenis", pav = "Pavardenis";
	vector <int> paz;
	int* pazAr = new int[100];
	int pazSk = 0;
	int egz = 0;
	double gal = 0;
	double med = 0;
};

#endif