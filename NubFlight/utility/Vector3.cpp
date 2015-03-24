//
//  Vector3.cpp
//  NubFlight
//
//  Created by Zachry Thayer on 3/23/15.
//  Copyright (c) 2015 A_Nub. All rights reserved.
//

#include "Vector3.h"

#include <limits>

const Vector3 Vector3::Zero = Vector3(0,0,0);
const Scalar Vector3::Epsilon = std::numeric_limits<Scalar>::epsilon();

Vector3::Vector3()
{
}

Vector3::Vector3(Scalar x, Scalar y, Scalar z)
: X( x )
, Y( y )
, Z( z )
{
}

Vector3& Vector3::operator+=(const Vector3& vector)
{
	X += vector.X;
	Y += vector.Y;
	Z += vector.Z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& vector)
{
	X -= vector.X;
	Y -= vector.Y;
	Z -= vector.Z;
	return *this;
}

Vector3& Vector3::operator*=(Scalar num)
{
	X *= num;
	Y *= num;
	Z *= num;
	return *this;
}

Vector3& Vector3::operator/=(Scalar num)
{
	this->X /= num;
	this->Y /= num;
	this->Z /= num;
	return *this;
}

void Vector3::print() const
{
	printf("X:%f, Y:%f, Z:%f\n", X, Y, Z);
}