/**<
Putting Text in image
putText renders the specified text string in the image.

void putText(Mat& img, const string& text, Point org, int fontFace, double fontScale, Scalar color, int thickness=1, int lineType=8, bool bottomLeftOrigin=false )
Parameters:
img �C Image.
text �C Text string to be drawn.
org �C Bottom-left corner of the text string in the image.
fontFace �C Font type. One of FONT_HERSHEY_SIMPLEX, FONT_HERSHEY_PLAIN, FONT_HERSHEY_DUPLEX, FONT_HERSHEY_COMPLEX, FONT_HERSHEY_TRIPLEX, FONT_HERSHEY_COMPLEX_SMALL, FONT_HERSHEY_SCRIPT_SIMPLEX, or FONT_HERSHEY_SCRIPT_COMPLEX, where each of the font ID��s can be combined with FONT_HERSHEY_ITALIC to get the slanted letters.
fontScale �C Font scale factor that is multiplied by the font-specific base size.
color �C Text color.
thickness �C Thickness of the lines used to draw a text.
lineType �C Line type. See the line for details.
bottomLeftOrigin �C When true, the image data origin is at the bottom-left corner. Otherwise, it is at the top-left corner.
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main( )
{
  // Create black empty images
  Mat image = Mat::zeros( 400, 400, CV_8UC3 );

  putText(image, "Hi all...", Point(50,100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);
  imshow("Image",image);

  waitKey( 0 );
  return(0);
}
