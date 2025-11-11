#include <iostream>
#include <complex>

void output_M(int* M) {
    std::cout << "M = " << *M << std::endl << std::endl;
}

void output_data(
    int M,
    std::complex <double> *alpha, std::complex <double> *beta,
    std::complex <double> *f, double *l
) {
    for(int i=0; i < M; i++) {
        std::cout << i << std::endl;
        std::cout << "alpha : " << alpha[i] << std::endl;
        std::cout << "beta : " << beta[i] << std::endl;
        std::cout << "f : " << f[i] << std::endl;
        std::cout << "l : " << l[i] << std::endl << std::endl;
    }
}

void output_boundary(
    int *boundary_type_in0, std::complex <double> *p0, std::complex <double> *gamma0, std::complex <double> *q0,
    int *boundary_type_inL, std::complex <double> *pL, std::complex <double> *gammaL, std::complex <double> *qL
) {
    std::cout << "x = 0" << std::endl;
    std::cout << *boundary_type_in0 << " " << *p0 << " " << *gamma0 << " " << *q0 << std::endl;
    std::cout << "x = L" << std::endl;
    std::cout << *boundary_type_inL << " " << *pL << " " << *gammaL << " " << *qL << std::endl << std::endl;
}  