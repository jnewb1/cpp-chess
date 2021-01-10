#include <boost/python.hpp>

#include <Square.h>

int parse(std::string st)
{
    return 50;
}

BOOST_PYTHON_MODULE(cpp_chess)
{
    using namespace boost::python;

    scope().attr("Square") = Square;
    def("square_parse", parse);
}