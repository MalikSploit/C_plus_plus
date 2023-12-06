//
// Created by root on 12/6/23.
//

#include "../TP2/Bavarde.hpp"

class Couple{
private:
    Bavarde bavarde1;
    Bavarde bavarde2;
    Bavarde bavarde3;
public:
    Couple(int val1, int val2, int val3) : bavarde1(val1), bavarde2(val2), bavarde3(val3){}
};

int main()
{
    Couple couple(1,2,3);
    return 0;
}