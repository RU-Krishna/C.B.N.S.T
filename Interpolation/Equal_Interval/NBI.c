/*
   Creator:- Krishna Purwar.
   Program For:- Newton's Gregory Backward Interpolation Method.

   Definition:-
      
      Suppose,
         
         We have a data table as:-
             ____________________________________________________________
            | x  ||  x0 | x1 | x2 | x3 | x4 | x5 | ... | x(n-1) | x(n) |
            |____________________________________________________________
            | y  ||  y0 | y1 | y2 | y3 | y4 | y5 | ... | y(n-1) | y(n) |
            |____________________________________________________________

            here, x1-x0 = x2-x1 = x3-x2 = ... = x(n-1) - x(n-2) = x(n) - x(n-1).

        and we have to find y(x(i)), where 'i' -> point close towards x(n-1) or x(n).

        then,

        y(i) =  y0 + C(i,1)*B(1, y(n)) + C(i,2)*F(2, y(n)) + C(i,,3)*F(3, y(n)) + ...
                                            C(i, n)*F(n, y(n)).


        here,  B -> Backward Difference Operator.
        
              i = ((x(i)) - x(n))/h , h = x1 - x0.

              C(n,r) = n*(n-1)*(n-2)...(n-r+1)/(r!).

              B(1, y(n)) = y(n) - (n-1).
              B(2, y(n)) = B(1, y(n)) - B(1, y(n-1))
              .
              .
              .
             B(n, y(n)) = B(n-1, y(n)) - B(n-1,y(n-1)).


*/

#include "Interpolation.h"

//Function Prototype.
float C(float, float);

int main() {

    //Immutable variable N for storing the size of the table.
    const int N;

    printf("Enter the size of the table\n");
    scanf("%d",&N);

    //Allocating N contiguous memory blocks of size node and type node*.
    node *data = (node *)malloc(sizeof(node)*N);

    //Backward Difference Table.
    float diff_table[N-1][N];

    printf("Enter the data in the form{x-y}\n");

    //Taking the data and storing the first Backward finite difference.
    for( int i = 0 ; i < N ; i++ ) {
        printf("Data no:- %d\n", i);
        scanf("%f-%f",&data[i].x ,&data[i].y);

        if(i > 0) {
            diff_table[0][i] = data[i].y - data[i-1].y;
        }
    }

    //Storing other Backward finite differences in the difference table.
    for( int n = 1 ; n < N-1 ; n++ ){
        for( int r = N-1 ; r > n ; r-- ) {
            diff_table[n][r] = diff_table[n-1][r] - diff_table[n-1][r-1];
        }
    }

    //Immutable Float variable for storing the Interval Difference
    const float h = data[1].x - data[0].x;

    //Immutable Float variable for taking the value at which to find y(x).
    const float x;


    printf("Enter the value of x\n");
    scanf("%f",&x);

    
    float u = (x - data[N-1].x)/h;

    float sum = data[N-1].y;

    for( int n = 0 ; n < N-1 ; n++ ) {
        sum += C(u+n , n+1)*diff_table[n][N-1];
    }

    printf("Result = %.4f\n", sum);

    return 0;
}

//Funtion for finding the Combination.
float C(float n , float r) {
    float numerator = 1.0f;
    float denominator = 1.0f;
    for( int i = 0 ; i < r ; i++ ){
        numerator *= (n-i);
        denominator *= (r-i);
    }
    float result = numerator/denominator;

    return result;

}