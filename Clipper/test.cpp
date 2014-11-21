#include <vector>
#include "clipper.hpp"
using namespace std;
using namespace ClipperLib;

int main()
{
    Paths subj(1);

    //define outer blue 'subject' polygon
    //subj[0] << IntPoint(180,200) << IntPoint(260,200) << IntPoint(260,150) << IntPoint(180,150);

    vector<IntPoint> pts;
    pts.push_back(IntPoint(180,200));
    pts.push_back(IntPoint(260,200));
    pts.push_back(IntPoint(260,150));
    pts.push_back(IntPoint(180,150));

    for(int i=0; i<pts.size(); i++)
    {
        subj[0] << pts[i];
    }

    return 0;
}
