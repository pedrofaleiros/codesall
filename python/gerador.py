import csv
import random

# Lista de nomes e sobrenomes
first_names = ["Maria", "João", "Ana", 'Daniela', 'Josué','Carlos',"Carlos", "Lucas", "Julia", "Pedro", "Gabriel", "Bruna", "Rafael", "Amanda", "Camila", "Fernanda", "Felipe", "Rodrigo", "Mateus", "Luiza", "Marcelo", "Thiago", "Eduarda", "Vitor", "Patricia", "Gustavo", "Leticia", "Natália", 'Bruno', 'Leonardo', 'Cristiano', 'Gabriel', 'Rafael', 'Cleber', 'Nayara', 'Lucas', 'Caio','Hugo', 'Felippe', 'Arthur', 'Artur', 'Ayrton', 'Ronaldo', 'Eduardo', 'Luan', 'David', 'Davi', 'Fabricio', 'Luisa', 'Ana Luiza', 'Paolla', 'Paloma', 'Chris']
last_names = ["Silva", "Santos", "Oliveira", "Souza", "Pereira", "Lima", "Carvalho", "Ferreira", "Costa", "Almeida", "Martins", "Rocha", "Ribeiro", "Alves", "Gomes", "Moreira", "Melo", "Barbosa", "Mendes", "Nunes", "Moraes", "Cardoso", "Pinto", "Araujo", "Cruz", 'Costa', 'Araujo', 'Rezende', 'Guedes', 'Amaral', 'Freitas', 'Souza', 'Arrascaeta', 'Faleiros', 'Costa', 'Solano', 'Lima', 'Saigg', 'Santoro', 'Simas', 'Santos']

# Geração aleatória de título e autor
def random_title():
    words = ["O", "A", "Casa", "Árvore", "Amor", "Sonho", "Vida", "Tempo", "Noite", "Luz", "Sombra", "Cidade", "Mar", "Mistério", "Esperança", "Destino", "Futuro", "Passado", "Silêncio", "Vento"]
    title = " ".join(random.choices(words, k=random.randint(2, 5)))
    return title

def random_author():
    first_name = random.choice(first_names)
    last_name = random.choice(last_names)
    return f"{first_name} {last_name}"

# Gerar dados aleatórios e escrever no arquivo CSV
with open("arquivos.csv", "w", newline="", encoding="utf-8") as csvfile:
    fieldnames = ["id", "title", "author", "year", "month"]
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    for i in range(1, 3001):
        writer.writerow({
            "id": 1000+i,
            "title": random_title(),
            "author": random_author(),
            "year": random.randint(2010, 2022),
        })
