#pragma once

#include "Customer.h"

ref class Employee : Person
{
private:
    int id_address;
    int id_manager;
    System::DateTime hire_date;
    
    // Private DB modification methods
    void create_employee_in_DB();
    void fetch_employee_from_DB();

    // These methods only affect the "Customers" Table, not the parent "People" table
    void modify_employee_in_DB();
    void delete_employee_from_DB();

public:
    Employee(int);
    Employee(System::String^, System::String^, System::DateTime, int);
    Employee(System::String^, System::String^, System::DateTime, int, int);

    int getIDaddress();
    void setIDaddress(int);
    int getIDmanager();
    void setIDmanager(int);
    void setIDmanagernullable(Object^); // Overloaded method for DBNull
    
    System::DateTime getHireDate();
    void setHireDate(System::DateTime);

    void modify_in_DB() override;
    void delete_in_DB() override;
};
