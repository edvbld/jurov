APPNAME = 'jurov' 
VERSION = '0.1'
out = 'build'
top = '.'

def options(opt):
    opt.load('compiler_cxx')
    opt.load('compiler_c')

def configure(conf):
    flags = ['-g', '-Wall']
    conf.env.CXX_FLAGS = flags
    conf.env.C_FLAGS = flags
    conf.env.FLEXFLAGS = ['--header-file=lex.yy.h']
    conf.load('compiler_cxx')
    conf.load('compiler_c')
    conf.load('flex')
    conf.load('bison')

def build(bld):
    print(bld.env.FLEXFLAGS)
    bld.recurse(['src', 'tests'])
