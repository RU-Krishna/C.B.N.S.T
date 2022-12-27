/*

  Creator:- Krishna Purwar
  Program for:- For calculating the derivative near the starting of the table.

  Definition:-
      
      Suppose,
         
         We have a data table as:-
             ____________________________________________________________
            | x  ||  x0 | x1 | x2 | x3 | x4 | x5 | ... | x(n-1) | x(n) |
            |____________________________________________________________
            | y  ||  y0 | y1 | y2 | y3 | y4 | y5 | ... | y(n-1) | y(n) |
            |____________________________________________________________

            here, x1-x0 = x2-x1 = x3-x2 = ... = x(n-1) - x(n-2) = x(n) - x(n-1).

            then, for a point x near the starting of the table:-

            f'(x) = [ F(1, 0) + ((2u-1)/2)F(2,0) + ((3*u*u - 6*u +2)/6)F(3, 0) +
                      ((2*u*u*u - 9*u*u + 11*u - 3)/12)F(4,0) + ... ]/h;

            f"(x) = [ F(2,0) + (u-1)F(3,0) + ((6*u*u - 18*u +11)/12)F(4, 0) + ...]/h*h.

            where, 
              
              u = (x - x0)/h , h = x1-x0.

              F -> Forward Difference Operator.
              F(1,0) = y1 - y0
              F(2,0) = F(1,1) - F(1,0)
              .
              .
              .
              F(n,0) = F(n-1,1) - F(n-1,0).

*/

#include "Differentiation.h"

//Function Prototype.
float first_derivative(float , float , int , float (*)[]);
float second_derivative(float , float , int , float (*)[]);

int main() {

    //Immutable int variable for holding the size of the table.
    const int N;

    //Immutable float variable for holding x.
    const float x;

    printf("Enter the size of the data table\n");
    getInt(N);
   
   //Allocating N contiguous blocks of size node and type node*.
    node *data = (node *)malloc(sizeof(node)*N);

    //Froward Difference Table.
    float diff_table[N-1][N-1];

    printf("Enter the data in the form {x-y}\n");


    for( int i = 0 ; i < N ; i++ ){
          printf("Data no:- %d\n", i);
          scanf("%f-%f",&data[i].x , &data[i].y);
          
          if(i > 0){
            diff_table[0][i-1] = data[i].y - data[i-1].y;
          }
    }

    for( int n = 1 ; n < N-1 ; n++) {
        for( int r = 0 ; r < N - n -1 ; r++ ) {
            diff_table[n][r] = diff_table[n-1][r+1] - diff_table[n-1][r];
        }
    }

    //Immutable float variable for hloding the interval difference.
    const float h = data[1].x - data[0].x;

    printf("Enter the value of x\n");
    scanf("%f",&x);

    float u = (x - data[0].x)/h;

    float result = first_derivative(u , h , N ,diff_table);
    printf("Result= %.4f\n",result);
    
    float result2 = second_derivative(u , h , N ,diff_table);
    printf("Result= %.4f\n",result2);

    return 0;
    
}
//Function for calculating the first derivative.
/*
   Parameters:- 
   u -> ( x - x0)/h.
   h -> interval difference,
   N -> size of the data table,
   arr -> Difference table.
      
*/
float first_derivative(const float u , const float h, const int N, float arr[N-1][N-1]) {


   float sum = 0.0;
   sum = arr[0][0] + 
              ((2*u-1)/2)*arr[1][0] +
                 (((3*u*u) - (6*u) + 2)/6)*arr[2][0] +
                    (((2*u*u*u) - (9*u*u) + (11*u) -3 )/12)*arr[3][0];
   return sum/h;
}
//Function for calculating the second derivative.
/*
   Parameters:- 
   u -> ( x - x0)/h.
   h -> interval difference,
   N -> size of the data table,
   arr -> Difference table.
      
*/
float second_derivative(const float u , const float h , const int N , float arr[N-1][N-1]) {

    float sum = arr[1][0] +
                  (u -1)*arr[2][0] +
                     (((6*u*u) - (18*u) + 11)/12)*arr[3][0];
                    
    return sum/(h*h);                

}


