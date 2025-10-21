# Formation pour Valentin, télégestion


## Algorithme 

### Q : Écrire l'algorithme du Plus Grand Diviseur Commun en Python.
### R : Réalisation de l’algorithme via Euclide et du modulo pgcd(a,b)=pgcd(b,a mod b)

Explications ici ....


### Q : Écrire des tests par exemple avec PyTest.
### R : Utilisation de la command `assert`

- test sur plusieurs variables avec la commande  assert (vérifié par pytest)
- test semblable au précédent mais autmatisé avec  @pytest.mark.parametrize
- test avec la fonction math.gcd sur 10^12 variables 

Fiabilité ? Moyenne vu que math.gcd est basé sur le même algorithme d’euclide. Résultat, ne fonctionne qu’avec les entiers naturels, pas les relatifs. Améliorer avec une valeur absolue sur le résultat.

Idée pour aller plus loin, vérification avec la méthode des suites, soit un algorithme différents.


### Q : quels sont les "corner cases" pour cet algorithme ?
### R : Problématique pour les entiers relatifs, la V1 est utilisable que pour les entiers naturels.

### Q : En effet, comment va ton logiciel reagir si tu donne autre chose qu'un entier ? crash ? exception ? quel type de message ?
### R : 
- Interdire les décimales, sinon déviance de l’algorithme et réslutat completement faux
- Fonctionnelle pour tout le reste mais résultats négatifs pour les entiers relatifs à corriger avec application 'abs()  

**Q : Quel est la "computational complexity O" d'Euclid et de l'alternative que tu mentionne ?**
    <R :
    - Pour le théorème d’Euclide nombre d’itérations≤O(log(min(a,b))) d’après la démonstration de  Lamé.
    - Pour la décomposition en nombre premier on est beaucoup plus important 
$$
O\left(\exp\left(\left(\frac{64}{9}\right)^{1/3}(\log n)^{1/3}(\log\log n)^{2/3}\right)\right)
$$
 ou
$$
\exp\!\left(\left(\tfrac{64}{9}\right)^{1/3}(\log n)^{1/3}(\log\log n)^{2/3}\right)
\gg
\log\!\bigl(\min(a,b)\bigr)
$$
   (logarithme << exponentiel)

**Q : donc pour O(exp) tres probablement inutilisable tel quel sur un systeme embarque.**
    <R : Oui exactement, les calculs sont largement inaccecible pour les grandes valeurs. La méthode euclidienne est dailleurs la plus obtimal.>

**Q : Comment peux-tu renforcer encore les tests ? Notion d'Invariante.**
    <R :Je ne comprends pas trop la question. Ici l’algorithme est basé sur la notion de : 
    pgcd(a,b)=pgcd(b,a mod b)
    C’est théoriquement ce qu’il faut vérifier pour que ce soit vrai à tout moment pour que ce soit vérifié. C’est l’invariant ?
    Ici, c’est le théorème démontrable qui est basé sur cette égalité. On peut rajouter une ligne du type : 
		assert pgcd(a, b) == pgcd(a, a mod b)
    Mais je trouve que ça revient au même, de prouver le théorème par lui-même…>

**Q : a condition que tu n'aies pas d'erreurs dans ton code ! Et en general, tu n'as pas de preuve ou de theoreme, les invariants sont donc tres utiles. Par exemple (selon wikipedia):**
**PGCD(a ,b) = PGCD(a, b – a) pour b ≥ a > 0**
**PGCD(a, b) = PGCD(b, a)**
**PGCD(a, 0) = a**
**Ces equations sont correctes pour toutes les valeurs que tu fournis.**
    <R : oui effectivement, lensemble des tests sont clairement des invariants peremettant de vérifier correctement lalgorithme. Ils sont dailleurs fonctionneles.>



