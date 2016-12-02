#program to regularize dates
#assumes YMD will start with 4 digits and all else is MDY
import sys
import re
def sep(line):
	ndes = re.compile("\D")
	sep = ""
	for i in line:
		if ndes.match(i):
			sep = i
	return sep

def MDY(line):
	sp = sep(line)
	nums = line.split(sp)
	if len(nums[0]) < 2:
		nums[0] = "0"+nums[0]
	if len(nums[1]) < 2:
		nums[1] = "0"+nums[1]
	if len(nums[2]) == 2:
		nums[2] = "20"+nums[2]
	final = nums[2]+"-"+nums[0]+"-"+nums[1]
	print final

def YMD(line):
	sp = sep(line)
	nums = line.split(sp)
	if len(nums[2]) < 2:
		nums[2] = "0"+nums[2]
	if len(nums[1]) < 2:
		nums[1] = "0"+nums[1]
	if len(nums[0]) == 2:
		nums[0] = "20"+nums[0]
	final = nums[0]+"-"+nums[1]+"-"+nums[2]
	print final

def check(line):
	des = re.compile("\d")
	n = 0
	for i in range(0, 3):
		if des.match(line[i]):
			n += 1
	if n == 4:
		MDY(line)
	else:
		YMD(line)
			
