from tqdm import tqdm
import pyzipper
import sys

zipFileName = sys.argv[1]
wordlist = "rockyou.txt"

total = len(list(open(wordlist, "rb")))

with pyzipper.AESZipFile(zipFileName) as file:
	with open(wordlist, "rb") as wl:
		for word in tqdm(wl, total= total, unit="word"):
			password = word.strip()
			try:
				file.extractall(pwd=password)

				print("Password: ", password)
				break
			except:
				continue