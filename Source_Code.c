// SOURCE : CODE_WITH_HARRY .... C_Programming_Playlist__EXERCISE_9..
/*
        **************** ROCK, PAPER, & SCISSORS GAME ****************

In this game there are two players, player_1 will be the user and player_2 will be the computer.

**** Allow user to play this game in three rounds with computer.
**** Log the scores of the computer and the player.
**** Display the name of the winner at the end.

### You Have to display the name of the player during the game...so Task users name as an input from user
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   // The header file 'time.h' contains definitions of functions to get and manipulate date and time in program.

int Generate_Random_Number(int n)
{
    srand(time(NULL));   //the fuction srand() is used to initialise the random number generator by passing the argument seed.
                        // srand() function is from <stdlib.h>
    return rand() % n;
}

int Score_Counter_User(int n)
{
    static int point_user = 0;
    
    switch (n)
    {
    case 0:
        point_user = point_user + 1;
        break;

    case 1:
        point_user = point_user + 2;
        break;

    case 2:
        point_user = point_user + 0;
        break;    
    }

    return point_user;
}

int Score_Counter_Computer(int n)
{
    static int point_computer = 0;

    switch (n)
    {
    case 0:
        point_computer = point_computer + 1;
        break;

    case 1:
        point_computer = point_computer + 2;
        break;

    case 2:
        point_computer = point_computer + 0;
        break;    
    }

    return point_computer;
}

int Match_Counter_Computer(int n)
{
    static int match_computer = 0;

    switch (n)
    {
    case 0:
        match_computer = match_computer + 1;
        break;

    case 1:
        match_computer = match_computer + 2;
        break;

    case 2:
        match_computer = match_computer + 0;
        break;    
    }

    return match_computer;
}

int Match_Counter_User(int n)
{
    static int match_user = 0;

    switch (n)
    {
    case 0:
        match_user = match_user + 1;
        break;

    case 1:
        match_user = match_user + 2;
        break;

    case 2:
        match_user = match_user + 0;
        break;    
    }

    return match_user;
}

int Start_Game (char user[], int n)
{
     int input, computer;

    for (int i = 0; i < n; i++)
    {
        printf("\n\nROUND%d :\n",i+1);
        label_2 : 
        printf("Enter the Input.....\t1 for Rock \t2 for Paper \t0 for Scisor\n");
        printf("%s\'s Turn :\t", user);
        scanf("%d", &input);

        switch (input)
        {
        case 1 :
            printf("\n\nYou have given *ROCK* .....\n");
            computer = Generate_Random_Number(3);
            switch (computer)
            {
            case 1:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *ROCK*...\n\t\tSo..Its *DRAW*....\n\nBoth will be given 1 point...\n");
                Score_Counter_Computer(0);
                Score_Counter_User(0);
                break;
            case 2:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *PAPER*...\n\t\tSo..Computer *WINS*...\n\nComputer 2 points and %s 0 points\n", user);
                Score_Counter_Computer(1);
                Score_Counter_User(2);
                break;
            case 0:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *SCISOR*...\n\t\tSo..%s *WINS*...\n\nComputer 0 points and %s 2 points\n", user, user);
                Score_Counter_Computer(2);
                Score_Counter_User(1);
                break;
            }
            break;
        
        case 2 :
            printf("\n\nYou have given *PAPER* .....\n");
            computer = Generate_Random_Number(3);
            switch (computer)
            {
            case 1:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *ROCK*...\n\t\tSo..%s *WINS*...\n\nComputer 0 points and %s 2 points\n", user, user);
                Score_Counter_Computer(2);
                Score_Counter_User(1);
                break;
            case 2:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *PAPER*...\n\t\tSo..Its *DRAW*....\n\nBoth will be given 1 point...\n");
                Score_Counter_Computer(0);
                Score_Counter_User(0);
                break;
            case 0:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *SCISOR*...\n\t\tSo..Computer *WINS*...\n\nComputer 2 points and %s 0 points\n", user);
                Score_Counter_Computer(1);
                Score_Counter_User(2);
                break;
            }
            break;

        case 0 :
            printf("\n\nYou have given *SCISOR* .....\n");
            computer = Generate_Random_Number(3);
            switch (computer)
            {
            case 1:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *ROCK*...\n\t\tSo..Computer *WINS*...\n\nComputer 2 points and %s 0 points\n", user);
                Score_Counter_Computer(1);
                Score_Counter_User(2);
                break;
            case 2:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *PAPER*...\n\t\tSo..%s *WINS*...\n\nComputer 0 points and %s 2 points\n", user, user);
                Score_Counter_Computer(2);
                Score_Counter_User(1);
                break;
            case 0:
                printf("Now Its Computer's Turn :...........Taking Computer's Input..... and ....\n");
                printf("Computer has given *SCISOR*...\n\t\tSo..Its *DRAW*....\n\nBoth will be given 1 point...\n");
                Score_Counter_Computer(0);
                Score_Counter_User(0);
                break;
            }
            break;

        default:
            printf("ERROR : PLZ Enter a Valid Input...\n");
            goto label_2;
            break;
        }
    }

}

int Result_Game (char user[], int score_computer, int score_user)
{
    printf("\n\n\n>>>>>>>>>>>>>>> COUNTING THE SCORE <<<<<<<<<<<<<<<<<\n\n");
    printf("COMPUTER   Has Got %d Points.\n%s Has Got %d Points\n", score_computer, user, score_user);

    if (score_computer > score_user)
    {
        printf("\nThe Winner Is\t~~~~~~~~~COMPUTER~~~~~~~~~~\nbETTER LUCK NEXT TIME");
        Match_Counter_Computer(1);
        Match_Counter_User(2);
        
    }
    else if (score_user > score_computer)
    {
        printf("\nThe Winner Is\t~~~~~~~~~%s~~~~~~~~~~\nCONGRATULATION YOU HAVE WON !!!!!!!!!", user);
        Match_Counter_Computer(2);
        Match_Counter_User(1);
    }
    else
    {
        printf("THE MATCH HAS BEEN DRAWN....\n");
        Match_Counter_Computer(0);
        Match_Counter_User(0);
    }
}

int main()
{
    char user[11];
    int input_1, input_2;
    char input_3;
    int round_number, series_match;
    int score_user, score_computer, Match_Computer, Match_User;

    printf("\n\n************ \"ROCK, PAPER, & SCISORS GAME\" ************\n\n\n");

    label_2:
    printf("Player_1 : USER   and   Player_2 : Computer\nPress 4 to Play Series and Press 6 to Play Quick Match\nPress 5 to Quit The Game\n");
    scanf("%d", &input_1);

    switch (input_1)
    {
    case 6 :
        label_3:
        printf("\n\n\n######### QUICK MATCH #########\n\n");
        printf("\nEnter Your Name (Maximum 10 characters) :\t");
        getchar();
        gets(user);

        label_4:    
        printf("\nEnter How Many Rounds You Want to play (Upto 10 Rounds Are Allowed)   ** Enter 0 To Exit The Match **\n");
        scanf("%d", &round_number);

        if (round_number == 0)
        {
            printf("\nExiting the match.....\n");
            goto label_2;
        }
        else if (round_number < 11)
        {
            Start_Game(user, round_number);

            score_computer = Score_Counter_Computer(3);
            score_user = Score_Counter_User(3);

            printf("\n\nEnter Any Key to Get Results\n");
            scanf("%c", &input_3);

            Result_Game(user, score_computer, score_user);
            goto label_3;
        }
        else
        {
            printf("..... Sorry!! You can Play Upto 10 Rounds In A Single Match .....");
            goto label_4;
            
        }
        break;

    case 4 :
        label_5:
        printf("\n*** Each Match Will Have 3 Rounds ***\nEnter How Many Matches You Want to play In This Series (Only 3, 5 or 7 Matches Are Allowed)   ** Enter 0 To Exit The Match **\n");
        scanf("%d", &series_match);

        label_6:

            if (series_match == 0)
            {
                printf("\nExiting the match.....\n");
                goto label_2;
            }

            else if (series_match == 3)
            {
                printf("\n\n\n######### SERIES OF %d MATCHES #########\n\n", series_match);

                printf("\nEnter Your Name (Maximum 10 characters) :\t");
                getchar();
                gets(user);

                for (int i = 0; i < 3; i++)
                {
                    printf("\n\n\n**** MATCH %d ****\n\n", i+1);

                    Start_Game(user, 3);

                    score_computer = Score_Counter_Computer(3);
                    score_user = Score_Counter_User(3);

                    Result_Game(user, score_computer, score_user);
                }
            }

            else if (series_match == 5)
            {
                printf("\n\n\n######### SERIES OF %d MATCHES #########\n\n", series_match);

                printf("\nEnter Your Name (Maximum 10 characters) :\t");
                getchar();
                gets(user);

               for (int i = 0; i < 3; i++)
                {
                    printf("\n\n\n**** MATCH %d ****\n\n", i+1);

                    Start_Game(user, 3);

                    score_computer = Score_Counter_Computer(3);
                    score_user = Score_Counter_User(3);

                    Result_Game(user, score_computer, score_user);
                }
            }

            else if (series_match == 7)
            {
                printf("\n\n\n######### SERIES OF %d MATCHES #########\n\n", series_match);

                printf("\nEnter Your Name (Maximum 10 characters) :\t");
                getchar();
                gets(user);

                for (int i = 0; i < 3; i++)
                {
                    printf("\n\n\n**** MATCH %d ****\n\n", i+1);

                    Start_Game(user, 3);

                    score_computer = Score_Counter_Computer(3);
                    score_user = Score_Counter_User(3);

                    Result_Game(user, score_computer, score_user);
                    
                }
            }

            else
            {
                printf("..... Sorry!! You can Choose Only 3, 5 or 7 Matches For A Series .....");
                goto label_5;
            }
        

        
        Match_Computer = Match_Counter_Computer(3);
        Match_User = Match_Counter_User(3);

        printf("\n\nEnter Any Key To Get Result...\n");
        scanf("%c", &input_3);

        printf("\n\n\n>>>>>>>>>>>>>>> ****** SUMMERIZING THE RESULT ****** <<<<<<<<<<<<<<<<<\n\n");
        printf("COMPUTER   Has  Won %d Matches.\n%s Has  Won %d Matches\n", Match_Computer/2, user, Match_User/2);

        if (Match_Computer > Match_User)
        {
            printf("\nThe Winner Of The Series Is\t~~~~~~~~~ COMPUTER ~~~~~~~~~~\nbETTER LUCK NEXT TIME");
        }
        else if (Match_User > Match_Computer)
        {
            printf("\nThe Winner Of The Series Is\t~~~~~~~~~ %s ~~~~~~~~~~\nCONGRATULATION YOU HAVE WON !!!!!!!!!", user);
        }
        else
        {
            printf("THE SERIES HAS BEEN DRAWN....\n");
        }
        
        label_7:
        printf("\n\nWhat do You Choose.....       Press  1 To Continue With Series of %d Matches      or  Press  0 To Back To Previous Menu      or  Press 5 To Quit The Game.....\n", series_match);
        scanf("%d", &input_2);

       switch (input_2)
       {
       case 1 :
           goto label_6;
           break;

        case 0 :
           goto label_5;
           break;

        case 5 :
           goto end;
           break;
       
       default:
            printf("\nPlease Enter A Valid Input\n\n");
            goto label_7;
           break;
       }
        
        break;


    case 5 :
        printf("\n\nQuitting the game................. Thank You For Playing ............");
        goto end;

    default:
        printf("\nError : Enter A Valid Input\n");
        goto label_2;
        break;
    }

    /*printf("\nEnter Your Name (Maximum 10 characters) :\t");
    getchar();
    gets(user);
    printf("\nEnter How Many Rounds You Want to play (Only 3, 5 and 9 Rounds Are Allowed)   ** Enter 0 To Exit The Match **\n");
    scanf("%d", &round_number);

    switch (round_number)
    {
    case 0 :
        printf("\nExiting the match.....\n");
        break;

    case 3 :
        Start_Game(user, 3);

        score_computer = Score_Counter_Computer(3);
        score_user = Score_Counter_User(3);

        Result_Game(user, score_computer, score_user);
        break;

    case 5 :
        Start_Game(user, 5);

        score_computer = Score_Counter_Computer(3);
        score_user = Score_Counter_User(3);

        Result_Game(user, score_computer, score_user);
        break;

    case 9 :
        Start_Game(user, 9);

        score_computer = Score_Counter_Computer(3);
        score_user = Score_Counter_User(3);

        Result_Game(user, score_computer, score_user);
        break;
    
    default:
        printf("..... Sorry!! You can Only 3, 5 or 9 Rounds In A Single Match .....");
        break;
    }*/
    
    //printf("Enter Your Name(Maximum 10 characters) :\t");
    //gets(user);

    //Start_Game(user, 5);
    //score_computer = Score_Counter_Computer(3);
    //score_user = Score_Counter_User(3);

    //Result_Game(user, score_computer, score_user);
   
    //score_computer = Score_Counter_Computer(3);
    //score_user = Score_Counter_User(3);

    //Result_Game(user, score_computer, score_user);

    end: 
    return 0;
}