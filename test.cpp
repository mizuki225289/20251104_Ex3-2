#include <iostream>

void array(int* a) {
    for(int i=0; i < 5; i++) {
        a[i] = i + 1;
    }
}

void num(int *M) {
    *M = 100;
}

int main(void) {
    int a_main[5];
    array(a_main);

    for(int i=0; i < 5; i++) {
        std::cout << a_main[i] << std::endl;
    }

    int N;
    num(&N);
    std::cout << "N = " << N << std::endl;

    return 0;
}