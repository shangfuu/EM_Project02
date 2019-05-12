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

	enum METHOD {
		enPowells = 0,
		enNewton,
		enSteep_Descent,
		enQuasi_Newton,
		enConjugate_Gradient
	}Method;


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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadEquationsToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rB_Conjugate;
	private: System::Windows::Forms::RadioButton^  rB_Quasi;
	private: System::Windows::Forms::RadioButton^  rB_Steep;
	private: System::Windows::Forms::RadioButton^  rB_Newton;
	private: System::Windows::Forms::RadioButton^  rB_Powell;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  InterYText;
	private: System::Windows::Forms::Label^  InterXText;
	private: System::Windows::Forms::Label^  IniYText;
	private: System::Windows::Forms::Label^  IniXText;
	private: System::Windows::Forms::TextBox^  InterY;
	private: System::Windows::Forms::TextBox^  InterX;
	private: System::Windows::Forms::TextBox^  IniY;
	private: System::Windows::Forms::TextBox^  IniX;
	private: System::Windows::Forms::Label^  EquationText;
	private: System::Windows::Forms::TextBox^  EquBox;

	public:



	protected:
		/// <summary>
		DataManager * dataManager;
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
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  InputText;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  OutputText;
	private: System::Windows::Forms::TextBox^  Output;



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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rB_Conjugate = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Quasi = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Steep = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Newton = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Powell = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->InterYText = (gcnew System::Windows::Forms::Label());
			this->InterXText = (gcnew System::Windows::Forms::Label());
			this->IniYText = (gcnew System::Windows::Forms::Label());
			this->IniXText = (gcnew System::Windows::Forms::Label());
			this->InterY = (gcnew System::Windows::Forms::TextBox());
			this->InterX = (gcnew System::Windows::Forms::TextBox());
			this->IniY = (gcnew System::Windows::Forms::TextBox());
			this->IniX = (gcnew System::Windows::Forms::TextBox());
			this->EquationText = (gcnew System::Windows::Forms::Label());
			this->EquBox = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->OutputText = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEquationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
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
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 643)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(992, 643);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->InputText);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->groupBox1);
			this->flowLayoutPanel1->Controls->Add(this->groupBox2);
			this->flowLayoutPanel1->Controls->Add(this->EquationText);
			this->flowLayoutPanel1->Controls->Add(this->EquBox);
			this->flowLayoutPanel1->Location = System::Drawing::Point(2, 2);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(491, 635);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// InputText
			// 
			this->InputText->AutoSize = true;
			this->InputText->Location = System::Drawing::Point(3, 0);
			this->InputText->Name = L"InputText";
			this->InputText->Size = System::Drawing::Size(30, 12);
			this->InputText->TabIndex = 0;
			this->InputText->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(3, 15);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(475, 132);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &MyForm::Input_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rB_Conjugate);
			this->groupBox1->Controls->Add(this->rB_Quasi);
			this->groupBox1->Controls->Add(this->rB_Steep);
			this->groupBox1->Controls->Add(this->rB_Newton);
			this->groupBox1->Controls->Add(this->rB_Powell);
			this->groupBox1->Location = System::Drawing::Point(2, 152);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(475, 104);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Method";
			// 
			// rB_Conjugate
			// 
			this->rB_Conjugate->AutoSize = true;
			this->rB_Conjugate->Location = System::Drawing::Point(298, 26);
			this->rB_Conjugate->Margin = System::Windows::Forms::Padding(2);
			this->rB_Conjugate->Name = L"rB_Conjugate";
			this->rB_Conjugate->Size = System::Drawing::Size(153, 16);
			this->rB_Conjugate->TabIndex = 4;
			this->rB_Conjugate->TabStop = true;
			this->rB_Conjugate->Text = L"Conjugate Gradient Method";
			this->rB_Conjugate->UseVisualStyleBackColor = true;
			this->rB_Conjugate->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Conjugate_CheckedChanged);
			// 
			// rB_Quasi
			// 
			this->rB_Quasi->AutoSize = true;
			this->rB_Quasi->Location = System::Drawing::Point(137, 65);
			this->rB_Quasi->Margin = System::Windows::Forms::Padding(2);
			this->rB_Quasi->Name = L"rB_Quasi";
			this->rB_Quasi->Size = System::Drawing::Size(128, 16);
			this->rB_Quasi->TabIndex = 3;
			this->rB_Quasi->TabStop = true;
			this->rB_Quasi->Text = L"Quasi-Newton Method";
			this->rB_Quasi->UseVisualStyleBackColor = true;
			this->rB_Quasi->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Quasi_CheckedChanged);
			// 
			// rB_Steep
			// 
			this->rB_Steep->AutoSize = true;
			this->rB_Steep->Location = System::Drawing::Point(137, 26);
			this->rB_Steep->Margin = System::Windows::Forms::Padding(2);
			this->rB_Steep->Name = L"rB_Steep";
			this->rB_Steep->Size = System::Drawing::Size(138, 16);
			this->rB_Steep->TabIndex = 2;
			this->rB_Steep->TabStop = true;
			this->rB_Steep->Text = L"Steep Descent Algorithm";
			this->rB_Steep->UseVisualStyleBackColor = true;
			this->rB_Steep->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Steep_CheckedChanged);
			// 
			// rB_Newton
			// 
			this->rB_Newton->AutoSize = true;
			this->rB_Newton->Location = System::Drawing::Point(11, 65);
			this->rB_Newton->Margin = System::Windows::Forms::Padding(2);
			this->rB_Newton->Name = L"rB_Newton";
			this->rB_Newton->Size = System::Drawing::Size(104, 16);
			this->rB_Newton->TabIndex = 1;
			this->rB_Newton->TabStop = true;
			this->rB_Newton->Text = L"Newton\'s Method";
			this->rB_Newton->UseVisualStyleBackColor = true;
			this->rB_Newton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Newton_CheckedChanged);
			// 
			// rB_Powell
			// 
			this->rB_Powell->AutoSize = true;
			this->rB_Powell->Location = System::Drawing::Point(11, 26);
			this->rB_Powell->Margin = System::Windows::Forms::Padding(2);
			this->rB_Powell->Name = L"rB_Powell";
			this->rB_Powell->Size = System::Drawing::Size(99, 16);
			this->rB_Powell->TabIndex = 0;
			this->rB_Powell->TabStop = true;
			this->rB_Powell->Text = L"Powell\'s Method";
			this->rB_Powell->UseVisualStyleBackColor = true;
			this->rB_Powell->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Powell_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->InterYText);
			this->groupBox2->Controls->Add(this->InterXText);
			this->groupBox2->Controls->Add(this->IniYText);
			this->groupBox2->Controls->Add(this->IniXText);
			this->groupBox2->Controls->Add(this->InterY);
			this->groupBox2->Controls->Add(this->InterX);
			this->groupBox2->Controls->Add(this->IniY);
			this->groupBox2->Controls->Add(this->IniX);
			this->groupBox2->Location = System::Drawing::Point(3, 261);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(475, 140);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Initial";
			// 
			// InterYText
			// 
			this->InterYText->AutoSize = true;
			this->InterYText->Location = System::Drawing::Point(191, 79);
			this->InterYText->Name = L"InterYText";
			this->InterYText->Size = System::Drawing::Size(52, 12);
			this->InterYText->TabIndex = 7;
			this->InterYText->Text = L"Interval Y";
			// 
			// InterXText
			// 
			this->InterXText->AutoSize = true;
			this->InterXText->Location = System::Drawing::Point(12, 80);
			this->InterXText->Name = L"InterXText";
			this->InterXText->Size = System::Drawing::Size(52, 12);
			this->InterXText->TabIndex = 6;
			this->InterXText->Text = L"Interval X";
			// 
			// IniYText
			// 
			this->IniYText->AutoSize = true;
			this->IniYText->Location = System::Drawing::Point(189, 31);
			this->IniYText->Name = L"IniYText";
			this->IniYText->Size = System::Drawing::Size(43, 12);
			this->IniYText->TabIndex = 5;
			this->IniYText->Text = L"Initial Y";
			// 
			// IniXText
			// 
			this->IniXText->AutoSize = true;
			this->IniXText->Location = System::Drawing::Point(10, 31);
			this->IniXText->Name = L"IniXText";
			this->IniXText->Size = System::Drawing::Size(43, 12);
			this->IniXText->TabIndex = 4;
			this->IniXText->Text = L"Initial X";
			// 
			// InterY
			// 
			this->InterY->Location = System::Drawing::Point(191, 97);
			this->InterY->Multiline = true;
			this->InterY->Name = L"InterY";
			this->InterY->Size = System::Drawing::Size(139, 22);
			this->InterY->TabIndex = 3;
			// 
			// InterX
			// 
			this->InterX->Location = System::Drawing::Point(10, 98);
			this->InterX->Multiline = true;
			this->InterX->Name = L"InterX";
			this->InterX->Size = System::Drawing::Size(129, 22);
			this->InterX->TabIndex = 2;
			// 
			// IniY
			// 
			this->IniY->Location = System::Drawing::Point(191, 49);
			this->IniY->Multiline = true;
			this->IniY->Name = L"IniY";
			this->IniY->Size = System::Drawing::Size(139, 22);
			this->IniY->TabIndex = 1;
			// 
			// IniX
			// 
			this->IniX->Location = System::Drawing::Point(10, 49);
			this->IniX->Multiline = true;
			this->IniX->Name = L"IniX";
			this->IniX->Size = System::Drawing::Size(129, 22);
			this->IniX->TabIndex = 0;
			// 
			// EquationText
			// 
			this->EquationText->AutoSize = true;
			this->EquationText->Location = System::Drawing::Point(3, 404);
			this->EquationText->Name = L"EquationText";
			this->EquationText->Size = System::Drawing::Size(47, 12);
			this->EquationText->TabIndex = 4;
			this->EquationText->Text = L"Equation";
			// 
			// EquBox
			// 
			this->EquBox->Location = System::Drawing::Point(3, 419);
			this->EquBox->Multiline = true;
			this->EquBox->Name = L"EquBox";
			this->EquBox->ReadOnly = true;
			this->EquBox->Size = System::Drawing::Size(474, 209);
			this->EquBox->TabIndex = 5;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->OutputText);
			this->flowLayoutPanel2->Controls->Add(this->Output);
			this->flowLayoutPanel2->Location = System::Drawing::Point(498, 2);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(484, 635);
			this->flowLayoutPanel2->TabIndex = 3;
			// 
			// OutputText
			// 
			this->OutputText->AutoSize = true;
			this->OutputText->Location = System::Drawing::Point(3, 0);
			this->OutputText->Name = L"OutputText";
			this->OutputText->Size = System::Drawing::Size(37, 12);
			this->OutputText->TabIndex = 2;
			this->OutputText->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Location = System::Drawing::Point(3, 15);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(475, 613);
			this->Output->TabIndex = 3;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(992, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->loadEquationsToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadEquationsToolStripMenuItem
			// 
			this->loadEquationsToolStripMenuItem->Name = L"loadEquationsToolStripMenuItem";
			this->loadEquationsToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->loadEquationsToolStripMenuItem->Text = L"Load Equations";
			this->loadEquationsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadEquationsToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 667);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Optimization";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
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
			EquBox->Multiline = true;
			for (unsigned int i = 0; i < equations.size(); i++)
			{
				EquBox->Text += i.ToString() + ": " + gcnew String(equations[i].c_str());
				EquBox->Text += Environment::NewLine;
			}
		}
	}
	private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		Input->Text->Length;
		Output->Text->Length;
	}
	private: System::Void Powell_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (rB_Powell->Checked) {
			Output->Text += rB_Powell->Name + Environment::NewLine;
			Method = enPowells;
		}
	}
	private: System::Void Steep_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Steep->Checked) {
			Output->Text += rB_Steep->Name + Environment::NewLine;
			Method = enSteep_Descent;
		}
	}
	private: System::Void Conjugate_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Conjugate->Checked) {
			Output->Text += rB_Conjugate->Name + Environment::NewLine;
			Method = enConjugate_Gradient;
		}
	}
	private: System::Void Newton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Newton->Checked) {
			Output->Text += rB_Newton->Name + Environment::NewLine;
			Method = enNewton;
		}
	}
	private: System::Void Quasi_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Quasi->Checked) {
			Output->Text += rB_Quasi->Name + Environment::NewLine;
			Method = enQuasi_Newton;
		}
	}
	};
}
