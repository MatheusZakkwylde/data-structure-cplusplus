#ifndef PILHA_H
#define PILHA_H
#include<iostream>

template<class T>

/**
 * @brief Classe de objeto tipo No
 */
class No {

private:
    T object; //Objeto de qualquer tipo
    No* next; //Objeto ponteiro do tipo No

public:
    No(T object){
        this->object = object;
        this->next = NULL; //O proximo sempre aponta para NULL
    }

    void setNext(No* next){
        this->next = next;
    }

    No* getNext(){
        return this->next;
    }

    T getObject(){
        return this->object;
    }
};

template<class T>
//Classe representa a pilha
class Stackseq{

private:
    No<T> *head; //cabeça
    No<T> *top_P;//topo
public:

    Stackseq(){
       this->head = NULL;
       this->top_P = NULL;
    }

    ~Stackseq(){
        delete this->head;
        delete this->top_P;
    }

    bool empty() {
        return this->head == NULL;
    }

    void push(T object) {// push- empilhar
        No<T>* new_No = new No<T>(object);

        if (empty()) {
            this->head = new_No;
            this->top_P= new_No;
        } else {
            this->top_P->setNext(new_No);//Topo aponta para o ultimo elemento, então aparte de topo setamos o elemento no topo pelo método setNext
            this->top_P = new_No; //Topo não aponta mais para o elemento anterior, agora aponta para o novo valor que é o topo agora.
        }
    }

    void pop() {//Pop desempilhar
        if (!empty()) {

             if(this->head->getNext() == NULL){//se cabeça o ponteiro proximo for null cabeca que aponta para um endereço recebe null

                 No<T> *new_Head = this->head;
                 this->head = NULL;
                 this->top_P = NULL;
                 delete new_Head;

             }else if(this->head->getNext()->getNext() == NULL){//se for dois

                 No<T> *new_Head = this->head->getNext();
                 this->head->setNext(NULL);
                 this->top_P = this->head;
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
                this->top_P = new_head;//atualizando cauda
             }
           }
    }

    T top(){
        if(this->top_P == NULL){
            return 0;
        }
        return this->top_P->getObject();
    }

    int size(){
       int cont = 0;

        if(empty()){
            return 0;
        }else{
            No<T>* chain = this->head; //Chain (Corrente) No corrente. No que pega da cabeça da pilha e percorrera toda pilha

            do{
              chain = chain->getNext(); //chain recebe o proximo dele até que o proximo seja null
              cont++;
            }while(chain != NULL);
        }
        return cont;
    }

    void clear(){
       No<T> *new_Head = this->head;
       this->head = NULL;
       this->top_P= NULL;

       while(new_Head !=NULL){
          No<T>*new_next = new_Head;
          new_Head = new_Head->getNext();
          delete new_next;
       }
    }
};
#endif // PILHA_H
