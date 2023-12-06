#include "SQLservices.h"

#include <crtdbg.h>

// Constructor
SQLservices::SQLservices()
{
 this->SQLadapter = gcnew SQLdatabaseAdapter;   
}
// ---------------------------------------------------------------------------------------------------------------------

// Person queries
System::Data::DataTable^ SQLservices::SQL_addPerson(System::String^ first_name, System::String^ last_name)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.People (first_name, last_name) OUTPUT inserted.id_person VALUES('@fname', '@lname')";

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
    System::String^ cmdString = "SELECT Customers.id_person, P.first_name, P.last_name, Customers.birth_date, Customers.first_order_date FROM Projet_POO.Projet_POO_Livrable.Customers JOIN Projet_POO_Livrable.People P on P.id_person = Customers.id_person";
    
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
    System::String^ cmdString = "SELECT id_order, order_reference, total_amount, order_discount_percentage, order_date, delivery_date FROM Projet_POO_Livrable.Orders WHERE id_customer = @param";

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
    System::String^ cmdString1 = "DELETE FROM Projet_POO_Livrable.has_billing_address WHERE id_customer = @id)";
    System::String^ cmdString2 = "DELETE FROM Projet_POO_Livrable.has_delivery_address WHERE id_customer = @id)";
    System::String^ cmdString3 = "DELETE FROM Projet_POO_Livrable.Addresses WHERE id_address IN (SELECT A.id_address FROM Projet_POO_Livrable.Addresses A LEFT JOIN Projet_POO_Livrable.has_billing_address B ON A.id_address = B.id_address LEFT JOIN Projet_POO_Livrable.has_delivery_address D ON A.id_address = D.id_address WHERE B.id_address IS NULL AND D.id_address IS NULL)";

    System::Data::SqlClient::SqlCommand^ cmd1 = gcnew System::Data::SqlClient::SqlCommand(cmdString1);
    System::Data::SqlClient::SqlCommand^ cmd2 = gcnew System::Data::SqlClient::SqlCommand(cmdString2);
    System::Data::SqlClient::SqlCommand^ cmd3 = gcnew System::Data::SqlClient::SqlCommand(cmdString3);


    cmd1->Parameters->AddWithValue("@id", id);

    this->SQLadapter->sendQuery(cmd1);
    this->SQLadapter->sendQuery(cmd2);
    // this->SQLadapter->sendQuery(cmd3, "Address"); TODO : Implement it at the end or else every addresses will be Deleted when testing
}


// ---------------------------------------------------------------------------------------------------------------------

// Employee Queries
System::Data::DataTable^ SQLservices::SQL_getEmployeeList()
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Employees";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd);
}
// ---------------------------------------------------------------------------------------------------------------------
