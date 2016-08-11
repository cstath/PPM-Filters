#ifndef _COMMON
#define _COMMON

#include "Filter.h"
#include "GrayFilter.h"
#include "BlurFilter.h"
#include "DiffFilter.h"
#include "MedianFilter.h"
#include "ColorFilter.h"
#include <cstdlib>
#include <string>
#include <list>

// Parse command line arguments and exctract input and output files and filter list
void parseInit(int argc, char ** argv, std::string & inputFileName, std::string & outputFileName, std::list<imaging::Filter *> & filtersList);

// Print out the filter list
std::ostream& operator<<(std::ostream &strm, const std::list<imaging::Filter *> &a);

// Take a filter name and return a respective filter object
imaging::Filter * stringToFilter(std::string filterString);

#endif