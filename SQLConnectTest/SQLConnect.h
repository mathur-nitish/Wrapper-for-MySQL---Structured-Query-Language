#ifndef SQLConnect_H
#define SQLConnect_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stdlib.h>
#include "SQLTable.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;



//for demonstration only. never save your password in the code!
const string server = "yourip";
const string username = "your_username";
const string password = "your_password";





class SQLConnect {
    enum QueryState { SELECT };
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    string server;
    string username;
    string password;

public:
    SQLConnect(string server, string username, string password);

    bool ConnectToServer();
    void useDatabase(string db);
    bool executeQuery(string query);
    SQLTable* getTable(string tablename);
    virtual SQLTable* createTable(string tableName, vector<pair<string, string>>& attributes);
    virtual SQLTable* createTable(string tableName, string query);

};




#endif















