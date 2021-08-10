# Atividade Pratica Tries

As Tries sao árvores de busca digital úteis para armazenamento de textos literários com o objetivo de localizar frases/palavras.
Outra aplicação interessante é o corretor ortográfico para sugerir se a escrita de uma determinada chave é correta ou não.

## Corretor ortografico

Para a atividade de hoje sobre Tries, vocês tem a disposiçao um codigo-fonte em C++ que cria uma Trie a partir de um array de strings, que compõe a base de palavras escritas corretamente, e uma chave que será buscada na Trie.

O programa retorna SIM caso a chave esteja escrita corretamente (contida na base). Mas caso nao encontre, o programa retorna sugestoes de palavras com a escrita correta.

## Atividade

1. Analise o código-fonte disponibilizado quanto as estruturas e funções utilizadas.
2. Atualize o código-fonte para aceitar uma chave informada por linha de comando.
3. Atualize novamente o código-fonte para carregar para a Trie uma lista de palavras do portugues-brasileiro [use um desses repositorios](https://www.ime.usp.br/~pf/dicios/index.html)
4. Entregue a atividade até o final do dia para 1 ponto extra.

### Para compilar no Linux/MacOS

```
g++ trie.cpp -o trie
```

### Para executar no Linux/MacOS

```
./trie
```

### Para executar e compilar no Windows 

Recomendo uso do VSCode conforme esse [Tutorial](https://medium.com/@juniortrojilio/preparando-o-vs-code-para-compilar-c-c-no-windows-988f4a91a557)
