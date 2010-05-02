// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "opencv_converters.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "boost/python/object/life_support.hpp"
#include "arrayobject.h"
#include "ndarray.hpp"
#include "CvSVM.pypp.hpp"

namespace bp = boost::python;

struct CvSVM_wrapper : CvSVM, bp::wrapper< CvSVM > {

    CvSVM_wrapper(CvSVM const & arg )
    : CvSVM( arg )
      , bp::wrapper< CvSVM >(){
        // copy constructor
        
    }

    CvSVM_wrapper( )
    : CvSVM( )
      , bp::wrapper< CvSVM >(){
        // null constructor
    
    }

    CvSVM_wrapper(::CvMat const * _train_data, ::CvMat const * _responses, ::CvMat const * _var_idx=0, ::CvMat const * _sample_idx=0, ::CvSVMParams _params=::CvSVMParams( ) )
    : CvSVM( boost::python::ptr(_train_data), boost::python::ptr(_responses), boost::python::ptr(_var_idx), boost::python::ptr(_sample_idx), _params )
      , bp::wrapper< CvSVM >(){
        // constructor
    
    }

    CvSVM_wrapper(::cv::Mat const & _train_data, ::cv::Mat const & _responses, ::cv::Mat const & _var_idx=cv::Mat(), ::cv::Mat const & _sample_idx=cv::Mat(), ::CvSVMParams _params=::CvSVMParams( ) )
    : CvSVM( boost::ref(_train_data), boost::ref(_responses), boost::ref(_var_idx), boost::ref(_sample_idx), _params )
      , bp::wrapper< CvSVM >(){
        // constructor
    
    }

    virtual void clear(  ) {
        if( bp::override func_clear = this->get_override( "clear" ) )
            func_clear(  );
        else{
            this->CvSVM::clear(  );
        }
    }
    
    void default_clear(  ) {
        CvSVM::clear( );
    }

    virtual ::CvSVMParams get_params(  ) const  {
        if( bp::override func_get_params = this->get_override( "get_params" ) )
            return func_get_params(  );
        else{
            return this->CvSVM::get_params(  );
        }
    }
    
    ::CvSVMParams default_get_params(  ) const  {
        return CvSVM::get_params( );
    }

    virtual int get_support_vector_count(  ) const  {
        if( bp::override func_get_support_vector_count = this->get_override( "get_support_vector_count" ) )
            return func_get_support_vector_count(  );
        else{
            return this->CvSVM::get_support_vector_count(  );
        }
    }
    
    int default_get_support_vector_count(  ) const  {
        return CvSVM::get_support_vector_count( );
    }

    virtual float predict( ::CvMat const * _sample, bool returnDFVal=false ) const  {
        namespace bpl = boost::python;
        if( bpl::override func_predict = this->get_override( "predict" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_predict.ptr(), _sample, returnDFVal );
            return bpl::extract< float >( pyplus_conv::get_out_argument( py_result, 0 ) );
        }
        else{
            return CvSVM::predict( boost::python::ptr(_sample), returnDFVal );
        }
    }
    
    static boost::python::object default_predict_c02d4fcfe9f774ce1816d6b16d2df3c5( ::CvSVM const & inst, ::cv::Mat & _sample, bool returnDFVal=false ){
        float result;
        if( dynamic_cast< CvSVM_wrapper const* >( boost::addressof( inst ) ) ){
            result = inst.::CvSVM::predict(get_CvMat_ptr(_sample), returnDFVal);
        }
        else{
            result = inst.predict(get_CvMat_ptr(_sample), returnDFVal);
        }
        return bp::object( result );
    }

    virtual float predict( ::cv::Mat const & _sample, bool returnDFVal=false ) const  {
        if( bp::override func_predict = this->get_override( "predict" ) )
            return func_predict( boost::ref(_sample), returnDFVal );
        else{
            return this->CvSVM::predict( boost::ref(_sample), returnDFVal );
        }
    }
    
