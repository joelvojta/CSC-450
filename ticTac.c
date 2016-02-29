#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#define SHMSZ 27


int main(int argc, char** argv)
{
    
    int shmid;
    key_t key;
    char *board, *s;
    
    key = 5678;
    
    //create a segment of shared memory
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return -1;
    }
    
     //Now we attach the segment to our data space.
    if ((board = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        return -1;
    }
  
    //start the game
    printf("The Game has begun...\n");
    
    int sitDown == NULL;
    
    //establish an array for the game
    char *board[9];
    
    //the board setup
    // 0 1 2
    // 3 4 5
    // 6 7 8
    
    pid_t pid = fork();
    if(pid == 0)
    {
        //I am the child
        printf("Child's turn");
        //choose a number between 0 and 8
        int sitDown == (rand() % 9);
    
        //if that spot's taken, try again
        while(board[sitDown] != NULL)
        {
            int sitDown == (rand() % 9);
        }
        //place an X on the random spot
        else
        {
            board[sitDown] = "X";
        }
        
        //check to see if they won
        if (board[0,1,2] == "X" || board[3,4,5] == "X" || board[6,7,8] == "X" || //horizontal boxes
            board[0,3,6] == "X" || board[1,4,7] == "X" || board[2,5,8] == "X" || //vertical boxes
            board[0,4,8] == "X" || board[2,4,6] == "X" ||)                       //diagonal boxes
            {
                printf("The Child Wins");   //Display victory message
                printf(board);              //Display the final board
                exit(0);                    //Exit the Game
            }
    }
    else
    {
        //I am the parent
        printf("Parent's Turn");
        //choose a number between 0 and 8
        int sitDown == (rand() % 9);
    
        //if that spot's taken, try again
        while(board[sitDown] != NULL)
        {
            int sitDown == (rand() % 9);
        }
        //place an X on the random spot
        else
        {
            board[sitDown] = "O";
        }
        
        //check to see if they won
        if (board[0,1,2] == "O" || board[3,4,5] == "O" || board[6,7,8] == "O" || //horizontal boxes
            board[0,3,6] == "O" || board[1,4,7] == "O" || board[2,5,8] == "O" || //vertical boxes
            board[0,4,8] == "O" || board[2,4,6] == "O" ||)                       //diagonal boxes
            {
                printf("The Parent Wins");  //Display victory message
                printf(board);              //Display the final board
                exit(0);                    //Exit the Game
            }
    }
}