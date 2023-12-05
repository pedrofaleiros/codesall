import pandas as pd
import numpy as np
from sklearn.neighbors import NearestNeighbors

def getIndexbyId(id):
	ratings = pd.read_csv('ratings.csv')
	lista = []
	for i in ratings['userId']:
		if i not in lista:
			lista.append(i)

	if id not in lista:
		return False

	return lista.index(id)

movies = pd.read_csv('movies.csv')
ratings = pd.read_csv('ratings.csv')

movies = movies[['movieId', 'title']]
ratings = ratings[['userId', 'movieId', 'rating']]

df = pd.merge(movies, ratings, on='movieId')

df_recommender = df.pivot_table(index='userId', columns='title', values='rating').fillna(0)

modelo_knn = NearestNeighbors(metric='cosine')
modelo_knn.fit(df_recommender)

user = getIndexbyId(999)

distancia, i_vizinhos = modelo_knn.kneighbors(df_recommender.iloc[user].values.reshape(1, -1), n_neighbors=4)

distancia = distancia.flatten()
i_vizinhos = i_vizinhos.flatten()

usuario = df_recommender.index[user]

for i in range(0, len(distancia)):
	if i == 0:
		pass#print('Usuario: {0}\n'.format(usuario))
	else:
		pass#print('Vizinho {0} com distancia de {1}'.format(df_recommender.index[i_vizinhos.flatten()[i]], distancia[i]))

ds_usuario = df_recommender.loc[usuario].to_frame()
vizinho_proximo = df_recommender.index[i_vizinhos.flatten()[1]]
ds_vizinho = df_recommender.loc[vizinho_proximo].to_frame()

ds_titulos = pd.merge(ds_usuario, ds_vizinho, on='title').sort_values(by=vizinho_proximo, ascending=False)

ds_titulos = ds_titulos[(ds_titulos[vizinho_proximo] > 0) & (ds_titulos[usuario] == 0)].reset_index()

#print(ds_titulos[(ds_titulos[vizinho_proximo] >= 4)][['title', vizinho_proximo]])
#print(ds_titulos[['title', vizinho_proximo]])

print(movies.values)