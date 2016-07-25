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
		
		DiffFilter ();
		virtual ~DiffFilter();

		virtual Vec3<component_t> filteredPixel( imaging::Image& inpImage, unsigned int x, unsigned int y);

	};

}
#endif