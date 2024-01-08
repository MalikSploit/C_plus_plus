//
// Created by malik on 12/28/2023.
//

class Test{
private:
    int x = 10;
    int y = 13;
public:
    Test(int a, int b){
        x = a;
        y = b;
    }
    Test():Test(1,1){}
};