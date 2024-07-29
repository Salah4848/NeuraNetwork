#include "Layer.h"
#include <iostream>
#include <Eigen/Dense>

int main() {
    // Create previous layer with 3 neurons
    Layer prev_layer(3);
    prev_layer.set_value(0, 1.0);
    prev_layer.set_value(1, 2.0);
    prev_layer.set_value(2, 3.0);

    // Create current layer with 2 neurons
    Layer current_layer(2);

    // Define weight matrix (2x3) using Eigen
    Eigen::MatrixXd weights(2, 3);
    weights << 0.5, 0.3, 0.2,
                 0.4, 0.6, 0.1;

    // Update current layer values using weights and previous layer
    current_layer.update_values(weights, prev_layer);

    // Apply an activation function (e.g., ReLU)
    current_layer.set_activation_function(Layer::relu);
    current_layer.apply_activation_function();

    // Print the values after activation
    for (size_t i = 0; i < current_layer.size(); ++i) {
        std::cout << "Neuron " << i << ": " << current_layer.get_value(i) << std::endl;
    }
    std::cout<< weights<< std::endl;

    return 0;
}

