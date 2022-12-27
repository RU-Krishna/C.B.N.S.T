#include <stdio.h>  //Standard Input Output Header File
#include <stdlib.h> //Standars Library Header File

//Structure for holding Data Table.
typedef struct Table {
   const float x;
   const float y;
}node ;

#define getInt(N) scanf("%d",&N);

/*
  Function  for allocating N contiguous blocks of memory of size node and type node*
  and returning the base address of that memory block.
*/

node *take_data(const int N){

    node *data = (node *)malloc(sizeof(node)*N);
    
    printf("Enter the data in the form\n");
    for( int i = 0 ; i < N ; i++ ){
        printf("Data no:- %d\n", i);
        scanf("%f-%f",&data[i].x, &data[i].y);
    }

    return data;
}