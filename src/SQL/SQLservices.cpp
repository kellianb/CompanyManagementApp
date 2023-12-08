#include "SQLservices.h"

#include <crtdbg.h>

// Constructor
SQLservices::SQLservices()
{
 this->SQLadapter = gcnew SQLdatabaseAdapter;   
}
// ---------------------------------------------------------------------------------------------------------------------

// Orders Queries
System::Data::DataTable^ SQLservices::SQL_addOrder(System::DateTime delivery_date, System::DateTime order_date, System::Decimal discount_percentage, System::Decimal amount, int id_delivery_address, int id_billing_address, int id_customer)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Orders (delivery_date, order_date, order_discount_percentage, total_amount, id_delivery_address, id_billing_adress, id_customer) OUTPUT inserted.id_person VALUES(@deliveryDate, @orderDate, @dctPercentage, @amount, @idDelivery, @idBilling, @idCustomer)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@deliveryDate", delivery_date);
    cmd->Parameters->AddWithValue("@orderDate", order_date);
    cmd->Parameters->AddWithValue("@dctPercentage", discount_percentage);
    cmd->Parameters->AddWithValue("@amount", amount);
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

System::Data::DataTable^ SQLservices::SQL_modifyOrder(int id_order, System::DateTime new_delivery_date, System::DateTime new_order_date, System::Decimal new_discount_percentage, System::Decimal new_amount, int id_delivery_address, int id_billing_address, int id_customer)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Orders SET delivery_date = @deliveryDate, order_date = @orderDate, order_discount_percentage = @dctPercentage, total_amount = @amount, id_delivery_address = @idAdress, id_billing_address = @idBilling, id_customer = @idCustomer WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id_order);
    cmd->Parameters->AddWithValue("@deliveryDate", new_delivery_date);
    cmd->Parameters->AddWithValue("@orderDate", new_order_date);
    cmd->Parameters->AddWithValue("@dctPercentage", new_discount_percentage);
    cmd->Parameters->AddWithValue("@amount", new_amount);
    cmd->Parameters->AddWithValue("@idDelivery", id_delivery_address);
    cmd->Parameters->AddWithValue("@idBilling", id_billing_address);
    cmd->Parameters->AddWithValue("@idCustomer", id_customer);

    return this->SQLadapter->sendQuery(cmd);
}

void SQLservices::SQL_deleteOrder(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Orders WHERE id_order = @id";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd);
}
// ---------------------------------------------------------------------------------------------------------------------

// Inventory Queries
System::Data::DataTable^ SQLservices::SQL_addProduct(System::String^, int amount, int reorder)
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_getProduct(int id)
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_getProductList()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_modifyProduct(int id, System::String^, int amount, int reorder)
{
    return nullptr;
}

void SQLservices::SQL_deleteProduct(int id)
{
    
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
    System::String^ cmdString = "SELECT id_order, order_reference, total_amount, order_discount_percentage, order_date, delivery_date FROM Projet_POO_Livrable.Orders WHERE id_customer = @id";

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
System::Data::DataTable^ SQLservices::SQL_addEmployee(int id_person, System::DateTime hiring_date, int id_address, int id_manager)
{
        System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Employees (id_person, hiring_date, id_address, id_manager) OUTPUT inserted.id_person VALUES(@idPerson, @hiringDate, @Address, @manager)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@idPerson", id_person);
    cmd->Parameters->AddWithValue("@hiringDate", hiring_date);
    cmd->Parameters->AddWithValue("@address", id_address);
    cmd->Parameters->AddWithValue("@Manager", id_manager);

    return this->SQLadapter->sendQuery(cmd);
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

System::Data::DataTable^ SQLservices::SQL_modifyEmployee(int id_person, System::DateTime new_hiring_date, int id_address, int id_manager)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.Employees SET hiring_date = @hiringDate, id_address = @address WHERE id_person = @idPerson";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@idPerson", id_person);
    cmd->Parameters->AddWithValue("@hiringDate", new_hiring_date);
    cmd->Parameters->AddWithValue("@address", id_address);
    cmd->Parameters->AddWithValue("@manager", id_manager);

    return this->SQLadapter->sendQuery(cmd);
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
// ---------------------------------------------------------------------------------------------------------------------

// Statistics Queries
System::Data::DataTable^ SQLservices::SQL_calculateAverageBasketSize()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_calculateMonthlyTurnover(System::DateTime month)
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_identifyProductsBelowThreshold()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_calculateTotalPurchasesByCustomer(int customerId)
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_identifyTop10BestSellingItems()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_identifyTop10LeastSellingItems()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_calculateCommercialStockValue()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_calculatePurchaseStockValue()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_simulateStockValueVariations(array<System::String^>^ modifications)
{
    return nullptr;
}
// ---------------------------------------------------------------------------------------------------------------------

// Misc Queries
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

