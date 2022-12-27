/*

  Creator:- Krishna Purwar
  Program for:- For calculating the derivative near the end of the table.

  Definition:-
      
      Suppose,
         
         We have a data table as:-
             ____________________________________________________________
            | x  ||  x0 | x1 | x2 | x3 | x4 | x5 | ... | x(n-1) | x(n) |
            |____________________________________________________________
            | y  ||  y0 | y1 | y2 | y3 | y4 | y5 | ... | y(n-1) | y(n) |
            |____________________________________________________________

            here, x1-x0 = x2-x1 = x3-x2 = ... = x(n-1) - x(n-2) = x(n) - x(n-1).

            then, for a point x near the end of the table:-

            f'(x) = [ B(1, n) + ((2u+1)/2)B(2,n) + ((3*u*u + 6*u +2)/6)B(3, n) +
                      ((2*u*u*u + 9*u*u + 11*u + 3)/12)B(4,n) + ... ]/h;

            f"(x) = [ B(2,n) + (u+1)B(3,n) + ((6*u*u + 18*u +11)/12)B(4, n) + ...]/h*h.

            where, 
              
              u = (x - xn)/h , h = x1-x0.

              B -> Backward Difference Operator.
              B(1,n) = y(n) - y(n-1)
              F(2,n) = B(1,n) - B(1,n-1)
              .
              .
              .
              B(n,n) = B(n-1,n) - B(n-1,n-1).

*/#include "Differentiation.h"

//Function Prototype.
float first_derivative(float , float , int , float (*)[]);
float second_derivative(float , float , int , float (*)[]);

int main() {

    //Immutbale int variable for holding the size of the table.
    const int N;
    //Immutable float variable for holding the x.
    const float x;

    printf("Enter the size of the data table\n");
    getInt(N);

    //Allocating N contiguous memory blocks of size node and type node*.
    node *data = (node *)malloc(sizeof(node)*N);

    //Backward Difference Table.
    float diff_table[N-1][N];

    printf("Enter the data in the form {x-y}\n");


    for( int i = 0 ; i < N ; i++ ){
          printf("Data no:- %d\n", i);
          scanf("%f-%f",&data[i].x , &data[i].y);
          
          if(i > 0){
            diff_table[0][i] = data[i].y - data[i-1].y;
          }
    }

    for( int n = 1 ; n < N-1 ; n++) {
        for( int r = N-1 ; r > n ; r-- ) {
            diff_table[n][r] = diff_table[n-1][r] - diff_table[n-1][r-1];
        }
    }

    //Immutable float variable for holding the interval difference.
    const float h = data[1].x - data[0].x;

    printf("Enter the value of x\n");
    scanf("%f",&x);

    const float u = (x - data[N-1].x)/h;

    float result = first_derivative(u , h , N ,diff_table);
    printf("Result= %.4f\n",result);
    
    float result2 = second_derivative(u , h , N ,diff_table);
    printf("Result= %.4f\n",result2);

    return 0;
    
}
//Function for calculating the first derivative.
/*
   Parameters:- 
   u -> ( x - x(n))/h.
   h -> interval difference,
   N -> size of the data table,
   arr -> Difference table.
      
*/
float first_derivative(float u ,float h,  int N, float arr[N-1][N]) {


   float sum = 0.0;
   sum = arr[0][N-1] + 
              ((2*u+1)/2)*arr[1][N-1] +
                 (((3*u*u) + (6*u) + 2)/6)*arr[2][N-1] +
                    (((2*u*u*u) + (9*u*u) + (11*u) + 3)/12)*arr[3][N-1];
   return sum/h;
}
//Function for calculating the second derivative.
/*
   Parameters:- 
   u -> ( x - x(n))/h.
   h -> interval difference,
   N -> size of the data table,
   arr -> Difference table.
      
*/
float second_derivative(float u , float h , int N , float arr[N-1][N-1]) {

    float sum = arr[1][N-1] +
                  (u + 1)*arr[2][N-1] +
                     (((6*u*u) + (18*u) + 11)/12)*arr[3][N-1];
                    
    return sum/(h*h);                

}

