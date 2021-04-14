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
    std::cout << "\npi:\n";
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
    int a{0};
    std::for_each(jobs.begin(), jobs.end(), [&](const auto &job) {
        a += job.p;
    });

    std::for_each(jobs.begin(), jobs.end(),
                  [&](auto &job) {
                      job.r = rng.nextInt(1, a);
                  });

    std::for_each(jobs.begin(), jobs.end(),
                  [&](auto &job) {
                      job.q = rng.nextInt(1, a);
                  });

std::cout << "Permutacja naturalna " << std::endl;
print(jobs);
std::cout << "\n";

    /* Schrage algorythm */
    std::vector<job> N = jobs;
    std::vector<job> G;
    std::vector<job> pi;
    int k{};
    int t = (*std::min_element(N.begin(), N.end(), [&]( const auto &lhs, const auto &rhs) {
        return lhs.r < rhs.r;
    })).r;

    while(G.size() || N.size()) {   /* while G != 0 or N != 0 */
        while (N.size() &&
               (*std::min_element(N.begin(), N.end(), [&](const auto &lhs, const auto &rhs) { /* while N != 0 and min(r) <t */
                   return lhs.r < rhs.r;
               })).r <= t) {
            auto it = (std::min_element(N.begin(), N.end(), [&](const auto &lhs, const auto &rhs) { /* j <- argmin(rj) */
                return lhs.r < rhs.r;
            }));
            G.emplace_back(*it); /* G <- u {j*} */
            N.erase(it);         /* N <- \{j*} */
        }
        if (G.size()) {

            auto it = (std::max_element(G.begin(), G.end(), [&](const auto &lhs, const auto &rhs) {
                return lhs.q < rhs.q;
            }));
            pi.push_back(*it);
            t += it->p;
            G.erase(it);
            ++k;
        } else {
            t = (*std::min_element(N.begin(), N.end(), [&](const auto &lhs, const auto &rhs) {
                return lhs.r < rhs.r;
            })).r;
        }
    }
    std::vector<int> s_time;
    std::vector<int> c_time;
    int c_max{};
    s_time.push_back(std::max(pi[0].r, 0));
    c_time.push_back(s_time[0] + pi[0].p);
    c_max = c_time[0] + pi[0].q;
    for (size_t i = 1; i < size; ++i) {
        s_time.push_back(std::max(pi[i].r, c_time[i - 1]));
        c_time.push_back(s_time[i] + pi[i].p);
        c_max = std::max(c_max,c_time[i]+pi[i].q);
    }
std::cout << "c_max\n";
    std:: cout << c_max;
    std:: cout << "\n";
    std::cout << "Po algorytmie Shrage" << std::endl;
    print(pi);
}
