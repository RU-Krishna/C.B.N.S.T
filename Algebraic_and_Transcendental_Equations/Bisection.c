 /*

    Creator:- Krishna Purwar.

    Program for:- Bisection Method.
    For Equations:- Algebraic.
    Program Type:- General.


    Suppose we have an equation f(x) = 0,  and for two numbers {a,b} in it's domain
    f(a).f(b) < 0. 
    and f(x) is continuous in [a,b].

    then the Bisection Algo looks like:-

         i). Find initial approximation(x0) = (a + b)/2.

         ii). Find f(x0).
         iii). If f(x0) = 0, then x0 is the root.
         iv). If f(x0) > 0,
              then root is present between a & x0, thus find next approximation as (a + x0)/2.
          v). If f(x0) < 0,
              then root is present between x0 & b, thus find next approximation as (x0 + b)/2.

          vi). Repeat the steps (ii - v) with the next approximations,
               until desired accuracy is not acheived.

 */

#include "Equations.h"    //Header file for this Program.

//Main function.
int main() {

    /*
       N-> Number of terms in the equation.
       hundreds-> Multiplier of 10 for checking desired accuracy.
    */
    int N ,hundreds = 0 ;

    /*
       a,b -> Domain in which to find the root...
    */
    float a,b;

    printf("Enter the no. of terms\n");
    scanf("%d",&N);   //Taking number of terms.

    node *term = take_terms(N);  //Allocating N terms.

    take_domain(&a,&b);  //Asking for domain.

   hundreds = decimal_places();  //Asking for decimal places and returning multiplier of 10.

    /*
     avg-> for storing the average of the two ranges.
     previous_point-> variable for storing previous average during accuracy checking with current avg.
    */
    float avg = 0.0, previous_point = 0.0;

    //Creating an infinite loop.
    while(true) {
  
       avg = (a+b)/2;

       /* 
         Finding the value of equation at 'avg'
         and storing it in a result value.
       */
       float result = eqn_value_at_point(term,N,avg);  


       //if result = 0 , then avg is the root.
       if(result == 0){
        printf("%f is the root\n",avg);
        break;  //Break from infinite loop.
       }
       //If result > 0, then root is between a & avg.
       else if(result > 0) {
        b = avg;
       }
       //If result < 0, then root is between avg & b.
       else {
        a = avg;
       }

       //Checking for accuracy upto desired places.
       if(accuracy(previous_point,avg,hundreds)) {
         printf("%.4f is the required upto two decimal places\n",avg );
         break;
       }
       
       //Reassigning the current average for checking its accuracy with next avg.
       previous_point = avg;
    }


    return 0;
}





