#pragma once

#include "../Order.h"
#include "../SQL/SQLservices.h"
#include "../Product.h"
#include "../Product_price.h"

namespace Projet {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for editProductsInOrder
	/// </summary>
	public ref class editProductsInOrder : public System::Windows::Forms::Form
	{
	SQLservices^ SQLserver = gcnew SQLservices();
	Order^ selectedOrder;
	Product^ selectedProduct;
		
	public:
		editProductsInOrder(int id_order)
		{
			this->selectedOrder = gcnew Order(id_order);

			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~editProductsInOrder()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView_inventory;
	private: System::Windows::Forms::GroupBox^ groupBox_inventory;
	protected:

	protected:

	private: System::Windows::Forms::GroupBox^ groupBox_variants;

	private: System::Windows::Forms::DataGridView^ dataGridView_product_variants;
	private: System::Windows::Forms::GroupBox^ groupBox_products_in_order;


	private: System::Windows::Forms::NumericUpDown^ numericUpDown_product_discount;
	private: System::Windows::Forms::Button^ button_remove_item_to_order;




	private: System::Windows::Forms::Button^ button_add_item_to_order;

	private: System::Windows::Forms::DataGridView^ dataGridView_products_in_order;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_product_amount;
	private: System::Windows::Forms::Label^ label__product_amount;
	private: System::Windows::Forms::Label^ label_product_discount;






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
			this->dataGridView_inventory = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox_inventory = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox_variants = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView_product_variants = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox_products_in_order = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView_products_in_order = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDown_product_discount = (gcnew System::Windows::Forms::NumericUpDown());
			this->button_remove_item_to_order = (gcnew System::Windows::Forms::Button());
			this->button_add_item_to_order = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_product_amount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label__product_amount = (gcnew System::Windows::Forms::Label());
			this->label_product_discount = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_inventory))->BeginInit();
			this->groupBox_inventory->SuspendLayout();
			this->groupBox_variants->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_product_variants))->BeginInit();
			this->groupBox_products_in_order->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_products_in_order))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_product_discount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_product_amount))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_inventory
			// 
			this->dataGridView_inventory->AllowUserToAddRows = false;
			this->dataGridView_inventory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_inventory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_inventory->Location = System::Drawing::Point(6, 26);
			this->dataGridView_inventory->MultiSelect = false;
			this->dataGridView_inventory->Name = L"dataGridView_inventory";
			this->dataGridView_inventory->ReadOnly = true;
			this->dataGridView_inventory->RowHeadersWidth = 51;
			this->dataGridView_inventory->RowTemplate->Height = 24;
			this->dataGridView_inventory->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_inventory->Size = System::Drawing::Size(491, 404);
			this->dataGridView_inventory->TabIndex = 0;
			this->dataGridView_inventory->SelectionChanged += gcnew System::EventHandler(this, &editProductsInOrder::dataGridView_inventory_selectionChanged);
			// 
			// groupBox_inventory
			// 
			this->groupBox_inventory->Controls->Add(this->dataGridView_inventory);
			this->groupBox_inventory->Location = System::Drawing::Point(12, 12);
			this->groupBox_inventory->Name = L"groupBox_inventory";
			this->groupBox_inventory->Size = System::Drawing::Size(503, 436);
			this->groupBox_inventory->TabIndex = 1;
			this->groupBox_inventory->TabStop = false;
			this->groupBox_inventory->Text = L"Products";
			// 
			// groupBox_variants
			// 
			this->groupBox_variants->Controls->Add(this->dataGridView_product_variants);
			this->groupBox_variants->Location = System::Drawing::Point(12, 454);
			this->groupBox_variants->Name = L"groupBox_variants";
			this->groupBox_variants->Size = System::Drawing::Size(503, 207);
			this->groupBox_variants->TabIndex = 2;
			this->groupBox_variants->TabStop = false;
			this->groupBox_variants->Text = L"Variants";
			// 
			// dataGridView_product_variants
			// 
			this->dataGridView_product_variants->AllowUserToAddRows = false;
			this->dataGridView_product_variants->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_product_variants->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_product_variants->Location = System::Drawing::Point(6, 20);
			this->dataGridView_product_variants->MultiSelect = false;
			this->dataGridView_product_variants->Name = L"dataGridView_product_variants";
			this->dataGridView_product_variants->ReadOnly = true;
			this->dataGridView_product_variants->RowHeadersWidth = 51;
			this->dataGridView_product_variants->RowTemplate->Height = 24;
			this->dataGridView_product_variants->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_product_variants->Size = System::Drawing::Size(491, 181);
			this->dataGridView_product_variants->TabIndex = 0;
			this->dataGridView_product_variants->SelectionChanged += gcnew System::EventHandler(this, &editProductsInOrder::dataGridView_product_variants_selectionChanged);
			// 
			// groupBox_products_in_order
			// 
			this->groupBox_products_in_order->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_products_in_order->Controls->Add(this->dataGridView_products_in_order);
			this->groupBox_products_in_order->Location = System::Drawing::Point(750, 18);
			this->groupBox_products_in_order->Name = L"groupBox_products_in_order";
			this->groupBox_products_in_order->Size = System::Drawing::Size(677, 643);
			this->groupBox_products_in_order->TabIndex = 2;
			this->groupBox_products_in_order->TabStop = false;
			this->groupBox_products_in_order->Text = L"Products in Order";
			// 
			// dataGridView_products_in_order
			// 
			this->dataGridView_products_in_order->AllowUserToAddRows = false;
			this->dataGridView_products_in_order->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_products_in_order->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_products_in_order->Location = System::Drawing::Point(6, 20);
			this->dataGridView_products_in_order->MultiSelect = false;
			this->dataGridView_products_in_order->Name = L"dataGridView_products_in_order";
			this->dataGridView_products_in_order->ReadOnly = true;
			this->dataGridView_products_in_order->RowHeadersWidth = 51;
			this->dataGridView_products_in_order->RowTemplate->Height = 24;
			this->dataGridView_products_in_order->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView_products_in_order->Size = System::Drawing::Size(665, 617);
			this->dataGridView_products_in_order->TabIndex = 1;
			this->dataGridView_products_in_order->SelectionChanged += gcnew System::EventHandler(this, &editProductsInOrder::dataGridView_products_in_order_selectionChanged);
			// 
			// numericUpDown_product_discount
			// 
			this->numericUpDown_product_discount->DecimalPlaces = 2;
			this->numericUpDown_product_discount->Location = System::Drawing::Point(579, 550);
			this->numericUpDown_product_discount->Name = L"numericUpDown_product_discount";
			this->numericUpDown_product_discount->Size = System::Drawing::Size(120, 27);
			this->numericUpDown_product_discount->TabIndex = 3;
			// 
			// button_remove_item_to_order
			// 
			this->button_remove_item_to_order->Location = System::Drawing::Point(579, 59);
			this->button_remove_item_to_order->Name = L"button_remove_item_to_order";
			this->button_remove_item_to_order->Size = System::Drawing::Size(120, 30);
			this->button_remove_item_to_order->TabIndex = 4;
			this->button_remove_item_to_order->Text = L"<< Remove";
			this->button_remove_item_to_order->UseVisualStyleBackColor = true;
			this->button_remove_item_to_order->Click += gcnew System::EventHandler(this, &editProductsInOrder::button_remove_item_to_order_Click);
			// 
			// button_add_item_to_order
			// 
			this->button_add_item_to_order->Location = System::Drawing::Point(579, 596);
			this->button_add_item_to_order->Name = L"button_add_item_to_order";
			this->button_add_item_to_order->Size = System::Drawing::Size(120, 30);
			this->button_add_item_to_order->TabIndex = 5;
			this->button_add_item_to_order->Text = L"Add >>";
			this->button_add_item_to_order->UseVisualStyleBackColor = true;
			this->button_add_item_to_order->Click += gcnew System::EventHandler(this, &editProductsInOrder::button_add_item_to_order_Click);
			// 
			// numericUpDown_product_amount
			// 
			this->numericUpDown_product_amount->Location = System::Drawing::Point(579, 486);
			this->numericUpDown_product_amount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown_product_amount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_product_amount->Name = L"numericUpDown_product_amount";
			this->numericUpDown_product_amount->Size = System::Drawing::Size(120, 27);
			this->numericUpDown_product_amount->TabIndex = 6;
			this->numericUpDown_product_amount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_product_amount->ValueChanged += gcnew System::EventHandler(this, &editProductsInOrder::numericUpDown_product_amount_ValueChanged);
			// 
			// label__product_amount
			// 
			this->label__product_amount->AutoSize = true;
			this->label__product_amount->Location = System::Drawing::Point(579, 464);
			this->label__product_amount->Name = L"label__product_amount";
			this->label__product_amount->Size = System::Drawing::Size(72, 20);
			this->label__product_amount->TabIndex = 7;
			this->label__product_amount->Text = L"Amount";
			// 
			// label_product_discount
			// 
			this->label_product_discount->AutoSize = true;
			this->label_product_discount->Location = System::Drawing::Point(579, 527);
			this->label_product_discount->Name = L"label_product_discount";
			this->label_product_discount->Size = System::Drawing::Size(79, 20);
			this->label_product_discount->TabIndex = 8;
			this->label_product_discount->Text = L"Discount";
			// 
			// editProductsInOrder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1439, 673);
			this->Controls->Add(this->label_product_discount);
			this->Controls->Add(this->label__product_amount);
			this->Controls->Add(this->numericUpDown_product_amount);
			this->Controls->Add(this->button_add_item_to_order);
			this->Controls->Add(this->button_remove_item_to_order);
			this->Controls->Add(this->numericUpDown_product_discount);
			this->Controls->Add(this->groupBox_products_in_order);
			this->Controls->Add(this->groupBox_variants);
			this->Controls->Add(this->groupBox_inventory);
			this->Font = (gcnew System::Drawing::Font(L"Inter", 9.75F));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"editProductsInOrder";
			this->Text = L"editProductsInOrder";
			this->Load += gcnew System::EventHandler(this, &editProductsInOrder::editProductsInOrder_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_inventory))->EndInit();
			this->groupBox_inventory->ResumeLayout(false);
			this->groupBox_variants->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_product_variants))->EndInit();
			this->groupBox_products_in_order->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_products_in_order))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_product_discount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_product_amount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion

	private: void refresh_dataGridView_inventory()
	{
		this->dataGridView_inventory->Refresh();
		this->dataGridView_inventory->DataSource = SQLserver->SQL_getProductList();

		this->dataGridView_inventory->Columns["id_product"]->Width = 40;
		this->dataGridView_inventory->Columns["id_product"]->HeaderText = "ID";
		
		this->dataGridView_inventory->Columns["product_name"]->HeaderText = "Name";
		
		this->dataGridView_inventory->Columns["amount_in_stock"]->HeaderText = "Stock";
		this->dataGridView_inventory->Columns["amount_in_stock"]->Width = 100;

		
		this->dataGridView_inventory->Columns["reorder_threshold"]->HeaderText = "Reorder at";
		this->dataGridView_inventory->Columns["reorder_threshold"]->Width = 100;
		
		this->dataGridView_inventory->Columns["vat_percentage"]->HeaderText = "VAT %";
		this->dataGridView_inventory->Columns["vat_percentage"]->Width = 60;
	}

	private: void refresh_dataGridView_product_variants()
	{
		this->dataGridView_product_variants->Refresh();
		this->dataGridView_product_variants->DataSource = selectedProduct->getAvailableColors(System::Convert::ToInt32(numericUpDown_product_amount->Value));

		this->dataGridView_product_variants->Columns["color_rgb_r"]->HeaderText = "Red";
		this->dataGridView_product_variants->Columns["color_rgb_g"]->HeaderText = "Green";
		this->dataGridView_product_variants->Columns["color_rgb_b"]->HeaderText = "Blue";
		
		dataGridView_product_variants_selectionChanged(nullptr, nullptr);
	}

	private: void refresh_dataGridView_products_in_order()
	{
		this->dataGridView_products_in_order->Refresh();
		this->dataGridView_products_in_order->DataSource = selectedOrder->getProductsInOrderList();

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


		dataGridView_products_in_order_selectionChanged(nullptr, nullptr);

	}

	private: void dataGridView_inventory_selectionChanged(Object^ sender, EventArgs^ event_args)
	{
		if (dataGridView_inventory->SelectedRows->Count == 0)
		{
			return;
		}
		this->selectedProduct = gcnew Product(Convert::ToInt32(this->dataGridView_inventory->SelectedRows[0]->Cells["id_product"]->Value));

		refresh_dataGridView_product_variants();
	}

	private:void dataGridView_product_variants_selectionChanged(Object^ sender, EventArgs^ event_args)
	{
		if(dataGridView_product_variants->SelectedRows->Count == 0)
		{
			this->button_add_item_to_order->Enabled = false;
		}
		else
		{
			this->button_add_item_to_order->Enabled = true;
		}
	}
		
	private: System::Void dataGridView_products_in_order_selectionChanged(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView_products_in_order->SelectedRows->Count == 0)
		{
			this->button_remove_item_to_order->Enabled = false;
		}
		else
		{
			this->button_remove_item_to_order->Enabled = true;
		}
	}

		
	private: System::Void editProductsInOrder_Load(System::Object^ sender, System::EventArgs^ e) {
		refresh_dataGridView_inventory();
		refresh_dataGridView_products_in_order();

		this->Text = "Edit Products in Order " + selectedOrder->getReference();
	}
		
	private: System::Void numericUpDown_product_amount_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		refresh_dataGridView_product_variants();
	}
		

	private: System::Void button_add_item_to_order_Click(System::Object^ sender, System::EventArgs^ e) {
		int r = Convert::ToInt32(this->dataGridView_product_variants->SelectedRows[0]->Cells["color_rgb_r"]->Value);
		int g = Convert::ToInt32(this->dataGridView_product_variants->SelectedRows[0]->Cells["color_rgb_g"]->Value);
		int b = Convert::ToInt32(this->dataGridView_product_variants->SelectedRows[0]->Cells["color_rgb_b"]->Value);
		
		this->selectedOrder->addProductToOrder(selectedProduct->getID(), System::Convert::ToSingle(numericUpDown_product_amount->Value), System::Convert::ToSingle(numericUpDown_product_discount->Value), r, g, b);

		refresh_dataGridView_products_in_order();
	}
	private: System::Void button_remove_item_to_order_Click(System::Object^ sender, System::EventArgs^ e) {
		int product_id = Convert::ToInt32(this->dataGridView_products_in_order->SelectedRows[0]->Cells["id_product"]->Value);

		int r = Convert::ToInt32(this->dataGridView_products_in_order->SelectedRows[0]->Cells["color_rgb_r"]->Value);
		int g = Convert::ToInt32(this->dataGridView_products_in_order->SelectedRows[0]->Cells["color_rgb_g"]->Value);
		int b = Convert::ToInt32(this->dataGridView_products_in_order->SelectedRows[0]->Cells["color_rgb_b"]->Value);
		
		this->selectedOrder->removeProductFromOrder(product_id, r, g, b);

		refresh_dataGridView_products_in_order();
	}

};
}
