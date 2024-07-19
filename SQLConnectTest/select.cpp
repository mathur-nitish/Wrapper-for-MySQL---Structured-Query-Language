#include"SQLTable.h"


void SQLTable::select(std::string query) {
    sql::ResultSet* result = nullptr;
    std::cout << "Select query with whole statement is running!" << std::endl;
    // prepare a statement using custom input variables1   
    getResults(query);

}

vector<vector<variant<int, long double, string>>> SQLTable::select(std::vector<string> req_columns) {
    // preparing the query
    // select columns from tablename;
    string query = "select ";
    int req_columnsSize = req_columns.size();
    for (int i = 0;i < req_columnsSize - 1;i++) {
        query = query + req_columns[i] + ", ";
    }
    query = query + req_columns[req_columnsSize - 1] + " from " + tablename;
    std::cout << query << endl;
    /*getResults(query);*/
    // return a vector<vector<variant>> object having all the rows and columns
    return getResultVector(query);
}

void SQLTable::selectPrint(std::vector<string> req_columns)
{
    string query = "select ";
    int req_columnsSize = req_columns.size();
    for (int i = 0;i < req_columnsSize - 1;i++) {
        query = query + req_columns[i] + ", ";
    }
    query = query + req_columns[req_columnsSize - 1] + " from " + tablename;
    std::cout << query << endl;
    getResults(query);
}


QueryType SQLTable::select(std::vector<string> req_columns, pair<int, int> condi)
{
    // prepare a string
    string query = "select ";
    int req_columnsSize = req_columns.size();
    for (int i = 0;i < req_columnsSize - 1;i++) {
        query = query + req_columns[i] + ", ";
    }
    query = query + req_columns[req_columnsSize - 1] + " from " + tablename + " where ";
    query = query + std::to_string(condi.first) + "=" + std::to_string(condi.second);
        // where age = 14;
    std::cout << query << endl;
}

QueryType SQLTable::select(std::vector<string> req_columns, pair<string, string> condi)
{



}

QueryType SQLTable::select(std::vector<string> req_columns, pair<string, int> condi)
{
    std::cout << "Running pair<string,int> function" << endl;
    // prepare a string
    string query = "select ";
    int req_columnsSize = req_columns.size();
    for (int i = 0;i < req_columnsSize - 1;i++) {
        query = query + req_columns[i] + ", ";
    }
    query = query + req_columns[req_columnsSize - 1] + " from " + tablename + " where ";
    query = query + condi.first + "=" + std::to_string(condi.second);
    // where age = 14;
    std::cout << query << endl;
    return getResultVector(query);

}





