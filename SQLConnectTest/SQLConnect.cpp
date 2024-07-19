#include "SQLConnect.h"
#include "SQLTable.h"

SQLConnect::SQLConnect(string server, string username, string password) {
        this->server = server;
        this->username = username;
        this->password = password;
    }
bool SQLConnect::ConnectToServer() {
        try {
            this->driver = get_driver_instance();
            this->con = driver->connect(server, username, password);
            return true;
        }
        catch (sql::SQLException e) {
            std::cout << "Could not connect to server." << endl;
            std::cout << "Error message: " << e.what() << endl;
            system("pause");
            return false;
            exit(1);
        }
        return false;
    }
    void SQLConnect::useDatabase(string db) {
        con->setSchema(db);
    }

    bool SQLConnect::executeQuery(string query) {
        stmt = con->createStatement();
        try {
            stmt->execute(query);
        }
        catch (sql::SQLException e) {
            cout << e.what() << endl;
            return false;
        }
        return true;
    }


    SQLTable* SQLConnect::getTable(string tablename)
    {
        SQLTable* table = new SQLTable(tablename);
        // initialize the columns for faster retrivel
        table->setVariables(con);
        table->setColumns(); // initializes the columns name vector
        
        return table;
    }




    SQLTable* SQLConnect::createTable(string tableName, vector<pair<string, string>>& attributes) {
        // construct a string
        // create table table_Name ( id int, name varchar )
        // where ( id int, name varchar ) -> part can vary as length
        string query = "create table " + tableName + " ";
        query += "(";
        for (int i = 0;i < attributes.size() - 1;i++) {
            string s = attributes[i].first + " " + attributes[i].second + ", ";
            query += s;
        }
        query += attributes[attributes.size() - 1].first + " " + attributes[attributes.size() - 1].second;
        query += ")";

        cout << query << endl;

        stmt = con->createStatement();
        try {
            stmt->execute(query);
            SQLTable* table = new SQLTable(tableName);
            return table;
        }
        catch (sql::SQLException e) {
            cout << e.what() << endl;
        }
        return NULL;

    }

    SQLTable* SQLConnect::createTable(string tableName, string query) {
        SQLTable* table = new SQLTable(tableName);
        stmt = con->createStatement();
        try {
            stmt->execute(query);
            return table;
        }
        catch (sql::SQLException e) {
            cout << e.what() << endl;
        }
        return NULL;

    }



















    //void executeQuery(string Query, int n) {
    //    stmt = con->createStatement();
    //    sql::ResultSet *result; 
    //    // it requires pstm as the function prepareStatement is required
    //    // create an enum to choose which command is used and then overload the function accordingly
    //    result = stmt->execute(Query);
    //}


//class SQLTable {
//private:
//    string tablename;
//public:
//    SQLTable(string name) {
//        this->tablename = name;
//    }
//
//    void select() {
//
//    }
//    void update() {
//
//    }
//    void alter() {
//
//    }
//    void deleteTable() {
//        // implicitly execute a query and then free this object
//    }
//
//};