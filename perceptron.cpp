#include "perceptron.h"

int Perceptron::counter = 0;

double Perceptron::Sigmoid(double value){
    return 1 / (1 + exp(-value));
}

double Perceptron::Sigmoid_derivate(double value){
    double s = Sigmoid(value);
    return s * ( 1 - s );
}

Perceptron::Perceptron(vector<double> W, double B, double R){
    vector<double> *w = new vector<double>;
    vector<double>::iterator it = W.begin();
    for(; it != W.end(); it++){
        w->push_back(*it);
    }
    this->weight = w;
    this->bias = B;
    this->rate = R;
    this->id = Perceptron::counter++;
    // cout << this->id << endl;
}

double Perceptron::Sum(vector<double> inputs){
    double sum = 0;
    vector<double>::iterator w = this->weight->begin();
    // cout << "Perceptron : " << this->id << endl;
    int p = 0;
    for(vector<double>::iterator it = inputs.begin(); it != inputs.end(); it++){
        cout << "==== Peso " << p++ << ": " << *it << endl;
        // cout << "Peso : " << *w << " Input: " << *it << endl;
        sum += ((*it) * (*w));
        w++;
    }
    // cout << "Sum: " << sum << endl;
    return sum;
}

double Perceptron::SumSigma(){
    double sum = 0;
    // cout << "== Perceptron " << this->id << endl;
    int p = 0;
    for(vector<double>::iterator it = this->weight->begin(); it != this->weight->end(); it++){
        // cout << "==== Peso " << p++ << ": " << *it << endl;
        sum += ((*it) * this->sigma);
    }
    return sum;
}

double Perceptron::Net(vector<double> inputs){
    cout << "== Perceptron " << this->id << endl;
    double sum = Sum(inputs);
    sum += this->bias;
    cout << "==== Bias: " << this->bias  << endl << "==== Soma Ponderada: " << sum << endl << endl;;
    this->sigmoid = Sigmoid(sum);
    this->sigmoid_derivate = this->sigmoid*(1 - this->sigmoid);
    return sum;
}

void Perceptron::UpdateWeights(vector<double> inputs){
    vector<double>::iterator it = this->weight->begin();
    vector<double>::iterator it_in = inputs.begin();
    cout << "== Perceptron : " << this->id <<  endl;
    int p = 0;
    for(; it != this->weight->end(); it++){
        // cout << "Old weight: " << *it;
        *it += (this->rate * (*it_in) * this->sigma);
        // cout << " Delta Weight: " <<  (rate * (*it_in) * this->sigma);
        cout << "====  Novo Peso " << p++ <<  ": " << *it << endl;
        it_in++;
    }
    // cout << "Old bias: " << this->bias << " new Bias: ";
     this->bias = this->bias + this->sigma * this->rate;
    cout << "====  Novo Bias: " << this->bias << endl;
    // cout << this->bias << endl;
}
