class contoBancario:
    def __init__(self, nA=0, nomeProp="", saldo=0, saldoMinimo=100):
        self.nA = nA
        self.nomeProp = nomeProp
        self.saldo = saldo
        self.saldoMinimo = saldoMinimo
    
    def copy(self):
        return contoBancario(self.nA, self.nomeProp, self.saldo, self.saldoMinimo)

    def getNA(self):
        return self.nA
    
    def getNomeProp(self):
        return self.nomeProp
    
    def getSaldo(self):
        return self.saldo
    
    def getSaldoMinimo(self):
        return self.saldoMinimo
    
    def setNA(self, nA):
        self.nA = nA
    
    def setNomeProp(self, nomeProp):
        self.nomeProp = nomeProp
    
    def setSaldo(self, saldo):
        self.saldo = saldo
    
    def deposita(self, importo):
        if importo > 0:
            self.saldo += importo
            print("Deposito di: " + str(importo) + " effettuato. Saldo attuale: " + str(self.saldo))
        else:
            print("Importo non valido")
    
    def preleva(self, importo):
        if importo <= self.saldo - self.saldoMinimo:
            self.saldo -= importo
            print("Prelievo di: " + str(importo) + " effettuato con successo. Saldo attuale: " + str(self.saldo))
        else:
            print("Fondi insufficienti")


nA = int(input("Inserisci numero account: "))
nomeProp = input("Inserisci nome account: ")

conto = contoBancario(nA, nomeProp)

n = int(input("Inserisci 1 per depositare e 2 per prelevare: "))
if n == 1:
    importo = int(input("Inserisci importo da depositare: "))
    conto.deposita(importo)
else:
    importo = int(input("Inserisci importo da prelevare: "))
    conto.preleva(importo)
