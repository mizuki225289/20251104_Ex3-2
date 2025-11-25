#include <iostream>
#include <fstream>
#include <complex>
#include <string>
#include <cmath>

std::complex <double> zj (0.0, 1.0); /*()はコンストラクタ*/

// std::complex <double> MU_r = std::complex <double> (2.0, -0.1);
std::complex <double> MU_r (2.0, -0.1);

double L = 5.0;
double lambda = 1.0;
double k0 = 2.0 * M_PI / lambda;

std::complex <double> EPS_r(double x) {
    // return 4.0 + (2.0 - 0.1 * zj) * (1.0 - x / L) * (1.0 - x / L);
    return 4.0 - 0.1 * zj;
}

std::complex <double> alpha = 1.0 / MU_r;

std::complex <double> beta(double theta, double x) {
    return -k0 * k0 * (EPS_r(x) - sin(theta) * sin(theta) / MU_r);
}

void makedatfile(void) {
    // std::ofstream ofs("dinput.dat");

    int M;
    std::cout << "M > " << std::endl;
    std::cin >> M;
    // ofs << M << std::endl;

    // ofs << real(1.0 / MU_r) << " " << imag(1.0 / MU_r) << std::endl;

    for(int theta_deg = 0; theta_deg <= 90; theta_deg += 5) {
        std::ofstream ofs_dat("./input/input_theta" + std::to_string(theta_deg) + ".dat");
        double theta = theta_deg * M_PI / 180.0;

        ofs_dat << M << std::endl;

        for(int i=0; i < M; i++) {
            double x = (i+0.5) * L / M;
            ofs_dat << real(alpha) << " " << imag(alpha) << " "; /*alpha*/
            ofs_dat << real(beta(theta, x )) << " " << imag(beta(theta, x)) << " ";
            ofs_dat << 0 << " " << 0 << " " << L / M << std::endl; //f, l
        }

        std::complex <double> gamma = zj * k0 * cos(theta);
        std::complex <double> q = 2.0 * zj * k0 * cos(theta) * exp(zj * k0 * L * cos(theta));
        ofs_dat << 1 << " " << 0 << std::endl;
        ofs_dat << 3 << " " << gamma << " " << q << std::endl;

        ofs_dat.close();
    }

}

int main(void) {
    makedatfile();

    // int M = 50;
    // for(int theta_deg = 0; theta_deg <= 90; theta_deg += 5){
    //     double theta = theta_deg * M_PI / 180.0;
    //     for(int i=0; i < M; i++) {
    //         double x = i * L / M;
    //         std::cout << theta_deg << " " << i << " " << beta(theta, x) << std::endl;
    //     }
    // }

    std::cout << EPS_r(0.05) << std::endl;
    std::cout << k0 << std::endl;
    std::cout << k0 * k0 * EPS_r(0.05) << std::endl;

    return 0;
}