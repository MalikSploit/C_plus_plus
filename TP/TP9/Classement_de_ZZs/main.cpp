//
// Created by root on 1/8/24.
//
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>

class ZZ {
private:
    std::string nom, prenom;
    double note;

public:
    ZZ(std::string nom, std::string prenom, double note) : nom(std::move(nom)), prenom(std::move(prenom)), note(note) {}

    [[nodiscard]] double getNote() const {
        return note;
    }

    /*bool operator<(const ZZ& other) const {
        return note < other.note;
    }*/

    bool operator<(const ZZ& other) const {
        return nom + prenom > other.nom + other.prenom;
    }

    friend std::ostream& operator<<(std::ostream& os, const ZZ& zz) {
        os << zz.nom << " " << zz.prenom << " : " << zz.note << "\n";
        return os;
    }
};

class CompareNote{
public:
    bool operator()(const ZZ& a, const ZZ& b) const {
        return a.getNote() < b.getNote();
    }
};


int main(){
    std::vector<ZZ> zz;

    zz.emplace_back("Makkes", "Malik", 14.6);
    zz.emplace_back("Bouterige", "Pierre", 15.4);
    zz.emplace_back("John", "Nobody", 16.0);

    /*auto compareNote = [](const ZZ& a, const ZZ& b) {
        return a.getNote() < b.getNote();
    };
    std::priority_queue<ZZ, std::vector<ZZ>, decltype(compareNote) < tri_note2(compareNote);*/

    // Priority queue for lexicographic order
    std::priority_queue<ZZ> tri;
    // Priority queue for reverse grade order
    std::priority_queue<ZZ, std::vector<ZZ>, CompareNote> tri_note;

    for (auto & it : zz){
        tri.push(it);
        tri_note.push(it);
    }

    while (!tri.empty()){
        std::cout << tri.top();
        tri.pop();
    }

    std::cout << std::endl;

    while (!tri_note.empty()){
        std::cout << tri_note.top();
        tri_note.pop();
    }

    std::cout << std::endl;

    // Using set for lexicographic order
    std::set<ZZ> zz_set(zz.begin(), zz.end());

    for (auto & it : zz_set){
        std::cout << it;
    }

    return 0;
}