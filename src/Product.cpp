#include "Product.h"

void Product::create_product_in_DB()
{
    this->SQLserv->SQL_addProduct(this->product_name, this->amount_in_stock, this->reorder_threshold, this->vat_percentage);
}

void Product::fetch_product_from_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv->SQL_getProduct(this->id);
    
    this->product_name = buffer->Rows[0]["product_name"]->ToString();
    this->amount_in_stock = System::Convert::ToInt32(buffer->Rows[0]["amount_in_stock"]);
    this->reorder_threshold = System::Convert::ToInt32(buffer->Rows[0]["reorder_threshold"]);
    this->vat_percentage = System::Convert::ToSingle(buffer->Rows[0]["vat_percentage"]);
}

Product::Product(int id) : id(id)
{
    fetch_product_from_DB();
}

Product::Product(System::String^ name, int amount_in_stock, int reorder_threshold, float vat_percentage) : product_name(name), amount_in_stock(amount_in_stock), reorder_threshold(reorder_threshold), vat_percentage(vat_percentage)
{
    create_product_in_DB();
}


int Product::getID()
{
    return this->id;
}

System::String^ Product::getProductName()
{
    return this->product_name;
}

void Product::setProductName(System::String^ product_name_param)
{
    this->product_name = product_name_param;
}

int Product::getAmountInStock()
{
    return this->amount_in_stock;
}

void Product::setAmountInStock(int amount_in_stock_param)
{
    this->amount_in_stock = amount_in_stock_param;
}

int Product::getReorderThreshold()
{
    return this->reorder_threshold;
}

void Product::setReorderThreshold(int reorder_threshold_param)
{
    this->reorder_threshold = reorder_threshold_param;
}

float Product::getVATPercentage()
{
    return this->vat_percentage;
}

void Product::setVATPercentage(float vat_percentage_param)
{
    this->vat_percentage = vat_percentage_param;
}

void Product::modify_product_in_DB()
{
    this->SQLserv->SQL_modifyProduct(this->id, this->product_name, this->amount_in_stock, this->reorder_threshold, this->vat_percentage);
}

void Product::delete_product_from_DB()
{
    this->SQLserv->SQL_deleteProduct(this->id);
}

System::Data::DataTable^ Product::getProductPrices()
{
    System::Data::DataTable^ myDataTable = this->SQLserv->SQL_getProductPricesListForProduct(this->id);

    return myDataTable;
}

System::Data::DataTable^ Product::getAvailableColors(int amount)
{
    return SQLserv->SQL_getAvailableColors(this->id, amount);
}


float Product::get_price_for_product(int color_rgb_r, int color_rgb_g, int color_rgb_b, int amount, float discount)
{
    return this->SQLserv->SQL_getPriceForProduct(this->id, color_rgb_r, color_rgb_g, color_rgb_b, amount, discount);
}


