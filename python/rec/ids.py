import pandas as pd
import numpy as np

""" def lista_dict(ds):
	lista = []
	for item in ds:
		lista.append(item)
	return lista

movies = pd.read_csv('movies.csv')

ds = []

for i in range(len(movies)):
	generos = movies.loc[movies.index[i]]['genres'].split('|')
	for genero in generos:
		ds.append({genero:1})

	if i == 5:
		break

print(ds) """
