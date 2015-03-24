//
//  Vector3.h
//  NubFlight
//
//  Created by Zachry Thayer on 3/23/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#ifndef __NubFlight__Vector3__
#define __NubFlight__Vector3__

#include <cmath>
#include <stdio.h>

typedef float Scalar;
typedef int Bool;
	
class Vector3 {
public:
	Scalar X;
	Scalar Y;
	Scalar Z;

	Vector3();
	Vector3(Scalar x, Scalar y, Scalar z);

	Vector3 operator+(const Vector3& vector) const;
	Vector3 operator-(const Vector3& vector) const;
	Vector3 operator-() const;
	Vector3 operator*(Scalar num) const;
	Vector3 operator/(Scalar num) const;

	Vector3& operator+=(const Vector3& vector);
	Vector3& operator-=(const Vector3& vector);
	Vector3& operator*=(Scalar num);
	Vector3& operator/=(Scalar num);

	Bool operator==(const Vector3& vector) const;
	Bool operator!=(const Vector3& vector) const;

	
	Vector3 operator*(Vector3 vector);
	Vector3 pow(Vector3 vector);
	void print() const;

	static const Vector3 Zero;
	static const Scalar Epsilon;
};
	
inline Bool Vector3::operator==(const Vector3& vector) const
{
	return X == vector.X && Y == vector.Y && Z == vector.Z;
}

inline Bool Vector3::operator!=(const Vector3& vector) const
{
	return X != vector.X || Y != vector.Y || Z != vector.Z;
}

inline Vector3 Vector3::operator+(const Vector3& vector) const
{
	return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
}

inline Vector3 Vector3::operator-(const Vector3& vector) const
{
	return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
}

inline Vector3 Vector3::operator-() const
{
	return Vector3(-X,-Y,-Z);
}

inline Vector3 Vector3::operator*(Scalar num) const
{
	return Vector3(X * num, Y * num, Z * num);
}

inline Vector3 Vector3::operator/(Scalar num) const
{
	return Vector3(X / num, Y / num, Z / num);
}

#endif /* defined(__NubFlight__Vector3__) */
