def maior_elem_matriz(matriz):

    cont = matriz[0][0]

    for i in range( len(matriz)):
        for j in range( len(matriz[0])):
            if cont < matriz[i][j]:
                cont = matriz[i][j]

    return print("o maior elemento é:\n-->",cont)

#-----------------------MAIN------------------#

matriz_teste = [[0,1,2,50,4],[4,6,8,2,20]]

maior_elem_matriz(matriz_teste)
