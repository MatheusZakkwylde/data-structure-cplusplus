#include <iostream>
#include<queue>
using namespace std;

int main()
{
    queue <string> fila;
    cout<<"Adicionando valores na Fila : "<<endl;
    //push adiciona valores na fila
    fila.push("Matheus");
    fila.push("Maria");
    cout<<"Valores Adicionados!"<<endl<<endl;
    //Mostrando o ultimo valor da fila
    cout<<"Ultima pessoa na fila : "<<fila.back()<<endl<<endl;
   //enquanto tive pessoa na fila imprima
    while(!fila.empty()){
        //Mostrando pessoas
        cout<<"Pessoa na primeira fila: "<<fila.front()<<endl;
        //Retirand elementos da fila
        fila.pop();
    }
    return 0;
}

