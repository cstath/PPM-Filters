#ifndef _FILTER
#define _FILTER

#include "Image.h"

namespace imaging
{
	class Filter
	{
	protected:
		// Image * bufImage;
	public:
		
		Filter () {};
		~Filter() {};

		// This virtual method has to be implemented in each Filter subclass for specific filters
		virtual Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y) = 0;

		// Apply the filter 
		Image operator << (imaging::Image& inpImage) {
		// Image apply(Image& inpImage) {

			//make a new image buffer with the same size to store the filter result
			Image bufImage(inpImage.getWidth(), inpImage.getHeight());

			// Apply the filter to the image replica
			for (unsigned int i = 0; i < bufImage.getHeight(); i++) {
				for (unsigned int j = 0; j < bufImage.getWidth(); j++) {

					bufImage(j,i) = filteredPixel(inpImage, j, i);
				}
			}

			// Return the result
			return bufImage;
		}

	};

}
#endif