#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#define pi 3.14

using namespace std;

class Figure
{
public:
	virtual void info() = 0;
	virtual double Volume() = 0;
	virtual double Area() = 0;
	virtual ~Figure() 
	{
		cout << "Figure free" << endl;
	};
};

class Cylinder : public Figure
{
private:
	string name;
	double height;
	double radius;
public:
	Cylinder() {};

	Cylinder(string name, double height, double radius) :
		name(name),
		height(height),
		radius(radius)
	{
		cout << "Cylinder initialized" << endl;
	}

	~Cylinder() 
	{
		cout << "Cylinder free" << endl;
	}

	void info()
	{
		cout << "Object name: " << name << endl;
	}

	double Volume()
	{
		return pi*radius*radius*height;
	}

	double Area()
	{
		return 2 * pi*radius*radius + 2 * pi*radius*height;
	}
};

class Ball : public Figure
{
private:
	string name;
	double radius;
public:
	Ball() {};

	Ball(string name, double radius) :
		name(name),
		radius(radius)
	{
		cout << "Ball initialized" << endl;
	}

	~Ball() 
	{
		cout << "Ball free" << endl;
	}

	void info()
	{
		cout << "Object name: " << name << endl;
	}

	double Volume()
	{
		return 4 * pi*radius*radius*radius / 3;
	}

	double Area()
	{
		return 4 * pi*radius*radius;
	}
};

int main()
{
	Cylinder C1("C1", 10, 6);
	Cylinder C2("C2", 12, 8);
	Ball B1("B1", 5);
	Ball B2("B2", 10);
	vector <Figure*> array;
	array.push_back(new Cylinder);
	array.push_back(new Cylinder);
	array.push_back(new Ball);
	array.push_back(new Ball);
	array[0] = &C1;
	array[1] = &C2;
	array[2] = &B1;
	array[3] = &B2;
	for (size_t i = 0; i < array.size(); i++)
	{	
		array[i]->info();
		cout << "Volume: " << array[i]->Volume() << endl;
		cout << "Area: " << array[i]->Area() << endl;
	}
	array.clear();
	return 0;
}
