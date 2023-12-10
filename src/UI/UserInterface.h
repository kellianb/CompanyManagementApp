#pragma once

#include "../SQL/SQLservices.h"

#include "editAddressPrompt.h"
#include "createCustomerPrompt.h"
#include "selectEmployeeManager.h"
#include "createEmployeePrompt.h"
#include "editOrderPrompt.h"
#include "editProductPrompt.h"
#include "editProductPrices.h"
#include "editProductsInOrder.h"

#include "../Customer.h"
#include "../Employee.h"
#include "../Address.h"
#include "../Order.h"
#include "../Product.h"
#include "../Product_price.h"


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
        // SQL services
        SQLservices^ SQLserver = gcnew SQLservices;

        // Products tab
        Product^ selected_product;
        Product_price^ selected_product_price;

        // Customer tab
        Customer^ selected_customer;
        Order^ selected_customer_order;
        
        Address^ currentlySelectedDeliveryAddress;
        Address^ currentlySelectedBillingAddress;

        // Employee tab
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

    private: System::Windows::Forms::DataGridView^ dataGridView_inventory;
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
    private: System::Windows::Forms::TextBox^ textBox_product_reorder_threshold;

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

    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::Label^ label_reorder_threshold;
    private: System::Windows::Forms::Button^ button_delete_product;


    private: System::Windows::Forms::Button^ button_modify_product;

    private: System::Windows::Forms::Label^ label_product_stock;
    private: System::Windows::Forms::Label^ label_product_name;


    private: System::Windows::Forms::TextBox^ textBox_product_name;
    private: System::Windows::Forms::TextBox^ textBox_product_stock;
    private: System::Windows::Forms::Label^ label_product_vat;



    private: System::Windows::Forms::TextBox^ textBox_product_vat;
    private: System::Windows::Forms::Button^ button_create_product;
    private: System::Windows::Forms::Button^ button_products_reload;
    private: System::Windows::Forms::Label^ label_product_reorder;
    private: System::Windows::Forms::GroupBox^ groupBox_product_prices;
    private: System::Windows::Forms::DataGridView^ dataGridView_product_prices;
    private: System::Windows::Forms::Button^ button_delete_product_prices;
    private: System::Windows::Forms::Button^ button_add_product_prices;
    private: System::Windows::Forms::Button^ button_modify_product_prices;
