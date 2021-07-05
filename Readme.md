
##  Trabalho 1 da disciplina do Bacharelado em tecnologia da informação da Universidade Federal do Rio Grande do Norte, campus Natal.

Este documento tem como objetivo demonstrar como executar o programa:
Há duas maneira de utilizar este projeto, utilizando o `Makefile` e utilizando o `cmake`.

Utilizando Makefile:
No terminal, entre na pasta src/ do projeto, e execute o comando `make` para compilar os arquivos `.cpp`. Após a finalização, digite o comando `./keno.o <arquivo de aposta>`, podendo utilizar alguns arquivos de testes prontos armazenados na pasta tests na raiz do projeto.

Utilizando cmake:
No terminal, entre na pasta `src/` e em seguida:

    mkdir build
    cd build/
    cmake ../
    make
    cd ../
    cp table.dat build/
    cd build/
    ./keno <arquivo de aposta>

ou utilize algum dos arquivos de teste localizados na pasta `tests` na raiz do projeto.

**Observação: Testes automatizados não foram implementados no projeto.**