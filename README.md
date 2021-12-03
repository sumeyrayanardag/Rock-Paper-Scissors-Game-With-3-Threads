# Rock-Paper-Scissors-Game-With-3-Threads

Algorithm of the project:
1. Main process will create 3 threads pthread_create()
2. 1. Thread will select an item randomly
3. 2. Thread will select an item randomly too
4. 3. Thread will select an item randomly too
5. Then they will compare their items
6. Score of the winning thread will be increased
7. Game will continue until one of the threads reaches 5 points.

Compilation commands:
-> gcc mtgame.c -o mtgame -lpthread 
-> ./mtgame
