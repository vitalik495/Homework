#include "pch.h"
#include "CppUnitTest.h"
#include "../8.1.5/Project1/Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* s = "whileaaaa";
			char* cs = "while";
			Assert::AreEqual(true, Include(s, cs));
		}
	};
}