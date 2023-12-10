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

			this->button_create->Text = "Create";
			this->button_create->Enabled = false;
		}

		editProductPrices(String^ windowText, int minimum_amount, double price_excluding_tax, DateTime price_date, int color_rgb_r, int color_rgb_g, int color_rgb_b) : windowText(windowText)
		{
			InitializeComponent();

			this->textBox_minimum_amount->Text = minimum_amount.ToString();
			this->dateTimePicker_price_date->Value = price_date;
			this->textBox_price_exc_tax->Text = price_excluding_tax.ToString();

			this->colorDialog_product_price->Color = Color::FromArgb(color_rgb_r, color_rgb_g, color_rgb_b);

			this->label_red->Text = "R: " + color_rgb_r;
			this->label_green->Text = "G: " + color_rgb_g;
			this->label_blue->Text = "B: " + color_rgb_b;
			
			this->button_create->Text = "Modify";
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
				return this->colorDialog_product_price->Color.R;
			}
		}

		property int color_rgb_g {
			int get() {
				return this->colorDialog_product_price->Color.G;
			}
		}

		property int color_rgb_b {
			int get() {
				return this->colorDialog_product_price->Color.B;
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



	private: System::Windows::Forms::ColorDialog^ colorDialog_product_price;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_price_date;
	private: System::Windows::Forms::Button^ button_select_color;


	private: System::Windows::Forms::Label^ label_color_picker;

	private:

	private:


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
			this->colorDialog_product_price = (gcnew System::Windows::Forms::ColorDialog());
			this->dateTimePicker_price_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->button_select_color = (gcnew System::Windows::Forms::Button());
			this->label_color_picker = (gcnew System::Windows::Forms::Label());
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
			this->button_cancel->Location = System::Drawing::Point(249, 286);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(100, 28);
			this->button_cancel->TabIndex = 27;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Location = System::Drawing::Point(116, 286);
			this->button_create->Margin = System::Windows::Forms::Padding(4);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(100, 28);
			this->button_create->TabIndex = 26;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			// 
			// label_price_date
			// 
			this->label_price_date->AutoSize = true;
			this->label_price_date->Location = System::Drawing::Point(23, 108);
			this->label_price_date->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_price_date->Name = L"label_price_date";
			this->label_price_date->Size = System::Drawing::Size(70, 16);
			this->label_price_date->TabIndex = 21;
			this->label_price_date->Text = L"Price Date";
			// 
			// label_product_amount
			// 
			this->label_product_amount->AutoSize = true;
			this->label_product_amount->Location = System::Drawing::Point(21, 17);
			this->label_product_amount->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_product_amount->Name = L"label_product_amount";
			this->label_product_amount->Size = System::Drawing::Size(107, 16);
			this->label_product_amount->TabIndex = 20;
			this->label_product_amount->Text = L"Minimum amount";
			// 
			// textBox_minimum_amount
			// 
			this->textBox_minimum_amount->Location = System::Drawing::Point(157, 15);
			this->textBox_minimum_amount->Margin = System::Windows::Forms::Padding(4);
			this->textBox_minimum_amount->Name = L"textBox_minimum_amount";
			this->textBox_minimum_amount->Size = System::Drawing::Size(265, 22);
			this->textBox_minimum_amount->TabIndex = 18;
			// 
			// dateTimePicker_price_date
			// 
			this->dateTimePicker_price_date->Location = System::Drawing::Point(159, 108);
			this->dateTimePicker_price_date->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_price_date->Name = L"dateTimePicker_price_date";
			this->dateTimePicker_price_date->Size = System::Drawing::Size(265, 22);
			this->dateTimePicker_price_date->TabIndex = 28;
			// 
			// button_select_color
			// 
			this->button_select_color->Location = System::Drawing::Point(157, 160);
			this->button_select_color->Margin = System::Windows::Forms::Padding(4);
			this->button_select_color->Name = L"button_select_color";
			this->button_select_color->Size = System::Drawing::Size(267, 28);
			this->button_select_color->TabIndex = 29;
			this->button_select_color->Text = L"Pick a color";
			this->button_select_color->UseVisualStyleBackColor = true;
			this->button_select_color->Click += gcnew System::EventHandler(this, &editProductPrices::button_select_color_Click);
			// 
			// label_color_picker
			// 
			this->label_color_picker->AutoSize = true;
			this->label_color_picker->Location = System::Drawing::Point(21, 166);
			this->label_color_picker->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_color_picker->Name = L"label_color_picker";
			this->label_color_picker->Size = System::Drawing::Size(80, 16);
			this->label_color_picker->TabIndex = 30;
			this->label_color_picker->Text = L"Color Picker";
			// 
			// label_red
			// 
			this->label_red->AutoSize = true;
			this->label_red->Location = System::Drawing::Point(159, 199);
			this->label_red->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_red->Name = L"label_red";
			this->label_red->Size = System::Drawing::Size(20, 16);
			this->label_red->TabIndex = 34;
			this->label_red->Text = L"R:";
			// 
			// label_green
			// 
			this->label_green->AutoSize = true;
			this->label_green->Location = System::Drawing::Point(159, 224);
			this->label_green->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_green->Name = L"label_green";
			this->label_green->Size = System::Drawing::Size(20, 16);
			this->label_green->TabIndex = 35;
			this->label_green->Text = L"G:";
			// 
			// label_blue
			// 
			this->label_blue->AutoSize = true;
			this->label_blue->Location = System::Drawing::Point(159, 249);
			this->label_blue->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_blue->Name = L"label_blue";
			this->label_blue->Size = System::Drawing::Size(19, 16);
			this->label_blue->TabIndex = 36;
			this->label_blue->Text = L"B:";
			// 
			// label_price_exc_tax
			// 
			this->label_price_exc_tax->AutoSize = true;
			this->label_price_exc_tax->Location = System::Drawing::Point(21, 65);
			this->label_price_exc_tax->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_price_exc_tax->Name = L"label_price_exc_tax";
			this->label_price_exc_tax->Size = System::Drawing::Size(111, 16);
			this->label_price_exc_tax->TabIndex = 38;
			this->label_price_exc_tax->Text = L"Price minus taxes";
			// 
			// textBox_price_exc_tax
			// 
			this->textBox_price_exc_tax->Location = System::Drawing::Point(157, 63);
			this->textBox_price_exc_tax->Margin = System::Windows::Forms::Padding(4);
			this->textBox_price_exc_tax->Name = L"textBox_price_exc_tax";
			this->textBox_price_exc_tax->Size = System::Drawing::Size(265, 22);
			this->textBox_price_exc_tax->TabIndex = 37;
			// 
			// editProductPrices
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(452, 329);
			this->Controls->Add(this->label_price_exc_tax);
			this->Controls->Add(this->textBox_price_exc_tax);
			this->Controls->Add(this->label_blue);
			this->Controls->Add(this->label_green);
			this->Controls->Add(this->label_red);
			this->Controls->Add(this->label_color_picker);
			this->Controls->Add(this->button_select_color);
			this->Controls->Add(this->dateTimePicker_price_date);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->label_price_date);
			this->Controls->Add(this->label_product_amount);
			this->Controls->Add(this->textBox_minimum_amount);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(470, 376);
			this->MinimumSize = System::Drawing::Size(470, 376);
			this->Name = L"editProductPrices";
			this->Text = L"editProductPrices";
			this->Load += gcnew System::EventHandler(this, &editProductPrices::editProductPrices_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void editProductPrices_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = windowText;
	}
		
	private: System::Void button_select_color_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->colorDialog_product_price->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			
			// Extract RGB values from the selected color
			int r = this->colorDialog_product_price->Color.R;
			int g = this->colorDialog_product_price->Color.G;
			int b = this->colorDialog_product_price->Color.B;

			this->label_red->Text = "R: " + r.ToString();
			this->label_green->Text = "G: " + g.ToString();
			this->label_blue->Text = "B: " + b.ToString();

			this->button_create->Enabled = true;
		}

	}

};
}