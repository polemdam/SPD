#include "RandomNumberGenerator.h"
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <random>
#include <vector>

struct job {
    int n{};
    int p{};
    int r{};
    int q{};
};


void print(const std::vector<job> &vec) {
    std::cout << "\nj:\n";
    for (const auto &v : vec) {
        std::cout << v.n << " ";
    }
    std::cout << "\nr:\n";
    for (const auto &v : vec) {
        std::cout << v.r << " ";
    }
    std::cout << "\np:\n";
    for (const auto &v : vec) {
        std::cout << v.p << " ";
    }
    std::cout << "\nq:\n";
    for(const auto &v : vec) {
        std::cout << v.q << " ";
    }
    std::cout << "\n";

}

void print(const std::vector<int> &vec) {
    std::cout << "\n";
    for (const auto &v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

void Schrage(uint16_t K, uint8_t G[], uint8_t N[], uint8_t t){}

int main() {
    int seed{};
    int size{};
    std::cout << "Podaj seed: ";
    std::cin >> seed;
    std::cout << "Podaj ilosc zadan: ";
    std::cin >> size;
    auto rng = RandomNumberGenerator(seed);
    std::vector<job> jobs(size);
    int i = 0;
    std::for_each(jobs.begin(), jobs.end(),
                  [&](auto &job) {
                      job.p = rng.nextInt(1, 29);
                      ++i;
                      job.n = i;
                  });
    int a{};
    std::for_each(jobs.begin(), jobs.end(), [&](const auto &job) {
        a += job.p;
    });

    std::for_each(jobs.begin(), jobs.end(),
                  [&](auto &job) {
                      job.q = rng.nextInt(1, 29);
                  });

    std::for_each(jobs.begin(), jobs.end(),
                  [&](auto &job) {
                      job.r = rng.nextInt(1, a);
                  });

    std::for_each(jobs.begin(), jobs.end(),
                  [&](auto &job) {
                      std::cout << job.p << " ";
                  });
    std::for_each(jobs.begin(), jobs.end(),
                    [&](auto &job) {
                    std::cout << job.q << " ";
                  });

    std::sort(jobs.begin(), jobs.end(), [&](const auto &lhs, const auto &rhs) {
        return lhs.r < rhs.r;
    });
    std::vector<int> s_time;
    std::vector<int> c_time;
    s_time.push_back(std::max(jobs[0].r, 0));
    c_time.push_back(s_time[0] + jobs[0].p);
    for (size_t i = 1; i < size; ++i) {
        s_time.push_back(std::max(jobs[i].r, c_time[i - 1]));
        c_time.push_back(s_time[i] + jobs[i].p);
    }

    /* Schrage algorythm */

    

}
