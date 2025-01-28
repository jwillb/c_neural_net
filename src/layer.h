#include "fvector.h"

typedef struct DenseLayer {
    MATRIX weights; // inputs x numnber of neurons
    VECTOR biases; // number of neurons
} DenseLayer;

DenseLayer newDenseLayer(int n_inputs, int n_neurons);
MATRIX forwardPass(DenseLayer layer);

