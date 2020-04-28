#include <iostream>
#include"Pilha.h"
using namespace std;

int main()
{
   Stackseq <int>pilha;
   pilha.push(10);
   pilha.push(20);
   pilha.clear();
   pilha.push(30);
   pilha.push(40);
   pilha.pop();
   pilha.push(50);
   pilha.push(60);
   pilha.clear();
   cout<<"Valor do topo: "<<pilha.top()<<endl;
   cout<<"Tamanho da pilha: "<<pilha.size()<<endl;
    return 0;
}

