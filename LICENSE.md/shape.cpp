#include <iostream>
#include <string>

using namespace std;

class Shape
{
public: 
	Shape();
	virtual ~Shape();
	void message();
};
Shape::Shape()
{
	cout << "Shape constructor...\n";
}
Shape::~Shape()
{
	cout << "Shape destructor...\n";
}
void Shape::message()
{
	cout << "Shape! \n";
}

class Rectangle : public Shape
{
public: 
	Rectangle();
	~Rectangle();
	virtual void message();
};
Rectangle::Rectangle() : Shape()
{
	cout << "Rectangle constructor...\n";
}
Rectangle::~Rectangle()
{
	cout << "Rectangle destructor...\n";
}
void Rectangle::message()
{
	cout << "Rectangle! \n";
}

class Square : public Rectangle
{
public: 
	Square();
	~Square();
	virtual void message();
};
Square::Square() : Rectangle()
{
	cout << "Square constructor...\n";
}
Square::~Square()
{
	cout << "Square destructor...\n";
}
void Square::message()
{
	cout << "Square! \n";
}

void main()
{
	Shape *aShape = new Square();
	aShape->message(); 
	delete aShape;
}

