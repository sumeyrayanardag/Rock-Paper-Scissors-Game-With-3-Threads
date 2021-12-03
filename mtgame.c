#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define MAX_THREAD 3   // defines maximum number of threads as 3
int compare(int p1, int p2);
int shared[3]={0,0,0};
char message[][20] = { "ROCK", "PAPER", "SCISSORS" };
int part=0;
void* randomSelections(void* arg)
{
        int thread_part=part++;
        int choice=rand() % (3);
        shared[thread_part]=choice;


}

int main()
{       srand(time(NULL));
        int scores[]={0,0,0};
        int sr=0, ss=0, sp=0;
        int tour=1;
        printf("The game has launched\n%d threads will be created\nThe game starts\n--\n--\n", MAX_THREAD);
        while(scores[0]<5 && scores[1]<5 && scores[2]<5  ){
                pthread_t threads[MAX_THREAD];
                for(int i=0; i<MAX_THREAD; i++)
                {
                pthread_create(&threads[i],NULL,randomSelections,(void*)NULL);
                }

                for(int i=0; i<MAX_THREAD; i++)
                                pthread_join(threads[i], NULL);

                for(int i =0; i<3 ; i++)
                {
                        if(shared[i]==0)
                        sr++;
                        if(shared[i]==1)
                        sp++;
                        if(shared[i]==2)
                        ss++;
                }

 printf("%d. Turn, 1. Thread: %s - 2. Thread: %s  3. Thread: %s  \n",tour,message[shared[0]],message[shared[1]]
                ,message[shared[2]]);

                tour++;

                int first=compare(shared[0],shared[1]);
                if(first==shared[0] && shared[1]==shared[2])
                        first=0;
                else if(first==shared[1] && shared[0]==shared[2])
                                first=1;
                        else if(first==-1 && compare(shared[0],shared[2])==shared[2])
                                first=2;
                                else {printf("DRAW, Scores: %d - %d - %d \n--\n--\n",scores[0], scores[1],scores[2]);
						first=-1;
                                                }

                for(int i=0;i<MAX_THREAD;i++)
                {
                        if(i==first)
                        {
                                printf("%d. Thread win, ",first+1);
                                scores[i]+=1;

                                        printf("Scores: %d - %d - %d \n--\n--\n",scores[0], scores[1],scores[2]);
                                break;
                        }
                }

        }
        for (int i = 0 ; i<3; i++)
        if(scores[i]== 5)
        printf("%d.Thread has won the game with score: %d - %d - %d in %d Turns. \n--\n--\n",i+1,scores[0],
        scores[1],scores[2], tour-1);

        printf("How many times items were selected: SCISSORS: %d, PAPER: %d, ROCK: %d \n--\n--\n",ss,sp,sr);

         printf("1.Thread terminated \n2.Thread terminated \n3.Thread terminated \nThreads are joined by"
                " main process\nGame finished\n\n");


        return 0;
}

int compare(int p1, int p2){
        if(p1==0 && p2==1)
                return p2;
        else if(p1==0 && p2==2)
                return p1;
        else if(p1==1 && p2==0)
                return p1;
        else if(p1==1 && p2==2)
                return p2;
        else if(p1==2 && p2==0)
                return p2;
        else if(p1==2 && p2==1)
                return p1;
        else
                return -1;
}

