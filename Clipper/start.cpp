#include <iostream>
#include "clipper.hpp"
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace ClipperLib;
using namespace cv;

//double const scale = 1024.0;
//double const min_value = std::numeric_limits<long>::min() / scale;
//double const max_value = std::numeric_limits<long>::max() / scale;

//long to_long(double v)
//{
//    if(v < 0)
//    {
//        if(v < min_value)
//            throw out_of_range();
//        return static_cast<long>(v * scale - 0.5);
//    }
//    else
//    {
//        if(v > max_value)
//            throw out_of_range();
//        return static_cast<long>(v * scale + 0.5);
//    }
//}

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
    return 0;
}

int main()
{
    Paths subj(1), clip(1), solution;

    //define outer blue 'subject' polygon
    subj[0] << IntPoint(180,200);
    subj[0] << IntPoint(260,200);
    subj[0] << IntPoint(260,150);
    subj[0] << IntPoint(180,150);

    //define subject's inner triangular 'hole' (with reverse orientation)
    //subj[1] << IntPoint(215,160) << IntPoint(230,190) << IntPoint(200,190);

    //define orange 'clipping' polygon
    clip[0] << IntPoint(90,200) << IntPoint(40,200) << IntPoint(40,150) << IntPoint(90,150);

    //clip[1] << IntPoint(190,210) << IntPoint(240,210) << IntPoint(240,130) << IntPoint(190,130);
    //clip[1] << IntPoint(90,200) << IntPoint(90,150) << IntPoint(180, 150) << IntPoint(180, 200);

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
    bool flag =  c.Execute(ctUnion, solution, pftNonZero, pftNonZero);

    cout << flag << endl;

    cout << solution.size() << endl;
    //draw solution with user-defined routine ...
    DrawPolygons(image, solution, Scalar(0, 255, 0)); //solution shaded green

    imshow("Image",image);

    waitKey( 0 );
    return 0;
}
