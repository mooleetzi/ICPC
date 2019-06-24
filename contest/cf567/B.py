n=input()
s1 = str(input())
s2=s1
ans = int(s1)
for i in range(n - 1):
    if s2[i+1]!='0':
        ans = min(ans, int(s2[0:i + 1]) + int(s2[i + 1:n]))
print(ans)
print(1)