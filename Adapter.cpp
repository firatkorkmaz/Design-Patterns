/* Adapter Example */

#include <iostream>
using namespace std;


class Shape{
 public:
   virtual void draw() const = 0;
};

////////////////////////////////////////////////////////////////////////////////////////

class Circle : public Shape{
 protected:
    // Center Point Coordinates and Radius of A Circle
	int x_center, y_center;
	int radius;
 public:
   // Circle Constructor
	Circle(int x_cen, int y_cen, int r) : x_center(x_cen), y_center(y_cen), radius(r){ }

   // Function to Draw This Shape
	void draw() const{
        cout << "This is a Circle!" << endl;
        cout << "Center Point: " << "(" << x_center <<  ", " << y_center << ")" << endl;
        cout << "Radius: " << radius << endl << endl;
    }
};

////////////////////////////////////////////////////////////////////////////////////////

class Rectangle : public Shape{
 private:
   // Coordinates of the 4 Points of A Rectangle
   int x1, y1;
   int x2, y2;
   int x3, y3;
   int x4, y4;
 public:
   // Rectangle Constructor
   Rectangle(int x1_in, int y1_in, int x2_in, int y2_in, int x3_in, int y3_in, int x4_in, int y4_in) :
             x1(x1_in), y1(y1_in), x2(x2_in), y2(y2_in), x3(x3_in), y3(y3_in), x4(x4_in), y4(y4_in){ }

   // Function to Draw This Shape
   void draw() const{
        cout << "This is a Rectangle!" << endl;
        cout << "Corner Points: " << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3
                                        << ", " << y3 << "), (" << x4 << ", " << y4 << ")" << endl << endl;
    }
};

////////////////////////////////////////////////////////////////////////////////////////

// A New Class with A Different Interface
class TriangleX{
 private:
   // Coordinates of the 3 Points of A Triangle
   int x1, y1;
   int x2, y2;
   int x3, y3;
 public:
   // TriangleX Constructor
    TriangleX(int x1_in, int y1_in, int x2_in, int y2_in, int x3_in, int y3_in) :
              x1(x1_in), y1(y1_in), x2(x2_in), y2(y2_in), x3(x3_in), y3(y3_in){ }

   // Function to Draw This Shape
    void drawInfo() const{              // The Same Printer Function with A Different Name
        cout << "This is a Triangle!" << endl;
        cout << "Corner Points: " << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2
                                      << "), (" << x3 << ", " << y3 << ")" << endl << endl;
    }
};

//--------------------------------------------------------------------------------------

// Adapter for the New TriangleX Shape
class Triangle : public Shape{
  private:
	 TriangleX *newTriangle;        // Definition of A TriangleX Object

  public:
   // Triangle Constructor Creates the TriangleX Object
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
		 newTriangle = new TriangleX(x1, y1, x2, y2, x3, y3);
	 }

	 // Function to Draw This Shape
	 void draw() const{
        newTriangle->drawInfo();    // Calling the Printer Function of the Foreign Class
    }

	 ~Triangle(){
       delete newTriangle;          // Deletion of the TriangleX Object
    }
};

////////////////////////////////////////////////////////////////////////////////////////

// A Client Class That Uses the Shape Library
class Client{
	Shape *shape;			        // Shape Pointer Can Point to Different Shapes

  public:
    // Client Constructor
	Client(Shape *inShape) : shape(inShape){ };

	// Changing the Shape in Run-Time
	void setShape(Shape *inShape){
		shape = inShape;			// *shape will Point to A Different Shape Object
	}

	// Polymorphic show() Function
	void show() const{              // It is Unknown Which draw() Function...
		shape->draw();              // ...will Be Called at the Compile-Time
	}
};


int main(){

    Client client(nullptr);

    Circle* circle1 = new Circle(45, 35, 10);
    client.setShape(circle1);       // Circle Shape is Set for the Client
    client.show();

    Rectangle* rectangle1 = new Rectangle(30, 50, 30, 80, 120, 50, 120, 80);
    client.setShape(rectangle1);    // Rectangle Shape is Set for the Client
    client.show();

    Triangle* triangle1 = new Triangle(10, 15, 30, 40, 20, 25);
    client.setShape(triangle1);     // Triangle Shape is Set for the Client
    client.show();                  // Triangle Adapter Runs New TriangleX


cout << endl << "-------------" << endl;
system("pause");
return 0;
}
