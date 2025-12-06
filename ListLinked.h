#include <ostream>
#include <stdexcept>
#include <iostream>
#include "Node.h"
#include "List.h"
template<typename T>
class ListLinked :public List<T>{
	private:
		Node<T>* first;
		int n;
	public:
		//Metodos de la clase List
		T get(int pos) override{
			Node<T>* aux = first;
           		 if (pos < size() && pos >= 0) {
          	      int i=0;
              		  while (i < pos) {
               		     i++;
               		     aux = aux->next;
               		 }
               		 return aux->data;
           		 }
         		else{
          		      throw std::out_of_range("Posicion invalida en el intervalo [0,size()-1[ al ejectuar get()");
          		  }
		}
		int size() override {
		return n;
		}

		bool empty()override {
			if (n == 0) return true;
			else return false;
		}

		int search(T element) override {
			Node<T>* aux=first;
			int i=0;
        	        while(aux != nullptr){
			if (aux->data == element) return i;
			aux = aux->next;
			i++;
			}
			return -1;
          	 }

		void insert (int pos, T element) override {
			if (pos <= size() && pos >= 0) {
				if (pos == 0) {
					first = new Node<T>(element,first);
					n++;
					}
					else {
						Node<T>* prev = nullptr;
						Node<T>* aux = first;
						int i = 0;
						while (aux != nullptr && i < pos) {
						prev = aux;
								aux= aux->next;
								i++;
						}
						if (i == pos) {
						prev -> next = new Node<T> (element,aux);
								n++;
						}
					}
			}
			else throw std::out_of_range("Posicion inválida en el intervalo [0,size()[");
		}
		void append(T element) override {
		
			insert(n,element);
		}
		void prepend(T element) override {
			insert(0,element);
		}
		T remove(int pos) override {
		int cont = 0 ;
		T element;
        	Node<T>* aux = first;
       		Node<T>* prevAux = nullptr;
		if (pos < 0 || pos > n-1) {
			throw std::out_of_range("Posicion no valida en el intervalo [0,size-1[");
		}
       		 while (pos != cont) {
          	  	prevAux = aux;
            		aux = aux -> next;
           		 cont ++;
           	 }
        	    if (aux == first) {
       			element = first->data;
  	  		first = aux->next;
           	 }
           	 else {                               
		      element = aux->data;	 
          	      prevAux -> next = aux -> next;
         	   }
       			 delete aux;
      			  n--;
			  return element;
      		  }
		
		//Metodos de la clase ListLinked	
		ListLinked(){

			n = 0;
			first = nullptr;
		}
		
		~ListLinked(){

		while (first->next != nullptr) {
			Node<T>* aux=first->next;
			delete[] first;
			first = aux;
			}

		}

		T operator[](int pos){
			return get(pos);
		}
		friend std::ostream& operator<<(std::ostream &out, ListLinked<T> &list) {
		out<<"List --> [ ";
                        for (unsigned int i=0 ; i< list.n ; i++){
                                out<<list.get(i)<<" ";
                        }out<<"]\n";
                return out;
		}

};
