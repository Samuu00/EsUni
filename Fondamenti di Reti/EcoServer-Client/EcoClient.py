from socket import *

serverIP = '127.0.0.1'
serverPort = 2000

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverIP, serverPort))

outStream = clientSocket.makefile('w')
inStream = clientSocket.makefile('r')

while True:
    data = input("Scrivi...: ")
    outStream.writelines(data + "\n")
    outStream.flush()
    sentence = inStream.readline()
    print(f"From server: {sentence}")

    if data == "exit":
        break

inStream.close()
outStream.close()
clientSocket.close()
