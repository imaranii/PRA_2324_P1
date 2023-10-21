#include <iostream>
#include "Shape.h"
#include <cmath>


class Circle : public Shape {
	
	private:
		Point2D center;
    		double radius;

	public:
		Circle(){
			center.x = 0;
			center.y = 0;
			radius = 1;
			color = "red";
		};

		Circle(std::string color , Point2D center , double radius ){
			this->color= color;
			this->center = center;
			this->radius = radius;

		};

		Point2D get_center() const{
			return center;
		};

		void set_center(Point2D p){
			center = p;
		};

		double get_radius() const{
			return radius;
		};

		void set_radius(double r){
			radius = r;
		};

		friend std::ostream& operator<<(std::ostream &out, const Circle &c){
			out<<"[ Radio: "<< c.radius << " Coordenadas centro:  " << c.center << " Color:  " << c.color <<"]";
			return out;
		};

		double area() const override final {
			return M_PI * pow(radius,2);
		};

		double perimeter() const override final {
			return M_PI * radius;
		};

		void translate(double incX, double incY) override final {
			center.x += incX;
			center.y += incY;
		};

		void print() override final {
			std::cout<< *this  << std::endl;
		};

};
