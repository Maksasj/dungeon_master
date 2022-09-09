from PIL import Image
import sys

def rgbHex(r, g, b):
    return ((r)+((g)<<5)+((b)<<10)) 

class Converter:
    def __init__(self, imagePath):
        self.imagePath = imagePath
        self.output = []

    def Convert(self):
        img = Image.open("C:\Programming\c\dungeon-master\scripts\image.png")
        pixels = img.load()

        for i in range(img.size[0]):
            for j in range(img.size[1]):
                r, g, b = pixels[i,j]
                self.output.append(hex(rgbHex(r, g, b)))
                print(hex(rgbHex(r, g, b)))

        print(len(self.output))

    def SaveFile(self, savePath):
        f = open(savePath, "w")
        f.write("const u16 image["+str(len(self.output))+"] = {")
        
        for i in self.output:
            f.write(str(i)+",")
        f.write("};")
        f.close()

convert = Converter(sys.argv[0])
convert.Convert()
convert.SaveFile("C:\\Programming\\c\\dungeon-master\\scripts\\test.txt")