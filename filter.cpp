#include <iostream>
#include <gtest/gtest.h>
#include <cstdlib>
#include <string>
#include <list>
#include "Array.h"
#include "Image.h"
#include "Vec3.h"

using namespace std;
using namespace math;
using namespace imaging;

std::ostream& operator<<(std::ostream &strm, const list<string> &a); 

int main(int argc, char **argv) {

	Image readImage((unsigned int)0, (unsigned int)0);

	string inputFileName, outputFileName;

	// inputFileName = "TestOut.ppm";

	list<string> filtersList;
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
				filtersList.push_back(string(argv[i]));
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

	// readImage << (inputFileName.c_str());
	// readImage >> ("TestOut.ppm");

	// Vec3<component_t> avgColor;
	// avgColor = readImage.imageAveragePPM();

	// cout << "Image dimensions are: " << readImage.getWidth() << " X " << readImage.getHeight() << endl;

	// cout << "The average color of the image is (" << avgColor.x << ", " << avgColor.y << ", " << avgColor.z << ")" << endl;

	return 0;
}

std::ostream& operator<<(std::ostream &strm, const list<string> &a) {
	strm << "[";
	//<< a.i << ")"
	for (list<string>::const_iterator it = a.begin(); it != a.end(); it++)
    	strm << " " << *it;
    strm << " ]";
	return strm;
}