#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../../../../Downloads/CSCN71020_Group5-David/CSCN71020_Group5-David/Group Project/Inputs.h"
#include "../../../../Downloads/CSCN71020_Group5-David/CSCN71020_Group5-David/Group Project/interiorAngles.h"
#include "../../../../Downloads/CSCN71020_Group5-David/CSCN71020_Group5-David/Group Project/isTriangle.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectTesting
{
	TEST_CLASS(ProjectTesting)
	{
	public:
		
		TEST_METHOD(isTriangle_pass_case_base)
		{
			float l1 = 3, l2 = 4, l3 = 5;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(isTriangle_pass_case_equilateral)
		{
			float l1 = 5, l2 = 5, l3 = 5;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(isTriangle_pass_case_isosceles)
		{
			float l1 = 5, l2 = 5, l3 = 8;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(isTriangle_fail_case_123)
		{
			float l1 = 1, l2 = 2, l3 = 3;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(isTriangle_fail_case_0)
		{
			float l1 = 0, l2 = 4, l3 = 5;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(isTriangle_fail_case_Not_Triangle)
		{
			float l1 = 10, l2 = 11, l3 = 30;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(false, result);
		}

	};
}
