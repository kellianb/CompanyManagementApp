#pragma once

#include "Person.h"

ref class Customer : Person
{
private:
    System::DateTime birth_date;

    // Private DB modification methods
    void create_customer_in_DB();
    void fetch_customer_from_DB();
    void delete_all_orders();

    // These methods only affect the "Customers" Table, not the parent "People" table
    void modify_customer_in_DB();
    void delete_customer_from_DB();
    
public:
    Customer(int id);

    Customer(System::String^, System::String^, System::DateTime);

    System::DateTime getBirthDate();
    void setBirthDate(System::DateTime);

    void modify_in_DB() override;
    void delete_in_DB() override;

    System::Data::DataTable^ getOrders();
    
};
