# AES_cypher_STM32
Projet de cryptographie: implémentation de l'algorithme de cryptage AES


## Key schedule
>This part of the algorithm consist in creating 11 different keys for the 10 steps of the algorithm and uses for that 3 functions:
- The *RotWord* function that rotates a 4 bytes part of the key on the left
- The *SubWord* function that associate all the 8bits letters of a 4 bytes part of the key with 4 other letters
- The *Rcon* function that modify the first letter of a 4 bytes part of the key

These 3 functions are applied to the 4th part of the 128bits key at the end of each of the 10 steps
The 4 parts of the created key are obtained by XORing the parts of the previous key and the modified 4th part

## AES algorithm

> The AES cypher has 3 steps:
- The startup phase consist in XORing the plain text with the key
- The main phase conssit in 9 repetitions of 4 functions: 
  - *SubBytes* that associate all the 8bits letters of the state with other letters
  - *ShiftRow* that rearange the subparts of the key by rotating those by 0, 1, 2 and 3 bytes
  - *MixColumns* that multiply all the 4 parts of the state by a matrix (A)
  - *AddRoundKey* that XOR the state with the key optained with the *Key Schedule* algorithm
- The final phase that is the same as a repetition from the main phase but withtout the *MixColumns* function

The final state is then the cyphered text


## Quick references :

>A:
>|2|3|1|1|
>|1|2|3|1|
>|1|1|2|3|
>|3|1|1|2|
