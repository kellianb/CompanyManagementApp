#pragma once

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for createAddress
	/// </summary>
	public ref class createAddressPrompt : public System::Windows::Forms::Form
	{
	private:
		String^ windowText;
		
	public:
		createAddressPrompt(String^ windowText) : windowText((windowText))
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public:
		property String^ new_address_city {
			String^ get() {
				return textBox_address_city->Text;
			}
		}
		property int new_address_postal_code {
			int get() {
				return Convert::ToInt32(textBox_address_postal_code->Text);
			}
		}
		property String^ new_address_street {
			String^ get() {
				return textBox_address_street->Text;
			}
		}
		property int new_address_street_number {
			int get() {
				return Convert::ToInt32(textBox_address_street_number->Text);
			}
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~createAddressPrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ textBox_address_city;
	protected:

	protected:

	protected:

	protected:

	protected:
	public: System::Windows::Forms::TextBox^ textBox_address_street;
	public: System::Windows::Forms::TextBox^ textBox_address_street_number;
	public: System::Windows::Forms::TextBox^ textBox_address_postal_code;
	private: System::Windows::Forms::Label^ label_address_city;
	private: System::Windows::Forms::Label^ label_address_postal_code;
	private: System::Windows::Forms::Label^ label_address_street_number;
	private: System::Windows::Forms::Label^ label_address_street;
	public:

	public:



	private: System::Windows::Forms::Button^ button_cancel;
	private: System::Windows::Forms::Button^ button_create;

	protected:




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
			this->textBox_address_city = (gcnew System::Windows::Forms::TextBox());
			this->textBox_address_street = (gcnew System::Windows::Forms::TextBox());
			this->textBox_address_street_number = (gcnew System::Windows::Forms::TextBox());
			this->textBox_address_postal_code = (gcnew System::Windows::Forms::TextBox());
			this->label_address_city = (gcnew System::Windows::Forms::Label());
			this->label_address_postal_code = (gcnew System::Windows::Forms::Label());
			this->label_address_street_number = (gcnew System::Windows::Forms::Label());
			this->label_address_street = (gcnew System::Windows::Forms::Label());
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_address_city
			// 
			this->textBox_address_city->Location = System::Drawing::Point(163, 52);
			this->textBox_address_city->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_city->Name = L"textBox_address_city";
			this->textBox_address_city->Size = System::Drawing::Size(298, 26);
			this->textBox_address_city->TabIndex = 4;
			// 
			// textBox_address_street
			// 
			this->textBox_address_street->Location = System::Drawing::Point(163, 148);
			this->textBox_address_street->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_street->Name = L"textBox_address_street";
			this->textBox_address_street->Size = System::Drawing::Size(298, 26);
			this->textBox_address_street->TabIndex = 5;
			// 
			// textBox_address_street_number
			// 
			this->textBox_address_street_number->Location = System::Drawing::Point(163, 201);
			this->textBox_address_street_number->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_street_number->Name = L"textBox_address_street_number";
			this->textBox_address_street_number->Size = System::Drawing::Size(298, 26);
			this->textBox_address_street_number->TabIndex = 6;
			// 
			// textBox_address_postal_code
			// 
			this->textBox_address_postal_code->Location = System::Drawing::Point(163, 98);
			this->textBox_address_postal_code->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_address_postal_code->Name = L"textBox_address_postal_code";
			this->textBox_address_postal_code->Size = System::Drawing::Size(298, 26);
			this->textBox_address_postal_code->TabIndex = 7;
			// 
			// label_address_city
			// 
			this->label_address_city->AutoSize = true;
			this->label_address_city->Location = System::Drawing::Point(29, 55);
			this->label_address_city->Name = L"label_address_city";
			this->label_address_city->Size = System::Drawing::Size(35, 20);
			this->label_address_city->TabIndex = 8;
			this->label_address_city->Text = L"City";
			// 
			// label_address_postal_code
			// 
			this->label_address_postal_code->AutoSize = true;
			this->label_address_postal_code->Location = System::Drawing::Point(29, 101);
			this->label_address_postal_code->Name = L"label_address_postal_code";
			this->label_address_postal_code->Size = System::Drawing::Size(95, 20);
			this->label_address_postal_code->TabIndex = 9;
			this->label_address_postal_code->Text = L"Postal Code";
			// 
			// label_address_street_number
			// 
			this->label_address_street_number->AutoSize = true;
			this->label_address_street_number->Location = System::Drawing::Point(29, 204);
			this->label_address_street_number->Name = L"label_address_street_number";
			this->label_address_street_number->Size = System::Drawing::Size(111, 20);
			this->label_address_street_number->TabIndex = 10;
			this->label_address_street_number->Text = L"Street number";
			// 
			// label_address_street
			// 
			this->label_address_street->AutoSize = true;
			this->label_address_street->Location = System::Drawing::Point(29, 151);
			this->label_address_street->Name = L"label_address_street";
			this->label_address_street->Size = System::Drawing::Size(53, 20);
			this->label_address_street->TabIndex = 11;
			this->label_address_street->Text = L"Street";
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Location = System::Drawing::Point(314, 261);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(112, 35);
			this->button_cancel->TabIndex = 13;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Location = System::Drawing::Point(165, 261);
			this->button_create->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(112, 35);
			this->button_create->TabIndex = 12;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			// 
			// createAddressPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 344);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->label_address_street);
			this->Controls->Add(this->label_address_street_number);
			this->Controls->Add(this->label_address_postal_code);
			this->Controls->Add(this->label_address_city);
			this->Controls->Add(this->textBox_address_postal_code);
			this->Controls->Add(this->textBox_address_street_number);
			this->Controls->Add(this->textBox_address_street);
			this->Controls->Add(this->textBox_address_city);
			this->MaximumSize = System::Drawing::Size(550, 400);
			this->MinimumSize = System::Drawing::Size(550, 400);
			this->Name = L"createAddressPrompt";
			this->Text = L"Add address";
			this->Load += gcnew System::EventHandler(this, &createAddressPrompt::createAddressPrompt_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void createAddressPrompt_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = windowText;
	}
};
}
