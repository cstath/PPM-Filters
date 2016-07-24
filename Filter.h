#ifndef _FILTER
#define _FILTER

#include <string>
#include "Image.h"

using namespace std;

namespace imaging
{
	class Filter
	{
	protected:
		string filtername;
		// Image * bufImage;
	public:
		
		Filter () {};
		virtual ~Filter() {};

		// This virtual method has to be implemented in each Filter subclass for specific filters
		virtual Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y) = 0;

		// Apply the filter 
		Image operator << (imaging::Image& inpImage) {

			cout << "Applying " << filtername << " filter..." << endl;
			//make a new image buffer with the same size to store the filter result
			Image bufImage(inpImage.getWidth(), inpImage.getHeight());

			// Apply the filter to the image replica
			for (unsigned int i = 0; i < bufImage.getHeight(); i++) {
				for (unsigned int j = 0; j < bufImage.getWidth(); j++) {

					bufImage(j,i) = filteredPixel(inpImage, j, i);
				}
			}

			cout << filtername << " filter applied." << endl;

			// Return the result
			return bufImage;
		}

		string getFilterName(){ return filtername; };

		friend ostream &operator<<( ostream & output, const Filter & filter )
		{
			output << filter.filtername ;
			return output;
		}

	};

}
#endif