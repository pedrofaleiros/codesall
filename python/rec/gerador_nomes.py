import csv 
import random
import names


with open('places.csv', 'w', newline='') as csvfile:

  fieldnames = ['placeId', 'placeName', 'rating']
  localProb = ['Zoo', 'Airport', 'Bakery', 'Park', 'Bar', 
               'Bookstore', 'Book Shop', 'Bestaurant', 'Butcher\'s', 'Café',
               'Church', 'Supermarket', 'Department Store', 'Cinema', 'Service Station',
               'Gym', 'Hairdresser\'s', 'Hotel', 'Gallery', 'Greengrocer\'s',
               'Library', "Mall", 'Museum', 'Pharmacy', 'Pub']

  thewriter = csv.DictWriter(csvfile, fieldnames=fieldnames)

  thewriter.writeheader()

  #Alterar o valor dentro de range() para a quantidade de lugares desejados.
  #Ex: range(200) retorna 200 lugares.
  count = 0
  for x in range(10000):
    count+= 1
    thewriter.writerow({'placeId':count, 
                        'placeName':names.get_first_name() + ' ' + random.choice(localProb),
                        'rating':round(random.uniform(3,5), 1)
                        })