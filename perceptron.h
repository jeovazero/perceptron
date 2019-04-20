#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

class Perceptron{
    public:
        // Rate vai ser atributo de classe
        static int counter;
        double rate;
        int id;
        Perceptron(vector<double> W, double B, double R);
        vector<double> *weight;
        double bias;
        double sigma;
        double sigmoid;
        double sigmoid_derivate;
        double Sigmoid(double value);
        double Sigmoid_derivate(double value);
        double Sum(vector<double> inputs);
        double SumSigma();
        double Net(vector<double> inputs);
        void UpdateWeights(vector<double> inputs);
};

#endif
