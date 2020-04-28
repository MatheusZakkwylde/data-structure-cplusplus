#include <iostream>
#include<stack>
using namespace std;

int main()
{
    //criando pilha
    stack <string> pilha;
    //adicionando valores a pilha

    if(pilha.empty()){
        cout<<"Pilha vazia. Adicione valores a pilha"<<endl;
    }

    cout<<"Adicionando valores a pilha "<<endl;
    pilha.push("Maria");
    pilha.push("João");

    if(!pilha.empty()){
        cout<<"Valores adicionado a pilha"<<endl;
    }

    cout<<"Pessoa no topo da pilha : "<<pilha.top()<<endl;
    cout<<"Tamanho da pilha: "<<pilha.size()<<endl;
    cout<<"Removendo Pessoa da pilha"<<endl;
    pilha.pop();
    cout<<"Pessoa removida pilha"<<endl;

    return 0;
}

