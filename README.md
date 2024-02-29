# MARGE SORT

    • É um algoritmo de ordenação 
    • tipo: dividir-pra-conquistar
    • Divide em sub-problemas e resolve de forma recursiva, depois combina as
    resposta pra uma solução menor.
    • É um sistema eficiente (tempo e execução).
    • Complexidade: O( n log n) .

Funcionalidade

    • Divisão: tem um vetor de entrada, que é dividido no meio até que os “sub-vetores” seja 1.
    • de forma recursiva, até não ter mais pra dividir.
    • Conquista: Ordena os sub-vetores.
    • Os sub-vetores são ordenados (crescente).
    • Usa-se a intercalação (merge), isso cria um vetor com o dobro do tamanho.
    • Combinação: Realizado pela intercalação dos subvetores.
    • Isso vai dar um vetor ordenado final.
    • A intercalação (merge) combina dois subvetores no vetor final.
    • A complexidade é O(log n) , n é o tamanho do vetor resultante do merge.
    • O merge pode ser feito com um vetor auxiliar.






Karla Ferreira e Victor Miranda
