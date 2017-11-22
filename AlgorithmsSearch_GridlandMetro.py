
## AlgorithmsSearch_GridlandMetro

import collections
print collections.Counter(['a', 'b', 'c', 'a', 'b', 'b'])

import reduce
lst = range(5)
reduce(lambda x,y : x*y, lst) 
reduce

import functools
functools.reduce(lambda x,y : x*y, lst) 


"aa bb cc 111".rsplit(None,1)[1]

functools.reduce(lambda x,y : [y] + x , range(5),[]) 

import re
pat = re.compile(r"(?P<c>(P<a>[A-Z][A-Za-z]*)\s* (P<b>[A-Z][A-Za-z]*) )")
x = pat.match("Oliver Twist by Charles Dickens")
x.group('b')

range(0,5)
xrange(0,5)
