//
//  main.c
//  master_mind
//
//  Created by Samuel Rosén on 2021-01-29.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

void proont(int arr[]){
    for(int i=0; i <=3;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int check(int arr1[], int arr2[], int size){
    int hit = 0;
    int miss =0;
    int block[4] ={0,0,0,0}; // Checks for hits and blocks that numer so that it won't double-count as a miss
    for(int i =0; i < 4; i++){
        if(arr1[i]==arr2[i]){
            hit++;
            block[i] = 1;
        }
    }
    for(int x=0;x<4;x++){
        if(arr1[x] != arr2[x]){
            for(int y=0; y<4; y++){
                if(arr1[x]==arr2[y] && block[y]==0){
                    miss++;
                    block[y]=1;
                    break;
                }
            }
        }
    }
    printf("Hits: %d\nMisses: %d\n", hit, miss);
    if(hit==4){ return 1;}
    else{ return 0;}
}


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    
    printf("Welcome to mastermind_c. This game is about guessing numbers.");
    int arr1[4];
    int arr2[4];
    
    int game_type;
    printf("\nEnter 1 if you want to enter the numbers manually or 0 = random numbers: ");
    scanf("%d", &game_type);
    
    if(game_type==1)
    {
        for(int i =0; i < 4;i++){
            printf("Enter number %d: ", i+1);
            scanf("%d", &arr1[i]);
        }
    }
    
    else
    {
        printf("Creating random array with  numbers between 0 and 4...");
        for(int i=0; i<4; i++){
            arr1[i] = rand()%4+1;
        }
        printf(" Done! \n");
    }
    
    if(game_type==1)
    {
    int dummy;
    printf("Click (cmd or control)+k to clear the terminal. (Else the person you're playing with can see the answers you typed in.)\n");
    printf("Then type your favorite integer number and finally click enter to start the game.");
    scanf("%d", &dummy);
    }
    
    printf("\n\nHit = right number on right spot. \nMiss = right number on wrong spot. \nGood luck.\n" );
    int key = 1;
    int lives;
    printf("Enter how many lives (guess chances) do you want to give: ");
    scanf("%d", &lives);
    
    for(int x=0 ; x < lives; x++)
    {
        //Read in the guess
        if(((lives-x)!=1)){printf("\n--->You have: %d lives left. Also if you get tired enter 121 for autosolving.\n", lives-x);}
        else{printf("\n ---> Last try! \n");}
        for(int i =0; i < 4; i++){
            printf("Enter guess # %d: ", i+1);
            scanf("%d", &arr2[i]);
            if(arr2[i]==121){
                goto label;
            }
        }
        
        if(0){
        label:
        printf("\nEntered secret superguesser. Now bruteforcing the answer... This is why you never only use digits for passwords.\n");
            sleep(3);
        int maxx = 0;
        for(int i=0; i<4; i++){
            if(maxx < *&arr1[i]){
                maxx = *&arr1[i];
            }
        }
        for(int a1=0;a1<=maxx;a1++){
        for(int a2=0;a2<=maxx;a2++){
        for(int a3=0;a3<=maxx;a3++){
        for(int a4=0;a4<=maxx;a4++){
            arr2[0] = a1;
            arr2[1] = a2;
            arr2[2] = a3;
            arr2[3] = a4;
            printf("Computer guess: ");
            for(int abc=0;abc<4;abc++){
                printf("%d ", arr2[abc]);
                usleep(10000);
            }
            printf("\n");
            key = check(arr1, arr2, 4);
            if(key==1){
                goto win;
            }
        }
        }
        }
        }
        }
        
        //Check the guess
        key = check(arr1, arr2, 4);
        if(key==1){
            win:
            printf("\nGood job, you won! \n");
            printf("Your guess: ");
            proont(arr1);
            printf("The key:    \n\n");
            proont(arr2);
            break;
        }
    }
    if(key==0){printf("You lose, better luck next time! \n");}
    printf("End of Game! \n");
    return 0;
}
