#ifndef _FILTER
#define _FILTER

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
		
		Filter ();
		virtual ~Filter();

		// This virtual method has to be implemented in each Filter subclass for specific filters
		virtual Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y) = 0;

		// Apply the filter 
		Image operator << (imaging::Image& inpImage);

		string getFilterName();

		friend ostream &operator<<( ostream & output, const Filter & filter );

	};

}
#endif