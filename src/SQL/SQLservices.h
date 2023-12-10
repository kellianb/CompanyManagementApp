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
    System::Data::DataTable^ SQL_addOrder(System::DateTime, System::DateTime, float, int id_delivery_address, int id_billing_address, int id_customer);

    System::Data::DataTable^ SQL_getOrder(int id);

    System::Data::DataTable^ SQL_getOrderList();
    
    System::Data::DataTable^ SQLservices::SQL_getOrderBillingAdress(int id);

    System::Data::DataTable^ SQLservices::SQL_getOrderDeliveryAdress(int id);

    System::Data::DataTable^ SQL_modifyOrder(int, System::DateTime, System::DateTime, float, int, int, int);

    void SQL_removeAllProductsFromOrder(int);
    
    void SQL_deleteOrder(int);

    System::Data::DataTable^ SQL_getProductsInOrderList(int);

    int SQL_getOrderFromPayment(int);
    
    // Inventory Queries
    System::Data::DataTable^ SQL_addProduct(System::String^, int, int, float);

    System::Data::DataTable^ SQL_getProduct(int idProduct);

    System::Data::DataTable^ SQL_getProductList();

    System::Data::DataTable^ SQL_modifyProduct(int id, System::String^, int amount, int reorder, float);

    System::Data::DataTable^ SQL_getAvailableColors(int, int);

    void SQL_deleteProduct(int id);

    // Product_price Queries
    System::Data::DataTable^ SQL_addProductPrice(int, int, float, System::DateTime, int, int, int);

    System::Data::DataTable^ SQL_getProductPrice(int);

    System::Data::DataTable^ SQL_getProductPricesListForProduct(int);

    System::Data::DataTable^ SQL_getProductPriceList();

    System::Data::DataTable^ SQL_modifyProductPrice(int, int, float, System::DateTime, int, int, int);

    void SQL_deleteProductPrice(int);
    
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

    System::Data::DataTable^ SQL_addBillingAddressesToCustomer(int, int );

    System::Data::DataTable^ SQL_addDeliveryAddressesToCustomer(int, int);

    System::Data::DataTable^ SQL_deleteBillingAddressesFromCustomer(int, int);

    System::Data::DataTable^ SQL_deleteDeliveryAddressesFromCustomer(int, int);
    
    System::Data::DataTable^ SQL_getCustomerBillingAddresses(int);
    
    System::Data::DataTable^ SQL_getCustomerDeliveryAddresses(int);

    
    // Employee Queries
    void SQL_addEmployee(int, System::DateTime, int);

    System::Data::DataTable^ SQL_getEmployeeList();

    System::Data::DataTable^ SQL_getEmployee(int);
    
    void SQL_modifyEmployee(int, System::DateTime);

    void SQL_deleteEmployee(int);

    void SQL_deleteEmployeeAddresses(int);

    void SQL_setEmployeeManager(int, int);

    void SQL_removeEmployeeManager(int);

    void SQL_removeEmployeeAsManager(int);

    
    // Statistics Queries
    System::Data::DataTable^ SQL_calculateAverageBasketSize();

    System::Data::DataTable^ SQL_calculateMonthlyTurnover(int month);

    System::Data::DataTable^ SQL_identifyProductsBelowThreshold();

    System::Data::DataTable^ SQL_calculateTotalPurchasesByCustomer();

    System::Data::DataTable^ SQL_identifyTop10BestSellingItems();

    System::Data::DataTable^ SQL_identifyTop10LeastSellingItems();

    System::Data::DataTable^ SQL_calculateCommercialStockValue();

    System::Data::DataTable^ SQL_calculatePurchaseStockValue();

    System::Data::DataTable^ SQL_simulateStockValueVariation(double, double, double, double);

    // Address Queries
    System::Data::DataTable^ SQL_addAddress(System::String^, System::String^, int postal_code, int street_number);

    System::Data::DataTable^ SQL_getAddress(int id);

    System::Data::DataTable^ SQL_getAddressList();

    System::Data::DataTable^ SQL_modifyAddress(int id, System::String^, System::String^, int postal_code, int street_number);

    void SQL_deleteAddress(int id);

    // Payment Queries
    System::Data::DataTable^ SQL_addPayment(System::DateTime, System::String^, double, int);

    System::Data::DataTable^ SQL_getPayment(int id);

    System::Data::DataTable^ SQL_getPaymentList();

    System::Data::DataTable^ SQL_modifyPayment(int id, System::DateTime, System::String^, double, int);

    void SQL_deletePayment(int id);
    
};