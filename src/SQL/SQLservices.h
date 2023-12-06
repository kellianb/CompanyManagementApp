#pragma once

#include "SQLdatabaseAdapter.h"

// Contains the SQL commands for the different DB operations and sends them to the SQLdatabaseAdapter  with the correct parameters
ref class SQLservices
{
private:
    SQLdatabaseAdapter^ SQLadapter;
    
public:
    SQLservices();
    
    System::Data::DataTable^ SQL_addPerson(System::String^, System::String^);

    System::Data::DataTable^ SQL_getPerson(int id);

    System::Data::DataTable^ SQL_modifyPerson(int id, System::String^, System::String^);

    void SQL_deletePerson(int id);
    
    System::Data::DataTable^ SQL_addCustomer(int, System::DateTime);
    
    System::Data::DataTable^ SQL_getCustomerList();
    
    System::Data::DataTable^ SQL_getCustomer(int id);
    
    System::Data::DataTable^ SQL_modifyCustomer(int id, System::DateTime);

    void SQL_deleteCustomer(int id);

    System::Data::DataTable^ SQL_getCustomerOrders(int id);

    void SQL_deleteCustomerOrders(int id);

    System::Data::DataTable^ SQL_getEmployeeList();
};
