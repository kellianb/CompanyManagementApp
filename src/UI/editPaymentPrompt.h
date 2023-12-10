#pragma once

#include "../SQL/SQLservices.h"

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
	public:
		editPaymentPrompt(void)
		{
			InitializeComponent();
		}
	public:
		editPaymentPrompt(int paymentId) : paymentId(paymentId)
		{
			InitializeComponent();
			LoadPaymentData(paymentId);
		}

		int paymentId = -1;
		int orderId;
		

		void LoadPaymentData(int paymentId) {
			SQLservices^ sqlService = gcnew SQLservices();
			DataTable^ paymentData = sqlService->SQL_getPayment(paymentId);

			if (paymentData != nullptr && paymentData->Rows->Count > 0)
			{
				DataRow^ row = paymentData->Rows[0];
				// Assuming these columns exist in your payment table
				this->textBox_amount->Text = row["amount"]->ToString();
				this->dateTimePicker_payment_date->Value = Convert::ToDateTime(row["payment_date"]);
				this->comboBox_payment_method->SelectedItem = row["payment_method"]->ToString();
			}
		}

		void button_save_Click(System::Object^ sender, System::EventArgs^ e) {
			SQLservices^ sqlService = gcnew SQLservices();
			System::DateTime paymentDate = this->dateTimePicker_payment_date->Value;
			System::String^ paymentMethod = this->comboBox_payment_method->Text;
			double amount = Convert::ToDouble(this->textBox_amount->Text);
			orderId = sqlService->SQL_getOrderFromPayment(this->paymentId);
			
			if (this->paymentId == -1) {
				// Add new payment
				sqlService->SQL_addPayment(paymentDate, paymentMethod, amount, orderId);
			} else {
				// Update existing payment
				sqlService->SQL_modifyPayment(this->paymentId, paymentDate, paymentMethod, amount, orderId);
			}

			this->Close();
		}

		void button_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
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
	private: System::Windows::Forms::TextBox^ textBox_amount;
	private: System::Windows::Forms::ComboBox^ comboBox_payment_method;






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
			this->textBox_amount = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_payment_method = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button_cancel->Location = System::Drawing::Point(185, 146);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(75, 23);
			this->button_cancel->TabIndex = 9;
			this->button_cancel->Text = L"Cancel";
			this->button_cancel->UseVisualStyleBackColor = true;
			this->button_cancel->Click += gcnew System::EventHandler(this, &editPaymentPrompt::button_cancel_Click);
			// 
			// button_create
			// 
			this->button_create->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_create->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button_create->Location = System::Drawing::Point(86, 146);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(75, 23);
			this->button_create->TabIndex = 8;
			this->button_create->Text = L"Create";
			this->button_create->UseVisualStyleBackColor = true;
			this->button_create->Click += gcnew System::EventHandler(this, &editPaymentPrompt::button_save_Click);
			// 
			// label_amount
			// 
			this->label_amount->AutoSize = true;
			this->label_amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label_amount->Location = System::Drawing::Point(12, 23);
			this->label_amount->Name = L"label_amount";
			this->label_amount->Size = System::Drawing::Size(52, 16);
			this->label_amount->TabIndex = 11;
			this->label_amount->Text = L"Amount";
			// 
			// dateTimePicker_payment_date
			// 
			this->dateTimePicker_payment_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->dateTimePicker_payment_date->Location = System::Drawing::Point(126, 58);
			this->dateTimePicker_payment_date->Name = L"dateTimePicker_payment_date";
			this->dateTimePicker_payment_date->Size = System::Drawing::Size(199, 22);
			this->dateTimePicker_payment_date->TabIndex = 10;
			// 
			// label_method
			// 
			this->label_method->AutoSize = true;
			this->label_method->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label_method->Location = System::Drawing::Point(12, 103);
			this->label_method->Name = L"label_method";
			this->label_method->Size = System::Drawing::Size(108, 16);
			this->label_method->TabIndex = 15;
			this->label_method->Text = L"Payment method";
			// 
			// label_payment_date
			// 
			this->label_payment_date->AutoSize = true;
			this->label_payment_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label_payment_date->Location = System::Drawing::Point(12, 64);
			this->label_payment_date->Name = L"label_payment_date";
			this->label_payment_date->Size = System::Drawing::Size(92, 16);
			this->label_payment_date->TabIndex = 14;
			this->label_payment_date->Text = L"Payment Date";
			// 
			// textBox_amount
			// 
			this->textBox_amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->textBox_amount->Location = System::Drawing::Point(126, 20);
			this->textBox_amount->Name = L"textBox_amount";
			this->textBox_amount->Size = System::Drawing::Size(199, 22);
			this->textBox_amount->TabIndex = 13;
			// 
			// comboBox_payment_method
			// 
			this->comboBox_payment_method->FormattingEnabled = true;
			this->comboBox_payment_method->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Cash", L"Card", L"Crypto" });
			this->comboBox_payment_method->Location = System::Drawing::Point(126, 98);
			this->comboBox_payment_method->Name = L"comboBox_payment_method";
			this->comboBox_payment_method->Size = System::Drawing::Size(199, 21);
			this->comboBox_payment_method->TabIndex = 16;
			// 
			// editPaymentPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 181);
			this->Controls->Add(this->comboBox_payment_method);
			this->Controls->Add(this->label_method);
			this->Controls->Add(this->label_payment_date);
			this->Controls->Add(this->textBox_amount);
			this->Controls->Add(this->label_amount);
			this->Controls->Add(this->dateTimePicker_payment_date);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_create);
			this->Name = L"editPaymentPrompt";
			this->Text = L"editPaymentPrompt";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
