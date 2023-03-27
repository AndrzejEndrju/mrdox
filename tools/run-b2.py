import subprocess
import re
import sys
import os
import json
import os.path

cwd = os.getcwd()
ll = subprocess.Popen(
    sys.argv[1:] + ['-n'],
    stdout=subprocess.PIPE
).stdout.readlines()

rc = re.compile("^([^.]+)\.compile\.c(?:\+\+)? ([^\n]+)$")

tc = re.compile('.*"((?:\\"|[^"])+)"$')

res = []

i = 0
while i < len(ll):
    m = rc.match(ll[i].decode())
    if m:
        output = m[2]
        i += 2
        command = ll[i].strip().decode()
        file = tc.match(command)[1]
        res.append({
            "directory": cwd,
            "command":  command,
            "file":     os.path.abspath(file),
            "output":   os.path.abspath(output)
        })
    i += 1

json.dump(res, sys.stdout, indent=1)