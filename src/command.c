#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

int parseCommand() // simple hash penjumlahan char
{
    // Commands:
    // PREGAME:
    // NEW GAME: 548
    // EXIT: 314
    // LOAD GAME: 602
    // INGAME:
    // MOVE -> 311
    // PICK_UP -> 555
    // DROP_OFF -> 623
    // RETURN -> 480
    // MAP -> 222
    // TO_DO -> 405
    // IN_PROGRESS -> 875
    // BUY -> 240
    // INVENTORY -> 718
    // HELP -> 297
    // SAVE_GAME -> 680
    int tally = 0;

    for (int i = 0; i < currentWord.length; i++)
        tally += currentWord.contents[i];

    return tally;
}

int Menu(char cfg[][CAPACITY_WORDMACHINE])
{
    int command, menu = 0;
    boolean found = false;

    printf("Hello, Welcome to Nobita's Delivery Service...\n");
    printf("Enter (NEW GAME) to start playing, or (LOAD GAME) to play\n");
    printf("a previously saved game. Enter (EXIT) to stop playing.\n\n");
    printf("Commands (->Enter the word between the brackets<-):\n");
    printf("1. (NEW GAME)\n");
    printf("2. (EXIT)\n");
    printf("3. (LOAD GAME)\n\n");
    printf("ENTER COMMAND: ");
    startWord();
    command = parseCommand();
    while (menu == 0)
    {
        switch (command)
        {
        case 548:
            printf("ENTER CONFIG FILE: ");
            advWord();
            found = parseConfig(cfg, currentWord.contents, currentWord.length, 0);
            while (!found)
            {
                printf("\nYou entered the wrong config file!\n\n");
                printf("ENTER CONFIG FILE: ");
                startWord();
                found = parseConfig(cfg, currentWord.contents, currentWord.length, 0);
            }
            menu = 1;
            break;
        
        case 314:
            exit(0);
            break;
        
        case 602:
            printf("ENTER CONFIG FILE: ");
            advWord();
            found = parseConfig(cfg, currentWord.contents, currentWord.length, 1);
            while (!found)
            {
                printf("\nYou entered the wrong config file!\n\n");
                printf("ENTER CONFIG FILE: ");
                startWord();
                found = parseConfig(cfg, currentWord.contents, currentWord.length, 1);
            }
            menu = 1;
            break;

        default:
            printf("\nYou entered the wrong command!\n\n");
            printf("Commands (->Enter the word between the brackets<-):\n");
            printf("1. (NEW GAME)\n");
            printf("2. (EXIT)\n");
            printf("3. (LOAD GAME)\n");
            printf("ENTER COMMAND: ");
            advWord();
            command = parseCommand();
            break;
        }
    }
    return 1;
}

int Game()
{
    int command;
    boolean running = 1;
    printf("ENTER COMMAND: ");
    startWord();
    command = parseCommand();
    while (running)
    {
        switch (command)
        {
        case 311:
            /* MOVE */
            printf("Tried to <MOVE>, but command hasn't been implemented yet\n");
            break;
        case 555:
            /* PICK_UP */
            printf("Tried to <PICK_UP>, but command hasn't been implemented yet\n");
            break;
        case 623:
            /* DROP_OFF */
            printf("Tried to <DROP_OFF>, but command hasn't been implemented yet\n");
            break;
        case 480:
            /* RETURN */
            printf("Tried to <RETURN>, but command hasn't been implemented yet\n");
            break;
        case 222:
            /* MAP */
            printf("Tried to <MAP>, but command hasn't been implemented yet\n");
            break;
        case 405:
            /* TO_DO */
            printf("Tried to <TO_DO>, but command hasn't been implemented yet\n");
            break;
        case 875:
            /* IN_PROGRESS */
            printf("Tried to <IN_PROGRESS>, but command hasn't been implemented yet\n");
            break;
        case 240:
            /* BUY */
            printf("Tried to <BUY>, but command hasn't been implemented yet\n");
            break;
        case 718:
            /* INVENTORY */
            printf("Tried to <INVENTORY>, but command hasn't been implemented yet\n");
            break;
        case 680:
            /* SAVE_GAME */
            printf("Tried to <SAVE_GAME>, but command hasn't been implemented yet\n");
            break;
        case 297:
            /* HELP */
            printf("\nCommands you can tell Nobita to do:\n");
            printf("1. <MOVE>        : Tells Nobita to move to an adjacent city.\n");
            printf("2. <PICK_UP>     : Tells Nobita to pick up an order at the current city.\n");
            printf("3. <DROP_OFF>    : Tells Nobita to drop off the top order at the current city.\n");
            printf("4. <RETURN>      : Tells Nobita to return a perishable item to the pick up point.\n");
            printf("5. <MAP>         : Opens the map to see the game state.\n");
            printf("6. <TO_DO>       : Opens the \"To Do\" list.\n");
            printf("7. <IN_PROGRESS> : Opens the \"In Progress\" list.\n");
            printf("8. <BUY>         : Opens the list of gadgets you can buy if you are at your headquarters.\n");
            printf("9. <INVENTORY>   : Opens your inventory to see your current gadgets.\n");
            printf("10. <SAVE_GAME>  : Saves game state and returns to menu.\n\n");
            break;
        default:
            printf("\n\"Entered a wrong command, Nobita gained <Confusion> status.\n");
            printf("Nobita scrathed his head and did <nothing>.\"\n\n");
            printf("Enter the command (HELP) to see what actions Nobita can take,\n");
            printf("or enter any valid command to continue the game.\n\n");
            break;
        }
        printf("ENTER COMMAND: ");
        advWord();
        command = parseCommand();
    }
}