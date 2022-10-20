#include <iostream>
#include <iterator>
#include <initializer_list>
#include "Prototype.h"

int main(){
    LinkedList<int> now = {22,21,66,7,89,44,44,44,1};
    //now.push_back(5);
    //now.push_back(5);
    //now.push_back(5);
    //now.push_back(66);
    //now.push_back(5);
    //now.push_back(5);
    //now.push_back(5);
    //now.push_front(99);
    //now.clear();
    // LinkedList<int>::Iterator it = now.begin();
    //now.insert(it, 99);
    //LinkedList<int> N = now;//= {3,3,0, 3,5,7,3,9,11,3,3,3,3,28, 30,3,3,3,3};
    //now = N;
    // now = std::move(N);
    //if (now < N) {
    //  std::cout << "A";
    //}
    // std::cout << now.size();
    //std::cout << now.empty();
   // LinkedList<int>::Iterator itr = N.begin();
    //++itr;
    //++itr;
    //++itr;
    //++itr;
    //N.erase(itr);
    //N.pop_back();
    //N.pop_front();
     //now.resize(1);
    //std::cout << N.size() << std::endl;
    //now.swap(N);
    //now.merge(N);
    //N.sort();
   // now.remove(1);
    //now.reverse();
    now.unique();
    //std::cout << now.back();
    //std::cout << now.front();
    //now.assign(5, 'a');
    std::cout << now;
}

