#ifndef DRAWING_H
#define DRAWING_H

#include <list>
#include "Shape.h"
#include "Point2D.h"
#include "Rectangle.h"
#include "Square.h"

class Drawing : public Square {
	private:
		std::list<Shape*>* shapes;
	
	public:
		 Drawing(){
			shapes = new std::list<Shape*>;
		 };

		~Drawing(){
			delete shapes;	
		};

		void add_front(Shape* shape){
			shapes->emplace_front(shape);
		};

		void add_back(Shape* shape){
			shapes->emplace_back(shape);
                };

		void print_all(){
			for(const Shape* figura : *shapes){
				if(figura != nullptr){
				this->print();
				};
			};
		};
		
		double get_area_all_circles(){
			double total = 0 ;
			for(const Shape* circulo : *shapes){
                               total += circulo->area();
                        };

			return total;
		};
		void move_squares(double incX, double incY){
			for(const Shape* cuadrado : *shapes){
                                this->translate(incX , incY);
                        };
                };
};

#endif
