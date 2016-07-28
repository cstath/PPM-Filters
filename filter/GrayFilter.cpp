#include "GrayFilter.h"

using namespace math;

namespace imaging
{

GrayFilter::GrayFilter () {
	filtername = "gray";
}

GrayFilter::~GrayFilter() {}

Vec3<component_t> GrayFilter::filteredPixel( Image & inpImage, unsigned int x, unsigned int y) {

	Vec3<component_t> filteredPixel;

	filteredPixel.r = (inpImage(x, y).r + inpImage(x, y).g + inpImage(x, y).b) / 3;
	filteredPixel.b = filteredPixel.g = filteredPixel.r;

	return filteredPixel;

}

}
