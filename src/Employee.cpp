#include "Employee.h"

Employee::Employee(int id) : Person(id) {
    fetch_employee_from_DB();
}

Employee::Employee(System::String^ firstName, System::String^ lastName, System::DateTime hireDate, int addressId) 
    : Person(firstName, lastName), hire_date(hireDate), id_address(addressId) {
    create_employee_in_DB();
}

Employee::Employee(System::String^ firstName, System::String^ lastName, System::DateTime hireDate, int addressId, int managerId) 
    : Person(firstName, lastName), hire_date(hireDate), id_address(addressId), id_manager(managerId) {
    create_employee_in_DB();
}

int Employee::getIDaddress() { return id_address; }
void Employee::setIDaddress(int id) { id_address = id; modify_in_DB(); }

int Employee::getIDmanager() { return id_manager; }
void Employee::setIDmanager(int id) { id_manager = id; modify_in_DB(); }

void Employee::setIDmanagernullable(Object^ nullableId) { 
    id_manager = nullableId != nullptr ? safe_cast<int>(nullableId) : -1; 
    modify_in_DB(); 
}

System::DateTime Employee::getHireDate() { return hire_date; }
void Employee::setHireDate(System::DateTime date) { hire_date = date; modify_in_DB(); }

void Employee::create_employee_in_DB() {
    SQLserv.SQL_addEmployee(this->getID(), hire_date, id_address, id_manager);
}

void Employee::fetch_employee_from_DB() {
    System::Data::DataTable^ buffer = this->SQLserv.SQL_getEmployee(this->getID());

    // Assuming these columns exist in the returned DataTable
    this->hire_date = safe_cast<System::DateTime>(buffer->Rows[0]["hiring_date"]);
    this->id_address = safe_cast<int>(buffer->Rows[0]["id_address"]);

    // Handling nullable manager ID
    if (buffer->Rows[0]->IsNull("id_manager")) {
        this->id_manager = -1; // or any other default/indicator value
    } else {
        this->id_manager = safe_cast<int>(buffer->Rows[0]["id_manager"]);
    }
}


void Employee::modify_employee_in_DB() {
    Object^ dbManagerId;
    if (this->id_manager == -1) {
        dbManagerId = System::DBNull::Value;
    } else {
        dbManagerId = this->id_manager;
    }

    SQLserv.SQL_modifyEmployee(this->getID(), hire_date, id_address, dbManagerId);
}

void Employee::delete_employee_from_DB() {
    SQLserv.SQL_deleteEmployee(this->getID());
}

void Employee::modify_in_DB() {
    modify_person_in_DB();
    modify_employee_in_DB();
}

void Employee::delete_in_DB() {
    delete_person_from_DB();
    delete_employee_from_DB();
}
