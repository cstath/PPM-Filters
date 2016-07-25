#ifndef _IMAGE_
#define _IMAGE_

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
		Image(unsigned int w, unsigned int h);
		Image(const Array<Vec3<component_t>> & source);

		virtual bool operator << (std::string filename); // Read the contents of an object from the specified file
		virtual bool operator >> (std::string filename);   // Write the contents of an object to the specified file
		
		Vec3<component_t> imageAveragePPM();

	}; // class Image


}

#endif