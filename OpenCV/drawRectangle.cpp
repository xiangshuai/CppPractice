/**<
Drawing a Rectangle
void rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
Parameters:
img �C Image.
pt1 �C Vertex of the rectangle.
pt2 �C Vertex of the rectangle opposite to pt1 .
rec �C Alternative specification of the drawn rectangle.
color �C Rectangle color or brightness (grayscale image).
thickness �C Thickness of lines that make up the rectangle. Negative values, like CV_FILLED , mean that the function has to draw a filled rectangle.
lineType �C Type of the line. See the line() description.
shift �C Number of fractional bits in the point coordinates.
*/

#include <core/core.hpp>
#include <highgui/highgui.hpp>
using namespace cv;

int main()
{
    // Create black empty images
    Mat image = Mat::zeros( 400, 400, CV_8UC3 );

    // Draw a rectangle ( 5th argument is not -ve)
    rectangle( image, Point( 15, 20 ), Point( 70, 50), Scalar( 0, 55, 255 ), +1, 4 );
    imshow("Image1",image);
    // Draw a filled rectangle ( 5th argument is -ve)
    rectangle( image, Point( 115, 120 ), Point( 170, 150), Scalar( 100, 155, 25 ), -1, 8 );

    imshow("Image2",image);

    waitKey( 0 );
    return(0);
}
