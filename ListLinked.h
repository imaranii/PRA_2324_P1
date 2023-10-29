#ifndef LISTLINKED_H
#define LISTLINKED_H

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
			if(pos < 0 || pos >= n){
                                throw std::out_of_range("Fuera de rango");
                        }
                        else{
                                Node<T>* aux = first;
                                for(int i = 0 ; i != pos ; i++){
                                        aux = aux->next;
                                };
                                return aux->data;
                        };
                };



		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* aux =list.first;
			while(aux != nullptr){
				out << aux->data <<" " ;
				aux = aux->next;

			};
			return out;
		};
		
		void insert(int pos, T e) override final{
			if(pos < 0 || pos > n){
				throw std::out_of_range("Fuera de rango");
			}
			else{
				Node<T>* aux = first;
                        	Node<T>* preaux = nullptr;

				for(int i = 0 ; i != pos ; i++){ 
					preaux = aux;
					aux = aux-> next;
				}

				Node<T>* nuevo = new Node(e , aux );

				if(pos == 0){
					nuevo->next = first;
					first = nuevo;
				}
				else{
					preaux->next = nuevo;
					nuevo->next = aux;
				}

				n++;	
			};
		};
			

		void append(T e) override final{
			insert(n , e);
		};

		void prepend(T e) override final{
			insert(0 , e);
		};

		T remove(int pos) override final{
			if(pos < 0 || pos >= n){
                                throw std::out_of_range("Fuera de rango");
                        }
                        else{
                                Node<T>* aux = first;
                                Node<T>* preaux = nullptr;

                                for(int i = 0 ; i != pos ; i++){
                                        preaux = aux;
                                        aux = aux-> next;
                                }
				
				T valor = aux->data;
				n--;

                                if(pos == 0){
					first = aux->next;
					return valor;
				}
				else{
					preaux->next = aux->next;
					delete aux;
					return valor;
                        	};
                	};
		};
		T get(int pos) override final{
			if(pos < 0 || pos >= n){
                                throw std::out_of_range("Fuera de rango");
                        }
                        else{
				Node<T>* aux = first;
				for(int i = 0 ; i != pos ; i++){
					aux = aux->next;
				};
				return aux->data;
			};
		};

		int search(T e) override final{
			Node<T>*  aux = first;
                        for(int i = 0 ; i < n ; i++){
                                if(aux->data = e){
					return i;
				};
			};
				
			return -1;
				
                                        
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

#endif
