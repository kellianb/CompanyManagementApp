#pragma once

namespace Projet
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for selectEmployeeManager
    /// </summary>
    public ref class selectEmployeeManager : public System::Windows::Forms::Form
    {
    public:
        selectEmployeeManager(DataTable^ employeeList, String^ windowText)
        {
            InitializeComponent();

            this->Text = windowText;

            this->dataGridView_employees->DataSource = employeeList;

            this->dataGridView_employees->Columns["id_person"]->Width = 40;
            this->dataGridView_employees->Columns["hiring_date"]->Width = 130;
            this->dataGridView_employees->Columns["id_address"]->Width = 130;
            this->dataGridView_employees->Columns["id_manager"]->Width = 130;

            this->dataGridView_employees->Columns["id_person"]->HeaderText = "ID";
            this->dataGridView_employees->Columns["first_name"]->HeaderText = "First name";
            this->dataGridView_employees->Columns["last_name"]->HeaderText = "Last name";
            this->dataGridView_employees->Columns["hiring_date"]->HeaderText = "Hiring date";
            this->dataGridView_employees->Columns["id_address"]->Visible = false;
            this->dataGridView_employees->Columns["id_manager"]->Visible = false;
        }

    public:
        property int selected_manager
        {
            int get()
            {
                return Convert::ToInt32(dataGridView_employees->SelectedRows[0]->Cells["id_person"]->Value->ToString());
            }
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~selectEmployeeManager()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView_employees;

    private:
        System::Windows::Forms::Button^ button_cancel;

    private:
        System::Windows::Forms::Button^ button_select;

    protected:

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
            this->dataGridView_employees = (gcnew System::Windows::Forms::DataGridView());
            this->button_cancel = (gcnew System::Windows::Forms::Button());
            this->button_select = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_employees))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView_employees
            // 
            this->dataGridView_employees->AllowUserToAddRows = false;
            this->dataGridView_employees->AllowUserToDeleteRows = false;
            this->dataGridView_employees->AllowUserToOrderColumns = true;
            this->dataGridView_employees->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_employees->Location = System::Drawing::Point(13, 12);
            this->dataGridView_employees->MultiSelect = false;
            this->dataGridView_employees->Name = L"dataGridView_employees";
            this->dataGridView_employees->ReadOnly = true;
            this->dataGridView_employees->RowHeadersWidth = 62;
            this->dataGridView_employees->RowTemplate->Height = 28;
            this->dataGridView_employees->SelectionMode =
                System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView_employees->Size = System::Drawing::Size(779, 470);
            this->dataGridView_employees->TabIndex = 0;
            // 
            // button_cancel
            // 
            this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->button_cancel->Location = System::Drawing::Point(400, 506);
            this->button_cancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->button_cancel->Name = L"button_cancel";
            this->button_cancel->Size = System::Drawing::Size(112, 35);
            this->button_cancel->TabIndex = 15;
            this->button_cancel->Text = L"Cancel";
            this->button_cancel->UseVisualStyleBackColor = true;
            // 
            // button_select
            // 
            this->button_select->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->button_select->Location = System::Drawing::Point(251, 506);
            this->button_select->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->button_select->Name = L"button_select";
            this->button_select->Size = System::Drawing::Size(112, 35);
            this->button_select->TabIndex = 14;
            this->button_select->Text = L"Select";
            this->button_select->UseVisualStyleBackColor = true;
            // 
            // selectEmployeeManager
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(804, 565);
            this->Controls->Add(this->button_cancel);
            this->Controls->Add(this->button_select);
            this->Controls->Add(this->dataGridView_employees);
            this->Name = L"selectEmployeeManager";
            this->Text = L"Select manager";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_employees))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
    };
}
