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
