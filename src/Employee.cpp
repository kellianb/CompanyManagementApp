#include "Employee.h"

Employee::Employee(int id) : Person(id) {
    fetch_employee_from_DB();
}


Employee::Employee(System::String^ firstName, System::String^ lastName, System::DateTime hireDate, int addressId) : Person(firstName, lastName), hire_date(hireDate), id_address(addressId) {
    create_employee_in_DB();
}

int Employee::getAddress()
{
    return id_address;
}

void Employee::setAddress(int id)
{
    id_address = id;
}

int Employee::getManager()
{
    return id_manager;
}
void Employee::setManager(int id_manager)
{
    this->id_manager = id_manager;
    this->SQLserv->SQL_setEmployeeManager(this->id, id_manager);
}

void Employee::removeManager()
{
    this->id_manager = -1;
    this->SQLserv->SQL_removeEmployeeManager(this->id);
}

System::DateTime Employee::getHireDate()
{
    return hire_date;
}

void Employee::setHireDate(System::DateTime date)
{
    hire_date = date; modify_in_DB();
}

void Employee::create_employee_in_DB() {
    SQLserv->SQL_addEmployee(this->id, hire_date, id_address);
}

void Employee::fetch_employee_from_DB() {
    System::Data::DataTable^ buffer = this->SQLserv->SQL_getEmployee(this->getID());

    // Assuming these columns exist in the returned DataTable
    this->hire_date = safe_cast<System::DateTime>(buffer->Rows[0]["hiring_date"]);
    this->id_address = safe_cast<int>(buffer->Rows[0]["id_address"]);

    // Handling nullable manager ID
    if (buffer->Rows[0]->IsNull("id_manager")) {
        this->id_manager = -1; // or any other default/indicator value
    }
    else {
        this->id_manager = safe_cast<int>(buffer->Rows[0]["id_manager"]);
    }
}


void Employee::modify_employee_in_DB() {
    SQLserv->SQL_modifyEmployee(this->getID(), hire_date);
    
}

void Employee::delete_employee_from_DB() {
    SQLserv->SQL_deleteEmployee(this->getID());
}

void Employee::modify_in_DB() {
    modify_person_in_DB();
    modify_employee_in_DB();
}

void Employee::delete_in_DB() {
    SQLserv->SQL_removeEmployeeAsManager(this->id);
    delete_employee_from_DB();
    delete_person_from_DB();
    SQLserv->SQL_deleteAddress(this->id_address);
}
