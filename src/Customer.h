#pragma once

#include "Person.h"

ref class Customer : Person
{
private:
    void create_customer_in_DB();
    void fetch_customer_from_DB();

    System::DateTime birth_date;
    
public:
    Customer(int id);

    Customer(System::String^, System::String^, System::DateTime);

    System::DateTime getBirthDate();
    void setBirthDate(System::DateTime);
    
};
