﻿#include "SQLservices.h"

#include <crtdbg.h>

// Constructor
SQLservices::SQLservices()
{
 this->SQLadapter = gcnew SQLdatabaseAdapter;   
}
// ---------------------------------------------------------------------------------------------------------------------

// Person queries
System::Data::DataSet^ SQLservices::SQL_addPerson(System::String^ first_name, System::String^ last_name)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.People (first_name, last_name) OUTPUT inserted.id_person VALUES('@param1', '@param2')";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@param1", first_name);
    cmd->Parameters->AddWithValue("@param2", last_name);

    return this->SQLadapter->sendQuery(cmd, "addedPersonID");
}

System::Data::DataSet^ SQLservices::SQL_getPerson(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.People WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@param", id);

    return this->SQLadapter->sendQuery(cmd, "Person");
}

System::Data::DataSet^ SQLservices::SQL_modifyPerson(int id, System::String^ new_first_name, System::String^ new_last_name)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.People SET first_name = @param1, last_name = @param2 WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@param", id);
    cmd->Parameters->AddWithValue("@param1", new_first_name);
    cmd->Parameters->AddWithValue("@param2", new_last_name);

    return this->SQLadapter->sendQuery(cmd, "Person");
}

void SQLservices::SQL_deletePerson(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.People WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@param", id);

    this->SQLadapter->sendQuery(cmd, "Person");
}
// ---------------------------------------------------------------------------------------------------------------------

// Customer queries
System::Data::DataSet^ SQLservices::SQL_addCustomer(int id, System::DateTime birth_date)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Customers (id_person, birth_date) OUTPUT inserted.id_person VALUES(@param1, @param2)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@param1", id);
    cmd->Parameters->AddWithValue("@param2", birth_date);

    return this->SQLadapter->sendQuery(cmd, "addedCustomer");
}

System::Data::DataSet^ SQLservices::SQL_getCustomerList()
{
    System::String^ cmdString = "SELECT Customers.id_person, P.first_name, P.last_name, Customers.birth_date, Customers.first_order_date FROM Projet_POO.Projet_POO_Livrable.Customers JOIN Projet_POO_Livrable.People P on P.id_person = Customers.id_person";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd, "Customers");
}

System::Data::DataSet^ SQLservices::SQL_getCustomer(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Customers WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->AddWithValue("@param", id);

    return this->SQLadapter->sendQuery(cmd, "Customer");
}



System::Data::DataSet^ SQLservices::SQL_modifyCustomer(int id, System::DateTime new_birth_date)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.customers SET birth_date = @param1 WHERE id_person = @param2";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@param1", new_birth_date);
    cmd->Parameters->AddWithValue("@param2", id);

    return this->SQLadapter->sendQuery(cmd, "Customers");
}

void SQLservices::SQL_deleteCustomer(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Customers WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@param", id);

    SQL_deleteCustomerOrders(id);

    this->SQLadapter->sendQuery(cmd, "Customer");
}

System::Data::DataSet^ SQLservices::SQL_getCustomerOrders(int id)
{
    System::String^ cmdString = "SELECT O.id_order, delivery_date, order_date, order_discount_percentage, total_amount FROM Projet_POO_Livrable.Orders O INNER JOIN Projet_POO_Livrable.Customers C ON O.id_customer = C.id_person WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@param", id);

    return this->SQLadapter->sendQuery(cmd, "Customer");
}

void SQLservices::SQL_deleteCustomerOrders(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Orders WHERE id_customer IN (SELECT id_person FROM Projet_POO_Livrable.Customers WHERE id_person = @param)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->AddWithValue("@param", id);

    this->SQLadapter->sendQuery(cmd, "Customer");
}



// ---------------------------------------------------------------------------------------------------------------------

// Employee Queries
System::Data::DataSet^ SQLservices::SQL_getEmployeeList()
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Employees";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd, "Employees");
}
// ---------------------------------------------------------------------------------------------------------------------