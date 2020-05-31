def somaLinha(matriz):
    vetor_das_somas = []
    soma = 0 
    for linha in range(len(matriz)):
        for coluna in range(len(matriz[0])):
           soma += matriz[linha][coluna] 
        vetor_das_somas.append(soma)
        soma = 0
    return vetor_das_somas


teste = [[2,2,2],[4,4,4],[5,5,5]]

soma = [6,12,15]

print(somaLinha(teste))

print(soma)
