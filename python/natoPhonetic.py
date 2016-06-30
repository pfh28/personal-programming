mapping = {
'A':'Alpha',
'B':'Bravo',
'C':'Charlie',
'D':'Delta',
'E':'Echo',
'F':'Foxtrot',
'G':'Golf',
'H':'Hotel',
'I':'India',
'J':'Juliet',
'K':'Kilo',
'L':'Lima',
'M':'Mike',
'N':'November',
'O':'Oscar',
'P':'Papa',
'Q':'Quebec',
'R':'Romeo',
'S':'Sierra',
'T':'Tango',
'U':'Uniform',
'V':'Victor',
'W':'Whiskey',
'X':'X-ray',
'Y':'Yankee',
'Z':'Zulu'
}
inpt = "yes, no, maybe"
for char in inpt:
	if char.isalpha():
		print mapping[char.upper()],
	else:
		print char,