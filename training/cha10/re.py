import re

key = "the sum of 7 and 9 is [7+9]."
p1 = r"s.m"
pattern = re.compile(p1)
resul = re.findall(pattern,key)
print resul
