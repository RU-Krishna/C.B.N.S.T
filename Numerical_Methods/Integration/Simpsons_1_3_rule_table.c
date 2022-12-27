#include "Integral.h"

int main() {
  
  //Immutable integer variable for holding the size of the data-table.
  const int N;
  
  printf("Enter the number of terms\n");
  getInt(N);

  //Refer to the function.
  node *data = take_data(N);

  //Immutable float variable for holding the interval difference.
  const float h = data[1].x - data[0].x;
   
  float sum = data[0].y + data[N-1].y;

  for( int i = 1 ; i <= N-2 ; i += 2 ) {
    sum += 4*data[i].y + 2*data[i+1].y;
  }

  sum -= 2*data[N-1].y;

  float result = sum*h/3;

  printf("Result = %.3f",result);
  
  return 0;
}