#include "Filter.h"
#include <string>

using namespace std;

namespace imaging
{

	Filter::Filter () {}
	Filter::~Filter() {}

	// Apply the filter
	Image Filter::operator << (imaging::Image & inpImage) {

		cout << "Applying " << filtername << " filter..." << endl;
		//make a new image buffer with the same size to store the filter result
		Image bufImage(inpImage.getWidth(), inpImage.getHeight());

		// Apply the filter to the image replica
		for (unsigned int i = 0; i < bufImage.getHeight(); i++) {
			for (unsigned int j = 0; j < bufImage.getWidth(); j++) {

				bufImage(j, i) = filteredPixel(inpImage, j, i);
			}
		}

		cout << filtername << " filter applied." << endl;

		// Return the result
		return bufImage;
	}

	string Filter::getFilterName() {
		return filtername;
	}

	ostream & operator<<( ostream & output, const Filter & filter )
	{
		output << filter.filtername ;
		return output;
	}

}