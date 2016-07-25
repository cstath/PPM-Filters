#ifndef _BLURFILTER
#define _BLURFILTER

#include "Image.h"
#include "Filter.h"

namespace imaging
{
	class BlurFilter : public Filter
	{
	protected:
		
	public:
		
		BlurFilter ();
		virtual ~BlurFilter();

		virtual Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y);
	
	};

}
#endif