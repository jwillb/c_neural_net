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
    float bias[] = {2,3,0.5};

    MATRIX weights = setMtx(3, 4, weights_arr);
    MATRIX temp = transpose(weights, 3, 4);

    freeMtx(weights, 3);
    weights = temp;

    MATRIX out = multiply(input, 3, 4, weights, 4, 3);
    
    freeMtx(input, 3);
    freeMtx(weights, 4);

    vAdd(out, 3, 3, bias, 3);
    
    printMtx(out, 3, 3);
    freeMtx(out, 3);

    return 0;
}
