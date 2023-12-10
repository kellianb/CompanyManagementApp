#pragma once

#include "SQL/SQLservices.h"

ref class Product
{
private:
    SQLservices^ SQLserv = gcnew SQLservices;

    void create_product_in_DB();
    void fetch_product_from_DB();
    
    int id;
    System::String^ product_name;
    int amount_in_stock;
    int reorder_threshold;
    float vat_percentage;

public:
    Product(int);

    Product(System::String^, int, int, float);

    int getID();

    System::String^ getProductName();
    void setProductName(System::String^);

    int getAmountInStock();
    void setAmountInStock(int);

    int getReorderThreshold();
    void setReorderThreshold(int);

    float getVATPercentage();
    void setVATPercentage(float);
    
    void modify_product_in_DB();
    void delete_product_from_DB();

    System::Data::DataTable^ getProductPrices();
};
