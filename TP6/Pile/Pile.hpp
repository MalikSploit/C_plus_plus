#ifndef CPP6_PILE_HPP
#define CPP6_PILE_HPP

#include <iostream>
#include <fstream>

class Pile  {
private:
    int capacite;
    int *tab{};
    int topPile;
public :
    explicit Pile();
    explicit Pile(int cap);
    ~Pile();

    bool empty() const;
    void push(int val);
    void pop();
    int top() const;
    int size() const;

    class ExceptionPile:std::exception{
    private:
        std::string errorMessage;
    public:
        explicit ExceptionPile(std::string errMsg) noexcept;

        [[nodiscard]] const char *what() const noexcept override;
    };
};

#endif //CPP6_PILE_HPP