    float default_predict( ::cv::Mat const & _sample, bool returnDFVal=false ) const  {
        return CvSVM::predict( boost::ref(_sample), returnDFVal );
    }

    virtual void read( ::CvFileStorage * storage, ::CvFileNode * node ) {
        namespace bpl = boost::python;
        if( bpl::override func_read = this->get_override( "read" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_read.ptr(), storage, node );
        }
        else{
            CvSVM::read( boost::python::ptr(storage), boost::python::ptr(node) );
        }
    }
    
    static void default_read( ::CvSVM & inst, ::cv::FileStorage & storage, ::cv::FileNode & node ){
        if( dynamic_cast< CvSVM_wrapper * >( boost::addressof( inst ) ) ){
            inst.::CvSVM::read(storage.fs, *(node));
        }
        else{
            inst.read(storage.fs, *(node));
        }
    }

    virtual bool train( ::CvMat const * _train_data, ::CvMat const * _responses, ::CvMat const * _var_idx=0, ::CvMat const * _sample_idx=0, ::CvSVMParams _params=::CvSVMParams( ) ) {
        namespace bpl = boost::python;
        if( bpl::override func_train = this->get_override( "train" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_train.ptr(), _train_data, _responses, _var_idx, _sample_idx, _params );
            return bpl::extract< bool >( pyplus_conv::get_out_argument( py_result, 0 ) );
        }
        else{
            return CvSVM::train( boost::python::ptr(_train_data), boost::python::ptr(_responses), boost::python::ptr(_var_idx), boost::python::ptr(_sample_idx), _params );
        }
    }
    
    static boost::python::object default_train_a051ed21e9e7670e8100d8bda1f730ea( ::CvSVM & inst, ::cv::Mat & _train_data, ::cv::Mat & _responses, ::cv::Mat _var_idx=cv::Mat(), ::cv::Mat _sample_idx=cv::Mat(), ::CvSVMParams _params=::CvSVMParams( ) ){
        bool result;
        if( dynamic_cast< CvSVM_wrapper * >( boost::addressof( inst ) ) ){
            result = inst.::CvSVM::train(get_CvMat_ptr(_train_data), get_CvMat_ptr(_responses), get_CvMat_ptr(_var_idx), get_CvMat_ptr(_sample_idx), _params);
        }
        else{
            result = inst.train(get_CvMat_ptr(_train_data), get_CvMat_ptr(_responses), get_CvMat_ptr(_var_idx), get_CvMat_ptr(_sample_idx), _params);
        }
        return bp::object( result );
    }

    virtual bool train( ::cv::Mat const & _train_data, ::cv::Mat const & _responses, ::cv::Mat const & _var_idx=cv::Mat(), ::cv::Mat const & _sample_idx=cv::Mat(), ::CvSVMParams _params=::CvSVMParams( ) ) {
        if( bp::override func_train = this->get_override( "train" ) )
            return func_train( boost::ref(_train_data), boost::ref(_responses), boost::ref(_var_idx), boost::ref(_sample_idx), _params );
        else{
            return this->CvSVM::train( boost::ref(_train_data), boost::ref(_responses), boost::ref(_var_idx), boost::ref(_sample_idx), _params );
        }
    }
    
    bool default_train( ::cv::Mat const & _train_data, ::cv::Mat const & _responses, ::cv::Mat const & _var_idx=cv::Mat(), ::cv::Mat const & _sample_idx=cv::Mat(), ::CvSVMParams _params=::CvSVMParams( ) ) {
        return CvSVM::train( boost::ref(_train_data), boost::ref(_responses), boost::ref(_var_idx), boost::ref(_sample_idx), _params );
    }

