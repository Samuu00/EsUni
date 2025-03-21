from threading import Thread

class Stampa:
    def __init__(self):
        pass

    def stampa(self,c,l):
        pass

    def stampaStriscia(self,c):
        pass

class StampaPrimitiva(Stampa):

    def __init__(self):
        super().__init__()

    def stampa(self, c, l):
        for i in range(0,l+1):
            print(c, end='', flush=True)
        
        print('')

    def stampaRighe(self,c,l,r):
        for i in range(r):
            self.stampa(c,l)

    def stampaStriscia(self, c, r=1):
        return self.stampaRighe(c,50,r)
    
MAXITER = 100
class StampatoreDiAsterischi(Thread):
    
    def __init__(self,istanzaDiStampa):
        super().__init__()
        self.st = istanzaDiStampa

    def run(self):
        conta = MAXITER  
        while conta > 0:
            self.st.stampaStriscia('*')
            conta -= 1

class StampatoreDiTrattini(Thread):
    
    def __init__(self,istanzaDiStampa):
        super().__init__()
        self.st = istanzaDiStampa

    def run(self):
        conta = MAXITER
        while conta > 0:
            self.st.stampaStriscia('-')
            conta -= 1

class StampatoreDiRighe(Thread):
    
    def __init__(self,istanzaDiStampa):
        super().__init__()
        self.st = istanzaDiStampa

    def run(self):
        conta = MAXITER
        while conta > 0:
            self.st.stampaRighe('@', 48, 5)
            conta -= 1

s = StampaPrimitiva()

john = StampatoreDiAsterischi(s)
al = StampatoreDiTrattini(s)
jack = StampatoreDiRighe(s)
ajeje = StampatoreDiAsterischi(s)

john.run()
al.run()
jack.run()

print("Test stampa()")
s.stampa('*', 10)

print("Test stampaRighe()")
s.stampaRighe('-', 4, 7)

print("Test stampaStriscia()")
s.stampaStriscia('x', 3)
