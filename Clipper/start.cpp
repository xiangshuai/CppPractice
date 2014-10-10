#include "clipper.hpp"
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace ClipperLib;
using namespace cv;

int DrawPolygons(Mat &image, Paths paths, Scalar scalar)
{
    for(int i=0; i<paths.size(); i++)
    {
        vector<Point> pts;
        for(int j=0; j<paths[i].size(); j++)
        {
            pts.push_back(Point(paths[i][j].X, paths[i][j].Y));
        }

        const Point* ppt[1] = { &pts[0] };
        int npt = (int)pts.size();
        fillPoly( image, ppt, &npt, 1, scalar, 8 );
    }
}

int main()
{
    Paths subj(2), clip(1), solution;

    //define outer blue 'subject' polygon
    subj[0] << IntPoint(180,200) << IntPoint(260,200) << IntPoint(260,150) << IntPoint(180,150);

    //define subject's inner triangular 'hole' (with reverse orientation)
    subj[1] << IntPoint(215,160) << IntPoint(230,190) << IntPoint(200,190);

    //define orange 'clipping' polygon
    clip[0] << IntPoint(190,210) << IntPoint(240,210) << IntPoint(240,130) << IntPoint(190,130);

    Mat image = Mat::zeros( 400, 400, CV_8UC3 );
    //draw input polygons with user-defined routine ...
    DrawPolygons(image, subj, Scalar(0, 100, 0)); //blue
    DrawPolygons(image, clip, Scalar(0, 100, 0)); //orange

    //perform intersection ...
    Clipper c;
    c.AddPaths(subj, ptSubject, true);
    c.AddPaths(clip, ptClip, true);
    //c.Execute(ctIntersection, solution, pftNonZero, pftNonZero);
    //c.Execute(ctUnion, solution, pftNonZero, pftNonZero);
    c.Execute(ctDifference, solution, pftNonZero, pftNonZero);

    //draw solution with user-defined routine ...
    DrawPolygons(image, solution, Scalar(0, 255, 0)); //solution shaded green

    imshow("Image",image);

    waitKey( 0 );
    return 0;
}
