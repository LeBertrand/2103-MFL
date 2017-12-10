#include "Array.h"
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