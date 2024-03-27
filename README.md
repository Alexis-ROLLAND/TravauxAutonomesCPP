# TravauxAutonomesCPP


TEST0 : Validation de la structure du projet uniquement.

TEST1 : Constructeur par défaut - Crée une tirelire vide. Vérification via méthode getNbCoins, qui retourne le nombre de pièces et 
        la méthode estVide retournant true si la tirelire est vide.
        -> getNbCoins utilise la méthode size() de Vector
        -> estVide utilise la méthode empty de Vector

TEST2 : Méthode Add qui permet d'ajouter une pièce
        -> Nécessité de vérifier la validité de la pièce (ajout méthode isCoinValid) - Levée d'exception sinon

TEST3 : Méthode getTotal, qui retourne (unsigned int) la somme contenue en centimes d'Euros

TEST4 : Méthode countCoins, qui retourne le nombre de pièces d'un type donné. Levée d'exception si type de pièce non valide.

TEST5 : Retrieve, qui enlève une pièce d'un type donné. Levée d'Exception si pas de pièce correspondante ou si type de pièce non valide.

