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

     Necessary Condition:- [ n must be a multiple of 2].

     Let the result of this integral be result.
     then,
      
    result = (h/3)((y0 + y1) + 4(y1 + y3 + y5 +.. + y(n-1)) + 2(y2 + y4 +.. + y(n))).
    
    or

    result = (h/3)((Sum of first and last ordinates) + 
                     4(Sum of remaining even(term no.) ordinates)) +
                     2(Sum of remaining odd(term no.) ordinates)).


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) pow( 1 + x*x , -1)  //Change the equation as per your problem.

int main() {
 
  //Change these values according to your equation's interval.
  const float a = 0 , b= 1;
  
  //Change the no. of intervals as per your question
  const int n = 4;

  /* 
    Immutable float variable for holding interval difference.
    Do not change anything from this point.
  */
  const float h = (b-a)/n;
  
  float data[n+1];

  for( int  i = 0 ; i <= n ; i++ ) {
    float term = a + i*h;
    data[i] = f(term);
  }

  float sum = data[0] + data[n];

  for ( int i = 1 ; i < n ; i+= 2 ) {
     sum += (4*data[i]) + (2*data[i+1]);
  }

  sum -= 2*data[n];

  float result = (sum*h)/3;

  printf("Result = %.3f\n", result);

  return 0;

}