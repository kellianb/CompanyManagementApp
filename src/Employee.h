﻿#pragma once
#include "Person.h"

ref class Employee : Person {
private:
    int id_address;
    int id_manager;
    System::DateTime hire_date;

    void create_employee_in_DB();
    void fetch_employee_from_DB();
    void modify_employee_in_DB();
    void delete_employee_from_DB();

public:
    Employee(int);
    Employee(System::String^, System::String^, System::DateTime, int);

    int getAddress();
    void setAddress(int);
    int getManager();
    void setManager(int);
    void removeManager();

    System::DateTime getHireDate();
    void setHireDate(System::DateTime);

    void modify_in_DB() override;
    void delete_in_DB() override;
};
