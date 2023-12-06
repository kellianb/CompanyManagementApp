#include "Employee.h"

void Employee::create_employee_in_DB()
{
}

void Employee::fetch_employee_from_DB()
{
}

void Employee::modify_employee_in_DB()
{
}

void Employee::delete_employee_from_DB()
{
}

Employee::Employee(int id) : Person(id)
{
    this->fetch_employee_from_DB();
}

Employee::Employee(System::String^ first_name, System::String^ last_name, System::DateTime hire_date, int id_adress) : Person(first_name, last_name)
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