## Microcontroleurs
**Q : - se familiariser avec la plateforme IOT "Walter".**
**- comparer les microcontrôleurs:**
  **- ATmega328P (Microchip)**
  **- nRF9160 SiP (Nordic)**
            **- telecharger les "datasheet", se familiariser avec les termes GPIO, SPI, I2C, Clock Module**
            **- quel est le voltage en sortant des GPIOs pour les deux contrôleurs ?**
    <R : TEST ESP32-S3:
    - Installation de Arduino IDE
    - Intégration de la bibliothèque de connectique avec l’ESP32-S3
    - Essaie d’allumer la LED sur le GPIO 2 (échec, pas de LED en GPIO 2, compilation et upload OK)
    - Essaie d’allumer la LED sur tous les GPIO (échec, pas de LED du tout sur ESP32-S3)
    - D’après les datasheet, le voltage max en sortie de GPIOs est de 3.3V pour du “digitalWrite(pin, HIGH)”
    - Essaie d’un test pour lire le voltage sur un GPI et l’afficher sur le serial monitor.(échec, rien ne s’affiche malgré le bon port de communication, la conversion de l’ADC en 12 bits en volt. Utilisation du reset.
    - Piste de réflexion, pas de courant dans le GPIO mesuré… >

**Q :- c'est un kit que je n'ai pas, a regarder ensemble…**
**- comment mesurer le courant ? ( par opposition au voltage ). Difference fondamentalle entre courant et voltage.** 
        <R : 
        - Multimètre/ampèremètre (j’ai utilisé des pinces ampèremétriques, qui mesure le champ magnétique pendant l’utilisation des appareils.)
        - -Avec une résistance définie et une tension choisie et la loi d’Home “U=RI” ?>

**Q : quel est le courant mini que tu peux mesurer avec ces pinces ?**
        <R : En regardant la documentation des outils, on trouve le seuil de détection à 0.5 Aac voici le site de location : [site Hydreka](https://hydreka.com/produit/pinces-amperemetriques/)>

**Q : peux tu m'envoyer un lien avec le site de documentation pour l'ESP32-S3 ?**
        <R : [ESP32-S3-VROOM](https://www.espressif.com/sites/default/files/documentation/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)


**Q : voir schema ci-dessous: dimensionner resistance R1. pourquoi faut-il une resistance ? Comprendre le fonctionnement d'une diode / LED.**
        <R : 
        - VGPIO​=VD2​+VR​
        - VR​=R1×ID2
        - Alors R1= (VGPIO-VD2)/ID2
        - Deux inconnus (ID2 et VD2)

**Q : VD2 est dans le datasheet, essaie d'en trouver un (osram, …) et de chercher ce parametre.**
**Compare-le pour les Leds de differentes couleurs (orange, vert, rouge, blanc, bleu)**
**Fais un petit tableau avec differentes resistances et calcule les differents courants qui en resultent.**
        <R :
    | Couleur LED     | ( V_{LED} ) typique | Courant ( I_{LED} ) | Résistance ( R ) conseillée |
    | --------------- | ------------------- | ------------------- | --------------------------- |
    | Rouge           | 1,8 V               | 1 mA               | ( (3,3-1,8)/0,001 = 1500 Ω )  |
    | *ambré*         | 2,0 V               | 1 mA               | ( (3,3-2,0)/0,001 = 1300 Ω )  |
    | Verte           | 2,1 V               | 1 mA               | ( (3,3-2,1)/0,001 = 1200 Ω )  |
    | Jaune           | 2,0 V               | 1 mA               | ( (3,3-2,0)/0,001 = 1300 Ω )  |
    | Bleue / Blanche | 3,0 V               | 1 mA               | ( (3,3-3,0)/0,001 = 300 Ω )   |

    On situe ID2 en courant cible autour des 1 mA se qui nous donne une résitance en série denvirons 1kΩ. Finalement c'est clairement le résistance qui définit la valeur du courant présent dans le cicuit. Cela permet d'ajuster la consomation et de passer de 1mA à 10 mA le cas échéant.>

**Q : il y en a qui ne necessite que 1 mA , 20 mA est beaucoup trop pour nos applications.**

**Q : difference fondamentale entre diode et resistance ?**
        <R : La résistance est bidirectionnelle et proportionnelle alors que la diode est unidirectionnelle et non proportionnelle ?>

**Q : Exacte, presque, regarde dans un datasheet et essaie de comprendre ce qui se passe si tu augmente la "reverse bias voltage" au dela d'un certain seuil.**
**Cherche le datasheet de la diode 4001 et de la diode  4048 et compare les deux.**
**Quels sont les  courants admis ?**
        <R : 
        - Comme le fonctionnement habituelle se fait de la cathode à lanode, je pense que si on passe au dessus de 5V elle chauffe (pour dciper lénergie) et elle éclate à terme.
        - [4001](https://www.vishay.com/docs/88503/1n4001.pdf)
        - La diode 4048 à un courant de fonctionnement à 275 A (ce qui est énorme) et une tension inverse max de 250 V 
        - La diode 4001 à un courant de fonctionnement à 1 A et une tension inverse max de 1.1 V
        - Jimagine que lutilité des diodes cest de les faire fonctionner également à lenvers pour brider des courant ? La 4048 peux fonctionner sur du 230 V pour empecher les courant négatif, peut être pour passer AC en DC ?
        - La différence des deux, cest le courant utilisé ? Entre des apareilles en 12 V, 230 V ou ici en 3.3 V?>


**Q : Detail: comparer les symboles electroniques aux US et en Europe.**
    <R :Différence par rapport aux résistances (Rhéostat, Potentiomètre, Photoresistor)>
**Q : differences aussi pour Inductivite et Capacite, https://www.scribd.com/document/613801168/American-European-Symbols-Differences**






  <TEST MRK-ZERO
    Connection sans soucis pour allumer “LED_BUILTIN” je l’ai même fait clignoter toute les 500ms
    J’ai essayé de bricoler un code pour faire clignoter et lire les mesures>


**Q : quel est le courant maxi en sortant des GPIOs pour les deux contrôleurs ?**
    <R : pour le MKR Zero, on est à 7 mA par sorties, elles peuvent être cumulé jusuqa 46mA. Pour ESP32-s3, on est à 40 mA par sortie avec un maximum cumulé à 1.5 A. On peut en déduire que la consommation nest pas prévu pareille. ESP32 est prévu pour des courant beaucoup plus élevé.>




https://docs.arduino.cc/hardware/mkr-zero/



**Q :Tres bien, maintenant il est temp de passer a github pour partager le code.**
**familariser avec git, github and markdown, creer un compte sur github un repo partage comme explique ici: https://chatgpt.com/share/68e3e3ba-e1ac-8009-a4db-f6923679e870**
**mettre tout au propre (questions et reponses) completer reponses qui manquent.**
**Ensuite , je peux faire un "pull" et executer ton code ici.**


**A preparer pour apres:**
**se munir d'un vieux PC "box" ( il en  y a ici ) et installer Ubuntu Server, derniere version. Installer openssh-server, creer cles ssl**
**acceder la box a partir de ton portable sans mot de passe (passkey only). Se familariser avec ssh et les outils autour. Comprendre difference cles publiques <-> cles privees**

