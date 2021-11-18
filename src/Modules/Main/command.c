#include "main.h"

void displayStats(ListDin locations, Queue orders, ListLinked todo)
{
    if (mobita != HEADQUARTERS)
        printf("Mobita sedang berada di %c pada koordinat ", mobita);
    else
        printf("Mobita sedang berada di Headquarters pada koordinat ");
    TulisPOINT(ELMT_LISTDIN(locations, indexOf_ListDin(locations, mobita)));
    printf(".\nWaktu: %d\n", time_game);
    printf("Saldo: %d Yen\n", cash);
    printf("Masih ada %d pesanan yang tersisa.\n\n", length_Queue(orders) + length_ListOrder(todo));
}

void advanceTurn(Queue *orders, ListLinked *todo, ListLinked *inpro, Stack *bag)
{
    Stack temp;
    item ord, trash;
    UseSpeed();
    temp = advPerishable(bag);
    while (!isEmpty_Stack(temp))
    {
        pop(&temp, &ord);
        deleteItem_ListOrder(inpro, &trash, ord);
    }
    advTime(SPEED(abilities), numHeavy());
    while (!isEmpty_Queue(*orders) && TSERVE(HEAD(*orders)) <= time_game)
    {
        dequeue(orders, &ord);
        insertLast_ListOrder(todo, ord);
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
    loreStart();
    printf("\"Mobita mengendarai sepeda ajaib yang diberikan Doraemonangis menuju kota lain.\"\n");
    loreEnd();
    while (!found)
    {
        printf("\nKota dalam jangkauan Mobita:\n\n");
        displayList_ListDin(temp);
        printf("\nMasukkan angka kota yang ingin dituju! (Masukkan \"0\" untuk kembali)\n\n");
        printf("ENTER CITY NUMBER: ");
        advWord();
        sscanf(currentWord.contents, "%d", &input);
        if (input == 0)
        {
            found = true;
            loreStart();
            printf("\n\"Mobita menggelengkan kepala dan memutuskan untuk tidak berpindah kota terlebih dahulu. Ia");
            printf("\ningat Doraemonangis pernah bernasihat untuk berpikir dengan matang sebelum bertindak.\"\n\n");
            loreEnd();
        }
        else if (isIdxEff_ListDin(temp, input - 1))
        {
            found = true;
            mobita = NAME(temp, input - 1);
            loreStart();
            printf("\n\"Mobita dengan girang bergerak ke kota %c di koordinat ", NAME(temp, input - 1));
            TulisPOINT(ELMT_LISTDIN(temp, input - 1));
            printf(". Sambil bersenandung\nia mulai memikirkan tentang banyaknya uang yang akan ia buat.\"\n\n");
            loreEnd();
        }
        else
        {
            loreStart();
            printf("\n\"Angka kota tujuan salah! Mobita terkena status <Kebingungan>.\n");
            printf("Mobita menggarukkan kepala dan tidak melakukan apa-apa.\"\n");
            loreEnd();
        }
    }
    dealocate(&temp);
}

void pickup(ListLinked *todo, ListLinked *inpro, Stack *bag)
{
    item it;
    if (!isFull_Tas(*bag))
    {
        deleteAt_ListOrder(todo, &it, indexOfPick_ListOrder(*todo, mobita));
        if (TYPE(it) == 'H')
            ActIncHeavy();
        insertFirst_ListOrder(inpro, it);
        push(bag, it);
    }
    printf("Berhasil pickup item!\n");
}

void dropoff(ListLinked *inpro, Stack *bag)
{
    item it, src;
    pop(bag, &it);
    deleteItem_ListOrder(inpro, &src, it);
    printf("\ndelivered: ");
    displayItem(src);
    printf("\n");
    switch (TYPE(it))
    {
    case 'N':
        SuccessNormal();
        break;
    case 'H':
        SuccessHeavy();
        break;
    case 'P':
        increaseCapacity(SuccessPerishable());
        break;
    case 'V':
        SuccessVIP();
        break;
    
    default:
        break;
    }
}

void returnOrder(ListLinked *todo, ListLinked *inpro, Stack *bag)
{
    item it, ori;
    pop(bag, &it);
    if (isHeavy(it))
        HEAVY(abilities) -= 1;
    REDUCT(abilities) = false;
    deleteItem_ListOrder(inpro, &ori, it);
    insertLast_ListOrder(todo, ori);
}

void getColor(char **color, Matrix adj, ListDin points, ListLinked todo, ListLinked inpro, char loc)
{
    IdxType x = indexOf_ListDin(points, mobita), y = indexOf_ListDin(points, loc);
    if (x == y)
        *color = mob_color;
    else if (indexOfDrop_ListOrder(inpro, loc) != IDX_UNDEF)
        *color = dropoff_color;
    else if (indexOfPick_ListOrder(todo, loc) != IDX_UNDEF)
        *color = pickup_color;
    else if (ELMT_MATRIX(adj, x, y) == ADJACENT)
        *color = dest_color;
    else
        *color = none_color;
}

void displayMap(Matrix map, Matrix adj, ListDin points, ListLinked todo, ListLinked inpro)
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
            getColor(&color, adj, points, todo, inpro, ELMT_MATRIX(map, i, j));
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

int Menu(char cfg[][CAPACITY_WORDMACHINE])
{
    int command, menu = 0;
    boolean found = false, load = false;

    wipeScreen();
    loreStart();
    printf("\"Selamat datang di Kurir Barang Mobita...\n");
    printf("Masukkan (NEW GAME) untuk mulai bermain atau (LOAD GAME) untuk\n");
    printf("melanjutkan permainan. Masukkan (EXIT) untuk berhenti bermain.\"\n\n");
    loreEnd();
    printf("Masukan (->Masukkan yang di dalam kurung<-):\n");
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
            found = parseConfig(cfg, load);
            while (!found)
            {
                printf("\nNama config tidak ditemukan. Coba periksa ulang masukan anda.\n\n");
                printf("ENTER CONFIG FILE: ");
                startWord();
                found = parseConfig(cfg, load);
            }
            menu = 1;
            wipeScreen();
            printf("Berhasil memulai permainan!\n\n");
            break;
        
        case 314:
            exit(0);
            break;
        
        case 602:
            load = 1;
            printf("ENTER CONFIG FILE: ");
            advWord();
            found = parseConfig(cfg, load);
            while (!found)
            {
                printf("\nNama config tidak ditemukan. Coba periksa ulang masukan anda.\n\n");
                printf("ENTER CONFIG FILE: ");
                startWord();
                found = parseConfig(cfg, load);
            }
            menu = 1;
            wipeScreen();
            printf("Berhasil memuat kemajuan, silahkan melanjutkan permainan!\n\n");
            break;

        default:
            printf("\nAnda memberikan masukan yang salah. Coba periksa ulang masukan anda.\n\n");
            printf("Masukan (->Masukkan yang di dalam kurung<-):\n");
            printf("1. (NEW GAME)\n");
            printf("2. (EXIT)\n");
            printf("3. (LOAD GAME)\n\n");
            printf("ENTER COMMAND: ");
            advWord();
            command = parseCommand();
            break;
        }
    }
    return load;
}

