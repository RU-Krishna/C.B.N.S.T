/*
     Creator:- Krishna Purwar.

     Program for:- Regular Falsi Method.
     Equation type:- Algebraic.
     Program type:- General.

     Suppose we have an equation f(x) = 0,  and for two numbers {a,b} in it's domain
      f(a).f(b) < 0. 
      and f(x) is continuous in [a,b].

      Algo:-
       
       i). Find first approximations with the help of formula:-
            
            x1 = (a*f(b) - b*f(a)) / (f(b) - f(a)).

       ii). Find f(x1).
       iii). If f(x1) = 0, then x1 is the root of the equation.
       iv).  If f(x1) > 0, then root is present between a & x1,
              thus find next approximations as:-
                x(n) = (a*f(x1) - x1*f(a)) / (f(x1) - f(a)).
        
        v). If f(x1) < 0, then root is present between x1 & b.
            thus find next approximation as:-
                x(n) = (x1*f(b) - b*f(x1)) / (f(b) - f(x1)).

        vi). Repeat the steps (ii - v), until desired accuracy isn't achieved between two adjacent approximations.
    
     

*/

#include "Equations.h"  //Header File

//Prototype of next_approximation function.
float next_approximation(node * , int , float , float);

//Main function.
int main() {

  /*
    N-> Number of terms.
    hundreds-> multiplier of 10 for checking accuracy.
  
  */
  int N = 0, hundreds = 0;

  //a,b-> Range
  float a, b;

 
  printf("Enter the number of terms in the Equation\n");  //Asking for number of terms.
  scanf("%d",&N);     //Storing number of terms in N.
  
   node *term = take_terms(N);  //Taking terms's coefficent and power and storing it in term variable.

   take_domain(&a,&b);  //Asking for domain.

   hundreds = decimal_places();   //Asking for decimal places and returning a multiple of 10.

   float next_point = 0.0;  //For storing next approximation.
   float previous_point = 0.0; //For storing previous approximation.

   //Infinite Loop.
   while(true) {
    
    //Storing next approximation's value.
    next_point = next_approximation(term, N, a, b);
    
    //Equation's value at next point.
    float value_at_next_point = eqn_value_at_point(term, N, next_point);

    //If value_at_next_point = 0, then next_point is the root.
    if(value_at_next_point == 0){
        printf("%f is the required root\n",next_point);
        break;  //Break the infinte loop.
    }
    //If value_at_next_point > 0, then root is present between a & next_point.
    else if(value_at_next_point > 0){
        b = next_point;
    }
    //If value_at_next_point < 0, then root is present between next_point & b.
    else {
        a = next_point;
    }

     //If desired accuracy is achieved then,next_point is the root.
     if(accuracy(previous_point,next_point,hundreds)){
        printf("%f is the required upto desired accuracy\n", next_point);
        break;
    }
    //Reassign the previous_point, next_point's value.
    previous_point = next_point;
    

   }
   
   return 0;
}

/*
  Function for finding next approximations.
  term-> storing address of 0th index of the struct Equation array
  a,b-> Range.
*/
float next_approximation(node *term,int N, float a, float b) {
    float f_a = eqn_value_at_point(term, N, a);  //Finding  and storing f(a).
    float f_b = eqn_value_at_point(term, N, b);  //Finding and storing f(b).
    float first_term = a*f_b;  //Stroing the value of the first_term of numerator.
    float second_term = b*f_a;  //Storing the value of the second_term of numerator.
    float next_point = (first_term - second_term)/(f_b - f_a);  //Finding next point by applying formula.
    return next_point;  //Returning next_point's value.
}