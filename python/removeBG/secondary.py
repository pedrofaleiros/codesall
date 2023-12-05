from rembg import remove
import easygui
from PIL import Image

inputPath = easygui.fileopenbox(title='Selecionar imagem')

if not inputPath:
    exit("Nenhuma imagem selecionada.")

base_name = inputPath.rsplit('/', 1)[-1].rsplit('.', 1)[0]

suggested_output_name = base_name + "-rmBG.png"

outputPath = easygui.filesavebox(title='Salvar imagem', default=suggested_output_name, filetypes=["*.png"])

if not outputPath:
    exit("Salvar imagem cancelado.")

input_image = Image.open(inputPath)

output = remove(input_image)

output.save(outputPath, 'PNG')

print(f"Imagem salva em: {outputPath}")
