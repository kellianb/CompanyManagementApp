﻿#include "Customer.h"

void Customer::create_customer_in_DB()
{
    this->SQLserv->SQL_addCustomer(this->id, this->birth_date);
}

void Customer::fetch_customer_from_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv->SQL_getCustomer(this->id);

    this->birth_date = safe_cast<System::DateTime>(buffer->Rows[0]["birth_date"]);
}

void Customer::delete_all_orders()
{
    this->SQLserv->SQL_deleteCustomerOrders(this->id);
}

void Customer::modify_customer_in_DB()
{
    this->SQLserv->SQL_modifyCustomer(this->id, this->birth_date);
}

void Customer::delete_customer_from_DB()
{
    this->SQLserv->SQL_deleteCustomer(this->id);
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
    this->delete_all_orders();
    this->delete_customer_from_DB();
    this->delete_person_from_DB();
}

System::Data::DataTable^ Customer::getOrders()
{
    System::Data::DataTable^ myDataTable = this->SQLserv->SQL_getCustomerOrders(this->id);

    /*
    for each (System::Data::DataColumn^ column in myDataTable->Columns)
    {
        System::Console::WriteLine("Column Name: " + column->ColumnName);
        System::Console::WriteLine("Data Type: " + column->DataType->FullName);
        System::Console::WriteLine("Allow DBNull: " + column->AllowDBNull);
        System::Console::WriteLine("-----");
    }*/
    
    return myDataTable;
}

System::Data::DataTable^ Customer::getBillingAddresses()
{
    return this->SQLserv->SQL_getCustomerBillingAddresses(this->id);
}

System::Data::DataTable^ Customer::getDeliveryAddresses()
{
    return this->SQLserv->SQL_getCustomerDeliveryAddresses(this->id);
}

void Customer::addBillingAddressToCustomer(int id_address)
{
    this->SQLserv->SQL_addBillingAddressesToCustomer(this->id, id_address);
}

void Customer::addDeliveryAddressToCustomer(int id_address)
{
    this->SQLserv->SQL_addDeliveryAddressesToCustomer(this->id, id_address);
}

void Customer::deleteBillingAddressFromCustomer(int id_address)
{
    this->SQLserv->SQL_deleteBillingAddressesFromCustomer(this->id, id_address);
}

void Customer::deleteDeliveryAddressFromCustomer(int id_address)
{
    this->SQLserv->SQL_deleteDeliveryAddressesFromCustomer(this->id, id_address);
}