private: System::Windows::Forms::Button^ button_customer_order_modify_items;






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
            this->tab_inventory = (gcnew System::Windows::Forms::TabPage());
            this->groupBox_product_prices = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView_product_prices = (gcnew System::Windows::Forms::DataGridView());
            this->button_delete_product_prices = (gcnew System::Windows::Forms::Button());
            this->button_add_product_prices = (gcnew System::Windows::Forms::Button());
            this->button_modify_product_prices = (gcnew System::Windows::Forms::Button());
            this->button_create_product = (gcnew System::Windows::Forms::Button());
            this->button_products_reload = (gcnew System::Windows::Forms::Button());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->label_product_reorder = (gcnew System::Windows::Forms::Label());
            this->label_product_vat = (gcnew System::Windows::Forms::Label());
            this->textBox_product_vat = (gcnew System::Windows::Forms::TextBox());
            this->label_reorder_threshold = (gcnew System::Windows::Forms::Label());
            this->textBox_product_reorder_threshold = (gcnew System::Windows::Forms::TextBox());
            this->button_delete_product = (gcnew System::Windows::Forms::Button());
            this->button_modify_product = (gcnew System::Windows::Forms::Button());
            this->label_product_stock = (gcnew System::Windows::Forms::Label());
            this->label_product_name = (gcnew System::Windows::Forms::Label());
            this->textBox_product_name = (gcnew System::Windows::Forms::TextBox());
            this->textBox_product_stock = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView_inventory = (gcnew System::Windows::Forms::DataGridView());
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
            this->button_customer_order_modify_items = (gcnew System::Windows::Forms::Button());
            this->tabController->SuspendLayout();
            this->tab_inventory->SuspendLayout();
            this->groupBox_product_prices->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_product_prices))->BeginInit();
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_inventory))->BeginInit();
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
            this->tabController->Controls->Add(this->tab_inventory);
            this->tabController->Controls->Add(this->tab_customers);
            this->tabController->Controls->Add(this->tab_employee);
            this->tabController->Controls->Add(this->tab_statistics);
            this->tabController->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabController->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tabController->Location = System::Drawing::Point(0, 0);
            this->tabController->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tabController->Name = L"tabController";
            this->tabController->SelectedIndex = 0;
            this->tabController->Size = System::Drawing::Size(1258, 751);
            this->tabController->TabIndex = 0;
            this->tabController->SelectedIndexChanged += gcnew System::EventHandler(this, &UserInterface::OnTabSelectedIndexChanged);
            // 
            // tab_inventory
            // 
            this->tab_inventory->Controls->Add(this->groupBox_product_prices);
            this->tab_inventory->Controls->Add(this->button_create_product);
            this->tab_inventory->Controls->Add(this->button_products_reload);
            this->tab_inventory->Controls->Add(this->groupBox1);
            this->tab_inventory->Controls->Add(this->dataGridView_inventory);
            this->tab_inventory->Location = System::Drawing::Point(4, 28);
            this->tab_inventory->Margin = System::Windows::Forms::Padding(2);
            this->tab_inventory->Name = L"tab_inventory";
            this->tab_inventory->Padding = System::Windows::Forms::Padding(2);
            this->tab_inventory->Size = System::Drawing::Size(1250, 719);
            this->tab_inventory->TabIndex = 2;
            this->tab_inventory->Text = L"Inventory";
            this->tab_inventory->UseVisualStyleBackColor = true;
            // 
            // groupBox_product_prices
            // 
            this->groupBox_product_prices->Controls->Add(this->dataGridView_product_prices);
            this->groupBox_product_prices->Controls->Add(this->button_delete_product_prices);
            this->groupBox_product_prices->Controls->Add(this->button_add_product_prices);
            this->groupBox_product_prices->Controls->Add(this->button_modify_product_prices);
            this->groupBox_product_prices->Location = System::Drawing::Point(559, 201);
            this->groupBox_product_prices->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_product_prices->Name = L"groupBox_product_prices";
            this->groupBox_product_prices->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_product_prices->Size = System::Drawing::Size(688, 522);
            this->groupBox_product_prices->TabIndex = 17;
            this->groupBox_product_prices->TabStop = false;
            this->groupBox_product_prices->Text = L"Product prices";
            // 
            // dataGridView_product_prices
            // 
            this->dataGridView_product_prices->AllowUserToAddRows = false;
            this->dataGridView_product_prices->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_product_prices->Location = System::Drawing::Point(6, 21);
            this->dataGridView_product_prices->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView_product_prices->MultiSelect = false;
            this->dataGridView_product_prices->Name = L"dataGridView_product_prices";
            this->dataGridView_product_prices->ReadOnly = true;
            this->dataGridView_product_prices->RowHeadersWidth = 62;
            this->dataGridView_product_prices->RowTemplate->Height = 28;
            this->dataGridView_product_prices->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_product_prices->Size = System::Drawing::Size(675, 460);
            this->dataGridView_product_prices->TabIndex = 1;
            this->dataGridView_product_prices->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_product_prices_selectionChanged);
            // 
            // button_delete_product_prices
            // 
            this->button_delete_product_prices->Location = System::Drawing::Point(224, 488);
            this->button_delete_product_prices->Margin = System::Windows::Forms::Padding(2);
            this->button_delete_product_prices->Name = L"button_delete_product_prices";
            this->button_delete_product_prices->Size = System::Drawing::Size(88, 30);
            this->button_delete_product_prices->TabIndex = 6;
            this->button_delete_product_prices->Text = L"Delete";
            this->button_delete_product_prices->UseVisualStyleBackColor = true;
            this->button_delete_product_prices->Click += gcnew System::EventHandler(this, &UserInterface::button_delete_product_price_Click);
            // 
            // button_add_product_prices
            // 
            this->button_add_product_prices->Location = System::Drawing::Point(6, 488);
            this->button_add_product_prices->Margin = System::Windows::Forms::Padding(2);
            this->button_add_product_prices->Name = L"button_add_product_prices";
            this->button_add_product_prices->Size = System::Drawing::Size(88, 30);
            this->button_add_product_prices->TabIndex = 3;
            this->button_add_product_prices->Text = L"Add";
            this->button_add_product_prices->UseVisualStyleBackColor = true;
            this->button_add_product_prices->Click += gcnew System::EventHandler(this, &UserInterface::button_add_product_price_Click);
            // 
            // button_modify_product_prices
            // 
            this->button_modify_product_prices->Location = System::Drawing::Point(114, 488);
            this->button_modify_product_prices->Margin = System::Windows::Forms::Padding(2);
            this->button_modify_product_prices->Name = L"button_modify_product_prices";
            this->button_modify_product_prices->Size = System::Drawing::Size(88, 30);
            this->button_modify_product_prices->TabIndex = 5;
            this->button_modify_product_prices->Text = L"Modify";
            this->button_modify_product_prices->UseVisualStyleBackColor = true;
            this->button_modify_product_prices->Click += gcnew System::EventHandler(this, &UserInterface::button_edit_product_price_Click);
            // 
            // button_create_product
            // 
            this->button_create_product->Location = System::Drawing::Point(908, 152);
            this->button_create_product->Margin = System::Windows::Forms::Padding(2);
            this->button_create_product->Name = L"button_create_product";
            this->button_create_product->Size = System::Drawing::Size(195, 38);
            this->button_create_product->TabIndex = 16;
            this->button_create_product->Text = L"Create a product";
            this->button_create_product->UseVisualStyleBackColor = true;
            this->button_create_product->Click += gcnew System::EventHandler(this, &UserInterface::button_create_product_Click);
            // 
            // button_products_reload
            // 
            this->button_products_reload->Location = System::Drawing::Point(1122, 152);
            this->button_products_reload->Margin = System::Windows::Forms::Padding(2);
            this->button_products_reload->Name = L"button_products_reload";
            this->button_products_reload->Size = System::Drawing::Size(100, 38);
            this->button_products_reload->TabIndex = 15;
            this->button_products_reload->Text = L"Reload";
            this->button_products_reload->UseVisualStyleBackColor = true;
            this->button_products_reload->Click += gcnew System::EventHandler(this, &UserInterface::button_products_reload_Click);
            // 
            // groupBox1
            // 
            this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox1->Controls->Add(this->label_product_reorder);
            this->groupBox1->Controls->Add(this->label_product_vat);
            this->groupBox1->Controls->Add(this->textBox_product_vat);
            this->groupBox1->Controls->Add(this->label_reorder_threshold);
            this->groupBox1->Controls->Add(this->textBox_product_reorder_threshold);
            this->groupBox1->Controls->Add(this->button_delete_product);
            this->groupBox1->Controls->Add(this->button_modify_product);
            this->groupBox1->Controls->Add(this->label_product_stock);
            this->groupBox1->Controls->Add(this->label_product_name);
            this->groupBox1->Controls->Add(this->textBox_product_name);
            this->groupBox1->Controls->Add(this->textBox_product_stock);
            this->groupBox1->Location = System::Drawing::Point(8, 201);
            this->groupBox1->Margin = System::Windows::Forms::Padding(2);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Padding = System::Windows::Forms::Padding(2);
            this->groupBox1->Size = System::Drawing::Size(542, 236);
            this->groupBox1->TabIndex = 14;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Product Information";
            // 
            // label_product_reorder
            // 
            this->label_product_reorder->AutoSize = true;
            this->label_product_reorder->Font = (gcnew System::Drawing::Font(L"Inter ExtraBold", 14, System::Drawing::FontStyle::Bold));
            this->label_product_reorder->ForeColor = System::Drawing::Color::Red;
            this->label_product_reorder->Location = System::Drawing::Point(22, 190);
            this->label_product_reorder->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_product_reorder->Name = L"label_product_reorder";
            this->label_product_reorder->Size = System::Drawing::Size(128, 29);
            this->label_product_reorder->TabIndex = 16;
            this->label_product_reorder->Text = L"REORDER";
            // 
            // label_product_vat
            // 
            this->label_product_vat->AutoSize = true;
            this->label_product_vat->Location = System::Drawing::Point(312, 101);
            this->label_product_vat->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_product_vat->Name = L"label_product_vat";
            this->label_product_vat->Size = System::Drawing::Size(61, 20);
            this->label_product_vat->TabIndex = 15;
            this->label_product_vat->Text = L"VAT %";
            // 
            // textBox_product_vat
            // 
            this->textBox_product_vat->Location = System::Drawing::Point(316, 124);
            this->textBox_product_vat->Margin = System::Windows::Forms::Padding(2);
            this->textBox_product_vat->Name = L"textBox_product_vat";
            this->textBox_product_vat->Size = System::Drawing::Size(196, 27);
            this->textBox_product_vat->TabIndex = 15;
            // 
            // label_reorder_threshold
            // 
            this->label_reorder_threshold->AutoSize = true;
            this->label_reorder_threshold->Location = System::Drawing::Point(312, 30);
            this->label_reorder_threshold->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_reorder_threshold->Name = L"label_reorder_threshold";
            this->label_reorder_threshold->Size = System::Drawing::Size(154, 20);
            this->label_reorder_threshold->TabIndex = 8;
            this->label_reorder_threshold->Text = L"Reorder threshold";
            // 
            // textBox_product_reorder_threshold
            // 
            this->textBox_product_reorder_threshold->Location = System::Drawing::Point(316, 52);
            this->textBox_product_reorder_threshold->Margin = System::Windows::Forms::Padding(2);
            this->textBox_product_reorder_threshold->Name = L"textBox_product_reorder_threshold";
            this->textBox_product_reorder_threshold->Size = System::Drawing::Size(196, 27);
            this->textBox_product_reorder_threshold->TabIndex = 7;
            // 
            // button_delete_product
            // 
            this->button_delete_product->Location = System::Drawing::Point(425, 192);
            this->button_delete_product->Margin = System::Windows::Forms::Padding(2);
            this->button_delete_product->Name = L"button_delete_product";
            this->button_delete_product->Size = System::Drawing::Size(88, 30);
            this->button_delete_product->TabIndex = 6;
            this->button_delete_product->Text = L"Delete";
            this->button_delete_product->UseVisualStyleBackColor = true;
            this->button_delete_product->Click += gcnew System::EventHandler(this, &UserInterface::button_delete_product_Click);
            // 
            // button_modify_product
            // 
            this->button_modify_product->Location = System::Drawing::Point(316, 191);
            this->button_modify_product->Margin = System::Windows::Forms::Padding(2);
            this->button_modify_product->Name = L"button_modify_product";
            this->button_modify_product->Size = System::Drawing::Size(88, 30);
            this->button_modify_product->TabIndex = 5;
            this->button_modify_product->Text = L"Modify";
            this->button_modify_product->UseVisualStyleBackColor = true;
            this->button_modify_product->Click += gcnew System::EventHandler(this, &UserInterface::button_modify_product_Click);
            // 
            // label_product_stock
            // 
            this->label_product_stock->AutoSize = true;
            this->label_product_stock->Location = System::Drawing::Point(24, 101);
            this->label_product_stock->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_product_stock->Name = L"label_product_stock";
            this->label_product_stock->Size = System::Drawing::Size(54, 20);
            this->label_product_stock->TabIndex = 4;
            this->label_product_stock->Text = L"Stock";
            // 
            // label_product_name
            // 
            this->label_product_name->AutoSize = true;
            this->label_product_name->Location = System::Drawing::Point(24, 30);
            this->label_product_name->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_product_name->Name = L"label_product_name";
            this->label_product_name->Size = System::Drawing::Size(122, 20);
            this->label_product_name->TabIndex = 3;
            this->label_product_name->Text = L"Product name";
            // 
            // textBox_product_name
            // 
            this->textBox_product_name->Location = System::Drawing::Point(28, 52);
            this->textBox_product_name->Margin = System::Windows::Forms::Padding(2);
            this->textBox_product_name->Name = L"textBox_product_name";
            this->textBox_product_name->Size = System::Drawing::Size(240, 27);
            this->textBox_product_name->TabIndex = 1;
            // 
            // textBox_product_stock
            // 
            this->textBox_product_stock->Location = System::Drawing::Point(28, 124);
            this->textBox_product_stock->Margin = System::Windows::Forms::Padding(2);
            this->textBox_product_stock->Name = L"textBox_product_stock";
            this->textBox_product_stock->Size = System::Drawing::Size(240, 27);
            this->textBox_product_stock->TabIndex = 2;
            // 
            // dataGridView_inventory
            // 
            this->dataGridView_inventory->AllowUserToAddRows = false;
            this->dataGridView_inventory->AllowUserToDeleteRows = false;
            this->dataGridView_inventory->AllowUserToOrderColumns = true;
            this->dataGridView_inventory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView_inventory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_inventory->Location = System::Drawing::Point(8, 8);
            this->dataGridView_inventory->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView_inventory->MinimumSize = System::Drawing::Size(999, 112);
            this->dataGridView_inventory->MultiSelect = false;
            this->dataGridView_inventory->Name = L"dataGridView_inventory";
            this->dataGridView_inventory->ReadOnly = true;
            this->dataGridView_inventory->RowHeadersWidth = 62;
            this->dataGridView_inventory->RowTemplate->Height = 28;
            this->dataGridView_inventory->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_inventory->Size = System::Drawing::Size(1236, 188);
            this->dataGridView_inventory->TabIndex = 1;
            this->dataGridView_inventory->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_inventory_selectionChanged);
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
            this->tab_customers->Location = System::Drawing::Point(4, 28);
            this->tab_customers->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Name = L"tab_customers";
            this->tab_customers->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Size = System::Drawing::Size(1250, 719);
            this->tab_customers->TabIndex = 0;
            this->tab_customers->Text = L"Customers";
            this->tab_customers->UseVisualStyleBackColor = true;
            // 
            // button_create_customer
            // 
            this->button_create_customer->Location = System::Drawing::Point(908, 152);
            this->button_create_customer->Margin = System::Windows::Forms::Padding(2);
            this->button_create_customer->Name = L"button_create_customer";
            this->button_create_customer->Size = System::Drawing::Size(195, 38);
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
            this->groupBox_delivery_addresses->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_delivery_addresses->Name = L"groupBox_delivery_addresses";
            this->groupBox_delivery_addresses->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_delivery_addresses->Size = System::Drawing::Size(542, 169);
            this->groupBox_delivery_addresses->TabIndex = 8;
            this->groupBox_delivery_addresses->TabStop = false;
            this->groupBox_delivery_addresses->Text = L"Delivery addresses";
            // 
            // dataGridView_customer_delivery_addresses
            // 
            this->dataGridView_customer_delivery_addresses->AllowUserToAddRows = false;
            this->dataGridView_customer_delivery_addresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_delivery_addresses->Location = System::Drawing::Point(6, 21);
            this->dataGridView_customer_delivery_addresses->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView_customer_delivery_addresses->MultiSelect = false;
            this->dataGridView_customer_delivery_addresses->Name = L"dataGridView_customer_delivery_addresses";
            this->dataGridView_customer_delivery_addresses->ReadOnly = true;
            this->dataGridView_customer_delivery_addresses->RowHeadersWidth = 62;
            this->dataGridView_customer_delivery_addresses->RowTemplate->Height = 28;
            this->dataGridView_customer_delivery_addresses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_delivery_addresses->Size = System::Drawing::Size(531, 99);
            this->dataGridView_customer_delivery_addresses->TabIndex = 1;
            this->dataGridView_customer_delivery_addresses->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_customer_delivery_addresses_selectionChanged);
            // 
            // button_customer_delete_delivery_address
            // 
            this->button_customer_delete_delivery_address->Location = System::Drawing::Point(220, 126);
            this->button_customer_delete_delivery_address->Margin = System::Windows::Forms::Padding(2);
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
            this->button_customer_add_delivery_address->Margin = System::Windows::Forms::Padding(2);
            this->button_customer_add_delivery_address->Name = L"button_customer_add_delivery_address";
            this->button_customer_add_delivery_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_add_delivery_address->TabIndex = 3;
            this->button_customer_add_delivery_address->Text = L"Add";
            this->button_customer_add_delivery_address->UseVisualStyleBackColor = true;
            this->button_customer_add_delivery_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_add_delivery_address_Click);
            // 
            // button_customer_modify_delivery_address
            // 
            this->button_customer_modify_delivery_address->Location = System::Drawing::Point(112, 126);
            this->button_customer_modify_delivery_address->Margin = System::Windows::Forms::Padding(2);
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
            this->groupBox_customer_billing_addresses->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_customer_billing_addresses->Name = L"groupBox_customer_billing_addresses";
            this->groupBox_customer_billing_addresses->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_customer_billing_addresses->Size = System::Drawing::Size(542, 169);
            this->groupBox_customer_billing_addresses->TabIndex = 7;
            this->groupBox_customer_billing_addresses->TabStop = false;
            this->groupBox_customer_billing_addresses->Text = L"Billing addresses";
            // 
            // button_customer_delete_billing_address
            // 
            this->button_customer_delete_billing_address->Location = System::Drawing::Point(220, 126);
            this->button_customer_delete_billing_address->Margin = System::Windows::Forms::Padding(2);
            this->button_customer_delete_billing_address->Name = L"button_customer_delete_billing_address";
            this->button_customer_delete_billing_address->Size = System::Drawing::Size(88, 30);
            this->button_customer_delete_billing_address->TabIndex = 4;
            this->button_customer_delete_billing_address->Text = L"Delete";
            this->button_customer_delete_billing_address->UseVisualStyleBackColor = true;
            this->button_customer_delete_billing_address->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_delete_billing_address_Click);
            // 
            // button_customer_modify_billing_address
            // 
            this->button_customer_modify_billing_address->Location = System::Drawing::Point(112, 126);
            this->button_customer_modify_billing_address->Margin = System::Windows::Forms::Padding(2);
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
            this->button_customer_add_billing_address->Margin = System::Windows::Forms::Padding(2);
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
            this->dataGridView_customer_billing_addresses->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView_customer_billing_addresses->MultiSelect = false;
            this->dataGridView_customer_billing_addresses->Name = L"dataGridView_customer_billing_addresses";
            this->dataGridView_customer_billing_addresses->ReadOnly = true;
            this->dataGridView_customer_billing_addresses->RowHeadersWidth = 62;
            this->dataGridView_customer_billing_addresses->RowTemplate->Height = 28;
            this->dataGridView_customer_billing_addresses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_billing_addresses->Size = System::Drawing::Size(531, 99);
            this->dataGridView_customer_billing_addresses->TabIndex = 1;
            this->dataGridView_customer_billing_addresses->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_customer_billing_addresses_selectionChanged);
            // 
            // groupBox_customer_orders
            // 
            this->groupBox_customer_orders->Controls->Add(this->groupBox_customer_currently_selected_order);
            this->groupBox_customer_orders->Controls->Add(this->button_customer_add_order);
            this->groupBox_customer_orders->Controls->Add(this->dataGridView_customer_orders);
            this->groupBox_customer_orders->Location = System::Drawing::Point(561, 201);
            this->groupBox_customer_orders->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_customer_orders->Name = L"groupBox_customer_orders";
            this->groupBox_customer_orders->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_customer_orders->Size = System::Drawing::Size(679, 518);
            this->groupBox_customer_orders->TabIndex = 5;
            this->groupBox_customer_orders->TabStop = false;
            this->groupBox_customer_orders->Text = L"Customer Orders";
            // 
            // groupBox_customer_currently_selected_order
            // 
            this->groupBox_customer_currently_selected_order->Controls->Add(this->button_customer_order_modify_items);
            this->groupBox_customer_currently_selected_order->Controls->Add(this->button1);
            this->groupBox_customer_currently_selected_order->Controls->Add(this->button_customer_delete_order);
            this->groupBox_customer_currently_selected_order->Controls->Add(this->label_customers_current_order_billing_address);
            this->groupBox_customer_currently_selected_order->Controls->Add(this->label_customers_current_order_delivery_address);
            this->groupBox_customer_currently_selected_order->Location = System::Drawing::Point(11, 348);
            this->groupBox_customer_currently_selected_order->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_customer_currently_selected_order->Name = L"groupBox_customer_currently_selected_order";
            this->groupBox_customer_currently_selected_order->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_customer_currently_selected_order->Size = System::Drawing::Size(656, 156);
            this->groupBox_customer_currently_selected_order->TabIndex = 10;
            this->groupBox_customer_currently_selected_order->TabStop = false;
            this->groupBox_customer_currently_selected_order->Text = L"Order";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(6, 120);
            this->button1->Margin = System::Windows::Forms::Padding(2);
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
            this->button_customer_delete_order->Margin = System::Windows::Forms::Padding(2);
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
            this->label_customers_current_order_billing_address->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_customers_current_order_billing_address->Name = L"label_customers_current_order_billing_address";
            this->label_customers_current_order_billing_address->Size = System::Drawing::Size(20, 20);
            this->label_customers_current_order_billing_address->TabIndex = 2;
            this->label_customers_current_order_billing_address->Text = L" f";
            // 
            // label_customers_current_order_delivery_address
            // 
            this->label_customers_current_order_delivery_address->AutoSize = true;
            this->label_customers_current_order_delivery_address->Location = System::Drawing::Point(24, 79);
            this->label_customers_current_order_delivery_address->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_customers_current_order_delivery_address->Name = L"label_customers_current_order_delivery_address";
            this->label_customers_current_order_delivery_address->Size = System::Drawing::Size(20, 20);
            this->label_customers_current_order_delivery_address->TabIndex = 1;
            this->label_customers_current_order_delivery_address->Text = L" f";
            // 
            // button_customer_add_order
            // 
            this->button_customer_add_order->Location = System::Drawing::Point(561, 298);
            this->button_customer_add_order->Margin = System::Windows::Forms::Padding(2);
            this->button_customer_add_order->Name = L"button_customer_add_order";
            this->button_customer_add_order->Size = System::Drawing::Size(88, 38);
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
            this->dataGridView_customer_orders->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView_customer_orders->MultiSelect = false;
            this->dataGridView_customer_orders->Name = L"dataGridView_customer_orders";
            this->dataGridView_customer_orders->ReadOnly = true;
            this->dataGridView_customer_orders->RowHeadersWidth = 62;
            this->dataGridView_customer_orders->RowTemplate->Height = 28;
            this->dataGridView_customer_orders->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_orders->Size = System::Drawing::Size(668, 321);
            this->dataGridView_customer_orders->TabIndex = 0;
            this->dataGridView_customer_orders->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_customer_orders_selectionChanged);
            // 
            // button_customers_reload
            // 
            this->button_customers_reload->Location = System::Drawing::Point(1122, 152);
            this->button_customers_reload->Margin = System::Windows::Forms::Padding(2);
            this->button_customers_reload->Name = L"button_customers_reload";
            this->button_customers_reload->Size = System::Drawing::Size(100, 38);
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
            this->groupBox_customer_information->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_customer_information->Name = L"groupBox_customer_information";
            this->groupBox_customer_information->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_customer_information->Size = System::Drawing::Size(545, 166);
            this->groupBox_customer_information->TabIndex = 3;
            this->groupBox_customer_information->TabStop = false;
            this->groupBox_customer_information->Text = L"Customer Information";
            // 
            // label_customer_birth_date
            // 
            this->label_customer_birth_date->AutoSize = true;
            this->label_customer_birth_date->Location = System::Drawing::Point(312, 30);
            this->label_customer_birth_date->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_customer_birth_date->Name = L"label_customer_birth_date";
            this->label_customer_birth_date->Size = System::Drawing::Size(89, 20);
            this->label_customer_birth_date->TabIndex = 8;
            this->label_customer_birth_date->Text = L"Birth date";
            // 
            // dateTimePicker_customer_birth_date
            // 
            this->dateTimePicker_customer_birth_date->Location = System::Drawing::Point(316, 52);
            this->dateTimePicker_customer_birth_date->Margin = System::Windows::Forms::Padding(2);
            this->dateTimePicker_customer_birth_date->Name = L"dateTimePicker_customer_birth_date";
            this->dateTimePicker_customer_birth_date->Size = System::Drawing::Size(196, 27);
            this->dateTimePicker_customer_birth_date->TabIndex = 7;
            // 
            // button_delete_customer
            // 
            this->button_delete_customer->Location = System::Drawing::Point(425, 120);
            this->button_delete_customer->Margin = System::Windows::Forms::Padding(2);
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
            this->button_modify_customer->Margin = System::Windows::Forms::Padding(2);
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
            this->label_last_name_customer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_last_name_customer->Name = L"label_last_name_customer";
            this->label_last_name_customer->Size = System::Drawing::Size(97, 20);
            this->label_last_name_customer->TabIndex = 4;
            this->label_last_name_customer->Text = L"Last Name";
            // 
            // label_first_name_customer
            // 
            this->label_first_name_customer->AutoSize = true;
            this->label_first_name_customer->Location = System::Drawing::Point(24, 30);
            this->label_first_name_customer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_first_name_customer->Name = L"label_first_name_customer";
            this->label_first_name_customer->Size = System::Drawing::Size(97, 20);
            this->label_first_name_customer->TabIndex = 3;
            this->label_first_name_customer->Text = L"First Name";
            // 
            // textBox_first_name_customer
            // 
            this->textBox_first_name_customer->Location = System::Drawing::Point(28, 52);
            this->textBox_first_name_customer->Margin = System::Windows::Forms::Padding(2);
            this->textBox_first_name_customer->Name = L"textBox_first_name_customer";
            this->textBox_first_name_customer->Size = System::Drawing::Size(240, 27);
            this->textBox_first_name_customer->TabIndex = 1;
            // 
            // textBox_last_name_customer
            // 
            this->textBox_last_name_customer->Location = System::Drawing::Point(28, 124);
            this->textBox_last_name_customer->Margin = System::Windows::Forms::Padding(2);
            this->textBox_last_name_customer->Name = L"textBox_last_name_customer";
            this->textBox_last_name_customer->Size = System::Drawing::Size(240, 27);
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
            this->dataGridView_customers->Location = System::Drawing::Point(8, 8);
            this->dataGridView_customers->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView_customers->MinimumSize = System::Drawing::Size(999, 112);
            this->dataGridView_customers->MultiSelect = false;
            this->dataGridView_customers->Name = L"dataGridView_customers";
            this->dataGridView_customers->ReadOnly = true;
            this->dataGridView_customers->RowHeadersWidth = 62;
            this->dataGridView_customers->RowTemplate->Height = 28;
            this->dataGridView_customers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customers->Size = System::Drawing::Size(1238, 188);
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
            this->tab_employee->Location = System::Drawing::Point(4, 28);
            this->tab_employee->Margin = System::Windows::Forms::Padding(2);
            this->tab_employee->Name = L"tab_employee";
            this->tab_employee->Padding = System::Windows::Forms::Padding(2);
            this->tab_employee->Size = System::Drawing::Size(1250, 719);
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
            this->groupBox_employee_address->Location = System::Drawing::Point(8, 372);
            this->groupBox_employee_address->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_employee_address->Name = L"groupBox_employee_address";
            this->groupBox_employee_address->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_employee_address->Size = System::Drawing::Size(545, 205);
            this->groupBox_employee_address->TabIndex = 11;
            this->groupBox_employee_address->TabStop = false;
            this->groupBox_employee_address->Text = L"Employee Address";
            // 
            // textBox_employee_address_street_number
            // 
            this->textBox_employee_address_street_number->Location = System::Drawing::Point(316, 122);
            this->textBox_employee_address_street_number->Margin = System::Windows::Forms::Padding(2);
            this->textBox_employee_address_street_number->Name = L"textBox_employee_address_street_number";
            this->textBox_employee_address_street_number->Size = System::Drawing::Size(198, 27);
            this->textBox_employee_address_street_number->TabIndex = 11;
            // 
            // textBox_employee_address_postal_code
            // 
            this->textBox_employee_address_postal_code->Location = System::Drawing::Point(315, 52);
            this->textBox_employee_address_postal_code->Margin = System::Windows::Forms::Padding(2);
            this->textBox_employee_address_postal_code->Name = L"textBox_employee_address_postal_code";
            this->textBox_employee_address_postal_code->Size = System::Drawing::Size(198, 27);
            this->textBox_employee_address_postal_code->TabIndex = 10;
            // 
            // button_employee_modify_address
            // 
            this->button_employee_modify_address->Location = System::Drawing::Point(425, 165);
            this->button_employee_modify_address->Margin = System::Windows::Forms::Padding(2);
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
            this->label_employee_address_street_number->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_employee_address_street_number->Name = L"label_employee_address_street_number";
            this->label_employee_address_street_number->Size = System::Drawing::Size(128, 20);
            this->label_employee_address_street_number->TabIndex = 9;
            this->label_employee_address_street_number->Text = L"Street Number";
            // 
            // label_employee_address_postal_code
            // 
            this->label_employee_address_postal_code->AutoSize = true;
            this->label_employee_address_postal_code->Location = System::Drawing::Point(312, 30);
            this->label_employee_address_postal_code->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_employee_address_postal_code->Name = L"label_employee_address_postal_code";
            this->label_employee_address_postal_code->Size = System::Drawing::Size(104, 20);
            this->label_employee_address_postal_code->TabIndex = 8;
            this->label_employee_address_postal_code->Text = L"Postal code";
            // 
            // label_employee_address_street
            // 
            this->label_employee_address_street->AutoSize = true;
            this->label_employee_address_street->Location = System::Drawing::Point(24, 101);
            this->label_employee_address_street->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_employee_address_street->Name = L"label_employee_address_street";
            this->label_employee_address_street->Size = System::Drawing::Size(58, 20);
            this->label_employee_address_street->TabIndex = 4;
            this->label_employee_address_street->Text = L"Street";
            // 
            // label_employee_address_city
            // 
            this->label_employee_address_city->AutoSize = true;
            this->label_employee_address_city->Location = System::Drawing::Point(24, 30);
            this->label_employee_address_city->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_employee_address_city->Name = L"label_employee_address_city";
            this->label_employee_address_city->Size = System::Drawing::Size(40, 20);
            this->label_employee_address_city->TabIndex = 3;
            this->label_employee_address_city->Text = L"City";
            // 
            // textBox_employee_address_city
            // 
            this->textBox_employee_address_city->Location = System::Drawing::Point(28, 52);
            this->textBox_employee_address_city->Margin = System::Windows::Forms::Padding(2);
            this->textBox_employee_address_city->Name = L"textBox_employee_address_city";
            this->textBox_employee_address_city->Size = System::Drawing::Size(240, 27);
            this->textBox_employee_address_city->TabIndex = 1;
            // 
            // textBox_employee_address_street
            // 
            this->textBox_employee_address_street->Location = System::Drawing::Point(28, 122);
            this->textBox_employee_address_street->Margin = System::Windows::Forms::Padding(2);
            this->textBox_employee_address_street->Name = L"textBox_employee_address_street";
            this->textBox_employee_address_street->Size = System::Drawing::Size(240, 27);
            this->textBox_employee_address_street->TabIndex = 2;
            // 
            // button_employee_reload
            // 
            this->button_employee_reload->Location = System::Drawing::Point(1122, 152);
            this->button_employee_reload->Margin = System::Windows::Forms::Padding(2);
            this->button_employee_reload->Name = L"button_employee_reload";
            this->button_employee_reload->Size = System::Drawing::Size(100, 38);
            this->button_employee_reload->TabIndex = 11;
            this->button_employee_reload->Text = L"Reload";
            this->button_employee_reload->UseVisualStyleBackColor = true;
            this->button_employee_reload->Click += gcnew System::EventHandler(this, &UserInterface::button_employee_reload_Click);
            // 
            // button_create_employee
            // 
            this->button_create_employee->Location = System::Drawing::Point(908, 152);
            this->button_create_employee->Margin = System::Windows::Forms::Padding(2);
            this->button_create_employee->Name = L"button_create_employee";
            this->button_create_employee->Size = System::Drawing::Size(195, 38);
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
            this->groupBox_employee_manager->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_employee_manager->Name = L"groupBox_employee_manager";
            this->groupBox_employee_manager->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_employee_manager->Size = System::Drawing::Size(688, 121);
            this->groupBox_employee_manager->TabIndex = 6;
            this->groupBox_employee_manager->TabStop = false;
            this->groupBox_employee_manager->Text = L"Employee Manager ";
            // 
            // button_employee_remove_manager
            // 
            this->button_employee_remove_manager->Location = System::Drawing::Point(109, 71);
            this->button_employee_remove_manager->Margin = System::Windows::Forms::Padding(2);
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
            this->button_employee_select_manager->Margin = System::Windows::Forms::Padding(2);
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
            this->label_employee_manager_name->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_employee_manager_name->Name = L"label_employee_manager_name";
            this->label_employee_manager_name->Size = System::Drawing::Size(234, 20);
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
            this->dataGridView_employee->Location = System::Drawing::Point(8, 8);
            this->dataGridView_employee->Margin = System::Windows::Forms::Padding(2);
            this->dataGridView_employee->MinimumSize = System::Drawing::Size(999, 112);
            this->dataGridView_employee->MultiSelect = false;
            this->dataGridView_employee->Name = L"dataGridView_employee";
            this->dataGridView_employee->ReadOnly = true;
            this->dataGridView_employee->RowHeadersWidth = 62;
            this->dataGridView_employee->RowTemplate->Height = 28;
            this->dataGridView_employee->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_employee->Size = System::Drawing::Size(1238, 188);
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
            this->groupBox_employee_information->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_employee_information->Name = L"groupBox_employee_information";
            this->groupBox_employee_information->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_employee_information->Size = System::Drawing::Size(545, 166);
            this->groupBox_employee_information->TabIndex = 3;
            this->groupBox_employee_information->TabStop = false;
            this->groupBox_employee_information->Text = L"Employee Information";
            // 
            // button_delete_employee
            // 
            this->button_delete_employee->Location = System::Drawing::Point(425, 120);
            this->button_delete_employee->Margin = System::Windows::Forms::Padding(2);
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
            this->button_modify_employee->Margin = System::Windows::Forms::Padding(2);
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
            this->label_employee_hiring_date->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_employee_hiring_date->Name = L"label_employee_hiring_date";
            this->label_employee_hiring_date->Size = System::Drawing::Size(98, 20);
            this->label_employee_hiring_date->TabIndex = 8;
            this->label_employee_hiring_date->Text = L"Hiring date";
            // 
            // dateTimePicker_employee_hiring_date
            // 
            this->dateTimePicker_employee_hiring_date->Location = System::Drawing::Point(316, 52);
            this->dateTimePicker_employee_hiring_date->Margin = System::Windows::Forms::Padding(2);
            this->dateTimePicker_employee_hiring_date->Name = L"dateTimePicker_employee_hiring_date";
            this->dateTimePicker_employee_hiring_date->Size = System::Drawing::Size(196, 27);
            this->dateTimePicker_employee_hiring_date->TabIndex = 7;
            // 
            // label_last_name_employee
            // 
            this->label_last_name_employee->AutoSize = true;
            this->label_last_name_employee->Location = System::Drawing::Point(24, 101);
            this->label_last_name_employee->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_last_name_employee->Name = L"label_last_name_employee";
            this->label_last_name_employee->Size = System::Drawing::Size(97, 20);
            this->label_last_name_employee->TabIndex = 4;
            this->label_last_name_employee->Text = L"Last Name";
            // 
            // label_first_name_employee
            // 
            this->label_first_name_employee->AutoSize = true;
            this->label_first_name_employee->Location = System::Drawing::Point(24, 30);
            this->label_first_name_employee->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_first_name_employee->Name = L"label_first_name_employee";
            this->label_first_name_employee->Size = System::Drawing::Size(97, 20);
            this->label_first_name_employee->TabIndex = 3;
            this->label_first_name_employee->Text = L"First Name";
            // 
            // textBox_first_name_employee
            // 
            this->textBox_first_name_employee->Location = System::Drawing::Point(28, 52);
            this->textBox_first_name_employee->Margin = System::Windows::Forms::Padding(2);
            this->textBox_first_name_employee->Name = L"textBox_first_name_employee";
            this->textBox_first_name_employee->Size = System::Drawing::Size(240, 27);
            this->textBox_first_name_employee->TabIndex = 1;
            // 
            // textBox_last_name_employee
            // 
            this->textBox_last_name_employee->Location = System::Drawing::Point(28, 124);
            this->textBox_last_name_employee->Margin = System::Windows::Forms::Padding(2);
            this->textBox_last_name_employee->Name = L"textBox_last_name_employee";
            this->textBox_last_name_employee->Size = System::Drawing::Size(240, 27);
            this->textBox_last_name_employee->TabIndex = 2;
            // 
            // tab_statistics
            // 
            this->tab_statistics->Controls->Add(this->groupBox_worst_products);
            this->tab_statistics->Controls->Add(this->groupBox_bestsellers);
            this->tab_statistics->Controls->Add(this->groupBox_product_below_threshold);
            this->tab_statistics->Controls->Add(this->groupBox_total_purchases_by_customers);
            this->tab_statistics->Controls->Add(this->groupBox_general_stats);
            this->tab_statistics->Location = System::Drawing::Point(4, 28);
            this->tab_statistics->Margin = System::Windows::Forms::Padding(2);
            this->tab_statistics->Name = L"tab_statistics";
            this->tab_statistics->Size = System::Drawing::Size(1250, 719);
            this->tab_statistics->TabIndex = 4;
            this->tab_statistics->Text = L"Statistics";
            this->tab_statistics->UseVisualStyleBackColor = true;
            // 
            // groupBox_worst_products
            // 
            this->groupBox_worst_products->Controls->Add(this->dataGridView4);
            this->groupBox_worst_products->Location = System::Drawing::Point(612, 351);
            this->groupBox_worst_products->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_worst_products->Name = L"groupBox_worst_products";
            this->groupBox_worst_products->Padding = System::Windows::Forms::Padding(2);
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
            this->dataGridView4->Margin = System::Windows::Forms::Padding(2);
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
            this->groupBox_bestsellers->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_bestsellers->Name = L"groupBox_bestsellers";
            this->groupBox_bestsellers->Padding = System::Windows::Forms::Padding(2);
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
            this->dataGridView3->Margin = System::Windows::Forms::Padding(2);
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
            this->groupBox_product_below_threshold->Location = System::Drawing::Point(8, 178);
            this->groupBox_product_below_threshold->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_product_below_threshold->Name = L"groupBox_product_below_threshold";
            this->groupBox_product_below_threshold->Padding = System::Windows::Forms::Padding(2);
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
            this->dataGridView2->Margin = System::Windows::Forms::Padding(2);
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
            this->groupBox_total_purchases_by_customers->Location = System::Drawing::Point(612, 178);
            this->groupBox_total_purchases_by_customers->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_total_purchases_by_customers->Name = L"groupBox_total_purchases_by_customers";
            this->groupBox_total_purchases_by_customers->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_total_purchases_by_customers->Size = System::Drawing::Size(632, 168);
            this->groupBox_total_purchases_by_customers->TabIndex = 9;
            this->groupBox_total_purchases_by_customers->TabStop = false;
            this->groupBox_total_purchases_by_customers->Text = L"Total purchases by customers";
            // 
            // button_search_customer
            // 
            this->button_search_customer->Location = System::Drawing::Point(525, 128);
            this->button_search_customer->Margin = System::Windows::Forms::Padding(2);
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
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(97, 20);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Last Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(6, 121);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(97, 20);
            this->label2->TabIndex = 7;
            this->label2->Text = L"First Name";
            // 
            // textBox_fname_statistics
            // 
            this->textBox_fname_statistics->Location = System::Drawing::Point(6, 136);
            this->textBox_fname_statistics->Margin = System::Windows::Forms::Padding(2);
            this->textBox_fname_statistics->Name = L"textBox_fname_statistics";
            this->textBox_fname_statistics->Size = System::Drawing::Size(240, 27);
            this->textBox_fname_statistics->TabIndex = 5;
            // 
            // textBox_lname_statistics
            // 
            this->textBox_lname_statistics->Location = System::Drawing::Point(262, 136);
            this->textBox_lname_statistics->Margin = System::Windows::Forms::Padding(2);
            this->textBox_lname_statistics->Name = L"textBox_lname_statistics";
            this->textBox_lname_statistics->Size = System::Drawing::Size(240, 27);
            this->textBox_lname_statistics->TabIndex = 6;
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(6, 21);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
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
            this->groupBox_general_stats->Location = System::Drawing::Point(8, 2);
            this->groupBox_general_stats->Margin = System::Windows::Forms::Padding(2);
            this->groupBox_general_stats->Name = L"groupBox_general_stats";
            this->groupBox_general_stats->Padding = System::Windows::Forms::Padding(2);
            this->groupBox_general_stats->Size = System::Drawing::Size(1241, 168);
            this->groupBox_general_stats->TabIndex = 7;
            this->groupBox_general_stats->TabStop = false;
            this->groupBox_general_stats->Text = L"General statistics";
            // 
            // label_simulate_stock_value
            // 
            this->label_simulate_stock_value->AutoSize = true;
            this->label_simulate_stock_value->Location = System::Drawing::Point(6, 142);
            this->label_simulate_stock_value->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_simulate_stock_value->Name = L"label_simulate_stock_value";
            this->label_simulate_stock_value->Size = System::Drawing::Size(390, 20);
            this->label_simulate_stock_value->TabIndex = 6;
            this->label_simulate_stock_value->Text = L"This text is for the simulation of the stock value";
            // 
            // label_purchase_stock_value
            // 
            this->label_purchase_stock_value->AutoSize = true;
            this->label_purchase_stock_value->Location = System::Drawing::Point(6, 109);
            this->label_purchase_stock_value->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_purchase_stock_value->Name = L"label_purchase_stock_value";
            this->label_purchase_stock_value->Size = System::Drawing::Size(330, 20);
            this->label_purchase_stock_value->TabIndex = 5;
            this->label_purchase_stock_value->Text = L"This text is for the purchase stock value";
            // 
            // label_commercial_stock_value
            // 
            this->label_commercial_stock_value->AutoSize = true;
            this->label_commercial_stock_value->Location = System::Drawing::Point(6, 79);
            this->label_commercial_stock_value->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_commercial_stock_value->Name = L"label_commercial_stock_value";
            this->label_commercial_stock_value->Size = System::Drawing::Size(348, 20);
            this->label_commercial_stock_value->TabIndex = 4;
            this->label_commercial_stock_value->Text = L"This text is for the commercial stock value";
            // 
            // label_monthly_turnover
            // 
            this->label_monthly_turnover->AutoSize = true;
            this->label_monthly_turnover->Location = System::Drawing::Point(6, 48);
            this->label_monthly_turnover->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_monthly_turnover->Name = L"label_monthly_turnover";
            this->label_monthly_turnover->Size = System::Drawing::Size(296, 20);
            this->label_monthly_turnover->TabIndex = 3;
            this->label_monthly_turnover->Text = L"This text is for the monthly turnover";
            // 
            // label_avg_basket
            // 
            this->label_avg_basket->AutoSize = true;
            this->label_avg_basket->Location = System::Drawing::Point(6, 21);
            this->label_avg_basket->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label_avg_basket->Name = L"label_avg_basket";
            this->label_avg_basket->Size = System::Drawing::Size(285, 20);
            this->label_avg_basket->TabIndex = 2;
            this->label_avg_basket->Text = L"This text is for the average basket";
            // 
            // button_customer_order_modify_items
            // 
            this->button_customer_order_modify_items->Location = System::Drawing::Point(194, 120);
            this->button_customer_order_modify_items->Margin = System::Windows::Forms::Padding(2);
            this->button_customer_order_modify_items->Name = L"button_customer_order_modify_items";
            this->button_customer_order_modify_items->Size = System::Drawing::Size(124, 30);
            this->button_customer_order_modify_items->TabIndex = 10;
            this->button_customer_order_modify_items->Text = L"Modify items";
            this->button_customer_order_modify_items->UseVisualStyleBackColor = true;
            this->button_customer_order_modify_items->Click += gcnew System::EventHandler(this, &UserInterface::button_customer_order_modify_items_Click);
            // 
            // UserInterface
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1258, 751);
            this->Controls->Add(this->tabController);
            this->Font = (gcnew System::Drawing::Font(L"Inter", 10));
            this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->MaximumSize = System::Drawing::Size(1276, 798);
            this->MinimumSize = System::Drawing::Size(1276, 798);
            this->Name = L"UserInterface";
            this->Text = L"Company management";
            this->Load += gcnew System::EventHandler(this, &UserInterface::UserInterface_Load);
            this->tabController->ResumeLayout(false);
            this->tab_inventory->ResumeLayout(false);
            this->groupBox_product_prices->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_product_prices))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_inventory))->EndInit();
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
           
            OnTabSelectedIndexChanged(sender, e);
        }

        // Executes code when a specific tab is opened
    private:
        void OnTabSelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            switch(this->tabController->SelectedIndex)
            {
            case 0: // Inventory
                refresh_products_datagrid();
                return;
            case 1: // Customers
                refresh_customers_datagrid();
                return;
            case 2: // Employee
                refresh_employee_datagrid();
                return;
            case 3: // Statistics
                return;
            default:
                return;
            }
        }
        
    // ### Inventory tab ###
    private:
        void refresh_products_datagrid()
        {
            this->dataGridView_inventory->Refresh();
            this->dataGridView_inventory->DataSource = SQLserver->SQL_getProductList();

            this->dataGridView_inventory->Columns["id_product"]->Width = 40;
            this->dataGridView_inventory->Columns["id_product"]->HeaderText = "ID";
            this->dataGridView_inventory->Columns["product_name"]->HeaderText = "Name";
            this->dataGridView_inventory->Columns["amount_in_stock"]->HeaderText = "Stock";
            this->dataGridView_inventory->Columns["reorder_threshold"]->HeaderText = "Reorder at";
            this->dataGridView_inventory->Columns["vat_percentage"]->HeaderText = "VAT %";
        }


        void refresh_product_information()
        {
            this->groupBox1->Text = "Product " + selected_product->getID() + " Information";

            if (selected_product->getAmountInStock() > selected_product->getReorderThreshold())
            {
                this->label_product_reorder->Visible = false;
            }
            else
            {
                this->label_product_reorder->Visible = true;
            }
            
            this->textBox_product_name->Text = selected_product->getProductName();
            this->textBox_product_stock->Text = selected_product->getAmountInStock().ToString();
            this->textBox_product_reorder_threshold->Text = selected_product->getReorderThreshold().ToString();
            this->textBox_product_vat->Text = selected_product->getVATPercentage().ToString();
        }

        void refresh_product_prices_datagrid()
        {
            this->groupBox_product_prices->Text = "Product " + selected_product->getID() + " Prices";

            // Refresh datagrid
            this->dataGridView_product_prices->Refresh();
            this->dataGridView_product_prices->DataSource = this->selected_product->getProductPrices();

            // Configure columns
            this->dataGridView_product_prices->Columns["id_product_price"]->Visible = false;
            this->dataGridView_product_prices->Columns["id_product"]->Visible = false;
            
            this->dataGridView_product_prices->Sort(this->dataGridView_product_prices->Columns["price_date"], System::ComponentModel::ListSortDirection::Descending);

            this->dataGridView_product_prices->Columns["price_date"]->HeaderText = "Price date";
            this->dataGridView_product_prices->Columns["price_excl_tax"]->HeaderText = "Price";
            this->dataGridView_product_prices->Columns["min_order_amount"]->HeaderText = "Minimum amount";
            this->dataGridView_product_prices->Columns["color_rgb_r"]->HeaderText = "Color R";
            this->dataGridView_product_prices->Columns["color_rgb_g"]->HeaderText = "Color G";
            this->dataGridView_product_prices->Columns["color_rgb_b"]->HeaderText = "Color B";

            if (dataGridView_product_prices->SelectedRows->Count == 0)
            {
                this->button_delete_product_prices->Visible = false;
                this->button_modify_product_prices->Visible = false;
            }
            else
            {
                this->button_delete_product_prices->Visible = true;
                this->button_modify_product_prices->Visible = true;
            }
        }

        // Events
        void dataGridView_inventory_selectionChanged(Object^ sender, EventArgs^ event_args)
        {
            // Return if no columns are selected
            if (dataGridView_inventory->SelectedRows->Count == 0)
            {
                return;
            }
            
            String^ selectedIDstring = this->dataGridView_inventory->SelectedRows[0]->Cells["id_product"]->Value->ToString();

            
            selected_product = gcnew Product(System::Convert::ToInt32(selectedIDstring));

            refresh_product_information();
            refresh_product_prices_datagrid();
        }

        private: System::Void button_create_product_Click(System::Object^ sender, System::EventArgs^ e) {
            editProductPrompt^ prompt = gcnew editProductPrompt("Create a product");

            if(prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                Product^ new_product = gcnew Product(prompt->product_name, prompt->amount_in_stock, prompt->reorder_threshold, prompt->vat_percentage);
                
                refresh_products_datagrid();
            }
            
        }
    
        private: System::Void button_modify_product_Click(System::Object^ sender, System::EventArgs^ e) {
            this->selected_product->setProductName(this->textBox_product_name->Text->Trim());
            this->selected_product->setAmountInStock(System::Convert::ToInt32(this->textBox_product_stock->Text->Trim()));
            this->selected_product->setReorderThreshold(System::Convert::ToInt32(this->textBox_product_reorder_threshold->Text->Trim()));
            this->selected_product->setVATPercentage(System::Convert::ToSingle(this->textBox_product_vat->Text->Trim()));

            this->selected_product->modify_product_in_DB();

            refresh_products_datagrid();
        }
        
        private: System::Void button_delete_product_Click(System::Object^ sender, System::EventArgs^ e) {
            this->selected_product->delete_product_from_DB();

            refresh_products_datagrid();
            }

        private: System::Void button_products_reload_Click(System::Object^ sender, System::EventArgs^ e) {
            refresh_products_datagrid();
        }

        private: System::Void dataGridView_product_prices_selectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
            if (dataGridView_product_prices->SelectedRows->Count == 0)
            {
                return;
            }
            
            this->selected_product_price = gcnew Product_price(System::Convert::ToInt32(this->dataGridView_product_prices->SelectedRows[0]->Cells["id_product_price"]->Value));
        }
        
        private: System::Void button_reload_product_price_Click(System::Object^ sender, System::EventArgs^ e) {
            refresh_product_prices_datagrid();
            }
        
            // Events
        private: System::Void button_add_product_price_Click(System::Object^ sender, System::EventArgs^ e) {
                editProductPrices^ prompt = gcnew editProductPrices("Create a product");

                if(prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    Product_price^ new_product_price = gcnew Product_price(selected_product->getID(), prompt->minimum_amount, prompt->price_excluding_tax, prompt->price_date, prompt->color_rgb_r, prompt->color_rgb_g, prompt->color_rgb_b);
                        
                    refresh_products_datagrid();
                }
                
            }
        

    private: System::Void button_edit_product_price_Click(System::Object^ sender, System::EventArgs^ e) {
        editProductPrices^ prompt = gcnew editProductPrices("Edit Product Price " + this->selected_product_price->getID(), this->selected_product_price->getMinOrderAmount(), this->selected_product_price->getPriceExclTax(), this->selected_product_price->getPriceDate(), this->selected_product_price->getColorRgbR(), this->selected_product_price->getColorRgbG(), this->selected_product_price->getColorRgbB());
        if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            this->selected_product_price->setMinOrdeAmount(prompt->minimum_amount);
            this->selected_product_price->setPriceExclTax(prompt->price_excluding_tax);
            this->selected_product_price->setPriceDate(prompt->price_date);
            this->selected_product_price->setColorRgbR(prompt->color_rgb_r);
            this->selected_product_price->setColorRgbG(prompt->color_rgb_g);
            this->selected_product_price->setColorRgbB(prompt->color_rgb_b);

            this->selected_product_price->modify_product_price_in_DB();

            refresh_product_prices_datagrid();
        }
    
    }


    private: System::Void button_delete_product_price_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->selected_product_price->delete_product_price_from_DB();

            refresh_product_prices_datagrid();
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
            this->selected_customer_order = gcnew Order(Convert::ToInt32(this->dataGridView_customer_orders->SelectedRows[0]->Cells["id_order"]->Value->ToString()));

            
            this->groupBox_customer_currently_selected_order->Visible = true;

            
            Address^ currently_selected_order_billing_address = gcnew Address(selected_customer_order->getBillingAddress());
            
            label_customers_current_order_billing_address->Text = "Billing address : " + currently_selected_order_billing_address->getStreetNumber() + " " + currently_selected_order_billing_address->getStreet() + ", " + currently_selected_order_billing_address->getPostalCode() + " " + currently_selected_order_billing_address->getCity();
            
            Address^ currently_selected_order_delivery_address = gcnew Address(selected_customer_order->getDeliveryAddress());

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
        editOrderPrompt^ prompt = gcnew editOrderPrompt(this->selected_customer->getID(), this->selected_customer->getFirstName() + " " + this->selected_customer->getLastName() + " - Edit order", selected_customer_order->getOrderDate(), selected_customer_order->getDeliveryDate(), selected_customer_order->getDiscoutPercentage(), selected_customer_order->getBillingAddress(), selected_customer_order->getDeliveryAddress());

        if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            selected_customer_order->setOrderDate(prompt->new_order_order_date);
            selected_customer_order->setDeliveryDate(prompt->new_order_delivery_date);
            selected_customer_order->setDiscountPercentage(prompt->new_order_discount_percentage);
            selected_customer_order->setBillingAddress(prompt->new_order_id_billing_address);
            selected_customer_order->setDeliveryAddress(prompt->new_order_id_delivery_address);

            selected_customer_order->modify_order_in_DB();

            refresh_customer_orders_datagrid();
        }
    }

    private: System::Void button_customer_delete_order_Click(System::Object^ sender, System::EventArgs^ e) {
        Order ^selected_order = gcnew Order(Convert::ToInt32(this->dataGridView_customer_orders->SelectedRows[0]->Cells["id_order"]->Value->ToString()));

        selected_order->delete_order_from_DB();

        refresh_customer_orders_datagrid();
    }

    private: System::Void button_customer_order_modify_items_Click(System::Object^ sender, System::EventArgs^ e) {
        editProductsInOrder^ prompt = gcnew editProductsInOrder(this->selected_customer_order->getID());
        
        prompt->ShowDialog();

        refresh_customer_orders_datagrid();
    }


    // Billing address stuff
    void dataGridView_customer_billing_addresses_selectionChanged(Object^ sender, EventArgs^ event_args)
    {
        if(dataGridView_customer_billing_addresses->SelectedRows->Count == 0)
        {
            this->button_customer_modify_billing_address->Visible = false;
            this->button_customer_delete_billing_address->Visible = false;
            return;
        }
        this->button_customer_modify_billing_address->Visible = true;
        this->button_customer_delete_billing_address->Visible = true;

        this->currentlySelectedBillingAddress = gcnew Address(Convert::ToInt32(this->dataGridView_customer_billing_addresses->SelectedRows[0]->Cells["id_address"]->Value->ToString()));
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
        this->selected_customer->deleteBillingAddressFromCustomer(currentlySelectedBillingAddress->getID());

        currentlySelectedBillingAddress->delete_address_from_DB();

        refresh_customer_billing_addresses_datagrid();
        
    }

    // Delivery address stuff
    void dataGridView_customer_delivery_addresses_selectionChanged(Object^ sender, EventArgs^ event_args)
    {
        if (dataGridView_customer_delivery_addresses->SelectedRows->Count == 0)
        {
            this->button_customer_modify_delivery_address->Visible = false;
            this->button_customer_delete_delivery_address->Visible = false;
            return;
            
        }
        this->button_customer_modify_delivery_address->Visible = true;
        this->button_customer_delete_delivery_address->Visible = true;
        
        this->currentlySelectedDeliveryAddress = gcnew Address(Convert::ToInt32(this->dataGridView_customer_delivery_addresses->SelectedRows[0]->Cells["id_address"]->Value->ToString()));
    }
    
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