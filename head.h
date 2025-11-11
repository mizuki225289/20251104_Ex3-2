//read_datafile
void read_M(
    int* M
);
void read_data(
    int M,
    std::complex <double> *alpha, std::complex <double> *beta,
    std::complex <double> *f, double *l
);
void read_boundary(
    int *type,
    std::complex <double> *p, std::complex <double> *gamma, std::complex <double> *q
);

//output_datafile
void output_M(int* M);
void output_data(
    int M,
    std::complex <double> *alpha, std::complex <double> *beta,
    std::complex <double> *f, double *l
);
void output_boundary(
    int *boundary_type_in0, std::complex <double> *p0, std::complex <double> *gamma0, std::complex <double> *q0,
    int *boundary_type_inL, std::complex <double> *pL, std::complex <double> *gammaL, std::complex <double> *qL
);