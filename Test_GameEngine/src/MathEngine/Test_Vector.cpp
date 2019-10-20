#include"../pch.h"
#include "CppUnitTest.h"
#include "MathEngine/Vector.h"
#include "MathEngine/Vector.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<> static std::wstring ToString<Vector>(const Vector& t) { return std::wstring(); }
		}
	}
}

namespace TestGameEngine {

	TEST_CLASS(Test_Vector) {

	public:
		TEST_METHOD(Dot) {
			Vector v(4.0f, 5.0f, -6.0f);
			Vector w(2.0f, 0.0f, 1.0f);

			Assert::AreEqual(v.Dot(w), 2.0f);
		}

		TEST_METHOD(Cross) {
			Vector v(4.0f, 5.0f, -6.0f);
			Vector w(2.0f, 0.0f, 1.0f);

			Assert::AreEqual(v.Cross(w), Vector(5.0f, -16.0f, -10.0f));
		}

		TEST_METHOD(Normalize) {
			Vector v(3.0f, 4.0f, 5.0f);

			Assert::AreEqual(v.Normalize(), Vector(0.6f, 0.8f, 1.0f));
		}

		TEST_METHOD(Lenght) {
			Vector v(1.0f, 2.0f, 2.0f);

			Assert::AreEqual(v.Length(), 3.0f);
		}

		TEST_METHOD(Add) {
			Vector v(1.5f, 6.2f, 4.5f);
			Vector w(3.0f, 6.7f, -2.2f);

			Assert::AreEqual(v + w, Vector(4.5f, 12.9f, 2.3f));
		}

		TEST_METHOD(Substract) {
			Vector v(1.5f, 6.2f, 4.5f);
			Vector w(3.0f, 6.7f, -2.2f);

			Assert::AreEqual(v - w, Vector(-1.5f, -0.5f, 6.7f));
		}

		TEST_METHOD(Multiply) {
			Vector v(1.2f, 6.0f, -2.9f);
			Vector w = v * 2.5f;

			Assert::AreEqual(w, Vector(3.0f, 15.0f, -7.25f));
		}

		TEST_METHOD(Divide) {
			Vector v(1.2f, 6.0f, 2.6f);
			Vector w = v / 2;

			Assert::AreEqual(w, Vector(0.6f, 3.0f, 1.3f));
		}

		TEST_METHOD(Equal) {
			bool b = Vector(1.5f, 6.0f, 0.0f) == Vector(1.5f, 6.0f, 0.0f);
			Assert::IsTrue(b);
		}

		TEST_METHOD(NotEqual) {
			bool b = Vector(1.5f, 6.0f, 0.0f) != Vector(1.5f, 6.0f, 0.0f);
			Assert::IsFalse(b);
		}
	};
}
