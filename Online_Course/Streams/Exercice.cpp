//
// Created by malik on 12/26/2023.
//
#include <iostream>
#include <fstream>
#include <utility>
#include "vector"

class Item{
private:
    std::string Name;
    float Price{};
    int Quantity{};
public:
    Item(std::string name, float price, int quantity) : Name(std::move(name)), Price(price), Quantity(quantity) {}
    Item() = default;
    friend std::ifstream & operator>>(std::ifstream &ifs, Item &i);
    friend std::ofstream & operator<<(std::ofstream &ofs, Item &i);
    friend std::ostream & operator<<(std::ostream &os, Item &i);
};

std::ifstream & operator>>(std::ifstream &ifs, Item &i){
    ifs >> i.Name >> i.Price >> i.Quantity;
    return ifs;
}

std::ofstream & operator<<(std::ofstream &ofs, Item &i){
    ofs << i.Name << " " << i.Price << " " << i.Quantity << "\n";
    return ofs;
}

std::ostream & operator<<(std::ostream &os, Item &i){
    os << "Name: " << i.Name << "\nPrice: " << i.Price << "$" << "\nQuantity: " << i.Quantity;
    return os;
}


int main(){
    int n;
    std::string name;
    float price;
    int quantity;

    std::cout << "Enter number of Items:";
    std::cin >> n;

    std::vector<Item> list;

    for (int i = 0; i < n; i++){
        std::cout << "Enter " << i+1 << " Item name, price and quantity" << std::endl;
        std::cout << "Name :";
        std::cin >> name;
        std::cout << "Price :";
        std::cin >> price;
        std::cout << "Quantity :";
        std::cin >> quantity;
        list.emplace_back(name, price, quantity);
    }

    std::ofstream fos("Items.txt");
    for (int i = 0; i < n; i++){
        fos << list[i];
    }
    fos.close();

    Item items;
    std::ifstream fis("Items.txt");
    for (int i = 0; i < n; i++){
        fis >> items;
        std::cout << "Item " << i+1 << " " << items << std::endl;
    }
    fis.close();

    return 0;
}