#!/usr/bin/env python3
import socket
adresseIP = "127.0.0.1"	# Ici, le poste local
port = 50000	# Se connecter sur le port 50000
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((adresseIP, port))
print("Connecté au serveur")
print("Tapez FIN pour terminer la conversation. ")
message = ""
while message.upper() != "FIN":
	message = input("> ")
	client.send(message.encode("utf-8"))
	reponse = client.recv(255)
	print(reponse.decode("utf-8"))
print("Connexion fermée")
client.close()