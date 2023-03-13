#include <iostream>
#include <fstream>
#include <unordered_map>

//

int balance;
int choice;
int chips = 0;
int *chip = &chips;

//

bool balanceExists();
void checkBalance();
void cashOut(int *chip);
void mainRoom();
void slots();

//

int main() {

    if (!balanceExists()) {
        std::ofstream outfile ("balance.txt");
        outfile << "100" << std::endl;
    }
    std::fstream outfile;
    outfile.open("balance.txt", std::ios::in);
    outfile >> balance;

    //mainRoom();

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
    std::cout << "You have " << chips << " chips available to bet." << std::endl;
}

void mainRoom() {
    std::cout << "Welcome to Chip's Con.";
    std::cout << "pick room";
    while (choice != 4) {
        std::cin >> choice;
        if (!isdigit(choice) || choice > 4 || choice < 1) {
            std::cout << "wrong";
        } else {
            break;
        }
    }

    switch (choice) {
        case 1:
        choice = 0;
        slots();

        case 2:
        choice = 1;

        case 3:
        choice = 1;

        case 4:
        cashOut(chip);
        exit(0);

        default:
        std::cout << "wrong" << std::endl;
        std::cin >> choice;
    }
}

void slots() {
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

        std::cout << "wyd";
        while (true) {
            std::cin >> choice;
            if (!isdigit(choice) || choice > 4 || choice < 1) {
                std::cout << "wrong";
            } else {
                break;
            }
        }
        if (choice == 1) {
            int bet = 0;
            while (true) {
                checkBalance();
                std::cout << "Enter your bet amount: ";
                std::cin >> bet;
                if (!isdigit(bet) || bet > chips) {
                    std::cout << "wrong";
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
                std::cout << "You lost! " << bet << " chips.";

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
                    ;;
                }

                // no matches
                
                else {
                    std::cout << "lol";
                }
            } // if(!lost)
            choice = 0;
        } // if (choice == 1)
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