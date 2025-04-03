#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Group Project/sidelengths.h"
}
extern "C" SIDE getSideLength(double, double, double, double);
extern "C" QUADRI getQuadri(double, double, double, double, double, double, double, double);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GroupProjecttests
{
	TEST_CLASS(getSideLengthTests)
	{
	public:
		
		TEST_METHOD(WholeNumbersOnX)
		{
			double x1 = 10.0;
			double y1 = 0.0;
			double x2 = 17.0;
			double y2 = 0.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(7.0, A.length);
		}

		TEST_METHOD(WholeNumbersOnY)
		{
			double x1 = 0.0;
			double y1 = 5.0;
			double x2 = 0.0;
			double y2 = 19.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(14.0, A.length);
		}

		TEST_METHOD(WholeNumbersOnXY)
		{
			double x1 = 7.0;
			double y1 = 9.0;
			double x2 = 10.0;
			double y2 = 13.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(5.0, A.length);
		}

		TEST_METHOD(WholeNegDiffX)
		{
			double x1 = 20.0;
			double y1 = 0.0;
			double x2 = 4.0;
			double y2 = 0.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(16.0, A.length);
		}

		TEST_METHOD(WholeNegDiffY)
		{
			double x1 = 0.0;
			double y1 = 33.0;
			double x2 = 0.0;
			double y2 = 13.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(20.0, A.length);
		}

		TEST_METHOD(WholeNegativesOnX)
		{
			double x1 = -3.0;
			double y1 = 0.0;
			double x2 = -27.0;
			double y2 = 0.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(24.0, A.length);
		}

		TEST_METHOD(WholeNegativesOnY)
		{
			double x1 = 0.0;
			double y1 = -14.0;
			double x2 = 0.0;
			double y2 = -7.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(7.0, A.length);
		}

		TEST_METHOD(DecimalsOnX)
		{
			double x1 = 5.9;
			double y1 = 0.0;
			double x2 = 13.4;
			double y2 = 0.0;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(7.5, A.length);
		}

		TEST_METHOD(DecimalsOnY)
		{
			double x1 = 0.0;
			double y1 = 9.3;
			double x2 = 0.0;
			double y2 = 16.1;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(6.80, A.length); //expected: 6.8, actual 6.8
		}
		TEST_METHOD(FixedDecimalsOnY)
		{
			double x1 = 0.0;
			double y1 = 9.3;
			double x2 = 0.0;
			double y2 = 16.1;
			SIDE A = getSideLength(x1, y1, x2, y2);
			int a = trunc(A.length * 1000000.0);//precision used when doubles are printed
			Assert::AreEqual(6800000,a);
		}

		TEST_METHOD(DecimalsOnXY)
		{
			double x1 = 4.41;
			double y1 = 9.3;
			double x2 = 13.32;
			double y2 = 21.21;
			SIDE A = getSideLength(x1, y1, x2, y2);
			Assert::AreEqual(14.87401089, A.length); //mathematical result: 14.87401089. test only shows 3 digits. expected: 14.874, actual: 14.874
		}

		TEST_METHOD(FixedDecimalsOnXY)
		{
			double x1 = 4.41;
			double y1 = 9.3;
			double x2 = 13.32;
			double y2 = 21.21;
			SIDE A = getSideLength(x1, y1, x2, y2);
			int a = trunc(A.length * 1000000);//precision used when doubles are printed
			Assert::AreEqual(14874010,a);
		}

	};

	TEST_CLASS(getQuadriTests)
	{
	public:

		TEST_METHOD(dos)
		{
		}

	};
}
