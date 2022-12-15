dose_diaria = 0.2
def calculo(dias):
    dose_total = 0
    for i in range(dias):
        dose_total = dose_diaria + dose_total*0.3
        i+=1
    return dose_total
dias = int(input("Digite o número de dias: "))
print("A dose total é: ", calculo(dias))