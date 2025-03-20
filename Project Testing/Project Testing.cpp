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
		
		TEST_METHOD(isTriangle_pass_case)
		{
			float l1 = 15, l2 = 16, l3 =15;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(isTriangle_pass_case)
		{
			float l1 = 15, l2 = 16, l3 = 15;
			bool result = isTriangle(l1, l2, l3);
			Assert::AreEqual(true, result);
		}
	};
}
