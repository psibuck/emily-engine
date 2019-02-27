//
//  MathTests.cpp
//  Emily
//
//  When any new mathematical functionality is added tests should be added here that will fail
//  on project startup if any maths is broken
//
//  Created by Archie Buck on 21/02/2019.
//  Copyright © 2019 Archie Buck. All rights reserved.
//

#include "Code/Math/MathTests.h"

#include "Code/Math/Vector3.h"

namespace EMILY
{
    //--
    // The public call that triggers the tests to run
    //--
    void MathTests::run( void )
    {
        test_vector_operations();
    }
    
    //--
    // Tests for the vector class "Code/Math/Vector3.h"
    //--
    void MathTests::test_vector_operations( void )
    {
        const int x = 1;
        const int y = 2;
        const int z = 3;
        const Vector3 vector1 = Vector3( x, y, z );
        
        //! Addition
        const Vector3 addition = vector1 + vector1;

        if(   addition.x != 2*x
           || addition.y != 2*y
           || addition.z != 2*z )
        {
            // Assert test failed
            // failed to add the vectors correctly
        }
        
        //! Subtraction
        const Vector3 subtraction = addition - vector1;
        if(   subtraction.x != x
           || subtraction.y != y
           || subtraction.z != z )
        {
            // Assert test failed
            // failed to subtract the vectors successfully
        }
        
        //! Inequality
        if( subtraction != vector1 )
        {
            // Assert test failed
            // Failed to equate the vectors
        }
        
        //! Equality
        if( !(subtraction == vector1 ))
        {
            // Assert test failed
            // Failed to successfully check equality
        }
        
        //! Scalar
        const Vector3 scaled_vector = vector1 * 2;
        if(   scaled_vector.x != 2*x
           || scaled_vector.y != 2*y
           || scaled_vector.z != 2*z )
        {
            // Assert test failed
            // Failed to successfully scale a vector
        }
    }
}

