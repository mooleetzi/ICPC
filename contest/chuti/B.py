import re

try:
    # f=open("test2/6.out",'w+')

    c = int(input())
    while c>0:
        p = input().lower()
        s = input().lower()
        lp = len(p)
        ls = len(s)
        i = 0
        res=0
        while i<ls:
            if s[i]==p[0]:
                j = i
                cnt = 0
                cur = 0
                while j < ls:
                    if s[j] == p[cur]:
                        cur += 1
                        if (cur == lp):
                            cnt += 1
                            cur = 0
                        j += 1
                    else:
                        break
                if cnt>0:
                    t=i+cnt*lp
                    if t<ls:
                        if (s[t].isdigit()):
                            tmp = re.split(r'[a-z]',s[t:],1)[0]
                            res += int(tmp)*cnt
                        else:
                            res += cnt
                    else:
                        res += cnt
                i = j
            else:
                i = i+1
        print(res)
        # f.write(str(res))
        # f.write('\n')
        c-=1
except Exception as err:
    print(err)