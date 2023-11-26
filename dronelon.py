


import socket 
import sys



id =int(sys.argv[2])
port  = int (sys.argv[1])
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(port)
server.listen(5)

while True :
    client , infosclient = server.accept()

    print(f"client connect  {infosclient[0]}" )
    requete = client.recv(255)

    print(requete.decode('utf-8'))
    response  = "accepted drone " +  id
    client.send(response.encode('utf-8'))
    client.close()

server.close()

