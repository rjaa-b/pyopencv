#!/usr/bin/env python
# PyOpenCV - A Python wrapper for OpenCV 2.x using Boost.Python and NumPy

# Copyright (c) 2009, Minh-Tri Pham
# All rights reserved.

# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

#    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
#    * Neither the name of pyopencv's copyright holders nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# For further inquiries, please contact Minh-Tri Pham at pmtri80@gmail.com.
# ----------------------------------------------------------------------------

import os.path as _op
import os as _os
import sys as _sys
from pygccxml import declarations as _D
import pyplusplus as _pp
from pyplusplus.module_builder import call_policies as _CP
import common as _c
import function_transformers as _FT
import memvar_transformers as _MT


class SdModuleBuilder:
    FT = _FT
    MT = _MT
    D = _D
    CP = _CP

    mb = None
    cc = None
    funs = None

    dummy_struct = None
    def add_reg_code(self, s):
        if self.dummy_struct:
            self.dummy_struct._reg_code += "\n        "+s


    def __init__(self, module_name, include_paths=[]):
        self.module_name = module_name

        # package directory
        self.pkg_dir = _op.join(_op.split(_op.abspath(__file__))[0], '..', 'src', 'package')

        # create an instance of class that will help you to expose your declarations
        self.mb = _pp.module_builder.module_builder_t([module_name+"_wrapper.hpp"],
            gccxml_path=r"M:/utils/gccxml/bin/gccxml.exe",
            include_paths=include_paths+[
                self.pkg_dir+"/"+module_name+"_ext",
                r"M:\programming\builders\MinGW\gcc\gcc-4.4.0-mingw\lib\gcc\mingw32\4.4.0\include\c++",
                r"M:\programming\builders\MinGW\gcc\gcc-4.4.0-mingw\lib\gcc\mingw32\4.4.0\include\c++\mingw32",
                r"M:\programming\builders\MinGW\gcc\gcc-4.4.0-mingw\lib\gcc\mingw32\4.4.0\include",
            ])

        # create a Python file
        self.cc = open(_op.join(self.pkg_dir, self.module_name+'.py'), 'w')
        self.cc.write('''#!/usr/bin/env python
# PyOpenCV - A Python wrapper for OpenCV 2.x using Boost.Python and NumPy

# Copyright (c) 2009, Minh-Tri Pham
# All rights reserved.

# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

#    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
#    * Neither the name of pyopencv's copyright holders nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# For further inquiries, please contact Minh-Tri Pham at pmtri80@gmail.com.
# ----------------------------------------------------------------------------

import common as _c
import MODULE_NAME_ext as _ext
from MODULE_NAME_ext import *
        '''.replace("MODULE_NAME", module_name))

        # Well, don't you want to see what is going on?
        # self.mb.print_declarations() -- too many declarations

        # Disable every declarations first
        self.mb.decls().exclude()

        # disable some warnings
        # self.mb.decls().disable_warnings(messages.W1027, messages.W1025)

        # expose 'this'
        self.mb.classes().expose_this = True

        # expose all enumerations
        self.mb.enums().include()

        # except some weird enums
        for z in ('_', 'VARENUM', 'GUARANTEE', 'NLS_FUNCTION', 'POWER_ACTION',
            'PROPSETFLAG', 'PROXY_PHASE', 'PROXY_PHASE', 'SYS', 'XLAT_SIDE',
            'STUB_PHASE',
            ):
            try:
                self.mb.enums(lambda x: x.name.startswith(z)).exclude()
            except RuntimeError:
                pass
        for z in ('::std', '::tag'):
            try:
                self.mb.enums(lambda x: x.decl_string.startswith(z)).exclude()
            except RuntimeError:
                pass

        # add 'pds' attribute to every class
        for z in self.mb.classes():
            z.pds = unique_pds(z.partial_decl_string)

        # dummy struct
        z = self.mb.class_(module_name+"_dummy_struct")
        self.dummy_struct = z
        z.include()
        z.decls().exclude()
        z.class_('dummy_struct2').include()
        z.rename("__"+z.name)
        z._reg_code = ""

        # turn on 'most' of the constants
        for z in ('IPL_', 'CV_'):
            try:
                self.mb.decls(lambda decl: decl.name.startswith(z)).include()
            except RuntimeError:
                pass

        # initialise the list of free functions
        try:
            self.funs = self.mb.free_funs()
        except RuntimeError:
            self.funs = []
        _c.init_transformers(self.funs)
        
        # make sure size_t is still size_t -- for 64-bit support
        z = self.mb.decl('size_t')
        z.type = _FT.size_t_t()




    def done(self):
        # update registration code
        self.prepare_decls_registration_code()

        # rename functions that starts with 'cv'
        for z in self.funs:
            if z.alias[:2] == 'cv'and z.alias[2].isupper():
                zz = z.alias[2:]
                if len(zz) > 1 and zz[1].islower():
                    zz = zz[0].lower()+zz[1:]
                # print "Old name=", z.alias, " new name=", zz
                z.rename(zz)

        # beautify free functions
        beautify_func_list(self.funs)

        # expose std::vector, only those with alias starting with 'vector_'
        # remember to create operator==() for each element type
        for z in self.mb.classes(lambda x: x.pds.startswith('std::vector<')):
            # check if the class has been registered
            try:
                t = self.get_registered_decl(z.partial_decl_string)
                elem_type = t[1]
                t = self.get_registered_decl(elem_type) # to make sure element type is also registered
            except:
                z.exclude()
                z.set_already_exposed(True)
                continue
            z.include()
            z.add_declaration_code('static inline void resize(%s &inst, size_t num) { inst.resize(num); }' \
                % z.partial_decl_string)
            z.add_registration_code('def("resize", &::resize, ( bp::arg("num") ))')
            self.cc.write('''
CLASS_NAME.__old_init__ = CLASS_NAME.__init__
CLASS_NAME.__init__ = _c.__vector__init__
CLASS_NAME.create = _c.__vector_create
CLASS_NAME.__repr__ = _c.__vector__repr__
CLASS_NAME.tolist = _c.__vector_tolist
CLASS_NAME.fromlist = classmethod(_c.__vector_fromlist)
_z = CLASS_NAME()
_z.resize(1)
CLASS_NAME.elem_type = _z[0].__class__
del(_z)
            '''.replace('CLASS_NAME', z.alias))
            # add conversion between vector and ndarray
            if _FT.is_elem_type_fixed_size(elem_type):
                self.dummy_struct.include_files.append('ndarray.hpp')
                self.add_reg_code('bp::def("asndarray", &sdcpp::vector_to_ndarray2< ELEM_TYPE >, (bp::arg("inst_CLASS_NAME")) );' \
                    .replace('CLASS_NAME', z.alias).replace('ELEM_TYPE', elem_type))
                self.add_reg_code('bp::def("asCLASS_NAME", &sdcpp::ndarray_to_vector2< ELEM_TYPE >, (bp::arg("inst_ndarray")) );' \
                    .replace('CLASS_NAME', z.alias).replace('ELEM_TYPE', elem_type))

        # dummy struct
        self.dummy_struct.add_registration_code('''setattr("v0", 0);
    }
    {
        %s''' % self.dummy_struct._reg_code)


        # ----------
        # BUILD CODE
        # ----------

        self.mb.build_code_creator(self.module_name+"_ext")

        # hack os.path.normcase
        _old_normcase = _op.normcase
        def _new_normcase(s):
            return s
        _op.normcase = _new_normcase

        # change current directory
        _cwd = _os.getcwd()
        _os.chdir(self.pkg_dir)

        # write code to file.
        self.mb.split_module(self.module_name+"_ext")

        # return current directory
        _os.chdir(_cwd)

        # return old normcase
        _op.normcase = _old_normcase


    # ==================
    # class registration
    # ==================
    decls_reg = {}

    def prepare_decls_registration_code(self):
        str = '''#ifndef SD_MODULE_NAME_TEMPLATE_INSTANTIATIONS_HPP
#define SD_SD_MODULE_NAME_TEMPLATE_INSTANTIATIONS_HPP

class MODULE_NAME_dummy_struct {
public:
    struct dummy_struct2 {};
    static const int total_size = 0'''.replace("MODULE_NAME", self.module_name)

        pdss = self.decls_reg.keys()
        for i in xrange(len(pdss)):
            if '<' in pdss[i]: # only instantiate those that need to
                str += '\n        + sizeof(%s)' % pdss[i]

        str += ''';
};

#endif
'''
        filename = self.module_name+'_template_instantiations.hpp'
        if _c.update_file(_op.join(self.pkg_dir, self.module_name+"_ext", filename), str):
            print "Warning: File '%s' has been modified. Re-run the generator." % filename
            _sys.exit(0)

    # get information of a registered class
    def get_registered_decl(self, pds):
        upds = unique_pds(pds)
        try:
            return self.decls_reg[upds]
        except KeyError:
            raise ValueError("Class of pds '%s' has not been registered." % pds)

    def get_registered_decl_name(self, pds):
        upds = unique_pds(pds)
        try:
            return self.decls_reg[upds][0]
        except KeyError:
            return "(C++)"+upds

    def find_classes(self, pds):
        pds = unique_pds(pds)
        return self.mb.classes(lambda x: x.pds==pds)

    def find_class(self, pds):
        pds = unique_pds(pds)
        return self.mb.class_(lambda x: x.pds==pds)

    # pds = partial_decl_string without the preceeding '::'
    def register_decl(self, pyName, pds, cChildName_pds=None, pyEquivName=None):
        upds = unique_pds(pds)
        if upds in self.decls_reg:
            # print "Declaration %s already registered." % pds
            return upds
        if '::' in pds: # assume it is a class
            print "Registration: %s ==> %s..." % (upds, pyName)
            try:
                self.find_class(upds).rename(pyName)
            except RuntimeError:
                # print "Class %s does not exist." % pds
                pass
        self.decls_reg[upds] = (pyName, unique_pds(cChildName_pds), pyEquivName)
        return upds

    # vector template instantiation
    # cName_pds : C name of the class without template element(s)
    # cChildName_pds : C name of the class without template element(s)
    # e.g. if partial_decl_string is '::std::vector<int>' then
    #    cName_pds='std::vector'
    #    cChildName_pds='int'
    def register_vec(self, cName_pds, cChildName_pds, pyName=None, pds=None, pyEquivName=None):
        cupds = unique_pds(cChildName_pds)
        if pyName is None:
            pyName = cName_pds[cName_pds.rfind(':')+1:] + '_' + self.decls_reg[cupds][0]
        if pds is None:
            pds = cName_pds + '< ' + cChildName_pds + ' >'
        return self.register_decl(pyName, pds, cupds, pyEquivName)

    # non-vector template instantiation
    # cName_pds : C name of the class without template element(s)
    # cElemNames_pds : list of the C names of the template element(s)
    # numbers are represented as int, not as str
    # e.g. if partial_decl_string is '::cv::Vec<int, 4>' then
    #    cName_pds='cv::Vec'
    #    cChildName_pds=['int', 4]
    def register_ti(self, cName_pds, cElemNames_pds=[], pyName=None, pds=None):
        if pyName is None:
            pyName = cName_pds[cName_pds.rfind(':')+1:]
            for elem in cElemNames_pds:
                pyName += '_' + (str(elem) if isinstance(elem, int) else self.decls_reg[unique_pds(elem)][0])
        if pds is None:
            pds = cName_pds
            if len(cElemNames_pds)>0:
                pds += '< '
                for elem in cElemNames_pds:
                    pds += (str(elem) if isinstance(elem, int) else elem) + ', '
                pds = pds[:-2] + ' >'
        return self.register_decl(pyName, pds)

    def get_decl_equivname(self, pds):
        z = self.decls_reg[unique_pds(pds)]
        if z[2] is not None:
            return z[2]
        if z[1] is not None:
            return "list of "+get_decl_equivname(z[1])
        return z[0]



