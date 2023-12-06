#include "Customer.h"

void Customer::create_customer_in_DB()
{
    this->SQLserv.SQL_addCustomer(this->id, this->birth_date);
}

void Customer::fetch_customer_from_DB()
{
    
    System::Data::DataSet^ buffer = this->SQLserv.SQL_getCustomer(this->id);

    this->birth_date = safe_cast<System::DateTime>(buffer->Tables["Customer"]->Rows[0]["birth_date"]);
}

void Customer::modify_customer_in_DB()
{
    this->SQLserv.SQL_modifyCustomer(this->id, this->birth_date);
}

void Customer::delete_customer_from_DB()
{
    this->SQLserv.SQL_deleteCustomer(this->id);
}

Customer::Customer(int id) : Person(id)
{
    fetch_customer_from_DB();
}

Customer::Customer(System::String^ first_name, System::String^ last_name, System::DateTime birth_date): Person(first_name, last_name), birth_date(birth_date)
{
    create_customer_in_DB();
}

System::DateTime Customer::getBirthDate()
{
    return this->birth_date;
}

void Customer::setBirthDate(System::DateTime birth_date_param)
{
    this->birth_date = birth_date_param;
}

void Customer::modify_in_DB()
{
    this->modify_person_in_DB();
    this->modify_customer_in_DB();
}

void Customer::delete_in_DB()
{
    this->delete_customer_from_DB();
    this->delete_person_from_DB();
}

System::Data::DataSet^ Customer::getOrders()
{
    return nullptr;
}
