import sys
sys.path.append("..")
from PIL import Image, ImageFilter
from suiteIO import get_option_index_input, ask_YN, prompt_input

myImage = Image.open("image1.png")
myImage.load

print("Image details: ")
print(myImage.format, myImage.size, myImage.mode)

choice = get_option_index_input("What would you like to do?",
						["Blur", "Contour", "Detail", "Edge enhance",
						"Edge enhance more", "Emobss", "Find edges", 
						"Smooth", "Smooth more", "Sharpen"])
filter_dict = {1:ImageFilter.BLUR, 2:ImageFilter.CONTOUR, 3:ImageFilter.DETAIL,
				3:ImageFilter.EDGE_ENHANCE, 4:ImageFilter.EDGE_ENHANCE_MORE,
				5:ImageFilter.EMBOSS, 6:ImageFilter.FIND_EDGES, 7:ImageFilter.FIND_EDGES,
				8:ImageFilter.SMOOTH, 9:ImageFilter.SMOOTH_MORE, 10:ImageFilter.SHARPEN}
modified = myImage.filter(filter_dict[choice])

print("unfiltered image:")
myImage.show()			#required associating .bmp with paint (windows)
print("filtered image:")
modified.show()

if ask_YN("Save filtered image?"):
	filename = prompt_input("Filename:")
	filename += ".jpg"						#png wasn't working
	modified.save(filename)
	