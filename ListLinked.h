#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>

class ListLinked : public List<T> {

	private:
		Node<T>* first;
		int n;
	
	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			Node<T>* aux  = first;
			while(first != nullptr){
				first = first->next;
				delete aux;
				aux = first;
			};
		};

		T operator[](int pos){
			Node<T>* punt = first;
			for(int i = 0; i<=pos; i++){
				if(i == pos){
					return punt->data;
				}
			punt = punt->next;
			}
		};


		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* aux =list.first;
			while(aux != nullptr){
				out << aux->data <<" ";
				aux = aux->next;

			};
			return out;
		};
		
		void insert(int pos, T e) override final{
			Node<T>*  aux = first , preaux = nullptr;
			for(int i = 0 ; i <= pos ; i++){
				if(i == n){
					throw std::out_of_range("Fuera de rango");
				};
				if(i==pos){
					Node<T>* nuevo = new Node(e,aux->next);
					preaux->next = nuevo;
					n++;
					break;
				};

				preaux = aux;
				aux = aux->next;
			};
		};

		void append(T e) override final{
			insert(n-1 , e);
		};

		void prepend(T e) override final{
			insert(0 , e);
		};

		T remove(int pos) override final{
			Node<T>*  aux = first , preaux = nullptr;
        	        for(int i = 0 ; i <= pos ; i++){
                		if(i == n){
                        		throw std::out_of_range("Fuera de rango");
                                };
                               	if(i==pos){	
					preaux->next = aux->next;
					delete aux;
					n--;
					break;
                        	};

                              	preaux = aux;
                                aux = aux->next;
                        };
                };

		T get(int pos) override final{
			Node<T>*  aux = first , preaux = nullptr;
                        for(int i = 0 ; i <= pos ; i++){
                                if(i == n){
                                        throw std::out_of_range("Fuera de rango");
                                };
                                if(i==pos){
                                        return aux->data;
					break;
                                };

                                preaux = aux;
                                aux = aux->next;
                        };
                };

		int search(T e) override final{
			Node<T>*  aux = first;
                        for(int i = 0 ; i < n ; i++){
                                if(aux->data = e){
					return i;
				};
				if(i == n-1){
					return -1;
				};
                                        
                        };
                };

		bool empty() override final{
			if(n == 0){
				return 1;
			}
			else{
				return 0;
			};
		};

		int size() override final{
			return n;	
		};
};






