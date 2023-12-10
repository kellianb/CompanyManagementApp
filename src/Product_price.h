#pragma once
#include "SQL/SQLservices.h"


ref class Product_price
{
public:
    SQLservices^ SQLserv = gcnew SQLservices;

    void create_product_price_in_DB();
    void fetch_product_price_from_DB();

    int id_product;
    int id_product_price;
    int min_order_amount;
    int color_rgb_r;
    int color_rgb_g;
    int color_rgb_b;
    
    double price_excl_tax;
    double vat_percentage;

    System::DateTime price_date;

public:
    Product_price(int);

    Product_price(int, int, double, System::DateTime, int, int, int);

    int getID();

    int getIdProduct() 
    {
        return id_product;
    }

    void setIdProduct(int id_product)
    {
        this->id_product = id_product;
    }

    int getMinOrderAmount() 
    {
        return min_order_amount;
    }

    void setMinOrdeAmount(int min_order_amount)
    {
        this->min_order_amount = min_order_amount;
    }

    int getColorRgbR() 
    {
        return color_rgb_r;
    }

    void setColorRgbR(int color_rgb_r)
    {
        this->color_rgb_r = color_rgb_r;
    }

    int getColorRgbG() 
    {
        return color_rgb_g;
    }

    void setColorRgbG(int color_rgb_g)
    {
        this->color_rgb_g = color_rgb_g;
    }

    int getColorRgbB() 
    {
        return color_rgb_b;
    }

    void setColorRgbB(int color_rgb_b)
    {
        this->color_rgb_b = color_rgb_b;
    }

    double getPriceExclTax() 
    {
        return price_excl_tax;
    }

    void setPriceExclTax(double price_excl_tax)
    {
        this->price_excl_tax = price_excl_tax;
    }

    double getVatPercentage() 
    {
        return vat_percentage;
    }

    void setVatPercentage(double vat_percentage)
    {
        this->vat_percentage = vat_percentage;
    }

    System::DateTime getPriceDate() 
    {
        return price_date;
    }

    void setPriceDate( System::DateTime& price_date)
    {
        this->price_date = price_date;
    }

    void modify_product_price_in_DB();
    void delete_product_price_from_DB();
};
