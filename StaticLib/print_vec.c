#include "Array.h"
void print_vec(Vector vec){
    printf("Vector contains %d objects, with space allocated for %d.\n",
        vec.count, vec.length);
    int index;
    for(index = 0; index < vec.count; index++){
        printf("\t%lf", vec.vector[index]);
    }
    puts("");
}