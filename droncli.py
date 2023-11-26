import socket

import sys
adresseIP = sys.argv[1]	# Ici, le poste local
port = int(sys.argv[2])	# Se connecter sur le port 50000
idclient = sys.argv[3]
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((adresseIP, port))
print("Connecté au serveur")
client.send(f"Bonjour, drone clinet   {idclient}".encode("utf-8"))
reponse = client.recv(255)
print(reponse.decode("utf-8"))
print("Connexion fermée")
client.close()
