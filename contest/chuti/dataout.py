from cyaron import *
import traceback
maxn=10**5

basep=ALPHABET
bases=ALPHABET+NUMBERS


try:

    f = open("test2/6.in",'w+')
    n = randint(1, 10)


    f.write(str(n))
    f.write('\n')

    for i in range(n):
        ls = randint(1,maxn)
        lp = randint(1,10)
        p = String.random(lp,charset=basep)
        # s = String.random(ls,charset=bases)
        s=""
        for j in  range(100):
            if j&1 == 1:
                s += p.upper()*randint(1,100)+str(randint(1,maxn*maxn*maxn))
            else:
                s += p.lower()*randint(1,100)+str(randint(1,maxn*maxn*maxn))

        f.write(p)
        f.write('\n')
        f.write(s)
        f.write('\n')
    f.close()
except Exception as err:
    traceback.print_exc()
