#include "Layer.h"
#include <stdexcept>
#include <cassert>
#include <cmath>
#include <Eigen/Dense>

// Constructor that initializes the layer with a given number of neurons
Layer::Layer(size_t num_neurons) {
    values.resize(num_neurons);  // Initialize all elements to zero
}

// Method to set the value of a specific neuron
void Layer::set_value(size_t index, double value) {
    if (index < values.size()) {
        values(index) = value;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// Method to get the value of a specific neuron
double Layer::get_value(size_t index) const {
    if (index < values.size()) {
        return values(index);
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// Method to get the size of the layer
size_t Layer::size() const {
    return values.size();
}

// Method to access all neuron values
const Eigen::VectorXd& Layer::get_values() const {
    return values;
}

// Method to set all neuron values
void Layer::set_values(const Eigen::VectorXd& new_values) {
    values = new_values;
}

// Method to set the activation function
void Layer::set_activation_function(const std::function<double(double)>& func) {
    activation_function = func;
}

// Method to apply the activation function to all neuron values
void Layer::apply_activation_function() {
    if (activation_function) {
        for (int i = 0; i < values.size(); ++i) {
            values(i) = activation_function(values(i));
        }
    }
}

// Method to update layer values using another layer and a weight matrix
void Layer::update_values(const Eigen::MatrixXd& weights, const Layer& prev_layer) {
    if (weights.cols() != prev_layer.size() || weights.rows() != size()) {
        throw std::invalid_argument("Weight matrix dimensions do not match layer sizes");
    }
    values = weights * prev_layer.get_values();
}

// Common activation functions
double Layer::relu(double x) {
    return x > 0 ? x : 0;
}

double Layer::sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double Layer::tanh(double x) {
    return std::tanh(x);
}

