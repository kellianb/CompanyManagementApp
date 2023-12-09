#pragma once

#include "editAddressPrompt.h"
#include "../SQL/SQLservices.h"
#include "../Customer.h"
#include "createCustomerPrompt.h"
#include "selectEmployeeManager.h"
#include "createEmployeePrompt.h"
#include "editOrderPrompt.h"
#include "../Employee.h"
#include "../Address.h"
#include "../Order.h"


namespace Projet
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for UserInterface
    /// </summary>
    public ref class UserInterface : public System::Windows::Forms::Form
    {
    private:
        SQLservices^ SQLserver = gcnew SQLservices;
        Customer^ selected_customer;
        Employee^ selected_employee;
        Address^ selected_employee_address;

    private:
        System::Windows::Forms::TextBox^ textBox_last_name_customer;

    private:
        System::Windows::Forms::TextBox^ textBox_first_name_customer;

    private:
        System::Windows::Forms::GroupBox^ groupBox_customer_information;

    private:
        System::Windows::Forms::TextBox^ textBox_last_name_employee;

    private:
        System::Windows::Forms::TextBox^ textBox_first_name_employee;

    private:
        System::Windows::Forms::GroupBox^ groupBox_employee_information;
        
    private:
        System::Windows::Forms::Label^ label_last_name_customer;
        
    private:
        System::Windows::Forms::Label^ label_first_name_customer;

    private:
        System::Windows::Forms::Label^ label_last_name_employee;

    private:
        System::Windows::Forms::Label^ label_first_name_employee;

    private:
        System::Windows::Forms::Button^ button_delete_customer;

    private:
        System::Windows::Forms::Button^ button_delete_employee;

    private:
        System::Windows::Forms::Button^ button_modify_customer;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker_customer_birth_date;
    private: System::Windows::Forms::Button^ button_customers_reload;
    private: System::Windows::Forms::GroupBox^ groupBox_customer_orders;
    private: System::Windows::Forms::DataGridView^ dataGridView_customer_orders;

    private: System::Windows::Forms::Button^ button_create_customer;
    private: System::Windows::Forms::GroupBox^ groupBox_customer_billing_addresses;
    private: System::Windows::Forms::GroupBox^ groupBox_delivery_addresses;
    private: System::Windows::Forms::DataGridView^ dataGridView_customer_delivery_addresses;
    private: System::Windows::Forms::DataGridView^ dataGridView_customer_billing_addresses;
    private: System::Windows::Forms::Button^ button_customer_add_delivery_address;

    private: System::Windows::Forms::Button^ button_customer_add_billing_address;
    private: System::Windows::Forms::Button^ button_customer_delete_billing_address;


    private: System::Windows::Forms::Button^ button_customer_modify_billing_address;
    private: System::Windows::Forms::Button^ button_customer_delete_delivery_address;
    private: System::Windows::Forms::Button^ button_customer_modify_delivery_address;


    private: System::Windows::Forms::Button^ button_modify_employee;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker_employee_hiring_date;


    private: System::Windows::Forms::Label^ label_customer_birth_date;


    private: System::Windows::Forms::Label^ label_customers_current_order_billing_address;
    private: System::Windows::Forms::Label^ label_customers_current_order_delivery_address;
    private: System::Windows::Forms::GroupBox^ groupBox_employee_manager;



    private: System::Windows::Forms::Label^ label_employee_manager_name;
    private: System::Windows::Forms::Button^ button_employee_select_manager;
    private: System::Windows::Forms::Button^ button_employee_reload;
    private: System::Windows::Forms::Button^ button_create_employee;
    private: System::Windows::Forms::DataGridView^ dataGridView_Orders;
    private: System::Windows::Forms::DataGridView^ dataGridView_Inventory;
    private: System::Windows::Forms::GroupBox^ groupBox_general_stats;

    private: System::Windows::Forms::Label^ label_avg_basket;
    private: System::Windows::Forms::Label^ label_monthly_turnover;
    private: System::Windows::Forms::Label^ label_commercial_stock_value;
    private: System::Windows::Forms::Label^ label_purchase_stock_value;

    private: System::Windows::Forms::Label^ label_simulate_stock_value;
    private: System::Windows::Forms::Button^ button_customer_delete_order;
    private: System::Windows::Forms::Button^ button_customer_add_order;



    private: System::Windows::Forms::GroupBox^ groupBox_total_purchases_by_customers;

    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::GroupBox^ groupBox_product_below_threshold;

    private: System::Windows::Forms::DataGridView^ dataGridView2;
    private: System::Windows::Forms::GroupBox^ groupBox_worst_products;
    private: System::Windows::Forms::DataGridView^ dataGridView4;
    private: System::Windows::Forms::GroupBox^ groupBox_bestsellers;
    private: System::Windows::Forms::DataGridView^ dataGridView3;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox_fname_statistics;
    private: System::Windows::Forms::TextBox^ textBox_lname_statistics;


    private: System::Windows::Forms::Button^ button_search_customer;

    private: System::Windows::Forms::GroupBox^ groupBox_order_information;
    private: System::Windows::Forms::Label^ label_order_date;

    private: System::Windows::Forms::DateTimePicker^ dateTimePicker_order_date;

    private: System::Windows::Forms::Button^ button_order_delete;

    private: System::Windows::Forms::Button^ button_order_modify;



    private: System::Windows::Forms::Label^ label_discount_percentage;
    private: System::Windows::Forms::TextBox^ textBox_discount_percentage;


    private: System::Windows::Forms::Label^ label_delivery_date;

    private: System::Windows::Forms::DateTimePicker^ dateTimePicker_delivery_date;

    private: System::Windows::Forms::GroupBox^ groupBox_product_information;

    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ button10;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label_product_name;
    private: System::Windows::Forms::TextBox^ textBox_product_name;
    private: System::Windows::Forms::TextBox^ textBox_product_amount;
    private: System::Windows::Forms::Label^ label_reorder_threshold;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::GroupBox^ groupBox_customer_currently_selected_order;

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::GroupBox^ groupBox_employee_address;
    private: System::Windows::Forms::Button^ button_employee_modify_address;



    private: System::Windows::Forms::Label^ label_employee_address_street_number;


    private: System::Windows::Forms::Label^ label_employee_address_postal_code;
    private: System::Windows::Forms::Label^ label_employee_address_street;



    private: System::Windows::Forms::Label^ label_employee_address_city;

    private: System::Windows::Forms::TextBox^ textBox_employee_address_city;
    private: System::Windows::Forms::TextBox^ textBox_employee_address_street;
    private: System::Windows::Forms::TextBox^ textBox_employee_address_street_number;



    private: System::Windows::Forms::TextBox^ textBox_employee_address_postal_code;
    private: System::Windows::Forms::Button^ button_employee_remove_manager;

    private: System::Windows::Forms::Label^ label_employee_hiring_date;

    public:
        UserInterface(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~UserInterface()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TabControl^ tabController;

    protected:

    protected:

    protected:

    private:
        System::Windows::Forms::TabPage^ tab_customers;

    private:
        System::Windows::Forms::TabPage^ tab_orders;

    protected:

    protected:


    private:
        System::Windows::Forms::TabPage^ tab_inventory;

    private:
        System::Windows::Forms::TabPage^ tab_employee;

    private:
        System::Windows::Forms::DataGridView^ dataGridView_employee;

    private:
        System::Windows::Forms::TabPage^ tab_statistics;

    private:
        System::Windows::Forms::DataGridView^ dataGridView_customers;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->tabController = (gcnew System::Windows::Forms::TabControl());
            this->tab_orders = (gcnew System::Windows::Forms::TabPage());
            this->groupBox_order_information = (gcnew System::Windows::Forms::GroupBox());
            this->label_delivery_date = (gcnew System::Windows::Forms::Label());
            this->dateTimePicker_delivery_date = (gcnew System::Windows::Forms::DateTimePicker());
            this->button_order_modify = (gcnew System::Windows::Forms::Button());
            this->button_order_delete = (gcnew System::Windows::Forms::Button());
            this->label_order_date = (gcnew System::Windows::Forms::Label());
            this->dateTimePicker_order_date = (gcnew System::Windows::Forms::DateTimePicker());
            this->label_discount_percentage = (gcnew System::Windows::Forms::Label());
            this->textBox_discount_percentage = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView_Orders = (gcnew System::Windows::Forms::DataGridView());
            this->tab_inventory = (gcnew System::Windows::Forms::TabPage());
            this->groupBox_product_information = (gcnew System::Windows::Forms::GroupBox());
            this->label_reorder_threshold = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button10 = (gcnew System::Windows::Forms::Button());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label_product_name = (gcnew System::Windows::Forms::Label());
            this->textBox_product_name = (gcnew System::Windows::Forms::TextBox());
            this->textBox_product_amount = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView_Inventory = (gcnew System::Windows::Forms::DataGridView());
            this->tab_customers = (gcnew System::Windows::Forms::TabPage());
            this->button_create_customer = (gcnew System::Windows::Forms::Button());
            this->groupBox_delivery_addresses = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView_customer_delivery_addresses = (gcnew System::Windows::Forms::DataGridView());
            this->button_customer_delete_delivery_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_add_delivery_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_modify_delivery_address = (gcnew System::Windows::Forms::Button());
            this->groupBox_customer_billing_addresses = (gcnew System::Windows::Forms::GroupBox());
            this->button_customer_delete_billing_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_modify_billing_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_add_billing_address = (gcnew System::Windows::Forms::Button());
            this->dataGridView_customer_billing_addresses = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_customer_orders = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox_customer_currently_selected_order = (gcnew System::Windows::Forms::GroupBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button_customer_delete_order = (gcnew System::Windows::Forms::Button());
            this->label_customers_current_order_billing_address = (gcnew System::Windows::Forms::Label());
            this->label_customers_current_order_delivery_address = (gcnew System::Windows::Forms::Label());
            this->button_customer_add_order = (gcnew System::Windows::Forms::Button());
            this->dataGridView_customer_orders = (gcnew System::Windows::Forms::DataGridView());
            this->button_customers_reload = (gcnew System::Windows::Forms::Button());
            this->groupBox_customer_information = (gcnew System::Windows::Forms::GroupBox());
            this->label_customer_birth_date = (gcnew System::Windows::Forms::Label());
            this->dateTimePicker_customer_birth_date = (gcnew System::Windows::Forms::DateTimePicker());
            this->button_delete_customer = (gcnew System::Windows::Forms::Button());
            this->button_modify_customer = (gcnew System::Windows::Forms::Button());
            this->label_last_name_customer = (gcnew System::Windows::Forms::Label());
            this->label_first_name_customer = (gcnew System::Windows::Forms::Label());
            this->textBox_first_name_customer = (gcnew System::Windows::Forms::TextBox());
            this->textBox_last_name_customer = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView_customers = (gcnew System::Windows::Forms::DataGridView());
            this->tab_employee = (gcnew System::Windows::Forms::TabPage());
            this->groupBox_employee_address = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_employee_address_street_number = (gcnew System::Windows::Forms::TextBox());
            this->textBox_employee_address_postal_code = (gcnew System::Windows::Forms::TextBox());
            this->button_employee_modify_address = (gcnew System::Windows::Forms::Button());
            this->label_employee_address_street_number = (gcnew System::Windows::Forms::Label());
            this->label_employee_address_postal_code = (gcnew System::Windows::Forms::Label());
            this->label_employee_address_street = (gcnew System::Windows::Forms::Label());
            this->label_employee_address_city = (gcnew System::Windows::Forms::Label());
            this->textBox_employee_address_city = (gcnew System::Windows::Forms::TextBox());
            this->textBox_employee_address_street = (gcnew System::Windows::Forms::TextBox());
            this->button_employee_reload = (gcnew System::Windows::Forms::Button());
            this->button_create_employee = (gcnew System::Windows::Forms::Button());
            this->groupBox_employee_manager = (gcnew System::Windows::Forms::GroupBox());
            this->button_employee_remove_manager = (gcnew System::Windows::Forms::Button());
            this->button_employee_select_manager = (gcnew System::Windows::Forms::Button());
            this->label_employee_manager_name = (gcnew System::Windows::Forms::Label());
            this->dataGridView_employee = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_employee_information = (gcnew System::Windows::Forms::GroupBox());
            this->button_delete_employee = (gcnew System::Windows::Forms::Button());
            this->button_modify_employee = (gcnew System::Windows::Forms::Button());
            this->label_employee_hiring_date = (gcnew System::Windows::Forms::Label());
            this->dateTimePicker_employee_hiring_date = (gcnew System::Windows::Forms::DateTimePicker());
            this->label_last_name_employee = (gcnew System::Windows::Forms::Label());
            this->label_first_name_employee = (gcnew System::Windows::Forms::Label());
            this->textBox_first_name_employee = (gcnew System::Windows::Forms::TextBox());
            this->textBox_last_name_employee = (gcnew System::Windows::Forms::TextBox());
            this->tab_statistics = (gcnew System::Windows::Forms::TabPage());
            this->groupBox_worst_products = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_bestsellers = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_product_below_threshold = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_total_purchases_by_customers = (gcnew System::Windows::Forms::GroupBox());
            this->button_search_customer = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox_fname_statistics = (gcnew System::Windows::Forms::TextBox());
            this->textBox_lname_statistics = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_general_stats = (gcnew System::Windows::Forms::GroupBox());
            this->label_simulate_stock_value = (gcnew System::Windows::Forms::Label());
            this->label_purchase_stock_value = (gcnew System::Windows::Forms::Label());
            this->label_commercial_stock_value = (gcnew System::Windows::Forms::Label());
            this->label_monthly_turnover = (gcnew System::Windows::Forms::Label());
            this->label_avg_basket = (gcnew System::Windows::Forms::Label());
            this->tabController->SuspendLayout();
            this->tab_orders->SuspendLayout();
            this->groupBox_order_information->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Orders))->BeginInit();
            this->tab_inventory->SuspendLayout();
            this->groupBox_product_information->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Inventory))->BeginInit();
            this->tab_customers->SuspendLayout();
            this->groupBox_delivery_addresses->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_delivery_addresses))->BeginInit();
            this->groupBox_customer_billing_addresses->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_billing_addresses))->BeginInit();
            this->groupBox_customer_orders->SuspendLayout();
            this->groupBox_customer_currently_selected_order->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_orders))->BeginInit();
            this->groupBox_customer_information->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customers))->BeginInit();
            this->tab_employee->SuspendLayout();
            this->groupBox_employee_address->SuspendLayout();
            this->groupBox_employee_manager->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_employee))->BeginInit();
            this->groupBox_employee_information->SuspendLayout();
            this->tab_statistics->SuspendLayout();
            this->groupBox_worst_products->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
            this->groupBox_bestsellers->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
            this->groupBox_product_below_threshold->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
            this->groupBox_total_purchases_by_customers->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->groupBox_general_stats->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabController
            // 
            this->tabController->Controls->Add(this->tab_orders);
            this->tabController->Controls->Add(this->tab_inventory);
            this->tabController->Controls->Add(this->tab_customers);
            this->tabController->Controls->Add(this->tab_employee);
            this->tabController->Controls->Add(this->tab_statistics);
            this->tabController->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabController->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tabController->Location = System::Drawing::Point(0, 0);
            this->tabController->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tabController->Name = L"tabController";
            this->tabController->SelectedIndex = 0;
            this->tabController->Size = System::Drawing::Size(1258, 751);
            this->tabController->TabIndex = 0;
            this->tabController->SelectedIndexChanged += gcnew System::EventHandler(this, &UserInterface::OnTabSelectedIndexChanged);
            // 
            // tab_orders
            // 
            this->tab_orders->Controls->Add(this->groupBox_order_information);
            this->tab_orders->Controls->Add(this->dataGridView_Orders);
            this->tab_orders->Location = System::Drawing::Point(4, 29);
            this->tab_orders->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_orders->Name = L"tab_orders";
            this->tab_orders->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_orders->Size = System::Drawing::Size(1250, 718);
            this->tab_orders->TabIndex = 1;
            this->tab_orders->Text = L"Orders";
            this->tab_orders->UseVisualStyleBackColor = true;
            // 
            // groupBox_order_information
            // 
            this->groupBox_order_information->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox_order_information->Controls->Add(this->label_delivery_date);
            this->groupBox_order_information->Controls->Add(this->dateTimePicker_delivery_date);
            this->groupBox_order_information->Controls->Add(this->button_order_modify);
            this->groupBox_order_information->Controls->Add(this->button_order_delete);
            this->groupBox_order_information->Controls->Add(this->label_order_date);
            this->groupBox_order_information->Controls->Add(this->dateTimePicker_order_date);
            this->groupBox_order_information->Controls->Add(this->label_discount_percentage);
            this->groupBox_order_information->Controls->Add(this->textBox_discount_percentage);
            this->groupBox_order_information->Location = System::Drawing::Point(8, 201);
            this->groupBox_order_information->Name = L"groupBox_order_information";
            this->groupBox_order_information->Size = System::Drawing::Size(543, 166);
            this->groupBox_order_information->TabIndex = 9;
            this->groupBox_order_information->TabStop = false;
            this->groupBox_order_information->Text = L"Order Information";
            // 
            // label_delivery_date
            // 
            this->label_delivery_date->AutoSize = true;
            this->label_delivery_date->Location = System::Drawing::Point(309, 22);
            this->label_delivery_date->Name = L"label_delivery_date";
            this->label_delivery_date->Size = System::Drawing::Size(107, 20);
            this->label_delivery_date->TabIndex = 10;
            this->label_delivery_date->Text = L"Delivery date";
            // 
            // dateTimePicker_delivery_date
            // 
            this->dateTimePicker_delivery_date->Location = System::Drawing::Point(313, 45);
            this->dateTimePicker_delivery_date->Name = L"dateTimePicker_delivery_date";
            this->dateTimePicker_delivery_date->Size = System::Drawing::Size(197, 26);
            this->dateTimePicker_delivery_date->TabIndex = 9;
            // 
            // button_order_modify
            // 
            this->button_order_modify->Location = System::Drawing::Point(313, 116);
            this->button_order_modify->Name = L"button_order_modify";
            this->button_order_modify->Size = System::Drawing::Size(88, 30);
            this->button_order_modify->TabIndex = 5;
            this->button_order_modify->Text = L"Modify";
            this->button_order_modify->UseVisualStyleBackColor = true;
            // 
            // button_order_delete
            // 
            this->button_order_delete->Location = System::Drawing::Point(422, 118);
            this->button_order_delete->Name = L"button_order_delete";
            this->button_order_delete->Size = System::Drawing::Size(88, 30);
            this->button_order_delete->TabIndex = 6;
            this->button_order_delete->Text = L"Delete";
            this->button_order_delete->UseVisualStyleBackColor = true;
            // 
            // label_order_date
            // 
            this->label_order_date->AutoSize = true;
            this->label_order_date->Location = System::Drawing::Point(24, 22);
            this->label_order_date->Name = L"label_order_date";
            this->label_order_date->Size = System::Drawing::Size(89, 20);
            this->label_order_date->TabIndex = 8;
            this->label_order_date->Text = L"Order date";
            // 
            // dateTimePicker_order_date
            // 
            this->dateTimePicker_order_date->Location = System::Drawing::Point(28, 45);
            this->dateTimePicker_order_date->Name = L"dateTimePicker_order_date";
            this->dateTimePicker_order_date->Size = System::Drawing::Size(197, 26);
            this->dateTimePicker_order_date->TabIndex = 7;
            // 
            // label_discount_percentage
            // 
            this->label_discount_percentage->AutoSize = true;
            this->label_discount_percentage->Location = System::Drawing::Point(24, 97);
            this->label_discount_percentage->Name = L"label_discount_percentage";
            this->label_discount_percentage->Size = System::Drawing::Size(120, 20);
            this->label_discount_percentage->TabIndex = 3;
            this->label_discount_percentage->Text = L"Order discount";
            // 
            // textBox_discount_percentage
            // 
            this->textBox_discount_percentage->Location = System::Drawing::Point(28, 120);
            this->textBox_discount_percentage->Name = L"textBox_discount_percentage";
            this->textBox_discount_percentage->Size = System::Drawing::Size(197, 26);
            this->textBox_discount_percentage->TabIndex = 1;
            // 
            // dataGridView_Orders
            // 
            this->dataGridView_Orders->AllowUserToAddRows = false;
            this->dataGridView_Orders->AllowUserToDeleteRows = false;
            this->dataGridView_Orders->AllowUserToOrderColumns = true;
            this->dataGridView_Orders->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_Orders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_Orders->Location = System::Drawing::Point(6, 7);
            this->dataGridView_Orders->MinimumSize = System::Drawing::Size(999, 112);
            this->dataGridView_Orders->MultiSelect = false;
            this->dataGridView_Orders->Name = L"dataGridView_Orders";
            this->dataGridView_Orders->ReadOnly = true;
            this->dataGridView_Orders->RowHeadersWidth = 62;
            this->dataGridView_Orders->RowTemplate->Height = 28;
            this->dataGridView_Orders->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_Orders->Size = System::Drawing::Size(1236, 188);
            this->dataGridView_Orders->TabIndex = 1;
            // 
            // tab_inventory
            // 
            this->tab_inventory->Controls->Add(this->groupBox_product_information);
            this->tab_inventory->Controls->Add(this->dataGridView_Inventory);
            this->tab_inventory->Location = System::Drawing::Point(4, 29);
            this->tab_inventory->Name = L"tab_inventory";
            this->tab_inventory->Padding = System::Windows::Forms::Padding(3);
            this->tab_inventory->Size = System::Drawing::Size(1250, 718);
            this->tab_inventory->TabIndex = 2;
            this->tab_inventory->Text = L"Inventory";
            this->tab_inventory->UseVisualStyleBackColor = true;
            // 
            // groupBox_product_information
            // 
            this->groupBox_product_information->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox_product_information->Controls->Add(this->label_reorder_threshold);
            this->groupBox_product_information->Controls->Add(this->textBox1);
            this->groupBox_product_information->Controls->Add(this->button9);
            this->groupBox_product_information->Controls->Add(this->button10);
            this->groupBox_product_information->Controls->Add(this->label7);
            this->groupBox_product_information->Controls->Add(this->label_product_name);
            this->groupBox_product_information->Controls->Add(this->textBox_product_name);
            this->groupBox_product_information->Controls->Add(this->textBox_product_amount);
            this->groupBox_product_information->Location = System::Drawing::Point(8, 200);
            this->groupBox_product_information->Name = L"groupBox_product_information";
            this->groupBox_product_information->Size = System::Drawing::Size(543, 181);
            this->groupBox_product_information->TabIndex = 13;
            this->groupBox_product_information->TabStop = false;
            this->groupBox_product_information->Text = L"Product Information";
            // 
            // label_reorder_threshold
            // 
            this->label_reorder_threshold->AutoSize = true;
            this->label_reorder_threshold->Location = System::Drawing::Point(283, 30);
            this->label_reorder_threshold->Name = L"label_reorder_threshold";
            this->label_reorder_threshold->Size = System::Drawing::Size(143, 20);
            this->label_reorder_threshold->TabIndex = 8;
            this->label_reorder_threshold->Text = L"Reorder threshold";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(287, 53);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(240, 26);
            this->textBox1->TabIndex = 7;
            // 
            // button9
            // 
            this->button9->Location = System::Drawing::Point(439, 97);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(88, 30);
            this->button9->TabIndex = 6;
            this->button9->Text = L"Delete";
            this->button9->UseVisualStyleBackColor = true;
            // 
            // button10
            // 
            this->button10->Location = System::Drawing::Point(287, 97);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(88, 30);
            this->button10->TabIndex = 5;
            this->button10->Text = L"Modify";
            this->button10->UseVisualStyleBackColor = true;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(24, 99);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(127, 20);
            this->label7->TabIndex = 4;
            this->label7->Text = L"Product amount";
            // 
            // label_product_name
            // 
            this->label_product_name->AutoSize = true;
            this->label_product_name->Location = System::Drawing::Point(24, 30);
            this->label_product_name->Name = L"label_product_name";
            this->label_product_name->Size = System::Drawing::Size(113, 20);
            this->label_product_name->TabIndex = 3;
            this->label_product_name->Text = L"Product name";
            // 
            // textBox_product_name
            // 
            this->textBox_product_name->Location = System::Drawing::Point(28, 53);
            this->textBox_product_name->Name = L"textBox_product_name";
            this->textBox_product_name->Size = System::Drawing::Size(240, 26);
            this->textBox_product_name->TabIndex = 1;
            // 
            // textBox_product_amount
            // 
            this->textBox_product_amount->Location = System::Drawing::Point(28, 118);
            this->textBox_product_amount->Name = L"textBox_product_amount";
            this->textBox_product_amount->Size = System::Drawing::Size(240, 26);
            this->textBox_product_amount->TabIndex = 2;
            // 
            // dataGridView_Inventory
            // 
            this->dataGridView_Inventory->AllowUserToAddRows = false;
            this->dataGridView_Inventory->AllowUserToDeleteRows = false;
            this->dataGridView_Inventory->AllowUserToOrderColumns = true;
            this->dataGridView_Inventory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_Inventory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_Inventory->Location = System::Drawing::Point(6, 6);
            this->dataGridView_Inventory->MinimumSize = System::Drawing::Size(999, 112);
            this->dataGridView_Inventory->MultiSelect = false;
            this->dataGridView_Inventory->Name = L"dataGridView_Inventory";
            this->dataGridView_Inventory->ReadOnly = true;
            this->dataGridView_Inventory->RowHeadersWidth = 62;
            this->dataGridView_Inventory->RowTemplate->Height = 28;
            this->dataGridView_Inventory->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_Inventory->Size = System::Drawing::Size(1236, 188);
            this->dataGridView_Inventory->TabIndex = 1;
            // 
            // tab_customers
            // 
            this->tab_customers->Controls->Add(this->button_create_customer);
            this->tab_customers->Controls->Add(this->groupBox_delivery_addresses);
            this->tab_customers->Controls->Add(this->groupBox_customer_billing_addresses);
            this->tab_customers->Controls->Add(this->groupBox_customer_orders);
            this->tab_customers->Controls->Add(this->button_customers_reload);
            this->tab_customers->Controls->Add(this->groupBox_customer_information);
            this->tab_customers->Controls->Add(this->dataGridView_customers);
            this->tab_customers->Location = System::Drawing::Point(4, 29);
            this->tab_customers->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Name = L"tab_customers";
            this->tab_customers->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Size = System::Drawing::Size(1250, 718);
            this->tab_customers->TabIndex = 0;
            this->tab_customers->Text = L"Customers";
            this->tab_customers->UseVisualStyleBackColor = true;
            // 
            // button_create_customer
            // 
            this->button_create_customer->Location = System::Drawing::Point(907, 152);
            this->button_create_customer->Name = L"button_create_customer";
            this->button_create_customer->Size = System::Drawing::Size(195, 37);
            this->button_create_customer->TabIndex = 9;
            this->button_create_customer->Text = L"Create a customer";
            this->button_create_customer->UseVisualStyleBackColor = true;
            this->button_create_customer->Click += gcnew System::EventHandler(this, &UserInterface::button_create_customer_Click);
            // 
            // groupBox_delivery_addresses
            // 
            this->groupBox_delivery_addresses->Controls->Add(this->dataGridView_customer_delivery_addresses);
            this->groupBox_delivery_addresses->Controls->Add(this->button_customer_delete_delivery_address);
            this->groupBox_delivery_addresses->Controls->Add(this->button_customer_add_delivery_address);
            this->groupBox_delivery_addresses->Controls->Add(this->button_customer_modify_delivery_address);
            this->groupBox_delivery_addresses->Location = System::Drawing::Point(8, 374);
            this->groupBox_delivery_addresses->Name = L"groupBox_delivery_addresses";
            this->groupBox_delivery_addresses->Size = System::Drawing::Size(543, 169);
            this->groupBox_delivery_addresses->TabIndex = 8;
            this->groupBox_delivery_addresses->TabStop = false;
            this->groupBox_delivery_addresses->Text = L"Delivery addresses";
            // 
            // dataGridView_customer_delivery_addresses
            // 
            this->dataGridView_customer_delivery_addresses->AllowUserToAddRows = false;
            this->dataGridView_customer_delivery_addresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_delivery_addresses->Location = System::Drawing::Point(6, 21);
            this->dataGridView_customer_delivery_addresses->MultiSelect = false;
            this->dataGridView_customer_delivery_addresses->Name = L"dataGridView_customer_delivery_addresses";
            this->dataGridView_customer_delivery_addresses->ReadOnly = true;
            this->dataGridView_customer_delivery_addresses->RowHeadersWidth = 62;
            this->dataGridView_customer_delivery_addresses->RowTemplate->Height = 28;
            this->dataGridView_customer_delivery_addresses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_delivery_addresses->Size = System::Drawing::Size(531, 99);
            this->dataGridView_customer_delivery_addresses->TabIndex = 1;
            // 
            // button_customer_delete_delivery_address
            // 
            this->button_customer_delete_delivery_address->Location = System::Drawing::Point(220, 126);
            this->button_customer_delete_delivery_address->Name = L"button_customer_delete_delivery_address";
            this->button_customer_delete_delivery_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_delete_delivery_address->TabIndex = 6;
            this->button_customer_delete_delivery_address->Text = L"Delete";
            this->button_customer_delete_delivery_address->UseVisualStyleBackColor = true;
            this->button_customer_delete_delivery_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_delete_delivery_address_Click);
            // 
            // button_customer_add_delivery_address
            // 
            this->button_customer_add_delivery_address->Location = System::Drawing::Point(6, 126);
            this->button_customer_add_delivery_address->Name = L"button_customer_add_delivery_address";
            this->button_customer_add_delivery_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_add_delivery_address->TabIndex = 3;
            this->button_customer_add_delivery_address->Text = L"Add";
            this->button_customer_add_delivery_address->UseVisualStyleBackColor = true;
            this->button_customer_add_delivery_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_add_delivery_address_Click);
            // 
            // button_customer_modify_delivery_address
            // 
            this->button_customer_modify_delivery_address->Location = System::Drawing::Point(113, 126);
            this->button_customer_modify_delivery_address->Name = L"button_customer_modify_delivery_address";
            this->button_customer_modify_delivery_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_modify_delivery_address->TabIndex = 5;
            this->button_customer_modify_delivery_address->Text = L"Modify";
            this->button_customer_modify_delivery_address->UseVisualStyleBackColor = true;
            this->button_customer_modify_delivery_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_modify_delivery_address_Click);
            // 
            // groupBox_customer_billing_addresses
            // 
            this->groupBox_customer_billing_addresses->Controls->Add(this->button_customer_delete_billing_address);
            this->groupBox_customer_billing_addresses->Controls->Add(this->button_customer_modify_billing_address);
            this->groupBox_customer_billing_addresses->Controls->Add(this->button_customer_add_billing_address);
            this->groupBox_customer_billing_addresses->Controls->Add(this->dataGridView_customer_billing_addresses);
            this->groupBox_customer_billing_addresses->Location = System::Drawing::Point(8, 549);
            this->groupBox_customer_billing_addresses->Name = L"groupBox_customer_billing_addresses";
            this->groupBox_customer_billing_addresses->Size = System::Drawing::Size(543, 169);
            this->groupBox_customer_billing_addresses->TabIndex = 7;
            this->groupBox_customer_billing_addresses->TabStop = false;
            this->groupBox_customer_billing_addresses->Text = L"Billing addresses";
            // 
            // button_customer_delete_billing_address
            // 
            this->button_customer_delete_billing_address->Location = System::Drawing::Point(220, 126);
            this->button_customer_delete_billing_address->Name = L"button_customer_delete_billing_address";
            this->button_customer_delete_billing_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_delete_billing_address->TabIndex = 4;
            this->button_customer_delete_billing_address->Text = L"Delete";
            this->button_customer_delete_billing_address->UseVisualStyleBackColor = true;
            this->button_customer_delete_billing_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_delete_billing_address_Click);
            // 
            // button_customer_modify_billing_address
            // 
            this->button_customer_modify_billing_address->Location = System::Drawing::Point(113, 126);
            this->button_customer_modify_billing_address->Name = L"button_customer_modify_billing_address";
            this->button_customer_modify_billing_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_modify_billing_address->TabIndex = 3;
            this->button_customer_modify_billing_address->Text = L"Modify";
            this->button_customer_modify_billing_address->UseVisualStyleBackColor = true;
            this->button_customer_modify_billing_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_modify_billing_address_Click);
            // 
            // button_customer_add_billing_address
            // 
            this->button_customer_add_billing_address->Location = System::Drawing::Point(6, 126);
            this->button_customer_add_billing_address->Name = L"button_customer_add_billing_address";
            this->button_customer_add_billing_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_add_billing_address->TabIndex = 2;
            this->button_customer_add_billing_address->Text = L"Add";
            this->button_customer_add_billing_address->UseVisualStyleBackColor = true;
            this->button_customer_add_billing_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_add_billing_address_Click);
            // 
            // dataGridView_customer_billing_addresses
            // 
            this->dataGridView_customer_billing_addresses->AllowUserToAddRows = false;
            this->dataGridView_customer_billing_addresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_billing_addresses->Location = System::Drawing::Point(6, 21);
            this->dataGridView_customer_billing_addresses->MultiSelect = false;
            this->dataGridView_customer_billing_addresses->Name = L"dataGridView_customer_billing_addresses";
            this->dataGridView_customer_billing_addresses->ReadOnly = true;
            this->dataGridView_customer_billing_addresses->RowHeadersWidth = 62;
            this->dataGridView_customer_billing_addresses->RowTemplate->Height = 28;
            this->dataGridView_customer_billing_addresses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_billing_addresses->Size = System::Drawing::Size(531, 99);
            this->dataGridView_customer_billing_addresses->TabIndex = 1;
            // 
            // groupBox_customer_orders
            // 
            this->groupBox_customer_orders->Controls->Add(this->groupBox_customer_currently_selected_order);
            this->groupBox_customer_orders->Controls->Add(this->button_customer_add_order);
            this->groupBox_customer_orders->Controls->Add(this->dataGridView_customer_orders);
            this->groupBox_customer_orders->Location = System::Drawing::Point(561, 201);
            this->groupBox_customer_orders->Name = L"groupBox_customer_orders";
            this->groupBox_customer_orders->Size = System::Drawing::Size(679, 517);
            this->groupBox_customer_orders->TabIndex = 5;
            this->groupBox_customer_orders->TabStop = false;
            this->groupBox_customer_orders->Text = L"Customer Orders";
            // 
            // groupBox_customer_currently_selected_order
            // 
            this->groupBox_customer_currently_selected_order->Controls->Add(this->button1);
            this->groupBox_customer_currently_selected_order->Controls->Add(this->button_customer_delete_order);
            this->groupBox_customer_currently_selected_order->Controls->Add(this->label_customers_current_order_billing_address);
            this->groupBox_customer_currently_selected_order->Controls->Add(this->label_customers_current_order_delivery_address);
            this->groupBox_customer_currently_selected_order->Location = System::Drawing::Point(11, 348);
            this->groupBox_customer_currently_selected_order->Name = L"groupBox_customer_currently_selected_order";
            this->groupBox_customer_currently_selected_order->Size = System::Drawing::Size(656, 156);
            this->groupBox_customer_currently_selected_order->TabIndex = 10;
            this->groupBox_customer_currently_selected_order->TabStop = false;
            this->groupBox_customer_currently_selected_order->Text = L"Order";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(6, 120);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(88, 30);
            this->button1->TabIndex = 5;
            this->button1->Text = L"Modify";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_modify_order);
            // 
            // button_customer_delete_order
            // 
            this->button_customer_delete_order->Location = System::Drawing::Point(100, 120);
            this->button_customer_delete_order->Name = L"button_customer_delete_order";
            this->button_customer_delete_order->Size = System::Drawing::Size(88, 30);
            this->button_customer_delete_order->TabIndex = 9;
            this->button_customer_delete_order->Text = L"Delete";
            this->button_customer_delete_order->UseVisualStyleBackColor = true;
            this->button_customer_delete_order->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_delete_order_Click);
            // 
            // label_customers_current_order_billing_address
            // 
            this->label_customers_current_order_billing_address->AutoSize = true;
            this->label_customers_current_order_billing_address->Location = System::Drawing::Point(24, 30);
            this->label_customers_current_order_billing_address->Name = L"label_customers_current_order_billing_address";
            this->label_customers_current_order_billing_address->Size = System::Drawing::Size(19, 20);
            this->label_customers_current_order_billing_address->TabIndex = 2;
            this->label_customers_current_order_billing_address->Text = L" f";
            // 
            // label_customers_current_order_delivery_address
            // 
            this->label_customers_current_order_delivery_address->AutoSize = true;
            this->label_customers_current_order_delivery_address->Location = System::Drawing::Point(24, 79);
            this->label_customers_current_order_delivery_address->Name = L"label_customers_current_order_delivery_address";
            this->label_customers_current_order_delivery_address->Size = System::Drawing::Size(19, 20);
            this->label_customers_current_order_delivery_address->TabIndex = 1;
            this->label_customers_current_order_delivery_address->Text = L" f";
            // 
            // button_customer_add_order
            // 
            this->button_customer_add_order->Location = System::Drawing::Point(561, 298);
            this->button_customer_add_order->Name = L"button_customer_add_order";
            this->button_customer_add_order->Size = System::Drawing::Size(88, 37);
            this->button_customer_add_order->TabIndex = 7;
            this->button_customer_add_order->Text = L"Create";
            this->button_customer_add_order->UseVisualStyleBackColor = true;
            this->button_customer_add_order->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_add_order_Click);
            // 
            // dataGridView_customer_orders
            // 
            this->dataGridView_customer_orders->AllowUserToAddRows = false;
            this->dataGridView_customer_orders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_orders->Location = System::Drawing::Point(6, 21);
            this->dataGridView_customer_orders->MultiSelect = false;
            this->dataGridView_customer_orders->Name = L"dataGridView_customer_orders";
            this->dataGridView_customer_orders->ReadOnly = true;
            this->dataGridView_customer_orders->RowHeadersWidth = 62;
            this->dataGridView_customer_orders->RowTemplate->Height = 28;
            this->dataGridView_customer_orders->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_orders->Size = System::Drawing::Size(667, 321);
            this->dataGridView_customer_orders->TabIndex = 0;
            this->dataGridView_customer_orders->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_customer_orders_selectionChanged);
            // 
            // button_customers_reload
            // 
            this->button_customers_reload->Location = System::Drawing::Point(1122, 152);
            this->button_customers_reload->Name = L"button_customers_reload";
            this->button_customers_reload->Size = System::Drawing::Size(100, 37);
            this->button_customers_reload->TabIndex = 4;
            this->button_customers_reload->Text = L"Reload";
            this->button_customers_reload->UseVisualStyleBackColor = true;
            this->button_customers_reload->Click += gcnew System::EventHandler(this, &UserInterface::button_customers_reload_click);
            // 
            // groupBox_customer_information
            // 
            this->groupBox_customer_information->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox_customer_information->Controls->Add(this->label_customer_birth_date);
            this->groupBox_customer_information->Controls->Add(this->dateTimePicker_customer_birth_date);
            this->groupBox_customer_information->Controls->Add(this->button_delete_customer);
            this->groupBox_customer_information->Controls->Add(this->button_modify_customer);
            this->groupBox_customer_information->Controls->Add(this->label_last_name_customer);
            this->groupBox_customer_information->Controls->Add(this->label_first_name_customer);
            this->groupBox_customer_information->Controls->Add(this->textBox_first_name_customer);
            this->groupBox_customer_information->Controls->Add(this->textBox_last_name_customer);
            this->groupBox_customer_information->Location = System::Drawing::Point(8, 201);
            this->groupBox_customer_information->Name = L"groupBox_customer_information";
            this->groupBox_customer_information->Size = System::Drawing::Size(543, 166);
            this->groupBox_customer_information->TabIndex = 3;
            this->groupBox_customer_information->TabStop = false;
            this->groupBox_customer_information->Text = L"Customer Information";
            // 
            // label_customer_birth_date
            // 
            this->label_customer_birth_date->AutoSize = true;
            this->label_customer_birth_date->Location = System::Drawing::Point(312, 30);
            this->label_customer_birth_date->Name = L"label_customer_birth_date";
            this->label_customer_birth_date->Size = System::Drawing::Size(82, 20);
            this->label_customer_birth_date->TabIndex = 8;
            this->label_customer_birth_date->Text = L"Birth date";
            // 
            // dateTimePicker_customer_birth_date
            // 
            this->dateTimePicker_customer_birth_date->Location = System::Drawing::Point(316, 53);
            this->dateTimePicker_customer_birth_date->Name = L"dateTimePicker_customer_birth_date";
            this->dateTimePicker_customer_birth_date->Size = System::Drawing::Size(197, 26);
            this->dateTimePicker_customer_birth_date->TabIndex = 7;
            // 
            // button_delete_customer
            // 
            this->button_delete_customer->Location = System::Drawing::Point(425, 120);
            this->button_delete_customer->Name = L"button_delete_customer";
            this->button_delete_customer->Size = System::Drawing::Size(88, 30);
            this->button_delete_customer->TabIndex = 6;
            this->button_delete_customer->Text = L"Delete";
            this->button_delete_customer->UseVisualStyleBackColor = true;
            this->button_delete_customer->Click += gcnew System::EventHandler(this, &UserInterface::button_delete_customer_Click);
            // 
            // button_modify_customer
            // 
            this->button_modify_customer->Location = System::Drawing::Point(316, 120);
            this->button_modify_customer->Name = L"button_modify_customer";
            this->button_modify_customer->Size = System::Drawing::Size(88, 30);
            this->button_modify_customer->TabIndex = 5;
            this->button_modify_customer->Text = L"Modify";
            this->button_modify_customer->UseVisualStyleBackColor = true;
            this->button_modify_customer->Click += gcnew System::EventHandler(this, &UserInterface::button_modify_customer_Click);
            // 
            // label_last_name_customer
            // 
            this->label_last_name_customer->AutoSize = true;
            this->label_last_name_customer->Location = System::Drawing::Point(24, 101);
            this->label_last_name_customer->Name = L"label_last_name_customer";
            this->label_last_name_customer->Size = System::Drawing::Size(91, 20);
            this->label_last_name_customer->TabIndex = 4;
            this->label_last_name_customer->Text = L"Last Name";
            // 
            // label_first_name_customer
            // 
            this->label_first_name_customer->AutoSize = true;
            this->label_first_name_customer->Location = System::Drawing::Point(24, 30);
            this->label_first_name_customer->Name = L"label_first_name_customer";
            this->label_first_name_customer->Size = System::Drawing::Size(92, 20);
            this->label_first_name_customer->TabIndex = 3;
            this->label_first_name_customer->Text = L"First Name";
            // 
            // textBox_first_name_customer
            // 
            this->textBox_first_name_customer->Location = System::Drawing::Point(28, 53);
            this->textBox_first_name_customer->Name = L"textBox_first_name_customer";
            this->textBox_first_name_customer->Size = System::Drawing::Size(240, 26);
            this->textBox_first_name_customer->TabIndex = 1;
            // 
            // textBox_last_name_customer
            // 
            this->textBox_last_name_customer->Location = System::Drawing::Point(28, 124);
            this->textBox_last_name_customer->Name = L"textBox_last_name_customer";
            this->textBox_last_name_customer->Size = System::Drawing::Size(240, 26);
            this->textBox_last_name_customer->TabIndex = 2;
            // 
            // dataGridView_customers
            // 
            this->dataGridView_customers->AllowUserToAddRows = false;
            this->dataGridView_customers->AllowUserToDeleteRows = false;
            this->dataGridView_customers->AllowUserToOrderColumns = true;
            this->dataGridView_customers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_customers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customers->Location = System::Drawing::Point(8, 7);
            this->dataGridView_customers->MinimumSize = System::Drawing::Size(999, 112);
            this->dataGridView_customers->MultiSelect = false;
            this->dataGridView_customers->Name = L"dataGridView_customers";
            this->dataGridView_customers->ReadOnly = true;
            this->dataGridView_customers->RowHeadersWidth = 62;
            this->dataGridView_customers->RowTemplate->Height = 28;
            this->dataGridView_customers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customers->Size = System::Drawing::Size(1236, 188);
            this->dataGridView_customers->TabIndex = 0;
            this->dataGridView_customers->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_customers_selectionChanged);
            // 
            // tab_employee
            // 
            this->tab_employee->Controls->Add(this->groupBox_employee_address);
            this->tab_employee->Controls->Add(this->button_employee_reload);
            this->tab_employee->Controls->Add(this->button_create_employee);
            this->tab_employee->Controls->Add(this->groupBox_employee_manager);
            this->tab_employee->Controls->Add(this->dataGridView_employee);
            this->tab_employee->Controls->Add(this->groupBox_employee_information);
            this->tab_employee->Location = System::Drawing::Point(4, 29);
            this->tab_employee->Name = L"tab_employee";
            this->tab_employee->Padding = System::Windows::Forms::Padding(3);
            this->tab_employee->Size = System::Drawing::Size(1250, 718);
            this->tab_employee->TabIndex = 3;
            this->tab_employee->Text = L"Employees";
            this->tab_employee->UseVisualStyleBackColor = true;
            // 
            // groupBox_employee_address
            // 
            this->groupBox_employee_address->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox_employee_address->Controls->Add(this->textBox_employee_address_street_number);
            this->groupBox_employee_address->Controls->Add(this->textBox_employee_address_postal_code);
            this->groupBox_employee_address->Controls->Add(this->button_employee_modify_address);
            this->groupBox_employee_address->Controls->Add(this->label_employee_address_street_number);
            this->groupBox_employee_address->Controls->Add(this->label_employee_address_postal_code);
            this->groupBox_employee_address->Controls->Add(this->label_employee_address_street);
            this->groupBox_employee_address->Controls->Add(this->label_employee_address_city);
            this->groupBox_employee_address->Controls->Add(this->textBox_employee_address_city);
            this->groupBox_employee_address->Controls->Add(this->textBox_employee_address_street);
            this->groupBox_employee_address->Location = System::Drawing::Point(8, 373);
            this->groupBox_employee_address->Name = L"groupBox_employee_address";
            this->groupBox_employee_address->Size = System::Drawing::Size(543, 205);
            this->groupBox_employee_address->TabIndex = 11;
            this->groupBox_employee_address->TabStop = false;
            this->groupBox_employee_address->Text = L"Employee Address";
            // 
            // textBox_employee_address_street_number
            // 
            this->textBox_employee_address_street_number->Location = System::Drawing::Point(316, 123);
            this->textBox_employee_address_street_number->Name = L"textBox_employee_address_street_number";
            this->textBox_employee_address_street_number->Size = System::Drawing::Size(198, 26);
            this->textBox_employee_address_street_number->TabIndex = 11;
            // 
            // textBox_employee_address_postal_code
            // 
            this->textBox_employee_address_postal_code->Location = System::Drawing::Point(315, 53);
            this->textBox_employee_address_postal_code->Name = L"textBox_employee_address_postal_code";
            this->textBox_employee_address_postal_code->Size = System::Drawing::Size(198, 26);
            this->textBox_employee_address_postal_code->TabIndex = 10;
            // 
            // button_employee_modify_address
            // 
            this->button_employee_modify_address->Location = System::Drawing::Point(425, 165);
            this->button_employee_modify_address->Name = L"button_employee_modify_address";
            this->button_employee_modify_address->Size = System::Drawing::Size(88, 30);
            this->button_employee_modify_address->TabIndex = 5;
            this->button_employee_modify_address->Text = L"Modify";
            this->button_employee_modify_address->UseVisualStyleBackColor = true;
            this->button_employee_modify_address->Click += gcnew System::EventHandler(this, &UserInterface::button_employee_modify_address_Click);
            // 
            // label_employee_address_street_number
            // 
            this->label_employee_address_street_number->AutoSize = true;
            this->label_employee_address_street_number->Location = System::Drawing::Point(312, 101);
            this->label_employee_address_street_number->Name = L"label_employee_address_street_number";
            this->label_employee_address_street_number->Size = System::Drawing::Size(118, 20);
            this->label_employee_address_street_number->TabIndex = 9;
            this->label_employee_address_street_number->Text = L"Street Number";
            // 
            // label_employee_address_postal_code
            // 
            this->label_employee_address_postal_code->AutoSize = true;
            this->label_employee_address_postal_code->Location = System::Drawing::Point(312, 30);
            this->label_employee_address_postal_code->Name = L"label_employee_address_postal_code";
            this->label_employee_address_postal_code->Size = System::Drawing::Size(97, 20);
            this->label_employee_address_postal_code->TabIndex = 8;
            this->label_employee_address_postal_code->Text = L"Postal code";
            // 
            // label_employee_address_street
            // 
            this->label_employee_address_street->AutoSize = true;
            this->label_employee_address_street->Location = System::Drawing::Point(24, 101);
            this->label_employee_address_street->Name = L"label_employee_address_street";
            this->label_employee_address_street->Size = System::Drawing::Size(54, 20);
            this->label_employee_address_street->TabIndex = 4;
            this->label_employee_address_street->Text = L"Street";
            // 
            // label_employee_address_city
            // 
            this->label_employee_address_city->AutoSize = true;
            this->label_employee_address_city->Location = System::Drawing::Point(24, 30);
            this->label_employee_address_city->Name = L"label_employee_address_city";
            this->label_employee_address_city->Size = System::Drawing::Size(38, 20);
            this->label_employee_address_city->TabIndex = 3;
            this->label_employee_address_city->Text = L"City";
            // 
            // textBox_employee_address_city
            // 
            this->textBox_employee_address_city->Location = System::Drawing::Point(28, 53);
            this->textBox_employee_address_city->Name = L"textBox_employee_address_city";
            this->textBox_employee_address_city->Size = System::Drawing::Size(240, 26);
            this->textBox_employee_address_city->TabIndex = 1;
            // 
            // textBox_employee_address_street
            // 
            this->textBox_employee_address_street->Location = System::Drawing::Point(28, 123);
            this->textBox_employee_address_street->Name = L"textBox_employee_address_street";
            this->textBox_employee_address_street->Size = System::Drawing::Size(240, 26);
            this->textBox_employee_address_street->TabIndex = 2;
            // 
            // button_employee_reload
            // 
            this->button_employee_reload->Location = System::Drawing::Point(1122, 152);
            this->button_employee_reload->Name = L"button_employee_reload";
            this->button_employee_reload->Size = System::Drawing::Size(100, 37);
            this->button_employee_reload->TabIndex = 11;
            this->button_employee_reload->Text = L"Reload";
            this->button_employee_reload->UseVisualStyleBackColor = true;
            this->button_employee_reload->Click += gcnew System::EventHandler(this, &UserInterface::button_employee_reload_Click);
            // 
            // button_create_employee
            // 
            this->button_create_employee->Location = System::Drawing::Point(907, 152);
            this->button_create_employee->Name = L"button_create_employee";
            this->button_create_employee->Size = System::Drawing::Size(195, 37);
            this->button_create_employee->TabIndex = 10;
            this->button_create_employee->Text = L"Create an employee";
            this->button_create_employee->UseVisualStyleBackColor = true;
            this->button_create_employee->Click += gcnew System::EventHandler(this, &UserInterface::button_create_employee_Click);
            // 
            // groupBox_employee_manager
            // 
            this->groupBox_employee_manager->Controls->Add(this->button_employee_remove_manager);
            this->groupBox_employee_manager->Controls->Add(this->button_employee_select_manager);
            this->groupBox_employee_manager->Controls->Add(this->label_employee_manager_name);
            this->groupBox_employee_manager->Location = System::Drawing::Point(561, 201);
            this->groupBox_employee_manager->Name = L"groupBox_employee_manager";
            this->groupBox_employee_manager->Size = System::Drawing::Size(687, 121);
            this->groupBox_employee_manager->TabIndex = 6;
            this->groupBox_employee_manager->TabStop = false;
            this->groupBox_employee_manager->Text = L"Employee Manager ";
            // 
            // button_employee_remove_manager
            // 
            this->button_employee_remove_manager->Location = System::Drawing::Point(109, 71);
            this->button_employee_remove_manager->Name = L"button_employee_remove_manager";
            this->button_employee_remove_manager->Size = System::Drawing::Size(80, 30);
            this->button_employee_remove_manager->TabIndex = 12;
            this->button_employee_remove_manager->Text = L"Remove";
            this->button_employee_remove_manager->UseVisualStyleBackColor = true;
            this->button_employee_remove_manager->Click += gcnew System::EventHandler(this, &UserInterface::button_employee_remove_manager_Click);
            // 
            // button_employee_select_manager
            // 
            this->button_employee_select_manager->Location = System::Drawing::Point(10, 71);
            this->button_employee_select_manager->Name = L"button_employee_select_manager";
            this->button_employee_select_manager->Size = System::Drawing::Size(80, 30);
            this->button_employee_select_manager->TabIndex = 11;
            this->button_employee_select_manager->Text = L"Select";
            this->button_employee_select_manager->UseVisualStyleBackColor = true;
            this->button_employee_select_manager->Click += gcnew System::EventHandler(this, &UserInterface::button_employee_select_manager_click);
            // 
            // label_employee_manager_name
            // 
            this->label_employee_manager_name->AutoSize = true;
            this->label_employee_manager_name->Location = System::Drawing::Point(6, 30);
            this->label_employee_manager_name->Name = L"label_employee_manager_name";
            this->label_employee_manager_name->Size = System::Drawing::Size(217, 20);
            this->label_employee_manager_name->TabIndex = 2;
            this->label_employee_manager_name->Text = L"If you see this, this is a bug.";
            // 
            // dataGridView_employee
            // 
            this->dataGridView_employee->AllowUserToAddRows = false;
            this->dataGridView_employee->AllowUserToDeleteRows = false;
            this->dataGridView_employee->AllowUserToOrderColumns = true;
            this->dataGridView_employee->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_employee->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_employee->Location = System::Drawing::Point(8, 7);
            this->dataGridView_employee->MinimumSize = System::Drawing::Size(999, 112);
            this->dataGridView_employee->MultiSelect = false;
            this->dataGridView_employee->Name = L"dataGridView_employee";
            this->dataGridView_employee->ReadOnly = true;
            this->dataGridView_employee->RowHeadersWidth = 62;
            this->dataGridView_employee->RowTemplate->Height = 28;
            this->dataGridView_employee->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_employee->Size = System::Drawing::Size(1236, 188);
            this->dataGridView_employee->TabIndex = 0;
            this->dataGridView_employee->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_employee_selectionChanged);
            // 
            // groupBox_employee_information
            // 
            this->groupBox_employee_information->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox_employee_information->Controls->Add(this->button_delete_employee);
            this->groupBox_employee_information->Controls->Add(this->button_modify_employee);
            this->groupBox_employee_information->Controls->Add(this->label_employee_hiring_date);
            this->groupBox_employee_information->Controls->Add(this->dateTimePicker_employee_hiring_date);
            this->groupBox_employee_information->Controls->Add(this->label_last_name_employee);
            this->groupBox_employee_information->Controls->Add(this->label_first_name_employee);
            this->groupBox_employee_information->Controls->Add(this->textBox_first_name_employee);
            this->groupBox_employee_information->Controls->Add(this->textBox_last_name_employee);
            this->groupBox_employee_information->Location = System::Drawing::Point(8, 201);
            this->groupBox_employee_information->Name = L"groupBox_employee_information";
            this->groupBox_employee_information->Size = System::Drawing::Size(543, 166);
            this->groupBox_employee_information->TabIndex = 3;
            this->groupBox_employee_information->TabStop = false;
            this->groupBox_employee_information->Text = L"Employee Information";
            // 
            // button_delete_employee
            // 
            this->button_delete_employee->Location = System::Drawing::Point(425, 120);
            this->button_delete_employee->Name = L"button_delete_employee";
            this->button_delete_employee->Size = System::Drawing::Size(88, 30);
            this->button_delete_employee->TabIndex = 6;
            this->button_delete_employee->Text = L"Delete";
            this->button_delete_employee->UseVisualStyleBackColor = true;
            this->button_delete_employee->Click += gcnew System::EventHandler(this, &UserInterface::button_delete_employee_Click);
            // 
            // button_modify_employee
            // 
            this->button_modify_employee->Location = System::Drawing::Point(316, 120);
            this->button_modify_employee->Name = L"button_modify_employee";
            this->button_modify_employee->Size = System::Drawing::Size(88, 30);
            this->button_modify_employee->TabIndex = 5;
            this->button_modify_employee->Text = L"Modify";
            this->button_modify_employee->UseVisualStyleBackColor = true;
            this->button_modify_employee->Click += gcnew System::EventHandler(this, &UserInterface::button_modify_employee_Click);
            // 
            // label_employee_hiring_date
            // 
            this->label_employee_hiring_date->AutoSize = true;
            this->label_employee_hiring_date->Location = System::Drawing::Point(312, 30);
            this->label_employee_hiring_date->Name = L"label_employee_hiring_date";
            this->label_employee_hiring_date->Size = System::Drawing::Size(91, 20);
            this->label_employee_hiring_date->TabIndex = 8;
            this->label_employee_hiring_date->Text = L"Hiring date";
            // 
            // dateTimePicker_employee_hiring_date
            // 
            this->dateTimePicker_employee_hiring_date->Location = System::Drawing::Point(316, 53);
            this->dateTimePicker_employee_hiring_date->Name = L"dateTimePicker_employee_hiring_date";
            this->dateTimePicker_employee_hiring_date->Size = System::Drawing::Size(197, 26);
            this->dateTimePicker_employee_hiring_date->TabIndex = 7;
            // 
            // label_last_name_employee
            // 
            this->label_last_name_employee->AutoSize = true;
            this->label_last_name_employee->Location = System::Drawing::Point(24, 101);
            this->label_last_name_employee->Name = L"label_last_name_employee";
            this->label_last_name_employee->Size = System::Drawing::Size(91, 20);
            this->label_last_name_employee->TabIndex = 4;
            this->label_last_name_employee->Text = L"Last Name";
            // 
            // label_first_name_employee
            // 
            this->label_first_name_employee->AutoSize = true;
            this->label_first_name_employee->Location = System::Drawing::Point(24, 30);
            this->label_first_name_employee->Name = L"label_first_name_employee";
            this->label_first_name_employee->Size = System::Drawing::Size(92, 20);
            this->label_first_name_employee->TabIndex = 3;
            this->label_first_name_employee->Text = L"First Name";
            // 
            // textBox_first_name_employee
            // 
            this->textBox_first_name_employee->Location = System::Drawing::Point(28, 53);
            this->textBox_first_name_employee->Name = L"textBox_first_name_employee";
            this->textBox_first_name_employee->Size = System::Drawing::Size(240, 26);
            this->textBox_first_name_employee->TabIndex = 1;
            // 
            // textBox_last_name_employee
            // 
            this->textBox_last_name_employee->Location = System::Drawing::Point(28, 124);
            this->textBox_last_name_employee->Name = L"textBox_last_name_employee";
            this->textBox_last_name_employee->Size = System::Drawing::Size(240, 26);
            this->textBox_last_name_employee->TabIndex = 2;
            // 
            // tab_statistics
            // 
            this->tab_statistics->Controls->Add(this->groupBox_worst_products);
            this->tab_statistics->Controls->Add(this->groupBox_bestsellers);
            this->tab_statistics->Controls->Add(this->groupBox_product_below_threshold);
            this->tab_statistics->Controls->Add(this->groupBox_total_purchases_by_customers);
            this->tab_statistics->Controls->Add(this->groupBox_general_stats);
            this->tab_statistics->Location = System::Drawing::Point(4, 29);
            this->tab_statistics->Name = L"tab_statistics";
            this->tab_statistics->Size = System::Drawing::Size(1250, 718);
            this->tab_statistics->TabIndex = 4;
            this->tab_statistics->Text = L"Statistics";
            this->tab_statistics->UseVisualStyleBackColor = true;
            // 
            // groupBox_worst_products
            // 
            this->groupBox_worst_products->Controls->Add(this->dataGridView4);
            this->groupBox_worst_products->Location = System::Drawing::Point(612, 351);
            this->groupBox_worst_products->Name = L"groupBox_worst_products";
            this->groupBox_worst_products->Size = System::Drawing::Size(632, 371);
            this->groupBox_worst_products->TabIndex = 12;
            this->groupBox_worst_products->TabStop = false;
            this->groupBox_worst_products->Text = L"Worst products";
            // 
            // dataGridView4
            // 
            this->dataGridView4->AllowUserToAddRows = false;
            this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView4->Location = System::Drawing::Point(6, 21);
            this->dataGridView4->MultiSelect = false;
            this->dataGridView4->Name = L"dataGridView4";
            this->dataGridView4->RowHeadersWidth = 62;
            this->dataGridView4->RowTemplate->Height = 28;
            this->dataGridView4->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView4->Size = System::Drawing::Size(620, 344);
            this->dataGridView4->TabIndex = 1;
            // 
            // groupBox_bestsellers
            // 
            this->groupBox_bestsellers->Controls->Add(this->dataGridView3);
            this->groupBox_bestsellers->Location = System::Drawing::Point(8, 351);
            this->groupBox_bestsellers->Name = L"groupBox_bestsellers";
            this->groupBox_bestsellers->Size = System::Drawing::Size(598, 371);
            this->groupBox_bestsellers->TabIndex = 11;
            this->groupBox_bestsellers->TabStop = false;
            this->groupBox_bestsellers->Text = L"Bestsellers";
            // 
            // dataGridView3
            // 
            this->dataGridView3->AllowUserToAddRows = false;
            this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView3->Location = System::Drawing::Point(6, 21);
            this->dataGridView3->MultiSelect = false;
            this->dataGridView3->Name = L"dataGridView3";
            this->dataGridView3->RowHeadersWidth = 62;
            this->dataGridView3->RowTemplate->Height = 28;
            this->dataGridView3->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView3->Size = System::Drawing::Size(586, 344);
            this->dataGridView3->TabIndex = 1;
            // 
            // groupBox_product_below_threshold
            // 
            this->groupBox_product_below_threshold->Controls->Add(this->dataGridView2);
            this->groupBox_product_below_threshold->Location = System::Drawing::Point(8, 177);
            this->groupBox_product_below_threshold->Name = L"groupBox_product_below_threshold";
            this->groupBox_product_below_threshold->Size = System::Drawing::Size(598, 168);
            this->groupBox_product_below_threshold->TabIndex = 10;
            this->groupBox_product_below_threshold->TabStop = false;
            this->groupBox_product_below_threshold->Text = L"Total purchases by customers";
            // 
            // dataGridView2
            // 
            this->dataGridView2->AllowUserToAddRows = false;
            this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView2->Location = System::Drawing::Point(6, 21);
            this->dataGridView2->MultiSelect = false;
            this->dataGridView2->Name = L"dataGridView2";
            this->dataGridView2->RowHeadersWidth = 62;
            this->dataGridView2->RowTemplate->Height = 28;
            this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView2->Size = System::Drawing::Size(586, 138);
            this->dataGridView2->TabIndex = 1;
            // 
            // groupBox_total_purchases_by_customers
            // 
            this->groupBox_total_purchases_by_customers->Controls->Add(this->button_search_customer);
            this->groupBox_total_purchases_by_customers->Controls->Add(this->label1);
            this->groupBox_total_purchases_by_customers->Controls->Add(this->label2);
            this->groupBox_total_purchases_by_customers->Controls->Add(this->textBox_fname_statistics);
            this->groupBox_total_purchases_by_customers->Controls->Add(this->textBox_lname_statistics);
            this->groupBox_total_purchases_by_customers->Controls->Add(this->dataGridView1);
            this->groupBox_total_purchases_by_customers->Location = System::Drawing::Point(612, 177);
            this->groupBox_total_purchases_by_customers->Name = L"groupBox_total_purchases_by_customers";
            this->groupBox_total_purchases_by_customers->Size = System::Drawing::Size(632, 168);
            this->groupBox_total_purchases_by_customers->TabIndex = 9;
            this->groupBox_total_purchases_by_customers->TabStop = false;
            this->groupBox_total_purchases_by_customers->Text = L"Total purchases by customers";
            // 
            // button_search_customer
            // 
            this->button_search_customer->Location = System::Drawing::Point(525, 128);
            this->button_search_customer->Name = L"button_search_customer";
            this->button_search_customer->Size = System::Drawing::Size(88, 30);
            this->button_search_customer->TabIndex = 9;
            this->button_search_customer->Text = L"Search";
            this->button_search_customer->UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(260, 121);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(91, 20);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Last Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(6, 121);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(92, 20);
            this->label2->TabIndex = 7;
            this->label2->Text = L"First Name";
            // 
            // textBox_fname_statistics
            // 
            this->textBox_fname_statistics->Location = System::Drawing::Point(6, 136);
            this->textBox_fname_statistics->Name = L"textBox_fname_statistics";
            this->textBox_fname_statistics->Size = System::Drawing::Size(240, 26);
            this->textBox_fname_statistics->TabIndex = 5;
            // 
            // textBox_lname_statistics
            // 
            this->textBox_lname_statistics->Location = System::Drawing::Point(263, 136);
            this->textBox_lname_statistics->Name = L"textBox_lname_statistics";
            this->textBox_lname_statistics->Size = System::Drawing::Size(240, 26);
            this->textBox_lname_statistics->TabIndex = 6;
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(6, 21);
            this->dataGridView1->MultiSelect = false;
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 62;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView1->Size = System::Drawing::Size(620, 95);
            this->dataGridView1->TabIndex = 1;
            // 
            // groupBox_general_stats
            // 
            this->groupBox_general_stats->Controls->Add(this->label_simulate_stock_value);
            this->groupBox_general_stats->Controls->Add(this->label_purchase_stock_value);
            this->groupBox_general_stats->Controls->Add(this->label_commercial_stock_value);
            this->groupBox_general_stats->Controls->Add(this->label_monthly_turnover);
            this->groupBox_general_stats->Controls->Add(this->label_avg_basket);
            this->groupBox_general_stats->Location = System::Drawing::Point(8, 3);
            this->groupBox_general_stats->Name = L"groupBox_general_stats";
            this->groupBox_general_stats->Size = System::Drawing::Size(1241, 168);
            this->groupBox_general_stats->TabIndex = 7;
            this->groupBox_general_stats->TabStop = false;
            this->groupBox_general_stats->Text = L"General statistics";
            // 
            // label_simulate_stock_value
            // 
            this->label_simulate_stock_value->AutoSize = true;
            this->label_simulate_stock_value->Location = System::Drawing::Point(6, 143);
            this->label_simulate_stock_value->Name = L"label_simulate_stock_value";
            this->label_simulate_stock_value->Size = System::Drawing::Size(361, 20);
            this->label_simulate_stock_value->TabIndex = 6;
            this->label_simulate_stock_value->Text = L"This text is for the simulation of the stock value";
            // 
            // label_purchase_stock_value
            // 
            this->label_purchase_stock_value->AutoSize = true;
            this->label_purchase_stock_value->Location = System::Drawing::Point(6, 109);
            this->label_purchase_stock_value->Name = L"label_purchase_stock_value";
            this->label_purchase_stock_value->Size = System::Drawing::Size(307, 20);
            this->label_purchase_stock_value->TabIndex = 5;
            this->label_purchase_stock_value->Text = L"This text is for the purchase stock value";
            // 
            // label_commercial_stock_value
            // 
            this->label_commercial_stock_value->AutoSize = true;
            this->label_commercial_stock_value->Location = System::Drawing::Point(6, 79);
            this->label_commercial_stock_value->Name = L"label_commercial_stock_value";
            this->label_commercial_stock_value->Size = System::Drawing::Size(325, 20);
            this->label_commercial_stock_value->TabIndex = 4;
            this->label_commercial_stock_value->Text = L"This text is for the commercial stock value";
            // 
            // label_monthly_turnover
            // 
            this->label_monthly_turnover->AutoSize = true;
            this->label_monthly_turnover->Location = System::Drawing::Point(6, 48);
            this->label_monthly_turnover->Name = L"label_monthly_turnover";
            this->label_monthly_turnover->Size = System::Drawing::Size(273, 20);
            this->label_monthly_turnover->TabIndex = 3;
            this->label_monthly_turnover->Text = L"This text is for the monthly turnover";
            // 
            // label_avg_basket
            // 
            this->label_avg_basket->AutoSize = true;
            this->label_avg_basket->Location = System::Drawing::Point(6, 21);
            this->label_avg_basket->Name = L"label_avg_basket";
            this->label_avg_basket->Size = System::Drawing::Size(262, 20);
            this->label_avg_basket->TabIndex = 2;
            this->label_avg_basket->Text = L"This text is for the average basket";
            // 
            // UserInterface
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1258, 751);
            this->Controls->Add(this->tabController);
            this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->MaximumSize = System::Drawing::Size(1276, 798);
            this->MinimumSize = System::Drawing::Size(1276, 798);
            this->Name = L"UserInterface";
            this->Text = L"Company management";
            this->Load += gcnew System::EventHandler(this, &UserInterface::UserInterface_Load);
            this->tabController->ResumeLayout(false);
            this->tab_orders->ResumeLayout(false);
            this->groupBox_order_information->ResumeLayout(false);
            this->groupBox_order_information->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Orders))->EndInit();
            this->tab_inventory->ResumeLayout(false);
            this->groupBox_product_information->ResumeLayout(false);
            this->groupBox_product_information->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Inventory))->EndInit();
            this->tab_customers->ResumeLayout(false);
            this->groupBox_delivery_addresses->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_delivery_addresses))->EndInit();
            this->groupBox_customer_billing_addresses->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_billing_addresses))->EndInit();
            this->groupBox_customer_orders->ResumeLayout(false);
            this->groupBox_customer_currently_selected_order->ResumeLayout(false);
            this->groupBox_customer_currently_selected_order->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_orders))->EndInit();
            this->groupBox_customer_information->ResumeLayout(false);
            this->groupBox_customer_information->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customers))->EndInit();
            this->tab_employee->ResumeLayout(false);
            this->groupBox_employee_address->ResumeLayout(false);
            this->groupBox_employee_address->PerformLayout();
            this->groupBox_employee_manager->ResumeLayout(false);
            this->groupBox_employee_manager->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_employee))->EndInit();
            this->groupBox_employee_information->ResumeLayout(false);
            this->groupBox_employee_information->PerformLayout();
            this->tab_statistics->ResumeLayout(false);
            this->groupBox_worst_products->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
            this->groupBox_bestsellers->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
            this->groupBox_product_below_threshold->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
            this->groupBox_total_purchases_by_customers->ResumeLayout(false);
            this->groupBox_total_purchases_by_customers->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->groupBox_general_stats->ResumeLayout(false);
            this->groupBox_general_stats->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
        
        // General UserInterface functions
    private:
        System::Void UserInterface_Load(System::Object^ sender, System::EventArgs^ e)
        {

        }

        // Executes code when a specific tab is opened
    private:
        void OnTabSelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            switch(this->tabController->SelectedIndex)
            {
            case 0: // Orders
                return;
            case 1: // Inventory
                return;
            case 2: // Customers
                refresh_customers_datagrid();
                return;
            case 3: // Employee
                refresh_employee_datagrid();
                return;
            case 4: // Statistics
                return;
            default:
                return;
            }
        }
        

        // ### Customers tab ###
    private:
        void refresh_customers_datagrid()
        {
            // Refresh datagrid
            this->dataGridView_customers->Refresh();
            this->dataGridView_customers->DataSource = SQLserver->SQL_getCustomerList();

            
            // Configure columns
            this->dataGridView_customers->Columns["id_person"]->Width = 40;
            this->dataGridView_customers->Columns["first_order_date"]->Width = 130;

            this->dataGridView_customers->Columns["id_person"]->HeaderText = "ID";
            this->dataGridView_customers->Columns["first_order_date"]->HeaderText = "First order date";
            this->dataGridView_customers->Columns["first_name"]->HeaderText = "First name";
            this->dataGridView_customers->Columns["last_name"]->HeaderText = "Last name";
            this->dataGridView_customers->Columns["birth_date"]->HeaderText = "Birth date";

            
        }
    
    private:
        void refresh_customer_information()
        {
            this->groupBox_customer_information->Text = "Customer " + selected_customer->getID() + " Information";
            
            this->textBox_first_name_customer->Text = selected_customer->getFirstName();
            this->textBox_last_name_customer->Text = selected_customer->getLastName();
            this->dateTimePicker_customer_birth_date->Value = selected_customer->getBirthDate();
        }
        
    private:
        void refresh_customer_orders_datagrid()
        {
            this->groupBox_customer_orders->Text = "Customer " + selected_customer->getID() + " Orders";

            // Refresh datagrid
            this->dataGridView_customer_orders->Refresh();
            this->dataGridView_customer_orders->DataSource = this->selected_customer->getOrders();
            
            // Configure columns
            this->dataGridView_customer_orders->Sort(this->dataGridView_customer_orders->Columns["order_date"], System::ComponentModel::ListSortDirection::Descending);

            this->dataGridView_customer_orders->Columns["id_order"]->Visible = false;
            this->dataGridView_customer_orders->Columns["id_billing_address"]->Visible = false;
            this->dataGridView_customer_orders->Columns["id_delivery_address"]->Visible = false;
                        
            this->dataGridView_customer_orders->Columns["order_reference"]->HeaderText = "Order reference";
            this->dataGridView_customer_orders->Columns["total_amount"]->HeaderText = "Total Amount";
            this->dataGridView_customer_orders->Columns["order_discount_percentage"]->HeaderText = "Discount Percentage";
            this->dataGridView_customer_orders->Columns["order_date"]->HeaderText = "Order Date";
            this->dataGridView_customer_orders->Columns["delivery_date"]->HeaderText = "Delivery Date";
        }

        void refresh_customer_billing_addresses_datagrid()
        {
            this->groupBox_customer_billing_addresses->Text = "Customer " + selected_customer->getID() + " Billing addresses";
            
            this->dataGridView_customer_billing_addresses->Refresh();
            this->dataGridView_customer_billing_addresses->DataSource = this->selected_customer->getBillingAddresses();
            this->dataGridView_customer_billing_addresses->Columns["id_address"]->Visible = false;

            this->dataGridView_customer_billing_addresses->Sort(this->dataGridView_customer_billing_addresses->Columns["postal_code"], System::ComponentModel::ListSortDirection::Descending);
            
            this->dataGridView_customer_billing_addresses->Columns["city"]->HeaderText = "City";
            this->dataGridView_customer_billing_addresses->Columns["postal_code"]->HeaderText = "Postal Code";
            this->dataGridView_customer_billing_addresses->Columns["street"]->HeaderText = "Street";
            this->dataGridView_customer_billing_addresses->Columns["street_number"]->HeaderText = "Street Number";
        }

        void refresh_customer_delivery_addresses_datagrid()
        {
            this->groupBox_delivery_addresses->Text = "Customer " + selected_customer->getID() + " Delivery addresses";
            
            this->dataGridView_customer_delivery_addresses->Refresh();
            this->dataGridView_customer_delivery_addresses->DataSource = this->selected_customer->getDeliveryAddresses();
            this->dataGridView_customer_delivery_addresses->Columns["id_address"]->Visible = false;

            this->dataGridView_customer_delivery_addresses->Sort(this->dataGridView_customer_delivery_addresses->Columns["postal_code"], System::ComponentModel::ListSortDirection::Descending);
            
            this->dataGridView_customer_delivery_addresses->Columns["city"]->HeaderText = "City";
            this->dataGridView_customer_delivery_addresses->Columns["postal_code"]->HeaderText = "Postal Code";
            this->dataGridView_customer_delivery_addresses->Columns["street"]->HeaderText = "Street";
            this->dataGridView_customer_delivery_addresses->Columns["street_number"]->HeaderText = "Street Number";
        }

    // Events
    private:
        void dataGridView_customers_selectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Return if no columns are selected
            if (dataGridView_customers->SelectedRows->Count == 0)
            {
                return;
            }
            
            String^ selectedIDstring = this->dataGridView_customers->SelectedRows[0]->Cells["id_person"]->Value->ToString();

            
            selected_customer = gcnew Customer(System::Convert::ToInt32(selectedIDstring));
            
            refresh_customer_information();
            refresh_customer_orders_datagrid();
            refresh_customer_billing_addresses_datagrid();
            refresh_customer_delivery_addresses_datagrid();
        }
    
    private:
        System::Void button_modify_customer_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->selected_customer->setFirstName(this->textBox_first_name_customer->Text->Trim());
            this->selected_customer->setLastName(this->textBox_last_name_customer->Text->Trim());
            this->selected_customer->setBirthDate(this->dateTimePicker_customer_birth_date->Value);

            this->selected_customer->modify_in_DB();

            this->refresh_customers_datagrid();
        }

    private:
        System::Void button_delete_customer_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->selected_customer->delete_in_DB();

            this->refresh_customers_datagrid();
        }

    private:
        System::Void button_customers_reload_click(System::Object^ sender, System::EventArgs^ e)
        {
            this->refresh_customers_datagrid();
        }

    private: System::Void button_create_customer_Click(System::Object^ sender, System::EventArgs^ e) {
        createCustomerPrompt^ prompt = gcnew createCustomerPrompt;
        if(prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            this->selected_customer = gcnew Customer(prompt->new_customer_first_name, prompt->new_customer_last_name, prompt->new_customer_birth_date);

            refresh_customers_datagrid();
        }
    }

    // Orders stuff
    void dataGridView_customer_orders_selectionChanged(Object^ sender, EventArgs^ event_args)
    {
        if (this->dataGridView_customer_orders->SelectedRows->Count != 0)
        {
            this->groupBox_customer_currently_selected_order->Visible = true;
            
            Address^ currently_selected_order_billing_address = gcnew Address(Convert::ToInt32(this->dataGridView_customer_orders->SelectedRows[0]->Cells["id_billing_address"]->Value->ToString()));

            label_customers_current_order_billing_address->Text = "Billing address : " + currently_selected_order_billing_address->getStreetNumber() + " " + currently_selected_order_billing_address->getStreet() + ", " + currently_selected_order_billing_address->getPostalCode() + " " + currently_selected_order_billing_address->getCity();
            
            Address^ currently_selected_order_delivery_address = gcnew Address(Convert::ToInt32(this->dataGridView_customer_orders->SelectedRows[0]->Cells["id_delivery_address"]->Value->ToString()));

            label_customers_current_order_delivery_address->Text = "Delivery address : " + currently_selected_order_delivery_address->getStreetNumber() + " " + currently_selected_order_delivery_address->getStreet() + ", " + currently_selected_order_delivery_address->getPostalCode() + " " + currently_selected_order_delivery_address->getCity();
        }
        else
        {
            this->groupBox_customer_currently_selected_order->Visible = false;
        }
    }

    private: System::Void button_customer_add_order_Click(System::Object^ sender, System::EventArgs^ e) {
        editOrderPrompt^ prompt = gcnew editOrderPrompt(this->selected_customer->getID(), this->selected_customer->getFirstName() + " " + this->selected_customer->getLastName() + " - Create order");

        if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Order ^new_order = gcnew Order(prompt->new_order_order_date, prompt->new_order_delivery_date, prompt->new_order_discount_percentage, prompt->new_order_id_billing_address, prompt->new_order_id_delivery_address, selected_customer->getID());

            refresh_customer_orders_datagrid();
        }
    }

    private: System::Void button_customer_modify_order(System::Object^ sender, System::EventArgs^ e) {
        Order ^selected_order = gcnew Order(Convert::ToInt32(this->dataGridView_customer_orders->SelectedRows[0]->Cells["id_order"]->Value->ToString()));
        
        editOrderPrompt^ prompt = gcnew editOrderPrompt(this->selected_customer->getID(), this->selected_customer->getFirstName() + " " + this->selected_customer->getLastName() + " - Edit order", selected_order->getOrderDate(), selected_order->getDeliveryDate(), selected_order->getDiscoutPercentage(), selected_order->getBillingAddress(), selected_order->getDeliveryAddress());

        if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            selected_order->setOrderDate(prompt->new_order_order_date);
            selected_order->setDeliveryDate(prompt->new_order_delivery_date);
            selected_order->setDiscountPercentage(prompt->new_order_discount_percentage);
            selected_order->setBillingAddress(prompt->new_order_id_billing_address);
            selected_order->setDeliveryAddress(prompt->new_order_id_delivery_address);

            selected_order->modify_order_in_DB();

            refresh_customer_orders_datagrid();
        }
    }

    private: System::Void button_customer_delete_order_Click(System::Object^ sender, System::EventArgs^ e) {
        Order ^selected_order = gcnew Order(Convert::ToInt32(this->dataGridView_customer_orders->SelectedRows[0]->Cells["id_order"]->Value->ToString()));

        selected_order->delete_order_from_DB();

        refresh_customer_orders_datagrid();
    }


    // Billing address stuff
    int get_currently_selected_billing_address()
    {
        return Convert::ToInt32(this->dataGridView_customer_billing_addresses->SelectedRows[0]->Cells["id_address"]->Value->ToString());
    }
        
    int get_currently_selected_delivery_address()
    {
        return Convert::ToInt32(this->dataGridView_customer_delivery_addresses->SelectedRows[0]->Cells["id_address"]->Value->ToString());
    }
        
    private: System::Void button_customer_add_billing_address_Click(System::Object^ sender, System::EventArgs^ e) {
        Projet::editAddressPrompt^ prompt = gcnew Projet::editAddressPrompt(this->selected_customer->getFirstName() + " " + this->selected_customer->getLastName() + " - Add billing address");
        
        if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Address^ new_customer_billing_address = gcnew Address(prompt->new_address_city, prompt->new_address_postal_code, prompt->new_address_street, prompt->new_address_street_number);

            selected_customer->addBillingAddressToCustomer(new_customer_billing_address->getID());

            refresh_customer_billing_addresses_datagrid();
        }
    }

    private: System::Void button_customer_modify_billing_address_Click(System::Object^ sender, System::EventArgs^ e) {
        Address^ currentlySelectedBillingAddress = gcnew Address(get_currently_selected_billing_address());

        String^ windowText = this->selected_customer->getFirstName() + " " + this->selected_customer->getLastName() + " - Edit billing address";

        Projet::editAddressPrompt^ prompt = gcnew Projet::editAddressPrompt(windowText, currentlySelectedBillingAddress->getCity(), currentlySelectedBillingAddress->getPostalCode(), currentlySelectedBillingAddress->getStreet(), currentlySelectedBillingAddress->getStreetNumber());

        if(prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            currentlySelectedBillingAddress->setCity(prompt->new_address_city);
            currentlySelectedBillingAddress->setPostalCode(prompt->new_address_postal_code);
            currentlySelectedBillingAddress->setStreet(prompt->new_address_street);
            currentlySelectedBillingAddress->setStreetNumber(prompt->new_address_street_number);

            currentlySelectedBillingAddress->modify_address_in_DB();

            refresh_customer_billing_addresses_datagrid();
        }
    }
        
    private: System::Void button_customer_delete_billing_address_Click(System::Object^ sender, System::EventArgs^ e) {
        Address^ currentlySelectedBillingAddress = gcnew Address(get_currently_selected_billing_address());
        
        this->selected_customer->deleteBillingAddressFromCustomer(currentlySelectedBillingAddress->getID());

        currentlySelectedBillingAddress->delete_address_from_DB();

        refresh_customer_billing_addresses_datagrid();
        
    }

        // Delivery address stuff

        // TODO handle invalid values for adding and mofifying addresses
        
    private: System::Void button_customer_add_delivery_address_Click(System::Object^ sender, System::EventArgs^ e) {
        Projet::editAddressPrompt^ prompt = gcnew Projet::editAddressPrompt(this->selected_customer->getFirstName() + " " + this->selected_customer->getLastName() + " - Add delivery address");

        if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Address^ new_customer_delivery_address = gcnew Address(prompt->new_address_city, prompt->new_address_postal_code, prompt->new_address_street, prompt->new_address_street_number);

            selected_customer->addDeliveryAddressToCustomer(new_customer_delivery_address->getID());

            refresh_customer_delivery_addresses_datagrid();
        }
    }

    private: System::Void button_customer_modify_delivery_address_Click(System::Object^ sender, System::EventArgs^ e) {
        Address^ currentlySelectedDeliveryAddress = gcnew Address(get_currently_selected_delivery_address());

        String^ windowText = this->selected_customer->getFirstName() + " " + this->selected_customer->getLastName() + " - Edit delivery address";

        Projet::editAddressPrompt^ prompt = gcnew Projet::editAddressPrompt(windowText, currentlySelectedDeliveryAddress->getCity(), currentlySelectedDeliveryAddress->getPostalCode(), currentlySelectedDeliveryAddress->getStreet(), currentlySelectedDeliveryAddress->getStreetNumber());

        if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            currentlySelectedDeliveryAddress->setCity(prompt->new_address_city);
            currentlySelectedDeliveryAddress->setPostalCode(prompt->new_address_postal_code);
            currentlySelectedDeliveryAddress->setStreet(prompt->new_address_street);
            currentlySelectedDeliveryAddress->setStreetNumber(prompt->new_address_street_number);

            currentlySelectedDeliveryAddress->modify_address_in_DB();

            refresh_customer_delivery_addresses_datagrid();
        }

        
    }
    private: System::Void button_customer_delete_delivery_address_Click(System::Object^ sender, System::EventArgs^ e) {
        Address^ currentlySelectedDeliveryAddress = gcnew Address(get_currently_selected_delivery_address());

        this->selected_customer->deleteDeliveryAddressFromCustomer(currentlySelectedDeliveryAddress->getID());

        currentlySelectedDeliveryAddress->delete_address_from_DB();

        refresh_customer_delivery_addresses_datagrid();
    }
        

        
        // ### Employee tab ###
    private:
        void refresh_employee_datagrid()
        {
            this->dataGridView_employee->Refresh();
            this->dataGridView_employee->DataSource = SQLserver->SQL_getEmployeeList();
            this->dataGridView_employee->Columns["id_person"]->Width = 40;
            this->dataGridView_employee->Columns["hiring_date"]->Width = 130;
            this->dataGridView_employee->Columns["id_address"]->Visible = false;
            this->dataGridView_employee->Columns["id_manager"]->Visible = false;

            this->dataGridView_employee->Columns["id_person"]->HeaderText = "ID";
            this->dataGridView_employee->Columns["first_name"]->HeaderText = "First name";
            this->dataGridView_employee->Columns["last_name"]->HeaderText = "Last name";
            this->dataGridView_employee->Columns["hiring_date"]->HeaderText = "Hiring date";
        }

    private:
        void refresh_employee_information()
        {
            this->groupBox_employee_information->Text = "Employee " + selected_employee->getID() + " Information";
            
            this->textBox_first_name_employee->Text = selected_employee->getFirstName();
            this->textBox_last_name_employee->Text = selected_employee->getLastName();
            this->dateTimePicker_employee_hiring_date->Value = selected_employee->getHireDate();
        }

        void refresh_employee_manager_information()
        {
            this->groupBox_employee_manager->Text = "Employee " + this->selected_employee->getID() + " Manager";

            
            if (selected_employee->getManager() != -1)
            {
                this->button_employee_remove_manager->Visible = true;
                
                Employee^ manager = gcnew Employee(selected_employee->getManager());
                
                this->label_employee_manager_name->Text = "Manager : " + manager->getFirstName() + " " + manager->getLastName();
            }
            else
            {
                this->label_employee_manager_name->Text = "This employee has no manager";

                this->button_employee_remove_manager->Visible = false;
            }
            
        }

        void refresh_employee_address_information()
        {
            this->groupBox_employee_address->Text = "Employee " + selected_employee->getID() + " Address";

            selected_employee_address = gcnew Address(selected_employee->getAddress());

            this->textBox_employee_address_city ->Text = selected_employee_address->getCity();
            this->textBox_employee_address_postal_code->Text = selected_employee_address->getPostalCode().ToString();
            this->textBox_employee_address_street->Text = selected_employee_address->getStreet();
            this->textBox_employee_address_street_number->Text = selected_employee_address->getStreetNumber().ToString();

        }

        
        
    // Events
    private: System::Void button_create_employee_Click(System::Object^ sender, System::EventArgs^ e) {
        createEmployeePrompt^ prompt = gcnew createEmployeePrompt;
        if(prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            Address^ new_employee_address = gcnew Address(prompt->new_employee_address_city, prompt->new_employee_address_postal_code, prompt->new_employee_address_street, prompt->new_employee_address_street_number);
            
            this->selected_employee = gcnew Employee(prompt->new_employee_first_name, prompt->new_employee_last_name, prompt->new_employee_hire_date, new_employee_address->getID());

            refresh_employee_datagrid();
        }
    }

    private:
        System::Void button_employee_reload_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->refresh_employee_datagrid();
        }
        
    private:
        void dataGridView_employee_selectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Return if no columns are selected
            if (dataGridView_employee->SelectedRows->Count == 0)
            {
                return;
            }

            String^ selectedIDstring = this->dataGridView_employee->SelectedRows[0]->Cells["id_person"]->Value->ToString();
            

            selected_employee = gcnew Employee(Convert::ToInt32(selectedIDstring));
            
            refresh_employee_information();
            refresh_employee_manager_information();
            refresh_employee_address_information();
        }

    private:
        System::Void button_delete_employee_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->selected_employee->delete_in_DB();

            this->refresh_employee_datagrid();
        }

    private: 
        System::Void button_modify_employee_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->selected_employee->setFirstName(this->textBox_first_name_employee->Text->Trim());
            this->selected_employee->setLastName(this->textBox_last_name_employee->Text->Trim());
            this->selected_employee->setHireDate(this->dateTimePicker_employee_hiring_date->Value);

            
            this->selected_employee->modify_in_DB();
            
            this->refresh_employee_datagrid();
        }
    
    private: 
        System::Void button_employee_select_manager_click(System::Object^ sender, System::EventArgs^ e)
        {
            selectEmployeeManager^ prompt = gcnew selectEmployeeManager(SQLserver->SQL_getEmployeeList(), "Choose a manager");
            
            if(prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                this->selected_employee->setManager(prompt->selected_manager);
            
                refresh_employee_manager_information();
            }
        }


    private:
        System::Void button_employee_remove_manager_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->selected_employee->removeManager();
            
            refresh_employee_manager_information();
        }
        
    private:
        System::Void button_employee_modify_address_Click(System::Object^ sender, System::EventArgs^ e) {
        this->selected_employee_address->setCity(this->textBox_employee_address_city->Text->Trim());
        this->selected_employee_address->setPostalCode(Convert::ToInt32(this->textBox_employee_address_postal_code->Text));
        this->selected_employee_address->setStreet(this->textBox_employee_address_street->Text->Trim());
        this->selected_employee_address->setStreetNumber(Convert::ToInt32(this->textBox_employee_address_street_number->Text));

        this->selected_employee_address->modify_address_in_DB();

        refresh_employee_address_information();
}



};
}