#include "Employee.h"
#include "SQL/SQLservices.h"

void Employee::create_employee_in_DB()
{
    this->SQLserv.SQL_addEmployee(this->id, this->hire_date, this->id_address, this->id_manager);
}

void Employee::fetch_employee_from_DB()
{
    System::Data::DataTable^ buffer = this->SQLserv.SQL_getEmployee(this->id);

    this->hire_date = safe_cast<System::DateTime>(buffer->Rows[0]["hiring_date"]);
}

void Employee::modify_employee_in_DB()
{
    // TODO: This
}

void Employee::delete_employee_from_DB()
{
    // TODO: This
}

Employee::Employee(int id) : Person(id)
{
    this->fetch_employee_from_DB();
}

Employee::Employee(System::String^ first_name, System::String^ last_name, System::DateTime hire_date, int id_address) : Person(first_name, last_name), hire_date(hire_date), id_address(id_address)
{
    this->create_employee_in_DB();
}

Employee::Employee(System::String^ first_name, System::String^ last_name, System::DateTime hire_date, int id_address, int id_manager) : Person(first_name, last_name), hire_date(hire_date), id_address(id_address), id_manager(id_manager)
{
    this->create_employee_in_DB();
}

int Employee::getIDaddress()
{
    return this->id_address;
}

void Employee::setIDaddress(int id)
{
    this->id_address = id;
}

System::DateTime Employee::getHireDate()
{
    return this->hire_date;
}

void Employee::setHireDate(System::DateTime date)
{
    this->hire_date = date;
}

void Employee::modify_in_DB()
{
    this->modify_person_in_DB();
    this->modify_employee_in_DB();
}

void Employee::delete_in_DB()
{
    this->delete_employee_from_DB();
    this->delete_person_from_DB();
}
