jurov
=====

jurov is a compiler for the MiniJava language (see documentation for grammar).

Dependencies
------------
* [Python](http://www.python.org/) >= 2.3 or 
  [Jython](http://www.jython.org/) >= 2.5
* [bison](http://www.gnu.org/software/bison/) and 
* [flex](http://flex.sourceforge.net/)

Building
--------
First, make sure that you have the dependences listed above installed.
Then, to build jurov, simply run
    ./waf configure build

To remove all the binaries produced by the build, run
    ./waf distclean

Tests
-----
jurov uses the (CuTest)[http://cutest.sourceforge.net/] as its 
unit tests framework. Since CuTest is so small, it is bundled 
together with jurov. To run all the unit test, just run
    ./waf configure build --test

Documentation
-------------
jurov uses (Sphinx)[http://sphinx.pocoo.org/] for all its documentation. 
To use Sphinx, you need to have Python >= 2.4 (it does not currently work 
with Jython). To install Sphinx, you need to have 
(setuptools)[http://pypi.python.org/pypi/setuptools] installed. Once 
setuptools is installed, run
    easy_install -U Sphinx
to install Sphinx. Once Sphinx is installed, run
    cd doc/
    sphinx-build -b html source build
Now open doc/build/index.html in your favorite browser to read the 
documentation!
