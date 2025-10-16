#include "List.h"
#include <ostream>
#include<iostream>

#include <stdexcept>

bool NO_EN_INTERVALO(int pos, int size){
return (pos < 0 || pos > size);
}
template <typename T>

class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2; //Tamaño minimo del array. Inicializado a 2
		void resize(int new_size){
			T* new_arr = new T[new_size];
			for (unsigned int i=0; i < n ;i++){
				new_arr[i] = arr[i];
				}
			delete[] arr;
			arr = new_arr;
			max = new_size;
			}
	public:
		ListArray(){
			arr = new T[MINSIZE];
			max = 2;
			n = 0;
				
		}
		~ListArray(){
			delete[] arr;
		}
		void insert(int pos, T element) override { 
			if ( NO_EN_INTERVALO(pos,size())) { // Comprueba si la posicion es válida
				
				throw std::out_of_range("Posicion no valida al isnertar  en el intervalo [0,size()[");
			}
			else {
				if (n >=  max) //Si no hay espacio suficiente reescala sino no hace nada
				{
					resize(max+1);
				}
				for (unsigned int i = n; i > pos; i-- ) { //Recorre el vector añadiendo un espacio en pos
					arr[i] = arr[i-1];
				}
				arr[pos] = element; // rellena el espacio con el elemento
				n++; 
				
			}

		}

		void append(T element) override { // insert en la úlima posicion del vector
			insert(n,element);
		}

		void prepend(T element) override { // insert en la primera posicion del vector
			insert(0,element);
		}

		T remove(int pos) override {
			if(NO_EN_INTERVALO(pos,size()-1)){
			throw std::out_of_range("Posicion no valida al eliminar la pos en el intervalo [0,size()]");
			}
			else {
				T aux = arr[pos];
				for (unsigned int i=pos;i<size()-1;i++){
					arr[i] = arr[i+1];
				}
				n--;
				return aux;
			}
		}

		int search(T element) override{
		
			for(unsigned int i=0; i<size();i++) {
				if (arr[i] == element) return i;
			}
			return -1;
		}
		bool empty() override {
		if (n == 0)
			return true;
		else
			return false;
		}

		T get(int pos) override {
			if (NO_EN_INTERVALO(pos,size()-1)) {
				throw std::out_of_range("Posicion no valida al leer  en el intervalo [0,size()[");
			}
			else
			{
				return arr[pos];
			}
			
		}
		int size() override{
			return n;
		
		}
		T operator[](int pos) {
			return get(pos);
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T>&list) {
			out<<"List --> [ ";
			for (unsigned int i=0 ; i< list.n ; i++){
				out<<list.arr[i]<<" ";
			}out<<"]\n";
		return out;
		}

};
