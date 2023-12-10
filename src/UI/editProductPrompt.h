#pragma once

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for createProductPrompt
	/// </summary>
	public ref class editProductPrompt : public System::Windows::Forms::Form
	{
	String^	windowText;
		
	public:
		editProductPrompt(String^ windowText) : windowText(windowText)
		{
			InitializeComponent();
		}


		editProductPrompt(String^ windowText, System::String^ product_name, int amount_in_stock, int reorder_threshold, float vat_percentage) : windowText(windowText)
		{
			InitializeComponent();

			this->textBox_product_name->Text = product_name;
			this->textBox_amount_in_stock->Text = amount_in_stock.ToString();
			this->textBox_reorder_threshold->Text = reorder_threshold.ToString();
			this->textBox_product_vat->Text = vat_percentage.ToString();

			this->button_create->Text = "Modify";
		}

	public:
		property String^ product_name {
			String^ get() {
				return textBox_product_name->Text;
			}
		}

		property int amount_in_stock {
			int get() {
				return Convert::ToInt32(textBox_amount_in_stock->Text);
			}
		}

		property int reorder_threshold {
			int get() {
				return Convert::ToInt32(textBox_reorder_threshold->Text);
			}
		}

		property float vat_percentage {
			float get() {
				return Convert::ToSingle(textBox_product_vat->Text);
			}
		}
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~editProductPrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_amount_in_stock;
	private: System::Windows::Forms::Label^ label_product_name;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ textBox_amount_in_stock;
	public: System::Windows::Forms::TextBox^ textBox_product_name;
	private:

	private:

	private:


	private: System::Windows::Forms::Label^ label_product_vat;
	private: System::Windows::Forms::Label^ label_reorder_threshold;
	public:

	public:
	private:

	public:

	private: System::Windows::Forms::TextBox^ textBox_product_vat;
	public: System::Windows::Forms::TextBox^ textBox_reorder_threshold;
	private:


	private: System::Windows::Forms::Button^ button_cancel;
	public:
	private: System::Windows::Forms::Button^ button_create;
	private:

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
			this->label_amount_in_stock = (gcnew System::Windows::Forms::Label());
			this->label_product_name = (gcnew System::Windows::Forms::Label());
			this->textBox_amount_in_stock = (gcnew System::Windows::Forms::TextBox());
			this->textBox_product_name = (gcnew System::Windows::Forms::TextBox());
			this->label_product_vat = (gcnew System::Windows::Forms::Label());
			this->label_reorder_threshold = (gcnew System::Windows::Forms::Label());
			this->textBox_product_vat = (gcnew System::Windows::Forms::TextBox());
			this->textBox_reorder_threshold = (gcnew System::Windows::Forms::TextBox());
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_amount_in_stock
			// 
			this->label_amount_in_stock->AutoSize = true;
			this->label_amount_in_stock->Location = System::Drawing::Point(21, 88);
			this->label_amount_in_stock->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_amount_in_stock->Name = L"label_amount_in_stock";
			this->label_amount_in_stock->Size = System::Drawing::Size(102, 16);
			this->label_amount_in_stock->TabIndex = 7;
			this->label_amount_in_stock->Text = L"Amount in Stock";
			// 
			// label_product_name
			// 
			this->label_product_name->AutoSize = true;
			this->label_product_name->Location = System::Drawing::Point(21, 40);
			this->label_product_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_product_name->Name = L"label_product_name";
			this->label_product_name->Size = System::Drawing::Size(90, 16);
			this->label_product_name->TabIndex = 6;
			this->label_product_name->Text = L"Product name";
			// 
			// textBox_amount_in_stock
			// 
			this->textBox_amount_in_stock->Location = System::Drawing::Point(157, 86);
			this->textBox_amount_in_stock->Margin = System::Windows::Forms::Padding(4);
			this->textBox_amount_in_stock->Name = L"textBox_amount_in_stock";
			this->textBox_amount_in_stock->Size = System::Drawing::Size(265, 22);
			this->textBox_amount_in_stock->TabIndex = 5;
			// 
			// textBox_product_name
			// 
			this->textBox_product_name->Location = System::Drawing::Point(157, 37);
			this->textBox_product_name->Margin = System::Windows::Forms::Padding(4);
			this->textBox_product_name->Name = L"textBox_product_name";
			this->textBox_product_name->Size = System::Drawing::Size(265, 22);
			this->textBox_product_name->TabIndex = 4;
			// 
			// label_product_vat
			// 
			this->label_product_vat->AutoSize = true;
			this->label_product_vat->Location = System::Drawing::Point(21, 186);
			this->label_product_vat->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_product_vat->Name = L"label_product_vat";
			this->label_product_vat->Size = System::Drawing::Size(49, 16);
			this->label_product_vat->TabIndex = 15;
			this->label_product_vat->Text = L"VAT %";
			// 
			// label_reorder_threshold
			// 
			this->label_reorder_threshold->AutoSize = true;
			this->label_reorder_threshold->Location = System::Drawing::Point(21, 138);
			this->label_reorder_threshold->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_reorder_threshold->Name = L"label_reorder_threshold";
			this->label_reorder_threshold->Size = System::Drawing::Size(115, 16);
			this->label_reorder_threshold->TabIndex = 14;
			this->label_reorder_threshold->Text = L"Reorder threshold";
			// 
			// textBox_product_vat
			// 
			this->textBox_product_vat->Location = System::Drawing::Point(157, 184);
			this->textBox_product_vat->Margin = System::Windows::Forms::Padding(4);
			this->textBox_product_vat->Name = L"textBox_product_vat";
			this->textBox_product_vat->Size = System::Drawing::Size(265, 22);
			this->textBox_product_vat->TabIndex = 13;
			// 
			// textBox_reorder_threshold
			// 
			this->textBox_reorder_threshold->Location = System::Drawing::Point(157, 135);
			this->textBox_reorder_threshold->Margin = System::Windows::Forms::Padding(4);
			this->textBox_reorder_threshold->Name = L"textBox_reorder_threshold";
			this->textBox_reorder_threshold->Size = System::Drawing::Size(265, 22);
			this->textBox_reorder_threshold->TabIndex = 12;
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Location = System::Drawing::Point(234, 246);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(100, 28);
			this->button_cancel->TabIndex = 17;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Location = System::Drawing::Point(102, 246);
			this->button_create->Margin = System::Windows::Forms::Padding(4);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(100, 28);
			this->button_create->TabIndex = 16;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			// 
			// editProductPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(452, 296);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->label_product_vat);
			this->Controls->Add(this->label_reorder_threshold);
			this->Controls->Add(this->textBox_product_vat);
			this->Controls->Add(this->textBox_reorder_threshold);
			this->Controls->Add(this->label_amount_in_stock);
			this->Controls->Add(this->label_product_name);
			this->Controls->Add(this->textBox_amount_in_stock);
			this->Controls->Add(this->textBox_product_name);
			this->MaximumSize = System::Drawing::Size(470, 343);
			this->MinimumSize = System::Drawing::Size(470, 343);
			this->Name = L"editProductPrompt";
			this->Text = L"createProductPrompt";
			this->Load += gcnew System::EventHandler(this, &editProductPrompt::editProductPrompt_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void editProductPrompt_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = windowText;
	}
};
}
