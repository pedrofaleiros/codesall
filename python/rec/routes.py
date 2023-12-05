import pandas as pd
import numpy as np
from flask import Flask, request
import recommender

def getIndexbyId(id):
	ratings = pd.read_csv('ratings_places.csv')
	lista = []
	for i in ratings['userId']:
		if i not in lista:
			lista.append(i)

	if id not in lista:
		return False

	return lista.index(id)

app = Flask("Api")

@app.route("/hello", methods=["GET"])
def helloWorld():
	return {'Hello': 'World!'}

@app.route("/login", methods=['POST'])
def login():

	body = request.get_json()

	return body['name']

@app.route("/get_recommendation", methods=['POST'])
def getRecommendation():

	body = request.get_json()

	user = int(body['userId'])

	return recommender.recommender(user)

app.run()