import http.server
portEcoute = 80		# Port Web par défaut
adresseServeur = ("", portEcoute)
serveur = http.server.HTTPServer
handler = http.server.CGIHTTPRequestHandler
handler.cgi_directories = ["/tmp"]	# On sert le dossier /tmp
print("Serveur actif sur le port ", portEcoute)
httpd = serveur(adresseServeur, handler)
httpd.serve_forever()