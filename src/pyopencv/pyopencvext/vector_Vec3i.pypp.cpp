// This file has been generated by Py++.

#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
#include "opencv_headers.hpp"
#include "vector_Vec3i.pypp.hpp"

namespace bp = boost::python;

static inline void resize(::std::vector< cv::Vec<int, 3> > &inst, size_t num) { inst.resize(num); }

void register_vector_Vec3i_class(){

    { //::std::vector< cv::Vec<int, 3> >
        typedef bp::class_< std::vector< cv::Vec<int, 3> > > vector_Vec3i_exposer_t;
        vector_Vec3i_exposer_t vector_Vec3i_exposer = vector_Vec3i_exposer_t( "vector_Vec3i" );
        bp::scope vector_Vec3i_scope( vector_Vec3i_exposer );
        //WARNING: the next line of code will not compile, because "::cv::Vec<int, 3>" does not have operator== !
        vector_Vec3i_exposer.def( bp::vector_indexing_suite< ::std::vector< cv::Vec<int, 3> > >() );
        vector_Vec3i_exposer.def("resize", &::resize, ( bp::arg("num") ));
    }

}
