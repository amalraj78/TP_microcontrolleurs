# TP_controleur_AmalrajJCV_MarieMM

## Fait par
- Amalraj John Charles Varatharajan
- Mariam Mougammadou

## Démarrage

On commence par créer le projet, initialiser les périphériques par défaut. On fait un test avec la LED LD2 de la carte NUCLEO, ainsi qu'avec un printf pour voir que tout fonctionne correctement.

## GPIO Expander 

### Configuration

La référence du GPIO expander est la puce MCP23S17. Il y a 16 leds connectés sur la puce. 
Nous allons utiliser le SPI3 du STM32, et le configurer en mode Full-Duplex Master.

### Tests

#### MCP23S17

Nous allons écrire un driver pour le MCP23S17. L'adresse du la puce est 0x40 pour écrire et 0x41 pour lire. On met dans un couple de fichiers MCP_functions, les prototypes et fonctions du GPIO Expander.
On commence alors par une intialisation du MCP23S17 ainsi qu'une fonction pour écrire et lire dans des registres.

- [MCP_functions.h](https://github.com/Mariam-m95/TP_controleur_AmalrajJCV_MarieMM/blob/main/tp_noyau_tr_amalraj_mariam/tp_microcontroleurs_amalraj_mariam/Core/Src/MCP_functions.h)
- [MCP_functions.c](https://github.com/Mariam-m95/TP_controleur_AmalrajJCV_MarieMM/blob/main/tp_noyau_tr_amalraj_mariam/tp_microcontroleurs_amalraj_mariam/Core/Src/MCP_functions.c)

![MCP_functions](https://github.com/user-attachments/assets/f640d46a-4480-46e0-9a9f-66c1758ee94d)

On active le Chip Select pour écrire dans les registres et on le désactive quand on ne l'utilise plus.

#### LEDS

Nous allons maitenant écrire un driver pour contrôler les Leds, dans le couple de fichiers led. Nous allons définir les leds comme un structure contenant son registre associé, son pin et son état. Les registres pour contrôler les leds sont les registres A et B

- [led.h](https://github.com/Mariam-m95/TP_controleur_AmalrajJCV_MarieMM/blob/main/tp_noyau_tr_amalraj_mariam/tp_microcontroleurs_amalraj_mariam/Core/Src/led.h)
- [led.c](https://github.com/Mariam-m95/TP_controleur_AmalrajJCV_MarieMM/blob/main/tp_noyau_tr_amalraj_mariam/tp_microcontroleurs_amalraj_mariam/Core/Src/led.c)

![structure_led](https://github.com/user-attachments/assets/306b2904-ca9e-46cb-8f1e-8a7846050b24)

On commence par une initialisation des leds, puis on écrit une fonction pour allumer une led ou toutes les leds, et on fait de même pour les éteindre. Pour les allumer et les éteindre nous allons utiliser les fonctions MCP pour écrire dans les registres A et B respectivement aux adresses 0x12 et 0x13.

![image](https://github.com/user-attachments/assets/9476ce64-e4a1-4b08-9c1c-9d0fc579ae06)
![image](https://github.com/user-attachments/assets/04ba1f36-01cc-48cb-ac7f-0dd81767c063)

Nous allons aussi créer un chenillard :

![image](https://github.com/user-attachments/assets/cb149697-574b-4406-938c-501052f4ebb0)

## Codec audio

### Configurations préalables

Nous allons utiliser ces pins pour l'I2C :
- SCL : PB10
- SDA : PB11

On active l'I2C, ainso que le SAI2 et on le configure. On active aussi le DMA et les interruptions.

### Configuration du CODEC par l'I2C

On vérifie la présence d'une horloge MCLK :
![MCLK](https://github.com/user-attachments/assets/c33d271c-ddb4-479f-9540-3cc709ad542e)
On observe bien une horloge de 12.3 MHz, comme nous l'avons configuré juste avant.

On récupère la valeur du registre du CHIP_ID :
![CHIP_ID](https://github.com/user-attachments/assets/9ba2cb08-e8dc-40ea-b06b-830c23bc2778)


On vérifie si la configuration de l'I2C est bien effectuée, en regardant le signal sur un oscilloscope :
![I2C](https://github.com/user-attachments/assets/b2d0fd83-8cca-433a-b813-977283d87452)

On observe bien une horloge sur SCL et une trame de données sur SDA (les lignes ont été inversées par erreur).

Nous allons maintenant assigner les valeurs de chaque registre grâce à la documentation, nous allons créer un couple de fichier sgtl5000, pour faire l'initialisation des valeurs et l'écriture dans les registres.

- [sgtl5000.h](https://github.com/Mariam-m95/TP_controleur_AmalrajJCV_MarieMM/blob/main/tp_noyau_tr_amalraj_mariam/tp_microcontroleurs_amalraj_mariam/Core/Src/sgtl5000.h)
- [sgtl5000.c](https://github.com/Mariam-m95/TP_controleur_AmalrajJCV_MarieMM/blob/main/tp_noyau_tr_amalraj_mariam/tp_microcontroleurs_amalraj_mariam/Core/Src/sgtl5000.c)

Nous n'avons pas pu aller plus loin, nous avons tout de même réussi à avoir un signal en sortie, mais il n'était pas triangulaire, sûrement à cause de mauvaises valeurs assignées aux registres du SGTL5000.

## Conclusion

Nous avons pu lors de ce TP appliqué nos compétences en C et dans l'environnement STM32 CubeIDE. Nous avons appris à écrire des drivers pour avoir un code structuré et correct. Nous avons su configuré les périphériques. Nous avons aussi pu découvrir comment nous pouvons utiliser les périphériques et observer des résultats.



