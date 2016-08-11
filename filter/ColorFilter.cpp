#include "ColorFilter.h"

using namespace math;

namespace imaging
{

ColorFilter::ColorFilter() {
	filtername = "color";
	colorfactors.r = 0;
	colorfactors.g = 0;
	colorfactors.b = 0;
}

ColorFilter::~ColorFilter() {}

void ColorFilter::setColorFactors(component_t r, component_t g, component_t b){
	colorfactors.r = r;
	colorfactors.g = g;
	colorfactors.b = b;
}

Vec3<component_t> ColorFilter::filteredPixel( Image & inpImage, unsigned int x, unsigned int y) {

	Vec3<component_t> filteredPixel;

	filteredPixel = colorfactors * inpImage(x, y);

	return filteredPixel;

}

}