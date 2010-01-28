// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "RotatedRect.pypp.hpp"

namespace bp = boost::python;

void register_RotatedRect_class(){

    bp::class_< cv::RotatedRect >( "RotatedRect", bp::init< >() )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< cv::RotatedRect >() )    
        .def( bp::init< cv::Point2f const &, cv::Size2f const &, float >(( bp::arg("_center"), bp::arg("_size"), bp::arg("_angle") )) )    
        .def( 
            "boundingRect"
            , (::cv::Rect ( ::cv::RotatedRect::* )(  ) const)( &::cv::RotatedRect::boundingRect ) )    
        .def( 
            "points"
            , (void ( ::cv::RotatedRect::* )( ::cv::Point2f * ) const)( &::cv::RotatedRect::points )
            , ( bp::arg("pt") ) )    
        .def_readwrite( "angle", &cv::RotatedRect::angle )    
        .def_readwrite( "center", &cv::RotatedRect::center )    
        .def_readwrite( "size", &cv::RotatedRect::size );

}
