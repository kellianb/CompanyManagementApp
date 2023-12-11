#include "Payments.h"

Payment::Payment(int id) : id_payment(id) {
    fetchPaymentFromDB();
}

Payment::Payment(System::DateTime date, System::String^ payment_method, float amount, int id_order) : payment_date(date), payment_method(payment_method), amount(amount), id_order(id_order) {
    createPaymentInDB();
}

int Payment::getID() {
    return id_payment;
}

void Payment::createPaymentInDB()
{
    this->SQLserv->SQL_addPayment(this->payment_date, this->payment_method, this->amount, this->id_order);
}

void Payment::fetchPaymentFromDB()
{
    System::Data::DataTable^ buffer = this->SQLserv->SQL_getPayment(this->id_payment);

    this->payment_date = safe_cast<System::DateTime>(buffer->Rows[0]["payment_date"]);
    this->payment_method = safe_cast<System::String^>(buffer->Rows[0]["payment_method"]);
    this->amount = System::Convert::ToDouble(buffer->Rows[0]["amount"]);
    this->id_order = safe_cast<int>(buffer->Rows[0]["id_order"]);
}

void Payment::modifyPaymentInDB()
{
    this->SQLserv->SQL_modifyPayment(this->id_payment, this->payment_date, this->payment_method, this->amount);
}

void Payment::deletePaymentFromDB()
{
    this->SQLserv->SQL_deletePayment(this->id_payment);
}

System::DateTime Payment::getPaymentDate()
{
    return this->payment_date;
}

void Payment::setPaymentDate(System::DateTime date)
{
    this->payment_date = date;
}

System::String^ Payment::getPaymentMethod()
{
    return this->payment_method;
}

void Payment::setPaymentMethod(System::String^ method)
{
    this->payment_method = method;
}

double Payment::getAmount()
{
    return this->amount;
}

void Payment::setAmount(float amount)
{
    this->amount = amount;
}

int Payment::getOrderID()
{
    return this->id_order;
}

void Payment::setOrderID(int id_order)
{
    this->id_order = id_order;
}