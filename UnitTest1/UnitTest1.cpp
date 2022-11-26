#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Bao\source\repos\Assignment2DSA\Assignment2DSA\ConcatStringTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestConcatStringTree) {
	public:
		TEST_METHOD(SizeTest) {
			//Test 1 : Test size and concat (4 node and a lot concat) 
			string t1 = "This_i", t2 = "sI_", t3 = "vy_T", t4 = "ran_", t11 = "a";
			ConcatStringTree s1("This_i");
			ConcatStringTree s2("sI_");
			ConcatStringTree s3("vy_T");
			ConcatStringTree s4("ran_");
			ConcatStringTree s11("a");
			ConcatStringTree s5(s1.concat(s2));
			ConcatStringTree s6(s3.concat(s4));
			ConcatStringTree s7(s5.concat(s6));
			ConcatStringTree s8 = s1.concat(s3);
			ConcatStringTree s9 = s1.concat(s4);
			ConcatStringTree s10 = s8.concat(s9);
			ConcatStringTree s12(s7.concat(s10));

			//Test for size
			Assert::AreEqual(s1.length(), (int)t1.length());
			Assert::AreEqual(s11.length(), (int)t11.length());
			Assert::AreEqual(s5.length(), (int)(t1 + t2).length());
			Assert::AreEqual(s7.length(), (int)(t1 + t2 + t3 + t4).length());
			Assert::AreEqual(s8.length(), (int)(t1 + t4).length());
			Assert::AreEqual(s10.length(), (int)(t1 + t1 + t3 + t4).length());
			Assert::AreEqual(s12.length(), (int)(t1 + t2 + t3 + t4 + t1 + t1 + t3 + t4).length());
		}
		TEST_METHOD(getTest) {
			//Test 2 : Test concat and getChar
			string t1 = "This_i", t2 = "sI_", t3 = "vy_T", t4 = "ran_", t11 = "a";
			ConcatStringTree s1("This_i");
			ConcatStringTree s2("sI_");
			ConcatStringTree s3("vy_T");
			ConcatStringTree s4("ran_");
			ConcatStringTree s11("a");
			ConcatStringTree s5(s1.concat(s2));
			ConcatStringTree s6(s3.concat(s4));
			ConcatStringTree s7(s5.concat(s6));
			ConcatStringTree s8 = s1.concat(s3);
			ConcatStringTree s9 = s1.concat(s4);
			ConcatStringTree s10 = s8.concat(s9);
			ConcatStringTree s12(s7.concat(s10));

			//Test
			Assert::AreEqual(s3.get(3), t3[3]);

		}
		TEST_METHOD(indexOfTest) {

		}
		TEST_METHOD(toStringTest) {

		}
		TEST_METHOD(toStringPreTest) {

		}
		TEST_METHOD(revTest) {

		}
		TEST_METHOD(subStrTest) {

		}
		TEST_METHOD(AllTest) {

		}

	};

	TEST_CLASS(ParentsTree) {
	public:
		TEST_METHOD(insertNodeTest);
		TEST_METHOD(deleteNodeTest);
		TEST_METHOD(sizePTree);
		TEST_METHOD(toStringTest);


	};
}
