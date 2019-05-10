#pragma once
#include "DataManager.h"
#include "DotNetUtilities.h"

namespace Optimization {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	public:
	private: System::Windows::Forms::Label^  InputText;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  OutputText;
	private: System::Windows::Forms::TextBox^  Output;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadEquationsToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;




	public:





	protected:
		/// <summary>
		DataManager* dataManager;
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:








	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputText = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->OutputText = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEquationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 827)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1322, 827);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->InputText);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->OutputText);
			this->flowLayoutPanel1->Controls->Add(this->Output);
			this->flowLayoutPanel1->Location = System::Drawing::Point(4, 4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(637, 715);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// InputText
			// 
			this->InputText->AutoSize = true;
			this->InputText->Location = System::Drawing::Point(4, 0);
			this->InputText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->InputText->Name = L"InputText";
			this->InputText->Size = System::Drawing::Size(37, 15);
			this->InputText->TabIndex = 0;
			this->InputText->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(4, 19);
			this->Input->Margin = System::Windows::Forms::Padding(4);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(632, 164);
			this->Input->TabIndex = 1;
			// 
			// OutputText
			// 
			this->OutputText->AutoSize = true;
			this->OutputText->Location = System::Drawing::Point(4, 187);
			this->OutputText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OutputText->Name = L"OutputText";
			this->OutputText->Size = System::Drawing::Size(46, 15);
			this->OutputText->TabIndex = 2;
			this->OutputText->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Location = System::Drawing::Point(4, 206);
			this->Output->Margin = System::Windows::Forms::Padding(4);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->Size = System::Drawing::Size(632, 498);
			this->Output->TabIndex = 3;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->loadEquationsToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadEquationsToolStripMenuItem
			// 
			this->loadEquationsToolStripMenuItem->Name = L"loadEquationsToolStripMenuItem";
			this->loadEquationsToolStripMenuItem->Size = System::Drawing::Size(192, 26);
			this->loadEquationsToolStripMenuItem->Text = L"Load Equations";
			this->loadEquationsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadEquationsToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(927, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->TabIndex = 3;
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(457, 642);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1322, 827);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"MyForm";
			this->Text = L"Optimization";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void loadEquationsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
	}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	//從讀取讀取向量資料
	if (dataManager->LoadEquationData())
	{
		std::vector<std::string> equations = dataManager->GetEquations();
		Output->Multiline = true;
		for (unsigned int i = 0; i < equations.size(); i++)
		{
			Output->Text += gcnew String(equations[i].c_str());
			Output->Text += Environment::NewLine;
		}
	}
}
};
}
