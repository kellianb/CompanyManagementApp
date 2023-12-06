#pragma once
#include "SQL/SQLservices.h"

ref class Person
{
private:
    void create_person_in_DB();
    virtual void fetch_person_from_DB();
    
protected:
    int id;
    System::String^ first_name;
    System::String^ last_name;
    SQLservices SQLserv;
    void modify_person_in_DB();
    void delete_person_from_DB();

public:
    Person(int);
    Person(System::String^, System::String^);

    System::String^ getFirstName();
    System::String^ getLastName();

    void setFirstName(System::String^);
    void setLastName(System::String^);
    
    virtual void modify_from_DB();
    virtual void delete_from_DB();

};
