#pragma once

#include "SQL/SQLservices.h"

ref class Payment
{
private:
    int id_payment;
    System::DateTime payment_date;
    System::String^ payment_method;
    double amount;
    int id_order;
    SQLservices^ SQLserv = gcnew SQLservices;

public:
    Payment(int id);
    Payment(System::DateTime date, System::String^ method, double amt, int orderId);

    // Getters and setters
    int getID();
    System::DateTime getPaymentDate();
    void setPaymentDate(System::DateTime date);
    System::String^ getPaymentMethod();
    void setPaymentMethod(System::String^ method);
    double getAmount();
    void setAmount(double amt);
    int getOrderID();
    void setOrderID(int orderId);

    // Database interaction methods
    void createPaymentInDB();
    void fetchPaymentFromDB();
    void modifyPaymentInDB();
    void deletePaymentFromDB();
};
