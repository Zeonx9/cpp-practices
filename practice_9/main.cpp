//
// Created by musht on 23.12.2022.
//
#define B

#include <chrono>
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include "LinkedList.h"

#ifdef A
using Clock = std::chrono::steady_clock;

template<typename Callable>
double test(Callable func) {
    // call a function
    std::chrono::time_point<Clock> start = Clock::now();
    func();
    std::chrono::time_point<Clock> finish = Clock::now();

    // count and output time
    std::chrono::duration<double, std::micro> dur = finish - start;
    return dur.count();
}

template<class T>
void print_ll(const LinkedList<T> &ll) {
    for (auto e : ll) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

template<class T>
void run_tests(int n) {
    T v;
    // create random engine
    std::mt19937 engine(Clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distrib(-100, 100);
    std::uniform_int_distribution<int> index_dist(0, n - 1);

    auto test1 = [&] { // 9.1.1
        for (int i = 0; i < n; ++i) {
            v.push_back(distrib(engine));
        }
    };
    auto test2 = [&] {
        for (int i = 0; i < n; ++i) {
            v.insert(v.begin(),distrib(engine));
        }
    };
    auto test3 = [&] {
        auto ind = index_dist(engine);
        auto pos = v.begin() + ind;
        v.insert(pos, distrib(engine));
    };

    // actually run tests;
    std::cout << "reuslts\n" << test(test1) << "\n";
    v.clear();
    std::cout << test(test2) << "\n";
    std::cout << test(test3) << "\n";
}

int main () {
    int n;
    std::cout << "Enter N:";
    std::cin >> n;

    run_tests<std::vector<int>>(n);
    run_tests<LinkedList<int>>(n);
}
#endif

#ifdef B

void check_boundaries_and_increment(std::vector<int> &v, int ind) {
    if (ind < 0)
        ++v[0];
    else if (ind >= v.size())
        ++v[v.size() - 1];
    else
        ++v[ind];
}

// d - distance between pegs
// m - number of rows
// k - number of bins
// w - width of bin
// n - repeat
std::vector<int> galton_board(double d, int m, int k, double w, int n) {
    std::mt19937 engine(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution dist(0, 1);
    std::vector<int> v(k, 0);

    for (int i = 0; i < n; ++i) {
        double x = 0.0;
        for (int j = 0; j < m; ++j){
            if (dist(engine))
                x += d;
            else
                x -= d;
        }
        int ind = std::floor(x / w + (double) k / 2.0);
        check_boundaries_and_increment(v, ind);
    }
    return v;
}

void print_galton_board_horizontally(const std::vector<int> &board) {
    int max_val = *std::max_element(board.begin(), board.end());
    for (int i = 0; i < board.size(); ++i) {
        auto h = board[i] * 100 / max_val;
        std::cout << std::setw(3) << i << " ";
        for (int j = 0; j < h; ++j)
            std::cout << (char) 178;
        std::cout << "\n";
    }
}

std::pair<double, double> find_normal_distrib(const std::vector<int> &board) {
    long long n = 0;
    for (auto e : board) // count total
        n += e;
    double mean = 0;
    for (int i = 0; i < board.size(); ++i) { // calcuate mean
        mean += (double) i / (double) n * (double) board[i];
    }
    double stddev = 0;
    for (int i = 0; i < board.size(); ++i) { // calculate deviation
        double x0 = (double) i - mean;
        stddev += x0 * x0 / (double) n * (double) board[i];
    }
    return std::pair{mean, std::sqrt(stddev)};
}

std::vector<int> distribute_normally(std::pair<double, double> p, int count, int n) {
    std::normal_distribution<double> distr(p.first, p.second);
    std::mt19937 engine(std::chrono::steady_clock::now().time_since_epoch().count());

    std::vector<int> norm_d(count, 0);
    for (int i = 0; i < n; ++i) {
        int ind = (int) distr(engine);
        check_boundaries_and_increment(norm_d, ind);
    }
    return norm_d;
}

int main() {
    // get parameters
    int n = 1000;
    double step, width;
    int count, hight;
    std::cout << "Enter step -> width -> count -> hight->:\n";
    std::cin >> step >> width >> count >> hight;

    // modulate board and print it out
    auto board = galton_board(step, hight, count, width, n);
    std::cout << "halton board\n";
    print_galton_board_horizontally(board);

    // find paramenters of distribution
    auto parameters = find_normal_distrib(board);
    std::cout << "mean = " << parameters.first << "; stddev = " << parameters.second << ";\n";

    // get normal distribution and compare the output
    auto norm_d = distribute_normally(parameters, count, n);
    std::cout << "normal distribution with the same parameters\n";
    print_galton_board_horizontally(norm_d);
}
#endif