en = list(input().split())
a = int(en[0])
b = int(en[1])
x = 0
for i in range(0, 10):
    if (a & (1 << i)) != (b & (1 << i)):
        x |= (1 << i)
print(x)