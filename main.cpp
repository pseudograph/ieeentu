#include <iostream>
#include "Tiktok.h"
#include "Types.h"

int main() {
    Tiktok tiktok;
    Database db{ "dbname = tiktok user = postgres password = root host = 127.0.0.1 port = 5432" };
    while (true) {
        int input{};
        std::cin >> input;
        userId id;
        Money money;
        switch (input) {
        // addUser
        case (0) :
            std::cin >> id;
            tiktok.addUser(id);
            break;
        // addFunds
        case (1) :
            std::cin >> id;
            std::cin >> money;
            tiktok.addFunds(id, money);
            break;
        // deductFunds
        case (2) :
            std::cin >> id;
            std::cin >> money;
            tiktok.deductFunds(id, money);
            break;
        // transferFunds
        case (3) :
            std::vector<userId> recipients;
            std::cin >> id;
            std::cin >> money;
            while (std::cin) {
                std::cin >> id;
                recipients.push_back(id);
            }
            tiktok.transferFunds(id, money, recipients);
        }
    }
}
