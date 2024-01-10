#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
class Stats {
    vector<T> data;
    T sum;
    double moy;
    double ecart;

public:
    Stats():data(10), sum(0), moy(.0), ecart(0.0) {}

    void push_back(const T& t) { data.push_back(t); }

    void compute() {
        sum = T();
        for (typename vector<T>::const_iterator it = data.begin(); it != data.end(); ++it) {
            sum += *it;
        }
        moy = static_cast<double>(sum) / data.size();

        double variance = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            variance += pow(static_cast<double>(*it) - moy, 2);
        }
        ecart = sqrt(variance / data.size());
    }

    void display(ostream& o = cout) const {
        o << "Sum: " << sum << "\n";
        o << "Mean: " << moy << "\n";
        o << "Ecart: " << ecart << "\n";
    }
};

int main(int, char**) {
    Stats<int> is;

    is.push_back(3);
    is.push_back(4);
    is.push_back(2);
    is.compute();
    is.display();

    return 0;
}
