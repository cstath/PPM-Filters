#ifndef _IMAGE_
#define _IMAGE_

#include "Array.h"
#include "Serializable.h"
#include "Vec3.h"

#define component_t float

namespace imaging {

//Class Image inherits from Array and Serializable
class Image: public math::Array<math::Vec3<component_t>>, public Serializable {
	
public:

	//Constructors inhereted by Array class
	Image(unsigned int w, unsigned int h);
	Image(const math::Array<math::Vec3<component_t>> & source);

	virtual bool operator << (std::string filename); // Read the contents of an object from the specified file
	virtual bool operator >> (std::string filename);   // Write the contents of an object to the specified file

	math::Vec3<component_t> imageAveragePPM();

}; // class Image


}

#endif