//
// Created by iv on 2/26/23.
//

#include "Database.h"
#include "Types.h"
#include <cstdarg>

bool Database::isOpen() {
    return connection.is_open();
}

void Database::query(const std::string &query, const std::string& description) {
    pqxx::work transaction{ connection };
    transaction.exec(query, description);
    transaction.commit();
}

void Database::query(const std::vector<std::string>& queries) {
    pqxx::work transaction{ connection };
    for (const auto& query : queries) {
        transaction.exec(query);
    }
    transaction.commit();
}
