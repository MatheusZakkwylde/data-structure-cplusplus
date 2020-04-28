#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

template<class T>

class Node{

private:

    T object; //Qualquer objeto do template
    Node *next; //Aponta sempre para o proximo Node

public:
    /**
     * @brief Node - Construtor do Node
     * @param objet - objeto primitivo ou não
     * Como regra de Lista Linear o proximo ponteiro aponta para NULL.
     */
    Node(T object){
      this->object = object;
      this->next = NULL;
    }

    /**
     * @brief setNext - Método para seta o proximo Node a ser
     * criado fazendo que o Node anterior não aponte
     * mais para null e sim para o Node criado e o node criado aponte para NULL.
     * @param next - Recebe como parametro um novo Node.
     */

    void setNext(Node* next){
        this->next = next;
    }

    Node* getNext(){
        return this->next;
    }

    T getObject(){
        return this->object;
    }
};

template<class T>

class List{

private:
    Node<T> *head;
    Node<T> *tail;

public:

      List() {
          this->head = NULL;
          this->tail = NULL;
      }

      /**
       * @brief ~List - desconstrutor da lista. Quando
       * a operação da lista acabar desaloca memoria da cabeca da lista
       */
      virtual~List(){
          delete this->head;
          delete this->tail;
      }

      /**
       * @brief empty - Método de verificação de lista vazia
       * @return - Se head for igual a NULL vazia retorna true, se não false.
       */
      bool empty(){
          return (this->head == NULL);
      }

      /**
       * @brief push_front - Método de adiciona valor pela frente da lista
       * Para isso temos como função o estilo suap método de troca
       * um novo Node é criado, setamos o proximo  Node dele com a cabeca sendo o primeiro valor da lista
       * e a cabeca recebe o novo Node com o valor de cabeca anterior sendo o proximo valor do node
       * @param number
       */
      void push_front(T object){

          Node<T> *new_Node = new Node<T>(object);
          new_Node->setNext(this->head);
          this->head = new_Node;
      }

      void push_back(T object){
          Node<T>  *new_Node = new Node<T>(object);

          if(empty()){
              this->head = new_Node;
              this->tail = new_Node;
          }else{
              this->tail->setNext(new_Node);
              this->tail = new_Node;
          }
      }

      void pop_back() {//Pop desempilhar
          if (!empty()) {

               if(this->head->getNext() == NULL){//se cabeça o ponteiro proximo for null cabeca que aponta para um endereço recebe null

                   Node<T> *new_Head = this->head;
                   this->head = NULL;
                   this->tail = NULL;
                   delete new_Head;

               }else if(this->head->getNext()->getNext() == NULL){//se for dois

                   Node<T> *new_Head = this->head->getNext();
                   this->head->setNext(NULL);
                   this->tail = this->head;
                   delete new_Head;
               }else {

                   Node<T>*new_head = this->head; //Nova cabeça aponta para a cabeça
                   Node<T>*new_head_next = this->head->getNext();//Nova_cabeça_proximo aponta para cabeça_proximo
                   Node<T>*chain = this->head->getNext()->getNext();//Corrente aponta para cabelça_proximo_proximo

                  while(chain){
                      Node<T> *aux = new_head_next; // aux aponta para cabeça_proximo
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

      void pop_front(){

       Node<T>* new_Head = this->head;

       if(!empty()){
          this->head = head->getNext();
          delete new_Head;
       }
      }


      /**
       * @brief size - pegar o tamanho da lista
       * @return - se vazia retorna 0 se não retorna o tamanho
       */

      int size(){
          if(empty()){
              return 0;
          }else{
              Node<T> *new_Head = this->head;
              int length = 0;

              do{
                  new_Head = new_Head->getNext();
                  length++;
              }while(new_Head);//enquanto não for NULL

              return length;
          }
      }


      bool exist(T object){
          Node<T> *new_Head = this->head;

          while(new_Head){
            if(new_Head->getObject() == object){
                return true;
            }
              new_Head = new_Head->getNext();
          }
          return false;
      }

      void read(){
          //recebendo a cabeca da lista
          Node<T> *new_Head = this->head;
          if(empty()){
              cout<<"A lista se encontra vazia"<<endl;
          }else{
              //Mostrando valor do no
              while (new_Head) {
                  cout<<new_Head->getObject()<<endl;
                  //c recebe o proximo no que foi setado nele mesmo
                  new_Head =  new_Head->getNext();
              }
              cout<<endl;
          }
      }

      void clear(){
         Node<T> *new_Head = this->head;
         this->head = NULL;
         this->tail= NULL;

         while(new_Head !=NULL){
            Node<T>*new_next = new_Head;
            new_Head = new_Head->getNext();
            delete new_next;
         }
      }

      T front(){
        return this->head->getObject();
      }

      T back(){
        return this->tail->getObject();
      }
};
#endif // LIST_H
