#include <iostream>
#include <algorithm>
#include "Array.h"
#include "Vec3.h"

using namespace std;

namespace math{

	template <typename T>
	Array<T>::Array(unsigned int w, unsigned int h){

		this->width = w;
		this->height = h;

		buffer = new T[w * h];
	}

	template <typename T>
	Array<T>::Array(const Array<T> & source) {

		this->width = source.width;
		this->height = source.height;

		std::copy(source.buffer, source.buffer + width * height, buffer);
	}

	template <typename T>
	Array<T>::~Array() {
		delete[] buffer;
	}

	template <typename T>
	T & Array<T>::operator () (int x, int y) {

		//define zero color 3vec
		if ( x >= width || y >= width) {
			cout << "getPixel: Index out of image bounds!!!" << endl;
			exit(1);
		}

		return buffer[ y*width + x ];
	}

	template <typename T>
	const T & Array<T>::operator () (int x, int y) const{

		//define zero color 3vec
		if ( x >= width || y >= width) {
			cout << "getPixel: Index out of image bounds!!!" << endl;
			exit(1);
		}

		return buffer[ y*width + x ];
	}

	template <typename T>
	Array<T> & Array<T>::operator = (const Array<T> & source) {

		delete[] buffer;

		this->width = source.width;
		this->height = source.height;

		buffer = new T[width * height];

		std::copy(source.buffer, source.buffer + width * height, buffer);

		return (*this);
	}

	template <typename T>
	void * Array<T>::getRawDataPtr(){
		return (void *) buffer;
	}

	template <typename T>
	void Array<T>::resize(unsigned int new_width, unsigned int new_height){

		T * newbuffer = new T[new_width * new_height];

		for (unsigned int i = 0; i < new_height; i++) {
			for (unsigned int j = 0; j < new_width; j++) {
				if (i < height && j < width) {
					newbuffer[i * new_width + j] = buffer[i * width + j];
				}
				// else {
				// 	newbuffer[i * new_width + j] = 0.0;
				// }
			}
		}

		delete[] buffer;
		buffer = newbuffer;
	}

	// Here I must declare which types of Array class will be used
	template class Array<int>;
	template class Array<Vec3<float>>;

}