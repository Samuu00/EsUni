from socket import *
import sys, re

serverPort = int(sys.argv[1])
sender = sys.argv[2]
receiver = sys.argv[3]

def writeAndFlush(stream, string):
    stream.writelines(string)
    stream.flush()

ipAddress = "160.97.63.51"

clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((ipAddress, serverPort))

inStream = clientSocket.makefile('r')
outStream = clientSocket.makefile('w')

print(inStream.readline())

writeAndFlush(outStream, "HELO localhost\n")
print(inStream.readline())

writeAndFlush(outStream, f"MAIL FROM:<{sender}>\n")
print(inStream.readline())

writeAndFlush(outStream, f"RCPT TO:<{receiver}>\n")
print(inStream.readline())

writeAndFlush(outStream, "DATA\n")
print(inStream.readline())

if sys.stdin.isatty():
    message = input("Mail text: ")
else:
    message = sys.stdin.read()

writeAndFlush(outStream, message + "\n.\n")
print(inStream.readline())

writeAndFlush(outStream, "QUIT\n")
print(inStream.readline())

clientSocket.close()
