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



def recommender(userId):

	user = getIndexbyId(userId)

	if user == -1:
		return {'erro':'userId Invalido'}

	places = pd.read_csv('places.csv')
	ratings = pd.read_csv('ratings_places.csv')

	df = pd.merge(places, ratings, on='placeId')

	df_recommender = df.pivot_table(index='userId', columns='placeName', values='rating').fillna(0)

	modelo_knn = NearestNeighbors(metric='cosine')
	modelo_knn.fit(df_recommender)

	distancia, i_vizinhos = modelo_knn.kneighbors(df_recommender.iloc[user].values.reshape(1, -1), n_neighbors=4)

	distancia = distancia.flatten()
	i_vizinhos = i_vizinhos.flatten()

	usuario = df_recommender.index[user]

	data = {'data':
		[
		vizinho(df_recommender, usuario, i_vizinhos, 1),
		vizinho(df_recommender, usuario, i_vizinhos, 2),
		vizinho(df_recommender, usuario, i_vizinhos, 3)
		]
	}

	return data
	""" ds_usuario = df_recommender.loc[usuario].to_frame()
	vizinho_proximo = df_recommender.index[i_vizinhos[1]]
	ds_vizinho = df_recommender.loc[vizinho_proximo].to_frame()

	ds_titulos = pd.merge(ds_usuario, ds_vizinho, on='placeName').sort_values(by=vizinho_proximo, ascending=False)

	ds_titulos = ds_titulos[(ds_titulos[vizinho_proximo] >= 3) & (ds_titulos[usuario] == 0)].reset_index()

	return toJson(ds_titulos['placeName']) """

def vizinho(df_recommender, usuario, i_vizinhos, i):
	ds_usuario = df_recommender.loc[usuario].to_frame()
	vizinho_proximo = df_recommender.index[i_vizinhos[i]]
	ds_vizinho = df_recommender.loc[vizinho_proximo].to_frame()

	ds_titulos = pd.merge(ds_usuario, ds_vizinho, on='placeName').sort_values(by=vizinho_proximo, ascending=False)

	ds_titulos = ds_titulos[(ds_titulos[vizinho_proximo] >= 3) & (ds_titulos[usuario] == 0)].reset_index()

	return toJson(ds_titulos['placeName'], i)


def toJson(ds, value):
	lista = []

	indice = 0
	for i in ds:
		lista.append({str(indice):i})
		indice += 1
	
	return {value:lista}