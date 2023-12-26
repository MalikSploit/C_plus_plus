//
// Created by malik on 12/26/2023.
//
#include <iostream>
#include <fstream>
#include <utility>

class Student{
private:
    std::string name;
    int roll;
    std::string branch;

public:
    explicit Student(std::string name="", int roll=0, std::string branch="") : name(std::move(name)), roll(roll), branch(std::move(branch)) {}

    const std::string &getName() const {
        return name;
    }

    int getRoll() const {
        return roll;
    }

    const std::string &getBranch() const {
        return branch;
    }
    friend std::ofstream & operator<<(std::ofstream &ofs, Student &s);
    friend std::ifstream  & operator>>(std::ifstream &ifs, Student &s);

    std::string toString() const{
        return getName() + " " + std::to_string(getRoll()) + " " + getBranch();
    }
};

std::ofstream & operator<<(std::ofstream &ofs, Student &s){
    ofs << s.getName() << std::endl;
    ofs << s.getRoll() << std::endl;
    ofs << s.getBranch() << std::endl;
    return ofs;
}

std::ifstream & operator>>(std::ifstream &ifs, Student &s){
    std::getline(ifs, s.name);
    ifs >> s.roll;
    ifs.ignore(); //To ignore the rest of the line which is : '\n'
    std::getline(ifs, s.branch);
    return ifs;
}


int main(){
    Student s1("Malik", 1, "CS");

    std::ofstream ofs("Student.txt", std::ios::trunc);
    ofs << s1;
    ofs.close();

    Student copy;
    std::ifstream studentFile("Student.txt");
    if (studentFile){
        studentFile >> copy;
        std::cout << copy.toString() << std::endl;
    }
}