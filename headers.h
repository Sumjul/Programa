#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct Studentas {
	string var = "Vardenis", pav = "Pavardenis";
	vector <int> paz {0};
	int egz = 0;
	double gal = 0;
};

#endif