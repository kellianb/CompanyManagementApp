#pragma once
#include "SQL/SQLservices.h"

ref class Address
{
private:
    SQLservices^ SQLserv = gcnew SQLservices;

    void create_address_in_DB();
    void fetch_address_from_DB();
    
    int id;
    
    System::String^ city;
    System::String^ street;
    int postal_code;
    int street_number;

public:
    Address(int);

    Address(System::String^, int, System::String^, int);

    int getID();

    System::String^ getCity();
    void setCity(System::String^);

    System::String^ getStreet();
    void setStreet(System::String^);

    int getPostalCode();
    void setPostalCode(int);

    int getStreetNumber();
    void setStreetNumber(int);

    void modify_address_in_DB();
    void delete_address_from_DB();
};
