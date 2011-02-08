import os.path

APPNAME = 'jurov' 
VERSION = '0.1'
out = 'build'
top = '.'

def options(opt):
    opt.load('compiler_cxx')
    opt.load('compiler_c')

def configure(conf):
    conf.env.C_FLAGS = ['-g', '-Wall', '-ansi', '-pedantic', '-std=c89']
    conf.env.FLEXFLAGS = ['--header-file=src/lex.yy.h']
    conf.env.INCLUDE_CUTEST = os.path.abspath('lib/cutest-1.5')
    conf.env.INCLUDE_SRC = os.path.abspath('build/src')
    conf.load('compiler_c')
    conf.load('flex')
    conf.load('bison')

def build(bld):
    bld.recurse(['src', 'tests', 'lib'])
