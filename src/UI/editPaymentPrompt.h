#pragma once

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de editPaymentPrompt
	/// </summary>
	public ref class editPaymentPrompt : public System::Windows::Forms::Form
	{
	private:
		String^ windowText;


	// Create constructor
	public:
		editPaymentPrompt(String^ windowText) : windowText(windowText)
		{
			InitializeComponent();
		}

	// Modify constructor
	public:
		editPaymentPrompt(String^ windowText, float amount, DateTime payment_date, String^ paymentMethod) : windowText(windowText)
		{
			InitializeComponent();

			this->numericUpDown_amount->Value = Convert::ToDecimal(amount);
			this->dateTimePicker_payment_date->Value = payment_date;
			this->textBox_payment_method->Text = paymentMethod;

			this->button_create->Text = "Modify";

		}

		property  float amount {
			float get() {
				return Convert::ToSingle(numericUpDown_amount->Value);
			}
      
		void button_save_Click(System::Object^ sender, System::EventArgs^ e) {
			SQLservices^ sqlService = gcnew SQLservices();
			System::DateTime paymentDate = this->dateTimePicker_payment_date->Value;
			System::String^ paymentMethod = this->comboBox_payment_method->Text;
			double amount = Convert::ToDouble(this->textBox_amount->Text);

			if (this->paymentId == -1) {
				// Add new payment
				sqlService->SQL_addPayment(paymentDate, paymentMethod, amount, orderId);
			} else {
				// Update existing payment
				sqlService->SQL_modifyPayment(this->paymentId, paymentDate, paymentMethod, amount, orderId);

		property System::DateTime payment_date {
			DateTime get() {
				return dateTimePicker_payment_date->Value;
			}
		}

		property String^ payment_method {
			String^ get() {
				return textBox_payment_method->Text;
			}
		}
	
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~editPaymentPrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_cancel;
	protected:
	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::Label^ label_amount;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_payment_date;


	private: System::Windows::Forms::Label^ label_method;
	private: System::Windows::Forms::Label^ label_payment_date;


	private: System::Windows::Forms::TextBox^ textBox_payment_method;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_amount;

	private:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->label_amount = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_payment_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_method = (gcnew System::Windows::Forms::Label());
			this->label_payment_date = (gcnew System::Windows::Forms::Label());
			this->textBox_payment_method = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown_amount = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_amount))->BeginInit();
			this->SuspendLayout();
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_cancel->Location = System::Drawing::Point(278, 225);
			this->button_cancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(112, 35);
			this->button_cancel->TabIndex = 9;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_create->Location = System::Drawing::Point(129, 225);
			this->button_create->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(112, 35);
			this->button_create->TabIndex = 8;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			// 
			// label_amount
			// 
			this->label_amount->AutoSize = true;
			this->label_amount->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_amount->Location = System::Drawing::Point(18, 35);
			this->label_amount->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_amount->Name = L"label_amount";
			this->label_amount->Size = System::Drawing::Size(84, 24);
			this->label_amount->TabIndex = 11;
			this->label_amount->Text = L"Amount";
			// 
			// dateTimePicker_payment_date
			// 
			this->dateTimePicker_payment_date->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->dateTimePicker_payment_date->Location = System::Drawing::Point(189, 89);
			this->dateTimePicker_payment_date->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker_payment_date->Name = L"dateTimePicker_payment_date";
			this->dateTimePicker_payment_date->Size = System::Drawing::Size(296, 31);
			this->dateTimePicker_payment_date->TabIndex = 10;
			// 
			// label_method
			// 
			this->label_method->AutoSize = true;
			this->label_method->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_method->Location = System::Drawing::Point(18, 158);
			this->label_method->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_method->Name = L"label_method";
			this->label_method->Size = System::Drawing::Size(171, 24);
			this->label_method->TabIndex = 15;
			this->label_method->Text = L"Payment method";
			// 
			// label_payment_date
			// 
			this->label_payment_date->AutoSize = true;
			this->label_payment_date->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->label_payment_date->Location = System::Drawing::Point(18, 98);
			this->label_payment_date->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_payment_date->Name = L"label_payment_date";
			this->label_payment_date->Size = System::Drawing::Size(143, 24);
			this->label_payment_date->TabIndex = 14;
			this->label_payment_date->Text = L"Payment Date";
			// 
			// textBox_payment_method
			// 
			this->textBox_payment_method->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->textBox_payment_method->Location = System::Drawing::Point(189, 151);
			this->textBox_payment_method->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox_payment_method->Name = L"textBox_payment_method";
			this->textBox_payment_method->Size = System::Drawing::Size(296, 31);
			this->textBox_payment_method->TabIndex = 17;
			// 
			// numericUpDown_amount
			// 
			this->numericUpDown_amount->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->numericUpDown_amount->Location = System::Drawing::Point(189, 35);
			this->numericUpDown_amount->Name = L"numericUpDown_amount";
			this->numericUpDown_amount->Size = System::Drawing::Size(296, 31);
			this->numericUpDown_amount->TabIndex = 18;
			// 
			// editPaymentPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(506, 278);
			this->Controls->Add(this->numericUpDown_amount);
			this->Controls->Add(this->textBox_payment_method);
			this->Controls->Add(this->label_method);
			this->Controls->Add(this->label_payment_date);
			this->Controls->Add(this->label_amount);
			this->Controls->Add(this->dateTimePicker_payment_date);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"editPaymentPrompt";
			this->Text = L"editPaymentPrompt";
			this->Load += gcnew System::EventHandler(this, &editPaymentPrompt::editPaymentPrompt_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_amount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
	private: System::Void editPaymentPrompt_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = windowText;
	}
};
}