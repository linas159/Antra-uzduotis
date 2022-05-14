#include "pch.h"
#include "../../test/funkcijos1.cpp"

TEST(CalculationTest, Average) {
	vector<int> v{ 0 };
	EXPECT_EQ(vidurkis(v), 0);

	vector<int> v1{ 8, 1, 2, 4, 3 };
	EXPECT_EQ(vidurkis(v1), 3.6);

	vector<int> v2{ };
	EXPECT_EQ(vidurkis(v2), 0);
}

TEST(CalculationTest, Median) {
	vector<int> v{ 0 };
	EXPECT_EQ(mediana(v), 0);

	vector<int> v1{ 8, 1, 2, 4, 3 };
	EXPECT_EQ(mediana(v1), 3);

	vector<int> v2{ 8, 9, 2, 4, 3, 10 };
	EXPECT_EQ(mediana(v2), 6);

	vector<int> v3{ };
	EXPECT_EQ(mediana(v3), 0);
}

TEST(ValueVerification, Grade) {
	EXPECT_TRUE(ar_pazymys("0"));
	EXPECT_TRUE(ar_pazymys("10"));
	EXPECT_TRUE(ar_pazymys("4"));
	EXPECT_FALSE(ar_pazymys("-8"));
	EXPECT_FALSE(ar_pazymys("12"));
	EXPECT_FALSE(ar_pazymys("t"));
	EXPECT_FALSE(ar_pazymys("U"));
	EXPECT_FALSE(ar_pazymys("2.6"));
}

