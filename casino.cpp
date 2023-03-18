#include <iostream>
#include <fstream>
#include <unistd.h>
#include <unordered_map>

//

long int balance;
int chips = 0;
int *chip = &chips;
bool newPlayer = false;
bool finished = false;
int waitSecond = 1000000;

//

bool balanceExists(); // checks if balance.txt exists, aka a first time player
void checkBalance(); // displays acct balance and active chips
void getChips(); // convert balance to chips
void cashOut(int *chip); // convert chips to balance
int mainRoom(); // main room hub loop thing

// GAMES // 
void slots(); // slot machines
void blackjack(); // blackjack
    void cards(int game, int players); // displays cards for blackjack or poker, depends on which (int game) and how many (int players) is chosen


// issues:
// random things when inputs are stupid numbers

int main() {
    if (!balanceExists()) {
        std::ofstream outfile ("balance.txt");
        outfile << "100" << std::endl;
        newPlayer = true;
    }
    std::fstream outfile;
    outfile.open("balance.txt", std::ios::in);
    outfile >> balance;
    if (newPlayer) {
        std::cout << "Welcome t' the Rat-a-Tat Catsino!" << std::endl;
        std::cout << "I see this is your first time here.";
        usleep(2 * waitSecond);
        std::cout << "Or maybe you're fakin' it...." << std::endl;
        usleep(waitSecond);
        std::cout << "Whateva'. Yer startin' off with 100 chips. Don't waste 'em at all." << std::endl;
        usleep(3 * waitSecond);
        std::cout << "...Or do. I don't give a rat's ass." << std::endl;
        usleep(waitSecond);
    } else {
        std::cout << "Welcome back t' the Rat-a-Tat Catsino!" << std::endl;

    }
    srand(time(NULL));
    while (!finished) {
        int choice = mainRoom();
        if (choice == 1) {
            slots();
        } else if (choice == 2) {
            blackjack();
        } else if (choice == 3) {
            getChips();
        } else if (choice == 4) {
            finished = true;
        } else {
            std::cout << "help";
            break;
        }
    }

    std::cout << "Whelp. See ya next time! Or maybe I won't." << std::endl;

    return 0;
}

bool balanceExists() {
    FILE *outfile;
    if (outfile = fopen("balance.txt", "r")) {
        return true;
    } else {
        return false;
    }
}

void checkBalance() {
    std::cout << "You have " << balance << " chips in your account, and currently have " << 
    chips << " chips on you." << std::endl;
}

void getChips() {
    std::cout << "How many chips ya want? Ya have " << balance << " in that account of yers." << std::endl;
    int chipsInput;
    std::cin >> chipsInput;
    while (true) {
        if (std::cin.fail() || chipsInput > balance || chipsInput < 1) {
            std::cout << "Not enough dough." << std::endl;
            std::cin >> chipsInput;
        } else {
            balance -= chipsInput;
            chips += chipsInput;
            break;
        }
    }
}


int mainRoom() {
    int choice;

    usleep(waitSecond);
    checkBalance(); 
    usleep(waitSecond);
    std::cout << "Pick a room?" << std::endl;
    usleep(waitSecond);
    std::cout << "1. Slots" << '\n' << "2. WIP (picks 1)" << '\n' <<
        "3. Get chips." << '\n' << "4. Cash out and exit." << std::endl;
        
    while (true) {
        std::cin >> choice;
        if (!std::cin || choice > 4 || choice < 1) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That's not an option ya dipwad!" << std::endl;
        } else {
            break;
        }
    }
    return choice;
}
    

