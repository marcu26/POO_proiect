# POO_proiect

Protocoale:
1 username pass //este folosit pentru autentificare
	-daca e oke trimit 1 1
	-daca nu e oke trimit 1 0
	
2 username pass //este folosit pentru inregistrare
	-daca e oke trimit 2 1
	-daca nu e oke trimit 2 0
	
3 //trimit lista de jucatori cu tot cu player-ul care a facut request-ul
	- 3 lista
	
4 //trimit lista de jucatori fara player-ul care a facut request-ul
	- 4 lista

5 playerProvocat //primesc de la player, eu transmit mai departe (5 playerCareAProvocat)
	

6 //trimit jucatorului resursele
	-6 resurse //sunt delimitate de spatiu
	
7 //salvez resursele pe care mi le trimite playerul

8 opponentName //trimit oponentului pauza

e opponentName //trimit faptul ca e gata pauza

9 opponent raspuns //raspunul la provocare
	-9 0 sau 9 1 //trimit celui care a provocat
	
a opponentName //trimit player-ului informatii despre armata inamica

b 1/2 oponent 1/2/3   	//primul numar se refera la trupa care ataca, al doilea numar la trupa pe care o ataca

c nrSoldati nrCav nrMedici  //sa se adapteze trupele tale cand esti atacat (pe ecranul tau vor scadea trupele tale)

d nrSoldati nrCav nrMedici //sa se adapteze trupele adversarului cand ataci (pe ecranul tau vor scadea trupele inamicilor)

m 1/2/3 oponent 1/2/3		//e pentru medicis sa se vindece

q opponentName //player-ul s-a retras

k //sterge numele pentru a aparea deconectat

s //trimite informatii despre castiguri si infrangeri