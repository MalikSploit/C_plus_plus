//
// Created by malik on 12/3/2023.
//

#include <iostream>
using namespace std;

class Complex{
private:
    int real;
    int img;
public:
    explicit Complex(int real=0, int img=0){
        this->real = real;
        this->img = img;
    }

    Complex operator+(Complex x) const{
        Complex temp;
        temp.real = real + x.real;
        temp.img = img + x.img;

        return temp;
    }

    Complex operator-(Complex x) const{
        Complex temp;
        temp.real = real - x.real;
        temp.img = img - x.img;

        return temp;
    }

    friend Complex operator*(Complex c1, Complex c2);

    friend ostream & operator<<(ostream &o, Complex &c1);

    string toString() const{
        return to_string(real) + (img != 0 ? (img > 0 ? "+" : "-") + to_string(abs(img)) + "i" : "");
    }
};

Complex operator*(Complex c1, Complex c2){
    Complex temp;
    temp.img = c1.real * c2.img + c1.img * c2.real;
    temp.real = c1.real * c2.real - c1.img * c2.img;
    return temp;
}

ostream & operator<<(ostream &Output, Complex &c1){
    Output << c1.real << "+i" << c1.img;
    return Output;
}


int main()
{
    Complex c1(3, 4);
    Complex c2(5, 4);
    Complex c3;
    Complex c4;
    Complex c5;

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = "  << c2 << endl;

    cout << "c3 = "  << c3.toString() << endl;
    cout << "c4 = "  << c4.toString() << endl;
    cout << "c5 = "  << c5.toString() << endl;
    return 0;
}