#include <gtest/gtest.h>
#include "Array.h"
#include "Vec3.h"

using namespace std;
using namespace math;

TEST(ArrayClassTests, SetGetData) {

	unsigned int width = 3, height = 2;

	Array<int> intArray(width, height);

	intArray(0, 0) = 0; intArray(1, 0) = 1; intArray(2, 0) = 2;
	intArray(0, 1) = 3; intArray(1, 1) = 4; intArray(2, 1) = 5;

	EXPECT_EQ(intArray(0, 0), 0);
	EXPECT_EQ(intArray(1, 0), 1);
	EXPECT_EQ(intArray(2, 0), 2);
	EXPECT_EQ(intArray(0, 1), 3);
	EXPECT_EQ(intArray(1, 1), 4);
	EXPECT_EQ(intArray(2, 1), 5);

}