//
// Created by iv on 2/26/23.
//

#ifndef IEEENTU_SQL_H
#define IEEENTU_SQL_H


#include <string>

namespace Sql {
    static const std::string INITIALISE_DATABASE {
        "CREATE TABLE balances(" \
        "id INT PRIMARY KEY NOT NULL," \
        "balance NUMERIC NOT NULL );"
    };
}



#endif //IEEENTU_SQL_H
