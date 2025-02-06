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

struct Stud {
	string var = "Vardenis", pav = "Pavardenis";
	vector <int> paz;
	double gal;
	int egz;
};

#endif