    virtual bool train_auto( ::CvMat const * _train_data, ::CvMat const * _responses, ::CvMat const * _var_idx, ::CvMat const * _sample_idx, ::CvSVMParams _params, int k_fold=10, ::CvParamGrid C_grid=CvSVM::get_default_grid(0), ::CvParamGrid gamma_grid=CvSVM::get_default_grid(1), ::CvParamGrid p_grid=CvSVM::get_default_grid(2), ::CvParamGrid nu_grid=CvSVM::get_default_grid(3), ::CvParamGrid coef_grid=CvSVM::get_default_grid(4), ::CvParamGrid degree_grid=CvSVM::get_default_grid(5) ) {
        namespace bpl = boost::python;
        if( bpl::override func_train_auto = this->get_override( "train_auto" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_train_auto.ptr(), _train_data, _responses, _var_idx, _sample_idx, _params, k_fold, C_grid, gamma_grid, p_grid, nu_grid, coef_grid, degree_grid );
            return bpl::extract< bool >( pyplus_conv::get_out_argument( py_result, 0 ) );
        }
        else{
            return CvSVM::train_auto( boost::python::ptr(_train_data), boost::python::ptr(_responses), boost::python::ptr(_var_idx), boost::python::ptr(_sample_idx), _params, k_fold, C_grid, gamma_grid, p_grid, nu_grid, coef_grid, degree_grid );
        }
    }
    
    static boost::python::object default_train_auto_8b5d0a3d89137f3ac15eb66fedb4914d( ::CvSVM & inst, ::cv::Mat & _train_data, ::cv::Mat & _responses, ::cv::Mat & _var_idx, ::cv::Mat & _sample_idx, ::CvSVMParams _params, int k_fold=10, ::CvParamGrid C_grid=CvSVM::get_default_grid(0), ::CvParamGrid gamma_grid=CvSVM::get_default_grid(1), ::CvParamGrid p_grid=CvSVM::get_default_grid(2), ::CvParamGrid nu_grid=CvSVM::get_default_grid(3), ::CvParamGrid coef_grid=CvSVM::get_default_grid(4), ::CvParamGrid degree_grid=CvSVM::get_default_grid(5) ){
        bool result;
        if( dynamic_cast< CvSVM_wrapper * >( boost::addressof( inst ) ) ){
            result = inst.::CvSVM::train_auto(get_CvMat_ptr(_train_data), get_CvMat_ptr(_responses), get_CvMat_ptr(_var_idx), get_CvMat_ptr(_sample_idx), _params, k_fold, C_grid, gamma_grid, p_grid, nu_grid, coef_grid, degree_grid);
        }
        else{
            result = inst.train_auto(get_CvMat_ptr(_train_data), get_CvMat_ptr(_responses), get_CvMat_ptr(_var_idx), get_CvMat_ptr(_sample_idx), _params, k_fold, C_grid, gamma_grid, p_grid, nu_grid, coef_grid, degree_grid);
        }
        return bp::object( result );
    }

    virtual bool train_auto( ::cv::Mat const & _train_data, ::cv::Mat const & _responses, ::cv::Mat const & _var_idx, ::cv::Mat const & _sample_idx, ::CvSVMParams _params, int k_fold=10, ::CvParamGrid C_grid=CvSVM::get_default_grid(0), ::CvParamGrid gamma_grid=CvSVM::get_default_grid(1), ::CvParamGrid p_grid=CvSVM::get_default_grid(2), ::CvParamGrid nu_grid=CvSVM::get_default_grid(3), ::CvParamGrid coef_grid=CvSVM::get_default_grid(4), ::CvParamGrid degree_grid=CvSVM::get_default_grid(5) ) {
        if( bp::override func_train_auto = this->get_override( "train_auto" ) )
            return func_train_auto( boost::ref(_train_data), boost::ref(_responses), boost::ref(_var_idx), boost::ref(_sample_idx), _params, k_fold, C_grid, gamma_grid, p_grid, nu_grid, coef_grid, degree_grid );
        else{
            return this->CvSVM::train_auto( boost::ref(_train_data), boost::ref(_responses), boost::ref(_var_idx), boost::ref(_sample_idx), _params, k_fold, C_grid, gamma_grid, p_grid, nu_grid, coef_grid, degree_grid );
        }
    }
    
