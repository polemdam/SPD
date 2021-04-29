#include <iostream>
#include "RandomNumberGenerator.h"
#include <array>
#include <vector>
#include <iterator>
/*
  struct p{
    static int n;
    static int m;
    int tab[n][m];
};
 */
std::ostream &operator << (std::ostream &wyjscie, std::vector<int> myVector) {
return wyjscie << "Macierz zadan: "<< myVector <<std::endl;}
int main() {
    int seed = 0;
    int task; // n - ilosc zadan
    int m; // m - ilosc maszyn
    int l[task];
    std::cout << "Podaj seed:";
        std::cin >> seed;
    std::cout <<"Podaj ilosc zadan:";
        std::cin >> task;
    std::cout <<"Podaj ilosc maszyn:";
        std::cin >> m;

    int p[task][m];
    auto rng = RandomNumberGenerator(seed);
    std::vector<int> myVector(task);
    for(size_t i = 0; i < task; i++){
        //myVector.push_back(std::vector<int>());
        myVector[i] = (rng.nextInt(1,29));
        std::cout << myVector << std::endl;

    }
/*
 * Generuj instancję

for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        p[i][j] = rng.nextInt(1,29);
    }
}

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << p[i][j] << std::endl;
        }
        std::cout<<"\n";
    }

 */
    return 0;
}