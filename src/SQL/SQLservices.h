﻿#pragma once

#include "SQLdatabaseAdapter.h"

// Contains the SQL commands for the different DB operations and sends them to the SQLdatabaseAdapter  with the correct parameters
ref class SQLservices
{
private:
    SQLdatabaseAdapter^ SQLadapter;
    
public:
    // Constructor
    SQLservices();

    // Person Queries
    System::Data::DataTable^ SQL_addPerson(System::String^, System::String^);

    System::Data::DataTable^ SQL_getPerson(int id);

    System::Data::DataTable^ SQL_modifyPerson(int id, System::String^, System::String^);

    void SQL_deletePerson(int id);

    // Customer Queries
    System::Data::DataTable^ SQL_addCustomer(int, System::DateTime);
    
    System::Data::DataTable^ SQL_getCustomerList();
    
    System::Data::DataTable^ SQL_getCustomer(int id);
    
    System::Data::DataTable^ SQL_modifyCustomer(int id, System::DateTime);

    void SQL_deleteCustomer(int id);

    System::Data::DataTable^ SQL_getCustomerOrders(int id);

    void SQL_deleteCustomerOrders(int id);

    void SQL_deleteCustomerAddresses(int id);
    

    // Employee Queries
    System::Data::DataTable^ SQL_addEmployee(int id_person, System::DateTime, int id_address, int id_manager);

    System::Data::DataTable^ SQL_getEmployeeList();

    System::Data::DataTable^ SQL_getEmployee(int id);
    
    System::Data::DataTable^ SQL_modifyEmployee(int id_person, System::DateTime, int id_address, int id_manager);

    void SQL_deleteEmployee(int id);

    void SQL_deleteEmployeeAddresses(int id);
};
