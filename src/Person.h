#pragma once
#include "SQL/SQLservices.h"

ref class Person
{
private:
    void create_person_in_DB();
    void fetch_person_from_DB();
    
protected:
    // SQL services object
    SQLservices^ SQLserv = gcnew SQLservices;

    // Properties of the person
    int id;
    System::String^ first_name;
    System::String^ last_name;

    // Private DB modification methods
    void modify_person_in_DB();
    void delete_person_from_DB();

public:
    // Constructors
    Person(int);
    Person(System::String^, System::String^);

    // Setters and getters
    int getID();
    System::String^ getFirstName();
    System::String^ getLastName();
    
    void setFirstName(System::String^);
    void setLastName(System::String^);

    // DB modification methods
    virtual void modify_in_DB();
    virtual void delete_in_DB();
    
};
