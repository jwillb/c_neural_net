#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fvector.h"
#include "layer.h"

int main(void) {
    srand(time(NULL));

    MATRIX temp;
    float input_arr[3][4] = {{1,2,3,2.5},
                             {2,5,-1,2},
                             {-1.5,2.7,3.3,-0.8}};
    MATRIX input = setMtx(3, 4, input_arr);
    
    float weights_arr[3][4] = {{0.2,0.8,-0.5,1},
                               {0.5,-0.91,0.26,-0.5},
                               {-0.26,-0.27,0.17,0.87}};

    MATRIX weights = setMtx(3, 4, weights_arr);
    temp = transpose(weights, 3, 4);

    freeMtx(weights, 3);
    weights = temp;

    float bias[] = {2,3,0.5};

    float weights2_arr[3][4] = {{0.1,-0.14,0.5},
                               {-0.5,0.12,-0.33},
                               {-0.44,0.73,-0.13}};

    MATRIX weights2 = setMtx(3, 4, weights2_arr);
    temp = transpose(weights2, 3, 3);

    freeMtx(weights2, 3);
    weights2 = temp;

    float bias2[] = {-1,2,-0.5};

    MATRIX layer1_out = multiply(input, 3, 4, weights, 4, 3);
    
    freeMtx(input, 3);
    freeMtx(weights, 4);

    vAdd(layer1_out, 3, 3, bias, 3);

    MATRIX layer2_out = multiply(layer1_out, 3, 3, weights2, 3, 3);
    vAdd(layer2_out, 3, 3, bias2, 3);
    
    freeMtx(layer1_out, 3);
    
    printMtx(layer2_out, 3, 3);
    freeMtx(layer2_out, 3);

    DenseLayer new_layer = newDenseLayer(5, 10);

    printMtx(new_layer.weights, 5, 10);
    freeMtx(weights, 5);

    printVec(new_layer.biases, 10);
    free(new_layer.biases);

    return 0;
}
