#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

const int maxStud = 1000;
struct Studentas {
	string var = "Vardenis", pav = "Pavardenis";
	vector <int> paz;
	int pazAr[100];
	int pazSk = 0;
	int egz = 0;
	double gal = 0;
	double med = 0;
};

int skaicioTikrinimas(int min, int max);
#endif