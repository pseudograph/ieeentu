//
// Created by iv on 2/26/23.
//

#include "Tiktok.h"

bool Tiktok::addUser(userId id, Money money) {
    try {
        database.query(addUserString(id, money), "add user");
        return true;
    } catch (std::exception& exception) {
        std::cerr << "[Tiktok::addUser] Exception: " << exception.what() << std::endl;
        return false;
    }
}

bool Tiktok::addFunds(userId id, Money money) {
    try {
        database.query(addFundsString(id, money), "add funds to user");
        return true;
    } catch (std::exception& exception) {
        std::cerr << "[Tiktok::addFunds] Exception: " << exception.what() << std::endl;
    }
    return false;
}

bool Tiktok::deductFunds(userId id, Money money) {
    try {
        database.query(deductFundsString(id, money), "deduct funds from user");
        return true;
    } catch (std::exception& exception) {
        std::cerr << "[Tiktok::deductFunds] Exception: " << exception.what() << std::endl;
    }
    return false;
}

bool Tiktok::transferFunds(userId source, Money moneyPerRecipient, const std::vector<userId>& recipients, ...) {
    return false;
}

void Tiktok::addUserToExec(pqxx::work &transaction, userId id, Money money) {
   return;
}

std::string Tiktok::addUserString(userId id, Money money) {
    std::stringstream query;
    query << "INSERT INTO balances (id, balance) "
          << "VALUES('" << id << "','" << money
          << "');";
    return query.str();
}

std::string Tiktok::addFundsString(userId id, Money money) {
    std::stringstream query;
    query << "UPDATE balances "
          << "SET balance = balance - " << money << ' '
          << "WHERE id = " << id << ';';
    return query.str();
}

std::string Tiktok::deductFundsString(userId id, Money money) {
    std::stringstream query;
    query << "UPDATE balances "
          << "SET balance = balance - " << money << ' '
          << "WHERE id = " << id << ';';
    return query.str();
}

