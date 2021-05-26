#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1.6/Project1/Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char s[100] = { "whileuuaa" };
			char l[100] = { "***uuaa" };
			Change(s);
			Assert::AreEqual(s, l);
		}
	};
}