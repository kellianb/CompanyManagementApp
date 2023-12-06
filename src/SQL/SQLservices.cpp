﻿#include "SQLservices.h"

#include <crtdbg.h>


SQLservices::SQLservices()
{
 this->SQLadapter = gcnew SQLdatabaseAdapter;   
}

System::Data::DataSet^ SQLservices::SQL_addPerson(System::String^ first_name, System::String^ last_name)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.People (first_name, last_name) OUTPUT inserted.id_person VALUES('@param1', '@param2')";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->Add("@param1", first_name);
    cmd->Parameters->Add("@param2", last_name);

    return this->SQLadapter->sendQuery(cmd, "addedPersonID");
}

System::Data::DataSet^ SQLservices::SQL_getPerson(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.People WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->Add(gcnew System::Data::SqlClient::SqlParameter("@param", System::Data::SqlDbType::Int));
    cmd->Parameters["@param"]->Value = id;

    return this->SQLadapter->sendQuery(cmd, "Person");
}

void SQLservices::SQL_deletePerson(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.People WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->Add("@param", id);

    this->SQLadapter->sendQuery(cmd, "Person");
}

System::Data::DataSet^ SQLservices::SQL_addCustomer(int id, System::DateTime^ birth_date)
{
    System::String^ cmdString = "INSERT INTO Projet_POO_Livrable.Customers (id_person, birth_date) OUTPUT inserted.id_person VALUES(@param1, @param2)";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->Add("@param1", id);
    cmd->Parameters->Add("@param2", birth_date->ToString("yyyy-MM-dd"));

    return this->SQLadapter->sendQuery(cmd, "addedCustomer");
}

System::Data::DataSet^ SQLservices::SQL_getCustomerList()
{
    System::String^ cmdString = "SELECT Customers.id_person AS ID, P.first_name, P.last_name, Customers.birth_date, Customers.first_order_date FROM Projet_POO.Projet_POO_Livrable.Customers JOIN Projet_POO_Livrable.People P on P.id_person = Customers.id_person";
    
    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    return this->SQLadapter->sendQuery(cmd, "Customers");
}

System::Data::DataSet^ SQLservices::SQL_getCustomer(int id)
{
    System::String^ cmdString = "SELECT * FROM Projet_POO_Livrable.Customers WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);
    
    cmd->Parameters->Add(gcnew System::Data::SqlClient::SqlParameter("@param", System::Data::SqlDbType::Int));
    cmd->Parameters["@param"]->Value = id;

    return this->SQLadapter->sendQuery(cmd, "Customer");
}

System::Data::DataSet^ SQLservices::SQL_updatePerson(int id, System::String^ new_first_name, System::String^ new_last_name)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.People SET first_name = @param1, last_name = @param2 WHERE id = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->Add("@param", id);
    cmd->Parameters->Add("@param1", new_first_name);
    cmd->Parameters->Add("@param2", new_last_name);

    return this->SQLadapter->sendQuery(cmd, "Person");
}

System::Data::DataSet^ SQLservices::SQL_updateCustomer(int id, System::DateTime^ new_birth_date)
{
    System::String^ cmdString = "UPDATE Projet_POO_Livrable.customers SET birth_date = @param1 WHERE id = @param2";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->Add("@param1", new_birth_date);
    cmd->Parameters->Add("@param2", id);

    return this->SQLadapter->sendQuery(cmd, "Customers");
}

void SQLservices::SQL_deleteCustomer(int id)
{
    System::String^ cmdString = "DELETE FROM Projet_POO_Livrable.Customers WHERE id_person = @param";

    System::Data::SqlClient::SqlCommand^ cmd = gcnew System::Data::SqlClient::SqlCommand(cmdString);

    cmd->Parameters->Add("@param", id);
    
    SQL_deletePerson(id);

    this->SQLadapter->sendQuery(cmd, "Person");
}
