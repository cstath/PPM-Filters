#include <iostream>
#include <gtest/gtest.h>
#include "Vec3.h"

using namespace std;
using namespace math;

TEST(Vec3ClassChecks, ColorIndexing) {
	Vec3<float> a(0.1, 0.2, 0.3);

	EXPECT_NEAR(0.1, a.x, 0.00001);
	EXPECT_NEAR(0.2, a.y, 0.00001);
	EXPECT_NEAR(0.3, a.z, 0.00001);
}

TEST(Vec3ClassChecks, ColorAddition) {
	Vec3<float> a(0.1, 0.2, 0.3);
	Vec3<float> b(0.5, 0.6, 0.7);
	Vec3<float> c = a + b;

	EXPECT_NEAR(0.6, c.r, 0.00001);
	EXPECT_NEAR(0.8, c.g, 0.00001);
	EXPECT_NEAR(1.0, c.b, 0.00001);
}