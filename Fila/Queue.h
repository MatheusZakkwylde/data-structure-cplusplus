#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
/**
 * Fila
 * O conceito de fila é sempre adicionar valor no final e remover no incio..
 */
template<class T>
class No{

private:
    T object;
    No* next;
public:

    No(T object){
        this->object = object;
        this->next = NULL;
    }

    void setNext(No* next){
        this->next= next;
    }

    No* getNext(){
        return this->next;
    }

    T getObject(){
        return this->object;
    }
};

template<class T>

class Queue{

private:
    No<T>*head;
    No<T>*tail;

public:
    Queue(){
        this->head= NULL;
        this->tail= NULL;
    }

    ~Queue(){
       delete this->head;
       delete this->tail;
    }

    bool empty(){
       return this->head == NULL;
    }

    int size(){

        No<T> *new_Head = this->head;
        int cont=0;

        while(new_Head != NULL){
            new_Head = new_Head->getNext();
            cont++;
        }
        return cont;
    }

    T front(){
      return this->head->getObject();
    }

    T back(){
      return this->tail->getObject();
    }

    void push(T object){

      No<T> *new_No = new No<T> (object);

      if(empty()){
          this->head = new_No;
          this->tail = new_No;
      }else{
       this->tail->setNext(new_No);
       this->tail = new_No;
      }
    }

    void pop(){

     No<T>* new_Head = this->head;

     if(!empty()){
        this->head = head->getNext();
        delete new_Head;
     }
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
#endif // QUEUE_H
