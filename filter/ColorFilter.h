#ifndef _COLORFILTER
#define _COLORFILTER

#include "Image.h"
#include "Filter.h"

namespace imaging
{
class ColorFilter : public Filter
{
protected:
	math::Vec3<component_t> colorfactors;

public:

	ColorFilter ();
	virtual ~ColorFilter();

	void setColorFactors(component_t r, component_t g, component_t b);

	virtual math::Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y);

};

}
#endif