#include <iostream>
#include <gtest/gtest.h>
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

using namespace std;
using namespace math;
using namespace imaging;

std::ostream& operator<<(std::ostream &strm, const list<Filter *> &a);
Filter * stringToFilter(string filterString);

int main(int argc, char **argv) {

	Image readImage((unsigned int)0, (unsigned int)0);
	Image outImage((unsigned int)0, (unsigned int)0);

	string inputFileName, outputFileName;

	list<Filter *> filtersList;
	string argument;

	int i = 1;

	while(i<argc){

		argument = string(argv[i]);

		if (argument == "-o"){
			if (i+1 < argc) {
				i++;
				outputFileName = string(argv[i]);
			}
			else
			{
				cout << "Missing argument!" << endl;
				exit(1);
			}
		}
		else if (argument == "-f"){
			if (i+1 < argc){
				i++;
				filtersList.push_back( stringToFilter(string(argv[i])) );
			}
			else{
				cout << "Missing argument!" << endl;
				exit(1);
			}
		}
		else
		{
			inputFileName = string(argv[i]);
			break;
		}

		i++;
	}
	
	if (inputFileName.empty()){
		cout << "Please enter input filename: " << endl;
		cin >> inputFileName;
	}
	if (outputFileName.empty()){
		cout << "Please enter output filename: " << endl;
		cin >> outputFileName;
	}

	cout << "Input filename: " << inputFileName << endl;
	cout << "Output filename: " << outputFileName << endl;
	cout << "Filters list: " << filtersList << endl;

	// Reading input image
	readImage << inputFileName.c_str();
	// Initializing output image
	outImage = readImage;

	// Applying list of filters
	for (list<Filter *>::const_iterator it = filtersList.begin(); it != filtersList.end(); it++)
    	outImage = **it << outImage;

    // Exporting filtered image into output file
    outImage >> outputFileName;

	// Vec3<component_t> avgColor;
	// avgColor = readImage.imageAveragePPM();
	// cout << "Image dimensions are: " << readImage.getWidth() << " X " << readImage.getHeight() << endl;
	// cout << "The average color of the image is (" << avgColor.x << ", " << avgColor.y << ", " << avgColor.z << ")" << endl;

    // clearing things up
	for (list<Filter *>::const_iterator it = filtersList.begin(); it != filtersList.end(); it++)
		delete *it;

	return 0;
}


std::ostream& operator<<(std::ostream &strm, const list<Filter *> &a) {
	strm << "[";
	//<< a.i << ")"
	for (list<Filter *>::const_iterator it = a.begin(); it != a.end(); it++)
    	strm << " " << **it;
    strm << " ]";
	return strm;
}

Filter * stringToFilter(string filterString){

	if(filterString == "gray")
		return new GrayFilter;
	if(filterString == "blur")
		return new BlurFilter;
	if(filterString == "diff")
		return new DiffFilter;
	
	cout << "Argument: \"" << filterString << "\" not recognized as a filter!!!" << endl;
	exit(1);

	return NULL;

}