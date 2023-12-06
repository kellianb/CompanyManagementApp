#include "SQLdatabaseAdapter.h"


void SQLdatabaseAdapter::readSQLconnectionStringFromFile()
{
    System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("../../connectionString.txt");

    // Read the first line of the file
    this->SQLconnectionString = reader->ReadLine();

    // Close the StreamReader to release resources
    reader->Close();

}

System::Data::DataSet^ SQLdatabaseAdapter::sendQuery(System::Data::SqlClient::SqlCommand^ command, System::String^ dataTableName)
{
    // Add the connection to the command object
    command->Connection = this->connection;
    
    this->SQLdataBuffer->Clear();
    this->dataAdapter->SelectCommand = command;
    this->dataAdapter->Fill(this->SQLdataBuffer, dataTableName);

    //System::Console::WriteLine(this->SQLdataBuffer->Tables[0]->Rows[0]["first_name"]);
    
    return this->SQLdataBuffer;
}

SQLdatabaseAdapter::SQLdatabaseAdapter()
{
    readSQLconnectionStringFromFile();

    this->SQLdataBuffer = gcnew System::Data::DataSet;

    this->connection = gcnew System::Data::SqlClient::SqlConnection(this->SQLconnectionString);
    this->dataAdapter = gcnew System::Data::SqlClient::SqlDataAdapter();
}




