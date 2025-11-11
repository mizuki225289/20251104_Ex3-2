#include <iostream>
#include <complex>

void read_M(int* M) {
    std::cin >> *M; /* (*M) = 読み込むデータの個数*/
}

void read_data(
    int M,
    std::complex <double> *alpha, std::complex <double> *beta,
    std::complex <double> *f, double *l
) {
    /*虚数単位定義*/
    const std::complex <double> zj (0.0, 1.0);
    
    double alpha_Re[M], alpha_Im[M], beta_Re[M], beta_Im[M], f_Re[M], f_Im[M];
    for(int i=0; i < M; i++) {
        std::cin >> alpha_Re[i];
        std::cin >> alpha_Im[i];
        std::cin >> beta_Re[i];
        std::cin >> beta_Im[i];
        std::cin >> f_Re[i];
        std::cin >> f_Im[i];
        std::cin >> l[i];

        alpha[i] = alpha_Re[i] + zj * alpha_Im[i];
        beta[i] = beta_Re[i] + zj * beta_Im[i];
        f[i] = f_Re[i] + zj * f_Im[i];
    }
}

void read_boundary(
    int *type,
    std::complex <double> *p, std::complex <double> *gamma, std::complex <double> *q
) {
    std::cin >> *type;
    if(*type == 1) { //Dirichlet
        std::cin >> *p;
    } else if(*type == 3) { //Neumann
        std::cin >> *gamma;
        std::cin >> *q;
    } else {
        std::cout << "Error!!" << std::endl;
        exit(1);
    }
}  