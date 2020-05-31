matriz = [[1,1,3],[2,4,5]]

for i in range (0, len(matriz)):
    print(matriz[i])


def printMatriz( A ):
   N = len(A)
   M = len(A[0])
   for i in range(len(A)):
      for j in range(len(A[0])):
         print("%2d"%A[i][j], " ", end="")
         
      print() 


printMatriz(matriz)
