#include<cmath>
#include<iostream>

//--------------------------------------------------

namespace NoObjects {
  double area(double size, bool isCircle=true) {
    if (isCircle) {
      return size * size * M_PI;
    } else {
      return size * size;
    }
  };

  double circleArea(double size) {
    return size * size * M_PI;
  };
  double squareArea(double size) {
    return size * size;
  };

  void test() {
    area(10);
    area(10, true);
    area(10, false);
  };

  class Vector {
  public:
    Vector(double x, double y) {
      this->x = x;
      this->y = y;
    };
  private:
    double x, y;
  };
};
//-------------------------------------------------

class IShape {
public:
  double area() { return 0;};
  virtual double circumference() { return 0;};
  double pi;
};

class IRectange {
public:
  double diagonal;
};

class Circle : public IShape {
public:
  Circle(double radius) {
    _radius = radius;
  }
  //double area() {
  //  return M_PI * _radius * _radius;
  //}
  double circumference() {
    return 2 * M_PI * _radius;
  }
private:
  double _radius;
};

class Circle2 : public IShape {
public:
  Circle2(double radius) {
    _area = M_PI * radius * radius;
    _circ = 2 * M_PI * radius;
  }
  double area() {
    return _area;
  }
  double circumference() {
    return _circ;
  }
private:
  double _area;
  double _circ;
};

class Square : public IShape, public IRectange {
public:
  Square(double size) {
    _a = size;
    diagonal = sqrt(size * size + size * size);
  }
  double area() {
    return _a * _a;
  }

  double circumference() {
    return 4 * _a;
  }

private:
  double _a;
};

int main() {
  // cím &------* adat
  // (*pointer).member == pointer->member;
  // Object* o = &object;

  IShape* s = new Circle(10);// dinamikus helyfoglalás
  Square square = Square(10);// statikus helyfoglalás
  IShape* s2 = &square;
  IRectange* r = &square;
  std::cout
    << "Area: " << s->area()
    << ", Circumference: " << s->circumference() << std::endl;
  std::cout
    << "Area: " << s2->area()
    << ", Circumference: " << s2->circumference() << std::endl;
  std::cout
    << "Diagonal: " << r->diagonal << std::endl;

  std::cout << NoObjects::area(10, false) << std::endl;
  std::cout << NoObjects::squareArea(10) << std::endl;

  NoObjects::Vector v = NoObjects::Vector(1,2);
  NoObjects::Vector* v2 = new NoObjects::Vector(1,2);
  delete v2;
  delete s;
}
