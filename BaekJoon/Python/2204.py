import sys

class String:
    def init(self,string):
        self.st = string
    def __lt__(self,other):
        if type(self.st) == type(other.st):
            a = len(self.st)
            b = len(other.st)
            for i in range(min(a,b)):
                if not str(self.st[i]).lower() == str(other.st[i]).lower():
                    return ord(str(self.st[i]).lower()) < ord(str(other.st[i]).lower())
            return a < b
        else:
            return self < other
    
while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break
    textlist = []
    for i in range(n):
        t = sys.stdin.readline()
        te = String()
        te.init(t[:-1])
        textlist.append(te)
        
    min_text = textlist[0]
    for i in range(1,n):
        if not min_text < textlist[i]:
            min_text = textlist[i]

    sys.stdout.write(min_text.st)
    sys.stdout.write('\n')

    
