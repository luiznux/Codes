import math

def calculaPolinomio(f, x):
  resultado = 0
  #Pulando de 2 em 2 para definir o multiplicador e o expoente // nao pega o ultimo termo independente
  for i in range(0,len(f)-1,2):
  #f[i] = valor multiplicado por X e f[i+1]=expoente
    resultado += float(math.pow(x, f[i+1]) * f[i])
  #pega o ultimo termo independente
  resultado += f[len(f)-1]
  return resultado

def exercicioUm(f, x):
  resultado = x - (math.pow(f, -(x)))
  return resultado

def exercicioDois(f, x):
  resultado = calculaPolinomio(f, x)
  resultado += math.pow(math.e,x)
  return resultado

def exercicioTres(f, x):
  resultado = f*x * (math.cos(f*x)) - math.pow((x + 1), f)
  return resultado

def exercicioQuatro(f, x):
  resultado = calculaPolinomio(f, x)
  resultado += x * math.cos(x)
  return resultado

def sinal(a, b):
  #Os dois nao podem ser iguais visto que precisamos achar uma raiz proximo a 0
  if (a > 0 and b > 0) or (a < 0 and b < 0):
    return False
  else:
    return True

tol_exercicio = 0.00001

#exercicio 1
print("Exercício 1")
#função
f_um = 2
a_um = 0
b_um = 1
meio_um = (a_um + b_um) / 2
a_um_calculado = exercicioUm(f_um, a_um)
b_um_calculado = exercicioUm(f_um, b_um)

possivel = sinal(a_um_calculado, b_um_calculado) 
#verifica se é possivel calcular a bisseção
if(possivel == False):
  print("É impossível calcular está bisseção")

else:
  for i in range(0, 100):
    meio_um_calculado = exercicioUm(f_um, meio_um)

    if(abs(meio_um_calculado) <= tol_exercicio):
      print("Resultado: %.10f" %meio_um_calculado)
      break

    if(meio_um_calculado * a_um_calculado) < 0:
      b_um = meio_um
      b_um_calculado = meio_um_calculado
    else:
      a_um = meio_um
      a_um_calculado = meio_um_calculado

    meio_um = (a_um + b_um) / 2
    
  print("Resultado: %.10f" %meio_um_calculado)
#fim ex 1

#ex 2
print("\n\nExercício 2")
#função excluindo o numero de euler
f_dois = [-1, 2, 3, 1, -2] #calcula Polinomio
a_dois = float(0)
b_dois = float(1)
meio_dois = (a_dois + b_dois) / 2

a_dois_calculado = exercicioDois(f_dois, a_dois)
b_dois_calculado = exercicioDois(f_dois, b_dois)

possivel = sinal(a_dois_calculado, b_dois_calculado) 
#verifica se é possivel calcular a bisseção
if(possivel == False):
  print("É impossível calcular está bisseção")

else:
  for i in range(0, 100):
    meio_dois_calculado = exercicioDois(f_dois, meio_dois)

    if(abs(meio_dois_calculado) <= tol_exercicio):
      print("Resultado: %.10f" %meio_dois_calculado)
      break

    if(meio_dois_calculado * a_dois_calculado) < 0:
      b_dois = meio_dois
      b_dois_calculado = meio_dois_calculado
    else:
      a_dois = meio_dois
      a_dois_calculado = meio_dois_calculado

    meio_dois = (a_dois + b_dois) / 2
    
  print("Resultado: %.10f" %meio_dois_calculado)
# fim ex 2

#ex 3
print("\n\nExercício 3")
f_tres = 2
a_tres = -3
b_tres = -2

print("\nA = -3 e B = -2")
a_tres_calculado = exercicioTres(f_tres, a_tres)
b_tres_calculado = exercicioTres(f_tres, b_tres)
meio_tres = (a_tres + b_tres) / 2

if(possivel == False):
  print("É impossível calcular está bisseção")

else:
  for i in range(0, 100):
    meio_tres_calculado = exercicioTres(f_tres, meio_tres)

    if(abs(meio_tres_calculado) <= tol_exercicio):
      print("Resultado: %.10f" %meio_tres_calculado)
      break

    if(meio_tres_calculado * a_tres_calculado) < 0:
      b_tres = meio_tres
      b_tres_calculado = meio_tres_calculado
    else:
      a_tres = meio_tres
      a_tres_calculado = meio_tres_calculado

    meio_tres = (a_tres + b_tres) / 2

  print("Resultado: %.10f" %meio_tres_calculado)

a_tres = -1
b_tres = 0

print("\nA = -1 e B = 0")
a_tres_calculado = exercicioTres(f_tres, a_tres)
b_tres_calculado = exercicioTres(f_tres, b_tres)
meio_tres = (a_tres + b_tres) / 2

if(possivel == False):
  print("É impossível calcular está bisseção")

else:
  for i in range(0, 100):
    meio_tres_calculado = exercicioTres(f_tres, meio_tres)

    if(abs(meio_tres_calculado) <= tol_exercicio):
      print("Resultado: %.10f" %meio_tres_calculado)
      break

    if(meio_tres_calculado * a_tres_calculado) < 0:
      b_tres = meio_tres
      b_tres_calculado = meio_tres_calculado
    else:
      a_tres = meio_tres
      a_tres_calculado = meio_tres_calculado

    meio_tres = (a_tres + b_tres) / 2

  print("Resultado: %.10f" %meio_tres_calculado)
#fim ex 3

#ex 4
print("\n\nExercício 4")
f_quatro = [-2, 2, 3, 1, -1] #calcula Polinomio
a_quatro = 0.2
b_quatro = 0.3

print("\nA = 0.2 e B = 0.3")
a_quatro_calculado = exercicioQuatro(f_quatro, a_quatro)
b_quatro_calculado = exercicioQuatro(f_quatro, b_quatro)
meio_quatro = (a_quatro + b_quatro) / 2

if(possivel == False):
  print("É impossível calcular está bisseção")

else:
  for i in range(0, 100):
    meio_quatro_calculado = exercicioQuatro(f_quatro, meio_quatro)

    if(abs(meio_quatro_calculado) <= tol_exercicio):
      print("Resultado: %.10f" %meio_quatro_calculado)
      break

    if(meio_quatro_calculado * a_quatro_calculado) < 0:
      b_quatro = meio_quatro
      b_quatro_calculado = meio_quatro_calculado
    else:
      a_quatro = meio_quatro
      a_quatro_calculado = meio_quatro_calculado

    meio_quatro = (a_quatro + b_quatro) / 2

  print("Resultado: %.10f" %meio_quatro_calculado)

a_quatro = 1.2
b_quatro = 1.3

print("\nA = 1.2 e B = 1.3")
a_quatro_calculado = exercicioQuatro(f_quatro, a_quatro)
b_quatro_calculado = exercicioQuatro(f_quatro, b_quatro)
meio_quatro = (a_quatro + b_quatro) / 2

if(possivel == False):
  print("É impossível calcular está bisseção")

else:
  for i in range(0, 100):
    meio_quatro_calculado = exercicioQuatro(f_quatro, meio_quatro)

    if(abs(meio_quatro_calculado) <= tol_exercicio):
      print("Resultado: %.10f" %meio_quatro_calculado)
      break

    if(meio_quatro_calculado * a_quatro_calculado) < 0:
      b_quatro = meio_quatro
      b_quatro_calculado = meio_quatro_calculado
    else:
      a_quatro = meio_quatro
      a_quatro_calculado = meio_quatro_calculado

    meio_quatro = (a_quatro + b_quatro) / 2

  print("Resultado: %.10f" %meio_quatro_calculado)
#fim ex 4
