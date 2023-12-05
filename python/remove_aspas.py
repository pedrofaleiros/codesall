import csv

# Abrir o arquivo CSV
with open('novos_dados.csv', 'r', newline='') as arquivo_csv:
    leitor_csv = csv.reader(arquivo_csv)

    # Abrir um novo arquivo CSV para escrita
    with open('arquivo_sem_aspas.csv', 'w', newline='') as arquivo_sem_aspas:
        escritor_csv = csv.writer(arquivo_sem_aspas)

        # Loop sobre cada linha do arquivo CSV original
        for linha in leitor_csv:

            # Loop sobre cada célula da linha
            nova_linha = []
            for celula in linha:
                nova_celula = celula.replace('"', '')  # Remover as aspas duplas
                nova_linha.append(nova_celula)

            # Escrever a nova linha no arquivo CSV sem aspas duplas
            escritor_csv.writerow(nova_linha)
