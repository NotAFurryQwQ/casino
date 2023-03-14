#include <iostream>
#include <fstream>
#include <unistd.h>
#include <unordered_map>

//

int balance;
int chips = 100;
int *chip = &chips;
bool newPlayer = false;

//

bool balanceExists();
void checkBalance();
void getChips();
void cashOut(int *chip);
void mainRoom();
void slots();

// issues:
// when slots ends, it somehow calls getChips and then when that is done it ends the program instead of returning to mainRoom

int main() {

    if (!balanceExists()) {
        std::ofstream outfile ("balance.txt");
        outfile << "100" << std::endl;
        newPlayer = true;
    }
    std::fstream outfile;
    outfile.open("balance.txt", std::ios::in);
    outfile >> balance;

    mainRoom();

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
    std::cout << "You have " << balance << " chips available to bet, and currently have " << 
    chips << " chips on you." << std::endl;
}

void getChips() {
    std::cout << "get em" << std::endl;
    int chipsInput;
    std::cin >> chipsInput;
    while (true) {
        if (std::cin.fail() || chipsInput > balance || chips < 1) {
            std::cout << "no!" << std::endl;
            std::cin >> chipsInput;
        } else {
            balance -= chips;
            break;
        }
    }
}

void mainRoom() {
    while (true) {
        int choice = 0;
        if (newPlayer) {
            std::cout << "Welcome t' the Rat-a-Tat Catsino!" << std::endl;
            std::cout << "I see this is your first time here.";
            usleep(2000000);
            std::cout << "Or maybe you're fakin' it...." << std::endl;
            usleep(1000000);
            std::cout << "Whateva'. Yer startin' off with 100 chips. Don't waste 'em at all." << std::endl;
            usleep(3000000);
            std::cout << "...Or do. I don't give a rat's ass." << std::endl;
            usleep(1000000);
        } else {
            std::cout << "Welcome back t' the Rat-a-Tat Catsino!" << std::endl;
            usleep(1000000);
            checkBalance(); 
            usleep(1000000);
        }

        std::cout << "Pick a room?" << std::endl;
        usleep(1000000);
        std::cout << "1. Slots" << '\n' << "2. WIP (picks 1)" << '\n' <<
            "3. Get chips." << '\n' << "4. Cash out and exit." << std::endl;
        
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice > 4 || choice < 1) {
                std::cout << "That's not an option ya dipwad!" << std::endl;
            } else {
                break;
            }
        }
        switch (choice) {
            case 1:
            slots();
            std::cout << "Well? Anythin' else?" << std::endl;
            std::cout << "1. Slots" << '\n' << "2. WIP (picks 1)" << '\n' <<
            "3. Get chips." << '\n' << "4. Cash out and exit." << std::endl;
            while (true) {
                std::cin >> choice;
                if (std::cin.fail() || choice > 4 || choice < 1) {
                    std::cout << "That's not an option ya dipwad!" << std::endl;
                } else {
                    break;
                }
            }
            

            case 2:
            choice = 1;

            case 3:
            choice = 0;
            getChips();

            case 4:
            cashOut(chip);
            exit(0);

            default:
            std::cout << "That's not an option ya dipwad!" << std::endl;
            usleep(1000000);
            std::cout << "Pick a room?" << std::endl;
            usleep(3000000);
            std::cout << "1. Slots" << '\n' << "2. WIP (picks 1)" << '\n' <<
                "3. WIP (picks 1)" << '\n' << "4. Cash out and exit." << std::endl;
            
            std::cin >> choice;
        }
    }
}
    

void slots() {
    int choice = 0;
    std::cout << "(DESCRIBE THE SLOTS AREA)" << std::endl;
    srand(time(NULL));
    while (choice != 4) {



        /*
        const std::unordered_map<int, int> slotsSymbols = {
            { 10, 0 },
            { 1, 20 },
            { 2, 37 },
            { 3, 51 },
            { 4, 62 },
            { 5, 70 },
            { 6, 75 },
            { 7, 78 },
            { 8, 81 },
            { 9, 82 },
            { 0, 90 },
        };*/
        if (choice == 0) {
            std::cout << "Which machine will ya pick?" << std::endl;
            while (true) {
                std::cin >> choice;
                if (std::cin.fail() || choice > 4 || choice < 1) {
                    std::cout << "That's not an option ya dipwad!" << std::endl;
                } else {
                    break;
                }
            }
        }
        if (choice == 1) {
            int bet = 0;
            while (true) {
                checkBalance();
                std::cout << "Enter your bet amount (-1 to exit): " << std::endl;
                std::cin >> bet;
                if (bet == -1) {
                    return;
                } else if (std::cin.fail() || bet < -1 || bet > chips) {
                    std::cout << "That's not an option ya dipwad!" << std::endl;
                } else {
                    break;
                }
            }
            chips -= bet;

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
               // dict of values, key value for each. for loop that loops through keys and then prints the value that matches from rand
                /*
                for (int j = 0; j < 10 + 1; j++) {
                    
                }
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
                std::cout << "Hah! You lost " << bet << " chips!";
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
            } // if(!lost)
            
            std::cout << "Wanna go again? (1 - yes, 2 - no)" << std::endl;
            std::cin >> choice;
            while (true) {
                if (std::cin.fail() || choice > 4 || choice < 1) {
                    std::cout << "That's not an option ya dipwad!" << std::endl;
                } else if (choice == 1) { 
                    break;
                } else if (choice == 2) {
                    choice = 4;
                    break;
                }
            }
        } else if  (choice < 4) {
            choice = 4;
        } 
        
        else if (choice == 4) {
            choice = 0;
            return;
        }
    } // while (choice != 4)    
} // slots()

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