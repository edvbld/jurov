import os.path
import os

def run(cmd, files):
    res = True;
    d = os.path.split(os.path.abspath(__file__))[0]
    for p in files:
        fname = os.path.split(p)[1]
        fname = fname.replace('java', 'syntax')
        exp = open((d + '/' + fname), 'r').read()
        output = os.popen((cmd + ' ' + p)).read()
        res = ((output == exp) and res)
    return res
