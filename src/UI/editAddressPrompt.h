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
	public ref class editAddressPrompt : public System::Windows::Forms::Form
	{
	private:
		String^ windowText;
		
	public:
		// Constructor for creating a new address
		editAddressPrompt(String^ windowText) : windowText((windowText))
		{
			InitializeComponent();

		}

		// Constructor for editing an existing address
		editAddressPrompt(String^ windowText, System::String^ city, int postal_code, System::String^ street, int street_number) : windowText((windowText))
		{
			InitializeComponent();

			this->textBox_address_city->Text = city;
			this->textBox_address_postal_code->Text = postal_code.ToString();
			this->textBox_address_street->Text = street;
			this->textBox_address_street_number->Text = street_number.ToString();

			this->button_confirm->Text = "Modify";

			
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
		~editAddressPrompt()
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
	private: System::Windows::Forms::Button^ button_confirm;

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
			this->button_confirm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_address_city
			// 
			this->textBox_address_city->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->textBox_address_city->Location = System::Drawing::Point(156, 42);
			this->textBox_address_city->Margin = System::Windows::Forms::Padding(4);
			this->textBox_address_city->Name = L"textBox_address_city";
			this->textBox_address_city->Size = System::Drawing::Size(265, 31);
			this->textBox_address_city->TabIndex = 4;
			// 
			// textBox_address_street
			// 
			this->textBox_address_street->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->textBox_address_street->Location = System::Drawing::Point(156, 118);
			this->textBox_address_street->Margin = System::Windows::Forms::Padding(4);
			this->textBox_address_street->Name = L"textBox_address_street";
			this->textBox_address_street->Size = System::Drawing::Size(265, 31);
			this->textBox_address_street->TabIndex = 5;
			// 
			// textBox_address_street_number
			// 
			this->textBox_address_street_number->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->textBox_address_street_number->Location = System::Drawing::Point(156, 161);
			this->textBox_address_street_number->Margin = System::Windows::Forms::Padding(4);
			this->textBox_address_street_number->Name = L"textBox_address_street_number";
			this->textBox_address_street_number->Size = System::Drawing::Size(265, 31);
			this->textBox_address_street_number->TabIndex = 6;
			// 
			// textBox_address_postal_code
			// 
			this->textBox_address_postal_code->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->textBox_address_postal_code->Location = System::Drawing::Point(156, 78);
			this->textBox_address_postal_code->Margin = System::Windows::Forms::Padding(4);
			this->textBox_address_postal_code->Name = L"textBox_address_postal_code";
			this->textBox_address_postal_code->Size = System::Drawing::Size(265, 31);
			this->textBox_address_postal_code->TabIndex = 7;
			// 
			// label_address_city
			// 
			this->label_address_city->AutoSize = true;
			this->label_address_city->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_address_city->Location = System::Drawing::Point(26, 44);
			this->label_address_city->Name = L"label_address_city";
			this->label_address_city->Size = System::Drawing::Size(48, 24);
			this->label_address_city->TabIndex = 8;
			this->label_address_city->Text = L"City";
			// 
			// label_address_postal_code
			// 
			this->label_address_postal_code->AutoSize = true;
			this->label_address_postal_code->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_address_postal_code->Location = System::Drawing::Point(26, 81);
			this->label_address_postal_code->Name = L"label_address_postal_code";
			this->label_address_postal_code->Size = System::Drawing::Size(125, 24);
			this->label_address_postal_code->TabIndex = 9;
			this->label_address_postal_code->Text = L"Postal Code";
			// 
			// label_address_street_number
			// 
			this->label_address_street_number->AutoSize = true;
			this->label_address_street_number->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_address_street_number->Location = System::Drawing::Point(26, 163);
			this->label_address_street_number->Name = L"label_address_street_number";
			this->label_address_street_number->Size = System::Drawing::Size(146, 24);
			this->label_address_street_number->TabIndex = 10;
			this->label_address_street_number->Text = L"Street number";
			// 
			// label_address_street
			// 
			this->label_address_street->AutoSize = true;
			this->label_address_street->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_address_street->Location = System::Drawing::Point(26, 121);
			this->label_address_street->Name = L"label_address_street";
			this->label_address_street->Size = System::Drawing::Size(68, 24);
			this->label_address_street->TabIndex = 11;
			this->label_address_street->Text = L"Street";
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_cancel->Location = System::Drawing::Point(253, 219);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(100, 28);
			this->button_cancel->TabIndex = 13;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// button_confirm
			// 
			this->button_confirm->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_confirm->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_confirm->Location = System::Drawing::Point(121, 219);
			this->button_confirm->Margin = System::Windows::Forms::Padding(4);
			this->button_confirm->Name = L"button_confirm";
			this->button_confirm->Size = System::Drawing::Size(100, 28);
			this->button_confirm->TabIndex = 12;
			this->button_confirm->Text = L"Create";
			this->button_confirm->UseVisualStyleBackColor = true;
			// 
			// editAddressPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 273);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_confirm);
			this->Controls->Add(this->label_address_street);
			this->Controls->Add(this->label_address_street_number);
			this->Controls->Add(this->label_address_postal_code);
			this->Controls->Add(this->label_address_city);
			this->Controls->Add(this->textBox_address_postal_code);
			this->Controls->Add(this->textBox_address_street_number);
			this->Controls->Add(this->textBox_address_street);
			this->Controls->Add(this->textBox_address_city);
			this->Font = (gcnew System::Drawing::Font(L"Inter", 7.8F));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximumSize = System::Drawing::Size(491, 329);
			this->MinimumSize = System::Drawing::Size(491, 329);
			this->Name = L"editAddressPrompt";
			this->Text = L"Add address";
			this->Load += gcnew System::EventHandler(this, &editAddressPrompt::createAddressPrompt_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void createAddressPrompt_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = windowText;
	}
};
}
