#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class ZZ {
public:
    string nom, prenom;
    double note;

    ZZ(string nom, string prenom, double note) : nom(nom), prenom(prenom), note(note) {}

    bool operator<(const ZZ& other) const {
        return note < other.note;
    }

    friend ostream& operator<<(ostream& os, const ZZ& zz) {
        os << zz.nom << " " << zz.prenom << " : " << zz.note;
        return os;
    }
};

int main() {
    using vzz =  vector<ZZ>;
    vzz zz;

    zz.push_back(ZZ("Makkes", "Malik", 14.6));
    zz.push_back(ZZ("Bouterige", "Pierre", 15.5));

    priority_queue<ZZ> tri;

    for (auto& z : zz)
        tri.push(z);

    while (!tri.empty()) {
        cout << tri.top() << endl;
        tri.pop();
    }

    vector<ZZ*> pzz;
    pzz.push_back(new ZZ("Makkes", "Makkes", 14.6));
    pzz.push_back(new ZZ("Bouterige", "Pierre", 15.5));

    for (ZZ* ptr : pzz) {
        delete ptr;
    }
    pzz.clear();
}
