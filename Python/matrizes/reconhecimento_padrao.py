#----------------Funções para criar a matriz a partir do arquivo-------------------------------------------------#

#cria uma matriz com zeros e tamanho definido pelos parametros
def cria_matriz(linha,coluna):
    matriz = [None] * linha   # cria (aloca) x linhas
    for i in range(linha):
        matriz[i]=[0] * coluna  # aloca uma nova linha com x colunas
    return matriz

#verifica o tamanho da matriz lendo a primeira linha do arquivo
def tam_matriz_arquivo(arquivo):
    with open (arquivo) as filename:
        linha,coluna = filename[0].split() #remove o \n e pega o tamanho da matriz
        if linha or coluna < 3:
            print(" Erro!, a matriz informada tem que ser maior que 3 linhas e 3 colunas ")
            return 
    return linha,coluna

#cria a matriz com os elementos do arquivo a partir da segunda linha 
def cria_matriz_arquivo(arquivo, linha, coluna): 
    matriz_principal = cria_matriz(linha,coluna)
    with open (arquivo) as filename:
        for ler in range(1,len(filename)):
            matriz_principal.append(float(ler))
    return matriz_principal
        
            

            
            




#------------------funções para fazer o centro de gravidade-------------------------------------------------------#

#soma todos os elementos de todas as linhas da matriz dada e retorna um vetor com o resultado de todas as somas
def somaLinha(matriz):
    vetor_das_somas = []
    soma = 0 
    for linha in range(len(matriz)):
        for coluna in range(len(matriz[0])):
            soma += matriz[linha][coluna] 
            vetor_das_somas.append(soma)
            soma = 0
    return vetor_das_somas


#soma todos os elementos de todas as colunas da matriz dada e retorna um vetor com o resultado de todas as somas 
def somaColuna(matriz):
    vetor_das_somas = []
    soma = 0
    for coluna in range(len(matriz[0])):
        for linha in range(len(matriz[0])):
            soma += matriz[coluna][linha]
        vetor_das_somas.append(soma)
        soma = 0
    return vetor_das_somas


#soma os elementos de um vetor e pede parametros de qual o intervalo que a soma vai, exemplo do indice 2(inicio) ate indice 6(fim)
def soma_elementos(vetor, inicio, fim):
    for i in range (indice+1,len(vetor)-1):
        soma += vetor[i]
    return soma


#calcula o centro de gravidade de uma matriz 
def calcula_centro(vetor):
    vetor_centro = []
    for indice in range(1, len(vetor)-1):
        soma = soma_elementos(vetor,vetor[0],i-1) - soma_elementos(vetor,i,len(vetor) - i)
        vetor_centro.append(soma)
        soma = 0
    return vetor_centro

#acha  o maior index do vetor
def maior_index(vetor):
    vetor.sort()
    return len(vetor)-1




#----------------------------MAIN------------------------------------------#

arquivo = input("Digite o nome de um arquivo com usa extenção para ser lido e calcular o seu centro de gravidade\n ---->")

linha,coluna = tam_matriz_arquivo(arquivo)

matriz_criada = cria_matriz_arquivo(arquivo,linha,coluna)

Soma_das_linhas = somaLinha(matriz_criada)

Soma_das_colunas = somaColuna(matriz_criada)

centro_linha = maior_index(calcula_centro(Soma_das_linhas))

centro_coluna = maior_index(calcula_centro(Soma_das_colunas))

print("O centro de gravidade da matriz de seu arquivo é :\n --->" "linha[",centro_linha,"]","coluna[",centro_coluna,"]")
