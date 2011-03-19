import os.path
import platform
import Options

APPNAME = 'jurov' 
VERSION = '0.1'
out = 'build'
top = '.'

def options(opt):
    opt.load('compiler_c')
    opt.add_option('--spec', action = 'store_true', default = False, 
                   help = 'Runs all the speficications')
    opt.add_option('--valgrind', action = 'store_true', default = False,
                   help = 'Runs all the specifications in valgrind')
    opt.add_option('--integration', action = 'store_true', default = False,
                   help = 'Runs all the integration tests')

def run_valgrind(bld):
    print "Starting to run valgrind"
    run_all_specs = '{0}/test/spec/run_all_specs'.format(os.path.abspath(out))
    if platform.system() == 'Darwin':
        cmd = 'valgrind --dsymutil=yes '
    else:
        cmd = 'valgrind '
    cmd += ('-q --leak-check=full --error-exitcode=1 ' + run_all_specs)
    res = bld.exec_command(cmd)
    if res != 0:
        bld.fatal("Memory leaks detected!")

def run_specs(bld):
    print "Starting to run specs"
    run_all_specs = '{0}/test/spec/run_all_specs'.format(os.path.abspath(out))
    res = bld.exec_command(run_all_specs)
    if res != 0:
        bld.fatal("The specifications were not fulfilled!")

def run_integration(bld):
    print "Starting to run integration tests"
    cmd = 'python test/integration/runner.py'
    res = bld.exec_command(cmd)
    if res != 0:
        bld.fatal("The integration tests did not pass!")

def configure(conf):
    conf.env.CFLAGS = ['-g', '-Wall', '-Werror', '-ansi', '-pedantic']
    conf.env.FLEXFLAGS = ['--header-file=src/lex.yy.h']
    conf.env.INCLUDE_SPECS = os.path.abspath('test/spec')
    conf.env.INCLUDE_SPECTACULAR = os.path.abspath('lib/spectacular')
    conf.env.INCLUDE_GENERATED_SRC = os.path.abspath('{0}/src'.format(out))
    conf.env.INCLUDE_SRC = os.path.abspath('src')
    try:
        conf.find_program('valgrind')
    except conf.errors.ConfigurationError:
        conf.to_log("Could not find valgrind, memory leaks won't be checked!")
        conf.env.VALGRIND = False
    conf.load('compiler_c')
    conf.load('flex')
    conf.load('bison')

def build(bld):
    bld.recurse(['lib', 'src', 'test'])
    if Options.options.spec:
        bld.add_post_fun(run_specs)
    if Options.options.valgrind and bld.env.VALGRIND:
        bld.add_post_fun(run_valgrind)
    if Options.options.integration:
        bld.add_post_fun(run_integration)
