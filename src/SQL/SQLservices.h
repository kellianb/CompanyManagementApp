#pragma once

#include "SQLdatabaseAdapter.h"

// Contains the SQL commands for the different DB operations and sends them to the SQLdatabaseAdapter  with the correct parameters
ref class SQLservices
{
private:
    SQLdatabaseAdapter^ SQLadapter;
    
public:
    // Constructor
    SQLservices();

    
    // Orders Queries
    System::Data::DataTable^ SQL_addOrder(System::DateTime, System::DateTime, System::Decimal, System::Decimal, int id_delivery_address, int id_billing_address, int id_customer);

    System::Data::DataTable^ SQL_getOrder(int id);

    System::Data::DataTable^ SQL_getOrderList();

    System::Data::DataTable^ SQL_modifyOrder(int id_order, System::DateTime, System::DateTime, System::Decimal, System::Decimal, int id_delivery_address, int id_billing_address, int id_customer);

    void SQL_deleteOrder(int id);
    
    
    // Inventory Queries
    System::Data::DataTable^ SQL_addProduct(System::String^, int amount, int reorder);

    System::Data::DataTable^ SQL_getProduct(int id);

    System::Data::DataTable^ SQL_getProductList();

    System::Data::DataTable^ SQL_modifyProduct(int id, System::String^, int amount, int reorder);

    void SQL_deleteProduct(int id);
    
    
    // Person Queries
    System::Data::DataTable^ SQL_addPerson(System::String^, System::String^);

    System::Data::DataTable^ SQL_getPerson(int id);

    System::Data::DataTable^ SQL_modifyPerson(int id, System::String^, System::String^);

    void SQL_deletePerson(int id);

    
    // Customer Queries
    System::Data::DataTable^ SQL_addCustomer(int, System::DateTime);
    
    System::Data::DataTable^ SQL_getCustomerList();
    
    System::Data::DataTable^ SQL_getCustomer(int id);
    
    System::Data::DataTable^ SQL_modifyCustomer(int id, System::DateTime);

    void SQL_deleteCustomer(int id);

    System::Data::DataTable^ SQL_getCustomerOrders(int id);

    void SQL_deleteCustomerOrders(int id);

    void SQL_deleteCustomerAddresses(int id);

    System::Data::DataTable^ SQL_getCustomerBillingAddresses(int id);
    
    System::Data::DataTable^ SQL_getCustomerDeliveryAddresses(int id);

    
    // Employee Queries
    System::Data::DataTable^ SQL_addEmployee(int id_person, System::DateTime, int id_address, int id_manager);

    System::Data::DataTable^ SQL_getEmployeeList();

    System::Data::DataTable^ SQL_getEmployee(int id);
    
    System::Data::DataTable^ SQL_modifyEmployee(int id_person, System::DateTime, int id_address, int id_manager);

    void SQL_deleteEmployee(int id);

    void SQL_deleteEmployeeAddresses(int id);

    // Statistics Queries
    System::Data::DataTable^ SQL_calculateAverageBasketSize();

    System::Data::DataTable^ SQL_calculateMonthlyTurnover(System::DateTime month);

    System::Data::DataTable^ SQL_identifyProductsBelowThreshold();

    System::Data::DataTable^ SQL_calculateTotalPurchasesByCustomer(int customerId);

    System::Data::DataTable^ SQL_identifyTop10BestSellingItems();

    System::Data::DataTable^ SQL_identifyTop10LeastSellingItems();

    System::Data::DataTable^ SQL_calculateCommercialStockValue();

    System::Data::DataTable^ SQL_calculatePurchaseStockValue();

    System::Data::DataTable^ SQL_simulateStockValueVariations(array<System::String^>^ modifications);
};
