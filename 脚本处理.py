def to(s):
    if len(s)<20:
        return False
    l = s.split(" ")
    if len(l)<120 or len(l)>240:
        return False
    wn = len(re.findall(r'\b[A-Za-z\']{3,5}\b',s))
    if len(l)/wn>3:
        return False
    return True
open('ok.txt','w').write( reduce((lambda a,b :a+'\n\n'+b),filter(to, open('result.txt').read().split('\n') ))  )
