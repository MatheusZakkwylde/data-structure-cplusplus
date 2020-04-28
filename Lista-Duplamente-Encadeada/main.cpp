#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List <int> list;

    if(list.empty()){
        cout<<"A lista se encontra vazia"<<endl;
    }

    cout<<"Tamanho da lista atual: "<<list.size()<<endl;

    if(list.push_front(1)){
        cout<<"Lista Adicionado pela frente com sucesso!"<<endl;
     }

    if(list.push_front(2)){
        cout<<"Lista Adicionado pela frente com sucesso!"<<endl;
     }


    cout<<"Tamanho da lista atual: "<<list.size()<<endl;

    cout<<"Valores da lista pela frente: "<<endl;
    list.readFront();

    cout<<"Valores da lista por trás: "<<endl;
    list.readBack();

    cout<<"Verificando valor existente na lista"<<endl;

    if(list.exist(4)){
        cout<<"O valor existe na lista"<<endl;
    }else{
        cout<<"O valor não existe na lista"<<endl;
    }

    if(list.push_back(3)){
        cout<<"Lista Adicionado por trás com sucesso!"<<endl;
     }

    if(list.push_back(4)){
        cout<<"Lista Adicionado por trásfrente com sucesso!"<<endl;
     }

    cout<<"Valores da lista por trás: "<<endl;
    list.readBack();

    if(list.pop_back()){
        cout<<"Valor retirado por trás com sucesso!"<<endl;
    }

    cout<<"Valores da lista por trás: "<<endl;
    list.readBack();

    if(list.pop_front()){
        cout<<"Valor retirado pela frente com sucesso!"<<endl;
    }

    cout<<"Valores da lista por trás: "<<endl;
    list.readBack();

    return 0;
}

