#include <ostream>

template <typename T>
class Node {
	public:
		Node(T data, Node<T>* next = nullptr);
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << node->data;
			return out;
		};
};
