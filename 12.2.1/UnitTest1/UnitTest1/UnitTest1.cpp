  
#include "pch.h"
#include "CppUnitTest.h"
#include "../12.1.1/Project1/Project1/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			Elem* start = NULL;
			Elem* last = NULL;
			enqueue(start, last, 35);

			Assert::AreEqual(start->info, 35);

		}
	};
}


