import urllib.request
import json
codePostal = input("Entrez le code postal : ")
requete = urllib.request.Request('http://api.zippopotam.us/FR/' + codePostal)
reponse = urllib.request.urlopen(requete)
donneesBrut = reponse.read().decode("utf-8")
donneesJSON = json.loads(donneesBrut)
listeCommunes = donneesJSON["places"]
print("Voici les communes ayant pour code postal " + codePostal + " : ")
for commune in listeCommunes:
	print(" - " + commune["place name"])