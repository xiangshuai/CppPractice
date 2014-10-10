#include <core/core.hpp>
#include <highgui/highgui.hpp>
using namespace cv;

int main()
{
    // Create black empty images
    Mat image = Mat::zeros(400, 400, CV_8UC3);

    // Draw a line
    line(image, Point(15, 20), Point(70, 50), Scalar(110, 220, 0), 2, 8);
    imshow("image", image);

    waitKey(0);
    return 0;
}
