/*

   Creator:- Krishna Purwar.
   Program for:- Calculatiing Integral of a function in a given interval.
   Foramula name:- Simpson's 1/3 rule.

   Definition:- 

     Suppose we have a function f(x), 
     and we have to find the integral of f(x) in [a,b].

     then, first divide the interval [a,b] into n equal intervals as:-

     x0 = a, x1 = a+h , x2 = a+2h, ... , x(n) = b = a + nh.
     where, h = (b-a)/n.

     Necessary Condition:- [ n must be a multiple of 1].

     Let the result of this integral be result.
     then,
      
    result = (h/2)((y0 + y(n)) + 2(y1 + y2 + y3 + ... + y(n-1))).
    
    or

    result = (h/2)((Sum of first and last ordinates) + 
                   2(sum of remaining ordinates)).
                    
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) powf( x, -1)  //Change the equation with your problem.

int main() {

    //Change these intervals according to your equation's interval.
    const float a = 1.0, b = 2.0;

    //Change the number of intervals as per the question.
    const int n = 4;
    
    /*
      Immutable float variable for holding the interval difference.
      Do not change anything from this point.
    
    */
    const float h = (b - a) / n;

   
   float data[n+1];

   for( int i = 0 ; i <= n ; i++ ){
      float term = a + i*h ;
      data[i] = f(term);
   }
        

    float sum = data[0] + data[n];

    for( int  i = 1 ; i < n ; i++ ) {
        sum += (2*data[i]);
    }

    float result = (sum*h)/2;

    printf("Result = %.3f\n", result);


  return 0;
}