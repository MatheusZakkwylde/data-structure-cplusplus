#include <iostream>
#include"Queue.h"
using namespace std;

int main()
{
    Queue<int> fila;
    fila.push(10);
    fila.push(20);
    fila.push(30);
    fila.push(40);
    fila.pop();
    fila.pop();
    cout<<"Tamanho da fila: "<<fila.size()<<endl;
    cout<<"Frente: "<<fila.front()<<endl;
    cout<<"Trás: "<<fila.back()<<endl;
    fila.clear();
    return 0;
}

