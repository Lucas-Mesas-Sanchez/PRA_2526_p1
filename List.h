#ifndef LIST_H
#define LIST_H

template<typename T>

class List {
	public:
	virtual	void insert(int pos, T element)=0;	//inserta element en la posición, si la posicion no es válida lanza out_of range
	virtual	void append(T element)=0;		//inserta element al final de la lista
	virtual	void prepend(T element)=0;		//inserta element al inicio de la lista
	virtual	T remove(int pos)=0;			//Elimina y devuelve el elemento de la posicion. Si falla out_of_range
	virtual	T get(int pos)=0;			//Devuelve el elemento de la posicion. Si falla out_of_range
	virtual	int search(T element)=0;		//Devuelve la posicion en la q se encuentra un elemento. Sino -1
	virtual	bool empty()=0;				// Bool de si esta vacia o no la lista
	virtual	int size()=0;				//Devuelve el tamaño de la lista
};


#endif
