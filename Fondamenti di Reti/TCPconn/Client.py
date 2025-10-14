from socket import *

serverIP = '127.0.0.1'
serverPort = 6789

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverIP,serverPort))

sentence = ""
outStream = clientSocket.makefile("w")
inStream = clientSocket.makefile("r")

while sentence != "END":
    sentence = input('Frase in minuscolo: ')
    outStream.writelines(sentence+"\n")
    outStream.flush()

    if sentence == "END":
        break

    modifiedSentence = inStream.readline()
    print("FROM SERVER:", modifiedSentence)

inStream.close()
outStream.close()
clientSocket.close()