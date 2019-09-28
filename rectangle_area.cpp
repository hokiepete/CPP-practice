#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */


 class Rectangle{
     public:
     int width;
     int height;
     virtual void display(){
         cout << width << " " << height << endl;
     }
 };

 class RectangleArea : public Rectangle{
     public:
     void read_input(){
         cin >> width >> height ;
     }
     void display() override{
         cout << width*height << endl;
     }

//The class should have read_input() method, to read the values of width and height of the rectangle. The RectangleArea class should also overload the display() method to print the area of the rectangle.

 };


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}