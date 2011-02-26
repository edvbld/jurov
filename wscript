import os.path
import Options

APPNAME = 'jurov' 
VERSION = '0.1'
out = 'build'
top = '.'

def options(opt):
    opt.load('compiler_c')
    opt.add_option('--spec', action = 'store_true', default = False, 
                   help = 'Runs all the speficications')

def run_specs(bld):
    cmd = '{0}/specs/run_all_specs'.format(os.path.abspath(out))
    res = bld.exec_command(cmd)
    if res != 0:
        bld.fatal("The specifications were not fulfilled!")

def configure(conf):
    conf.env.C_FLAGS = ['-g', '-Wall', '-ansi', '-pedantic']
    conf.env.FLEXFLAGS = ['--header-file=src/lex.yy.h']
    conf.env.INCLUDE_SPECS = os.path.abspath('specs')
    conf.env.INCLUDE_SPECTACULAR = os.path.abspath('lib/spectacular')
    conf.env.INCLUDE_GENERATED_SRC = os.path.abspath('{0}/src'.format(out))
    conf.env.INCLUDE_SRC = os.path.abspath('src')
    conf.load('compiler_c')
    conf.load('flex')
    conf.load('bison')

def build(bld):
    bld.recurse(['lib', 'src', 'specs'])
    if Options.options.spec:
        bld.add_post_fun(run_specs)
