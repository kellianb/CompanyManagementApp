#pragma once

#include "SQLdatabaseAdapter.h"

// Contains the SQL commands for the different DB operations and sends them to the SQLdatabaseAdapter  with the correct parameters
ref class SQLservices
{
private:
    SQLdatabaseAdapter^ SQLadapter;
    
public:
    SQLservices();
    
    System::Data::DataSet^ SQL_addPerson(System::String^, System::String^);

    System::Data::DataSet^ SQL_getPerson(int id);

    void SQL_deletePerson(int id);
    
    System::Data::DataSet^ SQL_addCustomer(int, System::DateTime^);
    
    System::Data::DataSet^ SQL_getCustomerList();
    
    System::Data::DataSet^ SQL_getCustomer(int id);
};
