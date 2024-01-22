#ifndef CPP6_PILE_HPP
#define CPP6_PILE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>

template<typename T>
class Pile {
private:
    int capacite;
    T *tab;
    int topPile;
public:
    Pile() : capacite(0), tab(nullptr), topPile(0){}

    explicit Pile(int cap) : capacite(cap), tab(new T[capacite]), topPile(0){
        if (cap <= 0) {
            throw ExceptionPile("Erreur: Capacité ne peut pas être négative");
        }
    }

    ~Pile() {
        delete[] tab;
    }

    bool empty() const {
        return topPile == 0;
    }

    void push(T val) {
        if (tab == nullptr) {
            throw ExceptionPile("Erreur: Tableau non initialisé");
        }
        if (topPile >= capacite) {
            throw ExceptionPile("Erreur: Pile Pleine");
        }
        tab[topPile++] = val;
    }

    void pop() {
        if (empty()) {
            throw ExceptionPile("Erreur: Pile vide");
        }
        --topPile;
    }

    T top() const {
        if (tab == nullptr) {
            throw ExceptionPile("Erreur: Tableau non initialisé");
        }
        if (empty()) {
            throw ExceptionPile("Erreur: Pile vide");
        }
        return tab[topPile - 1];
    }

    int size() const {
        return topPile;
    }

    class ExceptionPile : public std::exception {
    private:
        std::string errorMessage;
    public:
        explicit ExceptionPile(std::string errMsg) noexcept : errorMessage(std::move(errMsg)) {}

        const char *what() const noexcept override {
            return errorMessage.c_str();
        }
    };
};

#endif //CPP6_PILE_HPP
