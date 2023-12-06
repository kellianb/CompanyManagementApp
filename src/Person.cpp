#include "Person.h"


void Person::create_person_in_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv.SQL_addPerson(this->first_name, this->last_name);

    this->id = System::Convert::ToInt32(buffer->Rows[0]["id_person"]);
}

void Person::fetch_person_from_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv.SQL_getPerson(this->id);
    
    this->first_name = buffer->Rows[0]["first_name"]->ToString();
    this->last_name = buffer->Rows[0]["last_name"]->ToString();
}

Person::Person(int id): id(id)
{
    fetch_person_from_DB();
}

// Create a new person and submit it to de DB
Person::Person(System::String^ first_name, System::String^ last_name): first_name(first_name), last_name(last_name)
{
    create_person_in_DB();
}

System::String^ Person::getFirstName()
{
    return this->first_name;
}

System::String^ Person::getLastName()
{
    return this->last_name;
}

void Person::setFirstName(System::String^ first_name_param)
{
    this->first_name = first_name_param;
}

void Person::setLastName(System::String^ last_name_param)
{
    this->last_name = last_name_param;
}

void Person::modify_person_in_DB()
{
    this->SQLserv.SQL_modifyPerson(this->id, this->first_name, this->last_name);
}

void Person::delete_person_from_DB()
{
    this->SQLserv.SQL_deletePerson(this->id);
}


void Person::modify_in_DB()
{
    modify_person_in_DB();
}

void Person::delete_in_DB()
{
    delete_person_from_DB();
}
