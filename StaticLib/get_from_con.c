#include "Array.h"
Vector get_from_con(){
    Vector v = empty_vector();
    char input[30];
    double dbl;
    int going = gets(input);
    
    while(going){
        dbl = atof(input);
        insert(&v, dbl);
        gets(input);
        going = input[0] != NULL;
    }
    
    return v;
}