    bool default_train_auto( ::cv::Mat const & _train_data, ::cv::Mat const & _responses, ::cv::Mat const & _var_idx, ::cv::Mat const & _sample_idx, ::CvSVMParams _params, int k_fold=10, ::CvParamGrid C_grid=CvSVM::get_default_grid(0), ::CvParamGrid gamma_grid=CvSVM::get_default_grid(1), ::CvParamGrid p_grid=CvSVM::get_default_grid(2), ::CvParamGrid nu_grid=CvSVM::get_default_grid(3), ::CvParamGrid coef_grid=CvSVM::get_default_grid(4), ::CvParamGrid degree_grid=CvSVM::get_default_grid(5) ) {
        return CvSVM::train_auto( boost::ref(_train_data), boost::ref(_responses), boost::ref(_var_idx), boost::ref(_sample_idx), _params, k_fold, C_grid, gamma_grid, p_grid, nu_grid, coef_grid, degree_grid );
    }

    virtual void write( ::CvFileStorage * storage, char const * name ) const  {
        namespace bpl = boost::python;
        if( bpl::override func_write = this->get_override( "write" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_write.ptr(), storage, name );
        }
        else{
            CvSVM::write( boost::python::ptr(storage), name );
        }
    }
    
    static void default_write( ::CvSVM const & inst, ::cv::FileStorage & storage, char const * name ){
        if( dynamic_cast< CvSVM_wrapper const* >( boost::addressof( inst ) ) ){
            inst.::CvSVM::write(storage.fs, name);
        }
        else{
            inst.write(storage.fs, name);
        }
    }

    virtual void load( char const * filename, char const * name=0 ) {
        if( bp::override func_load = this->get_override( "load" ) )
            func_load( filename, name );
        else{
            this->CvStatModel::load( filename, name );
        }
    }
    
    void default_load( char const * filename, char const * name=0 ) {
        CvStatModel::load( filename, name );
    }

    virtual void save( char const * filename, char const * name=0 ) const  {
        if( bp::override func_save = this->get_override( "save" ) )
            func_save( filename, name );
        else{
            this->CvStatModel::save( filename, name );
        }
    }
    
    void default_save( char const * filename, char const * name=0 ) const  {
        CvStatModel::save( filename, name );
    }

    CvSVM_wrapper(::cv::Mat const & _train_data, ::cv::Mat const & _responses, ::cv::Mat const & _var_idx=cv::Mat(), ::cv::Mat const & _sample_idx=cv::Mat(), ::CvSVMParams _params=::CvSVMParams( ) )
    : CvSVM()
      , bp::wrapper< CvSVM >(){
        // constructor
        train( _train_data, _responses, _var_idx, _sample_idx, _params );        
    }
      
    bp::object get_support_vector_(int i) {
        int len = get_var_count();
        bp::object result = sdcpp::new_ndarray(1, &len, NPY_FLOAT, 0, 
            (void *)get_support_vector(i), NPY_C_CONTIGUOUS).get_obj();
        bp::objects::make_nurse_and_patient(result.ptr(), bp::object(bp::ptr(this)).ptr());
        return result;
    }

};

