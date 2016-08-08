#ifndef _MEDIANFILTER
#define _MEDIANFILTER

#include "Image.h"
#include "Filter.h"

namespace imaging
{
	
class MedianFilter : public Filter
{
protected:

public:

	MedianFilter ();
	virtual ~MedianFilter();

	virtual math::Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y);

};

}
#endif
