#ifndef _COMMON
#define _COMMON

#include "Filter.h"
#include "GrayFilter.h"
#include "BlurFilter.h"
#include "DiffFilter.h"
#include <cstdlib>
#include <string>
#include <list>

using namespace std;
using namespace math;
using namespace imaging;

// Parse command line arguments and exctract input and output files and filter list
void parseInit(int argc, char ** argv, string & inputFileName, string & outputFileName, list<Filter *> & filtersList);

// Print out the filter list
std::ostream& operator<<(std::ostream &strm, const list<Filter *> &a);

// Take a filter name and return a respective filter object
Filter * stringToFilter(string filterString);

#endif