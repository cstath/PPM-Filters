#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "Array.h"
#include "Image.h"
#include "Vec3.h"

using namespace std;
using namespace math;
using namespace imaging;

int main(int argc, char **argv) {

	Image readImage((unsigned int)0, (unsigned int)0);

	string inputFileName;

	if (argc > 1){
		readImage << (argv[1]);
	}
	else{
		cout << "Please enter input filename: " << endl;
		cin >> inputFileName;
		readImage << (inputFileName.c_str());
	}
	
	readImage >> ("TestOut.ppm");

	Vec3<component_t> avgColor;
	avgColor = readImage.imageAveragePPM();

	cout << "Image dimensions are: " << readImage.getWidth() << " X " << readImage.getHeight() << endl;

	cout << "The average color of the image is (" << avgColor.x << ", " << avgColor.y << ", " << avgColor.z << ")" << endl;

	return 0;
}