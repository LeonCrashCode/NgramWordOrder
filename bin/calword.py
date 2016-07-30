#!/usr/bin/python

import sys
cnt = 0
Dict = dict()
for line in open(sys.argv[1]):
		line = line.strip()
		if line == "":
				continue
		line = line.split()
		cnt += len(line)
		for item in line:
				Dict[item] = 1
print cnt
print len(Dict)
