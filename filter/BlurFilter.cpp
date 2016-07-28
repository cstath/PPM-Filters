#include "BlurFilter.h"

using namespace math;

namespace imaging
{
BlurFilter::BlurFilter () {
	filtername = "blur";
}

BlurFilter::~BlurFilter() {}

Vec3<component_t> BlurFilter::filteredPixel( imaging::Image & inpImage, unsigned int x, unsigned int y) {

	Vec3<component_t> filteredPixel;

	int i = 0;

	for (int m = -1; m <= +1 ; m++) {
		for (int n = -1; n <= +1 ; n++) {

			int x_hat = (int)x + m;
			int y_hat = (int)y + n;

			if ( ( 0 <= x_hat ) && (x_hat < (int) inpImage.getWidth()) &&
			        ( 0 <= y_hat ) && (y_hat < (int) inpImage.getHeight()) ) {

				filteredPixel += inpImage( (unsigned int) x_hat , (unsigned int) y_hat );
				i++;
			}

		}
	}

	filteredPixel /= i;

	return filteredPixel;

}

}