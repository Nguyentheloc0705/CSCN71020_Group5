#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Group Project/Inputs.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(Testing)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			float result = 5;
			float firstLength, secondLength, thirdLength;
			get_triangle_input( &firstLength, &secondLength, &thirdLength);
			Assert::AreEqual(firstLength, result);
		}
	};
}
