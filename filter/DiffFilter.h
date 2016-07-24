#ifndef _DIFFFILTER
#define _DIFFFILTER

#include <vector>
#include <algorithm>
#include "Image.h"
#include "Filter.h"

using namespace std;

namespace imaging
{
	class DiffFilter : public Filter
	{
	protected:
		
	public:
		
		DiffFilter () { filtername = "diff";};
		~DiffFilter() {};

		virtual Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y){

			Vec3<component_t> filteredPixel;

			int i =0;

			vector <component_t> redNeighborhood, greenNeighborhood, blueNeighborhood;

			for (int m = -1; m <= +1 ; m++) {
				for (int n = -1; n <= +1 ; n++) {

					int x_hat = (int)x+m;
					int y_hat = (int)y+n;

					if ( ( 0 <= x_hat ) && (x_hat < (int) inpImage.getWidth()) &&
						( 0 <= y_hat ) && (y_hat < (int) inpImage.getHeight()) ){

						redNeighborhood.push_back( inpImage( (unsigned int) x_hat , (unsigned int) y_hat ).r );
						greenNeighborhood.push_back( inpImage( (unsigned int) x_hat , (unsigned int) y_hat ).g );
						blueNeighborhood.push_back( inpImage( (unsigned int) x_hat , (unsigned int) y_hat ).b );
						i++;
					}
						
				}
			}

			filteredPixel.r = *max_element(redNeighborhood.begin(),redNeighborhood.end()) - *min_element(redNeighborhood.begin(),redNeighborhood.end());
			filteredPixel.g = *max_element(greenNeighborhood.begin(),greenNeighborhood.end()) - *min_element(greenNeighborhood.begin(),greenNeighborhood.end());
			filteredPixel.b = *max_element(blueNeighborhood.begin(),blueNeighborhood.end()) - *min_element(blueNeighborhood.begin(),blueNeighborhood.end());

			return filteredPixel;

		}

	};

}
#endif