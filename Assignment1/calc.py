v = 1/1.06
sum = 0

for i in range(1, 11):
    sum += (20 + 4*(i-1))*(v**i)
    print((20 + 4*(i-1)), "v^", i)

print(sum)
