#!/usr/bin/python

import sys
Dict = dict()
for line in open(sys.argv[1]):
		line = line.strip()
		if line == "":
				continue
		line = line.split()
		for item in line:
				if item in Dict.keys():
					Dict[item] += 1
				else:
					Dict[item] 
