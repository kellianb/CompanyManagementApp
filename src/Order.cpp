#include "Order.h"

void Order::create_order_in_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv->SQL_addOrder(this->delivery_date, this->order_date, this->discount_percentage, this->id_delivery_address, this->id_billing_address, this->id_customer);

    this->reference = safe_cast<System::String^>(buffer->Rows[0]["order_reference"]);
    this->id = safe_cast<int>(buffer->Rows[0]["id_order"]);
    
}

void Order::fetch_order_from_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv->SQL_getOrder(this->id);

    this->reference = safe_cast<System::String^>(buffer->Rows[0]["order_reference"]);
    this->delivery_date = safe_cast<System::DateTime>(buffer->Rows[0]["delivery_date"]);
    this->order_date = safe_cast<System::DateTime>(buffer->Rows[0]["order_date"]);
    this->discount_percentage = safe_cast<float>(buffer->Rows[0]["discount_percentage"]);
    this->total_amount = safe_cast<float>(buffer->Rows[0]["total_amount"]);
    this->id_customer = safe_cast<int>(buffer->Rows[0]["id_customer"]);
    this->id_delivery_address = safe_cast<int>(buffer->Rows[0]["id_delivery_address"]);
    this->id_billing_address = safe_cast<int>(buffer->Rows[0]["id_billing_address"]);
}

Order::Order(int id) : id(id)
{
    this->fetch_order_from_DB();
}

Order::Order(System::DateTime order_date, System::DateTime delivery_date, float discount_percentage, int id_delivery_address, int id_billing_address, int id_customer) : order_date(order_date), delivery_date(delivery_date), discount_percentage(discount_percentage), id_delivery_address(id_delivery_address), id_billing_address(id_billing_address), id_customer(id_customer)
{
    this->create_order_in_DB();
}


int Order::getID()
{
    return this->id;
}

System::String^ Order::getReference()
{
    return this->reference;
}

System::DateTime Order::getOrderDate()
{
    return this->order_date;
}

void Order::setOrderDate(System::DateTime date)
{
    this->order_date = date;
}

System::DateTime Order::getDeliveryDate()
{
    return this->delivery_date;
}

void Order::setDeliveryDate(System::DateTime date)
{
    this->delivery_date = date;
}

int Order::getDeliveryAddress()
{
    return this->id_delivery_address;
}

void Order::setDeliveryAddress(int id_adr)
{
    this->id_delivery_address = id_adr;
}

void Order::setBillingAddress(int id_adr)
{
    this->id_billing_address = id_adr;
}

void Order::modify_order_in_DB()
{
    this->SQLserv->SQL_modifyOrder(this->id, this->delivery_date, this->order_date, this->discount_percentage, this->id_delivery_address, this->id_billing_address, this->id_customer);
}

void Order::delete_order_from_DB()
{
    this->SQLserv->SQL_deleteOrder(this->id);
}
