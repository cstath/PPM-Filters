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
		
		GrayFilter () { filtername = "gray";};
		~GrayFilter() {};

		virtual Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y){

			Vec3<component_t> filteredPixel;

			filteredPixel.r = (inpImage(x, y).r + inpImage(x, y).g + inpImage(x, y).b) / 3;
			filteredPixel.b = filteredPixel.g = filteredPixel.r;

			return filteredPixel;

		}

	};

}
#endif