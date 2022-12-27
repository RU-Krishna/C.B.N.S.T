#include "Integral.h"

int main() {

    //Immutable int variable for holding the size of the data table.
    const int N;
    
    printf("Enter the size of the table\n");
    getInt(N);

    node *data = take_data(N);

    //Immutable float variable for holding the interval difference.
    const float h = data[1].x - data[0].x;

    float sum = data[0].y + data[N-1].y;

    for( int  i = 1 ; i < N-1 ; i++ ) {
        sum += 2*data[i].y;
    }
    
    float result = sum*h/2;

    printf("Result = %.3f\n", result);

    return 0;
}