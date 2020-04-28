#include <iostream>
using namespace std;
#include "list.h"

int main()
{
     List <string> list;
    list.push_back("Python");
    list.push_back("C++");
    list.push_back("Ruby");
    list.push_front("Haskell");
    list.pop_back();
    list.pop_front();
    list.read();
    cout<<"Tamanho da lista: "<<list.size()<<endl;
    cout<<"Valor da frente da lista: "<< list.front()<<endl;
    cout<<"Valor de trás da fila: "<<list.back()<<endl<<endl;
    list.clear();
    return 0;
}

