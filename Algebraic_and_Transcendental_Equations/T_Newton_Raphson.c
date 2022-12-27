/*
  Creator:- Krishna Purwar.
  Equation Type:- Transcendental & Algebraic Equations.
  Program Type:- Specific.

  Method name:- Newton Raphson Method.


*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define f(x) ((x*x) - cosf(x) + x);  //Replace the eauation according to your problem.
#define Df(x) ((2*x) + sinf(x) + 1);  //Replace with derivative of the same equation.

float next_point_at(float);  //Function Prototype.

int main() {

   /*
     Change the intervals as per equation such that:-
     f(a) < 0 & f(b) > 0.
   
   */
   float a = 0.0 , b = 1;


   /*
     Change this value as per the following formula:-
     hundreds = 10^(x), where x = No. of decimal places.
   */
   int hundreds = 1000;

   /*
      Change the first approximation as described:-

      i). If,   f(a) = f(b)
          then,  first_approximation = (a+b)/2;

      ii). If f(a) is more close to 0, then f(b),
           then, first_approximation = a + 0.25;

      iii). If f(b) is more close to 0, then f(a),
           then, first_approximation = b - 0.25;
  
   */
   float first_approximation = 0.25;

   float next_point = 0.0, previous_point = first_approximation;

   while(true) {
      next_point = next_point_at(previous_point);

      if((int)(previous_point*hundreds) == (int)(next_point*hundreds)){
        printf("%f is the required root upto desired accuracy\n", next_point);
        break;
      }

      previous_point = next_point;
   }
    return 0;
}
//Function for finding the next approximation by giving it the previous point.
float next_point_at(float point) {
    float numerator = f(point);
    float denominator = Df(point);
    float result = point - (numerator/denominator);

    return result;

}