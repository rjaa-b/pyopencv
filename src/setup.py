﻿#!/usr/bin/env python
# PyOpenCV - A Python wrapper for OpenCV 2.0 using Boost.Python and NumPy

# Copyright (c) 2009, Minh-Tri Pham
# All rights reserved.

# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

#    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
#    * Neither the name of pyopencv's copyright holders nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# For further inquiries, please contact Minh-Tri Pham at pmtri80@gmail.com.
# ----------------------------------------------------------------------------
"""PyOpenCV - A Python wrapper for OpenCV 2.0 using Boost.Python and NumPy

PyOpenCV brings Willow Garage's Open Source Computer Vision Library (OpenCV) verion 2.0 to Python. The package takes a completely new and different approach in wrapping OpenCV than traditional swig-based and ctypes-based approaches. It is intended to be a successor of ctypes-opencv and to provide Python bindings for OpenCV 2.0. ctypes-based approaches like ctypes-opencv, while being very flexible at wrapping functions and structures, are weak at wrapping OpenCV's C++ interface. On the other hand, swig-based approaches flatten C++ classes and create countless memory management issues. In PyOpenCV, we use Boost.Python, a C++ library which enables seamless interoperability between C++ and Python. PyOpenCV will offer a better solution than both ctypes-based and swig-based wrappers:

    * Provide bindings for both the new C++ interface and the existing C interface of OpenCV 2.0,
    * Preserve C++ data structures and avoid memory management issues,
    * Run at a speed nearer to OpenCV's native speed than existing wrappers. 

In addition, we use NumPy to provide fast indexing and slicing functionality to OpenCV's arrays like Scalar, Mat, and MatND, and to offer the user an option to work with their multi-dimensional arrays in NumPy. It is well-known that NumPy is one of the best packages (if not the best) for dealing with multi-dimensional arrays in Python. OpenCV 2.0 provides a new C++ generic programming approach for matrix manipulation (i.e. MatExpr). It is a good attempt in C++. However, in Python, a package like NumPy is without a doubt a better solution. By incorporating NumPy into PyOpenCV to replace OpenCV 2.0's MatExpr approach, we seek to bring OpenCV and NumPy closer together, and offer a package that inherits the best of both world: fast computer vision functionality (OpenCV) and fast multi-dimensional array computation (NumPy). """

DOCLINES = __doc__.split("\n")

CLASSIFIERS = """\
Development Status :: 4 - Beta
Intended Audience :: Developers
Intended Audience :: End Users/Desktop
Intended Audience :: Information Technology
Intended Audience :: Science/Research
License :: OSI Approved :: BSD License
Natural Language :: English
Operating System :: OS Independent
Operating System :: Microsoft :: Windows
Operating System :: POSIX
Operating System :: Unix
Operating System :: MacOS
Programming Language :: Python
Topic :: Multimedia :: Graphics
Topic :: Multimedia :: Video
Topic :: Scientific/Engineering :: Artificial Intelligence
Topic :: Scientific/Engineering :: Human Machine Interfaces
Topic :: Software Development :: Libraries :: Python Modules
"""

from glob import glob
import os
from config import *


import ez_setup
ez_setup.use_setuptools()

import bjamcompiler
bjamcompiler.boost_dir = boost_include_dirs[0]

from setuptools import setup, find_packages, Extension

pyopencvext = Extension('pyopencv.pyopencvext',
    sources=glob(os.path.join('pyopencv', 'pyopencvext', '*.cpp')),
    include_dirs=opencv_include_dirs+boost_include_dirs+['pyopencv', 
        os.path.join('pyopencv', 'pyopencvext'), os.path.join('pyopencv', 'pyopencvext', 'numpy_include')],
    library_dirs=opencv_library_dirs+boost_library_dirs,
    libraries=opencv_libraries+boost_libraries,
    runtime_library_dirs=opencv_runtime_library_dirs+boost_runtime_library_dirs,
)

setup(
    name = "pyopencv",
	version = '2.0.0.wr1.0.0',
	description = DOCLINES[0],
	author = 'Minh-Tri Pham',
	author_email = 'pmtri80@gmail.com',
	url = 'http://code.google.com/p/pyopencv/',
	license = 'New BSD License',
	platforms = 'OS Independent, Windows, Linux, MacOS',
	classifiers = filter(None, CLASSIFIERS.split('\n')),
	long_description = "\n".join(DOCLINES[2:]),
    ext_modules=[pyopencvext],
    # install_requires = ['numpy>=1.2.0'],
    packages = find_packages(),
)

