/*
   Creator:- Krishna Purwar.
   Program For:- Newton's Gregory Forward Interpolation Method.

   Definition:-
      
      Suppose,
         
         We have a data table as:-
             ____________________________________________________________
            | x  ||  x0 | x1 | x2 | x3 | x4 | x5 | ... | x(n-1) | x(n) |
            |____________________________________________________________
            | y  ||  y0 | y1 | y2 | y3 | y4 | y5 | ... | y(n-1) | y(n) |
            |____________________________________________________________

            here, x1-x0 = x2-x1 = x3-x2 = ... = x(n-1) - x(n-2) = x(n) - x(n-1).

        and we have to find y(i), where 'i' -> point close towards x0 or x1.

        then,

        y(i) =  y0 + C(i,1)*F(1, y0) + C(i,2)*F(2, y0) + C(i,,3)*F(3, y0) + ...
                                            C(i, n)*F(n, y0).


        here, F -> Forward Difference Operator.
        
              i = ((x(i)) - x0)/h , h = x1 - x0.

              C(n,r) = n*(n-1)*(n-2)...(n-r+1)/(r!).

              F(1, y0) = y1 - y0.
              F(2, y0) = F(1, y1) - F(1, y0).
              .
              .
              .
              F(n, y0) = F(n-1, y1) - F(n-1,y0).

*/


#include "Interpolation.h"

//Function Prototype.

float c(float , float);

int main() {

    //Immutable variable N for storing the size of the table.
    const int N;
    
    //Immutable Float variable for taking the value at which to find y(x).
    const float x;

    printf("Enter the size of the data table\n");
    scanf("%d",&N);

    //Allocating N contiguous memory blocks of size node and type node*.
    node *data = (node *)malloc(sizeof(node)*N);

    //Two Dimensional Array for  storing the difference table.
    float diff_table[N-1][N-1];
 

    printf("Enter the data in the format {x-y}\n");

    //Taking the data and storing the first Forward finite difference.
    for( int i = 0 ; i < N ; i++ ){
        printf("Data no:- %d\n", i );
        scanf("%f-%f", &data[i].x, &data[i].y);

        if(i > 0) {
            diff_table[0][i-1] = data[i].y - data[i-1].y ;
        }

    }


    printf("Enter the x on which to interpolate\n");
    scanf("%f", &x);

    
    //Storing other Forward finite differences in the difference table.
    for( int n = 1 ; n < N-1 ; n++ ){
        for( int r = 0 ; r < N-n-1 ; r++ ) {
            diff_table[n][r] = diff_table[n-1][r+1] - diff_table[n-1][r];
        }
    }

    //Immutable Float variable for storing the Interval Difference.
    const float h = (data[1].x - data[0].x);
    //Immutable variable.
    const float u = (x - data[0].x)/h;

    float result = data[0].y;


    for( int i = 0 ; i < N-1 ; i++ ) {
          result += c(u, i+1)*diff_table[i][0];
    }

     printf("Thus, x at %.3f is %.3f\n", x, result);

    return 0;
}
//Function for finding the Combination.
float c(float n, float r) {
    float product = 1;
    float fact = 1;
    for( int i = 0 ; i < r; i++ ){
        product *= (n-i);
        fact *= (i+1);
    }

    return product/fact;

}