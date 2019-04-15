#include <iostream>

using namespace std;
/*
 * Shape Class provide the same interface so that the classes can refer to 
 * the interface not the concrete Shape
 */

class Shape
{
	public:
		virtual	~Shape() {}
		virtual std::string draw() = 0;

		//...
};

/*
 * Concrete Shape 
 * Define shape to be created
 */
class ConcreteShapeCircle: public Shape
{
public:
	~ConcreteShapeCircle(){};
	std::string draw()
	{
		return "Drawing Circle";
	}
};

/*
 * Concrete Shape 
 * Define shape to be created
 */
class ConcreteShapeSquare: public Shape
{
public:
	~ConcreteShapeSquare(){};
	std::string draw()
	{
		return "Drawing Square";
	}
};

/*
 * Concrete Shape 
 * Define shape to be created
 */
class ConcreteShapeRectangle: public Shape
{
public:
	~ConcreteShapeRectangle(){};
	std::string draw()
	{
		return "Drawing Rectangle";
	}
};

/*
 * Shape Factory tp create the concrete shape based on the information
 */

class ShapeFactory 
{
public:
	Shape* getShape(std::string shapeType) 
	{
		if(shapeType == "circle")
		{
			return new ConcreteShapeCircle();
		}
		if(shapeType == "rectangle")
		{
			return new ConcreteShapeRectangle();
		}
		if(shapeType == "square")
		{
			return new ConcreteShapeSquare();
		}
	}
};

int main()
{
	ShapeFactory *factory = new ShapeFactory();
	Shape *s1 = factory->getShape("circle");
	cout << s1->draw() << endl;
	Shape *s2 = factory->getShape("rectangle");
	cout << s2->draw() << endl;
	Shape *s3 = factory->getShape("square");
	cout << s3->draw() << endl;
}
