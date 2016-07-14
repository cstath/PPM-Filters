#include <iostream>
#include <gtest/gtest.h>
#include "Image.h"
#include "Array.h"
#include "Vec3.h"

using namespace std;
using namespace math;
using namespace imaging;

TEST(ColorClassChecks, ColorIndexing) {
	Vec3<float> a(0.1, 0.2, 0.3);

	EXPECT_NEAR(0.1, a.x, 0.00001);
	EXPECT_NEAR(0.2, a.y, 0.00001);
	EXPECT_NEAR(0.3, a.z, 0.00001);
}

TEST(ColorClassChecks, ColorAddition) {
	Vec3<float> a(0.1, 0.2, 0.3);
	Vec3<float> b(0.5, 0.6, 0.7);
	Vec3<float> c = a + b;

	EXPECT_NEAR(0.6, c.r, 0.00001);
	EXPECT_NEAR(0.8, c.g, 0.00001);
	EXPECT_NEAR(1.0, c.b, 0.00001);
}



TEST(ArrayClassTests, SetGetData) {

	unsigned int width = 3, height = 2;

	Array<int> intArray(width, height);

	//component_t * buf = new component_t[width*height*COLORS_PER_PIXEL];

	intArray(0, 0) = 0; intArray(1, 0) = 1; intArray(2, 0) = 2;
	intArray(0, 1) = 3; intArray(1, 1) = 4; intArray(2, 1) = 5;

	EXPECT_EQ(intArray(0, 0), 0);
	EXPECT_EQ(intArray(1, 0), 1);
	EXPECT_EQ(intArray(2, 0), 2);
	EXPECT_EQ(intArray(0, 1), 3);
	EXPECT_EQ(intArray(1, 1), 4);
	EXPECT_EQ(intArray(2, 1), 5);

	// retPix = testImage.getPixel(width, height);

	// CHECK_CLOSE(retPix.r, 0.0, 0.00001);
	// CHECK_CLOSE(retPix.g, 0.0, 0.00001);
	// CHECK_CLOSE(retPix.b, 0.0, 0.00001);

}



TEST(ImageTests, GetSetPixelTest) {

	Image testImage((unsigned int)3, (unsigned int)2);
	// SetPixel
	Vec3<float> pixelColor(0.2, 0.3, 0.4);
	testImage((unsigned int)2, (unsigned int)1) = pixelColor;
	// GetPixel
	Vec3<float> retPix = testImage((unsigned int)2, (unsigned int)1);

	EXPECT_NEAR(0.2, retPix.r, 0.00001);
	EXPECT_NEAR(0.3, retPix.g, 0.00001);
	EXPECT_NEAR(0.4, retPix.b, 0.00001);
}

TEST(ImageTests, PPMAverageTest) {
	Image * testImage = new Image(3, 2);
	Vec3<float> pixelColor(0.2, 0.3, 0.4);
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			(*testImage)(j, i) = pixelColor;
		}
	}

	Vec3<float> avgCol = testImage->imageAveragePPM();

	EXPECT_NEAR(0.2, avgCol.r, 0.00001);
	EXPECT_NEAR(0.3, avgCol.g, 0.00001);
	EXPECT_NEAR(0.4, avgCol.b, 0.00001);

}

