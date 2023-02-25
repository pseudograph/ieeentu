//
// Created by iv on 2/26/23.
//

#ifndef IEEENTU_USER_H
#define IEEENTU_USER_H

#include <cstdint>
#include <pqxx/pqxx>
#include "Database.h"
#include "Types.h"

class User {
private:
    Money money;
    Database database;
public:
    explicit User(const Database& database) : money{ 0 }, database{ database }
    {}

    User(const Database& database, Money money) : database{ database }, money{ money }
    {}

    bool add(userId id, Money money);
    bool deduct(userId id, Money money);
    bool transfer(userId source, Money moneyPerRecipient, userId recipients...);
};


#endif //IEEENTU_USER_H
