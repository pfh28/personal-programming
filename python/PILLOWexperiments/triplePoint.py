import sys
sys.path.append("..")
from PIL import Image
from suiteIO import get_option_index_input, ask_YN, prompt_input

def avg(tupe):
	return (tupe[0]+tupe[1])/2

myImage = Image.new('RGB',(300, 300))
pixels = myImage.load()
for c in range(myImage.size[0]):
	for r in range(myImage.size[1]):
		pixels[c,r] = (r, c, avg(myImage.size)-(r+c))
myImage.show()