void register_CvSVM_class(){

    { //::CvSVM
        typedef bp::class_< CvSVM_wrapper, bp::bases< CvStatModel > > CvSVM_exposer_t;
        CvSVM_exposer_t CvSVM_exposer = CvSVM_exposer_t( "CvSVM", bp::init< >() );
        bp::scope CvSVM_scope( CvSVM_exposer );
        CvSVM_exposer.add_property( "this", pyplus_conv::make_addressof_inst_getter< CvSVM >() );
        bp::scope().attr("C_SVC") = (int)CvSVM::C_SVC;
        bp::scope().attr("NU_SVC") = (int)CvSVM::NU_SVC;
        bp::scope().attr("ONE_CLASS") = (int)CvSVM::ONE_CLASS;
        bp::scope().attr("EPS_SVR") = (int)CvSVM::EPS_SVR;
        bp::scope().attr("NU_SVR") = (int)CvSVM::NU_SVR;
        bp::scope().attr("LINEAR") = (int)CvSVM::LINEAR;
        bp::scope().attr("POLY") = (int)CvSVM::POLY;
        bp::scope().attr("RBF") = (int)CvSVM::RBF;
        bp::scope().attr("SIGMOID") = (int)CvSVM::SIGMOID;
        bp::scope().attr("C") = (int)CvSVM::C;
        bp::scope().attr("GAMMA") = (int)CvSVM::GAMMA;
        bp::scope().attr("P") = (int)CvSVM::P;
        bp::scope().attr("NU") = (int)CvSVM::NU;
        bp::scope().attr("COEF") = (int)CvSVM::COEF;
        bp::scope().attr("DEGREE") = (int)CvSVM::DEGREE;
        CvSVM_exposer.def( bp::init< CvMat const *, CvMat const *, bp::optional< CvMat const *, CvMat const *, CvSVMParams > >(( bp::arg("_train_data"), bp::arg("_responses"), bp::arg("_var_idx")=bp::object(), bp::arg("_sample_idx")=bp::object(), bp::arg("_params")=::CvSVMParams( ) ), "\nWrapped function:"
    "\n    CvSVM"
    "\nArgument '_sample_idx':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_train_data':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_var_idx':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_responses':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat.") );
        CvSVM_exposer.def( bp::init< cv::Mat const &, cv::Mat const &, bp::optional< cv::Mat const &, cv::Mat const &, CvSVMParams > >(( bp::arg("_train_data"), bp::arg("_responses"), bp::arg("_var_idx")=cv::Mat(), bp::arg("_sample_idx")=cv::Mat(), bp::arg("_params")=::CvSVMParams( ) )) );
        { //::CvSVM::clear
        
            typedef void ( ::CvSVM::*clear_function_type )(  ) ;
            typedef void ( CvSVM_wrapper::*default_clear_function_type )(  ) ;
            
            CvSVM_exposer.def( 
                "clear"
                , clear_function_type(&::CvSVM::clear)
                , default_clear_function_type(&CvSVM_wrapper::default_clear) );
        
        }
        { //::CvSVM::get_default_grid
        
            typedef ::CvParamGrid ( *get_default_grid_function_type )( int );
            
            CvSVM_exposer.def( 
                "get_default_grid"
                , get_default_grid_function_type( &::CvSVM::get_default_grid )
                , ( bp::arg("param_id") ) );
        
        }
        { //::CvSVM::get_params
        
            typedef ::CvSVMParams ( ::CvSVM::*get_params_function_type )(  ) const;
            typedef ::CvSVMParams ( CvSVM_wrapper::*default_get_params_function_type )(  ) const;
            
            CvSVM_exposer.def( 
                "get_params"
                , get_params_function_type(&::CvSVM::get_params)
                , default_get_params_function_type(&CvSVM_wrapper::default_get_params) );
        
        }
        { //::CvSVM::get_support_vector_count
        
            typedef int ( ::CvSVM::*get_support_vector_count_function_type )(  ) const;
            typedef int ( CvSVM_wrapper::*default_get_support_vector_count_function_type )(  ) const;
            
            CvSVM_exposer.def( 
                "get_support_vector_count"
                , get_support_vector_count_function_type(&::CvSVM::get_support_vector_count)
                , default_get_support_vector_count_function_type(&CvSVM_wrapper::default_get_support_vector_count) );
        
        }
        { //::CvSVM::get_var_count
        
            typedef int ( ::CvSVM::*get_var_count_function_type )(  ) const;
            
            CvSVM_exposer.def( 
                "get_var_count"
                , get_var_count_function_type( &::CvSVM::get_var_count ) );
        
        }
        { //::CvSVM::predict
        
            typedef boost::python::object ( *default_predict_function_type )( ::CvSVM const &,::cv::Mat &,bool );
            
            CvSVM_exposer.def( 
                "predict"
                , default_predict_function_type( &CvSVM_wrapper::default_predict_c02d4fcfe9f774ce1816d6b16d2df3c5 )
                , ( bp::arg("inst"), bp::arg("_sample"), bp::arg("returnDFVal")=(bool)(false) )
                , "\nArgument '_sample':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat." );
        
        }
        { //::CvSVM::predict
        
            typedef float ( ::CvSVM::*predict_function_type )( ::cv::Mat const &,bool ) const;
            typedef float ( CvSVM_wrapper::*default_predict_function_type )( ::cv::Mat const &,bool ) const;
            
            CvSVM_exposer.def( 
                "predict"
                , predict_function_type(&::CvSVM::predict)
                , default_predict_function_type(&CvSVM_wrapper::default_predict)
                , ( bp::arg("_sample"), bp::arg("returnDFVal")=(bool)(false) ) );
        
        }
        { //::CvSVM::read
        
            typedef void ( *default_read_function_type )( ::CvSVM &,::cv::FileStorage &,::cv::FileNode & );
            
            CvSVM_exposer.def( 
                "read"
                , default_read_function_type( &CvSVM_wrapper::default_read )
                , ( bp::arg("inst"), bp::arg("storage"), bp::arg("node") )
                , "\nArgument 'node':"\
    "\n    C/C++ type: ::CvFileNode *."\
    "\n    Python type: FileNode."\
    "\nArgument 'storage':"\
    "\n    C/C++ type: ::CvFileStorage *."\
    "\n    Python type: FileStorage." );
        
        }
        { //::CvSVM::train
        
            typedef boost::python::object ( *default_train_function_type )( ::CvSVM &,::cv::Mat &,::cv::Mat &,::cv::Mat,::cv::Mat,::CvSVMParams );
            
            CvSVM_exposer.def( 
                "train"
                , default_train_function_type( &CvSVM_wrapper::default_train_a051ed21e9e7670e8100d8bda1f730ea )
                , ( bp::arg("inst"), bp::arg("_train_data"), bp::arg("_responses"), bp::arg("_var_idx")=cv::Mat(), bp::arg("_sample_idx")=cv::Mat(), bp::arg("_params")=::CvSVMParams( ) )
                , "\nArgument '_sample_idx':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_train_data':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_var_idx':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_responses':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat." );
        
        }
        { //::CvSVM::train
        
            typedef bool ( ::CvSVM::*train_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::CvSVMParams ) ;
            typedef bool ( CvSVM_wrapper::*default_train_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::CvSVMParams ) ;
            
            CvSVM_exposer.def( 
                "train"
                , train_function_type(&::CvSVM::train)
                , default_train_function_type(&CvSVM_wrapper::default_train)
                , ( bp::arg("_train_data"), bp::arg("_responses"), bp::arg("_var_idx")=cv::Mat(), bp::arg("_sample_idx")=cv::Mat(), bp::arg("_params")=::CvSVMParams( ) ) );
        
        }
        { //::CvSVM::train_auto
        
            typedef boost::python::object ( *default_train_auto_function_type )( ::CvSVM &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::CvSVMParams,int,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid );
            
            CvSVM_exposer.def( 
                "train_auto"
                , default_train_auto_function_type( &CvSVM_wrapper::default_train_auto_8b5d0a3d89137f3ac15eb66fedb4914d )
                , ( bp::arg("inst"), bp::arg("_train_data"), bp::arg("_responses"), bp::arg("_var_idx"), bp::arg("_sample_idx"), bp::arg("_params"), bp::arg("k_fold")=(int)(10), bp::arg("C_grid")=CvSVM::get_default_grid(0), bp::arg("gamma_grid")=CvSVM::get_default_grid(1), bp::arg("p_grid")=CvSVM::get_default_grid(2), bp::arg("nu_grid")=CvSVM::get_default_grid(3), bp::arg("coef_grid")=CvSVM::get_default_grid(4), bp::arg("degree_grid")=CvSVM::get_default_grid(5) )
                , "\nArgument '_sample_idx':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_train_data':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_var_idx':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat."\
    "\nArgument '_responses':"\
    "\n    C/C++ type: ::CvMat const *."\
    "\n    Python type: Mat." );
        
        }
        { //::CvSVM::train_auto
        
            typedef bool ( ::CvSVM::*train_auto_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::CvSVMParams,int,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid ) ;
            typedef bool ( CvSVM_wrapper::*default_train_auto_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::CvSVMParams,int,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid,::CvParamGrid ) ;
            
            CvSVM_exposer.def( 
                "train_auto"
                , train_auto_function_type(&::CvSVM::train_auto)
                , default_train_auto_function_type(&CvSVM_wrapper::default_train_auto)
                , ( bp::arg("_train_data"), bp::arg("_responses"), bp::arg("_var_idx"), bp::arg("_sample_idx"), bp::arg("_params"), bp::arg("k_fold")=(int)(10), bp::arg("C_grid")=CvSVM::get_default_grid(0), bp::arg("gamma_grid")=CvSVM::get_default_grid(1), bp::arg("p_grid")=CvSVM::get_default_grid(2), bp::arg("nu_grid")=CvSVM::get_default_grid(3), bp::arg("coef_grid")=CvSVM::get_default_grid(4), bp::arg("degree_grid")=CvSVM::get_default_grid(5) ) );
        
        }
        { //::CvSVM::write
        
            typedef void ( *default_write_function_type )( ::CvSVM const &,::cv::FileStorage &,char const * );
            
            CvSVM_exposer.def( 
                "write"
                , default_write_function_type( &CvSVM_wrapper::default_write )
                , ( bp::arg("inst"), bp::arg("storage"), bp::arg("name") )
                , "\nArgument 'storage':"\
    "\n    C/C++ type: ::CvFileStorage *."\
    "\n    Python type: FileStorage." );
        
        }
        { //::CvStatModel::load
        
            typedef void ( ::CvStatModel::*load_function_type )( char const *,char const * ) ;
            typedef void ( CvSVM_wrapper::*default_load_function_type )( char const *,char const * ) ;
            
            CvSVM_exposer.def( 
                "load"
                , load_function_type(&::CvStatModel::load)
                , default_load_function_type(&CvSVM_wrapper::default_load)
                , ( bp::arg("filename"), bp::arg("name")=bp::object() ) );
        
        }
        { //::CvStatModel::save
        
            typedef void ( ::CvStatModel::*save_function_type )( char const *,char const * ) const;
            typedef void ( CvSVM_wrapper::*default_save_function_type )( char const *,char const * ) const;
            
            CvSVM_exposer.def( 
                "save"
                , save_function_type(&::CvStatModel::save)
                , default_save_function_type(&CvSVM_wrapper::default_save)
                , ( bp::arg("filename"), bp::arg("name")=bp::object() ) );
        
        }
        CvSVM_exposer.staticmethod( "get_default_grid" );
        CvSVM_exposer.def( bp::init< cv::Mat const &, cv::Mat const &, bp::optional< cv::Mat const &, cv::Mat const &, CvSVMParams > >(( bp::arg("_train_data"), bp::arg("_responses"), bp::arg("_var_idx")=cv::Mat(), bp::arg("_sample_idx")=cv::Mat(), bp::arg("_params")=::CvSVMParams( ) )) );
        CvSVM_exposer.def( "get_support_vector", &CvSVM_wrapper::get_support_vector_, (bp::arg("i")) );
    }

}
