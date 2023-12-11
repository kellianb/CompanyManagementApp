#pragma once

#include "../Order.h"
#include "../Customer.h"

namespace Projet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for invoicePrompt
	/// </summary>
	public ref class invoicePrompt : public System::Windows::Forms::Form
	{
	Order^ current_order;
	Customer^ current_customer;
		
	public:
		invoicePrompt(int id_order, int id_customer)
		{
			InitializeComponent();
			current_order = gcnew Order(id_order);
			current_customer = gcnew Customer(id_customer);

			this->label_customer_name->Text = "To : " +  current_customer->getFirstName() + " " + current_customer->getLastName();

			this->label_order_discount->Text = "Discount   " + this->current_order->getDiscoutPercentage().ToString() + " %";

			this->label_order_total->Text = "Total   " + this->current_order->getTotalAmount().ToString() + " Eur";

			this->dataGridView_products_in_order->DataSource = this->current_order->getProductsInOrderList();

			this->dataGridView_products_in_order->Columns["id_product"]->HeaderText = "ID";
			this->dataGridView_products_in_order->Columns["id_product"]->Width = 40;

		
			this->dataGridView_products_in_order->Columns["price"]->HeaderText = "Price";
			this->dataGridView_products_in_order->Columns["price"]->Width = 60;

		
			this->dataGridView_products_in_order->Columns["product_name"]->HeaderText = "Name";
			this->dataGridView_products_in_order->Columns["product_name"]->Width = 120;

		
			this->dataGridView_products_in_order->Columns["product_quantity"]->HeaderText = "Amount";
			this->dataGridView_products_in_order->Columns["product_discount_percentage"]->HeaderText = "Discount %";
		
			this->dataGridView_products_in_order->Columns["color_rgb_r"]->HeaderText = "Red";
			this->dataGridView_products_in_order->Columns["color_rgb_r"]->Width = 60;

			this->dataGridView_products_in_order->Columns["color_rgb_g"]->HeaderText = "Green";
			this->dataGridView_products_in_order->Columns["color_rgb_g"]->Width = 60;

		
			this->dataGridView_products_in_order->Columns["color_rgb_b"]->HeaderText = "Blue";
			this->dataGridView_products_in_order->Columns["color_rgb_b"]->Width = 60;
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~invoicePrompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox_logo;
	private: System::Windows::Forms::DataGridView^ dataGridView_products_in_order;
	private: System::Windows::Forms::Label^ label_company_name;
	private: System::Windows::Forms::Label^ label_company_address;
	private: System::Windows::Forms::Label^ label_customer_name;
	private: System::Windows::Forms::Label^ label_order_discount;
	private: System::Windows::Forms::Label^ label_order_total;

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
			this->pictureBox_logo = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView_products_in_order = (gcnew System::Windows::Forms::DataGridView());
			this->label_company_name = (gcnew System::Windows::Forms::Label());
			this->label_company_address = (gcnew System::Windows::Forms::Label());
			this->label_customer_name = (gcnew System::Windows::Forms::Label());
			this->label_order_discount = (gcnew System::Windows::Forms::Label());
			this->label_order_total = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_logo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_products_in_order))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox_logo
			// 
			this->pictureBox_logo->Location = System::Drawing::Point(16, 14);
			this->pictureBox_logo->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox_logo->Name = L"pictureBox_logo";
			this->pictureBox_logo->Size = System::Drawing::Size(267, 240);
			this->pictureBox_logo->TabIndex = 0;
			this->pictureBox_logo->TabStop = false;
			// 
			// dataGridView_products_in_order
			// 
			this->dataGridView_products_in_order->AllowUserToAddRows = false;
			this->dataGridView_products_in_order->AllowUserToResizeColumns = false;
			this->dataGridView_products_in_order->AllowUserToResizeRows = false;
			this->dataGridView_products_in_order->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_products_in_order->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_products_in_order->Enabled = false;
			this->dataGridView_products_in_order->Location = System::Drawing::Point(13, 332);
			this->dataGridView_products_in_order->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView_products_in_order->MultiSelect = false;
			this->dataGridView_products_in_order->Name = L"dataGridView_products_in_order";
			this->dataGridView_products_in_order->ReadOnly = true;
			this->dataGridView_products_in_order->RowHeadersWidth = 51;
			this->dataGridView_products_in_order->RowTemplate->Height = 24;
			this->dataGridView_products_in_order->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_products_in_order->Size = System::Drawing::Size(778, 402);
			this->dataGridView_products_in_order->TabIndex = 2;
			// 
			// label_company_name
			// 
			this->label_company_name->AutoSize = true;
			this->label_company_name->Font = (gcnew System::Drawing::Font(L"Inter Black", 20, System::Drawing::FontStyle::Bold));
			this->label_company_name->Location = System::Drawing::Point(291, 14);
			this->label_company_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_company_name->Name = L"label_company_name";
			this->label_company_name->Size = System::Drawing::Size(550, 49);
			this->label_company_name->TabIndex = 3;
			this->label_company_name->Text = L"ScamExpess International";
			// 
			// label_company_address
			// 
			this->label_company_address->AutoSize = true;
			this->label_company_address->Location = System::Drawing::Point(290, 63);
			this->label_company_address->Name = L"label_company_address";
			this->label_company_address->Size = System::Drawing::Size(640, 24);
			this->label_company_address->TabIndex = 4;
			this->label_company_address->Text = L" Parc des Tanneries, 2 All. des Foulons, 67380 Lingolsheim France";
			// 
			// label_customer_name
			// 
			this->label_customer_name->AutoSize = true;
			this->label_customer_name->Location = System::Drawing::Point(16, 283);
			this->label_customer_name->Name = L"label_customer_name";
			this->label_customer_name->Size = System::Drawing::Size(160, 24);
			this->label_customer_name->TabIndex = 5;
			this->label_customer_name->Text = L"Customer name";
			// 
			// label_order_discount
			// 
			this->label_order_discount->AutoSize = true;
			this->label_order_discount->Location = System::Drawing::Point(16, 813);
			this->label_order_discount->Name = L"label_order_discount";
			this->label_order_discount->Size = System::Drawing::Size(105, 24);
			this->label_order_discount->TabIndex = 6;
			this->label_order_discount->Text = L"Discount :";
			// 
			// label_order_total
			// 
			this->label_order_total->AutoSize = true;
			this->label_order_total->Location = System::Drawing::Point(16, 862);
			this->label_order_total->Name = L"label_order_total";
			this->label_order_total->Size = System::Drawing::Size(68, 24);
			this->label_order_total->TabIndex = 7;
			this->label_order_total->Text = L"Total :";
			// 
			// invoicePrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(805, 916);
			this->Controls->Add(this->label_order_total);
			this->Controls->Add(this->label_order_discount);
			this->Controls->Add(this->label_customer_name);
			this->Controls->Add(this->label_company_address);
			this->Controls->Add(this->label_company_name);
			this->Controls->Add(this->dataGridView_products_in_order);
			this->Controls->Add(this->pictureBox_logo);
			this->Font = (gcnew System::Drawing::Font(L"Inter", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(827, 972);
			this->MinimumSize = System::Drawing::Size(827, 972);
			this->Name = L"invoicePrompt";
			this->Text = L"invoicePrompt";
			this->Load += gcnew System::EventHandler(this, &invoicePrompt::invoicePrompt_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_logo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_products_in_order))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void invoicePrompt_Load(System::Object^ sender, System::EventArgs^ e) {
		Bitmap^ img = gcnew Bitmap("../../img/logo.png");

		pictureBox_logo->SizeMode = PictureBoxSizeMode::Zoom;
		pictureBox_logo->Image = img;
		
	}


};
}
