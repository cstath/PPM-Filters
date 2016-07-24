#ifndef _ARRAY_
#define _ARRAY_

namespace math
{

	//---------------------------------------------------------------------------------------------
	// Do NOT modify this section. For the implementation, see comment below the class declaration

	template <typename T>
	class Array
	{
	protected:
		T * buffer;
		unsigned int width, height;

	public:

		unsigned int getWidth() const { return width; }      // returns the width of the image
		unsigned int getHeight() const { return height; }    // returns the height of the image

		void * getRawDataPtr();                              // Obtain a pointer to the internal data
		// This is NOT a copy of the internal image data, but rather 
		// a pointer to the internally allocated space, so DO NOT
		// attempt to delete the pointer. 

		T & operator () (int x, int y);                      // return a reference to the element at position (column x, row y) 
		// of the array (zeor-based)

		const T & operator () (int x, int y) const;          // return a reference to the element at position (column x, row y) 
		// of the array (zeor-based)

		Array(unsigned int w, unsigned int h);               // Constructors. No default constructor allowed, as it makes no sense.
		Array(const Array<T> & source);                      //

		Array & operator = (const Array<T> & source);        // Copy assignment operator.

		bool operator == (const Array<T> & source) const;    // returns true of the current array and the source have the same dimensions AND 
		// one by one their elements of type T are the same. 

		void resize(unsigned int new_width, unsigned int new_height);	// Change the internal data storage size to the new ones.
		// If the one or both of the dimensions are smaller, clip the 
		// by discarding the remaining elements in the rows / columns outside
		// the margins. If the new dimensions are larger, pad the old elements
		// with elements initialized ot their default value (i.e. with their default initializer/constructor).

		virtual ~Array();									 // The distructor

	};

	// This is a templated class so include its implementation in the header file below this line:
	//--------------------------------------------------------------------------------------------


	


} // namespace math
#endif
