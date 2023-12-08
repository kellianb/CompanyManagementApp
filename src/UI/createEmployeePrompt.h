#pragma once

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for createEmployeePrompt
	/// </summary>
	public ref class createEmployeePrompt : public System::Windows::Forms::Form
	{
	private :
		String^ windowText;
		
	public:
		createEmployeePrompt(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public:
		property String^ new_employee_first_name {
			String^ get() {
				return textBox_employee_first_name->Text;
			}
		}

		property String^ new_employee_last_name {
			String^ get() {
				return textBox_employee_last_name->Text;
			}
		}

		property System::DateTime new_employee_hire_date {
			DateTime get() {
				return dateTimePicker_employee_hire_date->Value;
			}
		}
		
		property String^ new_employee_address_city {
			String^ get() {
				return textBox_address_city->Text;
			}
		}
		property int new_employee_address_postal_code {
			int get() {
				return Convert::ToInt32(textBox_address_postal_code->Text);
			}
		}
		property String^ new_employee_address_street {
			String^ get() {
				return textBox_address_street->Text;
			}
		}
		property int new_employee_address_street_number {
			int get() {
				return Convert::ToInt32(textBox_address_street_number->Text);
			}
		}


		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~createEmployeePrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ textBox_employee_first_name;
	private: System::Windows::Forms::TextBox^ textBox_employee_last_name;
	public:
	protected:

	protected:

	private: System::Windows::Forms::Label^ label_first_name;
	private: System::Windows::Forms::Label^ label_last_name;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_employee_hire_date;



	private: System::Windows::Forms::Label^ label_hire_date;
	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::Button^ button_cancel;
	private: System::Windows::Forms::Label^ label_address_street;
	private: System::Windows::Forms::Label^ label_address_street_number;
	private: System::Windows::Forms::Label^ label_address_postal_code;
	private: System::Windows::Forms::Label^ label_address_city;
	public: System::Windows::Forms::TextBox^ textBox_address_postal_code;
	private:
	public: System::Windows::Forms::TextBox^ textBox_address_street_number;
	public: System::Windows::Forms::TextBox^ textBox_address_street;
	public: System::Windows::Forms::TextBox^ textBox_address_city;
	private: System::Windows::Forms::GroupBox^ groupBox_address;
	public:


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
			this->textBox_employee_first_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_employee_last_name = (gcnew System::Windows::Forms::TextBox());
			this->label_first_name = (gcnew System::Windows::Forms::Label());
			this->label_last_name = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_employee_hire_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_hire_date = (gcnew System::Windows::Forms::Label());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->label_address_street = (gcnew System::Windows::Forms::Label());
			this->label_address_street_number = (gcnew System::Windows::Forms::Label());
			this->label_address_postal_code = (gcnew System::Windows::Forms::Label());
			this->label_address_city = (gcnew System::Windows::Forms::Label());
			this->textBox_address_postal_code = (gcnew System::Windows::Forms::TextBox());
			this->textBox_address_street_number = (gcnew System::Windows::Forms::TextBox());
			this->textBox_address_street = (gcnew System::Windows::Forms::TextBox());
			this->textBox_address_city = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_address = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox_address->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox_employee_first_name
			// 
			this->textBox_employee_first_name->Location = System::Drawing::Point(162, 52);
			this->textBox_employee_first_name->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_employee_first_name->Name = L"textBox_employee_first_name";
			this->textBox_employee_first_name->Size = System::Drawing::Size(298, 26);
			this->textBox_employee_first_name->TabIndex = 0;
			// 
			// textBox_employee_last_name
			// 
			this->textBox_employee_last_name->Location = System::Drawing::Point(162, 114);
			this->textBox_employee_last_name->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_employee_last_name->Name = L"textBox_employee_last_name";
			this->textBox_employee_last_name->Size = System::Drawing::Size(298, 26);
			this->textBox_employee_last_name->TabIndex = 1;
			// 
			// label_first_name
			// 
			this->label_first_name->AutoSize = true;
			this->label_first_name->Location = System::Drawing::Point(36, 55);
			this->label_first_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_first_name->Name = L"label_first_name";
			this->label_first_name->Size = System::Drawing::Size(84, 20);
			this->label_first_name->TabIndex = 2;
			this->label_first_name->Text = L"First name";
			// 
			// label_last_name
			// 
			this->label_last_name->AutoSize = true;
			this->label_last_name->Location = System::Drawing::Point(36, 116);
			this->label_last_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_last_name->Name = L"label_last_name";
			this->label_last_name->Size = System::Drawing::Size(84, 20);
			this->label_last_name->TabIndex = 3;
			this->label_last_name->Text = L"Last name";
			// 
			// dateTimePicker_employee_hire_date
			// 
			this->dateTimePicker_employee_hire_date->Location = System::Drawing::Point(162, 177);
			this->dateTimePicker_employee_hire_date->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker_employee_hire_date->Name = L"dateTimePicker_employee_hire_date";
			this->dateTimePicker_employee_hire_date->Size = System::Drawing::Size(298, 26);
			this->dateTimePicker_employee_hire_date->TabIndex = 4;
			// 
			// label_hire_date
			// 
			this->label_hire_date->AutoSize = true;
			this->label_hire_date->Location = System::Drawing::Point(36, 181);
			this->label_hire_date->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_hire_date->Name = L"label_hire_date";
			this->label_hire_date->Size = System::Drawing::Size(74, 20);
			this->label_hire_date->TabIndex = 5;
			this->label_hire_date->Text = L"Hire date";
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Location = System::Drawing::Point(148, 493);
			this->button_create->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(112, 35);
			this->button_create->TabIndex = 6;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Location = System::Drawing::Point(297, 493);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(112, 35);
			this->button_cancel->TabIndex = 7;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// label_address_street
			// 
			this->label_address_street->AutoSize = true;
			this->label_address_street->Location = System::Drawing::Point(24, 135);
			this->label_address_street->Name = L"label_address_street";
			this->label_address_street->Size = System::Drawing::Size(53, 20);
			this->label_address_street->TabIndex = 19;
			this->label_address_street->Text = L"Street";
			// 
			// label_address_street_number
			// 
			this->label_address_street_number->AutoSize = true;
			this->label_address_street_number->Location = System::Drawing::Point(24, 188);
			this->label_address_street_number->Name = L"label_address_street_number";
			this->label_address_street_number->Size = System::Drawing::Size(111, 20);
			this->label_address_street_number->TabIndex = 18;
			this->label_address_street_number->Text = L"Street number";
			// 
			// label_address_postal_code
			// 
			this->label_address_postal_code->AutoSize = true;
			this->label_address_postal_code->Location = System::Drawing::Point(24, 85);
			this->label_address_postal_code->Name = L"label_address_postal_code";
			this->label_address_postal_code->Size = System::Drawing::Size(95, 20);
			this->label_address_postal_code->TabIndex = 17;
			this->label_address_postal_code->Text = L"Postal Code";
			// 
			// label_address_city
			// 
			this->label_address_city->AutoSize = true;
			this->label_address_city->Location = System::Drawing::Point(24, 39);
			this->label_address_city->Name = L"label_address_city";
			this->label_address_city->Size = System::Drawing::Size(35, 20);
			this->label_address_city->TabIndex = 16;
			this->label_address_city->Text = L"City";
			// 
			// textBox_address_postal_code
			// 
			this->textBox_address_postal_code->Location = System::Drawing::Point(150, 82);
			this->textBox_address_postal_code->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_postal_code->Name = L"textBox_address_postal_code";
			this->textBox_address_postal_code->Size = System::Drawing::Size(298, 26);
			this->textBox_address_postal_code->TabIndex = 15;
			// 
			// textBox_address_street_number
			// 
			this->textBox_address_street_number->Location = System::Drawing::Point(150, 185);
			this->textBox_address_street_number->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_street_number->Name = L"textBox_address_street_number";
			this->textBox_address_street_number->Size = System::Drawing::Size(298, 26);
			this->textBox_address_street_number->TabIndex = 14;
			// 
			// textBox_address_street
			// 
			this->textBox_address_street->Location = System::Drawing::Point(150, 132);
			this->textBox_address_street->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_street->Name = L"textBox_address_street";
			this->textBox_address_street->Size = System::Drawing::Size(298, 26);
			this->textBox_address_street->TabIndex = 13;
			// 
			// textBox_address_city
			// 
			this->textBox_address_city->Location = System::Drawing::Point(150, 36);
			this->textBox_address_city->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_city->Name = L"textBox_address_city";
			this->textBox_address_city->Size = System::Drawing::Size(298, 26);
			this->textBox_address_city->TabIndex = 12;
			// 
			// groupBox_address
			// 
			this->groupBox_address->Controls->Add(this->label_address_street_number);
			this->groupBox_address->Controls->Add(this->label_address_street);
			this->groupBox_address->Controls->Add(this->textBox_address_street_number);
			this->groupBox_address->Controls->Add(this->textBox_address_street);
			this->groupBox_address->Controls->Add(this->label_address_postal_code);
			this->groupBox_address->Controls->Add(this->textBox_address_postal_code);
			this->groupBox_address->Controls->Add(this->label_address_city);
			this->groupBox_address->Controls->Add(this->textBox_address_city);
			this->groupBox_address->Location = System::Drawing::Point(12, 232);
			this->groupBox_address->Name = L"groupBox_address";
			this->groupBox_address->Size = System::Drawing::Size(504, 238);
			this->groupBox_address->TabIndex = 20;
			this->groupBox_address->TabStop = false;
			this->groupBox_address->Text = L"Address";
			// 
			// createEmployeePrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 554);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->label_hire_date);
			this->Controls->Add(this->dateTimePicker_employee_hire_date);
			this->Controls->Add(this->label_last_name);
			this->Controls->Add(this->label_first_name);
			this->Controls->Add(this->textBox_employee_last_name);
			this->Controls->Add(this->textBox_employee_first_name);
			this->Controls->Add(this->groupBox_address);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(550, 400);
			this->Name = L"createEmployeePrompt";
			this->Text = L"Create employee";
			this->Load += gcnew System::EventHandler(this, &createEmployeePrompt::createEmployeePrompt_Load);
			this->groupBox_address->ResumeLayout(false);
			this->groupBox_address->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void createEmployeePrompt_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
