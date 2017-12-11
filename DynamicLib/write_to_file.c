#include "Array.h"
int write_to_file(Vector vec, char *filename){
    FILE* file_out = fopen(filename, "w");
    int x;
    for(x = 0; x < vec.count; x++){
        fprintf(file_out, "%.2f", vec.vector[x]);
        fputc('\n', file_out);
    }
    fclose(file_out);
}