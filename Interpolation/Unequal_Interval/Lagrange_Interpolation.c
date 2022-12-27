/*
  Creator:- Krishna Purwar
  Program for:- Lagrange's Unequal Interval Interpolation Formula.

    Definition:-
      
      Suppose,
         
         We have a data table as:-
             ____________________________________________________________
            | x  ||  x0 | x1 | x2 | x3 | x4 | x5 | ... | x(n-1) | x(n) |
            |____________________________________________________________
            | y  ||  y0 | y1 | y2 | y3 | y4 | y5 | ... | y(n-1) | y(n) |
            |____________________________________________________________

            here, x1-x0 != x2-x1 != x3-x2 != ... != x(n-1) - x(n-2) != x(n) - x(n-1).

            Now, to find y at any point x different from the data-table, we have:-
             
            y(x) = (x-x1)(x-x2)...(x-x(n))(y0)/(x0-x1)(x0-x2)...(x0-x(n)) +
                   
                   (x-x0)(x-x2)...(x-x(n))(y1/(x1-x0)(x1-x2)...(x1-x(n)) +

                ...+ (x-x0)(x-x1)...(x-x(n-1))(y(n))/(x(n)-x0)(x(n)-x1)...(x(n)-x(n-1)).


*/

#include "Interpolation.h"

//Function Prototype.
float coefficient(int, int, float, node *);

int main(){

    //Immutable integer N for taking the size of data-table..
    const int N;
    
    //Imutable float variable for taking x to find f(x).
    const float x;

    printf("Enter the size of the table\n");
    scanf("%d",&N);
    
    //Allocating N contiguous memory blocks of size node and data type node*.
    node *data = (node *)malloc(sizeof(node)*N);

    printf("Enter the data in the form{x-y}\n");

    for( int i = 0 ; i < N ; i++ ){
        printf("Data no:- %d\n", i);
        scanf("%f-%f",&data[i].x , &data[i].y);
    }

    printf("Enter the value of x\n");
    scanf("%f",&x);

    float answer = 0.0;

    for( int i = 0 ; i < N ; i++ ) {
        answer += coefficient( i, N, x, data)*data[i].y;
    }

    printf("Answer:- %.4f\n", answer);
 
 return 0;

}
//function for finding the coefficent part of the f(x(n)) for the formula described above.
float coefficient(int i , int N , float x , node *data) {

    float numerator = 1.0f;
    float denominator = 1.0f;

    for( int j = 0 ; j < N ;j++ ) {
        if(j != i) {
            numerator *= (x - data[j].x);
            denominator *= (data[i].x - data[j].x);
        }
    }

    return numerator/denominator;

}