def beautify_func_list(func_list):
    func_list = [f for f in func_list if not f.ignore]

    # fix default values
    # don't remove std::vector default values, old compilers _need_ std::allocator removed
    for f in func_list:
        for arg in f.arguments:
            if isinstance(arg.default_value, str):
                repl_list = {
                    'std::basic_string<char, std::char_traits<char>, std::allocator<char> >': 'std::string',
                    'std::vector<cv::Point_<int>, std::allocator<cv::Point_<int> > >': 'std::vector<cv::Point>',
                    'std::vector<cv::Scalar_<double>, std::allocator<cv::Scalar_<double> > >': 'std::vector<cv::Scalar>',
                    'std::vector<int, std::allocator<int> >': 'std::vector<int>',
                    'std::vector<cv::Vec<int, 4>, std::allocator<cv::Vec<int, 4> > >': 'std::vector<cv::Vec4i>',
                }
                for z in repl_list:
                    arg.default_value = arg.default_value.replace(z, repl_list[z])

    # one-to-one function argument
    for f in func_list:
        for arg in f.arguments:
            if is_arg_touched(f, arg.name):
                continue
            pds = common.unique_pds(arg.type.partial_decl_string)
            if pds in common.c2cpp:
                f._transformer_creators.append(FT.input_as_FixType(pds, common.c2cpp[pds], arg.name))
            elif pds in ['CvRNG *', 'CvRNG &', 'CvRNG cosnt *', 'CvRNG const &']:
                f._transformer_creators.append(FT.input_asRNG(arg.name))
            elif pds in ['CvFileStorage *', 'CvFileStorage const *']:
                f._transformer_creators.append(FT.input_as_FileStorage(arg.name))
            elif pds in ['CvFileNode *', 'CvFileNode const *']:
                f._transformer_creators.append(FT.input_as_FileNode(arg.name))
            elif pds in ['CvMemStorage *', 'CvMemStorage const *']:
                f._transformer_creators.append(FT.input_as_MemStorage(arg.name))
            elif pds in ['CvSparseMat *', 'CvSparseMat &', 'CvSparseMat const *', 'CvSparseMat const &']:
                f._transformer_creators.append(FT.input_asSparseMat(arg.name))
            elif pds in ["IplImage *", "IplImage const *", "CvArr *", "CvArr const *",
                "CvMat *", "CvMat const *", "cv::Range const *"]:
                f._transformer_creators.append(FT.input_as_Mat(arg.name))

    # function argument int *sizes and int dims
    for f in func_list:
        for arg in f.arguments:
            if is_arg_touched(f, arg.name):
                continue
            if arg.name == 'sizes' and D.is_pointer(arg.type):
                for arg2 in f.arguments:
                    if arg2.name == 'dims' and D.is_integral(arg2.type):
                        f._transformer_creators.append(FT.input_array1d('sizes', 'dims'))
                        break
            if arg.name == '_sizes' and D.is_pointer(arg.type):
                for arg2 in f.arguments:
                    if arg2.name == '_ndims' and D.is_integral(arg2.type):
                        f._transformer_creators.append(FT.input_array1d('_sizes', '_ndims'))
                        break
                    if arg2.name == 'dims' and D.is_integral(arg2.type):
                        f._transformer_creators.append(FT.input_array1d('_sizes', 'dims'))
                        break
            if arg.name == '_newsz' and D.is_pointer(arg.type):
                for arg2 in f.arguments:
                    if arg2.name == '_newndims' and D.is_integral(arg2.type):
                        f._transformer_creators.append(FT.input_array1d('_newsz', '_newndims'))
                        break

    # function argument const CvPoint2D32f * src and const CvPoint2D32f * dst
    for f in func_list:
        for arg in f.arguments:
            if is_arg_touched(f, arg.name):
                continue
            if arg.name == 'src' and D.is_pointer(arg.type) and 'CvPoint2D32f' in arg.type.decl_string:
                for arg2 in f.arguments:
                    if arg2.name == 'dst' and D.is_pointer(arg2.type) and 'CvPoint2D32f' in arg2.type.decl_string:
                        f._transformer_creators.append(FT.input_array1d('src'))
                        f._transformer_creators.append(FT.input_array1d('dst'))
                        break

    #  argument 'void *data'
    for f in func_list:
        for arg in f.arguments:
            if is_arg_touched(f, arg.name):
                continue
            if arg.name == 'data' and D.is_void_pointer(arg.type):
                f._transformer_creators.append(FT.input_string(arg.name))
                mb.add_doc(f.name, "'data' is represented by a string")

    # final step: apply all the function transformations
    for f in func_list:
        if len(f._transformer_creators) > 0:
            sort_transformers(f)

            f.add_transformation(*f._transformer_creators, **f._transformer_kwds)
            if 'unique_function_name' in f._transformer_kwds:
                f.transformations[0].unique_name = f._transformer_kwds['unique_function_name']
            else:
                s = f.transformations[0].unique_name
                repl_dict = {
                    'operator()': '__call__',
                }
                for t in repl_dict:
                    if t in s:
                        s = s.replace(t, repl_dict[t])
                        f.transformations[0].unique_name = s
                        f.transformations[0].alias = repl_dict[t]
                        break

        common.add_decl_desc(f)


# get a unique pds
def unique_pds(pds):
    if pds is None:
        return None
    if pds.startswith('::'):
        pds = pds[2:]
    pds = pds.replace('< ', '<').replace(', ', ',')
    while True:
        i = pds.find(' >')
        if i<0:
            break
        if i>0 and pds[i-1]=='>':
            pds = pds[:i-1]+'>SDSD>'+pds[i+2:]
        else:
            pds = pds[:i]+'>'+pds[i+2:]
    return pds.replace('SDSD', ' ')
