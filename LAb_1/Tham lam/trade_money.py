# Give 5 types of coin 1, 5, 10, 25, 100 cent
# find the way to give X cent which the number of coins 
# is minimun using Greedy Solution



# USING GREEDY


X = int(input())
Coins = [100, 25, 10, 5, 1]
Trade = []
for i in Coins:
    if (X / i >=1):
        Trade.append(int(X/i))
        X = X - i* int(X/i)
    else: Trade.append(0)

print(Trade)

