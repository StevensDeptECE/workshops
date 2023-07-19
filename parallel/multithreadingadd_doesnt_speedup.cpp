#include <thread>

int main() {
    const int n = 1000000;
    float *a = new float[n];
    float *b = new float[n];
    for (int i = 0; i < n; i++)
        a[i] = i, b[i] = i+2;
    
    // vector addition is TOO SIMPLE. There just isn't enough computation to go faster
    // with more CPUs
    float *c = new float[n];
    for (int i = 0; i < n; i++) { // this doesn't get MUCH faster! memory bound
        c[i] = a[i] + b[i];
    }
}