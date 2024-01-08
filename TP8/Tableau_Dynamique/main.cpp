//
// Created by root on 12/21/23.
//

#include <algorithm>
#include <vector>
#include <iostream>

int main (int, char **) {
    std::vector<int> v;
    int input;

    while (std::cin >> input)
        v.push_back (input);

    std::sort(v.begin(), v.end());

    for (int & e : v){
        std::cout << e << std::endl;
    }
    return 0;
}