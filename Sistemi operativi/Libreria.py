class Libreria:
    def __init__(self, catalogo=None, titolo=""):
        if catalogo is None:
            catalogo = []
        self.catalogo = catalogo
        self.titolo = titolo
    
    def copy(self):
        return Libreria(self.catalogo, self.titolo)

    def getCatalogo(self):
        return self.catalogo
    
    def getTitolo(self):
        return self.titolo
    
    def setTitolo(self, titolo):
        self.titolo = titolo
    
    def AggiungiLibro(self, nome):
        self.catalogo.append(nome)
    
    def stampaCatalogo(self):
        print("I libri disponibili sul catalogo sono: " + str(self.catalogo))
        


miaLibreria = Libreria()
n = int(input("Inserisci quanti libri vuoi aggiungere: "))
for i in range(n):
    libro = input("Inserisci nome del libro: ")
    miaLibreria.AggiungiLibro(libro)
miaLibreria.stampaCatalogo()

