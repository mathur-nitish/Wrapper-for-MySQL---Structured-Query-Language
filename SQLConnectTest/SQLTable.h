#ifndef SQLTable_H
#define SQLTable_H

#include<iostream>
#include<string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <variant>
using namespace std;
using QueryType = vector<vector<variant<int, long double, string>>>;


class SQLTable {
private:
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    
    void ExecuteQuery(string query,string command);
    std::string tablename;
    vector<pair<string, string>> columns;
    void getResults(std::string query);
    QueryType getResultVector(std::string query);

public:
    SQLTable(std::string name);
    void setColumns();
    void setVariables(sql::Connection* con);

    void select(const std::string query);
    QueryType select(std::vector<string> req_columns);
    void selectPrint(std::vector<string> req_columns);
    QueryType select(std::vector<string> req_columns,pair<int,int> condi);
    QueryType select(std::vector<string> req_columns, pair<string, string> condi);
    QueryType select(std::vector<string> req_columns, pair<string, int> condi);

    void update(std::string query);
    void deleteTable(std::string query);
   
};


#endif