void slots() {
    int choice = 0;
    int bet = 0;
    std::cout << "(DESCRIBE THE SLOTS AREA)" << std::endl;
    while (choice != 4) {
        if (choice == 0) {
            std::cout << "1. Lo-Lo" << '\n' << "2. Mid" << '\n' << "3.Hi-hi" << std::endl;
            std::cout << "(only hi risk, hi reward is open atm)" << std::endl;
            std::cout << "Which machine will ya pick? (0 to go back to main room)" << std::endl;
            while (true) {
                std::cin >> choice;
                if (choice == 0 ) {
                    return;
                }
                if (!std::cin || choice > 4 || choice < 1) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "That's not an option ya dipwad!" << std::endl;
                } else {
                    break;
                }
            }
        }

        if (choice == 1) {
            choice = 3;
        }

        else if (choice == 2) {
            choice = 3;
        }

        else if (choice == 3) {
            while (true) {
                if (bet == 0) {
                    checkBalance();
                    std::cout << "Enter your bet amount (-1 to go back to main room): " << std::endl;
                    std::cin >> bet;
                    if (bet == -1) {
                        return;
                    } else if (!std::cin || bet < -1 || bet > chips) {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "Not enough dough." << std::endl;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            chips -= bet;
            std::cout << "You've bet " << bet << " chips." << std::endl;

            usleep(waitSecond);

            std::string slotsOutput[3];
            for (int i = 0; i < 3; i++) {
                int rand = std::rand() % 100 + 1;
                /*
                1 = 20%
                2 = 17%
                3 = 14%
                4 = 11%
                5 = 8%
                6 = 5%
                7 = 3%
                8 = 2%
                9 = JACKPOT, 1%
                0 = WILDCARD, 8%
                */
                if (rand > 0 && rand <= 20) {
                    slotsOutput[i] = "1";
                } else if (rand > 20 && rand <= 37) {
                    slotsOutput[i] = "2";
                } else if (rand > 37 && rand <= 51) {
                    slotsOutput[i] = "3";
                } else if (rand > 51 && rand <= 62) {
                    slotsOutput[i] = "4";
                } else if (rand > 62 && rand <= 70) {
                    slotsOutput[i] = "5";
                } else if (rand > 70 && rand <= 75) {
                    slotsOutput[i] = "6";
                } else if (rand > 75 && rand <= 78) {
                    slotsOutput[i] = "7";
                } else if (rand > 78 && rand <= 81) {
                    slotsOutput[i] = "8";
                } else if (rand > 81 && rand <= 82) {
                    slotsOutput[i] = "9";
                } else if (rand > 82 && rand <= 90) {
                    slotsOutput[i] = "0";
                } else {
                    slotsOutput[i] = "X";
                }
                std::cout << slotsOutput[i] << " ";
                usleep(waitSecond);
                
            }
            std::cout << std::endl;
            bool lost = false;
            bool wildcard = false;
            for (int i = 0; i < 3; i++) {
                if (slotsOutput[i] == "X") {
                    lost = true;
                }
                if (slotsOutput[i] == "0") {
                    wildcard = true;
                }
            }
            if (lost) {
                std::cout << "Hah! You lost " << bet << " chips!" << std::endl;
            }

            // 3x Winner

            if (!lost) {
                if (slotsOutput[0] == slotsOutput[1] && slotsOutput[1] == slotsOutput[2]) {
                    if (slotsOutput[0] == "9") {
                        std::cout << "JACKPOT!!!";
                    }
                    chips += (std::stoi(slotsOutput[0])  *  6) * bet;
                    std::cout << "You won " << (std::stoi(slotsOutput[0]) * 6) * bet << " chips!" << std::endl;
                } 
                
                // 3x Winner (with wildcard)

                else if ((slotsOutput[0] == slotsOutput[1] && wildcard) || ((slotsOutput[0] == slotsOutput[2]) && wildcard) || ((slotsOutput[1] == slotsOutput[2]) && wildcard)) {
                    if (slotsOutput[0] == "9") {
                        std::cout << "JACKPOT!!!";
                    }
                    chips += (std::stoi(slotsOutput[0])  *  6) * bet;
                    std::cout << "You won " << (std::stoi(slotsOutput[0]) * 6) * bet << " chips!" << std::endl;                
                }
                
                // 2x Winner
                
                else if (slotsOutput[0] == slotsOutput[1] || slotsOutput[0] == slotsOutput[2] || slotsOutput[1] == slotsOutput[2]) {
                    chips += (std::stoi(slotsOutput[0]) * 2) * bet;
                    std::cout << "You won " << (std::stoi(slotsOutput[0]) * 2) * bet << " chips!" << std::endl;
                } else if (slotsOutput[1] == slotsOutput[2]) {
                    chips += (std::stoi(slotsOutput[1]) * 2) * bet;
                    std::cout << "You won " << (std::stoi(slotsOutput[1]) * 2) * bet << " chips!" << std::endl;
                }
                
                // 2x Winner (with wildcard)

                else if (wildcard) {
                    for (int i = 0; i < 3; i++) {
                        if (slotsOutput[i] > slotsOutput[0]) {
                            slotsOutput[0] = slotsOutput[i];
                        }
                    }
                    chips += (std::stoi(slotsOutput[0]) * 2) * bet;
                    std::cout << "You won " << (std::stoi(slotsOutput[0]) * 2) * bet << " chips!" << std::endl;
                }

                // no matches
                
                else {
                    std::cout << "Heh! Looka' that! No matches." << std::endl;
                }
            } 

            std::cout << "Wanna go again? (1 - yes, 2 - same bet, 3 - no)" << std::endl;
            std::cin >> choice;
            while (true) {
                if (!std::cin || choice > 4 || choice < 1) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "That's not an option ya dipwad!" << std::endl;
                } else if (choice == 1) { 
                    choice = 3;
                    bet = 0;
                    break;
                } else if (choice == 2) {
                    choice = 3;
                    break;
                } else { 
                    choice = 4;
                    break;
                }
            }
        }

        // exit //

        else if (choice == 4) {
            choice = 0;
            return;
        }
    } // while (choice != 4)    
} // slots()

void blackjack() {
    int choice = 0;
    int bet = 0;
    bool solo = true;
    std::cout << "(DESCRIBE THE BLACKJACK AREA)" << std::endl;
    std::cout << "Solo (1) or multiple players (2)" << std::endl;
    while (true) {
        std::cin >> choice;
        if (choice ==  2) {
            solo = false;
        } else if (choice == 3) {
            return;
        } else if (!std::cin || choice > 3 || choice < 1) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That's not an option ya dipwad!" << std::endl;
        } else {
            break;
        }
    }

    while (choice != 3) {
        while (true) {
            if (bet == 0) {
                checkBalance();
                std::cout << "Enter your bet amount (-1 to go back to main room): " << std::endl;
                std::cin >> bet;
                if (bet == -1) {
                    return;
                } else if (!std::cin || bet < -1 || bet > chips) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Not enough dough." << std::endl;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        chips -= bet;

        //


    }
}

void cards(int game, int players) {
    ;;
}

void cashOut(int *chip) {
    if (!balanceExists()) {
        std::ofstream outfile ("balance.txt");
        outfile << "100" << std::endl;
    }
    std::fstream outfile;
    outfile.open("balance.txt", std::ios::out);
    outfile << balance + chips;
    chips = 0;
    outfile.close();
}