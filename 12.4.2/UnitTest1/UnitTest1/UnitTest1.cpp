#include "pch.h"
#include "CppUnitTest.h"
#include "../12.4.2/Project1/Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* one;
			one = new Elem;

			one->info = 11;
			one->link = new Elem;

			one->link->info = 84;
			one->link->link = new Elem;
						
			one->link->info = 60;
			one->link->link = new Elem;
			
			one->link->info = 15;
			one->link->link = new Elem;

			one->link->link->info = 68;
			one->link->link->link = one;

			Elem* first = one;
			Assert::AreEqual(Count(one, first, 0), 3);
		}
	};
}