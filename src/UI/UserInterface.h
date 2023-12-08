#pragma once

#include "editAddressPrompt.h"
#include "../SQL/SQLservices.h"
#include "../Customer.h"
#include "createCustomerPrompt.h"
#include "../Employee.h"
#include "../Address.h"


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
        System::Windows::Forms::GroupBox^ groupBox_employee;
        
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
    private: System::Windows::Forms::GroupBox^ groupBox_create_customer;
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



    private:


    private:
        System::Windows::Forms::Label^ label_customer_birth_date;
    private: System::Windows::Forms::Label^ label_id_address_employee;
    private: System::Windows::Forms::Label^ label_id_manager_employee;
    private: System::Windows::Forms::TextBox^ textBox_id_manager_employee;
    private: System::Windows::Forms::TextBox^ textBox_id_address_employee;

    private:
        System::Windows::Forms::Label^ label_employee_hiring_date;

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
            this->tab_inventory = (gcnew System::Windows::Forms::TabPage());
            this->tab_customers = (gcnew System::Windows::Forms::TabPage());
            this->groupBox_delivery_addresses = (gcnew System::Windows::Forms::GroupBox());
            this->button_customer_delete_delivery_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_modify_delivery_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_add_delivery_address = (gcnew System::Windows::Forms::Button());
            this->dataGridView_customer_delivery_addresses = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_customer_billing_addresses = (gcnew System::Windows::Forms::GroupBox());
            this->button_customer_delete_billing_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_modify_billing_address = (gcnew System::Windows::Forms::Button());
            this->button_customer_add_billing_address = (gcnew System::Windows::Forms::Button());
            this->dataGridView_customer_billing_addresses = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_create_customer = (gcnew System::Windows::Forms::GroupBox());
            this->button_create_customer = (gcnew System::Windows::Forms::Button());
            this->groupBox_customer_orders = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView_customer_orders = (gcnew System::Windows::Forms::DataGridView());
            this->button_customers_reload = (gcnew System::Windows::Forms::Button());
            this->groupBox_customer_information = (gcnew System::Windows::Forms::GroupBox());
            this->label_customer_birth_date = (gcnew System::Windows::Forms::Label());
            this->label_employee_hiring_date = (gcnew System::Windows::Forms::Label());
            this->dateTimePicker_customer_birth_date = (gcnew System::Windows::Forms::DateTimePicker());
            this->dateTimePicker_employee_hiring_date = (gcnew System::Windows::Forms::DateTimePicker());
            this->button_delete_customer = (gcnew System::Windows::Forms::Button());
            this->button_modify_customer = (gcnew System::Windows::Forms::Button());
            this->label_last_name_customer = (gcnew System::Windows::Forms::Label());
            this->label_first_name_customer = (gcnew System::Windows::Forms::Label());
            this->textBox_first_name_customer = (gcnew System::Windows::Forms::TextBox());
            this->textBox_last_name_customer = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView_customers = (gcnew System::Windows::Forms::DataGridView());
            this->tab_employee = (gcnew System::Windows::Forms::TabPage());
            this->dataGridView_employee = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_employee = (gcnew System::Windows::Forms::GroupBox());
            this->label_employee_hiring_date = (gcnew System::Windows::Forms::Label());
            this->button_delete_employee = (gcnew System::Windows::Forms::Button());
            this->button_modify_employee = (gcnew System::Windows::Forms::Button());
            this->label_last_name_employee = (gcnew System::Windows::Forms::Label());
            this->label_first_name_employee = (gcnew System::Windows::Forms::Label());
            this->textBox_first_name_employee = (gcnew System::Windows::Forms::TextBox());
            this->textBox_last_name_employee = (gcnew System::Windows::Forms::TextBox());
            this->tab_statistics = (gcnew System::Windows::Forms::TabPage());
            this->label_id_address_employee = (gcnew System::Windows::Forms::Label());
            this->textBox_id_address_employee = (gcnew System::Windows::Forms::TextBox());
            this->textBox_id_manager_employee = (gcnew System::Windows::Forms::TextBox());
            this->label_id_manager_employee = (gcnew System::Windows::Forms::Label());
            this->tabController->SuspendLayout();
            this->tab_customers->SuspendLayout();
            this->groupBox_delivery_addresses->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_delivery_addresses))->BeginInit();
            this->groupBox_customer_billing_addresses->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_billing_addresses))->BeginInit();
            this->groupBox_create_customer->SuspendLayout();
            this->groupBox_customer_orders->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_orders))->BeginInit();
            this->groupBox_customer_information->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customers))->BeginInit();
            this->tab_employee->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_employee))->BeginInit();
            this->groupBox_employee->SuspendLayout();
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
            this->tabController->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tabController->Location = System::Drawing::Point(0, 0);
            this->tabController->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tabController->Name = L"tabController";
            this->tabController->SelectedIndex = 0;
            this->tabController->Size = System::Drawing::Size(1254, 742);
            this->tabController->TabIndex = 0;
            this->tabController->SelectedIndexChanged += gcnew System::EventHandler(this, &UserInterface::OnTabSelectedIndexChanged);
            // 
            // tab_orders
            // 
            this->tab_orders->Location = System::Drawing::Point(4, 33);
            this->tab_orders->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_orders->Name = L"tab_orders";
            this->tab_orders->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_orders->Size = System::Drawing::Size(1246, 705);
            this->tab_orders->TabIndex = 1;
            this->tab_orders->Text = L"Orders";
            this->tab_orders->UseVisualStyleBackColor = true;
            // 
            // tab_inventory
            // 
            this->tab_inventory->Location = System::Drawing::Point(4, 33);
            this->tab_inventory->Name = L"tab_inventory";
            this->tab_inventory->Padding = System::Windows::Forms::Padding(3);
            this->tab_inventory->Size = System::Drawing::Size(1246, 705);
            this->tab_inventory->TabIndex = 2;
            this->tab_inventory->Text = L"Inventory";
            this->tab_inventory->UseVisualStyleBackColor = true;
            // 
            // tab_customers
            // 
            this->tab_customers->Controls->Add(this->groupBox_delivery_addresses);
            this->tab_customers->Controls->Add(this->groupBox_customer_billing_addresses);
            this->tab_customers->Controls->Add(this->groupBox_create_customer);
            this->tab_customers->Controls->Add(this->groupBox_customer_orders);
            this->tab_customers->Controls->Add(this->button_customers_reload);
            this->tab_customers->Controls->Add(this->groupBox_customer_information);
            this->tab_customers->Controls->Add(this->dataGridView_customers);
            this->tab_customers->Location = System::Drawing::Point(4, 33);
            this->tab_customers->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Name = L"tab_customers";
            this->tab_customers->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Size = System::Drawing::Size(1246, 705);
            this->tab_customers->TabIndex = 0;
            this->tab_customers->Text = L"Customers";
            this->tab_customers->UseVisualStyleBackColor = true;
            // 
            // groupBox_delivery_addresses
            // 
            this->groupBox_delivery_addresses->Controls->Add(this->button_customer_delete_delivery_address);
            this->groupBox_delivery_addresses->Controls->Add(this->button_customer_modify_delivery_address);
            this->groupBox_delivery_addresses->Controls->Add(this->button_customer_add_delivery_address);
            this->groupBox_delivery_addresses->Controls->Add(this->dataGridView_customer_delivery_addresses);
            this->groupBox_delivery_addresses->Location = System::Drawing::Point(561, 534);
            this->groupBox_delivery_addresses->Name = L"groupBox_delivery_addresses";
            this->groupBox_delivery_addresses->Size = System::Drawing::Size(679, 169);
            this->groupBox_delivery_addresses->TabIndex = 8;
            this->groupBox_delivery_addresses->TabStop = false;
            this->groupBox_delivery_addresses->Text = L"Delivery addresses";
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
            // dataGridView_customer_delivery_addresses
            // 
            this->dataGridView_customer_delivery_addresses->AllowUserToAddRows = false;
            this->dataGridView_customer_delivery_addresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_delivery_addresses->Location = System::Drawing::Point(6, 21);
            this->dataGridView_customer_delivery_addresses->Name = L"dataGridView_customer_delivery_addresses";
            this->dataGridView_customer_delivery_addresses->ReadOnly = true;
            this->dataGridView_customer_delivery_addresses->RowHeadersWidth = 62;
            this->dataGridView_customer_delivery_addresses->RowTemplate->Height = 28;
            this->dataGridView_customer_delivery_addresses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_delivery_addresses->Size = System::Drawing::Size(667, 99);
            this->dataGridView_customer_delivery_addresses->TabIndex = 1;
            // 
            // groupBox_customer_billing_addresses
            // 
            this->groupBox_customer_billing_addresses->Controls->Add(this->button_customer_delete_billing_address);
            this->groupBox_customer_billing_addresses->Controls->Add(this->button_customer_modify_billing_address);
            this->groupBox_customer_billing_addresses->Controls->Add(this->button_customer_add_billing_address);
            this->groupBox_customer_billing_addresses->Controls->Add(this->dataGridView_customer_billing_addresses);
            this->groupBox_customer_billing_addresses->Location = System::Drawing::Point(8, 534);
            this->groupBox_customer_billing_addresses->Name = L"groupBox_customer_billing_addresses";
            this->groupBox_customer_billing_addresses->Size = System::Drawing::Size(539, 169);
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
            this->dataGridView_customer_billing_addresses->Name = L"dataGridView_customer_billing_addresses";
            this->dataGridView_customer_billing_addresses->ReadOnly = true;
            this->dataGridView_customer_billing_addresses->RowHeadersWidth = 62;
            this->dataGridView_customer_billing_addresses->RowTemplate->Height = 28;
            this->dataGridView_customer_billing_addresses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_billing_addresses->Size = System::Drawing::Size(527, 99);
            this->dataGridView_customer_billing_addresses->TabIndex = 1;
            // 
            // groupBox_create_customer
            // 
            this->groupBox_create_customer->Controls->Add(this->button_create_customer);
            this->groupBox_create_customer->Location = System::Drawing::Point(8, 437);
            this->groupBox_create_customer->Name = L"groupBox_create_customer";
            this->groupBox_create_customer->Size = System::Drawing::Size(539, 91);
            this->groupBox_create_customer->TabIndex = 6;
            this->groupBox_create_customer->TabStop = false;
            this->groupBox_create_customer->Text = L"Create a customer";
            // 
            // button_create_customer
            // 
            this->button_create_customer->Location = System::Drawing::Point(27, 36);
            this->button_create_customer->Name = L"button_create_customer";
            this->button_create_customer->Size = System::Drawing::Size(195, 30);
            this->button_create_customer->TabIndex = 9;
            this->button_create_customer->Text = L"Create a customer";
            this->button_create_customer->UseVisualStyleBackColor = true;
            this->button_create_customer->Click += gcnew System::EventHandler(this, &UserInterface::button_create_customer_Click);
            // 
            // groupBox_customer_orders
            // 
            this->groupBox_customer_orders->Controls->Add(this->dataGridView_customer_orders);
            this->groupBox_customer_orders->Location = System::Drawing::Point(561, 201);
            this->groupBox_customer_orders->Name = L"groupBox_customer_orders";
            this->groupBox_customer_orders->Size = System::Drawing::Size(679, 327);
            this->groupBox_customer_orders->TabIndex = 5;
            this->groupBox_customer_orders->TabStop = false;
            this->groupBox_customer_orders->Text = L"Customer Orders";
            // 
            // dataGridView_customer_orders
            // 
            this->dataGridView_customer_orders->AllowUserToAddRows = false;
            this->dataGridView_customer_orders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_orders->Location = System::Drawing::Point(6, 21);
            this->dataGridView_customer_orders->Name = L"dataGridView_customer_orders";
            this->dataGridView_customer_orders->ReadOnly = true;
            this->dataGridView_customer_orders->RowHeadersWidth = 62;
            this->dataGridView_customer_orders->RowTemplate->Height = 28;
            this->dataGridView_customer_orders->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_customer_orders->Size = System::Drawing::Size(667, 202);
            this->dataGridView_customer_orders->TabIndex = 0;
            // 
            // button_customers_reload
            // 
            this->button_customers_reload->Location = System::Drawing::Point(1128, 152);
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
            this->groupBox_customer_information->Size = System::Drawing::Size(539, 229);
            this->groupBox_customer_information->TabIndex = 3;
            this->groupBox_customer_information->TabStop = false;
            this->groupBox_customer_information->Text = L"Customer Information";
            // 
            // label_customer_birth_date
            // 
            this->label_customer_birth_date->AutoSize = true;
            this->label_customer_birth_date->Location = System::Drawing::Point(312, 30);
            this->label_customer_birth_date->Name = L"label_customer_birth_date";
            this->label_customer_birth_date->Size = System::Drawing::Size(103, 24);
            this->label_customer_birth_date->TabIndex = 8;
            this->label_customer_birth_date->Text = L"Birth date";
            // 
            // dateTimePicker_customer_birth_date
            // 
            this->dateTimePicker_customer_birth_date->Location = System::Drawing::Point(316, 53);
            this->dateTimePicker_customer_birth_date->Name = L"dateTimePicker_customer_birth_date";
            this->dateTimePicker_customer_birth_date->Size = System::Drawing::Size(197, 31);
            this->dateTimePicker_customer_birth_date->TabIndex = 7;
            // 
            // button_delete_customer
            // 
            this->button_delete_customer->Location = System::Drawing::Point(134, 184);
            this->button_delete_customer->Name = L"button_delete_customer";
            this->button_delete_customer->Size = System::Drawing::Size(88, 30);
            this->button_delete_customer->TabIndex = 6;
            this->button_delete_customer->Text = L"Delete";
            this->button_delete_customer->UseVisualStyleBackColor = true;
            this->button_delete_customer->Click += gcnew System::EventHandler(this, &UserInterface::button_delete_customer_Click);
            // 
            // button_modify_customer
            // 
            this->button_modify_customer->Location = System::Drawing::Point(27, 184);
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
            this->label_last_name_customer->Size = System::Drawing::Size(110, 24);
            this->label_last_name_customer->TabIndex = 4;
            this->label_last_name_customer->Text = L"Last Name";
            // 
            // label_first_name_customer
            // 
            this->label_first_name_customer->AutoSize = true;
            this->label_first_name_customer->Location = System::Drawing::Point(24, 30);
            this->label_first_name_customer->Name = L"label_first_name_customer";
            this->label_first_name_customer->Size = System::Drawing::Size(112, 24);
            this->label_first_name_customer->TabIndex = 3;
            this->label_first_name_customer->Text = L"First Name";
            // 
            // textBox_first_name_customer
            // 
            this->textBox_first_name_customer->Location = System::Drawing::Point(28, 53);
            this->textBox_first_name_customer->Name = L"textBox_first_name_customer";
            this->textBox_first_name_customer->Size = System::Drawing::Size(240, 31);
            this->textBox_first_name_customer->TabIndex = 1;
            // 
            // textBox_last_name_customer
            // 
            this->textBox_last_name_customer->Location = System::Drawing::Point(28, 124);
            this->textBox_last_name_customer->Name = L"textBox_last_name_customer";
            this->textBox_last_name_customer->Size = System::Drawing::Size(240, 31);
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
            this->dataGridView_customers->Size = System::Drawing::Size(1232, 188);
            this->dataGridView_customers->TabIndex = 0;
            this->dataGridView_customers->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_customers_selectionChanged);
            // 
            // tab_employee
            // 
            this->tab_employee->Controls->Add(this->dataGridView_employee);
            this->tab_employee->Controls->Add(this->groupBox_employee);
            this->tab_employee->Location = System::Drawing::Point(4, 29);
            this->tab_employee->Name = L"tab_employee";
            this->tab_employee->Padding = System::Windows::Forms::Padding(3);
            this->tab_employee->Size = System::Drawing::Size(1246, 709);
            this->tab_employee->TabIndex = 3;
            this->tab_employee->Text = L"Employee";
            this->tab_employee->UseVisualStyleBackColor = true;
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
            this->dataGridView_employee->Size = System::Drawing::Size(1232, 188);
            this->dataGridView_employee->TabIndex = 0;
            this->dataGridView_employee->SelectionChanged += gcnew System::EventHandler(this, &UserInterface::dataGridView_employee_selectionChanged);
            // 
            // groupBox_employee
            //
            this->groupBox_employee->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox_employee->Controls->Add(this->label_id_manager_employee);
            this->groupBox_employee->Controls->Add(this->textBox_id_manager_employee);
            this->groupBox_employee->Controls->Add(this->textBox_id_address_employee);
            this->groupBox_employee->Controls->Add(this->label_id_address_employee);
            this->groupBox_employee->Controls->Add(this->label_employee_hiring_date);
            this->groupBox_employee->Controls->Add(this->dateTimePicker_employee_hiring_date);
            this->groupBox_employee->Controls->Add(this->button_delete_employee);
            this->groupBox_employee->Controls->Add(this->button_modify_employee);
            this->groupBox_employee->Controls->Add(this->label_last_name_employee);
            this->groupBox_employee->Controls->Add(this->label_first_name_employee);
            this->groupBox_employee->Controls->Add(this->textBox_first_name_employee);
            this->groupBox_employee->Controls->Add(this->textBox_last_name_employee);
            this->groupBox_employee->Location = System::Drawing::Point(8, 201);
            this->groupBox_employee->Name = L"groupBox_employee";
            this->groupBox_employee->Size = System::Drawing::Size(539, 229);
            this->groupBox_employee->TabIndex = 3;
            this->groupBox_employee->TabStop = false;
            this->groupBox_employee->Text = L"Employee Information";
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
            // button_delete_employee
            // 
            this->button_delete_employee->Location = System::Drawing::Point(134, 184);
            this->button_delete_employee->Name = L"button_delete_employee";
            this->button_delete_employee->Size = System::Drawing::Size(88, 30);
            this->button_delete_employee->TabIndex = 6;
            this->button_delete_employee->Text = L"Delete";
            this->button_delete_employee->UseVisualStyleBackColor = true;
            this->button_delete_employee->Click += gcnew System::EventHandler(this, &UserInterface::button_delete_employee_Click);
            // 
            // button_modify_employee
            // 
            this->button_modify_employee->Location = System::Drawing::Point(27, 184);
            this->button_modify_employee->Name = L"button_modify_employee";
            this->button_modify_employee->Size = System::Drawing::Size(88, 30);
            this->button_modify_employee->TabIndex = 5;
            this->button_modify_employee->Text = L"Modify";
            this->button_modify_employee->UseVisualStyleBackColor = true;
            this->button_modify_employee->Click += gcnew System::EventHandler(this, &UserInterface::button_modify_employee_Click);
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
            // label_id_address_employee
            // 
            this->label_id_address_employee->AutoSize = true;
            this->label_id_address_employee->Location = System::Drawing::Point(312, 101);
            this->label_id_address_employee->Name = L"label_id_address_employee";
            this->label_id_address_employee->Size = System::Drawing::Size(93, 20);
            this->label_id_address_employee->TabIndex = 9;
            this->label_id_address_employee->Text = L"Address ID";
            // 
            // textBox_id_address_employee
            // 
            this->textBox_id_address_employee->Location = System::Drawing::Point(316, 124);
            this->textBox_id_address_employee->Name = L"textBox_id_address_employee";
            this->textBox_id_address_employee->Size = System::Drawing::Size(197, 26);
            this->textBox_id_address_employee->TabIndex = 10;
            // 
            // textBox_id_manager_employee
            // 
            this->textBox_id_manager_employee->Location = System::Drawing::Point(316, 188);
            this->textBox_id_manager_employee->Name = L"textBox_id_manager_employee";
            this->textBox_id_manager_employee->Size = System::Drawing::Size(197, 26);
            this->textBox_id_manager_employee->TabIndex = 11;
            // 
            // label_id_manager_employee
            // 
            this->label_id_manager_employee->AutoSize = true;
            this->label_id_manager_employee->Location = System::Drawing::Point(312, 165);
            this->label_id_manager_employee->Name = L"label_id_manager_employee";
            this->label_id_manager_employee->Size = System::Drawing::Size(96, 20);
            this->label_id_manager_employee->TabIndex = 12;
            this->label_id_manager_employee->Text = L"Manager ID";
            // 
            // tab_statistics
            // 
            this->tab_statistics->Location = System::Drawing::Point(4, 29);
            this->tab_statistics->Name = L"tab_statistics";
            this->tab_statistics->Size = System::Drawing::Size(1246, 709);
            this->tab_statistics->TabIndex = 4;
            this->tab_statistics->Text = L"Statistics";
            this->tab_statistics->UseVisualStyleBackColor = true;
            // 
            // UserInterface
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1254, 742);
            this->Controls->Add(this->tabController);
            this->Font = (gcnew System::Drawing::Font(L"Inter", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->MaximumSize = System::Drawing::Size(1276, 798);
            this->MinimumSize = System::Drawing::Size(1276, 798);
            this->Name = L"UserInterface";
            this->Text = L"Company management";
            this->Load += gcnew System::EventHandler(this, &UserInterface::UserInterface_Load);
            this->tabController->ResumeLayout(false);
            this->tab_customers->ResumeLayout(false);
            this->groupBox_delivery_addresses->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_delivery_addresses))->EndInit();
            this->groupBox_customer_billing_addresses->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_billing_addresses))->EndInit();
            this->groupBox_create_customer->ResumeLayout(false);
            this->groupBox_customer_orders->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_orders))->EndInit();
            this->groupBox_customer_information->ResumeLayout(false);
            this->groupBox_customer_information->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customers))->EndInit();
            this->tab_employee->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_employee))->EndInit();
            this->groupBox_employee->ResumeLayout(false);
            this->groupBox_employee->PerformLayout();
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
    int get_currently_selected_billing_address()
    {
        return Convert::ToInt32(this->dataGridView_customer_billing_addresses->SelectedRows[0]->Cells["id_address"]->Value->ToString());
    }
        
    int get_currently_selected_delivery_address()
    {
        return Convert::ToInt32(this->dataGridView_customer_delivery_addresses->SelectedRows[0]->Cells["id_address"]->Value->ToString());
    }
        
    

        
    void dataGridView_customer_orders_selectionChanged(Object^ sender, EventArgs^ event_args)
    {
        // TODO add logic here
    }


    // Billing address stuff
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
            this->dataGridView_employee->Columns["id_address"]->Width = 130;
            this->dataGridView_employee->Columns["id_manager"]->Width = 130;

            this->dataGridView_employee->Columns["id_person"]->HeaderText = "ID";
            this->dataGridView_employee->Columns["first_name"]->HeaderText = "First name";
            this->dataGridView_employee->Columns["last_name"]->HeaderText = "Last name";
            this->dataGridView_employee->Columns["hiring_date"]->HeaderText = "Hiring date";
            this->dataGridView_employee->Columns["id_address"]->HeaderText = "Address ID";
            this->dataGridView_employee->Columns["id_manager"]->HeaderText = "Manager ID";
        }

    private:
        void updateSelectedEmployee(int id)
        {
            selected_employee = gcnew Employee(id);

            this->textBox_first_name_employee->Text = selected_employee->getFirstName();
            this->textBox_last_name_employee->Text = selected_employee->getLastName();
            this->dateTimePicker_employee_hiring_date->Value = selected_employee->getHireDate();
            this->textBox_id_address_employee->Text = selected_employee->getIDaddress().ToString();
            this->textBox_id_manager_employee->Text = selected_employee->getIDmanager().ToString();
        }

    // Events    
    private:
        void dataGridView_employee_selectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Return if no columns are selected
            if (dataGridView_employee->SelectedRows->Count == 0)
            {
                return;
            }

            String^ selectedIDstring = this->dataGridView_employee->SelectedRows[0]->Cells["id_person"]->Value->ToString();

            this->groupBox_employee->Text = "Employee " + selectedIDstring + " Information";

            updateSelectedEmployee(System::Convert::ToInt32(selectedIDstring));
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

            // Handling id_address modification
            int idAddress;
            if (!String::IsNullOrWhiteSpace(this->textBox_id_address_employee->Text) && 
                Int32::TryParse(this->textBox_id_address_employee->Text->Trim(), idAddress)) {
                this->selected_employee->setIDaddress(idAddress);
                } else {
                    // Handle invalid input for id_address (e.g., show an error message)
                    MessageBox::Show("Invalid input for Address ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return; // Optionally, stop further processing
                }

            // Handling id_manager modification
            if (String::IsNullOrWhiteSpace(this->textBox_id_manager_employee->Text)) {
                this->selected_employee->setIDmanagernullable(nullptr); // Pass DBNull for whitespace or empty input
            } else {
                int idManager;
                if (Int32::TryParse(this->textBox_id_manager_employee->Text->Trim(), idManager)) {
                    this->selected_employee->setIDmanager(idManager);
                } else {
                    MessageBox::Show("Invalid input for Manager ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }
            }
            this->selected_employee->modify_in_DB();
            this->refresh_employee_datagrid();
        }
};
}