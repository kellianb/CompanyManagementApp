#pragma once

#include "editPaymentPrompt.h"
#include "../SQL/SQLservices.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de PaymentListForm
	/// </summary>
	public ref class managePaymentPrompt : public System::Windows::Forms::Form
	{
	public:
		managePaymentPrompt(int order_id) : order_id(order_id)
		{
			InitializeComponent();
			refresh_datagridview();
		}

	public:
		property int order_id;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~managePaymentPrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: SQLservices^ SQLserv = gcnew SQLservices;
	private: System::Windows::Forms::DataGridView^ dataGridView_payment;
	private: System::Windows::Forms::Button^ button_delete_payment;
	protected:


	private: System::Windows::Forms::Button^ button_add_payment;
	private: System::Windows::Forms::Button^ button_modify_payment;


	private: System::Windows::Forms::Button^ button_cancel;
	protected:

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
			this->dataGridView_payment = (gcnew System::Windows::Forms::DataGridView());
			this->button_delete_payment = (gcnew System::Windows::Forms::Button());
			this->button_add_payment = (gcnew System::Windows::Forms::Button());
			this->button_modify_payment = (gcnew System::Windows::Forms::Button());
			this->button_cancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_payment))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_payment
			// 
			this->dataGridView_payment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_payment->Location = System::Drawing::Point(12, 12);
			this->dataGridView_payment->Name = L"dataGridView_payment";
			this->dataGridView_payment->Size = System::Drawing::Size(335, 197);
			this->dataGridView_payment->TabIndex = 0;
			// 
			// button_delete_payment
			// 
			this->button_delete_payment->Location = System::Drawing::Point(246, 214);
			this->button_delete_payment->Margin = System::Windows::Forms::Padding(2);
			this->button_delete_payment->Name = L"button_delete_payment";
			this->button_delete_payment->Size = System::Drawing::Size(88, 30);
			this->button_delete_payment->TabIndex = 9;
			this->button_delete_payment->Text = L"Delete";
			this->button_delete_payment->UseVisualStyleBackColor = true;
			this->button_delete_payment->Click += gcnew System::EventHandler(this, &managePaymentPrompt::button_delete_payment_Click);
			// 
			// button_add_payment
			// 
			this->button_add_payment->Location = System::Drawing::Point(28, 214);
			this->button_add_payment->Margin = System::Windows::Forms::Padding(2);
			this->button_add_payment->Name = L"button_add_payment";
			this->button_add_payment->Size = System::Drawing::Size(88, 30);
			this->button_add_payment->TabIndex = 7;
			this->button_add_payment->Text = L"Add";
			this->button_add_payment->UseVisualStyleBackColor = true;
			this->button_add_payment->Click += gcnew System::EventHandler(this, &managePaymentPrompt::button_add_payment_Click);
			// 
			// button_modify_payment
			// 
			this->button_modify_payment->Location = System::Drawing::Point(136, 214);
			this->button_modify_payment->Margin = System::Windows::Forms::Padding(2);
			this->button_modify_payment->Name = L"button_modify_payment";
			this->button_modify_payment->Size = System::Drawing::Size(88, 30);
			this->button_modify_payment->TabIndex = 8;
			this->button_modify_payment->Text = L"Modify";
			this->button_modify_payment->UseVisualStyleBackColor = true;
			this->button_modify_payment->Click += gcnew System::EventHandler(this, &managePaymentPrompt::button_modify_payment_Click);
			// 
			// button_cancel
			// 
			this->button_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button_cancel->Location = System::Drawing::Point(142, 258);
			this->button_cancel->Name = L"button_cancel";
			this->button_cancel->Size = System::Drawing::Size(75, 23);
			this->button_cancel->TabIndex = 10;
			this->button_cancel->Text = L"Close";
			this->button_cancel->UseVisualStyleBackColor = true;
			this->button_cancel->Click += gcnew System::EventHandler(this, &managePaymentPrompt::button_cancel_Click);
			// 
			// managePaymentPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(359, 293);
			this->Controls->Add(this->button_cancel);
			this->Controls->Add(this->button_delete_payment);
			this->Controls->Add(this->button_add_payment);
			this->Controls->Add(this->button_modify_payment);
			this->Controls->Add(this->dataGridView_payment);
			this->Name = L"managePaymentPrompt";
			this->Text = L"PaymentListForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_payment))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void refresh_datagridview()
		{
			this->dataGridView_payment->DataSource = SQLserv->SQL_getPaymentList();
			this->dataGridView_payment->DataMember = "Payment";

			this->dataGridView_payment->Columns[0]->HeaderText = "ID";
			this->dataGridView_payment->Columns[1]->HeaderText = "Amount";
			this->dataGridView_payment->Columns[2]->HeaderText = "Date";
			this->dataGridView_payment->Columns[3]->HeaderText = "Method";
		}

	private:
		System::Void managePaymentPrompt::button_add_payment_Click(System::Object^ sender, System::EventArgs^ e) {
			editPaymentPrompt^ editPaymentForm = gcnew editPaymentPrompt();
			editPaymentForm->ShowDialog();
			refresh_datagridview();
		}


	private:
		System::Void button_modify_payment_Click(System::Object^ sender, System::EventArgs^ e)
		{
		editPaymentPrompt^ editPaymentForm = gcnew editPaymentPrompt();
			if (dataGridView_payment->SelectedRows->Count > 0) {
				int selectedPaymentId = Convert::ToInt32(dataGridView_payment->SelectedRows[0]->Cells["id_payment"]->Value);
				editPaymentPrompt^ modifyPaymentForm = gcnew editPaymentPrompt(selectedPaymentId); // Constructor for editing

				modifyPaymentForm->ShowDialog();

				// Refresh the DataGridView after modifying the payment
				refresh_datagridview();
			} else {
				MessageBox::Show("Please select a payment to modify.");
			}
		}

	private:
		System::Void button_delete_payment_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SQLserv->SQL_deletePayment(Convert::ToInt32(this->dataGridView_payment->CurrentRow->Cells[0]->Value));
			refresh_datagridview();
		}

	private:
		System::Void button_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
