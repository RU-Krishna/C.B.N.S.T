/*
  Creator:- Krishna Purwar.
  Program For:- Stirling's Central Difference Interpolation Method.

   Definition:-
      
      Suppose,
         
         We have a data table as:-
             ____________________________________________________________
            | x  ||  x0 | x1 | x2 | x3 | x4 | x5 | ... | x(n-1) | x(n) |
            |____________________________________________________________
            | y  ||  y0 | y1 | y2 | y3 | y4 | y5 | ... | y(n-1) | y(n) |
            |____________________________________________________________

            here, x1-x0 = x2-x1 = x3-x2 = ... = x(n-1) - x(n-2) = x(n) - x(n-1).

         and we have to find y(i), where i -> close to the center of the data-table,
            but not any point in the data-table.

        then, we select a point 'index'(say) from the data table which is close to the x(i).

        Now,
          
          y(i) =  y(index) + u*((F(1, index) + F(1, index-1))/2) +
                    u*u*(F(2, index-1))/2 +
                      (u(u*u - 1*1)/3!)*((F(3, index-1) + F(3, index-2))/2) +
                        (u*u)(u*u - 1*1)(F(4, index-2))/4! + ...

        here, F-> Forward Difference Operator.
 
              u = (x(i) - x(index))/h , h = x1 - x0.

              F(1, index) = y(index+1) - y(index),
              F(2, index-1) = F(1, index) - F(1, index-1), 
               and so on... 
              


*/
#include "Interpolation.h"

//Function Prototypes
float coeff(int , float);

float diff(const int ,float (*)[] , int , int);
int fact(int );

int main() {
    
    //Immutable constant for storing the size of the table.
    const int N;

    printf("Enter the size of the table\n");
    scanf("%d",&N);

    //Allocating N contiguous memory blocks of size node and type node*.
    node *data = (node *)malloc(sizeof(node)*N);

    //Forward Difference Table.
    float diff_table[N-1][N-1];

    //Taking the data and storing the first forward difference operator.
    for(int i = 0 ; i < N ; i++ ) {
        printf("Data no:- %d\n", i+1);
        scanf("%f-%f",&data[i].x,&data[i].y);

        if(i > 0 ){
            diff_table[0][i-1] = data[i].y - data[i-1].y;
        }
    }

    //Finding and storing the further forward differneces.
    for( int n = 1 ; n < N-1 ; n++) {
        for( int r = 0 ; r < N-n-1 ; r++ ){
            diff_table[n][r] = diff_table[n-1][r+1] - diff_table[n-1][r];
        }
    }
   
    //Immutable Float variable for storing the Interval Difference.
    const float h = data[1].x - data[0].x;
    //Immutable int variable for index.
    const int index = N >> 1;
    //Immutable Float for taking the x to find f(x).
    const float x;
    
    printf("Enter the value of x\n");
    scanf("%f",&x);

    const float u = (x - data[index].x)/h;

    float result = data[index].y;




    for( int i = 0 ; i < N-1 ; i++ ){
        if((i & 1) == 0) 
            result += u*(coeff(i, u))*(diff(N, diff_table , index , i))/fact(i+1);
        else
            result += u*u*(coeff(i, u))*(diff(N, diff_table , index , i))/fact(i+1);


    }

    printf("Result = %.4f\n", result);
   
    return 0;
}

//Function for finding the coefficient...
float coeff(int i, float u) {
    float result = 1.0f;
    int x = i>>1;
    if(x>0){
        for( int i = x ; i > 0; i-- ){
            result *= (u*u - i*i);
        }
    }
    return result;
}
//Function for finding the Differences.
float diff(const int N , float diff_table[N-1][N-1], int index , int i) {
    int r = i >> 1;
    float result = 1.0f;
    if((i & 1) == 0){
        result = (diff_table[i][index-r] + diff_table[i][index-r-1])/2;
    }
    else {
        result = diff_table[i][index-r-1];
    }
    return result;
}
//Function for finding the factorial.
int fact(int num) {
    int fac = 1;
    for( int i = num ; i > 1 ; i-- ) {
        fac *= i;
    }
    return fac;
}