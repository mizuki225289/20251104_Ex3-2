#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

void read_datafile(
    int *M,
    std::complex <double> *alpha,
    std::complex <double> *beta,
    std::complex <double> *f,
    double *l,
    int *boundary_type_in0,
    double *p0, double *gamma0, double *q0,
    double *pL, double *gammaL, double *qL
) {
    /*Mの値よみこみ*/
    int M;//データの個数
    std::cin >> M;
    std::cout << "M = " << M << std::endl;

    /*虚数単位定義*/
    const std::complex <double> zj (0.0, 1.0);
    
    /*要素のデータよみこみ*/
    double alpha_Re, alpha_Im, beta_Re, beta_Im, f_Re, f_Im;
    double l[M];
    std::complex <double> alpha[M], beta[M], f[M];
    for(int i=0; i < M; i++) {
        std::cin >> alpha_Re;
        std::cin >> alpha_Im;
        std::cin >> beta_Re;
        std::cin >> beta_Im;
        std::cin >> f_Re;
        std::cin >> f_Im;

        alpha[i] = alpha_Re + zj * alpha_Im;
        beta[i] = beta_Re + zj * beta_Im;
        f[i] = f_Re + zj * f_Im;

        std::cin >> l[i];
    }

    /*b.c. at x=0*/
    int boundary_type_in0;
    double p0, gamma0, q0;
    std::cin >> boundary_type_in0;
    if(boundary_type_in0 == 1) {
        std::cin >> p0;
    } else if(boundary_type_in0 == 3) {
        std::cin >> gamma0;
        std::cin >> q0;
    } else {
        std::cout << "Error!" << std::endl;
        exit(1);
    }

    /*b.c. at x=L*/
    int boundary_type_inL;
    double pL, gammaL, qL;
    std::cin >> boundary_type_inL;
    if(boundary_type_inL == 1) {
        std::cin >> pL;
    } else if(boundary_type_inL == 3) {
        std::cin >> gammaL;
        std::cin >> qL;
    } else {
        std::cout << "Error!" << std::endl;
        exit(1);
    }

    std::cout << "alpha >";
    for(int i=0; i < M; i++) {
        std::cout << alpha[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "beta >";
    for(int i=0; i < M; i++) {
        std::cout << beta[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "f >";
    for(int i=0; i < M; i++) {
        std::cout << f[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "l >";
    for(int i=0; i < M; i++) {
        std::cout << l[i] << " ";
    }
    std::cout << std::endl;

    std::cout << boundary_type_in0 << " " << p0 << " " << gamma0 << " " << q0 << std::endl;
    std::cout << boundary_type_inL << " " << pL << " " << gammaL << " " << qL << std::endl;

    std::cout << "test3" << std::endl;
}