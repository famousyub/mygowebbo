import urllib.request
import json
requete = urllib.request.Request('http://api.open-notify.org/iss-now.json')	# La requête de l'API
reponse = urllib.request.urlopen(requete)	# Récupérer le fichier JSON
donneesBrut = reponse.read().decode("utf-8")	# Décoder le texte reçu
donneesJSON = json.loads(donneesBrut)	# Décoder le fichier JSON
position = donneesJSON["iss_position"]
print("La station spatiale internationale est située à une longitude " + position["longitude"] + " et à une latitude " + position["latitude"] + ". ")