int Game(char cfg[][CAPACITY_WORDMACHINE], boolean load)
{
    int command, input, x;
    boolean running = 1, done;
    Matrix map, adj;
    ListDin locs;
    Queue ords;
    ListLinked todo, inpro;
    ListPos inv;
    Stack bag;

    // Reading Configs
    locs = parsePoints(cfg);
    map = parseMap(cfg, locs);
    adj = parsePath(cfg);
    ords = parseOrders(cfg);
    CreateListOrder(&todo);
    CreateListOrder(&inpro);
    CreateListPos(&inv);
    CreateStack(&bag);
    startTime();
    initTas(3);
    initCash(10000);
    initAbilities();

    // Game
    if (!load)
    {
        loreStart();
        printf("\"Dengan diberlakukannya PPKM selama setahun terakhir, usaha kecil milik orang tua Mobita sedikit lagi\n");
        printf("akan terpaksa gulung tikar. Namun untungnya, Mobita adalah anak yang berbakti dan bersedia membantu\n");
        printf("orang tuanya. Dalam upayanya untuk menggalang dana, Ia akhirnya mendaftar jadi kurir barang untuk\n");
        printf("toko online yang populer. Tidak hanya itu, temannya Doraemonangis pun ikut membantu dengan cara\n");
        printf("menyediakan gadget nan ajaib. Bisakah Mobita menjadi kurir terbaik se-Indonesia?\"\n\n");
        printf("\"Mobita memulai perjalanannya dari Headquarters yang sudah disediakan oleh Doraemonangis. Pada saat fajar\n");
        printf("menyingsing ia pun sudah bangun dan bersiap-siap. Mobita memulai perjalanannya.\"\n\n");
        loreEnd();
        printf("Jika pertama kali bermain, masukkan <HELP> untuk melihat aksi yang bisa Mobita lakukan.\n\n");
    }
    displayStats(locs, ords, todo);
    printf("ENTER COMMAND: ");
    startWord();
    command = parseCommand();
    while (running)
    {
        // wipeScreen();
        switch (command)
        {
        case 311:
            /* MOVE */
            move(adj, locs);
            advanceTurn(&ords, &todo, &inpro, &bag);
            break;
        case 555:
            /* PICK_UP */
            if (indexOfPick_ListOrder(todo, mobita) != IDX_UNDEF)
            {
                if (indexOfType_ListOrder(todo, 'V') == IDX_UNDEF)
                    pickup(&todo, &inpro, &bag);
                else if (getType_ListOrder(todo, indexOfPick_ListOrder(todo, mobita)) != 'V')
                {
                    loreStart();
                    printf("There's a VIP item\n");
                    loreEnd();
                }
                else
                    pickup(&todo, &inpro, &bag);
            }
            else
            {
                loreStart();
                printf("\n\"Mobita mencari-cari tempat untuk mengambil pesanan, namun ia tidak menemukannya. Setelah ia\n");
                printf("melihat daftar pesanannya, ia terkejut karena ternyata ia salah kota.\"\n\n");
                printf("Pesanan tidak ditemukan! Coba bergerak ke kota lain yang bertanda merah pada peta.\n\n");
                loreEnd();
            }
            break;
        case 623:
            /* DROP_OFF */
            if (isEmpty_Stack(bag))
            {
                printf("No orders taken yet");
            }
            else if (mobita != DROPOFF(TOP(bag)))
            {
                printf("Current order can not be dropped off here\n");
            }
            else if (indexOfType_ListOrder(todo,'V') != IDX_UNDEF)
            {
                if (TYPE(TOP(bag)) == 'V')
                    dropoff(&inpro, &bag);
                else
                {
                    printf("Not VIP, finish vip first\n");
                }
            }
            else
            {
                dropoff(&inpro, &bag);
            }
            break;
        case 480:
            /* RETURN */
            if (isEmpty_Stack(bag))
            {
                printf("Bag empty!");
            }
            else if (RETURN(abilities) > 0)
                returnOrder(&todo, &inpro, &bag);
            else
            {
                loreStart();
                printf("Mobita has no returns\n");
                loreEnd();
                printf("Do VIPS\n");
            }
            break;
        case 222:
            /* MAP */
            loreStart();
            printf("\n\"Mobita tiba-tiba lupa jalan, tapi untungnya Doraemonangis memberikan GPS ajaib yang\n");
            printf("dapat menunjukkan setiap kota yang bisa dikunjungi dan detilnya.\"\n\n");
            loreEnd();
            printf("Peta:\n\n");
            displayMap(map, adj, locs, todo, inpro);
            printf("\n\nLegenda:\n");
            printf("%sKuning%s : Mobita berada di sini\n", mob_color, clear);
            printf("%sMerah%s  : Mobita dapat mengambil pesanan di sini\n", pickup_color, clear);
            printf("%sBiru%s   : Pesanan diantarkan ke kota ini\n", dropoff_color, clear);
            printf("%sHijau%s  : Mobita bisa bergerak ke kota ini\n\n", dest_color, clear);
            break;
        case 405:
            /* TO_DO */
            loreStart();
            printf("\n\"Mobita merasa seperti ia melupakan sesuatu dan menjadi khawatir karena takut melupakan pesanan.\n");
            printf("Untungnya ia mempunyai catatan kiriman ajaib yang mencatat semua kiriman yang masuk.\"\n\n");
            loreEnd();
            printf("To Do List:\n\n");
            displayList_ListOrder(todo);
            printf("\n");
            break;
        case 875:
            /* IN_PROGRESS */
            printf("\nIn pro list:\n\n");
            displayList_ListOrder(todo);
            printf("\nBag: \n\n");
            displayStack(bag);
            break;
        case 240:
            /* BUY */
            if (mobita == HEADQUARTERS)
            {
                loreStart();
                printf("\"Mobita mulai merasa kesulitan menjadi seorang kurir barang. Karena berada di Headquarters, ia\n");
                printf("pun bergegas masuk untuk membeli gadget dari Doraemonangis.\"\n\n");
                loreEnd();

                done = false;
                do
                {
                    printf("Uang Anda sekarang: %d Yen\n", cash);
                    displayGadget();
                    printf("ENTER GADGET NUMBER: ");
                    advWord();
                    input = parseCommand() - 48;
                    if (input > 5 || input < 0)
                    {
                        loreStart();
                        printf("\n\"Mobita kebingungan mencari gadget yang sesuai karena semua gadget terlihat sangat bagus.\n");
                        printf("Mobita mengalami kegalauan yang mendalam dan merenungi nasib.\"\n\n");
                        loreEnd();
                        printf("Masukan pemain tidak sesuai. Tolong beri masukan yang sesuai.\n\n");
                    }
                    else
                        done = buy(input, &cash, &inv);
                } while (!done);
            }
            else
            {
                loreStart();
                printf("\"Mobita mulai merasa kesulitan menjadi seorang kurir barang. Namun karena ia tidak berada di\n");
                printf("Headquarters, ia pun hanya bisa meratapi nasib dengan sedih.\"\n\n");
                loreEnd();
            }
            break;
        case 718:
            /* INVENTORY */
            done = false;
            do
            {
                printf("\nInventory:\n\n");
                displayInventoryGadget(inv);
                printf("ENTER GADGET NUMBER: ");
                advWord();
                input = parseCommand() - 48;
                if (input > 5 || input < 0)
                {
                    loreStart();
                    printf("\n\"Mobita kebingungan mencari gadget yang sesuai karena semua gadget terlihat sangat bagus.\n");
                    printf("Mobita mengalami kegalauan yang mendalam dan merenungi nasib.\"\n\n");
                    loreEnd();
                    printf("Masukan pemain tidak sesuai. Tolong beri masukan yang sesuai.\n\n");
                }
                else
                {
                    x = inventory(input, &inv, TOP(bag));
                }
                switch (x)
                {
                case 0:
                    done = true;
                    break;
                case 1:
                    PTIME(TOP(bag)) = getPerTime_ListOrder(inpro, indexOfItem_ListOrder(inpro, TOP(bag)));
                    done = true;
                    break;
                case 2:
                    increaseCapacity(stack_capacity);
                    done = true;
                    break;
                case 3:
                    do
                    {
                        printf("ENTER CITY CHARACTER: ");
                        advWord();
                        if (currentWord.length == 1 && indexOf_ListDin(locs, currentWord.contents[0]) != IDX_UNDEF)
                            mobita = currentWord.contents[0];
                    } while (currentWord.length != 1 || indexOf_ListDin(locs, currentWord.contents[0]) == IDX_UNDEF);
                    
                    done = true;
                    break;
                case 4:
                    timeMachine();
                    done = true;
                    break;
                case 5:
                    ActReduct();
                    done = true;
                    break;
                default:
                    break;
                }
                break;
            } while (!done);
            
        case 680:
            /* SAVE_GAME */
            printf("Tried to <SAVE_GAME>, but command hasn't been implemented yet\n");
            break;
        case 297:
            /* HELP */
            printf("\nKegiatan yang Mobita dapat lakukan:\n");
            printf("1. <MOVE>        : Mobita bergerak ke kota yang berdekatan.\n");
            printf("2. <PICK_UP>     : Mobita mengambil pesanan yang datang pada lokasinya.\n");
            printf("3. <DROP_OFF>    : Mobita mengirimkan pesanan yang ia sudah antar pada lokasinya.\n");
            printf("4. <RETURN>      : Mobita membuka gapura ajaib dan mengembalikan pesanan teratas dalam tas.\n");
            printf("                   Anda mempunyai sisa %d kali penggunaan <RETURN>.\n", RETURN(abilities));
            printf("5. <MAP>         : Membuka GPS ajaib ala Doraemonangis.\n");
            printf("6. <TO_DO>       : Membuka catatan kiriman ajaib ala Doraemonangis.\n");
            printf("7. <IN_PROGRESS> : Melihat isi tas dan kiriman yang sedang dilaksanakan.\n");
            printf("8. <BUY>         : Mobita dapat membeli gadget jika ia berada di Headquarters.\n");
            printf("9. <INVENTORY>   : Mobita merogoh saku dan melihat gadget apa saja yang ia punya.\n");
            printf("10. <SAVE_GAME>  : Menyimpan kemajuan permainan dan kembali ke menu utama.\n\n");
            break;
        default:
            loreStart();
            printf("\"Perintah yang anda masukkan salah! Mobita terkena status <Kebingungan>.\n");
            printf("Mobita menggarukkan kepala dan tidak melakukan apa-apa.\"\n\n");
            loreEnd();
            printf("Masukkan (HELP) untuk melihat aksi yang Mobita bisa lakukan, atau\n");
            printf("masukkan perintah yang valid untuk melanjutkan permainan.\n\n");
            break;
        }
        displayStats(locs, ords, todo);
        printf("ENTER COMMAND: ");
        advWord();
        command = parseCommand();
    }
}