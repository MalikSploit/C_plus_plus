//
// Created by root on 12/21/23.
//
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

using mss = std::map<string, string>;

mss m;

const string& first(const pair<string,string>& p) { return p.first; }

string pairToString(const pair<string, string> &p){
    return p.first + ": " + p.second;
}

int main(int argc, char** argv) {
    /*m.insert(pair<string,string>("loic", "405042"));
    m.insert(make_pair("pierre", "405033"));
    m.insert(make_pair("SOS C++ 24/7", "407662"));
    m["secours"]  = "42";

    map<string, string> liste;

    map<string, string>::const_iterator it = liste.begin();

    while(it!=liste.end()) {
        cout << it->first  << " "
             << it->second << endl;
        ++it;
    }

    transform(liste.begin(), liste.end(),ostream_iterator<string>(cout, " "), first);
*/
    map<string, string> directory;
    map<string, string> inverseDirectory;

    ifstream file("directory.txt");
    string name, number;
    while (file >> name >> number) {
        directory[name] = number;
        inverseDirectory[number] = name;
    }

    if (argc == 1) {
        for_each(directory.begin(), directory.end(),
                 [](const pair<string, string>& p) { cout << pairToString(p) << endl; });
    } else {
        string searchKey = argv[1];
        auto it = directory.find(searchKey);
        if (it != directory.end()) {
            cout << pairToString(*it) << endl;
        } else {
            cout << "non trouvé" << endl;
        }
    }

    return 0;
}
