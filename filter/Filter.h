#ifndef _FILTER
#define _FILTER

#include "Image.h"
#include <string>

namespace imaging
{
	
class Filter
{
protected:
	std::string filtername;

public:

	Filter ();
	virtual ~Filter();

	// This virtual method has to be implemented in each Filter subclass for specific filters
	virtual math::Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y) = 0;

	// Apply the filter
	Image operator << (imaging::Image& inpImage);

	std::string getFilterName();

	friend std::ostream &operator<<( std::ostream & output, const Filter & filter );

};

}
#endif