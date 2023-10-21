#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape{
	protected:
		Point2D* vs;
	public:
		static int const N_VERTICES = 4;
		
		Rectangle(){
			vs = new Point2D[4];
			vs[0] = Point2D(-1 , 0.5);
			vs[1] = Point2D( 1 , 0.5);
			vs[2] = Point2D( 1 , -0.5);
			vs[3] = Point2D(-1 , -0.5);
		};

		~Rectangle(){
			delete[] vs;
		};

		Rectangle(std::string color, Point2D* vertices){
			if(check(vertices) == 0){
				throw std::invalid_argument ("No es un rectángulo");
			
			}
			else{
				vs = new Point2D[4];
                        	for(int i = 0 ; i < 3 ; i++){
					vs[i] = vertices[i];
					vs[i] = vertices[i];
				};
				this->color = color;
			};
		};

		Rectangle(const Rectangle &r){
			vs = r.vs;
			color = r.color;
			
		};

		Point2D get_vertex(int ind) const{
			if(ind > 3){
				throw std::out_of_range ("No existe ese vértice");
			}
			else{
				return vs[ind];
			};
		};

		Point2D operator[](int ind) const{
			if(ind > 3){
                                throw std::out_of_range ("No existe ese vértice");
                        }
                        else{
                                return vs[ind];
                        };
		};

		virtual void set_vertices(Point2D* vertices){
			if(check(vertices) == 0){
                                throw std::invalid_argument ("No es un rectángulo");
                        }
                        else{
                                for(int i = 0 ; i < 4 ; i++){
                                        vs[i] = vertices[i];
                                };
                        };
                };


		Rectangle& operator=(const Rectangle &r){
			vs = r.vs;
                        color = r.color;
			return *this;
			
		};

		friend std::ostream& operator<<(std::ostream &out, const Rectangle &r){
			for(int i = 0 ; i < 4 ; i++){
				out << r.vs[i];
			};
			return out << r.color;
		};


		double area() const{
			return Point2D::distance(vs[0],vs[1]) * Point2D::distance(vs[2],vs[3]);
		};

		double perimeter() const{
			return Point2D::distance(vs[0],vs[1]) * 2 +  Point2D::distance(vs[2],vs[3]) * 2;
                };

		void translate(double incX, double incY){
			for(int i = 0 ; i < 4 ; i++){
				vs[i].x += incX;
				vs[i].y += incY;
			};
		};

		virtual void print(){
			std::cout << *this << std::endl;
		};	



	private:
		static bool check(Point2D* vertices){
			if(Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[2] , vertices[3]) && Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[3] , vertices[0])){

				return 1;
			}
			else{
				return 0;
			};
		};

};



#endif
