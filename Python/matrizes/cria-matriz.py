#cria uma matriz com zeros e tamanho definido pelos parametros
def cria_matriz(linha,coluna):
    matriz = [0] * linha   # cria (aloca) x linhas
    for i in range(linha):
        matriz[i]=[0] * coluna  # aloca uma nova linha com x colunas
    return matriz


#adiciona elementos nas posições da matriz

def add_elem(matriz):

    for i in range (0,len(matriz)): # anda na linha

        for j in range (0,len(matriz[0])): # anda na coluna

            print("Inserir elementos em linha:",i,"e coluna",j,"\n")

            matriz[i][j] = int(input("digita ai o valor pra coloca na matriz \n --> "))



#-----------MAIN()-------------------------#

teste_matriz = cria_matriz(2,4)

add_elem(teste_matriz)

#printa a matriz bunitinha)

for i in range (0,len(teste_matriz)):#ando na linha
    print("\n",teste_matriz[i])#printo linha por linha dando enter entre elas
                               #pra fica bunitinha kkk


