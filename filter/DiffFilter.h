#ifndef _DIFFFILTER
#define _DIFFFILTER

#include "Image.h"
#include "Filter.h"

namespace imaging
{
	
class DiffFilter : public Filter
{
protected:

public:

	DiffFilter ();
	virtual ~DiffFilter();

	virtual math::Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y);

};

}
#endif