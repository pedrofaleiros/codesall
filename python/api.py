import requests
import time


token = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJuYW1lIjoidGVzdHVzZXIiLCJlbWFpbCI6InRlc3R1c2VyQGVtYWlsLmNvbSIsImlhdCI6MTY5MzQ4OTgxMywiZXhwIjoxNjk2MDgxODEzLCJzdWIiOiIyMWM4YTc2NS02YWY0LTRlNDctYmI2YS0xNmYwMzUyY2NhNzgifQ.1PHiG7J0Kjb2ygzq6J0fXozz16-iYHGZ27gWtZrhUaE'

headers = {'Authorization': f'Bearer {token}'}

for i in range(10000):
	# time.sleep(0.05)
	
	start_time = time.time()
	try:
		response = requests.get('http://localhost:3333/food', headers=headers)
		response.raise_for_status()
	except requests.RequestException as e:
		print("Falha na requisição:", e)

	end_time = time.time()

	elapsed_time = end_time - start_time
	elapsed_time = elapsed_time * 1000
	print(f"{i}> Time: {elapsed_time:.0f} ms")
