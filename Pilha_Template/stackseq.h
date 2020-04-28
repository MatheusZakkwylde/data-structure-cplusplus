#ifndef STACKSEQ_H
#define STACKSEQ_H

template<class T>

class Stackseq{

private:
    T * pilha;
    int length;
    int top_P;

public:

    Stackseq(int length){
       this->pilha = new T [length];
       this->length = length -1;
       this->top_P = -1;
    }

    ~Stackseq(){
        delete [] pilha;
    }

    bool full() {//Se topo for igual ao tamanho do vetor me retorne true pilha cheia;
        return this->top_P == this->length - 1;
    }

    bool empty() {//se topo for igual a -1 me retorna true pilha vazia, se não false;
        return this->top_P == -1;
    }

    bool push(T value) {// push- empilhar

        if (full()) {
            return false;
        } else {
            this->pilha [++top_P] = value;
            return true;
        }
    }

    bool pop() {//Pop desempilhar
        if (empty()) {
            return 0;
        } else {
            this->pilha[top_P] = 0;
            // e diminuir um indice
            this->top_P--;
        }
        return true;
    }

    T top(){
        return this->pilha[top_P];
    }

    int size(){
        return this->top_P+1;
    }
};

#endif // STACKSEQ_H

