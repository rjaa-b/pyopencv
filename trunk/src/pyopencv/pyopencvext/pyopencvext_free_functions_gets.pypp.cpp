// This file has been generated by Py++.

#include "boost/python.hpp"
#include "opencv_headers.hpp"
#include "pyopencvext_free_functions_gets.pypp.hpp"

namespace bp = boost::python;

void register_free_functions_gets(){

    { //::cvGetSetElem
    
        typedef ::CvSetElem * ( *getSetElem_function_type )( ::CvSet const *,int );
        
        bp::def( 
            "getSetElem"
            , getSetElem_function_type( &::cvGetSetElem )
            , ( bp::arg("set_header"), bp::arg("index") )
            , bp::with_custodian_and_ward_postcall< 0, 1, bp::return_value_policy< bp::reference_existing_object > >()
            , "\nWrapped function:"
    "\n    cvGetSetElem" );
    
    }

    { //::cv::getStructuringElement
    
        typedef ::cv::Mat ( *getStructuringElement_function_type )( int,::cv::Size,::cv::Point );
        
        bp::def( 
            "getStructuringElement"
            , getStructuringElement_function_type( &::cv::getStructuringElement )
            , ( bp::arg("shape"), bp::arg("ksize"), bp::arg("anchor")=cv::Point_<int>(-0x000000001, -0x000000001) ) );
    
    }

}
