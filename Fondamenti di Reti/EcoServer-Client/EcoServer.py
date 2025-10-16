from socket import *

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('127.0.0.1', 2000))
serverSocket.listen(1)

print('Server Listening')
while True:
    connectionSocket, clientAddress = serverSocket.accept()
    print(f"\nClient connesso da: {clientAddress}")

    inStream = connectionSocket.makefile('r')
    outStream = connectionSocket.makefile('w')

    while True:
        clientData = inStream.readline()

        if not clientData:
            print("Connessione chiusa dal client.")
            break

        stripped_data = clientData.strip()
        print(f"Ricevuto: '{stripped_data}'")

        outStream.write(clientData)
        outStream.flush()
        print(f"Inviato in Eco: '{stripped_data}'")


    inStream.close()
    outStream.close()
    connectionSocket.close()
    print(f"Socket di connessione con {clientAddress} chiuso.")

