from socket import *

serverPort = 6789

welcomeSocket = socket()
welcomeSocket.bind(('', serverPort))

welcomeSocket.listen(2)
print("SERVER LISTENING")

while True:
    connectionSocket, addr = welcomeSocket.accept()
    print(addr)
    inStream = connectionSocket.makefile("r")
    outStream = connectionSocket.makefile("w")
    clientSentence = inStream.readline().strip()

    while clientSentence != "END":
        capitalizedSentence = clientSentence.upper()
        outStream.writelines(capitalizedSentence + "\n")
        outStream.flush()
        clientSentence = inStream.readline().strip()

    inStream.close()
    outStream.close()
    connectionSocket.close()