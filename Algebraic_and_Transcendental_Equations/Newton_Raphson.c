/*

   Creator:- Krishna Purwar.

   Program for:- Newton Raphson Method.
   Equation Type:- Algebraic.
   Program Type:- General.


    Suppose we have an equation f(x) = 0,  and for two numbers {a,b} in it's domain
    f(a).f(b) < 0. 
    and f(x) is continuous in [a,b].

   Algo:- 

     i). Assume an approximation between a & b whose value at f(x) is closer to zero.
     ii). Find next approximations with the formula:- 
               x(n) = x(n-1) - f(x(n-1))/f'(x(n-1)).

          until desired accuracy between adjacent approximations
           isn't found upto desired accuracy.


*/
#include "Equations.h" //Equations.h header file.


//Prototype of first_approximation function.
float first_approximation(node * , int , float ,float);

//Prototype of next_approximation function.
float next_approximation(node *, node * , int , float);

//Main function.
int main() {

    //Variable for storing number of terms.
    int N;
    
    //a,b-> Range.
    float a ,b ;

    printf("Enter the number of terms\n");
    scanf("%d",&N);

    //For storing the actual equation's coefficient and power.
    node *term = malloc(sizeof(node)*N);
    //For storing the coefficient and power of the derivative of the same equation.
    node *derivative = malloc(sizeof(node)*N);

    for( int i = 0 ; i < N ; i++ ) {

        //Asking and storing  actual equations coefficient and power.
        printf("Enter the coefficients and power {x,y}\n");
        scanf("%d,%d",&term[i].coeff, &term[i].pow);

        //Storing the coefficient and power of the derivative of the same equation.
        derivative[i].coeff = term[i].coeff * term[i].pow;
        derivative[i].pow = term[i].pow - 1;
    }

    take_domain(&a , &b);  //asking for range

    int hundreds = decimal_places();  //asking for decimal places and returnig a multiplier of 100.

    /*
      next_point-> for storing next approximations.
      previous_approximation-> for storing first aproximation and finding next approximation from this one.
    */
    float next_point = 0.0 ,previous_point = first_approximation(term , N, a ,b);

    while(true) {
       //Finding next approximation from the previous one
       next_point = next_approximation(term , derivative , N, previous_point);

       /*
         If desired accuracy is achieved between 
          next_point & previous_point.
          then, next_point is the root of the equation and break the while loop.
       */
       if(accuracy(previous_point , next_point , hundreds)){
        printf("%f is the required root upto desired accuracy\n" , next_point);
        break;
       }

      //Reassigning the previous_point the next_point
       previous_point = next_point;


    }
}

/*
   term-> address of the 0th (Equation) struct array.
   N-> Number of terms.
   a,b-> Range
*/
float first_approximation(node *term , int N, float a, float b) {
    
    //Storing equations value at a.
    float val1 = 0.0 - eqn_value_at_point(term , N , a);
    //Storing equations value at b.
    float val2 = eqn_value_at_point(term , N , b);

    /*
      If both the values are at same differenece from 0.
      Return (a+b)/2.
    */
    if(val1 == val2)
      return (a+b)/2;
    //if val1 is greater then return b - 0.25. 
    else if(val1 > val2)
      return b - 0.25;
    //If val2 is greater then return a + 0.25.
    else
      return a + 0.25;
 
}
/*
   term-> stores 0th address of the struct Equation.
   derivative-> stores 0th address of the derivative equation.
   N-> Number of terms.
   previous_point-> previous approximation.

*/
float next_approximation(node *term ,node *derivative , int N, float previous_point){  

    //Equation's value at previous_point.
    float numerator = eqn_value_at_point(term , N , previous_point);
    //Value of the derivative of the original equation at previous_point.
    float denominator = eqn_value_at_point(derivative , N , previous_point);
    //Finding next point after applying formula.
    float next_point = previous_point - (numerator/denominator);
    //Returning next_point.
    return next_point;
}