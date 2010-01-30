// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "PatchGenerator.pypp.hpp"

namespace bp = boost::python;

void register_PatchGenerator_class(){

    bp::class_< cv::PatchGenerator >( "PatchGenerator", bp::init< >() )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< cv::PatchGenerator >() )    
        .def( bp::init< double, double, double, bp::optional< bool, double, double, double, double, double, double > >(( bp::arg("_backgroundMin"), bp::arg("_backgroundMax"), bp::arg("_noiseRange"), bp::arg("_randomBlur")=(bool)(true), bp::arg("_lambdaMin")=5.99999999999999977795539507496869191527366638184e-1, bp::arg("_lambdaMax")=1.5e+0, bp::arg("_thetaMin")=-3.14159265358979311599796346854418516159057617188e+0, bp::arg("_thetaMax")=3.14159265358979311599796346854418516159057617188e+0, bp::arg("_phiMin")=-3.14159265358979311599796346854418516159057617188e+0, bp::arg("_phiMax")=3.14159265358979311599796346854418516159057617188e+0 )) )    
        .def( 
            "generateRandomTransform"
            , (void ( ::cv::PatchGenerator::* )( ::cv::Point2f,::cv::Point2f,::cv::Mat &,::cv::RNG &,bool ) const)( &::cv::PatchGenerator::generateRandomTransform )
            , ( bp::arg("srcCenter"), bp::arg("dstCenter"), bp::arg("transform"), bp::arg("rng"), bp::arg("inverse")=(bool)(false) ) )    
        .def( 
            "__call__"
            , (void ( ::cv::PatchGenerator::* )( ::cv::Mat const &,::cv::Point2f,::cv::Mat &,::cv::Size,::cv::RNG & ) const)( &::cv::PatchGenerator::operator() )
            , ( bp::arg("image"), bp::arg("pt"), bp::arg("patch"), bp::arg("patchSize"), bp::arg("rng") ) )    
        .def( 
            "__call__"
            , (void ( ::cv::PatchGenerator::* )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat &,::cv::Size,::cv::RNG & ) const)( &::cv::PatchGenerator::operator() )
            , ( bp::arg("image"), bp::arg("transform"), bp::arg("patch"), bp::arg("patchSize"), bp::arg("rng") ) )    
        .def( 
            "warpWholeImage"
            , (void ( ::cv::PatchGenerator::* )( ::cv::Mat const &,::cv::Mat &,::cv::Mat &,::cv::Mat &,int,::cv::RNG & ) const)( &::cv::PatchGenerator::warpWholeImage )
            , ( bp::arg("image"), bp::arg("_T"), bp::arg("buf"), bp::arg("warped"), bp::arg("border"), bp::arg("rng") ) )    
        .def_readwrite( "backgroundMax", &cv::PatchGenerator::backgroundMax )    
        .def_readwrite( "backgroundMin", &cv::PatchGenerator::backgroundMin )    
        .def_readwrite( "lambdaMax", &cv::PatchGenerator::lambdaMax )    
        .def_readwrite( "lambdaMin", &cv::PatchGenerator::lambdaMin )    
        .def_readwrite( "noiseRange", &cv::PatchGenerator::noiseRange )    
        .def_readwrite( "phiMax", &cv::PatchGenerator::phiMax )    
        .def_readwrite( "phiMin", &cv::PatchGenerator::phiMin )    
        .def_readwrite( "randomBlur", &cv::PatchGenerator::randomBlur )    
        .def_readwrite( "thetaMax", &cv::PatchGenerator::thetaMax )    
        .def_readwrite( "thetaMin", &cv::PatchGenerator::thetaMin );

}