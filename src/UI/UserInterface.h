#pragma once

#include "../SQL/SQLservices.h"
#include "../Customer.h"
#include "createCustomerPrompt.h"


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

    private:
        System::Windows::Forms::TextBox^ textBox_last_name_customer;

    private:
        System::Windows::Forms::TextBox^ textBox_first_name_customer;

    private:
        System::Windows::Forms::GroupBox^ groupBox_customer;

    private:
        System::Windows::Forms::Label^ label_last_name_customer;

    private:
        System::Windows::Forms::Label^ label_first_name_customer;

    private:
        System::Windows::Forms::Button^ button_delete_customer;

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






    private:


    private:
        System::Windows::Forms::Label^ label_customer_birth_date;

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
        System::Windows::Forms::TabPage^ tab_staff;

    private:
        System::Windows::Forms::DataGridView^ dataGridView_staff;

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
            this->dataGridView_customer_delivery_addresses = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_customer_billing_addresses = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView_customer_billing_addresses = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_create_customer = (gcnew System::Windows::Forms::GroupBox());
            this->button_create_customer = (gcnew System::Windows::Forms::Button());
            this->groupBox_customer_orders = (gcnew System::Windows::Forms::GroupBox());
            this->dataGridView_customer_orders = (gcnew System::Windows::Forms::DataGridView());
            this->button_customers_reload = (gcnew System::Windows::Forms::Button());
            this->groupBox_customer = (gcnew System::Windows::Forms::GroupBox());
            this->label_customer_birth_date = (gcnew System::Windows::Forms::Label());
            this->dateTimePicker_customer_birth_date = (gcnew System::Windows::Forms::DateTimePicker());
            this->button_delete_customer = (gcnew System::Windows::Forms::Button());
            this->button_modify_customer = (gcnew System::Windows::Forms::Button());
            this->label_last_name_customer = (gcnew System::Windows::Forms::Label());
            this->label_first_name_customer = (gcnew System::Windows::Forms::Label());
            this->textBox_first_name_customer = (gcnew System::Windows::Forms::TextBox());
            this->textBox_last_name_customer = (gcnew System::Windows::Forms::TextBox());
            this->dataGridView_customers = (gcnew System::Windows::Forms::DataGridView());
            this->tab_staff = (gcnew System::Windows::Forms::TabPage());
            this->dataGridView_staff = (gcnew System::Windows::Forms::DataGridView());
            this->tab_statistics = (gcnew System::Windows::Forms::TabPage());
            this->tabController->SuspendLayout();
            this->tab_customers->SuspendLayout();
            this->groupBox_delivery_addresses->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_delivery_addresses))->BeginInit();
            this->groupBox_customer_billing_addresses->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_billing_addresses))->BeginInit();
            this->groupBox_create_customer->SuspendLayout();
            this->groupBox_customer_orders->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customer_orders))->BeginInit();
            this->groupBox_customer->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customers))->BeginInit();
            this->tab_staff->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_staff))->BeginInit();
            this->SuspendLayout();
            // 
            // tabController
            // 
            this->tabController->Controls->Add(this->tab_orders);
            this->tabController->Controls->Add(this->tab_inventory);
            this->tabController->Controls->Add(this->tab_customers);
            this->tabController->Controls->Add(this->tab_staff);
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
            this->tab_orders->Location = System::Drawing::Point(4, 28);
            this->tab_orders->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_orders->Name = L"tab_orders";
            this->tab_orders->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_orders->Size = System::Drawing::Size(1246, 710);
            this->tab_orders->TabIndex = 1;
            this->tab_orders->Text = L"Orders";
            this->tab_orders->UseVisualStyleBackColor = true;
            // 
            // tab_inventory
            // 
            this->tab_inventory->Location = System::Drawing::Point(4, 28);
            this->tab_inventory->Name = L"tab_inventory";
            this->tab_inventory->Padding = System::Windows::Forms::Padding(3);
            this->tab_inventory->Size = System::Drawing::Size(1246, 710);
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
            this->tab_customers->Controls->Add(this->groupBox_customer);
            this->tab_customers->Controls->Add(this->dataGridView_customers);
            this->tab_customers->Location = System::Drawing::Point(4, 28);
            this->tab_customers->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Name = L"tab_customers";
            this->tab_customers->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->tab_customers->Size = System::Drawing::Size(1246, 710);
            this->tab_customers->TabIndex = 0;
            this->tab_customers->Text = L"Customers";
            this->tab_customers->UseVisualStyleBackColor = true;
            // 
            // groupBox_delivery_addresses
            // 
            this->groupBox_delivery_addresses->Controls->Add(this->dataGridView_customer_delivery_addresses);
            this->groupBox_delivery_addresses->Location = System::Drawing::Point(561, 534);
            this->groupBox_delivery_addresses->Name = L"groupBox_delivery_addresses";
            this->groupBox_delivery_addresses->Size = System::Drawing::Size(679, 169);
            this->groupBox_delivery_addresses->TabIndex = 8;
            this->groupBox_delivery_addresses->TabStop = false;
            this->groupBox_delivery_addresses->Text = L"Delivery addresses";
            // 
            // dataGridView_customer_delivery_addresses
            // 
            this->dataGridView_customer_delivery_addresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_delivery_addresses->Location = System::Drawing::Point(6, 26);
            this->dataGridView_customer_delivery_addresses->Name = L"dataGridView_customer_delivery_addresses";
            this->dataGridView_customer_delivery_addresses->RowHeadersWidth = 51;
            this->dataGridView_customer_delivery_addresses->RowTemplate->Height = 24;
            this->dataGridView_customer_delivery_addresses->Size = System::Drawing::Size(661, 94);
            this->dataGridView_customer_delivery_addresses->TabIndex = 1;
            // 
            // groupBox_customer_billing_addresses
            // 
            this->groupBox_customer_billing_addresses->Controls->Add(this->dataGridView_customer_billing_addresses);
            this->groupBox_customer_billing_addresses->Location = System::Drawing::Point(8, 534);
            this->groupBox_customer_billing_addresses->Name = L"groupBox_customer_billing_addresses";
            this->groupBox_customer_billing_addresses->Size = System::Drawing::Size(539, 169);
            this->groupBox_customer_billing_addresses->TabIndex = 7;
            this->groupBox_customer_billing_addresses->TabStop = false;
            this->groupBox_customer_billing_addresses->Text = L"Billing addresses";
            // 
            // dataGridView_customer_billing_addresses
            // 
            this->dataGridView_customer_billing_addresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_customer_billing_addresses->Location = System::Drawing::Point(7, 27);
            this->dataGridView_customer_billing_addresses->Name = L"dataGridView_customer_billing_addresses";
            this->dataGridView_customer_billing_addresses->RowHeadersWidth = 51;
            this->dataGridView_customer_billing_addresses->RowTemplate->Height = 24;
            this->dataGridView_customer_billing_addresses->Size = System::Drawing::Size(526, 94);
            this->dataGridView_customer_billing_addresses->TabIndex = 0;
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
            this->button_create_customer->Size = System::Drawing::Size(184, 30);
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
            // groupBox_customer
            // 
            this->groupBox_customer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox_customer->Controls->Add(this->label_customer_birth_date);
            this->groupBox_customer->Controls->Add(this->dateTimePicker_customer_birth_date);
            this->groupBox_customer->Controls->Add(this->button_delete_customer);
            this->groupBox_customer->Controls->Add(this->button_modify_customer);
            this->groupBox_customer->Controls->Add(this->label_last_name_customer);
            this->groupBox_customer->Controls->Add(this->label_first_name_customer);
            this->groupBox_customer->Controls->Add(this->textBox_first_name_customer);
            this->groupBox_customer->Controls->Add(this->textBox_last_name_customer);
            this->groupBox_customer->Location = System::Drawing::Point(8, 201);
            this->groupBox_customer->Name = L"groupBox_customer";
            this->groupBox_customer->Size = System::Drawing::Size(539, 229);
            this->groupBox_customer->TabIndex = 3;
            this->groupBox_customer->TabStop = false;
            this->groupBox_customer->Text = L"Customer Information";
            // 
            // label_customer_birth_date
            // 
            this->label_customer_birth_date->AutoSize = true;
            this->label_customer_birth_date->Location = System::Drawing::Point(312, 30);
            this->label_customer_birth_date->Name = L"label_customer_birth_date";
            this->label_customer_birth_date->Size = System::Drawing::Size(89, 20);
            this->label_customer_birth_date->TabIndex = 8;
            this->label_customer_birth_date->Text = L"Birth date";
            // 
            // dateTimePicker_customer_birth_date
            // 
            this->dateTimePicker_customer_birth_date->Location = System::Drawing::Point(316, 53);
            this->dateTimePicker_customer_birth_date->Name = L"dateTimePicker_customer_birth_date";
            this->dateTimePicker_customer_birth_date->Size = System::Drawing::Size(197, 27);
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
            this->label_last_name_customer->Size = System::Drawing::Size(97, 20);
            this->label_last_name_customer->TabIndex = 4;
            this->label_last_name_customer->Text = L"Last Name";
            // 
            // label_first_name_customer
            // 
            this->label_first_name_customer->AutoSize = true;
            this->label_first_name_customer->Location = System::Drawing::Point(24, 30);
            this->label_first_name_customer->Name = L"label_first_name_customer";
            this->label_first_name_customer->Size = System::Drawing::Size(97, 20);
            this->label_first_name_customer->TabIndex = 3;
            this->label_first_name_customer->Text = L"First Name";
            // 
            // textBox_first_name_customer
            // 
            this->textBox_first_name_customer->Location = System::Drawing::Point(28, 53);
            this->textBox_first_name_customer->Name = L"textBox_first_name_customer";
            this->textBox_first_name_customer->Size = System::Drawing::Size(240, 27);
            this->textBox_first_name_customer->TabIndex = 1;
            // 
            // textBox_last_name_customer
            // 
            this->textBox_last_name_customer->Location = System::Drawing::Point(28, 124);
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
            // tab_staff
            // 
            this->tab_staff->Controls->Add(this->dataGridView_staff);
            this->tab_staff->Location = System::Drawing::Point(4, 28);
            this->tab_staff->Name = L"tab_staff";
            this->tab_staff->Padding = System::Windows::Forms::Padding(3);
            this->tab_staff->Size = System::Drawing::Size(1246, 710);
            this->tab_staff->TabIndex = 3;
            this->tab_staff->Text = L"Staff";
            this->tab_staff->UseVisualStyleBackColor = true;
            // 
            // dataGridView_staff
            // 
            this->dataGridView_staff->AllowUserToAddRows = false;
            this->dataGridView_staff->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dataGridView_staff->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Sunken;
            this->dataGridView_staff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_staff->Location = System::Drawing::Point(8, 6);
            this->dataGridView_staff->Name = L"dataGridView_staff";
            this->dataGridView_staff->ReadOnly = true;
            this->dataGridView_staff->RowHeadersWidth = 51;
            this->dataGridView_staff->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_staff->Size = System::Drawing::Size(1228, 227);
            this->dataGridView_staff->TabIndex = 0;
            // 
            // tab_statistics
            // 
            this->tab_statistics->Location = System::Drawing::Point(4, 28);
            this->tab_statistics->Name = L"tab_statistics";
            this->tab_statistics->Size = System::Drawing::Size(1246, 710);
            this->tab_statistics->TabIndex = 4;
            this->tab_statistics->Text = L"Statistics";
            this->tab_statistics->UseVisualStyleBackColor = true;
            // 
            // UserInterface
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1254, 742);
            this->Controls->Add(this->tabController);
            this->Font = (gcnew System::Drawing::Font(L"Inter", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
            this->MinimumSize = System::Drawing::Size(1272, 748);
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
            this->groupBox_customer->ResumeLayout(false);
            this->groupBox_customer->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_customers))->EndInit();
            this->tab_staff->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_staff))->EndInit();
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

    // Customers tab
    private:
        void refresh_customers_datagrid()
        {
            this->dataGridView_customers->Refresh();
            this->dataGridView_customers->DataSource = SQLserver->SQL_getCustomerList();

            this->dataGridView_customers->Columns["id_person"]->Width = 40;
            this->dataGridView_customers->Columns["first_order_date"]->Width = 130;

            this->dataGridView_customers->Columns["id_person"]->HeaderText = "ID";
            this->dataGridView_customers->Columns["first_order_date"]->HeaderText = "First order date";
            this->dataGridView_customers->Columns["first_name"]->HeaderText = "First name";
            this->dataGridView_customers->Columns["last_name"]->HeaderText = "Last name";
            this->dataGridView_customers->Columns["birth_date"]->HeaderText = "Birth date";
            
        }
    
    private:
        void updateSelectedCustomer(int id)
        {
            selected_customer = gcnew Customer(id);

            this->textBox_first_name_customer->Text = selected_customer->getFirstName();
            this->textBox_last_name_customer->Text = selected_customer->getLastName();
            this->dateTimePicker_customer_birth_date->Value = selected_customer->getBirthDate();
            
        }
        
    private:
        void refresh_customer_orders_datagrid()
        {
            this->dataGridView_customer_orders->Refresh();
            this->dataGridView_customer_orders->DataSource = this->selected_customer->getOrders();
            
            this->dataGridView_customer_orders->Columns["id_order"]->Visible = false;
            
            this->dataGridView_customer_orders->Sort(this->dataGridView_customer_orders->Columns["order_date"], System::ComponentModel::ListSortDirection::Descending);

            
            
            this->dataGridView_customer_orders->Columns["order_reference"]->HeaderText = "Order reference";
            this->dataGridView_customer_orders->Columns["total_amount"]->HeaderText = "Total Amount";
            
        }

        void refresh_customer_billing_addresses_datagrid()
        {
            this->dataGridView_customer_billing_addresses->Refresh();
            this->dataGridView_customer_billing_addresses->DataSource = this->selected_customer->getBillingAddresses();
            this->dataGridView_customer_billing_addresses->Columns["id_address"]->Visible = false;

        }

        void refresh_customer_delivery_addresses_datagrid()
        {
            this->dataGridView_customer_delivery_addresses->Refresh();
            this->dataGridView_customer_delivery_addresses->DataSource = this->selected_customer->getDeliveryAddresses();
            this->dataGridView_customer_delivery_addresses->Columns["id_address"]->Visible = false;

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
            
            String^ selectedIDstring = this->dataGridView_customers->SelectedRows[0]->Cells["id_person"]->Value->
                ToString();

            this->groupBox_customer->Text = "Customer " + selectedIDstring + " Information";
            this->groupBox_customer_orders->Text = "Customer " + selectedIDstring + " Orders";

            updateSelectedCustomer(System::Convert::ToInt32(selectedIDstring));

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
        
    // Employee/Staff tab
    private:
        void refresh_employee_datagrid()
        {
            this->dataGridView_staff->Refresh();
            this->dataGridView_staff->DataSource = SQLserver->SQL_getEmployeeList();
            this->dataGridView_staff->Columns["id_person"]->Width = 40;
            this->dataGridView_staff->Columns["hiring_date"]->Width = 130;
            this->dataGridView_staff->Columns["id_address"]->Width = 130;
            this->dataGridView_staff->Columns["id_manager"]->Width = 130;

            this->dataGridView_staff->Columns["id_person"]->HeaderText = "ID";
            this->dataGridView_staff->Columns["first_name"]->HeaderText = "First name";
            this->dataGridView_staff->Columns["last_name"]->HeaderText = "Last name";
            this->dataGridView_staff->Columns["hiring_date"]->HeaderText = "Hiring date";
            this->dataGridView_staff->Columns["id_address"]->HeaderText = "Address ID";
            this->dataGridView_staff->Columns["id_manager"]->HeaderText = "Manager ID";
        }
};
}

