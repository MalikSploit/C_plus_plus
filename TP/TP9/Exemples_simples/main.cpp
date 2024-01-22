//
// Created by root on 1/8/24.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <numeric>
#include <ctime>
#include <iterator>

class Rand_0_100{
public:
    Rand_0_100(){
        static bool seeded = false;
        if (!seeded){
            std::srand(std::time(nullptr));
            seeded = true;
        }
    }

    // Foncteur
    int operator()(){
        return std::rand() % 101;
    }
};

class Rand_int{
private:
    int a, b;
public:
    Rand_int(int low, int high) : a(low), b(high) {
        static bool seeded = false;
        if (!seeded){
            std::srand(std::time(nullptr));
            seeded = true;
        }
    }

    //Foncteur
    int operator()() const{
        return a + std::rand() % ((b+1) - a);
    }
};

class Fibonacci {
public:
    int operator()(int n) {
        if (n <= 1) return n;
        return operator()(n - 1) + operator()(n - 2);
    }
};

class SortFromSecondChar{
public:
    bool operator()(const std::string &str1, const std::string &str2){
        return str1.substr(1) < str2.substr(1);
    }
};

int main(){
    std::vector<int> vec;
    //Rand_0_100 rnd;
    //std::generate(vec.begin(), vec.end(), rnd);

    std::generate_n(std::back_inserter(vec), 50, Rand_0_100());

    double average = std::accumulate(vec.begin(), vec.end(), 0.0) / static_cast<double>(vec.size());
    auto minElement = *std::min_element(vec.begin(), vec.end());
    auto maxElement = *std::max_element(vec.begin(), vec.end());

    std::cout << "Average: " << average << "\n";
    std::cout << "Min: " << minElement << "\n";
    std::cout << "Max: " << maxElement << "\n";

    std::cout << std::endl;

    std::vector<int> vec2;
    //Rand_int rnd2(10, 20);
    //std::generate(vec.begin(), vec.end(), rnd);

    std::generate_n(std::back_inserter(vec2), 50, Rand_int(10, 20));

    double average2 = std::accumulate(vec2.begin(), vec2.end(), 0.0) / static_cast<double>(vec2.size());
    auto minElement2 = *std::min_element(vec2.begin(), vec2.end());
    auto maxElement2 = *std::max_element(vec2.begin(), vec2.end());

    std::cout << "Average2: " << average2 << "\n";
    std::cout << "Min2: " << minElement2 << "\n";
    std::cout << "Max2: " << maxElement2;

    std::cout << std::endl;
    std::cout << std::endl;

    Fibonacci fib;
    std::vector<int> fibNumbers(10);
    for (int i = 0; i < 10; ++i) {
        fibNumbers[i] = fib(i);
    }
    std::copy(fibNumbers.begin(), fibNumbers.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    std::vector<int> numbers(100);
    std::iota(numbers.begin(), numbers.end(), 1);

    std::shuffle(numbers.begin(), numbers.end(), std::mt19937(std::random_device()()));

    auto it = std::find(numbers.begin(), numbers.end(), 50);
    if (it != numbers.end()) {
        std::copy(it, numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    } else {
        std::cout << "50 introuvable" << std::endl;
    }
    return 0;
}