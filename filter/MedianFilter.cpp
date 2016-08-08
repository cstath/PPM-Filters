#include "MedianFilter.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace math;

namespace imaging
{

MedianFilter::MedianFilter () {
	filtername = "median";
}

MedianFilter::~MedianFilter() {}

Vec3<component_t> MedianFilter::filteredPixel( imaging::Image & inpImage, unsigned int x, unsigned int y) {

	Vec3<component_t> filteredPixel;

	int i = 0;

	vector <component_t> redNeighborhood, greenNeighborhood, blueNeighborhood;

	for (int m = -1; m <= +1 ; m++) {
		for (int n = -1; n <= +1 ; n++) {

			int x_hat = (int)x + m;
			int y_hat = (int)y + n;

			if ( ( 0 <= x_hat ) && (x_hat < (int) inpImage.getWidth()) &&
			        ( 0 <= y_hat ) && (y_hat < (int) inpImage.getHeight()) ) {

				redNeighborhood.push_back( inpImage( (unsigned int) x_hat , (unsigned int) y_hat ).r );
				greenNeighborhood.push_back( inpImage( (unsigned int) x_hat , (unsigned int) y_hat ).g );
				blueNeighborhood.push_back( inpImage( (unsigned int) x_hat , (unsigned int) y_hat ).b );
				i++;
			}

		}
	}

	std::sort(redNeighborhood.begin(), redNeighborhood.end());
	std::sort(greenNeighborhood.begin(), greenNeighborhood.end());
	std::sort(blueNeighborhood.begin(), blueNeighborhood.end());
	filteredPixel.r = redNeighborhood[redNeighborhood.size()/2];
	filteredPixel.g = greenNeighborhood[greenNeighborhood.size()/2];
	filteredPixel.b = blueNeighborhood[blueNeighborhood.size()/2];

	return filteredPixel;

}


}