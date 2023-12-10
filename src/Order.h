#pragma once
#include "SQL/SQLservices.h"

ref class Order
{
private:
    SQLservices^ SQLserv = gcnew SQLservices;

    void create_order_in_DB();
    void fetch_order_from_DB();

    int id;

    System::String^ reference;

    System::DateTime order_date;
    System::DateTime delivery_date;

    int id_delivery_address;
    int id_billing_address;

    int id_customer;

    float total_amount;
    
    float discount_percentage;

public:
    Order(int);

    Order(System::DateTime, System::DateTime, float, int, int, int);

    int getID();

    System::String^ getReference();
    
    float getDiscoutPercentage();
    void setDiscountPercentage(float);
    
    System::DateTime getOrderDate();
    void setOrderDate(System::DateTime);

    System::DateTime getDeliveryDate();
    void setDeliveryDate(System::DateTime);

    int getDeliveryAddress();
    void setDeliveryAddress(int);

    int getBillingAddress();
    void setBillingAddress(int);

    void modify_order_in_DB();
    void delete_order_from_DB();

    System::Data::DataTable^ getProductsInOrderList();
};
