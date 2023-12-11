#pragma once

#include "../Customer.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for createOrderPrompt
	/// </summary>
	public ref class editOrderPrompt : public System::Windows::Forms::Form
	{
	private:
		Customer^ currentCustomer;
		
		
		   System::String^ windowText;
		
	public:
		editOrderPrompt(int id_customer, String^ windowText) : windowText(windowText)
		{
			InitializeComponent();

			currentCustomer = gcnew Customer(id_customer);
		}

		editOrderPrompt(int id_customer, String^ windowText, System::DateTime order_date, System::DateTime delivery_date, float discount_percentage, int id_delivery_address, int id_billing_address) : windowText(windowText)
		{
			InitializeComponent();

			currentCustomer = gcnew Customer(id_customer);

			this->dateTimePicker_order_date->Value = order_date;
			this->dateTimePicker_delivery_date->Value = delivery_date;
			this->numericUpDown_discount_percentage->Value = Convert::ToDecimal(discount_percentage);

			for (int i = 0; i < this->dataGridView_delivery_address->Rows->Count; i++)
			{
				if (Convert::ToInt32(this->dataGridView_delivery_address->Rows[i]->Cells["id_address"]->Value) == id_delivery_address)
				{
					this->dataGridView_delivery_address->Rows[i]->Selected = true;
				}
			}

			for (int i = 0; i < this->dataGridView_billing_address->Rows->Count; i++)
			{
				if (Convert::ToInt32(this->dataGridView_billing_address->Rows[i]->Cells["id_address"]->Value) == id_billing_address)
				{
					this->dataGridView_billing_address->Rows[i]->Selected = true;
				}
			}

			this->button_create->Text = "Modify";
		}

		property System::DateTime new_order_delivery_date {
			DateTime get() {
				return dateTimePicker_delivery_date->Value;
			}
		}

		property System::DateTime new_order_order_date {
			DateTime get() {
				return dateTimePicker_order_date->Value;
			}
		}

		property  float new_order_discount_percentage {
			float get() {
				return Convert::ToSingle(numericUpDown_discount_percentage->Value);
			}
		}

		property int new_order_id_delivery_address {
			int get() {
				return Convert::ToInt32(dataGridView_delivery_address->SelectedRows[0]->Cells["id_address"]->Value);
			}
		}

		property int new_order_id_billing_address {
			int get() {
				return Convert::ToInt32(dataGridView_billing_address->SelectedRows[0]->Cells["id_address"]->Value);
			}
		}

	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~editOrderPrompt()
		{
			if (components)
			{
				delete components;
			}
		}

		
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_discount_percentage;
	private: System::Windows::Forms::Button^ button_cancel;
	protected:
	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_order_date;

	private: System::Windows::Forms::Label^ label_order_date;
	private: System::Windows::Forms::Label^ label_delivery_date;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_delivery_date;
	private: System::Windows::Forms::GroupBox^ groupBox_billing_address;
	private: System::Windows::Forms::DataGridView^ dataGridView_billing_address;





	private: System::Windows::Forms::DataGridView^ dataGridView_delivery_address;

	private: System::Windows::Forms::GroupBox^ groupBox_delivery_address;



	private: System::Windows::Forms::Label^ label_discount_percentage;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker_order_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_order_date = (gcnew System::Windows::Forms::Label());
			this->label_delivery_date = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_delivery_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox_billing_address = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView_billing_address = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView_delivery_address = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox_delivery_address = (gcnew System::Windows::Forms::GroupBox());
			this->label_discount_percentage = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_discount_percentage = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox_billing_address->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_billing_address))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_delivery_address))->BeginInit();
			this->groupBox_delivery_address->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_discount_percentage))->BeginInit();
			this->SuspendLayout();
			// 
			// button_cancel
			// 
			this->button_cancel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_cancel->Location = System::Drawing::Point(340, 490);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(100, 28);
			this->button_cancel->TabIndex = 9;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// button_create
			// 
			this->button_create->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_create->Location = System::Drawing::Point(205, 490);
			this->button_create->Margin = System::Windows::Forms::Padding(4);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(100, 28);
			this->button_create->TabIndex = 8;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker_order_date
			// 
			this->dateTimePicker_order_date->CalendarFont = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->dateTimePicker_order_date->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->dateTimePicker_order_date->Location = System::Drawing::Point(18, 47);
			this->dateTimePicker_order_date->Name = L"dateTimePicker_order_date";
			this->dateTimePicker_order_date->Size = System::Drawing::Size(200, 31);
			this->dateTimePicker_order_date->TabIndex = 10;
			// 
			// label_order_date
			// 
			this->label_order_date->AutoSize = true;
			this->label_order_date->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_order_date->Location = System::Drawing::Point(14, 20);
			this->label_order_date->Name = L"label_order_date";
			this->label_order_date->Size = System::Drawing::Size(111, 24);
			this->label_order_date->TabIndex = 11;
			this->label_order_date->Text = L"Order date";
			// 
			// label_delivery_date
			// 
			this->label_delivery_date->AutoSize = true;
			this->label_delivery_date->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_delivery_date->Location = System::Drawing::Point(14, 82);
			this->label_delivery_date->Name = L"label_delivery_date";
			this->label_delivery_date->Size = System::Drawing::Size(135, 24);
			this->label_delivery_date->TabIndex = 13;
			this->label_delivery_date->Text = L"Delivery date";
			// 
			// dateTimePicker_delivery_date
			// 
			this->dateTimePicker_delivery_date->CalendarFont = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->dateTimePicker_delivery_date->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->dateTimePicker_delivery_date->Location = System::Drawing::Point(18, 109);
			this->dateTimePicker_delivery_date->Name = L"dateTimePicker_delivery_date";
			this->dateTimePicker_delivery_date->Size = System::Drawing::Size(200, 31);
			this->dateTimePicker_delivery_date->TabIndex = 12;
			// 
			// groupBox_billing_address
			// 
			this->groupBox_billing_address->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_billing_address->Controls->Add(this->dataGridView_billing_address);
			this->groupBox_billing_address->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->groupBox_billing_address->Location = System::Drawing::Point(12, 309);
			this->groupBox_billing_address->Name = L"groupBox_billing_address";
			this->groupBox_billing_address->Size = System::Drawing::Size(656, 157);
			this->groupBox_billing_address->TabIndex = 15;
			this->groupBox_billing_address->TabStop = false;
			this->groupBox_billing_address->Text = L"Select billing addresses";
			// 
			// dataGridView_billing_address
			// 
			this->dataGridView_billing_address->AllowUserToAddRows = false;
			this->dataGridView_billing_address->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_billing_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_billing_address->Location = System::Drawing::Point(6, 21);
			this->dataGridView_billing_address->MultiSelect = false;
			this->dataGridView_billing_address->Name = L"dataGridView_billing_address";
			this->dataGridView_billing_address->ReadOnly = true;
			this->dataGridView_billing_address->RowHeadersWidth = 62;
			this->dataGridView_billing_address->RowTemplate->Height = 28;
			this->dataGridView_billing_address->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_billing_address->Size = System::Drawing::Size(641, 130);
			this->dataGridView_billing_address->TabIndex = 1;
			// 
			// dataGridView_delivery_address
			// 
			this->dataGridView_delivery_address->AllowUserToAddRows = false;
			this->dataGridView_delivery_address->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_delivery_address->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_delivery_address->Location = System::Drawing::Point(6, 21);
			this->dataGridView_delivery_address->MultiSelect = false;
			this->dataGridView_delivery_address->Name = L"dataGridView_delivery_address";
			this->dataGridView_delivery_address->ReadOnly = true;
			this->dataGridView_delivery_address->RowHeadersWidth = 62;
			this->dataGridView_delivery_address->RowTemplate->Height = 28;
			this->dataGridView_delivery_address->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_delivery_address->Size = System::Drawing::Size(641, 130);
			this->dataGridView_delivery_address->TabIndex = 1;
			// 
			// groupBox_delivery_address
			// 
			this->groupBox_delivery_address->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_delivery_address->Controls->Add(this->dataGridView_delivery_address);
			this->groupBox_delivery_address->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->groupBox_delivery_address->Location = System::Drawing::Point(12, 146);
			this->groupBox_delivery_address->Name = L"groupBox_delivery_address";
			this->groupBox_delivery_address->Size = System::Drawing::Size(656, 157);
			this->groupBox_delivery_address->TabIndex = 16;
			this->groupBox_delivery_address->TabStop = false;
			this->groupBox_delivery_address->Text = L"Select delivery addresses";
			// 
			// label_discount_percentage
			// 
			this->label_discount_percentage->AutoSize = true;
			this->label_discount_percentage->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_discount_percentage->Location = System::Drawing::Point(287, 20);
			this->label_discount_percentage->Name = L"label_discount_percentage";
			this->label_discount_percentage->Size = System::Drawing::Size(207, 24);
			this->label_discount_percentage->TabIndex = 18;
			this->label_discount_percentage->Text = L"Discount percentage";
			// 
			// numericUpDown_discount_percentage
			// 
			this->numericUpDown_discount_percentage->DecimalPlaces = 2;
			this->numericUpDown_discount_percentage->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->numericUpDown_discount_percentage->Location = System::Drawing::Point(291, 47);
			this->numericUpDown_discount_percentage->Name = L"numericUpDown_discount_percentage";
			this->numericUpDown_discount_percentage->Size = System::Drawing::Size(120, 31);
			this->numericUpDown_discount_percentage->TabIndex = 20;
			// 
			// editOrderPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(676, 522);
			this->Controls->Add(this->numericUpDown_discount_percentage);
			this->Controls->Add(this->label_discount_percentage);
			this->Controls->Add(this->groupBox_delivery_address);
			this->Controls->Add(this->groupBox_billing_address);
			this->Controls->Add(this->label_delivery_date);
			this->Controls->Add(this->dateTimePicker_delivery_date);
			this->Controls->Add(this->label_order_date);
			this->Controls->Add(this->dateTimePicker_order_date);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Font = (gcnew System::Drawing::Font(L"Inter", 7.8F));
			this->MaximumSize = System::Drawing::Size(698, 578);
			this->MinimumSize = System::Drawing::Size(698, 578);
			this->Name = L"editOrderPrompt";
			this->Text = L"createOrderPrompt";
			this->Load += gcnew System::EventHandler(this, &editOrderPrompt::createOrderPrompt_Load);
			this->groupBox_billing_address->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_billing_address))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_delivery_address))->EndInit();
			this->groupBox_delivery_address->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_discount_percentage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void createOrderPrompt_Load(System::Object^ sender, System::EventArgs^ e) {
	this->Text = windowText;
	
	this->dataGridView_delivery_address->DataSource = this->currentCustomer->getDeliveryAddresses();
	this->dataGridView_billing_address->DataSource = this->currentCustomer->getBillingAddresses();
	
	this->dataGridView_delivery_address->Columns["id_address"]->Visible = false;
	this->dataGridView_delivery_address->Columns["city"]->HeaderText = "City";
	this->dataGridView_delivery_address->Columns["postal_code"]->HeaderText = "Postal Code";
	this->dataGridView_delivery_address->Columns["street"]->HeaderText = "Street";
	this->dataGridView_delivery_address->Columns["street_number"]->HeaderText = "Street Number";


	this->dataGridView_billing_address->Columns["id_address"]->Visible = false;
	this->dataGridView_billing_address->Columns["city"]->HeaderText = "City";
	this->dataGridView_billing_address->Columns["postal_code"]->HeaderText = "Postal Code";
	this->dataGridView_billing_address->Columns["street"]->HeaderText = "Street";
	this->dataGridView_billing_address->Columns["street_number"]->HeaderText = "Street Number";
}
};
}
