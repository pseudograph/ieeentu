//
// Created by iv on 2/26/23.
//

#ifndef IEEENTU_DATABASE_H
#define IEEENTU_DATABASE_H


#include <string>
#include <pqxx/pqxx>

class Database {
private:
    pqxx::connection connection;
    std::string connString;
public:
    explicit Database(const std::string& connString) : connection{ connString }, connString{ connString }
    {
    }

    Database(const Database& other) : connection{ other.connString }
    {
    }

    bool isOpen();
    void query(const std::string& query, const std::string& description);
    void query(const std::vector<std::string>& queries);

    ~Database() {
        connection.close();
    }
};


#endif //IEEENTU_DATABASE_H
