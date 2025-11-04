#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

std::array<double, M> solve(int N, std::vector<double> a, std::vector<double> b, std::vector<double> c) {
    //Step7 ガウスの消去法
    std::vector<double> new_a(N);
    std::vector<double> new_b(N);
    std::vector<double> phi(N);
    
    new_a.at(0) = a.at(0);
    new_b.at(0) = b.at(0);
    for(int i=1; i < N; i++) {
        new_a.at(i) = a.at(i) - c.at(i-1) * c.at(i-1) / new_a.at(i-1);
    }
    for(int i=1; i < N; i++) {
        new_b.at(i) = b.at(i) - c.at(i-1) * new_b.at(i-1) / new_a.at(i-1);
    }

    phi.at(N-1) = new_b.at(N-1) / new_a.at(N-1);
    for(int i = *N-2; i >= 0; i--) {
        phi.at(i) = (new_b.at(i) - c.at(i) * phi.at(i+1)) / new_a.at(i);
    }

    // for(int i=0; i < N; i++) {
    //     std::cout << "new_a " << new_a.at(i) <<std::endl;
    // }
    // for(int i=0; i < N; i++) {
    //     std::cout << "new_b " << new_b.at(i) <<std::endl;
    // }
    // for(int i=0; i < N; i++) {
    //     std::cout << "phi " << phi.at(i) <<std::endl;
    // }

    //結果ファイル出力
    std::string name;
    std::cout << "file name > \n";
    std::cin >> name;
    std::ofstream ofs(name);
    for(int i=0; i < *N; i++) {
        ofs << 1.0 * i / (N-1) << " " << phi.at(i) << std::endl;
    }
    ofs.close();
}