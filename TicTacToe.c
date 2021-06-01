#include <stdio.h>
#include <stdlib.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

int checkForWin()
{

    // Horizontal Winning Condition begins
    if (board[1] == board[2] && board[2] == board[3])
        return 1;
    else if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    // Horizontal Winning Condition ends

    // Vertical Winning Condition begins
    else if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    // Vertical Winning Condition ends

    // Diagonal Winning Condition begins
    else if (board[1] == board[5] && board[5] && board[9])
        return 1;
    else if (board[3] == board[5] && board[5] == board[7])
        return 1;
    // Diagonal Winning Condition ends

    // Checking for draw begins
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
    {
        return 0;
    }
    // Checking for draw ends

    else
    {
        return -1;
    }
}

void displayBoard()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player-1: X and Player-2: O\n\n\n");
    printf("\t    |    |  \n");
    printf("\t %c  | %c  | %c \n", board[1], board[2], board[3]);
    printf("\t____|____|____\n");
    printf("\t    |    |  \n");
    printf("\t %c  | %c  | %c \n", board[4], board[5], board[6]);
    printf("\t____|____|____\n");
    printf("\t    |    |  \n");
    printf("\t %c  | %c  | %c \n", board[7], board[8], board[9]);
    printf("\t    |    | \n\n");
}
void markBoard(char mark)
{
    if (choice == 1 && board[1] == '1')
    {
        board[1] = mark;
    }
    else if (choice == 2 && board[2] == '2')
    {
        board[2] = mark;
    }
    else if (choice == 3 && board[3] == '3')
    {
        board[3] = mark;
    }
    else if (choice == 4 && board[4] == '4')
    {
        board[4] = mark;
    }
    else if (choice == 5 && board[5] == '5')
    {
        board[5] = mark;
    }
    else if (choice == 6 && board[6] == '6')
    {
        board[6] = mark;
    }
    else if (choice == 7 && board[7] == '7')
    {
        board[7] = mark;
    }
    else if (choice == 8 && board[8] == '8')
    {
        board[8] = mark;
    }
    else if (choice == 9 && board[9] == '9')
    {
        board[9] = mark;
    }
    else
    {
        printf("Invalid Move\n");
        printf("Sorry, the row %d is already marked with %c\n", choice, board[choice]);
        player--;
    }
}
int main()
{
    int gameStatus;
    char mark;
    player = 1;
    do
    {
        displayBoard();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, Enter the number: ", player);
        scanf("%d", &choice);
        // set the correct character based on player turn
        mark = (player == 1) ? 'X' : 'O';

        //set board based on user choice or invaid move
        markBoard(mark);
        gameStatus = checkForWin();
        player++;
    } while (gameStatus == -1);

    if (gameStatus == 1)
    {
        printf("==> Player %d Wins\n\n", (player % 2) + 1);
    }
    else
    {
        printf("==> Game Draw\n\n");
    }

    return 0;
}