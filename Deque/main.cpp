#include <iostream>
#include"Deque.h"
using namespace std;

int main()
{
    Deque<int> deque;
    deque.push_front(10);
    deque.push_back(20);
    deque.push_front(30);
    deque.push_back(50);
    deque.pop_front();
    deque.pop_back();
    deque.pop_front();
    cout<<"Valor da frente do deque: "<<deque.front()<<endl;
    cout<<"Valor da trás do deque: "<<deque.back()<<endl;
    deque.clear();
    return 0;
}

