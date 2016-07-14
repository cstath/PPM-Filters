#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Array.h"
#include "Serializable.h"
#include "Vec3.h"

#define component_t float

using namespace std;
using namespace math;

namespace imaging {

	class Image: public Array<Vec3<component_t>>, public Serializable {
		//Class Image inherits from Array and Serializable
	public:

		//Constructors inhereted by Array class
		Image(unsigned int w, unsigned int h): Array<Vec3<component_t>>(w, h){
			// nothing more
		}

		Image(const Array<Vec3<component_t>> & source): Array<Vec3<component_t>>( source){
			// nothing more
		}


		virtual bool operator << (std::string filename) { // Read the contents of an object from the specified file
			
			string ppmFormatVersion, width_str, height_str, maxColor_str;

			// open the file for reading
			ifstream infile;
			infile.open( filename, ios::in | ios::binary); //../../ExampleImages/

			cout << "Reading from file" << endl;


			infile >> ppmFormatVersion;
			infile >> width_str;
			infile >> height_str;
			infile >> maxColor_str;

			cout << "PPM format version: " << ppmFormatVersion << endl;

			if (ppmFormatVersion == "P6") {
				cout << "Supported format!" << endl;
			}
			else {
				cout << "Houston we have a problem: Not supported PPM format. Exiting..." << endl;
				exit(0);
			}

			if (stoi(maxColor_str) == 255) {
				cout << "Supported color mode!" << endl;
			}
			else {
				cout << "Houston we have a problem: Not supported color mode. Exiting..." << endl;
				exit(0);
			}


			//unsigned int width, height;
			unsigned char incharRed, incharGreen, incharBlue;
			width = stoi(width_str);
			height = stoi(height_str);

			if(buffer != NULL) 
				delete[] buffer;

			buffer = new Vec3<component_t>[width * height];

			infile.read((char *)&incharRed, 1); // minding the gap

			for (unsigned int i = 0; i < width * height; i++ ) {

				infile.read((char *)&incharRed, 1);
				infile.read((char *)&incharGreen, 1);
				infile.read((char *)&incharBlue, 1);

				Vec3<component_t> pixel(((component_t) incharRed) / 255.0, ((component_t) incharGreen) / 255.0, ((component_t) incharBlue) / 255.0);

				buffer[i] = pixel;
			}

			//Image * returnImage = new Image(width, height, imagemat);

			infile.close();

			return true;
		}


		virtual bool operator >> (std::string filename)   // Write the contents of an object to the specified file
		{
			// open the file for reading
			ofstream outfile;
			outfile.open( filename, ios::out | ios::binary); //../../ExampleImages/

			cout << "Writing to file" << endl;


			outfile << "P6" << endl;
			outfile << to_string(width) << endl;
			outfile << to_string(height) << endl;
			outfile << to_string(255) << endl;

			//component_t * imagemat = outImage->getRawDataPtr();

			unsigned char outcharRed, outcharGreen, outcharBlue;
			for (unsigned int i = 0; i < width*height; i++ ) {

				outcharRed = ((unsigned char) (buffer[i].x * 255 + 0.5));
				outcharGreen = ((unsigned char) (buffer[i].y * 255 + 0.5));
				outcharBlue = ((unsigned char) (buffer[i].z * 255 + 0.5));

				outfile.write( (char *) &outcharRed, 1);
				outfile.write( (char *) &outcharGreen, 1);
				outfile.write( (char *) &outcharBlue, 1);
			}

			outfile.close();

			return true;
		}

		Vec3<component_t> imageAveragePPM() {

			Vec3<component_t> sum(0,0,0), pix;

			for (unsigned int y = 0 ; y < height; y++) {
				for ( unsigned int x = 0 ; x < width; x++) {
					pix = (*this)(x,y);
					//sum = sum + image->getPixel(x, y);
					sum += pix;
				}
			}
			int totalPixels = height * width;

			sum /= totalPixels;

			return sum;
		}

	}; // class Image


}