#ifndef KERNELS_H
#define KERNELS_H

#include <bits/stdc++.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>

#define inf 50000

template<typename T>
void set_model(T *Y, T *y, T *mu,
               T *beta, T *alp, T *bet,
               int *nVars, int *lasso, int *step,
               int *done, int *act, int M, int N,
               int mod, int hact, cudaStream_t stream,
               dim3 blockDim);

void check(int *nVars, int *step, int maxVariables,
           int maxSteps, int *done, int *ctrl,
           int numModels);

template<typename T>
void set(T *array, T val, int size, dim3 blockDim);

template<typename T>
void mat_sub(T *a, T *b, T *c,
             int size, dim3 blockDim);

template<typename T>
void exclude(T *absC, int *lVars, int *nVars,
             int *act, int M, int N,
             int numModels, T def, dim3 blockDim);

template<typename T>
void set_cidx(T *cmax, int *cidx, T *c, int N, int numModels, dim3 blockDim);

void lasso_add(int *lasso, int *lVars, int *nVars,
               int *cidx, int M, int N,
               int numModels, dim3 blockDim);

template<typename T>
void gather(T *XA, T *X, int *lVars,
            int ni, int M, int N,
            int mod, cudaStream_t stream, dim3 blockDim);

template<typename T>
void gammat(T *gamma, T *beta, T *betaOls,
            int *lVars, int *nVars, int M,
            int N, int numModels, dim3 blockDim);

template<typename T>
void trans(T *c, T *cd, T *cmax,
           int *act, int N, int numModels, dim3 blockDim);

template<typename T>
void set_gamma(T *gamma, T *r, int *dropidx,
               int *lasso, int *nVars, int maxVariables,
               int M, int numModels, dim3 blockDim);

template<typename T>
void update(T *beta, T *mu, T *d, T *a1, T *a2,
            T *betaOls, T *gamma, int *lVars, 
            int *nVars, int M, int N,
            int numModels, dim3 blockDim);

void drop(int *lVars, int *dropidx, int *nVars,
          int *lasso, int M, int numModels);

template<typename T>
void final(T *a1, T *a2, T *cmax, T *r, int *step,
           int *done, int numModels, T g, dim3 blockDim);

#endif