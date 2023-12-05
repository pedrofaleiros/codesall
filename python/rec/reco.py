import pandas as pd
import numpy as np
from sklearn.neighbors import NearestNeighbors

def getIndexbyId(id):
	ratings = pd.read_csv('ratings_places.csv')
	lista = []
	for i in ratings['userId']:
		if i not in lista:
			lista.append(i)

	if id not in lista:
		return -1
	
	return lista.index(id)

places = pd.read_csv('places.csv')
ratings = pd.read_csv('ratings_places.csv')

places = places[['placeId', 'placeName']]

df = pd.merge(places, ratings, on='placeId')

df_recommender = df.pivot_table(index='userId', columns='placeId', values='rating').fillna(0)

modelo_knn = NearestNeighbors(metric='cosine', n_neighbors=4)
modelo_knn.fit(df_recommender)

user = getIndexbyId(14)

if user == False:
	print('Id invalido')

distancia, i_vizinhos = modelo_knn.kneighbors(df_recommender.iloc[user].values.reshape(1, -1))

distancia = distancia.flatten()
i_vizinhos = i_vizinhos.flatten()

usuario = df_recommender.index[user]

ds_usuario = df_recommender.loc[usuario].to_frame()

listaPlaces = []

for i in [1, 2, 3]:
	vizinho_proximo = df_recommender.index[i_vizinhos[i]]
	ds_vizinho = df_recommender.loc[vizinho_proximo].to_frame()

	ds_titulos = pd.merge(ds_usuario, ds_vizinho, on='placeId').sort_values(by=vizinho_proximo, ascending=False)

	ds_titulos = ds_titulos[(ds_titulos[vizinho_proximo] > 0) & (ds_titulos[usuario] == 0)].reset_index()

	#print(ds_titulos[(ds_titulos[vizinho_proximo] >= 4)][['placeName', vizinho_proximo]])
	#print(ds_titulos[(ds_titulos[vizinho_proximo] >= 4) & (ds_titulos[usuario] == 0)][:5])
	
	for i in ds_titulos['placeId'][((ds_titulos[vizinho_proximo] >= 4))]:
		if i not in listaPlaces:
			listaPlaces.append(i)

def getNamebyId(id):
	places = pd.read_csv('places.csv')
	i = 0
	for place in places.values:
		if id == place[0]:
			return place
		else:
			i += 1
	return 0

for i in listaPlaces:
	print(getNamebyId(i))