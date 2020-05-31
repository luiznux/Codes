def cria_matriz(linha,coluna):
    matriz = [0] * linha   # cria (aloca) x linhas
    for i in range(linha):
        matriz[i]=[0] * coluna  # aloca uma nova linha com x colunas
    return matriz


def transposta(matriz):

    linha_transposta = len(matriz[0])
    coluna_transposta = len(matriz)

    #crio uma matriz transposta com base na matriz dada como parametro
    mat_transposta = cria_matriz(linha_transposta,coluna_transposta) 

    #dois laços para transpor os elementos da matriz original para
    #a matriz transposta criada anteriormente, assim, como a linha 
    #da original vira a coluna da transposta, mat_trans[i][j] = matriz[j][i]
    for i in range(0, len(mat_transposta)):
        for j in range(0, len(mat_transposta[0])):
            mat_transposta[i][j] = matriz[j][i]
    return mat_transposta


def printa_matriz(matriz):
    for i in range(len(matriz)):
        print(matriz[i])

    
    
#---------------MAIN------------------------#

teste_matriz =[[0,6,5,8],[-1,2,4,7],[1,0,5,0]]

printa_matriz(teste_matriz)
print("\n")

m = transposta(teste_matriz)

printa_matriz(m)

print("\n")


