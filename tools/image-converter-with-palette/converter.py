from ast import arg
from PIL import Image
import sys
import os

def getColor(r, g, b):
    return rgbHex(int((r/255)*31), int((g/255)*31), int((b/255)*31))

def rgbHex(r, g, b):
    return ((r)+((g)<<5)+((b)<<10)) 

def unique(input):
    unique_list = []
  
    for x in input:
        if x not in unique_list:
            unique_list.append(x)
    
    return unique_list

class Converter:
    def __init__(self):
        self.output = []
        self.pallet = []
        
        imageWidth = 0
        imageHeight = 0

    def Convert(self, imagePath):
        img = Image.open(imagePath)

        # Lets check if image is proper for conversion
        assert(img.size[1] % 8 == 0)
        assert(img.size[0] % 8 == 0)

        self.imageWidth = img.size[0]
        self.imageHeight = img.size[1]

        # img.size[0] width
        # img.size[1] height

        # Loading pixels
        pixels = img.load()

        # Getting amount of tiles
        p1 = img.size[0] // 8
        p2 = img.size[1] // 8
        
        tiles = {}

        for i in range(p1*p2):
            tile = []
            tiles[i] = tile

        for i in range(img.size[1]):
            for j in range(img.size[0]):
                r, g, b, a= pixels[j,i]

                index = (j // 8) + (i // 8)*p1

                print("("+str(i)+", "+str(j)+") -> "+str(index))
                tiles[index].append(getColor(r, g, b))
                self.pallet.append(getColor(r, g, b))

        list_sample = unique(self.pallet);
        self.pallet = list_sample
        
        for i in range(p1*p2):
            for j in tiles[i]:
                self.output.append(self.pallet.index(j))

    def SaveFile(self, savePath):
        f = open(savePath, "w")

        f.write("\n")
        f.write("#define image_width "+str(self.imageWidth)+"\n")
        f.write("#define image_height "+str(self.imageHeight)+"\n")
        f.write("\n")
        f.write("const unsigned char image_data[] = { \n    ")
        
        I = 0
        for i, var in enumerate(self.output):
            f.write(str("0x{:02x}".format(var)))

            I += 1
            if i + 1 != len(self.output):
                f.write(", ")
            if (I % 12 == 0) and (i + 1 != len(self.output)):
                f.write("\n    ")
            
        f.write("\n};\n")

        f.write("\n")

        while len(self.pallet) < 256:
            self.pallet.append(0)

        f.write("const unsigned short image_palette[] = { \n    ")
        I = 0
        for i, var in enumerate(self.pallet):
            f.write(str("0x{:04x}".format(var)))

            I += 1
            if i + 1 != len(self.pallet):
                f.write(" ,")
            if (I % 9 == 0) and (i + 1 != len(self.pallet)):
                f.write("\n    ")
        f.write("\n};\n")

        f.close()

convert = Converter()
if sys.argv:
    convert.Convert("..\\..\\assets\\raw\\sprites.png")
    convert.SaveFile("..\\..\\assets\\generated\\sprites.h")
else:
    convert.Convert(sys.argv[0])
    convert.SaveFile(sys.argv[1])