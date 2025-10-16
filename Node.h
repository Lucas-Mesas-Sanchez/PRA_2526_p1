#include<ostream>
template<typename T>

class Node {
	public:
		//Atrib
		T data;
		Node<T>* next;
		//Metodos
		Node(T _data, Node<T>* _next = nullptr) {
			data = _data;
			next = _next;
		}
		friend std::ostream &operator<<(std::ostream& out, const Node<T> &node) {
			out << "Dato = "<< node.data<<"\n";
		return out;
		}

			
};
