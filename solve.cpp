#include <iostream>
#include <complex>

void solve ( //ガウスの消去法
    int *N, //対角成分の個数
    std::complex <double> *diagonal,
    std::complex <double> *offdiagonal,
    std::complex <double> *righthand,
    std::complex <double> *answer
) {

    // std::cout << 0 << " " << diagonal[0] << " " << offdiagonal[0] << " " << righthand[0] << std::endl;
    // std::cout << 100 << " " << diagonal[100] << " " << righthand[100] << std::endl;

    for(int i=1; i < *N; i++) {
        diagonal[i] = diagonal[i] - offdiagonal[i-1] * offdiagonal[i-1] / diagonal[i-1];
        righthand[i] = righthand[i] - offdiagonal[i-1] * righthand[i-1] / diagonal[i-1];
    }

    // std::cout << 100 << " " << diagonal[100] << " " << righthand[100] << std::endl;

    answer[*N-1] = righthand[*N-1] / diagonal[*N-1];

    for(int i = *N-2; i >= 0; i--) {
        answer[i] = (righthand[i] - offdiagonal[i] * answer[i+1]) / diagonal[i];
    }

}