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
    double *p, double *gamma, double *q
);

//output_datafile
void output_M(int* M);
void output_data(
    int M,
    std::complex <double> *alpha, std::complex <double> *beta,
    std::complex <double> *f, double *l
);
void output_boundary(
    int *boundary_type_in0, double *p0, double *gamma0, double *q0,
    int *boundary_type_inL, double *pL, double *gammaL, double *qL
);