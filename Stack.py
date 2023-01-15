push = 'PUSH'
pop = 'POP'
Stack = []
cmd = []
n = input()
while(n!='#'):
    cmd.append(n)
    n = input()
for i in cmd:
    if i == pop:
        if Stack :
            print(Stack[-1])
            Stack.pop()
        else :
            print("NULL")
    if push in i:
        Stack.append(i.split()[1])