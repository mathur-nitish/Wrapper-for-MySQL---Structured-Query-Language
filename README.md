# MySQL Wrapper - Simplified Structured Query Language Execution

This repository contains a C++ wrapper for MySQL, aimed at simplifying the interaction with MySQL databases. The wrapper allows users to easily execute queries, manage connections, and handle results using an intuitive and object-oriented interface.

## Features

- **Easy MySQL Integration**: Establish and manage MySQL database connections with minimal setup.
- **Simple Query Execution**: Execute SQL queries such as `SELECT`, `INSERT`, `UPDATE`, and `DELETE` using an easy-to-use interface.
- **Result Handling**: Simplified management of query results and error handling.
- **Object-Oriented Design**: C++ class structure to promote code reuse and clarity.

## Requirements

- MySQL C++ Connector
- C++11 or later
- MySQL Server

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/mathur-nitish/Wrapper-for-MySQL---Structured-Query-Language.git

2. Install MySQL C++ Connector: Follow the official guide to download and set up the MySQL C++ Connector for your system.
3. Add the required paths for the MySQL connector to your project’s include and lib directories.



## Usage
### 1. Establishing Connection
```cpp
#include "MySQLWrapper.h"
      
  MySQLWrapper db;
  if (db.connect("localhost", "user", "password", "database")) {
    std::cout << "Connected to the database!" << std::endl;
} else {
    std::cerr << "Failed to connect to the database." << std::endl;
}
```
### 2. Executing Queries
Select Query
```cpp
std::string query = "SELECT * FROM users";
auto results = db.executeQuery(query);

while (results.next()) {
    std::cout << "User ID: " << results.getInt("id") << std::endl;
    std::cout << "User Name: " << results.getString("name") << std::endl;
}
````

This allows you to simply select the columns you want to query for.
```
SQLTable* Mytable = connector.getTable("student");
vector<string> columns = { "id","name","age"};
Mytable->select(columns);
```
### Insert Query
```cpp
std::string insertQuery = "INSERT INTO users (name, email) VALUES ('John Doe', 'john@example.com')";
if (db.executeUpdate(insertQuery)) {
    std::cout << "User inserted successfully!" << std::endl;
}
```
### Contributing
1. Fork the repository.
2. Create a new branch (git checkout -b feature-branch).
3. Commit your changes (git commit -am 'Add a new feature').
4. Push to the branch (git push origin feature-branch).
5. Create a new Pull Request.

