/*
   Creator:- Krishna Purwar.
   Program for:- Newton's Divided Difference Interpolation Method.

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

            y(x) = y0 + (x-x0)DD(x0,x1) +(x-x0)(x-x1)DD(x0,x1,x2) +...
                   (x-x0)(x-x1)(x-x2)...(x-x(n-1))DD(x0,x1,x2,...,x(n)).

            where, DD -> Divided Difference Operator.
            DD(x0,x1) = (y1 - y0)/(x1-x0),
            DD(x0,x1,x2) = (DD(x1,x2) - DD(x0,x1))/(x2-x0),
            DD(x0,x1,x2,x3) = (DD(x1,x2,x3) - DD(x0,x1,x2))/(x3-x0)...
                   
*/
#include "Interpolation.h"

//Function Prototype
float coefficent(float , int , node *);

int main() {

     //Immutable integer variable for storing the size of the data table
     const int N;

     //Immutable float variable x for findinf f(x).
     const float x;

     printf("Enter the size of the table\n");
     scanf("%d",&N);

    //Allocating N contiguous memory blocks of size node and data type node*
     node *data = (node *)malloc(sizeof(node)*N);

     //Divided Difference Table.
     float matrix[N-1][N-1];

     printf("Enter the data in the form {x-y}\n");

     for( int i = 0 ; i < N ; i++ ) {

        printf("Data no:- %d\n", i);
        scanf("%f-%f",&data[i].x , &data[i].y);

        if(i > 0) {
            matrix[0][i-1] = (data[i].y - data[i-1].y) /(data[i].x - data[i-1].x);
        }

     }

     printf("Enter the point at which to find\n");
     scanf("%f",&x);

     for( int n = 1 ; n < N-1 ; n++ ) {
        for( int r = 0 ; r < N-n-1 ; r++ ) {
            matrix[n][r] = ( matrix[n-1][r+1] - matrix[n-1][r] ) / (data[ n+r+1 ].x - data[r].x );
        }
     }

     float answer = data[0].y;

     for( int i = 0 ; i < N ; i++ ){
        answer += coefficent(x , i , data)*matrix[i][0];
     }

     printf("Answer:- %.3f\n", answer);

     return 0;

}
//Function for finding the coefficient before DD's term.
float coefficent(float x , int i, node *data ) {
    float result = 1;
    for( int j = 0 ; j <= i ; j++ ) {
        result *= (x - data[j].x);
    }
    return result;
}