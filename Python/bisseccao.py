import math
import sys


def calculaPolinomio(f, x):

    resultado = 0
    # Pulando de 2 em 2 para definir o multiplicador e o expoente // nao pega o ultimo termo independente
    for i in range(0, len(f)-1, 2):
        # f[i] = valor multiplicado por X e f[i+1]=expoente
        resultado += float(math.pow(x, f[i+1]) * f[i])
    # pega o ultimo termo independente
    resultado += f[len(f)-1]
    return resultado


def sinal(a, b):
    # Os dois nao podem ser iguais visto que precisamos achar uma raiz proximo a 0
    if (a > 0 and b > 0) or (a < 0 and b < 0):
        return False
    else:
        return True


# tolerancia
tol = float(0.1)
# função do tipo 1x³+4x²-10
funcao = [1, 3, 4, 2, -10]
# raizes escolhendo um resultado negativo e um positivo
a, b = 1, 2
meio = (a + b) / 2

a_calculado = calculaPolinomio(funcao, a)
b_calculado = calculaPolinomio(funcao, b)

possivel = sinal(a_calculado, b_calculado)
# verifica se é possivel calcular a bisseção
if possivel == False:
    print("É impossível calcular está bisseção")
    sys.exit()

print("A:", a)
print("B:", b)
print("Meio:", meio)
print("Polinômio:", funcao)
print("A calculado:", a_calculado)
print("B calculado:", b_calculado)

'''
   range para tolerancia de contas para fazer e
   parar quando o meio calculado for menor igual a tolerancia
'''


for i in range(0, 10000):

    meio_calculado = calculaPolinomio(funcao, meio)

    if(abs(meio_calculado) <= tol):
        break

    if(meio_calculado * a_calculado) < 0:
        b = meio
        b_calculado = meio_calculado
    else:
        a = meio
        a_calculado = meio_calculado

    meio = (a + b) / 2

print("Resultado: %.5f" % meio_calculado)

[4, 3, 3, 2, 25, 1, -6]
