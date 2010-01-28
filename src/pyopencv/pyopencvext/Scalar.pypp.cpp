// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "ndarray.hpp"
#include "Scalar.pypp.hpp"

namespace bp = boost::python;

void register_Scalar_class(){

    { //::cv::Scalar_< double >
        typedef bp::class_< cv::Scalar_< double >, bp::bases< cv::Vec< double, 4 > > > Scalar_exposer_t;
        Scalar_exposer_t Scalar_exposer = Scalar_exposer_t( "Scalar", bp::init< >() );
        bp::scope Scalar_scope( Scalar_exposer );
        Scalar_exposer.add_property( "this", pyplus_conv::make_addressof_inst_getter< cv::Scalar_< double > >() );
        Scalar_exposer.def( bp::init< double, double, bp::optional< double, double > >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2")=0, bp::arg("v3")=0 )) );
        Scalar_exposer.def( bp::init< double >(( bp::arg("v0") )) );
        bp::implicitly_convertible< double, cv::Scalar_< double > >();
        { //::cv::Scalar_< double >::all
        
            typedef cv::Scalar_< double > exported_class_t;
            typedef ::cv::Scalar_< double > ( *all_function_type )( double );
            
            Scalar_exposer.def( 
                "all"
                , all_function_type( &::cv::Scalar_< double >::all )
                , ( bp::arg("v0") ) );
        
        }
        { //::cv::Scalar_< double >::mul
        
            typedef cv::Scalar_< double > exported_class_t;
            typedef ::cv::Scalar_< double > ( exported_class_t::*mul_function_type )( ::cv::Scalar_< double > const &,double ) const;
            
            Scalar_exposer.def( 
                "mul"
                , mul_function_type( &::cv::Scalar_< double >::mul )
                , ( bp::arg("t"), bp::arg("scale")=1 ) );
        
        }
        Scalar_exposer.staticmethod( "all" );
        Scalar_exposer.def("from_ndarray", &bp::from_ndarray< cv::Scalar > );
        Scalar_exposer.staticmethod("from_ndarray");
        Scalar_exposer.add_property("ndarray", &bp::as_ndarray< cv::Scalar >);
    }

}
