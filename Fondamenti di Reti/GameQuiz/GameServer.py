from socket import *
from random import randint
from threading import *

serverPort = 6789

questions = []
answers = []
correct = -1

def loadquiz():
    global correct
    global answers
    with open('Questions.txt', 'r') as file:
        for line in file:
            if len(line.strip()) == 0:
                continue
            if line[0].isdigit() and line[1] == ".":
                if correct != -1:
                    questions.append((question, answers, correct))
                question = line.strip()
                answers = []
                correct = -1
            else:
                if "*" in line.strip():
                    correct = len(answers)+1
                answers.append(line.replace("*", "").strip())
        print(questions)

def randomQuestion():
    questionNumber = randint(0, len(questions)-1)
    return questions[questionNumber]

def writeAndFlush(stream, string):
    stream.writelines(string)
    stream.flush()

def onNewClient(conn, addr):
    print(f"New client connected from: {addr}")
    inStream = conn.makefile('r')
    outStream = conn.makefile('w')

    while True:
        question = randomQuestion()
        sendQuestion(question, outStream)
        response = inStream.readline().strip()
        while response.lower() != "quit\n" and response.lower() != '':
            if response == '':
                print("CLIENT STREAM INTERRUPTED")
            elif response.lower() == 'quit\n':
                break
            else:
                print(f"Client responded with <{response}> -- CORRECT: <{question[2]}>")
                if int(response) == int(question[2]):
                    writeAndFlush(outStream, "Risposta corretta\n")
                else:
                    writeAndFlush(outStream, "Risposta sbagliata\n")

            question = randomQuestion()
            sendQuestion(question, outStream)
            response = inStream.readline().strip()

        writeAndFlush(outStream, "quit\n")
        conn.close()
        break

def sendQuestion(question, outStream):
    serverOutput = f"{question[0]}\n"
    for answer in question[1]:
        serverOutput += f"{answer}\n"
    writeAndFlush(outStream, f"{serverOutput}\n")


def main():
    loadquiz()

    server = socket()
    server.bind(('', serverPort))
    server.listen(2)

    print(f"Server listening on port {serverPort}")

    while True:
        conn, addr = server.accept()
        Thread(target=onNewClient, args=(conn, addr)).start()


if __name__ == "__main__":
    main()





