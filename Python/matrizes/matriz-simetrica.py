def matriz_simetrica(matriz):
    elementos_matriz = len(matriz)**2
    cont = 0
    for linha in range(0,len(matriz)):
        for coluna in range (0,len(matriz[0])):
            if matriz[linha][coluna] == matriz[coluna][linha]:
                cont+=1
    if elementos_matriz == cont:
        return True
    else:
        return False


def printa_matriz(matriz):
    for i in range (0, len(matriz)):
        print("\n",matriz[i])


#-------------MAIN--------------------------#

matriz_teste = [[3,5,6],[5,2,4],[6,4,8]]
printa_matriz(matriz_teste)
print(matriz_simetrica(matriz_teste))

print("\n")
matriz_2= [[1,5,7],[8,6,5],[7,9,2]]
printa_matriz(matriz_2)
print(matriz_simetrica(matriz_2))






