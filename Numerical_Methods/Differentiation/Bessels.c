/*
  Creator:- Krishna Purwar
  Program for:- For calculating the derivative near the mid of the table.

  Definition:-
      
      Suppose,
         
         We have a data table as:-
             ____________________________________________________________
            | x  ||  x0 | x1 | x2 | x3 | x4 | x5 | ... | x(n-1) | x(n) |
            |____________________________________________________________
            | y  ||  y0 | y1 | y2 | y3 | y4 | y5 | ... | y(n-1) | y(n) |
            |____________________________________________________________

            here, x1-x0 = x2-x1 = x3-x2 = ... = x(n-1) - x(n-2) = x(n) - x(n-1).

         then, for a point x from and near the mid of the table:-

         f'(x) = [F(1,mid) + ((2u-1)/2!)((F(2, mid-1) + F(2, mid))/2)  +
                    ((6*u*u - 6*u + 1)/6!)*F(3,mid-1)  + 
                      ((4*u*u*u - 6*u*u -2*u +2)/4!)((F(4, mid-2) + F(4, mid-1))/2) +
                        ((5*u*u*u*u - 10*u*u*u +5*u -1)/5!)(F(5, mid-2))+ ...]/h

        f"(x) = [ F(3, mid-1) + ((2*u -1)/2)((F(4,mid-2) + F(4,mid-1))/2) + 
                   ((u*u - u)/2)(F(5, mid-2)) + ... ]/h*h

            here, mid -> mid(center) point of the data table.
                  u = (x - mid)/h  , h = x1-x0.

                  F -> Forward difference Operator,
                  F(1, mid) = y(mid+1) - y(mid) , 
                  F(2, mid) = F(1, mid+1) - F(1, mid) ,
                  .
                  .
                  .
                  F(n, mid) = F(n-1 , mid+1) - F(n-1, mid).


*/


#include "Differentiation.h"

//Function Prototype.
float first_derivative(float , float , int ,float (*)[]);
float second_derivative(float,  float , int ,float (*)[]);

int main() {

    //Immutable Integer variable for storing the size of the data table.
    const int N;

    //Immutable Float variable for holding x.
    const float x;

    printf("Enter the size of the table\n");
    getInt(N);

    //Allocating N contiguous memory blocks of size node and type node*.
    node *data = (node *)malloc(sizeof(node)*N);

    //Forward Difference Table.
    float diff_table[N-1][N-1];

    printf("Enter the data in the form{x-y}\n");
    for( int i = 0 ; i < N ; i++ ){
        printf("Data no:- %d\n",i);
        scanf("%f-%f",&data[i].x ,&data[i].y);

        if(i > 0) {
            diff_table[0][i-1] = data[i].y - data[i-1].y;
        }
    }

    for( int n = 1 ; n < N-1 ; n++) {
        for( int r = 0 ; r < N-n-1 ; r++ ){
            diff_table[n][r] = diff_table[n-1][r+1] - diff_table[n-1][r];
        }

    }

    //Immutable float variable for holding interval difference.
    const float h = data[1].x - data[0].x;

    //Immutable int variable representing the mid point of the data table.
    const int mid = N >> 1;

    printf("Enter the value at which to find\n");
    scanf("%f",&x);

    const float u = (x - data[mid].x)/h;

    float result = first_derivative(u , h , N, diff_table);
    float result2 = second_derivative(u , h , N , diff_table);

    printf("First derivative =  %.4f\n",result);
    printf("Second derivative =  %.4f\n",result2);


    return 0;
}

//Function for calculating the first derivative.
/*
   Parameters:- 
   u -> ( x - x(mid))/h.
   h -> interval difference,
   N -> size of the data table,
   arr -> Difference table.
      
*/
float first_derivative(const float u , const float h, const int N, float arr[N-1][N-1]) {

    int mid = N >> 1;
    float sum = 0.0;
    sum = (arr[0][mid]) + 
            (((2*u) - 1)/4)*(arr[1][mid-1] + arr[1][mid]) +
              (((6*u*u)- (6*u) + 1)/12)*(arr[2][mid-1]) +
                (((4*u*u*u) - (6*u*u) - (2*u) + 2)/48)*(arr[3][mid-2] + arr[3][mid-1]) +
                  (((5*powf(u,4)) - (10*powf(u,3)) + (5*u) - 1)/120)*(arr[4][mid-2]);
    

    return sum/h; 
}
//Function for calculating the second derivative.
/*
   Parameters:- 
   u -> ( x - x(mid))/h.
   h -> interval difference,
   N -> size of the data table,
   arr -> Difference table.
      
*/
float second_derivative(const float u , const float h, const int N, float arr[N-1][N-1]) {
    int mid = N >> 1;
    float sum = 0.0;
    sum = ((arr[1][mid-1] + arr[1][mid])/2) +
            (((2*u) - 1)/2)*(arr[2][mid-1]) +
              (((6*u*u) -(6*u) -1)/24)*(arr[3][mid-2] + arr[3][mid-1]) +
                (((4*u*u*u) - (6*u*u) + 1)/24)*(arr[4][mid-2]);

    return sum/(h*h);
}

