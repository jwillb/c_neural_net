#include <stdlib.h>

#include "layer.h"
#include "fvector.h"

DenseLayer newDenseLayer(int n_inputs, int n_neurons) {
    DenseLayer l;
    l.weights = randMtx(n_inputs, n_neurons);
    l.biases = newVec(n_neurons);

    return l;
}
