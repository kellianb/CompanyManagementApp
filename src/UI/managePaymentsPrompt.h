#pragma once

#include "editPaymentPrompt.h"
#include "../SQL/SQLservices.h"
#include "../Payments.h"
#include "../Order.h"


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
	public ref class managePaymentsPrompt : public System::Windows::Forms::Form
	{
	public:
	private:
		Order^ current_order;
		Payment^ selected_payment;

	public:
		managePaymentsPrompt(int order_id)
		{
			current_order = gcnew Order(order_id);
			
			InitializeComponent();
			refresh_dataGridView_order_payments();
		}
	
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~managePaymentsPrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: SQLservices^ SQLserv = gcnew SQLservices;
	private: System::Windows::Forms::DataGridView^ dataGridView_order_payments;
	private: System::Windows::Forms::Button^ button_delete_payment;
	protected:


	private: System::Windows::Forms::Button^ button_add_payment;
	private: System::Windows::Forms::Button^ button_modify_payment;


	private: System::Windows::Forms::Button^ button_close;
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
			this->dataGridView_order_payments = (gcnew System::Windows::Forms::DataGridView());
			this->button_delete_payment = (gcnew System::Windows::Forms::Button());
			this->button_add_payment = (gcnew System::Windows::Forms::Button());
			this->button_modify_payment = (gcnew System::Windows::Forms::Button());
			this->button_close = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_order_payments))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_order_payments
			// 
			this->dataGridView_order_payments->AllowUserToAddRows = false;
			this->dataGridView_order_payments->AllowUserToDeleteRows = false;
			this->dataGridView_order_payments->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_order_payments->Location = System::Drawing::Point(18, 18);
			this->dataGridView_order_payments->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView_order_payments->MultiSelect = false;
			this->dataGridView_order_payments->Name = L"dataGridView_order_payments";
			this->dataGridView_order_payments->ReadOnly = true;
			this->dataGridView_order_payments->RowHeadersWidth = 62;
			this->dataGridView_order_payments->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_order_payments->Size = System::Drawing::Size(502, 303);
			this->dataGridView_order_payments->TabIndex = 0;
			this->dataGridView_order_payments->SelectionChanged += gcnew System::EventHandler(this, &managePaymentsPrompt::dataGridView_order_payments_selectionChanged);
			// 
			// button_delete_payment
			// 
			this->button_delete_payment->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_delete_payment->Location = System::Drawing::Point(369, 329);
			this->button_delete_payment->Name = L"button_delete_payment";
			this->button_delete_payment->Size = System::Drawing::Size(132, 46);
			this->button_delete_payment->TabIndex = 9;
			this->button_delete_payment->Text = L"Delete";
			this->button_delete_payment->UseVisualStyleBackColor = true;
			this->button_delete_payment->Click += gcnew System::EventHandler(this, &managePaymentsPrompt::button_delete_payment_Click);
			// 
			// button_add_payment
			// 
			this->button_add_payment->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_add_payment->Location = System::Drawing::Point(42, 329);
			this->button_add_payment->Name = L"button_add_payment";
			this->button_add_payment->Size = System::Drawing::Size(132, 46);
			this->button_add_payment->TabIndex = 7;
			this->button_add_payment->Text = L"Add";
			this->button_add_payment->UseVisualStyleBackColor = true;
			this->button_add_payment->Click += gcnew System::EventHandler(this, &managePaymentsPrompt::button_add_payment_Click);
			// 
			// button_modify_payment
			// 
			this->button_modify_payment->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_modify_payment->Location = System::Drawing::Point(204, 329);
			this->button_modify_payment->Name = L"button_modify_payment";
			this->button_modify_payment->Size = System::Drawing::Size(132, 46);
			this->button_modify_payment->TabIndex = 8;
			this->button_modify_payment->Text = L"Modify";
			this->button_modify_payment->UseVisualStyleBackColor = true;
			this->button_modify_payment->Click += gcnew System::EventHandler(this, &managePaymentsPrompt::button_modify_payment_Click);
			// 
			// button_close
			// 
			this->button_close->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_close->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->button_close->Location = System::Drawing::Point(213, 397);
			this->button_close->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_close->Name = L"button_close";
			this->button_close->Size = System::Drawing::Size(112, 35);
			this->button_close->TabIndex = 10;
			this->button_close->Text = L"Close";
			this->button_close->UseVisualStyleBackColor = true;
			// 
			// managePaymentsPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 451);
			this->Controls->Add(this->button_close);
			this->Controls->Add(this->button_delete_payment);
			this->Controls->Add(this->button_add_payment);
			this->Controls->Add(this->button_modify_payment);
			this->Controls->Add(this->dataGridView_order_payments);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"managePaymentsPrompt";
			this->Text = L"PaymentListForm";
			this->Load += gcnew System::EventHandler(this, &managePaymentsPrompt::managePaymentsPrompt_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_order_payments))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void refresh_dataGridView_order_payments()
		{
			this->dataGridView_order_payments->DataSource = SQLserv->SQL_getPaymentList();
			this->dataGridView_order_payments->Columns["id_order"]->Visible = false;

			this->dataGridView_order_payments->Columns["id_payment"]->Width = 30;
			this->dataGridView_order_payments->Columns["payment_date"]->Width = 100;
			this->dataGridView_order_payments->Columns["payment_method"]->Width = 50;
			this->dataGridView_order_payments->Columns["amount"]->Width = 50;

			this->dataGridView_order_payments->Columns["id_payment"]->HeaderText = "ID";
			this->dataGridView_order_payments->Columns["payment_date"]->HeaderText = "Date";
			this->dataGridView_order_payments->Columns["payment_method"]->HeaderText = "Method";
			this->dataGridView_order_payments->Columns["amount"]->HeaderText = "Amount";

			dataGridView_order_payments_selectionChanged(nullptr, nullptr);
		}

		void dataGridView_order_payments_selectionChanged(Object^ sender, EventArgs^ event_args)
		{
			if (dataGridView_order_payments->SelectedRows->Count == 0)
			{
				this->button_modify_payment->Visible = false;
				this->button_delete_payment->Visible = false;
			}
			else
			{
				selected_payment = gcnew Payment(Convert::ToInt32(dataGridView_order_payments->SelectedRows[0]->Cells["id_payment"]->Value));
				this->button_modify_payment->Visible = true;
				this->button_delete_payment->Visible = true;
			}
		}
	
	private:
		System::Void managePaymentsPrompt::button_add_payment_Click(System::Object^ sender, System::EventArgs^ e) {
			editPaymentPrompt^ prompt = gcnew editPaymentPrompt("Add payment to " + this->current_order->getReference());
			if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Payment^ new_payment = gcnew Payment(prompt->payment_date, prompt->payment_method, prompt->amount, current_order->getID());
				
				refresh_dataGridView_order_payments();
			}
			
		}


	private:
		System::Void button_modify_payment_Click(System::Object^ sender, System::EventArgs^ e)
		{
			editPaymentPrompt^ prompt = gcnew editPaymentPrompt("Edit payment " + this->selected_payment->getID(), this->selected_payment->getAmount(), this->selected_payment->getPaymentDate(), this->selected_payment->getPaymentMethod());

			if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->selected_payment->setAmount(prompt->amount);
				this->selected_payment->setPaymentDate(prompt->payment_date);
				this->selected_payment->setPaymentMethod(prompt->payment_method);

				this->selected_payment->modifyPaymentInDB();
				
				refresh_dataGridView_order_payments();
			}
		}

	private:
		System::Void button_delete_payment_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SQLserv->SQL_deletePayment(Convert::ToInt32(this->dataGridView_order_payments->CurrentRow->Cells[0]->Value));
			refresh_dataGridView_order_payments();
		}
		
	private: System::Void managePaymentsPrompt_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Edit payments of " + current_order->getReference();
	}
};
}