#include <iostream>
#include <string.h>
using namespace std;

class Shape {
    public:
   virtual void draw() = 0;
};

class Rectangle: public Shape {

   public:
   void draw() {
      cout << "Inside Rectangle::draw() method." << endl;
   }
};

class Triangle: public Shape {

   public:
   void draw() {
      cout << "Inside Triangle::draw() method." << endl;
   }
};

class Circle: public Shape {

   public:
   void draw() {
      cout << "Inside Circle::draw() method." << endl;
   }
};

class ShapeFactory {
	
   //use getShape method to get object of type shape 
   public:
   Shape* getShape(string shapeType) {		
  	
      if(strcmp(shapeType.c_str(),"CIRCLE")) {
         return new Circle();
         
      } else if(strcmp(shapeType.c_str(),"TRIANGLE")) {
         return new Triangle();
         
      } else if(strcmp(shapeType.c_str(),"RECTANGLE")) {
         return new Rectangle();
      }
      return NULL;
   }
};


int main() {
      ShapeFactory* shapeFactory = new ShapeFactory();

      //get an object of Circle and call its draw method.
      Shape* shape1 = shapeFactory->getShape("CIRCLE");

      //call draw method of Circle
      shape1->draw();

      //get an object of Rectangle and call its draw method.
      Shape* shape2 = shapeFactory->getShape("RECTANGLE");

      //call draw method of Rectangle
      shape2->draw();

      //get an object of Square and call its draw method.
      Shape* shape3 = shapeFactory->getShape("SQUARE");

      //call draw method of circle
      shape3->draw();
   }


