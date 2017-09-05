#include "stdafx.h"

#include "NullRefTests.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
	TEST_CLASS(NullRefTests_Test)
	{
	public:

		TEST_METHOD(Database___DbRef_ToDeleted_ThrowsNullReferenceException)
		{
			bool m_TestImplemented = false;
			Assert::IsTrue(m_TestImplemented);
		}
	};
}