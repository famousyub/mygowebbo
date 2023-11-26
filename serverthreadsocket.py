#!/usr/bin/env python3
import socket
import threading 
threadsClients = []
def instanceServeur (client, infosClient):
	adresseIP = infosClient[0]
	port = str(infosClient[1])
	print("Instance de serveur prêt pour " + adresseIP + ":" + port)
	message = ""
	while message.upper() != "FIN":
		message = client.recv(255).decode("utf-8")
		print("Message reçu du client " + adresseIP + ":" + port + " : " + message)
		client.send("Message reçu".encode("utf-8"))
	print("Connexion fermée avec " + adresseIP + ":" + port)
	client.close()
serveur = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serveur.bind(('', 50000))	# Écoute sur le port 50000
serveur.listen(5)
while True:
	client, infosClient = serveur.accept()
	threadsClients.append(threading.Thread(None, instanceServeur, None, (client, infosClient), {}))
	threadsClients[-1].start()
serveur.close()