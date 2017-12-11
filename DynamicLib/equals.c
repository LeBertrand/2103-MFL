#include "Array.h"
int equals(Vector v1, Vector v2){
    if(v1.count != v2.count){
        return 0;
    }
    
    int index;
    for(index = v1.count - 1; index >= 0; index--){
        if(v1.vector[index] != v2.vector[index]){
            return 0;
        }
    }
    return 1;
}