#pragma once

#include "SQL/SQLservices.h"

ref class Payment
{
private:
    int id_payment;
    System::DateTime payment_date;
    System::String^ payment_method;
    float amount;
    int id_order;
    SQLservices^ SQLserv = gcnew SQLservices;

public:
    Payment(int id);
    Payment(System::DateTime, System::String^, float, int);

    // Getters and setters
    int getID();
    System::DateTime getPaymentDate();
    void setPaymentDate(System::DateTime date);
    System::String^ getPaymentMethod();
    void setPaymentMethod(System::String^ method);
    double getAmount();
    void setAmount(float);
    int getOrderID();
    void setOrderID(int);

    // Database interaction methods
    void createPaymentInDB();
    void fetchPaymentFromDB();
    void modifyPaymentInDB();
    void deletePaymentFromDB();
};
