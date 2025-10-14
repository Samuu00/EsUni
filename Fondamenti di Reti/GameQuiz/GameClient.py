from socket import *
import sys

def writeAndFlush(stream, string):
    stream.writelines(string)
    stream.flush()


def main():
    ip = "127.0.0.1"
    port = 6789

    connectionSocket = socket(AF_INET, SOCK_STREAM)
    connectionSocket.connect((ip, port))

    inStream = connectionSocket.makefile("r")
    outStream = connectionSocket.makefile("w")

    quit = False
    while not quit:
        print("----------START----------")
        while True:
            line = inStream.readline()
            if line == "\n":
                break
            if line.lower() == "quit\n":
                quit = True
                break
            print(line.strip())
        print("----------END----------")

        sentence = input('')
        if sentence.lower == "quit\n":
            break
        writeAndFlush(outStream, sentence+"\n")
    connectionSocket.close()

if __name__ == "__main__":
    main()