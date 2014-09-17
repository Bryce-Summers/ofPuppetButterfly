//
//  cubic_spline.cpp
//  ofPuppetButterfly
//
//  Created by Tube on 9/16/14.
//
//

#include "cubic_spline.h"


// Coefficients of a cubic polynomial.

    
cubic_spline::cubic_spline(ofVec3f p1, ofVec3f t1, ofVec3f p2, ofVec3f t2)
{
	/*
	 * A =  2*p1 - 2*p2 + t1 + t2;
	 * B = -3*p1 + 3*p2 - t1 - 2*t2
	 * C = t2;
	 * D = p1;
	 */
		
	A = (2*p1)  - (2*p2) + t1 + t2;
	B = (-3*p1) + (3*p2) - t1 - (2*t2);
	C = t2;
	D = p1;
}
    
	// REQUIRES : input should be between 0 and 1.0;
ofVec3f cubic_spline::eval(float input)
{
	if(input < 0 || input > 1.0)
	{
		//throw new Error("Error: Input not in function domain!");
	}
	
	double x_1 = input;
	double x_2 = x_1*input;
	double x_3 = x_2*input;
		
	return A*x_3 + B*x_2 + C*x_1 + D;
    
}