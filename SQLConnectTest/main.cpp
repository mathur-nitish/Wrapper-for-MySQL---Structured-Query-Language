#include <stdlib.h>
#include <iostream>
#include <vector>
#include "SQLConnect.h";
#include "SQLTable.h";
using namespace std;

void printVector(vector<vector<variant<int, long double, string>>>& t)
{
    for (const std::vector<std::variant<int, long double, std::string>>& inner : t) {
        // Iterate through the inner vector
        for (const auto& element : inner) {
            // Check the type of the element and print accordingly
            if (std::holds_alternative<int>(element)) {
                std::cout << std::get<int>(element) << " ";
            }
            else if (std::holds_alternative<long double>(element)) {
                std::cout << std::get<long double>(element) << " ";
            }
            else if (std::holds_alternative<std::string>(element)) {
                std::cout << std::get<std::string>(element) << " ";
            }
        }
        std::cout << std::endl; // Newline after each inner vector
    }
}


int main()
{
    SQLConnect connector(server, username, password);
    connector.ConnectToServer();
    connector.useDatabase("test1");
    string tableName = "test2";
    vector<pair<string, string>> attributes
    {
        {"id","int"},
        {"name","varchar(50)"},
        {"marks","int"}
    };

    SQLTable* Mytable = connector.getTable("student");
    //Mytable->select("select * from student");
    vector<string> columns = { "id","name","age"};
    //Mytable->select(columns);
    //record = Mytable->select(columns,where={age,14});   

    //Mytable->select(columns, {"age",14});
    //QueryType t = Mytable->select(columns,{"age",13});
    Mytable->update("set age=12 where id=103");
    //printVector(t);
    Mytable->deleteTable("where id = 105");
   



    return 0;
} 