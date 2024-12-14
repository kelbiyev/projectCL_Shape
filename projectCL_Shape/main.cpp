#include <iostream>
#include <string>
#include <vector>

class Shape {
protected:
    std::string name;
public:
    Shape (const std::string& n): name(n){}
    virtual std::string Form() const = 0;
};

class Ellipse: public Shape {
private:
    int x , y , a , b;
public:
    Ellipse(const std::string& n): Shape(n){}
    std::string Form() const override {
        return "Ellipse";
    }
};

class Quadrangle: public Shape {
private:
    int a , b , c , d;
    int perimeter  = a + b + c + d;
public:
    Quadrangle(const std::string& n): Shape(n){}
    std::string Form() const override {
        return "Quadrangle";
    }
};

class Circle: public Ellipse {
private:
    int x , y , r;
    int pi = 3,14;
    int perimeter = 2 * pi * r;
public:
    Circle(const std::string& n): Ellipse(n){}
    std::string Form() const override final{
        return "Circle";
    }
};

class Rectangle: public Quadrangle {
private:
    int a , b;
    int perimeter = (a + b) * 2 ;
public:
    Rectangle(const std::string& n): Quadrangle(n){}
    std::string Form() const override {
        return "Rectangle";
    }
};

class Square: public Rectangle {
private:
    int a;
    int perimeter = 4 * a;
public:
    Square(const std::string& n): Rectangle(n){}
    std::string Form() const override final
    {
        return "Square";
    }
};

void Process(const Shape& form) {
    std::cout<<form.Form()<<"\n";
}

int main()
{
    std::vector <Shape*> classes;

    classes.push_back(new Ellipse("Эллипс"));
    classes.push_back(new Circle("Кружок"));
    classes.push_back(new Quadrangle("Четырехугольник"));
    classes.push_back(new Rectangle("Прямоугольник"));
    classes.push_back(new Square("Квадрат"));

    Process(*classes[0]);
    Process(*classes[1]);
    Process(*classes[2]);
    Process(*classes[3]);
    Process(*classes[4]);
}
