n = int(input())
mat = [[0 for i in range(n)] for i in range(n)]
cont = 1;
for i in range(n):
	mat[i][i] = cont
	cont = cont + 1
for i in range(n):
	if (mat[i][n - 1 - i]): continue
	mat[i][n - 1 -i] = cont
	cont = cont + 1
print("Matriz X:")
for i in range(n):
	for j in range(n):
		print(mat[i][j], " ", sep='', end='')
	print();
for i in range(n):
	for j in range(n // 2):
		temp = mat[i][j]
		mat[i][j] = mat[i][n - 1 - j]
		mat[i][n - 1 - j] = temp
print("La matriz X invertida es:")
for i in range(n):
	for j in range(n):
		print(mat[i][j], " ", sep='', end='')
	print();