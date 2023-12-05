import zipfile

filezip = zipfile.ZipFile("arquivo.zip")

with open("rockyou.txt", "r") as file:
    for line in file:
        line = line.strip()
        try:
            filezip.extractall(pwd=bytes(line, 'utf-8'))
            print("PASSWORD: ", line)
            break
        except:
            continue
