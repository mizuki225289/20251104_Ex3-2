#include <complex>
#include <iostream>
#include <fstream>
#include <cmath>

std::complex <double> EPS_r (4.0, -0.1);
std::complex <double> MU_r (2.0, -0.1);
std::complex <double> zj (0.0, 1.0);
double L = 5.0;
double lambda = 1.0;
double k0 = 2.0 * M_PI / lambda;

std::complex <double> ReflectionCoef_analytical(double theta_deg) {
    double theta = theta_deg * M_PI / 180.0;
    std::complex <double> alpha1 = sqrt(EPS_r * MU_r - sin(theta) * sin(theta));
    std::complex <double> alpha2 = cos(theta);

    std::complex <double> tmp1 = (alpha1 - MU_r * alpha2) * exp(zj * k0 * alpha1 * L);
    std::complex <double> tmp2 = (alpha1 + MU_r * alpha2) * exp(-zj * k0 * alpha1 * L);
    std::complex <double> tmp3 = - exp(2.0 * zj * k0 * alpha2 * L);
    std::complex <double> tmp4 = (alpha1 + MU_r * alpha2) * exp(zj * k0 * alpha1 * L);
    std::complex <double> tmp5 = (alpha1 - MU_r * alpha2) * exp(-zj * k0 * alpha1 * L);

    std::complex <double> R = ((tmp1 + tmp2) * tmp3) / (tmp4 + tmp5);

    return R;    
}

int main(void) {
    std::ofstream ofs_R("analytical_R.dat");
    std::ofstream ofs_abs("analytical_abs.dat");

    for(int theta = 0; theta <= 90; theta = theta + 5) {
        ofs_R << theta << " " << ReflectionCoef_analytical(theta) << std::endl;
        ofs_abs << theta << " " << abs(ReflectionCoef_analytical(theta)) << std::endl;
    }

    ofs_R.close();
    ofs_abs.close();
}