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
	/// Summary for editProductPrices
	/// </summary>
	public ref class editProductPrices : public System::Windows::Forms::Form
	{
		String^	windowText;
	private: System::Windows::Forms::Label^ label_price_exc_tax;

	public: System::Windows::Forms::TextBox^ textBox_price_exc_tax;
	public:
		editProductPrices(String^ windowText) : windowText(windowText)
		{
			InitializeComponent();
		}

		editProductPrices(String^ windowText, int minimum_amount, double price_excluding_tax, DateTime price_date, int color_rgb_r, int color_rgb_g, int color_rgb_b) : windowText(windowText)
		{
			InitializeComponent();

			this->textBox_minimum_amount->Text = minimum_amount.ToString();
			this->dateTimePicker_price_date->Value = price_date;
			this->textBox_price_exc_tax->Text = price_excluding_tax.ToString();
			this->textBox_red->Text = color_rgb_r.ToString();
			this->textBox_blue->Text = color_rgb_b.ToString();
			this->textBox_green->Text = color_rgb_g.ToString();

			this->button_create->Text = "Create";
		}

	public:
		property int minimum_amount {
			int get() {
				return Convert::ToInt32(textBox_minimum_amount->Text);
			}
		}

		property DateTime price_date {
			DateTime get() {
				return dateTimePicker_price_date->Value;
			}
		}

		property int color_rgb_r {
			int get() {
				return Convert::ToInt32(textBox_red->Text);
			}
		}

		property int color_rgb_g {
			int get() {
				return Convert::ToInt32(textBox_green->Text);
			}
		}

		property int color_rgb_b {
			int get() {
				return Convert::ToInt32(textBox_blue->Text);
			}
		}

		property double price_excluding_tax {
			double get() {
				return Convert::ToDouble(textBox_price_exc_tax->Text);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~editProductPrices()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_cancel;
	protected:
	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::Label^ label_price_date;




	private:

	private: System::Windows::Forms::Label^ label_product_amount;
	public: System::Windows::Forms::TextBox^ textBox_minimum_amount;
	private:

	public:



	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_price_date;
	private: System::Windows::Forms::Button^ button_select_color;


	private: System::Windows::Forms::Label^ label_color_picker;
	public: System::Windows::Forms::TextBox^ textBox_blue;
	private:

	private:
	public: System::Windows::Forms::TextBox^ textBox_green;
	public: System::Windows::Forms::TextBox^ textBox_red;
	private: System::Windows::Forms::Label^ label_red;
	public:
	private: System::Windows::Forms::Label^ label_green;
	private: System::Windows::Forms::Label^ label_blue;


	public:
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
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->label_price_date = (gcnew System::Windows::Forms::Label());
			this->label_product_amount = (gcnew System::Windows::Forms::Label());
			this->textBox_minimum_amount = (gcnew System::Windows::Forms::TextBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->dateTimePicker_price_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->button_select_color = (gcnew System::Windows::Forms::Button());
			this->label_color_picker = (gcnew System::Windows::Forms::Label());
			this->textBox_blue = (gcnew System::Windows::Forms::TextBox());
			this->textBox_green = (gcnew System::Windows::Forms::TextBox());
			this->textBox_red = (gcnew System::Windows::Forms::TextBox());
			this->label_red = (gcnew System::Windows::Forms::Label());
			this->label_green = (gcnew System::Windows::Forms::Label());
			this->label_blue = (gcnew System::Windows::Forms::Label());
			this->label_price_exc_tax = (gcnew System::Windows::Forms::Label());
			this->textBox_price_exc_tax = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Location = System::Drawing::Point(187, 232);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(75, 23);
			this->button_cancel->TabIndex = 27;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Location = System::Drawing::Point(87, 232);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(75, 23);
			this->button_create->TabIndex = 26;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			// 
			// label_price_date
			// 
			this->label_price_date->AutoSize = true;
			this->label_price_date->Location = System::Drawing::Point(17, 88);
			this->label_price_date->Name = L"label_price_date";
			this->label_price_date->Size = System::Drawing::Size(57, 13);
			this->label_price_date->TabIndex = 21;
			this->label_price_date->Text = L"Price Date";
			// 
			// label_product_amount
			// 
			this->label_product_amount->AutoSize = true;
			this->label_product_amount->Location = System::Drawing::Point(16, 14);
			this->label_product_amount->Name = L"label_product_amount";
			this->label_product_amount->Size = System::Drawing::Size(86, 13);
			this->label_product_amount->TabIndex = 20;
			this->label_product_amount->Text = L"Minimum amount";
			// 
			// textBox_minimum_amount
			// 
			this->textBox_minimum_amount->Location = System::Drawing::Point(118, 12);
			this->textBox_minimum_amount->Name = L"textBox_minimum_amount";
			this->textBox_minimum_amount->Size = System::Drawing::Size(200, 20);
			this->textBox_minimum_amount->TabIndex = 18;
			// 
			// dateTimePicker_price_date
			// 
			this->dateTimePicker_price_date->Location = System::Drawing::Point(119, 88);
			this->dateTimePicker_price_date->Name = L"dateTimePicker_price_date";
			this->dateTimePicker_price_date->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_price_date->TabIndex = 28;
			// 
			// button_select_color
			// 
			this->button_select_color->Location = System::Drawing::Point(118, 130);
			this->button_select_color->Name = L"button_select_color";
			this->button_select_color->Size = System::Drawing::Size(200, 23);
			this->button_select_color->TabIndex = 29;
			this->button_select_color->Text = L"Pick a color";
			this->button_select_color->UseVisualStyleBackColor = true;
			this->button_select_color->Click += gcnew System::EventHandler(this, &editProductPrices::button_select_color_Click);
			// 
			// label_color_picker
			// 
			this->label_color_picker->AutoSize = true;
			this->label_color_picker->Location = System::Drawing::Point(16, 135);
			this->label_color_picker->Name = L"label_color_picker";
			this->label_color_picker->Size = System::Drawing::Size(64, 13);
			this->label_color_picker->TabIndex = 30;
			this->label_color_picker->Text = L"Color Picker";
			// 
			// textBox_blue
			// 
			this->textBox_blue->Location = System::Drawing::Point(280, 159);
			this->textBox_blue->Name = L"textBox_blue";
			this->textBox_blue->Size = System::Drawing::Size(38, 20);
			this->textBox_blue->TabIndex = 31;
			// 
			// textBox_green
			// 
			this->textBox_green->Location = System::Drawing::Point(204, 159);
			this->textBox_green->Name = L"textBox_green";
			this->textBox_green->Size = System::Drawing::Size(38, 20);
			this->textBox_green->TabIndex = 32;
			// 
			// textBox_red
			// 
			this->textBox_red->Location = System::Drawing::Point(140, 159);
			this->textBox_red->Name = L"textBox_red";
			this->textBox_red->Size = System::Drawing::Size(38, 20);
			this->textBox_red->TabIndex = 33;
			// 
			// label_red
			// 
			this->label_red->AutoSize = true;
			this->label_red->Location = System::Drawing::Point(116, 166);
			this->label_red->Name = L"label_red";
			this->label_red->Size = System::Drawing::Size(18, 13);
			this->label_red->TabIndex = 34;
			this->label_red->Text = L"R:";
			// 
			// label_green
			// 
			this->label_green->AutoSize = true;
			this->label_green->Location = System::Drawing::Point(184, 166);
			this->label_green->Name = L"label_green";
			this->label_green->Size = System::Drawing::Size(18, 13);
			this->label_green->TabIndex = 35;
			this->label_green->Text = L"G:";
			// 
			// label_blue
			// 
			this->label_blue->AutoSize = true;
			this->label_blue->Location = System::Drawing::Point(256, 166);
			this->label_blue->Name = L"label_blue";
			this->label_blue->Size = System::Drawing::Size(17, 13);
			this->label_blue->TabIndex = 36;
			this->label_blue->Text = L"B:";
			// 
			// label_price_exc_tax
			// 
			this->label_price_exc_tax->AutoSize = true;
			this->label_price_exc_tax->Location = System::Drawing::Point(16, 53);
			this->label_price_exc_tax->Name = L"label_price_exc_tax";
			this->label_price_exc_tax->Size = System::Drawing::Size(89, 13);
			this->label_price_exc_tax->TabIndex = 38;
			this->label_price_exc_tax->Text = L"Price minus taxes";
			// 
			// textBox_price_exc_tax
			// 
			this->textBox_price_exc_tax->Location = System::Drawing::Point(118, 51);
			this->textBox_price_exc_tax->Name = L"textBox_price_exc_tax";
			this->textBox_price_exc_tax->Size = System::Drawing::Size(200, 20);
			this->textBox_price_exc_tax->TabIndex = 37;
			// 
			// editProductPrices
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 267);
			this->Controls->Add(this->label_price_exc_tax);
			this->Controls->Add(this->textBox_price_exc_tax);
			this->Controls->Add(this->label_blue);
			this->Controls->Add(this->label_green);
			this->Controls->Add(this->label_red);
			this->Controls->Add(this->textBox_red);
			this->Controls->Add(this->textBox_green);
			this->Controls->Add(this->textBox_blue);
			this->Controls->Add(this->label_color_picker);
			this->Controls->Add(this->button_select_color);
			this->Controls->Add(this->dateTimePicker_price_date);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->label_price_date);
			this->Controls->Add(this->label_product_amount);
			this->Controls->Add(this->textBox_minimum_amount);
			this->Name = L"editProductPrices";
			this->Text = L"editProductPrices";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_select_color_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Extract RGB values from the selected color
			int r = this->colorDialog1->Color.R;
			int g = this->colorDialog1->Color.G;
			int b = this->colorDialog1->Color.B;

			this->textBox_red->Text = r.ToString();
			this->textBox_green->Text = g.ToString();
			this->textBox_blue->Text = b.ToString();
		}

	}
	};
}