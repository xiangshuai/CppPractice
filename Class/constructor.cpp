#include <iostream>

// http://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm

using namespace std;

class Line
{
   public:
      int getLength( void );
      void setLength(double len);
      Line();
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

Line::Line(void)
{
    cout << "Object is being created" << endl;
     ptr = new int;
}

Line::Line(int len)
{
    cout << "Normal constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

Line::~Line(void)
{
    cout << "Freeing memory!"<< endl;
    delete ptr;
}

void Line::setLength(double len)
{
    *ptr = len;
}

int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "Length of line: " << obj.getLength() <<endl;
}

// Main function
int main()
{
//    int a = 10;
//    Line line(10);
//    // Copy an object to pass it as an argument to a function.
//    display(line);
//    return 0;


//    Line line1(10);
//    Line line2 = line1; // This also calls copy constructor
//
//    display(line1);
//    display(line2);

//    Line line3;
//    line3.setLength(6.0);
//    cout << "Length of line : " << line3.getLength() <<endl;
    Line *pl = new Line(10);
    display(*pl);
    delete pl;
    return 0;
}
