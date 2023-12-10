#include "Product_price.h"

void Product_price::create_product_price_in_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv->SQL_addProductPrice(this->id_product, this->min_order_amount, this->price_excl_tax, this->price_date, this->color_rgb_r, this->color_rgb_g, this->color_rgb_b);

    this->id_product_price = safe_cast<int>(buffer->Rows[0]["id_product_price"]);
}

void Product_price::fetch_product_price_from_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv->SQL_getProductPrice(this->id_product_price);

    this->id_product = safe_cast<int>(buffer->Rows[0]["id_product"]);
    this->min_order_amount = safe_cast<int>(buffer->Rows[0]["min_order_amount"]);
    this->price_excl_tax = System::Convert::ToDouble(buffer->Rows[0]["price_excl_tax"]);
    this->price_date = safe_cast<System::DateTime>(buffer->Rows[0]["price_date"]);
    this->color_rgb_r = safe_cast<int>(buffer->Rows[0]["color_rgb_r"]);
    this->color_rgb_g = safe_cast<int>(buffer->Rows[0]["color_rgb_g"]);
    this->color_rgb_b = safe_cast<int>(buffer->Rows[0]["color_rgb_b"]);
}

Product_price::Product_price(int id_product_price) : id_product_price(id_product_price)
{
    this->fetch_product_price_from_DB();
}

Product_price::Product_price(int id_product, int min_order_amount, double price_excl_tax, System::DateTime price_date, int color_rgb_r, int color_rgb_g, int color_rgb_b) : id_product(id_product), min_order_amount(min_order_amount), price_excl_tax(price_excl_tax), price_date(price_date), color_rgb_r(color_rgb_r), color_rgb_g(color_rgb_g), color_rgb_b(color_rgb_b)
{
    this->create_product_price_in_DB();
}

int Product_price::getID()
{
    return this->id_product_price;
}

void Product_price::modify_product_price_in_DB()
{
    this->SQLserv->SQL_modifyProductPrice(this->id_product_price, this->min_order_amount, this->price_excl_tax, this->price_date, this->color_rgb_r, this->color_rgb_g, this->color_rgb_b);
}

void Product_price::delete_product_price_from_DB()
{
    this->SQLserv->SQL_deleteProductPrice(this->id_product_price);
}