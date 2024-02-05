#pragma once
#include "pch.h"
#include "framework.h"

#ifdef VECTOR_EXPORTS
#define DllExport __declspec(dllexport)
#else
#define DllExport __declspec(dllimport)
#endif

#pragma comment(lib, "C:\\Users\\roman\\source\\repos\\Number\\x64\\Debug\\Number")

#include "C:\\Users\\roman\\source\\repos\\Number\\Number\\Number.h"
namespace vector {

	class __declspec(dllimport) Vector {
	public:
		typedef Number::Number Number;
		Vector(Number x, Number y);
		Vector() = default;
		~Vector() = default;

		double GetAngle();
		double GetRadius();
		Number GetX();
		Number GetY();
		Vector operator+(const Vector& other);
	private:
		Number x_;
		Number y_;
	};

	extern __declspec(dllimport) const Vector ONE_ONE;
	extern __declspec(dllimport) const Vector ZERO_ZERO;

}
