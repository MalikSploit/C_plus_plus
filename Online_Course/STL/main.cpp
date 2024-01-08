//
// Created by malik on 12/26/2023.
//

#include <iostream>
#include <list>
#include <map>

int main(){
    //vector : push_back(); pop_back(); insert(); remove(); size(); empty()
    //list : push_back(); pop_back(); push_front(); pop_front(); insert(); remove(); size(); empty(); front(); back()
    //forward_list : push_back(); pop_back(); push_front(); pop_front(); insert(); remove(); size(); empty(); front(); back()
    //deque : push_back(); pop_back(); push_front(); pop_front(); insert(); remove(); size(); empty(); front(); back()
    //priority_queue : push(); pop(); empty(); size()
    //stack : push(); pop(); empty(); size()
    //set : unique : insert(); size(); empty(); erase(iterator position); clear()
    //multiset : not unique
    //map : <key; value> pair, example: 1 "John"
    //multimap :

    //Vector example :
    //std::vector<int> v(size);
//    std::vector<int> v = {10, 20, 40, 44};
//    v.push_back(50);
//    v.push_back(70);
//    for (int x : v){
//        std::cout << x << " ";
//    }
//
//    std::cout << std::endl;
//
//    std::vector<int>::iterator itr;
//    for (itr = v.begin(); itr != v.end(); itr++){
//        std::cout << *itr << " ";
//    }

    //List example :
    std::list<int> l = {10, 20, 40, 44};
    l.push_back(50);
    l.push_back(70);
    std::cout << "Using for each loop : " << std::endl;
    for (int x : l){
        std::cout << x << " ";
    }

    std::cout << std::endl << "Using iterator : " << std::endl;
    std::list<int>::iterator itr;
    for (itr = l.begin(); itr != l.end(); itr++){
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    //map example :
    std::map<int, std::string> m;
    m.insert(std::pair<int, std::string>(1, "Malik"));
    m.insert(std::pair<int, std::string>(2, "Najet"));
    m.insert(std::pair<int, std::string>(3, "Kamel"));

    std::map<int, std::string>::iterator itr2;
    for(itr2 = m.begin(); itr2 != m.end(); itr2++){
        std::cout << itr2->first << " " << itr2->second << std::endl;
    }

    std::map<int, std::string>::iterator itr3;
    itr3 = m.find(2);
    std::cout << "Value found is : " <<  itr3->first << " " << itr3-> second << std::endl;
    return 0;
}