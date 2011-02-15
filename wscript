import os.path
import Options

APPNAME = 'jurov' 
VERSION = '0.1'
out = 'build'
top = '.'

def options(opt):
    opt.load('compiler_c')
    opt.add_option('--test', action = 'store_true', default = False, 
                   help = 'Runs the unit tests')

def run_tests(bld):
    bld.exec_command('{0}/tests/run_all_tests'.format(os.path.abspath(out)))

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
    if Options.options.test:
        bld.add_post_fun(run_tests)
