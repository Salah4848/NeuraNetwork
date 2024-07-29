#pragma once

#include <Eigen/Dense>
#include <vector>
#include <functional>
#include <cmath>

class Layer {
private:
    Eigen::VectorXd values;
    std::function<double(double)> activation_function;

public:
    // Default constructor
    Layer() = default;

    // Constructor that initializes the layer with a given number of neurons
    Layer(size_t num_neurons);

    // Method to set the value of a specific neuron
    void set_value(size_t index, double value);

    // Method to get the value of a specific neuron
    double get_value(size_t index) const;

    // Method to get the size of the layer
    size_t size() const;

    // Method to access all neuron values
    const Eigen::VectorXd& get_values() const;

    // Method to set all neuron values
    void set_values(const Eigen::VectorXd& new_values);

    // Method to set the activation function
    void set_activation_function(const std::function<double(double)>& func);

    // Method to apply the activation function to all neuron values
    void apply_activation_function();

    // Method to update layer values using another layer and a weight matrix
    void update_values(const Eigen::MatrixXd& weights, const Layer& prev_layer);

    // Common activation functions
    static double relu(double x);
    static double sigmoid(double x);
    static double tanh(double x);
};
