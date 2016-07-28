#ifndef _GRAYFILTER
#define _GRAYFILTER

#include "Image.h"
#include "Filter.h"

namespace imaging
{
class GrayFilter : public Filter
{
protected:

public:

	GrayFilter ();
	virtual ~GrayFilter();

	virtual math::Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y);

};

}
#endif