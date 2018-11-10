#include "CppUnitTest.h"
#include "../DSA-Preparation1/DynamicArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArray_Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(InitialisationAndGetSize)
		{
			DynamicArray<int> test;
			int result = test.GetSize();
			int expected = 0;

			Assert::AreEqual(result, expected);

		}

		TEST_METHOD(EmptyPop)
		{
			DynamicArray<int> test;
			try
			{
				test.PopBack();
			}
			catch (const std::out_of_range& e)
			{
				Assert::AreEqual(1, 1);
			}
			
			
		}

		TEST_METHOD(EmptyPushback)
		{
			DynamicArray<int> test;
			test.PushBack(1);
			test.PushBack(2);
			
			
			Assert::AreEqual(test[1], 2);
		}

		TEST_METHOD(RemoveAt)
		{
			DynamicArray<int> test;
			test.PushBack(1);
			test.PushBack(2);

			test.RemoveAt(0);


			Assert::AreEqual(test[0], 2);
		}

		TEST_METHOD(Resize)
		{
			DynamicArray<int> test;
			test.PushBack(1);
			test.PushBack(2);
			test.PushBack(3);
			test.PushBack(4);
			test.PushBack(5);
			test.PushBack(6);


			Assert::AreEqual(test[5], 6);
		}

		TEST_METHOD(ResizeKeepOld)
		{
			DynamicArray<int> test;
			test.PushBack(1);
			test.PushBack(2);
			test.PushBack(3);
			test.PushBack(4);
			test.PushBack(5);
			test.PushBack(6);


			Assert::AreEqual(test[1], 2);
		}


		TEST_METHOD(InsertAfter)
		{
			DynamicArray<int> test;
			test.PushBack(1);
			test.PushBack(2);
			test.InsertAfter(0, 1);


			Assert::AreEqual(test[1], 0);
		}

		TEST_METHOD(Equals)
		{
			DynamicArray<int> test1;
			DynamicArray<int> test2;

			test1.PushBack(1);
			test1.PushBack(2);

			test2.PushBack(3);
			test2.PushBack(4);

			test1 = test2;


			Assert::AreEqual(test1[1], 4);
		}

		TEST_METHOD(AccessOperator)
		{
			DynamicArray<int> test1;

			test1.PushBack(1);
			test1.PushBack(2);

			test1[1] = 3;


			Assert::AreEqual(test1[1], 3);
		}

	};
}