# Instale e carregue o pacote arules
install.packages("arules")
library(arules)

# Crie uma matriz com os dados fornecidos
dados <- matrix(c(1, 0, 1, 1, 1,
                  0, 1, 0, 0, 0,
                  1, 1, 1, 0, 0,
                  0, 0, 1, 0, 1),
                nrow = 5,
                ncol = 4,
                byrow = TRUE,
                dimnames = list(1:5, c("BD", "IA", "MD", "PP")))

# Converta a matriz em um objeto do tipo 'transactions'
dados_trans <- as(dados, "transactions")

# Defina os parâmetros de suporte mínimo e confiança mínima
suporte_min <- 0.4
confianca_min <- 0.6

# Gere as regras de associação utilizando o algoritmo Apriori
regras <- apriori(dados_trans, parameter = list(supp = suporte_min, conf = confianca_min))

# Visualize as regras geradas
inspect(regras)
