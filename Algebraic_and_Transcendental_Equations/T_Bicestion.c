/*
  Creator:- Krishna Purwar
  Equation Type:- Transcendental and Algebraic Both.
  Program Type:- Specific.

  Method Name:- Bisection Method.

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define f(x) (2*x) - log10f(x) - 6;  //Change the equation according to your problem...

int main() {
    /*
       Change the intervals [a,b] as per the equation
       such that f(a) < 0 & f(b) > 0...
    
    */
    float a = 3 , b = 4;  

    /*
      Change this value as described the formula:-
      hundreds = 10^(x), where x = No. of decimals places...
    */
    int hundreds = 1000;

    //Do not change anything from here ...
    while(true) {
        
        float mid = (a+b)/2;

        float result = f(mid);

        if(result == 0) {
            printf("%f is the root\n", mid);
            break;
        }
        else if(result > 0) {
            b = mid;
        }
        else {
            a = mid;
        }

        if((int)(a*hundreds) == (int)(b*hundreds)){
            printf("%f is the required root\n",mid);
            break;
        }

    }
    return 0;
}