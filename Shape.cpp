#include "Shape.h"
#include <string>
#include "Point2D.h"


		Shape::Shape(){
			color =" red";
		};

		Shape::Shape(std::string color){
			if(color != "red" || color != "green" || color != "blue"){
		       		throw std::invalid_argument ("Color no aceptado");
			}
			else{
				this->color = color;

			};
		};	       
		

		std::string Shape::get_color() const{
			return color;
		};


		void Shape::set_color(std::string c){
			if(color != "red" && color != "green" && color != "blue"){
                                throw std::invalid_argument ("Color no aceptado");
                        }
                        else{
                                color = c;

                        };
                };
