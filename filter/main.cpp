#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "Array.h"
#include "Image.h"
#include "Vec3.h"
#include "Filter.h"
#include "GrayFilter.h"
#include "BlurFilter.h"
#include "DiffFilter.h"
#include "Common.h"

using namespace std;
using namespace math;
using namespace imaging;

int main(int argc, char **argv) {

	Image readImage((unsigned int)0, (unsigned int)0);
	Image outImage((unsigned int)0, (unsigned int)0);

	string inputFileName, outputFileName;

	list<Filter *> filtersList;

	// Read data from arguments
	parseInit(argc, argv, inputFileName, outputFileName, filtersList);

	// Reading input image
	readImage << inputFileName.c_str();
	// Initializing output image
	outImage = readImage;

	// Applying list of filters
	for (list<Filter *>::const_iterator it = filtersList.begin(); it != filtersList.end(); it++)
		outImage = **it << outImage;

	// Exporting filtered image into output file
	outImage >> outputFileName;

	// clearing things up
	for (list<Filter *>::const_iterator it = filtersList.begin(); it != filtersList.end(); it++)
		delete *it;

	return 0;
}