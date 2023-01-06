#include "neuronnetwork.h"
#include "math.h"
#include <qdebug.h>

neuronNetwork::neuronNetwork(int layCount, int* tempArch)
{
    layersCount = layCount;
    arch = new int[layersCount];
    for (int i = 0; i < layersCount; i++)
    {
        arch[i] = tempArch[i];
        neuronCount += arch[i];
        if (i > 0) {
            weightCount += arch[i] * arch[i - 1];
        }
    }
    weights = new double[weightCount];
    errors = new double[neuronCount];
    neuronValues = new double[neuronCount];
}



void neuronNetwork::matrixMulti(int M, int N, int K, const double *matrixA, const double *matrixB, double *matrixC)
{
    for (int i = 0; i < M; ++i) {
        double* c = matrixC + i * N;
        for (int j = 0; j < N; ++j)
        {
            c[j] = 0;
        }
        for (int k = 0; k < K; ++k)
        {
            const double* b = matrixB + k * N;
            float a = matrixA[i * K + k];
            for (int j = 0; j < N; ++j)
            {
                c[j] += a * b[j];
                countOfMM++;
            }
        }
    }
}

void neuronNetwork::matrixMultiSumm(int M, int N, int K, const double *matrixA, const double *matrixB, double *matrixC)
{
    for (int i = 0; i < M; ++i){
        double* c = matrixC + i * N;
        for (int k = 0; k < K; ++k)
        {
            const double* b = matrixB + k * N;
            float a = matrixA[i * K + k];
            for (int j = 0; j < N; ++j)
            {
                c[j] += a * b[j];
            }
        }
    }
}

void neuronNetwork::activate(int numberOfValue, int layer)
{
    for (int i = numberOfValue; i < numberOfValue + arch[layer]; i++)
    {
        neuronValues[i] = (1 / (1 + pow(2.71828, -neuronValues[i])));
    }
}

void neuronNetwork::forwardFeed(double *inputData)
{
    for (int i = 0; i < arch[0]; i++){
        neuronValues[i] = inputData[i];
    }
    long long valuesC = 0;
    long long weightsC = 0;
    for (int i = 0; i < layersCount -1; i++)
    {
        double* nv = neuronValues + valuesC;
        double* w = weights + weightsC;
        double* result = nv + arch[i];
        matrixMulti(1, arch[i + 1], arch[i], nv, w, result);
        valuesC += arch[i];
        weightsC += arch[i] * arch[i + 1];
        activate(valuesC, i + 1);
    }

}

void neuronNetwork::BackPropogation(double *rightResult, float lr)
{
    int h = neuronCount - arch[layersCount - 1];
    for (int i = 0; i < arch[layersCount- 1]; i++)
    {
        errors[i + h] = rightResult[i] - neuronValues[i + h];
    }
    long long wcounter = weightCount;
    long long ecounter = neuronCount;
    long long ncounter = neuronCount - arch[layersCount-1];
    for (int i = layersCount- 1; i > 0; i--)
    {
        ecounter -= arch[i];
        wcounter -= arch[i] * arch[i - 1];
        ncounter -= arch[i - 1];
        double* a = errors + ecounter;
        double* b = weights + wcounter;
        double* c = errors + ncounter;
        matrixMulti(1, arch[i - 1], arch[i], a, b, c);

    }

    //обновляем веса
    long long vcounter = neuronCount - arch[layersCount - 1];
    wcounter = weightCount;
    ecounter = neuronCount;
    for (int i = layersCount - 1; i > 0; i--)
    {
        ecounter -= arch[i];
        vcounter -= arch[i - 1];
        wcounter -= arch[i] * arch[i - 1];

        double* b = new double[arch[i]];
        for (int j = 0; j < arch[i]; j++)
        {
            b[j] = errors[ecounter + j] * (1 / (1 + pow(2.71828, -neuronValues[ecounter + j])) * (1 - (1 / (1 + pow(2.71828, -neuronValues[ecounter + j]))))) * lr;
        }
        double* a = neuronValues + vcounter;
        double* c = weights + wcounter;

        matrixMultiSumm(arch[i - 1], arch[i], 1, a, b, c);
        delete[] b;
    }
}

void neuronNetwork::newNetwork()
{
    long long counter = 0;
    for(int i =0; i < layersCount - 1; i++){
        for(int j = 0; j < (arch[i] * arch[i + 1]); i++){
            weights[counter] = (double(rand() % 101)/100.0) / double(arch[i + 1]);
            counter++;
        }
    }
}

void neuronNetwork::getPrediction(double *result)
{
    int counter = 0;
    for(int i = 0; i < layersCount-1; i++){
        counter += arch[i];
    }

    for(int i = 0; i < arch[layersCount-1]; i++){
        result[i] = neuronValues[counter + i];
    }
}
