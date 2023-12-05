from rembg import remove
from PIL import Image

image_name = input("Digite o nome da imagem: ")

inputPath = "images/" + image_name

output_name = "rmBG-" + image_name.rsplit('.', 1)[0] + ".png"
outputPath = "images/" + output_name

input_image = Image.open(inputPath)

output = remove(input_image)

output.save(outputPath, 'PNG')

print(f"Imagem salva em: {outputPath}")
