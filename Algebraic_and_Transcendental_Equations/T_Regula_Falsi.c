/*
   Creator:-  Krishna Purwar
   Equation Type:- Transcendental & Algebraic Equations.
   Program Type:- Specific.


   Method name:- Reguala Falsi Method.

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define f(x) (expf(x) - (4*x));  //Replace the equation according to your problem.

float next_point_in(float , float); //Function Prototype.

int main() {
    
    /*
      Change the intervals[a,b] such that:-
      f(a) < 0 & f(b) > 0.
    
    */
    float a = 2, b = 2.5;
    
    /*
      Change this value as per the following formula:-
      hundreds = 10^(x), where x = No. of decimal places.
    */
    int hundreds = 1000;

    //Do not interfere with the following code.
    float next_point = 0.0, previous_point = 0.0;

    while(true) {
     
     next_point =  next_point_in(a ,b);

     float result = f(next_point);

     if(result == 0) {
        printf("%f is the root\n", next_point);
        break;
     }
     else if(result > 0) {
        b = next_point;
     }
     else {
        a = next_point;
     }

     if((int)(previous_point*hundreds) == (int)(next_point*hundreds)){
        printf("%f is the required root upto desired accuracy\n", next_point);
        break;
     }  

     previous_point = next_point;
    }


  return 0;
}
//Function for finding the next point.
float next_point_in(float a,float b){
    float first_term =  f(b);
    float second_term = f(a);
    float diff = first_term- second_term;
    float point = (a*first_term - b*second_term)/diff;

    return point;

}
