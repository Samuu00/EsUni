class Mico:
    def iniz(self, nome = "", cognome = "", eta = 0):
        self.nome = nome
        self.cognome = cognome
        self.eta = eta
        print("Costruttore chiamato")
    
    def copy(self):
        print("Costruttore per copia")
        return Mico(self.nome, self.cognome, self.eta)
    
    def getNome(self):
        return self.nome
    
    def getCognome(self):
        return self.cognome
    
    def getEta(self):
        return self.eta
    
    def setNome(self, nome):
        self.nome = nome

    def setCognome(self, cognome):
        self.cognome = cognome
    
    def setEta(self, eta):
        self.eta = eta


mico_list = []

m = int(input("Inserisci quanti mico vuoi creare: "))

for i in range(m):
    nome = input("Inserisci nome: ")
    cognome = input("Inserisci cognome: ")
    eta = int(input("Inserisci età: "))
    mico = Mico()
    mico.iniz(nome, cognome, eta)
    mico_list.append(mico)

for mico in mico_list:
    print(f"Nome: {mico.getNome()}, Cognome: {mico.getCognome()}, Eta: {mico.getEta()}")