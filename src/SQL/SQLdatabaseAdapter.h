#pragma once

ref class SQLdatabaseAdapter
{
private:
    System::String^ SQLconnectionString;

    void readSQLconnectionStringFromFile();

    System::Data::SqlClient::SqlConnection^ connection;
    System::Data::SqlClient::SqlDataAdapter^ dataAdapter;
    
    System::Data::DataSet^ SQLdataBuffer;

    
public:
    SQLdatabaseAdapter();

    System::Data::DataTable^ sendQuery(System::Data::SqlClient::SqlCommand^);
};
