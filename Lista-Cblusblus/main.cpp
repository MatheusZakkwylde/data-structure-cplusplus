#include <iostream>
#include<list>

using namespace std;

int main()
{
    list<int> lista;

    cout<<"Adicionando elementos pela frente da lista"<<endl;
    for(int i=0;i<10;i++){
        lista.push_front(i);
    }
    cout<<"Valores adicionados"<<endl<<endl;

    cout<<"Mostrando valores pela frente da lista"<<endl;

    for(int j=0;j<10;j++){
        cout<<lista.front()<<endl;
        lista.pop_front();
    }

    cout<<"Adicionando elementos por trás da lista"<<endl;
    for(int p=0;p<10;p++){
        lista.push_back(p);
    }
    cout<<"Valores adicionados"<<endl<<endl;

    cout<<"Mostrando valores por trás da lista"<<endl;

    for(int k=0;k<10;k++){
        cout<<lista.back()<<endl;
        lista.pop_back();
    }


    return 0;
}

