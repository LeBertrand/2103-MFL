#include "Array.h"

/*
    Function to create a vector of double.  It accepts the
    integer length of the vector to be created and returns
    a Vector struct containing the length of the allocated
    vector, the count (initialized to zero) of doubles
    inserted, and the allocated vector.
*/
Vector create_vector(int length){
    Vector v;
    v.vector = malloc(sizeof(double) * length);
    // check for null 
    if(v.vector == NULL){
        puts("Can't allocate memory for pointer. Exit program.");
        exit(1);
    }
    v.length = length;
    v.count = 0;
    return v;
}


/*
    Create an empty vector with vector pointer set to NULL,
    length set to zero and count set to zero.  This is used
    when something fails during the creation of a Vector or
    other functions that return a Vector.
*/
Vector empty_vector(){
    Vector v;
    v.vector = (double*) malloc(sizeof(double));
    v.length = 1;
    v.count = 0;
    return v;
}


/*
    Inserts a double into a vector of double.  If the
    vector is full (i.e. count == length), the length of
    the vector should be doubled and the data from the old
    vector should be copied and the old vector freed.  If
    the length is zero, use the defined initial size.
    You can use malloc, which requires you to manually copy
    and free the old vector or try realloc.
*/
int insert(Vector *vec, double dbl){
    // Case: vector is full
    
    if(vec->count==vec->length){
        
        double *newVec = malloc(2*vec->length*sizeof(double));
        if(newVec == NULL){
            puts("Cannot allocate more memory to vector.");
            return 1;
        }
        
        vec->length *= 2;
        vec->vector = newVec;
        
    } // @post--vector has space after count
    //printf("Trying to put value no. %d, %lf into vector", vec->count,vec->vector[vec->count]);
    vec->vector[vec->count] = dbl;
    vec->count+=1;
    return 1;
}


/*
    Prints the count, length and elements of a vector to
    screen.
*/
void print_vec(Vector vec){
    printf("Vector contains %d objects, with space allocated for %d.\n",
        vec.count, vec.length);
    int index;
    for(index = 0; index < vec.count; index++){
        printf("\t%lf", vec.vector[index]);
    }
    puts("");
}


/*
    Frees the memory allocated for the vector, and sets
    the count and length to zero.  Make sure not the free
    an empty (NULL) vector.
*/
void delete_vector(Vector *vec){
    if(vec->vector != NULL){
        free(vec->vector);
    }
    vec->count = vec->length = 0;
}


/*
    Creates a new vector with equal count, length and
    elements and returns the vector.
*/
Vector copy(Vector vec){
    Vector u = empty_vector();
    
    
    // case: empty vector or corrupted data
    if(vec.count && vec.vector != NULL){
        int index;
        for(index = 0; index < vec.length; index++){
            insert(&u, vec.vector[index]);
        }
    }
    return u;
}


/*
    Copies a range from a vector to a new vector and
    returns the new vector.  The count and length should
    be equal to the number of elements copied.  Remember
    to check for invalid operations:
        to less than from
        to less than zero
        from greater than or equal to count
    Indexes start at 0 and are inclusive
*/
Vector copy_range(Vector vec, int from, int to){
    Vector u = empty_vector();
    // catch some errors
    if(to<from || from < 0 || from >= vec.count){
        printf("Bad copy-range call. From: %d, To: %d\n", from, to);
        return u;
    }
    // iterate starting at 'from' index ending at 'to', and insert
    for(;from <= to; from++){
        insert(&u,vec.vector[from]);
    }
    return u;
}


/*
    Writes zeros to the elements of a vector and sets
    the count to zero.
*/
void clear_vector(Vector *vec){
    int zeroed;
    for(zeroed = 0; zeroed < vec->count; zeroed++){
        vec->vector[zeroed] = 0.0;
    }
    vec->count = 0;
}


/*
    Writes zeros to a vector's elements.
*/
void zeros(Vector *vec){
    int zeroed;
    for(zeroed = 0; zeroed < vec->count; zeroed++){
        vec->vector[zeroed] = 0.0;
    }
}


/*
    Fills a vector's elements with the value in dbl.
*/
void fill(Vector *vec, double dbl){
    int filled;
    for(filled = 0; filled < vec->count; filled++){
        vec->vector[filled] = dbl;
    }
}


/*
    Reads a vector from a file with one double on
    each line in the file and returns the vector.
    Remember that scanf returns a -1 after reading
    the last element in a file.
*/
Vector read_from_file(char *filename){
    // Create Vector
    Vector v = empty_vector();
    
    // Open file.
    FILE* file_in = fopen(filename, "r");
    
    // Create string to hold each line of the file.
    char dblstr[10];
    
    // Create double to hold each converted double.
    double dbin;
    
    // Empty string before reading in file.
    strcpy(dblstr,"\n\n\n\n\n\n\n\n\n\n");
    
    // Read in each line.
    while(fgets(dblstr, 10, file_in) != 0){
        dbin = atof(dblstr);
        insert(&v, dbin);
    }
    //fclose(file_in);
    return v;
}


/*
    Writes a vector's elements to a file.
*/
int write_to_file(Vector vec, char *filename){
    FILE* file_out = fopen(filename, "w");
    int x;
    for(x = 0; x < vec.count; x++){
        fprintf(file_out, "%.2f", vec.vector[x]);
        fputc('\n', file_out);
    }
    fclose(file_out);
}


