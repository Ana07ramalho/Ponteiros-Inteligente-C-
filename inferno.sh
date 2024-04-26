#!/bin/bash

# Definição dos nomes dos arquivos
codigoFonte="main.cpp"
nome_programa="programa"
numero_de_testes=4
contador_de_erros=0

# Mensagem de compilação
echo -e "\033[1;3mCompilando o programa...\033[0m"
# Compilação do programa
g++ -std=c++11 -Wall -Wextra -Wpedantic "$codigoFonte" Time.cpp Selecao.cpp Eliminatoria.cpp Competicao.cpp Clube.cpp Brasileirao.cpp -o "$nome_programa"

# Verifica se a compilação foi bem-sucedida
if [ $? -ne 0 ]; then
    echo "Erro ao compilar o programa."
    exit 1
else
    echo -e "O programa foi compilado com sucesso!\n"
fi

# Loop para executar o programa para cada teste
for ((i=1; i<=numero_de_testes; i++)); do
    # Mensagem indicando o teste atual
    echo -e "\033[1;3mRealizando teste aberto $i...\033[0m"
    
    # Execução do programa com entrada e saída redirecionadas
    ./"$nome_programa" < arq0${i}.in > saida.txt

    # Verifica se a execução foi bem-sucedida
    if [ $? -ne 0 ]; then
        echo -e "Erro ao executar o programa para o teste $i.\n"
        exit 1
    fi

    # Compara a saída do programa com o arquivo de referência
    diff -u saida.txt arq0${i}.res

    # Verifica o resultado da comparação e incrementa o contador de erros, se necessário
    if [ $? -ne 0 ]; then
        ((contador_de_erros++))
        echo -e "\033[1;31mForam encontradas inconsistências.\033[0m\n"
    else
        echo -e "\033[1;32mPassou!\033[0m\n"
    fi
done

# Verifica se houve erros e exibe a mensagem apropriada
if [ $contador_de_erros -gt 0 ]; then
    echo -e "\033[1;31mO teste terminou com $contador_de_erros erro(s).\033[0m\n"
else
    echo -e "\033[1;32mTodos os testes foram concluídos com sucesso!\033[0m\nPS: Esse teste não garante que o seu programa está totalmente correto,\napenas evita os erros mais comuns no Susy, economizando as tentativas!\nHavendo qualquer problema com a entrega, contate o seu monitor PMU ou PAD!\n"
fi
