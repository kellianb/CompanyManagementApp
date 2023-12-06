#include "SQLservices.h"


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
