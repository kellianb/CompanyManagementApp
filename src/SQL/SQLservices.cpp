#include "SQLservices.h"

#include <crtdbg.h>

// Constructor
SQLservices::SQLservices()
{
 this->SQLadapter = gcnew SQLdatabaseAdapter;   
}
// ---------------------------------------------------------------------------------------------------------------------

// Orders Queries
System::Data::DataTable^ SQLservices::SQL_addOrder(System::DateTime, System::DateTime, System::Decimal, System::Decimal,
    int id_delivery_address, int id_billing_address, int id_customer)
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_getOrder(int id)
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_getOrderList()
{
    return nullptr;
}

System::Data::DataTable^ SQLservices::SQL_modifyOrder(int id_order, System::DateTime, System::DateTime, System::Decimal,
    System::Decimal, int id_delivery_address, int id_billing_address, int id_customer)
{
    return nullptr;
}

void SQLservices::SQL_deleteOrder(int id)
{
    
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
    System::String^ cmdString = "SELECT C.id_person, P.first_name, P.last_name, C.birth_date, C.first_order_date FROM Projet_POO.Projet_POO_Livrable.Customers C JOIN Projet_POO_Livrable.People P on P.id_person = C.id_person";
    
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
    //System::String^ cmdString3 = "DELETE FROM Projet_POO_Livrable.Addresses WHERE id_address IN (SELECT A.id_address FROM Projet_POO_Livrable.Addresses A LEFT JOIN Projet_POO_Livrable.has_billing_address B ON A.id_address = B.id_address LEFT JOIN Projet_POO_Livrable.has_delivery_address D ON A.id_address = D.id_address WHERE B.id_address IS NULL AND D.id_address IS NULL)";

    System::Data::SqlClient::SqlCommand^ cmd1 = gcnew System::Data::SqlClient::SqlCommand(cmdString1);
    System::Data::SqlClient::SqlCommand^ cmd2 = gcnew System::Data::SqlClient::SqlCommand(cmdString2);
    //System::Data::SqlClient::SqlCommand^ cmd3 = gcnew System::Data::SqlClient::SqlCommand(cmdString3);
    
    cmd1->Parameters->AddWithValue("@id", id);
    cmd2->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd1);
    this->SQLadapter->sendQuery(cmd2);
    // this->SQLadapter->sendQuery(cmd3, "Address"); TODO : Implement it at the end or else every addresses will be Deleted when testing
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
    System::String^ cmdString = "SELECT E.id_person, P.first_name, P.last_name, E.hiring_date, E.id_address, E.id_manager FROM Projet_POO.Projet_POO_Livrable.Employees E JOIN Projet_POO_Livrable.People P on P.id_person = E.id_person";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd);
}

System::Data::DataTable^ SQLservices::SQL_getEmployee(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Employee WHERE id_person = @id";

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
    // this->SQLadapter->sendQuery(cmd3); TODO : Implement it at the end or else every addresses will be Deleted when testing
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