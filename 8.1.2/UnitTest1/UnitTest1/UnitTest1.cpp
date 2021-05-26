#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Project1"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char s[10] = "whileasdxawdaw";
			char a[10] = "***asdxawdaw";
			Change(s);
			Assert::AreEqual(s, a);
		}
	};
}