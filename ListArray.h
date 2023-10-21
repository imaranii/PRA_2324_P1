#include <ostream>
#include "List.h"
#include <exception>

template <typename T>
class ListArray : public List<T>{

	private:
		T* arr;
		int max;
		int n;
		static const int MINISIZE = 2;
		
		void resize(int new_size){
			int r;
			T* nuevo = new T[new_size];

			for(int i = 0; i < new_size; i++){
				nuevo[i] = arr[i];
			};
			delete[] arr;
			arr = nuevo;
			max = new_size;
		};

	public:
		ListArray(){
			max = MINISIZE;
			n = 0;
			arr = new T[MINISIZE];
		};
	
		~ListArray(){
			delete[] arr;
		};

	
		T operator[](int pos){
                        if(pos>n || pos<0){
                                throw std::out_of_range ("Fuera de rango");
                        }
                        else{
                                return arr[pos];
                        }

                };


		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    			for (int i = 0; i < list.n; i++) {
        			out << list.arr[i] << " ";
    			}
    			return out << std::endl;
			};

			

		
		void insert(int pos, T e) override final{
			T* nuevo = new T[max+1];
			if(pos>n || pos<0){
                                throw std::out_of_range ("Fuera de rango");
                        }
                        else{

                        	for(int i = 0, a = 0 ; i <= n; i++ , a++){
                                	if(pos != i){
						nuevo[i] = arr[a];
					}
					else{
						nuevo[i] = e;
						a--;
					};
                        	};
				n++;
                        	delete[] arr;
                        	arr = nuevo;
                        	max++;
			}
		};


		void append(T e) override final{
			insert(n , e);
			
		};


		void prepend(T e) override final{
			insert(0 , e);
		};


		T remove(int pos) override final{
		
			if(pos>n-1 || pos<0){
                                throw std::out_of_range ("Fuera de rango");
                        }
                        else{
				T eliminado;
				eliminado = arr[pos];
				for(int i=pos ; i< n ; i++){
					arr[i]=arr[i+1];
					
                        };
				arr[n-1] = 0;		
				n--;
				return eliminado;
			};
			
                };

		
		T get(int pos) override final{
			if(pos>n || pos<0){
                                throw std::out_of_range ("Fuera de rango");
                        }
                        else{
                                return arr[pos];
                        }
		};


		int search(T e) override final{
			for(int i = 0 ; i < n ; i++){
				if(arr[i] == e){
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
