#test progrm that reassigns the existing color intensities for each pixel as specified.

import sys
sys.path.append("..")
from PIL import Image
from suiteIO import get_option_index_input, ask_YN, prompt_input

def order_triple(trip):
	return tuple(sorted(trip, reverse = True))

def RGB_Order(img, priority="RGB"):
	pixels = img.load()
	for c in range(img.size[0]):
		for r in range(img.size[1]):
			pix = order_triple(pixels[c,r][0:3])
			priorts = {"RGB":pix, "RBG":(pix[0], pix[2], pix[1]), "GRB":(pix[1], pix[0], pix[2]),
						"GBR":(pix[2], pix[0], pix[1]), "BRG":(pix[1], pix[2], pix[0]),
						"BGR":(pix[2], pix[1], pix[0]), "MIN":(pix[0], pix[0], pix[0]),
						"MID":(pix[1], pix[1], pix[1]), "MAX":(pix[2], pix[2], pix[2])}
			pixels[c,r] = priorts[priority]

image = Image.open("image1.png")

RGB_Order(image)
image.show()