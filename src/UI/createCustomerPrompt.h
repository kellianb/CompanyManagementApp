#pragma once

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for createCustomerPrompt
	/// </summary>
	public ref class createCustomerPrompt : public System::Windows::Forms::Form
	{
	public:
		createCustomerPrompt(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public:
		property String^ new_customer_first_name {
			String^ get() {
				return textBox_customer_first_name->Text;
			}
		}

		property String^ new_customer_last_name {
			String^ get() {
				return textBox_customer_last_name->Text;
			}
		}

		property System::DateTime new_customer_birth_date {
			DateTime get() {
				return dateTimePicker_customer_birth_date->Value;
			}
		}


		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~createCustomerPrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ textBox_customer_first_name;
	private: System::Windows::Forms::TextBox^ textBox_customer_last_name;
	public:
	protected:

	protected:

	private: System::Windows::Forms::Label^ label_first_name;
	private: System::Windows::Forms::Label^ label_last_name;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_customer_birth_date;



	private: System::Windows::Forms::Label^ label_birth_date;
	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::Button^ button_cancel;


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
			this->textBox_customer_first_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_customer_last_name = (gcnew System::Windows::Forms::TextBox());
			this->label_first_name = (gcnew System::Windows::Forms::Label());
			this->label_last_name = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_customer_birth_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_birth_date = (gcnew System::Windows::Forms::Label());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_customer_first_name
			// 
			this->textBox_customer_first_name->Location = System::Drawing::Point(148, 52);
			this->textBox_customer_first_name->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_customer_first_name->Name = L"textBox_customer_first_name";
			this->textBox_customer_first_name->Size = System::Drawing::Size(298, 26);
			this->textBox_customer_first_name->TabIndex = 0;
			// 
			// textBox_customer_last_name
			// 
			this->textBox_customer_last_name->Location = System::Drawing::Point(148, 114);
			this->textBox_customer_last_name->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_customer_last_name->Name = L"textBox_customer_last_name";
			this->textBox_customer_last_name->Size = System::Drawing::Size(298, 26);
			this->textBox_customer_last_name->TabIndex = 1;
			// 
			// label_first_name
			// 
			this->label_first_name->AutoSize = true;
			this->label_first_name->Location = System::Drawing::Point(39, 57);
			this->label_first_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_first_name->Name = L"label_first_name";
			this->label_first_name->Size = System::Drawing::Size(84, 20);
			this->label_first_name->TabIndex = 2;
			this->label_first_name->Text = L"First name";
			// 
			// label_last_name
			// 
			this->label_last_name->AutoSize = true;
			this->label_last_name->Location = System::Drawing::Point(39, 118);
			this->label_last_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_last_name->Name = L"label_last_name";
			this->label_last_name->Size = System::Drawing::Size(84, 20);
			this->label_last_name->TabIndex = 3;
			this->label_last_name->Text = L"Last name";
			// 
			// dateTimePicker_customer_birth_date
			// 
			this->dateTimePicker_customer_birth_date->Location = System::Drawing::Point(148, 177);
			this->dateTimePicker_customer_birth_date->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker_customer_birth_date->Name = L"dateTimePicker_customer_birth_date";
			this->dateTimePicker_customer_birth_date->Size = System::Drawing::Size(298, 26);
			this->dateTimePicker_customer_birth_date->TabIndex = 4;
			// 
			// label_birth_date
			// 
			this->label_birth_date->AutoSize = true;
			this->label_birth_date->Location = System::Drawing::Point(39, 183);
			this->label_birth_date->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_birth_date->Name = L"label_birth_date";
			this->label_birth_date->Size = System::Drawing::Size(78, 20);
			this->label_birth_date->TabIndex = 5;
			this->label_birth_date->Text = L"Birth date";
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Location = System::Drawing::Point(148, 271);
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
			this->button_cancel->Location = System::Drawing::Point(297, 271);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(112, 35);
			this->button_cancel->TabIndex = 7;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// createCustomerPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 344);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->label_birth_date);
			this->Controls->Add(this->dateTimePicker_customer_birth_date);
			this->Controls->Add(this->label_last_name);
			this->Controls->Add(this->label_first_name);
			this->Controls->Add(this->textBox_customer_last_name);
			this->Controls->Add(this->textBox_customer_first_name);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximumSize = System::Drawing::Size(550, 400);
			this->MinimumSize = System::Drawing::Size(550, 400);
			this->Name = L"createCustomerPrompt";
			this->Text = L"Create customer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}
