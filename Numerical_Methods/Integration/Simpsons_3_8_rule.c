/*

   Creator:- Krishna Purwar.
   Program for:- Calculatiing Integral of a function in a given interval.
   Foramula name:- Simpson's 3/8 rule.

   Definition:- 

     Suppose we have a function f(x), 
     and we have to find the integral of f(x) in [a,b].

     then, first divide the interval [a,b] into n equal intervals as:-

     x0 = a, x1 = a+h , x2 = a+2h, ... , x(n) = b = a + nh.
     where, h = (b-a)/n.

     Necessary Condition:- [ n must be a multiple of 3].

     Let the result of this integral be result.
     then,
      
    result = (3h/8)((y0 + yn) + 3(y1 + y2 + y4 + y5 + .. + y(n-2) + y(n-1)) + 
                      2(y3 + y6 + y9 + ... + y(n-3)).
    

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) powf(1 + x*x , -1 ) //Change the equation as per your problem.

int main() {
    
    //Change these values as per your equation's interval.
    const float a = 0 , b = 6;

    //Change the no. of intervals as per your question.
    const int n = 6;
    
    /*
      Immutable float variable for hoding the interval differnce.
      Do not change anything from this point.

    */
    const float h = (b-a)/n;

    float data[n+1];

    for( int i = 0 ; i <= n ; i++ ){
        float term = a + i*h;
        data[i] = f(term);
    }

    float sum = data[0] + data[n];

    for ( int i = 0 ; i < n ; i += 3 ){
        sum +=  3*(data[i+1] + data[i+2]) + 2*data[i+3];
    }
    sum -= (2*data[n]);

    float result = (3*sum)/8;

    printf("Result = %f\n", result);

    return 0;
}