#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char s[10] = "whileaaaa";
			Assert::AreEqual(true, Include(s, 0));
		}
	};
}