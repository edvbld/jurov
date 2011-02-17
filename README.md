jurov
=====

jurov is a compiler for the MiniJava language. Is is written in C and 
should compile on Mac OS X and Linux.

For an introduction to MiniJava, see the documentation.

Dependencies
------------
* [Python](http://www.python.org/) >= 2.3 or 
  [Jython](http://www.jython.org/) >= 2.5
* [bison](http://www.gnu.org/software/bison/) 
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
jurov uses [CuTest](http://cutest.sourceforge.net/) as its 
unit tests framework. Since CuTest is so small, it is bundled 
together with jurov. To run all the unit test, just run
    ./waf configure build --test

Documentation
-------------
jurov uses [Doxygen](http://www.stack.nl/~dimitri/doxygen/) for all its 
documentation. To build the documentation you first need to install 
Doxygen. When doxygen is installed, run
    cd doc/ && doxygen

To view the documentation, just open 
    doc/build/html/index.html

with your favorite browser.

License
-------
jurov is licensed under the BSD license (3-clause BSD), see the LICENSE file 
for more details.
