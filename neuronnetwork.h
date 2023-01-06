#ifndef NEURONNETWORK_H
#define NEURONNETWORK_H


class neuronNetwork
{
public:
    int layersCount = 1;
    int* arch;
    long neuronCount = 0;
    long weightCount = 0;

    double* neuronValues;
    double* errors;
    double* weights;

    long long countOfMM = 0;

    neuronNetwork(int layCount, int* tempArch);

    void matrixMulti(int M, int N, int K, const double* matrixA, const double* matrixB, double* matrixC);

    void matrixMultiSumm(int M, int N, int K, const double* matrixA, const double* matrixB, double* matrixC);

    void activate(int numberOfValue, int layer);

    void forwardFeed(double* inputData);

    void BackPropogation(double* rightResult, float lr);

    void newNetwork();

    void getPrediction(double * result);
};

#endif // NEURONNETWORK_H
