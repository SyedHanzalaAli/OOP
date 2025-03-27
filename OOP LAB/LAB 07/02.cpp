#include <iostream>
using namespace std;

class Shape {
    protected:
       string color;
       float border; // border thickness

    public:
       Shape(string c ="black" , float bt=1.0) : color(c) , border(bt){}

       virtual void draw() const {
         cout << "Drawing shape" << endl;
       }

       virtual float calArea() const =0;
       virtual float calPerimeter() const =0;
       
       virtual ~Shape(){}
};

class Circle :  public Shape {
    float radius;
    float cx , cy;

    public:
       Circle(float r , float x , float y , string c = "black" , float bt=1.0)
         : Shape(c,bt) , radius(r), cx(x) , cy(y) {}
       
        void draw() const override{
            cout << "Drawing a circle at  " << cx << "," << cy << "with radius" << radius << endl;
        }

        float calArea() const override {
            return 3.142 * radius * radius;
        }

        float calPerimeter() const override {
            return 3.142*radius*2;
        }
};

class Rectangle : public Shape{
    float width , height;
    float rx , ry;

    public:
       Rectangle(float w , float h , float x , float y , string c = "Black" , float bt=1.0 )
       : Shape(c , bt) , width(w) , height(h) , rx(x) , ry(y) {}

       void draw()const override{
          cout << "Drawing a rectangle at top-left " << rx << "," << ry << "with width" << width << "and height" << height <<endl;
        }

        float calArea() const override{
            return width*height;
        }

        float calPerimeter() const override{
            return 2*(width+height);
        }
};

int main(){

    Shape* s1 =  new Circle(5.0 , 10.0 , 15.0 , "red" , 2.0);
    Shape* s2 = new Rectangle(8.0,4.0 , 0.0 , 0.0 , "blue" , 1.5);

    s1->draw();
    cout << "Area : " << s1->calArea() <<endl;
    cout << "Perimeter : " << s1->calPerimeter() << endl;

    cout <<endl;

    s2->draw();
    cout << "Area : " << s2->calArea() <<endl;
    cout << "Perimeter : " << s2->calPerimeter() << endl;

    delete s1;
    delete s2;

    return 0;
}