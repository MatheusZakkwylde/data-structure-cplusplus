#ifndef DEQUE_H
#define DEQUE_H
#include<iostream>
/**
 *Deque adiciona na frente e trás, e remove tanto na frente como atrás
 */
template<class T>

class No {

private:
    T Object;
    No*next;
public:

    No(T object){
        this->Object = object;
        this->next = NULL;
    }

    T getObject(){
        return this->Object;
    }

    void setNext(No*next){
           this->next=next;
    }

    No* getNext(){
        return this->next;
    }
};

template<class T>

class Deque{

private:
    No<T>*head;
    No<T>*tail;
public:
    Deque(){
        this->head= NULL;
        this->tail = NULL;
    }

    ~Deque(){
        delete this->head;
        delete this->tail;
    }

    void push_front(T object){//adicionado valor pela frente

        No<T> *new_Node = new No<T>(object);
        new_Node->setNext(this->head);
        this->head = new_Node;

        if(this->head->getNext() == NULL){
            this->tail = this->head;
        }
    }

    void push_back(T object) {//adicionando valor por trás
        No<T>* new_No = new No<T>(object);

        if (empty()) {
            this->head = new_No;
            this->tail= new_No;
        } else {
            this->tail->setNext(new_No);//Topo aponta para o ultimo elemento, então aparte de topo setamos o elemento no topo pelo método setNext
            this->tail = new_No; //Topo não aponta mais para o elemento anterior, agora aponta para o novo valor que é o topo agora.
        }
    }

    void pop_front(){//removendo pela frente

     No<T>* new_Head = this->head;

     if(!empty()){
        this->head = head->getNext();
        delete new_Head;
     }
    }

    void pop_back() {//Pop desempilhar
        if (!empty()) {

             if(this->head->getNext() == NULL){//se cabeça o ponteiro proximo for null cabeca que aponta para um endereço recebe null

                 No<T> *new_Head = this->head;
                 this->head = NULL;
                 this->tail = NULL;
                 delete new_Head;

             }else if(this->head->getNext()->getNext() == NULL){//se for dois

                 No<T> *new_Head = this->head->getNext();
                 this->head->setNext(NULL);
                 this->tail = this->head;
                 delete new_Head;


             }else {

                 No<T>*new_head = this->head; //Nova cabeça aponta para a cabeça
                 No<T>*new_head_next = this->head->getNext();//Nova_cabeça_proximo aponta para cabeça_proximo
                 No<T>*chain = this->head->getNext()->getNext();//Corrente aponta para cabelça_proximo_proximo

                while(chain){
                    No<T> *aux = new_head_next; // aux aponta para cabeça_proximo
                    new_head_next = chain;//cabeça_proximo aponta para cabeça_proximo_proximo
                    new_head = aux; //cabeça aponta para cabeça_proximo
                    chain = chain->getNext();//chain corrente aponta para o proximo de chain
                }

                delete new_head->getNext(); //deleta o proximo da cabeça que será o ultimo elemento da verifiação
                new_head->setNext(NULL); //evolta o ultimo para null
                this->tail = new_head;//atualizando cauda
             }
           }
    }

    bool empty() {
        return this->head == NULL;
    }

    T front(){
        if(this->head == NULL){
            return 0;
        }
          return this->head->getObject();
    }

    T back(){
        if(this->head == NULL){
            return 0;
        }
          return this->tail->getObject();
    }

    void clear(){
       No<T> *new_Head = this->head;
       this->head = NULL;
       this->tail= NULL;

       while(new_Head !=NULL){
          No<T>*new_next = new_Head;
          new_Head = new_Head->getNext();
          delete new_next;
       }
    }
};
#endif // DEQUE_H
