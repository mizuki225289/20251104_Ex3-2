#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>
// #include <sstream>
#include <string>
#include "head.h"

void solve ( //ガウスの消去法
    int *N, //対角成分の個数
    std::complex <double> *answer,
    std::complex <double> *diagonal,
    std::complex <double> *offdiagonal,
    std::complex <double> *righthand
);

int main(void) {
    /*mainで用意した配列にデータを読み込ませる*/
    int M;
    read_M(&M);

    std::complex <double> alpha[M], beta[M], f[M];
    double l[M];
    read_data(M, alpha, beta, f, l);

    int boundary_type_in0, boundary_type_inL;
    std::complex <double> p0, pL, gamma0, gammaL, q0, qL;
    read_boundary(&boundary_type_in0, &p0, &gamma0, &q0);
    read_boundary(&boundary_type_inL, &pL, &gammaL, &qL);

    /*データを書き出させて確認*/
    output_M(&M);
    // output_data(M, alpha, beta, f, l);
    output_boundary(
        &boundary_type_in0, &p0, &gamma0, &q0,
        &boundary_type_inL, &pL, &gammaL, &qL
    );

    int N = M+1;
    /*読み込んだデータから対角行列など作成*/
    std::complex <double> diagonal[M+1] = {}, offdiagonal[M] = {}, righthand[M+1] = {};
    diagonal[0] = alpha[0] / l[0] + beta[0] * l[0] / 3.0;
    diagonal[M] = alpha[M-1] / l[M-1] + beta[M-1] * l[M-1] / 3.0;
    righthand[0] = f[0] * l[0] / 2.0;
    righthand[M] = f[M-1] * l[M-1] / 2.0;
    for(int i=1; i < M; i++) {
        diagonal[i] = alpha[i-1] / l[i-1] + beta[i-1] * l[i-1] / 3.0
                    + alpha[i] / l[i] + beta[i] * l[i] / 3.0;
        righthand[i] = f[i-1] * l[i-1] / 2.0 + f[i] * l[i] / 2.0;
    }
    for(int i=0; i < M; i++) {
        offdiagonal[i] = -alpha[i] / l[i] + beta[i] * l[i] / 6.0;
    }
    
    /*境界条件適用 x=L*/
    if(boundary_type_inL == 1) {
        diagonal[N-1] = 1.0;
        righthand[N-1] = pL;
        righthand[N-2] = righthand[N-2] - offdiagonal[N-3] * pL;
        offdiagonal[N-2] = 0;
    } else if(boundary_type_inL == 3) {
        diagonal[M] = alpha[M-1] / l[M-1] + beta[M-1] * l[M-1] / 3.0 + gammaL;
        righthand[M] = f[M-1] * l[M-1] / 2.0 + qL;
    }

    // for(int i=0; i < N; i++) {
    //     std::cout << i << " " << diagonal[i] << " " << offdiagonal[i] << " " << righthand[i] << std::endl;
    // }

    /*境界条件適用 x=0*/
    if(boundary_type_in0 == 1) {
        diagonal[0] = 1.0;
        righthand[0] = p0;
        righthand[1] = righthand[1] - offdiagonal[0] * p0;
        offdiagonal[0] = 0;
    } else if(boundary_type_in0 == 3) {
        diagonal[0] = diagonal[0] + gamma0;
        righthand[0] = righthand[0] + q0;
    }

    std::cout << "diagonal etc\n";
    for(int i=0; i < M+1; i++) {
        std::cout << i << " " << diagonal[i] << " " << offdiagonal[i] << " " << righthand[i] << std::endl;
    }

    std::complex <double> answer[N] = {};
    solve(&N, diagonal, offdiagonal, righthand, answer);

    std::ofstream ofs("result.dat");
    double x = 0.0;
    for(int i=0; i < N; i++) {
        ofs << x << " " << real(answer[i]) << " " << imag(answer[i]) << std::endl;
        x += l[i];
    }
    ofs.close();

    double L = 5.0;
    double lambda = 1.0;
    double k0 = 2.0 * M_PI / lambda;
    std::complex <double> zj (0.0, 1.0); /*()はコンストラクタ*/

    /* 反射係数表示*/
    std::complex <double> ReflectionCoef;
    double theta_deg, theta;
    // std::cout << "theta_deg > " << std::endl;
    // std::cin >> theta_deg;
    theta_deg = 60.0;
    // std::cout << "theta > " << std::endl;
    // std::cin >> theta_deg;
    theta = theta_deg * M_PI / 180.0;
    ReflectionCoef = (answer[M] - exp(zj * k0 * L * cos(theta))) / exp(-zj * k0 * L * cos(theta));
    std::cout << "R = " << ReflectionCoef << " " << abs(ReflectionCoef) << std::endl;

    return 0;
}