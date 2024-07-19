#include "SQLTable.h"
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <cppconn/metadata.h>


SQLTable::SQLTable(std::string name) {
    this->tablename = name;
}
    void SQLTable::setVariables(sql::Connection* con) {
        this->con = con;
    }
    
    void SQLTable::setColumns()
    {
        // use result variable to print the columns of table
    }

    void SQLTable::update(string query) {
        string prequery = "update " + tablename + " ";
        ExecuteQuery(prequery+query,"Update Table");
    }
    void SQLTable::deleteTable(string query) {
        // implicitly execute a query and then free this object
        string prequery = "delete from " + tablename + " ";
        ExecuteQuery(prequery + query, "Delete from Table");
    }

    void SQLTable::ExecuteQuery(string query,string command)
    {
        pstmt = con->prepareStatement(query);
        try {
            pstmt->execute();
            std::cout << command << " is successfully executed!" << endl;
        }
        catch (sql::SQLException e) {
            std::cout << e.what() << endl;
        }
    }

    void SQLTable::getResults(std::string query)
    {
        sql::ResultSet* result = nullptr;
        sql::ResultSetMetaData* metaData = nullptr;

        try {
            pstmt = con->prepareStatement(query);
            result = pstmt->executeQuery();

            if (!result) {
                std::cout << "Result is empty" << endl;
                return;
            }
            metaData = result->getMetaData();
            int numberOfcolumns = metaData->getColumnCount();
            while (result->next()) {
                // getting each row
                for (int i = 1;i <= numberOfcolumns;i++) {
                    int columnType = metaData->getColumnType(i);
                    // getting each column for that row
                    switch (columnType) {
                    case sql::DataType::INTEGER:
                        std::cout << result->getInt(i) << "\t";
                        break;
                    case sql::DataType::VARCHAR:
                        std::cout << result->getString(i) << "\t";
                        break;
                    case sql::DataType::DOUBLE:
                        std::cout << result->getDouble(i) << "\t";
                        break;
                    case sql::DataType::DATE:
                        std::cout << result->getString(i) << "\t";
                        break;
                    default:
                        std::cout << "Unknown Type\t";
                        break;
                    }

                }
                std::cout << endl;
            }

        }
        catch (sql::SQLException e) {
            std::cout << e.what() << endl;
        }
    }


    vector<vector<variant<int,long double, string>>> SQLTable::getResultVector(std::string query)
    {
        sql::ResultSet* result = nullptr;

        pstmt = con->prepareStatement(query);
        result = pstmt->executeQuery();
        sql::ResultSetMetaData* metaData = result->getMetaData();

        vector<vector<variant<int,long double, string>>> record;
        while (result->next()) {
            vector<variant<int,long double, string>> t;
            int columns = metaData->getColumnCount();
            for (int i = 1;i <= columns;i++)
            {
                int columnType = metaData->getColumnType(i);
                variant<int, long double, string> temp;
                switch (columnType) {
                case sql::DataType::INTEGER:
                    temp = result->getInt(i);
                    break;
                case sql::DataType::VARCHAR:
                    temp = result->getString(i);
                    break;
                case sql::DataType::DOUBLE:
                    temp = result->getDouble(i);
                    break;
                case sql::DataType::DATE:
                    temp = result->getString(i);
                    break;
                default:
                    temp = "UnknownType";
                    break;
                }
                t.push_back(temp);

            }
            record.push_back(t);
        }

        return record;
    }











