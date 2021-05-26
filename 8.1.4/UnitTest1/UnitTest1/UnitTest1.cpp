#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1.4/Project1/Project1/Source.cpp"
#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char s[10] = "whileaaa";
			char a[10] = "***aaa";
			char str[10];
			int d;
			d = 8; 
			Change(s, str, 0, 0, d);
			Assert::AreEqual(s, a);
		}
	};
}