#include "Address.h"

void Address::create_address_in_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv.SQL_addAddress(this->city, this->street, this->postal_code, this->street_number);

    this->id = System::Convert::ToInt32(buffer->Rows[0]["id_address"]);
}

void Address::fetch_address_from_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv.SQL_getAddress(this->id);

    this->city = buffer->Rows[0]["city"]->ToString();
    this->postal_code = System::Convert::ToInt32(buffer->Rows[0]["postal_code"]->ToString());
    this->street = buffer->Rows[0]["street"]->ToString();
    this->street_number = System::Convert::ToInt32(buffer->Rows[0]["street_number"]->ToString());
}

void Address::modify_address_in_DB()
{
    this->SQLserv.SQL_modifyAddress(this->id, this->city, this->street, this->postal_code, this->street_number);
}

void Address::delete_address_from_DB()
{
    this->SQLserv.SQL_deleteAddress(this->id);
}


Address::Address(int id): id(id)
{
    fetch_address_from_DB();
}

Address::Address(System::String^ city, int postal_code, System::String^ street, int street_number): city(city), postal_code(postal_code), street(street), street_number(street_number)
{
    create_address_in_DB();
}
