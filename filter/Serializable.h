#ifndef _SERIALIZABLE_
#define _SERIALIZABLE_

#include <iostream>
#include <string>

class Serializable
{
public:
	virtual bool operator << (std::string filename) = 0;     // Read the contents of an object from the specified file
	virtual bool operator >> (std::string filename) = 0;     // Write the contents of an object to the specified file
};


#endif
