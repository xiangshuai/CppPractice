#include <iostream>
#include <deque>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/io/wkt/wkt.hpp>

#include <boost/foreach.hpp>


int main()
{
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    boost::geometry::read_wkt(
        "POLYGON((3 5, 6 5, 6 2, 3 2, 3 5))", green);

    boost::geometry::read_wkt(
        "POLYGON((4 3, 9 3, 9 1, 4 1, 4 3,))", blue);

    std::deque<polygon> output;
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
       // std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;

    }


    return 0;
}
