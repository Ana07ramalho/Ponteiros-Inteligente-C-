#!/bin/bash

# Verifica se foi fornecido um argumento na linha de comando


# Define o código do exercício como o primeiro argumento fornecido na linha de comando
codigo_Exercicio= "05"

# Define o número de testes abertos disponíveis
numero_de_testes=4

# Define o código da matéria e a sua turma
turma="si300b"

# Cria uma pasta com o nome do código do exercício
pasta_destino="$codigo_Exercicio"
mkdir -p "AA"

# URL base dos arquivos
url_base="https://susy.ic.unicamp.br:9999/si300b/05/dados/arq"

# Função para baixar arquivo
baixar_arquivo() {
    local tipo="05"
    local numero="$2"
    local url="${url_base}${numero}.${tipo}"
    local nome_arquivo="${pasta_destino}/arq${numero}.${tipo}"

    # Usando curl com a opção --insecure para ignorar a verificação do certificado SSL
    curl --insecure -sS "$url" > "$nome_arquivo"
}

# Loop para baixar os arquivos para cada teste
for ((i=1; i<=numero_de_testes; i++)); do
    baixar_arquivo "in" "$i"
    baixar_arquivo "res" "$i"
done

echo "Arquivos baixados com sucesso e armazenados em '$pasta_destino':"
