#include "pch.h"
#include "CppUnitTest.h"
#include "../8.2/Project3/Project3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Something
{
	TEST_CLASS(Something)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char s[100] = { "baba bg b aaa" };
			Assert::AreEqual(3, Count(s));
		}
	};
}