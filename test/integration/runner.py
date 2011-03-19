import os
import os.path
import sys
import parser.runner

def run():
    d = os.path.split(os.path.abspath(__file__))[0]
    d += '/sample_programs/'
    samples = [os.path.abspath(d + 'Factorial.java')]
    cmd = './build/src/jurov'
    res = parser.runner.run(cmd, samples)
    if res:
        sys.exit(0)
    else:
        sys.exit(1)

if __name__ == '__main__':
    run()
