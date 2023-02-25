//
// Created by iv on 2/26/23.
//

#ifndef IEEENTU_TIKTOK_H
#define IEEENTU_TIKTOK_H

#include "Database.h"
#include "Types.h"
#include "Sql.h"
#include <iostream>

class Tiktok {
    Database database;
public:
    Tiktok() : database { "dbname = tiktok user = postgres password = root host = 127.0.0.1 port = 5432" }
    {
        if (!database.isOpen()) {
            database.query(Sql::INITIALISE_DATABASE, "initialise database");
        }
    }

    bool isOpen() {
        return database.isOpen();
    }

    bool addUser(userId id, Money money = 0);
    bool addFunds(userId id, Money money);
    bool deductFunds(userId id, Money money);
    bool transferFunds(userId source, Money moneyPerRecipient, const std::vector<userId>& recipients...);

    void addUserToExec(pqxx::work& transaction, userId id, Money money = 0);
    void addFundsToExec(pqxx::work& transaction, userId id, Money money);
    void deductFundsToExec(pqxx::work& transaction, userId id, Money money);
    void transferFundsToExec(pqxx::work& transaction, userId source, Money moneyPerRecipient, const std::vector<userId>& recipients...);

private:
    std::string addUserString(userId id, Money money = 0);
    std::string addFundsString(userId id, Money money);
    std::string deductFundsString(userId id, Money money);
};


#endif //IEEENTU_TIKTOK_H