/*
    Creates a new vector and gets the elements from
    keyboard input.  Accepts and inserts doubles into
    the vector until Enter is pressed (without any other
    chars).  Remember that scanf will not work unless a
    required data type is entered.  You should use gets
    and check for '\0', when Enter only is pressed.
*/
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


/*
    Adds elements to a vector and gets the elements from
    keyboard input.  Accepts and inserts doubles into
    the vector until Enter is pressed (without any other
    chars).  Remember that scanf will not work unless a
    required data type is entered.  You should use gets
    and check for '\0', when Enter only is pressed.
*/
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


/*
    Swaps two elements in a vector.
*/
void swap(Vector *vec, int i, int j){
    int x = vec->vector[i];
    vec->vector[i] = vec->vector[j];
    vec->vector[j] = x;
}


/*
    Sorts a vector.  Can use selection or bubble
    sort. Ascending order.
*/
void sort(Vector *vec){
    int n, going = 1;
    while(going){
        going = 0;
        for(n = 1; n < vec->count; n++){
            if(vec->vector[n] < vec->vector[n - 1]){
                swap(vec, n, n - 1);
                going = 1;
            }
        }
    }
}



/*
    Reverses the elements of a vector.
*/
void reverse(Vector *vec){
    int i;
    for(i = 0; i < (vec->count) / 2; i++){
        swap(vec, i, vec->count - i - 1);
    }
}


/*
    Checks if two doubles are equal given the defined
    EPSILON.  Remember that there should be a threshold
    for which two do floating point values are considered
    equal due to computation of arithmetic operations.
*/
int dbl_equals(double d1, double d2){
    double dif = fabs(d1-d2);
    return dif < EPSILON;
}


/*
    Perform a binary search on a sorted vector and return
    the index of the element if found and -1 if not found.
*/
int search(Vector vec, double dbl){
    int lower = 0;
    int upper = vec.count - 1;
    int mid = (upper + lower)/2;
    while(lower < upper){
        // searching too early.
        if(vec.vector[mid] < dbl){
            // retain second half of list
            lower = mid + 1;
        }
        // searching too late...retain first half of list
        else upper = mid;
        
        // find new middle of list
        mid = (upper + lower)/2;
    }
    if(vec.vector[mid] == dbl)
        return mid;
    else return -1;
}


/*
    Calculate and return the sum of the elements in
    a vector.
*/
double sum(Vector vec){
    int index;
    double running = 0;
    for(index = 0; index < vec.count; index++){
        running += vec.vector[index];
    }
    return running;
}


/*
    Calculate and return the average of the elements in
    a vector.
*/
double avg(Vector vec){
    double mean = sum(vec); // this is about footprint, not run-time
    mean /= vec.count;
    return mean;
}


/*
    Calculate and return the variance of the elements in
    a vector.
*/
double var(Vector vec){
    double mean = avg(vec);
    double running = 0;
    int index;
    for(index = 0; index < vec.count; index++){
        double dif = mean - vec.vector[index];
        running += (dif * dif)/(vec.count-1);
    }
    
    return running;
}


/*
    Calculate and return the standard deviation of the
    elements in a vector.
*/
double stdv(Vector vec){
    return sqrt(var(vec));
}



/*

    Multiple vector functions

*/

/*
    Perform an element by element addition of two vectors,
    where v3[i] = v1[i] + v2[i] and return the resulting
    vector.
    Does not require vectors from the same space, but produces list of
    greatest length input.
*/
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


/*
    Perform an element by element subtraction of one vector from
    another, where v3[i] = v1[i] - v2[i] and return the resulting
    vector.
*/
Vector sub(Vector v1, Vector v2){
    Vector in_place = copy(v2);
    // footprint, not efficiency
    int index;
    for(index = 0; index < in_place.count; index++){
        in_place.vector[index] *= (-1);
    }
    return add(in_place, v1);
    
}


/*
    Perform an element by element multiplication of two vectors,
    where v3[i] = v1[i] * v2[i] and return the resulting
    vector.
*/
Vector mul(Vector v1, Vector v2){
    if(v1.count != v2.count){
        puts("Cannot multiply vectors of differing length.");
        return empty_vector();
    }
    Vector prod = empty_vector();
    int index;
    for(index = 0; index < v1.count; index++){
        insert(&prod, v1.vector[index] * v2.vector[index]);
    }
    
    return prod;
}


/*
    Perform an element by element division of two vectors,
    where v3[i] = v1[i] / v2[i] and return the resulting
    vector. No effort made to catch DIV0.
*/
Vector divv(Vector v1, Vector v2){
    if(v1.count != v2.count){
        puts("Cannot multiply vectors of differing length.");
        return empty_vector();
    }
    Vector quotient = empty_vector();
    int index;
    for(index = 0; index < v1.count; index++){
        insert(&quotient, v1.vector[index] / v2.vector[index]);
    }
    
    return quotient;
}


/*
    Perform the calculation of the dot product of two vectors,
    where dbl += v1[i] * v2[i] and return the resulting
    double.
*/
double dot(Vector v1, Vector v2){
    return sum(mul(v1, v2));
}


/*
    Perform an element by element comparison of two vectors.
    If for every i, v1[i] == v2[i], and the count is equal
    return 1, otherwise zero.
*/
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