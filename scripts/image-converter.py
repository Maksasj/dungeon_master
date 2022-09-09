from ast import arg
from PIL import Image
import sys
import os

def rgbHex(r, g, b):
    return ((r)+((g)<<5)+((b)<<10)) 

class Converter:
    def __init__(self):
        self.output = []
        self.imageSize = ()

    def Convert(self, imagePath):
        img = Image.open(imagePath)
        pixels = img.load()

        self.imageSize = (img.size[0], img.size[1])

        for i in range(img.size[0]):
            for j in range(img.size[1]):
                r, g, b, a = pixels[i,j]
                self.output.append(hex(rgbHex(int((r/255)*31), int((g/255)*31), int((b/255)*31))))

    def SaveFile(self, savePath):
        f = open(savePath, "w")
        f.write("const unsigned short image["+str(len(self.output))+"] = { \n    ")
        
        I = 0
        for i, var in enumerate(self.output):
            f.write(str(var))

            I += 1
            if i + 1 != len(self.output):
                f.write(",")
            if (I % self.imageSize[0] == 0) and (i + 1 != len(self.output)):
                f.write("\n    ")
            
        f.write("\n};\n")
        f.close()

convert = Converter()
if sys.argv:
    convert.Convert(os.getcwd()+"\\assets\\image.png")
    convert.SaveFile(os.getcwd()+"\\src\\image.h")
else:
    convert.Convert(sys.argv[0])
    convert.SaveFile(sys.argv[1])
