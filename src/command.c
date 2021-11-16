#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"
#include "matrix.h"
#include "listdinpos.h"
#include "q_pesanan.h"
#include "main.h"

char mobita = '8';

void wipeScreen()
{
    printf("%s", wipe);
}

void advanceOrders(Queue *orders, ListLinked *todo)
{
    ElType_Queue ord;
    while (HEAD_TSERVE(*orders) <= time_game)
    {
        dequeue(orders, &ord);
        insertFirst_ListOrder(todo, ord.tServe, ord.pickUp, ord.dropOff, ord.item, ord.pTime);
    }
    if (!isEmpty_Queue(*orders))
    {
        displayQueue(*orders);
        displayList_ListOrder(*todo);
    }
}

void move(Matrix adj, ListDin points)
{
    boolean found = false;
    IdxType x = indexOf_ListDin(points, mobita);
    int input = IDX_UNDEF;
    ListDin temp;
    CreateListDin(&temp, 26);
    for (int i = 0; i < COLS(adj); i++)
    {
        if (ELMT_MATRIX(adj, x, i) == ADJACENT)
            insertLast_ListDin(&temp, ELMT_LISTDIN(points, i), NAME(points, i));
    }
    while (!found)
    {
        printf("\nCities Mobita can reach:\n\n");
        displayList_ListDin(temp);
        printf("\nEnter the number of the city you want Mobita to go to! (Enter \"0\" to return)\n\n");
        printf("ENTER CITY NUMBER: ");
        advWord();
        sscanf(currentWord.contents, "%d", &input);
        if (input == 0)
        {
            found = true;
            printf("\n\"Mobita shakes his head and decides to stay at his current city. Mobita remembers");
            printf("\nDoraemonangis telling him he should think before he acts.\"\n\n");
        }
        else if (isIdxEff_ListDin(temp, input - 1))
        {
            found = true;
            mobita = NAME(temp, input - 1);
            printf("\n\"Mobita Hapily moves towards city %c at coordinates ", NAME(temp, input - 1));
            TulisPOINT(ELMT_LISTDIN(temp, input - 1));
            printf(". You can hear him humming\nas he thinks about all the money he is going to make.\"\n\n");
        }
        else
        {
            printf("\n\"Entered a wrong city number, Nobita gained <Confusion> status.\n");
            printf("Nobita scrathed his head and did <nothing>.\"\n");
        }
    }
    dealocate(&temp);
}

void getColor(char **color, Matrix adj, ListDin points,char loc)
{
    IdxType x = indexOf_ListDin(points, mobita), y = indexOf_ListDin(points, loc);
    if (x == y)
        *color = mob_color;
    else if (ELMT_MATRIX(adj, x, y) == ADJACENT)
        *color = dest_color;
    else
        *color = none_color;
}

void displayMap(Matrix map, Matrix adj, ListDin points)
{
    char *color;

    printf("%s", bg_color);
    for (int i = 0; i < COLS(map) + 1; i++)
        printf("* ");
    printf("*");
    printf("%s\n", normal);

    for (int i = 0; i < ROWS(map); i++)
    {
        printf("%s* ", bg_color);
        for (int j = 0; j < COLS(map); j++)
        {
            getColor(&color, adj, points, ELMT_MATRIX(map, i, j));
            printf("%s%c%s ", color, ELMT_MATRIX(map, i, j), clear);
        }
        printf("*%s\n", normal);
    }
    
    printf("%s", bg_color);
    for (int i = 0; i < COLS(map) + 1; i++)
        printf("* ");
    printf("*");
    printf("%s\n", normal);
}

int parseCommand() // simple hash penjumlahan char
{
    int tally = 0;

    for (int i = 0; i < currentWord.length; i++)
        tally += currentWord.contents[i];

    return tally;
}
// Commands:
// PREGAME:
// NEW GAME -> 548
// EXIT -> 314
// LOAD GAME -> 602
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

Queue parseOrders(char cfg[][CAPACITY_WORDMACHINE])
{
    int x, y;
    Time tserve, perish;
    char pick, drop, item;
    Queue orders;
    CreateQueue(&orders);

    sscanf(cfg[2], "%d", &x);
    x = 2 * x + 4;
    sscanf(cfg[x++], "%d", &y);
    for (int i = 0; i < y; i++)
    {
        sscanf(cfg[i + x], "%d %c %c %c %d", &tserve, &pick, &drop, &item, &perish);
        enqueue(&orders, createOrder(tserve, pick, drop, item, perish));
    }
    return orders;
}

int Menu(char cfg[][CAPACITY_WORDMACHINE])
{
    int command, menu = 0;
    boolean found = false;

    wipeScreen();
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

int Game(char cfg[][CAPACITY_WORDMACHINE])
{
    int command, x;
    boolean running = 1;
    Matrix map, adj;
    ListDin locs;
    Queue ords;
    ListLinked todo;

    // Reading Configs
    locs = parsePoints(cfg);
    map = parseMap(cfg, locs);
    adj = parsePath(cfg);
    ords = parseOrders(cfg);
    startTime();
    advTime();
    advanceOrders(&ords, &todo);

    // Game
    // wipeScreen();
    // displayStats();
    printf("ENTER COMMAND: ");
    startWord();
    command = parseCommand();
    while (running)
    {
        wipeScreen();
        switch (command)
        {
        case 311:
            /* MOVE */
            move(adj, locs);
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
            printf("\n\"Mobita has forgotten what his city looks like, but remembers he has the magical map\n");
            printf("that Doraemonangis gave him that shows where each city is and its details.\"\n\n");
            printf("Map:\n\n");
            displayMap(map, adj, locs);
            printf("\n\nLegend:\n");
            printf("%sYellow%s : Mobita is here\n", mob_color, clear);
            printf("%sRed%s    : Mobita can pick up items at this city\n", pickup_color, clear);
            printf("%sBlue%s   : Mobita can drop off items at this city\n", dropoff_color, clear);
            printf("%sGreen%s  : Mobita can move to this city\n\n", dest_color, clear);
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