#include "Array.h"
Vector add(Vector v1, Vector v2){
    
    Vector sums = empty_vector();
    
    int two_longer = 0, len = v1.count;
    // 
    if(v2.count < len){
        len = v2.count;
        two_longer = 1;
    }
    
    int index;
    for(index = 0; index < len; index++){
        insert(&sums, v1.vector[index] + v2.vector[index]);
    } //post: two is shorter than 1, or two_longer. Iterate over remaining positions
    
    if(two_longer){
        while(index < v2.count){
            insert(&sums, v2.vector[index]);
            index++;
        }
    }
    else{
        while(index < v1.count){
            insert(&sums, v1.vector[index]);
            index++;
        }
    }
    return sums;
}