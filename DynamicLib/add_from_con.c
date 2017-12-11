#include "Array.h"
void add_from_con(Vector *vec){
    char input[30];
    double dbl;
    int going = gets(input);
    
    while(going){
        dbl = atof(input);
        insert(vec, dbl);
        gets(input);
        going = input[0] != NULL;
    }
}