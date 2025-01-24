#include <stdio.h>
#include <stdlib.h>

#include "fvector.h"

int main(void) {
    float input_arr[3][4] = {{1,2,3,2.5},
                             {2,5,-1,2},
                             {-1.5,2.7,3.3,-0.8}};
    MATRIX input = setMtx(3, 4, input_arr);
    
    float weights_arr[3][4] = {{0.2,0.8,-0.5,1},
                               {0.5,-0.91,0.26,-0.5},
                               {-0.26,-0.27,0.17,0.87}};
    MATRIX weights = setMtx(3, 4, weights_arr);
    MATRIX weights_t = transpose(weights, 3, 4);
    freeMtx(weights, 3);

    float bias[] = {2,3,0.5};

    MATRIX out = multiply(input, 3, 4, weights_t, 4, 3);
    
    freeMtx(weights_t, 4);
    freeMtx(input, 3);
    

    vAdd(out, 3, 4, bias, 3);
    
    printMtx(out, 3, 3);
    free(out);

    return 0;
}
