import csv 
import random

with open('ratings_places.csv', 'w', newline='') as csvfile:

	fieldnames = ['userId', 'placeId', 'rating']

	thewriter = csv.DictWriter(csvfile, fieldnames=fieldnames)

	thewriter.writeheader()

	#Alterar o valor dentro de range() para a quantidade de avaliações desejadas.
	#Ex: range(200) retorna 200 avaliações.
	for x in range(500):
		aux = random.randint(0, 10)
		
		maximo = 1
		
		if aux == 1:
			maximo = 5
		elif aux in [2, 3, 4]:
			maximo = 15
		elif aux in [5, 6, 7]:
			maximo = 30
		elif aux in [8, 9, 10]:
			maximo = 50

		for i in range(0, random.randint(1, maximo)):
			thewriter.writerow({'userId':x+1,
			'placeId':random.randint(1, 10000),
			'rating':round(random.randint(0, 5), 
			#'rating':round(random.uniform(0,5), 
			1)
			})