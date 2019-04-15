#include <cstdlib>
#include <iostream> 
#define PI 3.14
using namespace std;

class Shape {
protected:
	float area;
public:
	Shape() { area = 0; }
	virtual float computeArea() = 0;
	void printArea()
	{
		cout << area << endl;
	}
};
class Quadrilateral : public Shape{
public:
	float height;
	float width;
	float top;
	float bottom;
	float long_edge;
	float short_edge;
};
class Rectangle : public Quadrilateral{
	// Add code here
public:
	Rectangle(float a, float b)
		{
			height = a;
			width = b;
		};
		float computeArea(){
			area = height * width;
			return area;
		}
};
class Trapezium : public Quadrilateral{ // Trapezium is Isosceles
	// Add code here
public:
	Trapezium(float a, float b, float c) {
		top = a;
		bottom = b;
		height = c;
	}
	float computeArea(){
		area = (top + bottom) * height / 2;
		return area;
	}
};
class Rhombus : public Quadrilateral{
	// Add code here
public:
	Rhombus(float a, float b){
		long_edge = a;
		short_edge = b;
	}
	float computeArea(){
		area = (long_edge * short_edge) / 2;
		return area;
	}
};
class Triangle : public Shape{
	// Add code here
public:
	float bottom;
	float height;
	Triangle(float a, float b) {
		bottom = a;
		height = b;
	}
	float computeArea(){
		area = (bottom * height) / 2;
		return area;
	}
};
class Circle : public Shape{
	// Add code here
public:
	float radius;
	Circle(float a) {
		radius = a;
	}
	float computeArea(){
		area = (radius * radius) * PI;
		return area;
	}
};
void calc(Shape &s) // Calculate the area of 's' and print it
{
	// Add code here
	s.computeArea();
	s.printArea();
}
// Main function for the program
int main()
{
	float a, b, c;
	Shape *shape;

	cin >> a >> b; // Enter the height and width of Rectangle
	Rectangle rec(a, b);

	cin >> a >> b >> c; // Enter the top, bottom and height of Trapezium
	Trapezium tre(a, b, c);

	cin >> a >> b; // Enter the long edge and short edge of Rhombus
	Rhombus rho(a, b);

	cin >> a >> b; // Enter the bottom and height of Triangle
	Triangle  tri(a, b);

	cin >> a; // Enter the radius of Circle
	Circle cir(a);

	shape = &rec;
	shape->computeArea();
	shape->printArea();

	shape = &tre;
	calc(*shape);

	calc(rho);

	shape = &tri;
	shape->computeArea();
	shape->printArea();

	shape = &cir;
	shape->computeArea();
	shape->printArea();
	system("pause");
	return 0;
}