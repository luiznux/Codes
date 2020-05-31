def traco_matriz(matriz_quadrada):
    traco = 0
    for i in range(0,len(matriz_quadrada)):
       traco+= matriz_quadrada[i][i] 
                        
    return traco

#-----------Main------------------#

matriz_teste =[[1,2,3],[4,5,6],[7,8,9]]

print(traco_matriz(matriz_teste))



