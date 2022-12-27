#include <stdio.h>  //Standard I/O header File for 'printf & scanf'.
#include <stdlib.h>  //Standard Library header file for 'malloc'
#include <math.h>   //Math headre file for pow function.
#include <stdbool.h> //Standard Bool headre file for 'bool datatype , true & false values'.


//struct for equation's term coefficent and power.
 typedef struct Equation {
       int coeff;
       int pow;
    }node; //We can call by the name node.

/*
  Function for taking coefficent and power associated with each term 
  by the user and after taking all terms,
  return the 0th index of the term array.

*/
node* take_terms(int N) {

    node *term = (node *)malloc(sizeof(node)*N);  //Allocating N locations of type node.
     for( int i = 0 ; i < N ; i++) {
        printf("Enter the coefficient and power as {x,y}\n");
        scanf("%d,%d",&term[i].coeff,&term[i].pow);
    }

    return term;
}
/*
 Function for asking domain in which to find.
*/
void take_domain(float *a, float *b) {

     printf("Enter the Domain\n");
    scanf("%f-%f",a,b);

}

int decimal_places() {

    int places;
    int hundreds;
    printf("Enter the number of decimal places\n"); //Asking for decimal places 
    scanf("%d",&places);
    hundreds = powf(10,places);  //Finding and storing a multiplier of 10 upto required decimal places.

    return hundreds;  //Returning the multiplier
}

//Function for checking accuracy.
bool accuracy(float a , float b , int multiplier) {
    int x = a*multiplier;   
    int y = b*multiplier;
    if(x == y)
      return true;
    else 
      return false;
}
//Finding equation's value at given point.
float eqn_value_at_point(node *term , int N , float point) {

    float result = 0.0;
    for(int i = 0 ; i < N ; i++ ) {
         result += ((float)term[i].coeff)*powf(point , term[i].pow);
    }
    return result;

}