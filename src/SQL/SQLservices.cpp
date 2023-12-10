#include "SQLservices.h"

#include <crtdbg.h>

// Constructor
SQLservices::SQLservices()
{
 this->SQLadapter = gcnew SQLdatabaseAdapter;   
}
// ---------------------------------------------------------------------------------------------------------------------

// Orders Queries
System::Data::DataTable^ SQLservices::SQL_addOrder(System::DateTime delivery_date, System::DateTime order_date, float discount_percentage, int id_delivery_address, int id_billing_address, int id_customer)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Orders (delivery_date, order_date, order_discount_percentage, id_delivery_address, id_billing_address, id_customer) OUTPUT inserted.id_order VALUES(@deliveryDate, @orderDate, @dctPercentage, @idDelivery, @idBilling, @idCustomer)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@deliveryDate", delivery_date);
    cmd->Parameters->AddWithValue("@orderDate", order_date);
    cmd->Parameters->AddWithValue("@dctPercentage", discount_percentage);
    cmd->Parameters->AddWithValue("@idDelivery", id_delivery_address);
    cmd->Parameters->AddWithValue("@idBilling", id_billing_address);
    cmd->Parameters->AddWithValue("@idCustomer", id_customer);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getOrder(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Orders WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getOrderList()
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Orders";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getOrderBillingAdress(int id)
{
    System::String^ cmdString = "SELECT hba.id_address, A.city, A.postal_code, A.street, A.street_number FROM Projet_POO_Livrable.Orders JOIN Projet_POO_Livrable.has_billing_address hba on Customers.id_order = hba.id_order JOIN Projet_POO_Livrable.Addresses A on A.id_address = hba.id_address WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getOrderDeliveryAdress(int id)
{
    System::String^ cmdString = "SELECT hda.id_address, A.city, A.postal_code, A.street, A.street_number FROM Projet_POO_Livrable.Orders JOIN Projet_POO_Livrable.has_delivery_address hda on Customers.id_order = hda.id_order JOIN Projet_POO_Livrable.Addresses A on A.id_address = hda.id_address WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_modifyOrder(int id_order, System::DateTime new_delivery_date, System::DateTime new_order_date, float new_discount_percentage, int id_delivery_address, int id_billing_address, int id_customer)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Orders SET delivery_date = @deliveryDate, order_date = @orderDate, order_discount_percentage = @dctPercentage, id_delivery_address = @idDelivery, id_billing_address = @idBilling, id_customer = @idCustomer WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id_order);
    cmd->Parameters->AddWithValue("@deliveryDate", new_delivery_date);
    cmd->Parameters->AddWithValue("@orderDate", new_order_date);
    cmd->Parameters->AddWithValue("@dctPercentage", new_discount_percentage);
    cmd->Parameters->AddWithValue("@idDelivery", id_delivery_address);
    cmd->Parameters->AddWithValue("@idBilling", id_billing_address);
    cmd->Parameters->AddWithValue("@idCustomer", id_customer);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_removeAllProductsFromOrder(int id_order)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.contains_product WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id_order);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteOrder(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Orders WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getProductsInOrderList(int id_order)
{   
    System::String^ cmdString = "SELECT P.id_product, P.product_name, CP.price, CP.product_quantity, CP.product_discount_percentage, CP.color_rgb_r, CP.color_rgb_g, CP.color_rgb_b FROM Projet_POO_Livrable.contains_product CP JOIN Projet_POO_Livrable.Products P on P.id_product = CP.id_product WHERE id_order = @idOrder";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idOrder", id_order);
    
    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_addProductToOrder(int id_order, int id_product, int amount, float discount, int color_rgb_r, int color_rgb_g, int color_rgb_b)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.contains_product (id_order, id_product, product_quantity, product_discount_percentage, color_rgb_r, color_rgb_g, color_rgb_b) VALUES (@idOrder, @idProduct, @product_quantity, @productDiscountPercentage, @color_rgb_r, @color_rgb_g, @color_rgb_b)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idOrder", id_order);
    cmd->Parameters->AddWithValue("@idProduct", id_product);
    cmd->Parameters->AddWithValue("@product_quantity", amount);
    cmd->Parameters->AddWithValue("@productDiscountPercentage", discount);
    cmd->Parameters->AddWithValue("@color_rgb_r", color_rgb_r);
    cmd->Parameters->AddWithValue("@color_rgb_g", color_rgb_g);
    cmd->Parameters->AddWithValue("@color_rgb_b", color_rgb_b);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_removeProductFromOrder(int id_order, int id_product, int color_rgb_r, int color_rgb_g, int color_rgb_b)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.contains_product WHERE id_order = @idOrder AND id_product = @idProduct AND color_rgb_r = @color_rgb_r AND color_rgb_g = @color_rgb_g AND color_rgb_b = @color_rgb_b";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idOrder", id_order);
    cmd->Parameters->AddWithValue("@idProduct", id_product);
    cmd->Parameters->AddWithValue("@color_rgb_r", color_rgb_r);
    cmd->Parameters->AddWithValue("@color_rgb_g", color_rgb_g);
    cmd->Parameters->AddWithValue("@color_rgb_b", color_rgb_b);

    this->SQLadapter->sendQuery(cmd);
}


// ---------------------------------------------------------------------------------------------------------------------

// Inventory Queries
System::Data::DataTable^ SQLservices::SQL_addProduct(System::String^ productName, int amountInStock, int reorderThreshold, float vatPercentage)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Products (product_name, amount_in_stock, reorder_threshold, vat_percentage) OUTPUT inserted.id_product VALUES(@productName, @amountInStock, @reorderThreshold, @vatPercentage)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@productName", productName);
    cmd->Parameters->AddWithValue("@amountInStock", amountInStock);
    cmd->Parameters->AddWithValue("@reorderThreshold", reorderThreshold);
    cmd->Parameters->AddWithValue("@vatPercentage", vatPercentage);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getProduct(int idProduct)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Products WHERE id_product = @idProduct";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@idProduct", idProduct);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getProductList()
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Products";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_modifyProduct(int id, System::String^ newProductName, int newAmountInStock, int newReorderThreshold, float newVatPercentage)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Products SET product_name = @productName, amount_in_stock = @amountInStock, reorder_threshold = @reorderThreshold, vat_percentage = @vatPercentage WHERE id_product = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);
    cmd->Parameters->AddWithValue("@productName", newProductName);
    cmd->Parameters->AddWithValue("@amountInStock", newAmountInStock);
    cmd->Parameters->AddWithValue("@reorderThreshold", newReorderThreshold);
    cmd->Parameters->AddWithValue("@vatPercentage", newVatPercentage);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getAvailableColors(int id_product, int amount)
{
    System::String^ cmdString = "SELECT color_rgb_r, color_rgb_g, color_rgb_b FROM Projet_POO_Livrable.Product_prices WHERE id_product = @idProduct AND min_order_amount <= @amount GROUP BY color_rgb_r, color_rgb_g, color_rgb_b";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idProduct", id_product);
    cmd->Parameters->AddWithValue("@amount", amount);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteProduct(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Products WHERE id_product = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getProductPricesListForProduct(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Product_prices WHERE id_product = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}


// ---------------------------------------------------------------------------------------------------------------------

// Product prices Queries

System::Data::DataTable^ SQLservices::SQL_addProductPrice(int id_product, int min_order_amount, float price_excl_tax, System::DateTime price_date, int color_rgb_r, int color_rgb_g, int color_rgb_b)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Product_prices (id_product, min_order_amount, price_excl_tax, price_date, color_rgb_r, color_rgb_g, color_rgb_b) OUTPUT inserted.id_product_price VALUES(@idProduct, @minOrderAmount, @priceExclTax, @priceDate, @colorR, @colorG, @colorB)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idProduct", id_product);
    cmd->Parameters->AddWithValue("@minOrderAmount", min_order_amount);
    cmd->Parameters->AddWithValue("@priceExclTax", price_excl_tax);
    cmd->Parameters->AddWithValue("@priceDate", price_date);
    cmd->Parameters->AddWithValue("@colorR", color_rgb_r);
    cmd->Parameters->AddWithValue("@colorG", color_rgb_g);
    cmd->Parameters->AddWithValue("@colorB", color_rgb_b);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getProductPrice(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Product_prices WHERE id_product_price = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}



System::Data::DataTable^ SQLservices::SQL_getProductPriceList()
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Product_prices";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_modifyProductPrice(int id_product_price, int min_order_amount, float price_excl_tax, System::DateTime price_date, int color_rgb_r, int color_rgb_g, int color_rgb_b)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Product_prices SET min_order_amount = @minOrderAmount, price_excl_tax = @priceExclTax, price_date = @priceDate, color_rgb_r = @colorR, color_rgb_g = @colorG, color_rgb_b = @colorB WHERE id_product_price = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id_product_price);
    cmd->Parameters->AddWithValue("@minOrderAmount", min_order_amount);
    cmd->Parameters->AddWithValue("@priceExclTax", price_excl_tax);
    cmd->Parameters->AddWithValue("@priceDate", price_date);
    cmd->Parameters->AddWithValue("@colorR", color_rgb_r);
    cmd->Parameters->AddWithValue("@colorG", color_rgb_g);
    cmd->Parameters->AddWithValue("@colorB", color_rgb_b);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteProductPrice(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Product_prices WHERE id_product_price = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}

// ---------------------------------------------------------------------------------------------------------------------


// Person queries
System::Data::DataTable^ SQLservices::SQL_addPerson(System::String^ first_name, System::String^ last_name)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.People (first_name, last_name) OUTPUT inserted.id_person VALUES(@fname, @lname)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@fname", first_name);
    cmd->Parameters->AddWithValue("@lname", last_name);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getPerson(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.People WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_modifyPerson(int id, System::String^ new_first_name, System::String^ new_last_name)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.People SET first_name = @fname, last_name = @lname WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);
    cmd->Parameters->AddWithValue("@fname", new_first_name);
    cmd->Parameters->AddWithValue("@lname", new_last_name);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deletePerson(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.People WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}
// ---------------------------------------------------------------------------------------------------------------------

// Customer queries
System::Data::DataTable^ SQLservices::SQL_addCustomer(int id, System::DateTime birth_date)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Customers (id_person, birth_date) OUTPUT inserted.id_person VALUES(@id, @birthDate)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);
    cmd->Parameters->AddWithValue("@birthDate", birth_date);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getCustomerList()
{
    System::String^ cmdString = "SELECT C.id_person, P.first_name, P.last_name, C.birth_date, C.first_order_date FROM Projet_POO_Livrable.Customers C JOIN Projet_POO_Livrable.People P on P.id_person = C.id_person";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getCustomer(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Customers WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_modifyCustomer(int id, System::DateTime new_birth_date)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.customers SET birth_date = @birthDate WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@birthDate", new_birth_date);
    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteCustomer(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Customers WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    SQL_deleteCustomerOrders(id);
    SQL_deleteCustomerAddresses(id);

    this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getCustomerOrders(int id)
{
    System::String^ cmdString = "SELECT id_order, order_reference, total_amount, order_discount_percentage, order_date, delivery_date, id_delivery_address, id_billing_address FROM Projet_POO_Livrable.Orders WHERE id_customer = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteCustomerOrders(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Orders WHERE id_customer IN (SELECT id_person FROM Projet_POO_Livrable.Customers WHERE id_person = @id)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteCustomerAddresses(int id)
{
    System::String^ cmdString1 = "DELETE FROM Projet_POO_Livrable.has_billing_address WHERE id_customer = @id";
    System::String^ cmdString2 = "DELETE FROM Projet_POO_Livrable.has_delivery_address WHERE id_customer = @id";
    System::String^ cmdString3 = "DELETE FROM Projet_POO_Livrable.Addresses WHERE id_address IN (SELECT A.id_address FROM Projet_POO_Livrable.Addresses A LEFT JOIN Projet_POO_Livrable.has_billing_address B ON A.id_address = B.id_address LEFT JOIN Projet_POO_Livrable.has_delivery_address D ON A.id_address = D.id_address WHERE B.id_address IS NULL AND D.id_address IS NULL)";

    System::Data::SqlClient::SqlCommand^ cmd1 = gcnew System::Data::SqlClient::SqlCommand(cmdString1);
    System::Data::SqlClient::SqlCommand^ cmd2 = gcnew System::Data::SqlClient::SqlCommand(cmdString2);
    System::Data::SqlClient::SqlCommand^ cmd3 = gcnew System::Data::SqlClient::SqlCommand(cmdString3);
    
    cmd1->Parameters->AddWithValue("@id", id);
    cmd2->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd1);
    this->SQLadapter->sendQuery(cmd2);
    this->SQLadapter->sendQuery(cmd3);
}

System::Data::DataTable^ SQLservices::SQL_addBillingAddressesToCustomer(int id_customer, int id_address) 
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.has_billing_address (id_address, id_customer) VALUES(@idAddress, @idCustomer)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idAddress", id_address);
    cmd->Parameters->AddWithValue("@idCustomer", id_customer);
    
    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_addDeliveryAddressesToCustomer(int id_customer, int id_address) 
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.has_delivery_address (id_address, id_customer) VALUES (@idAddress, @idCustomer)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idAddress", id_address);
    cmd->Parameters->AddWithValue("@idCustomer", id_customer);
    
    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_deleteBillingAddressesFromCustomer(int id_customer, int id_address)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.has_billing_address WHERE id_customer = @idCustomer AND id_address = @idAddress";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idAddress", id_address);
    cmd->Parameters->AddWithValue("@idCustomer", id_customer);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_deleteDeliveryAddressesFromCustomer(int id_customer, int id_address)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.has_delivery_address WHERE id_customer = @idCustomer AND id_address = @idAddress";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@idCustomer", id_customer);
    cmd->Parameters->AddWithValue("@idAddress", id_address);

    return this->SQLadapter->sendQuery(cmd);
}


System::Data::DataTable^ SQLservices::SQL_getCustomerBillingAddresses(int id)
{
    System::String^ cmdString = "SELECT hba.id_address, A.city, A.postal_code, A.street, A.street_number FROM Projet_POO_Livrable.Customers JOIN Projet_POO_Livrable.has_billing_address hba on Customers.id_person = hba.id_customer JOIN Projet_POO_Livrable.Addresses A on A.id_address = hba.id_address WHERE id_customer = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getCustomerDeliveryAddresses(int id)
{
    System::String^ cmdString = "SELECT hda.id_address, A.city, A.postal_code, A.street, A.street_number FROM Projet_POO_Livrable.Customers JOIN Projet_POO_Livrable.has_delivery_address hda on Customers.id_person = hda.id_customer JOIN Projet_POO_Livrable.Addresses A on A.id_address = hda.id_address WHERE id_customer = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}
// ---------------------------------------------------------------------------------------------------------------------

// Employee Queries
void SQLservices::SQL_addEmployee(int id_person, System::DateTime hiring_date, int id_address)
{
        System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Employees (id_person, hiring_date, id_address) VALUES(@idPerson, @hiringDate, @Address)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@idPerson", id_person);
    cmd->Parameters->AddWithValue("@hiringDate", hiring_date);
    cmd->Parameters->AddWithValue("@address", id_address);

    this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getEmployeeList()
{
    System::String^ cmdString = "SELECT E.id_person, P.first_name, P.last_name, E.hiring_date, E.id_address, E.id_manager FROM Projet_POO_Livrable.Employees E JOIN Projet_POO_Livrable.People P on P.id_person = E.id_person";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getEmployee(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Employees WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_modifyEmployee(int id_person, System::DateTime new_hiring_date)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Employees SET hiring_date = @hiringDate WHERE id_person = @idPerson";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idPerson", id_person);
    cmd->Parameters->AddWithValue("@hiringDate", new_hiring_date);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteEmployee(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Employees WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteEmployeeAddresses(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Addresses WHERE id_address IN (SELECT A.id_address FROM Projet_POO_Livrable.Addresses A LEFT JOIN Projet_POO_Livrable.has_billing_address B ON A.id_address = B.id_address LEFT JOIN Projet_POO_Livrable.has_delivery_address D ON A.id_address = D.id_address WHERE B.id_address IS NULL AND D.id_address IS NULL)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_setEmployeeManager(int id_employee, int id_manager)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Employees SET id_manager = @idManager WHERE id_person = @idPerson";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idPerson", id_employee);
    cmd->Parameters->AddWithValue("@idManager", id_manager);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_removeEmployeeManager(int id_employee)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Employees SET id_manager = NULL WHERE id_person = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id_employee);

    this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_removeEmployeeAsManager(int id_employee)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Employees SET id_manager = NULL WHERE id_manager = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id_employee);

    this->SQLadapter->sendQuery(cmd);
}


// ---------------------------------------------------------------------------------------------------------------------

// Statistics Queries
System::Data::DataTable^ SQLservices::SQL_calculateAverageBasketSize()
{
    System::String^ cmdString;
    cmdString = "SELECT CAST(ROUND(AVG(total_amount),2)AS decimal(10,2)) AS Prix_moyen_panier FROM Projet_POO_Livrable.Orders";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_calculateMonthlyTurnover(System::DateTime month)
{
    System::String^ cmdString;
    cmdString = "SELECT MONTH(payment_date) AS Month, CAST(SUM(amount) AS decimal(10,2)) Month_sales FROM Projet_POO_Livrable.Payments WHERE MONTH(payment_date) = @month GROUP BY MONTH(payment_date)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@month", month);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_identifyProductsBelowThreshold()
{
    System::String^ cmdString;
    cmdString = "SELECT id_product, product_name, amount_in_stock, reorder_threshold FROM Projet_POO_Livrable.Products WHERE amount_in_stock <= reorder_threshold";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_calculateTotalPurchasesByCustomer(int customerId)
{
    System::String^ cmdString;
    cmdString = "SELECT P.id_person ,P.last_name, P.first_name, SUM(O.total_amount) AS Total_amount FROM Projet_POO_Livrable.Customers JOIN Projet_POO_Livrable.People P on P.id_person = Customers.id_person JOIN Projet_POO_Livrable.Orders O on Customers.id_person = O.id_customer WHERE P.id_person = @customerId GROUP BY P.id_person, P.last_name, P.first_name";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@customerId", customerId);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_identifyTop10BestSellingItems()
{
    System::String^ cmdString;
    cmdString = "SELECT TOP 10 P.id_product,product_name, SUM(product_quantity) AS total_ordered_quantity FROM Projet_POO_Livrable.contains_product JOIN Projet_POO_Livrable.Orders O on O.id_order = contains_product.id_order JOIN Projet_POO_Livrable.Products P on P.id_product = contains_product.id_product GROUP BY P.id_product, product_name ORDER BY total_ordered_quantity DESC";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_identifyTop10LeastSellingItems()
{
    System::String^ cmdString;
    cmdString = "SELECT TOP 10 P.id_product,product_name, SUM(product_quantity) AS total_ordered_quantity FROM Projet_POO_Livrable.contains_product JOIN Projet_POO_Livrable.Orders O on O.id_order = contains_product.id_order JOIN Projet_POO_Livrable.Products P on P.id_product = contains_product.id_product GROUP BY P.id_product, product_name ORDER BY total_ordered_quantity";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_calculateCommercialStockValue()
{
    System::String^ cmdString;
    cmdString = "SELECT CAST(ROUND(SUM(amount_in_stock*(price_excl_tax + (price_excl_tax*(vat_percentage/100)))),2) AS decimal(10,2)) AS stock_commercial_value FROM Projet_POO_Livrable.Products JOIN Projet_POO_Livrable.Product_prices Pp on Products.id_product = Pp.id_product";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_calculatePurchaseStockValue()
{
    System::String^ cmdString;
    cmdString = "SELECT SUM(amount_in_stock*price_excl_tax) AS stock_buying_value FROM Projet_POO_Livrable.Products JOIN Projet_POO_Livrable.Product_prices Pp on Products.id_product = Pp.id_product";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_simulateStockValueVariations(array<System::String^>^ modifications)
{
    return nullptr;
}

/*
System::Data::DataTable^ SQLservices::SQL_simulateStockValueVariations(array<System::String^>^ modifications)
{
    return nullptr;
}
*/

// ---------------------------------------------------------------------------------------------------------------------

// Address Queries
System::Data::DataTable^ SQLservices::SQL_addAddress(System::String^ city, System::String^ street, int postal_code,
    int street_number)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Addresses (city, street, postal_code, street_number) OUTPUT inserted.id_address VALUES(@city, @street, @postalCode, @streetNumber)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@city", city);
    cmd->Parameters->AddWithValue("@street", street);
    cmd->Parameters->AddWithValue("@postalCode", postal_code);
    cmd->Parameters->AddWithValue("@streetNumber", street_number);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getAddress(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Addresses WHERE id_address = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getAddressList()
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Addresses";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_modifyAddress(int id, System::String^ city, System::String^ street, int postal_code,
    int street_number)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Addresses SET city = @city, street = @street, postal_code = @postalCode, street_number = @streetNumber WHERE id_address = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@id", id);
    cmd->Parameters->AddWithValue("@city", city);
    cmd->Parameters->AddWithValue("@street", street);
    cmd->Parameters->AddWithValue("@postalCode", postal_code);
    cmd->Parameters->AddWithValue("@streetNumber", street_number);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteAddress(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Addresses WHERE id_address = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}
