#include <iostream>
#include <fstream>
#include <complex>

std::complex <double> zj (0.0, 1.0);

std::complex <double> EPS_r(double x, double L) {
    return 4.0 + (2.0 - 0.1 * zj) * (1.0 - x / L) * (1.0 - x / L);
}

void makedatfile(void) {
    std::ofstream ofs("dinput.dat");

    int M;
    std::cout << "M > " <<std::endl;
    std::cin >> M;
    ofs << M << std::endl;

    std::complex <double> MU_r = std::complex <double> (2.0, -0.1);
    ofs << real(1.0 / MU_r) << " " << imag(1.0 / MU_r) << std::endl;

}

int main(void) {
    makedatfile();

    return 0;
}