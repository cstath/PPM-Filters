#include <gtest/gtest.h>
#include "Image.h"
#include "Array.h"
#include "Vec3.h"

using namespace std;
using namespace math;
using namespace imaging;


TEST(ImageTests, GetSetPixelTest) {

	Image testImage((unsigned int)3, (unsigned int)2);
	// SetPixel
	Vec3<component_t> pixelColor(0.2, 0.3, 0.4);
	testImage((unsigned int)2, (unsigned int)1) = pixelColor;
	// GetPixel
	Vec3<component_t> retPix = testImage((unsigned int)2, (unsigned int)1);

	EXPECT_NEAR(0.2, retPix.r, 0.00001);
	EXPECT_NEAR(0.3, retPix.g, 0.00001);
	EXPECT_NEAR(0.4, retPix.b, 0.00001);
}

TEST(ImageTests, PPMAverageTest) {
	Image * testImage = new Image(3, 2);
	Vec3<component_t> pixelColor(0.2, 0.3, 0.4);
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			(*testImage)(j, i) = pixelColor;
		}
	}

	Vec3<component_t> avgCol = testImage->imageAveragePPM();

	EXPECT_NEAR(0.2, avgCol.r, 0.00001);
	EXPECT_NEAR(0.3, avgCol.g, 0.00001);
	EXPECT_NEAR(0.4, avgCol.b, 0.00001);

	delete testImage;

}

