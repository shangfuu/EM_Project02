#pragma once
#include "Equation.h"
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
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadEquationsToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  InterYText;
	private: System::Windows::Forms::Label^  InterXText;
	private: System::Windows::Forms::Label^  IniYText;
	private: System::Windows::Forms::Label^  IniXText;
	private: System::Windows::Forms::TextBox^  MinX;
	private: System::Windows::Forms::TextBox^  IniY;
	private: System::Windows::Forms::TextBox^  IniX;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rB_Conjugate;
	private: System::Windows::Forms::RadioButton^  rB_Quasi;
	private: System::Windows::Forms::RadioButton^  rB_Steep;
	private: System::Windows::Forms::RadioButton^  rB_Newton;
	private: System::Windows::Forms::RadioButton^  rB_Powell;
	private: System::Windows::Forms::Label^  EquationText;
	private: System::Windows::Forms::TextBox^  EquBox;
	private: System::Windows::Forms::TextBox^  MinY;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  InputText;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  OutputText;
	private: System::Windows::Forms::TextBox^  Output;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	protected:
		/// <summary>
		DataManager * dataManager;
		String^ userInput;
		String^ UseEquation;
		bool loadFile = false;	// 判斷是否讀檔
	private: System::Windows::Forms::Label^  symbol2;
	protected:
	private: System::Windows::Forms::Label^  symbol1;
	private: System::Windows::Forms::TextBox^  MaxY;
	private: System::Windows::Forms::TextBox^  MaxX;
	private: System::Windows::Forms::Button^  OptimizeButton;

			 int FunctionIndex;
			 /// 清除任何使用中的資源。
			 /// </summary>
			 ~MyForm()
			 {
				 if (components)
				 {
					 delete components;
				 }
			 }

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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->symbol2 = (gcnew System::Windows::Forms::Label());
			this->symbol1 = (gcnew System::Windows::Forms::Label());
			this->MaxY = (gcnew System::Windows::Forms::TextBox());
			this->MaxX = (gcnew System::Windows::Forms::TextBox());
			this->InterYText = (gcnew System::Windows::Forms::Label());
			this->InterXText = (gcnew System::Windows::Forms::Label());
			this->IniYText = (gcnew System::Windows::Forms::Label());
			this->IniXText = (gcnew System::Windows::Forms::Label());
			this->MinY = (gcnew System::Windows::Forms::TextBox());
			this->MinX = (gcnew System::Windows::Forms::TextBox());
			this->IniY = (gcnew System::Windows::Forms::TextBox());
			this->IniX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->OptimizeButton = (gcnew System::Windows::Forms::Button());
			this->rB_Conjugate = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Quasi = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Steep = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Newton = (gcnew System::Windows::Forms::RadioButton());
			this->rB_Powell = (gcnew System::Windows::Forms::RadioButton());
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
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
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
			this->flowLayoutPanel1->Controls->Add(this->groupBox2);
			this->flowLayoutPanel1->Controls->Add(this->groupBox1);
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
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->symbol2);
			this->groupBox2->Controls->Add(this->symbol1);
			this->groupBox2->Controls->Add(this->MaxY);
			this->groupBox2->Controls->Add(this->MaxX);
			this->groupBox2->Controls->Add(this->InterYText);
			this->groupBox2->Controls->Add(this->InterXText);
			this->groupBox2->Controls->Add(this->IniYText);
			this->groupBox2->Controls->Add(this->IniXText);
			this->groupBox2->Controls->Add(this->MinY);
			this->groupBox2->Controls->Add(this->MinX);
			this->groupBox2->Controls->Add(this->IniY);
			this->groupBox2->Controls->Add(this->IniX);
			this->groupBox2->Location = System::Drawing::Point(3, 153);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(475, 140);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Initial";
			// 
			// symbol2
			// 
			this->symbol2->AutoSize = true;
			this->symbol2->Location = System::Drawing::Point(238, 102);
			this->symbol2->Name = L"symbol2";
			this->symbol2->Size = System::Drawing::Size(11, 12);
			this->symbol2->TabIndex = 11;
			this->symbol2->Text = L"~";
			// 
			// symbol1
			// 
			this->symbol1->AutoSize = true;
			this->symbol1->Location = System::Drawing::Point(59, 102);
			this->symbol1->Name = L"symbol1";
			this->symbol1->Size = System::Drawing::Size(11, 12);
			this->symbol1->TabIndex = 10;
			this->symbol1->Text = L"~";
			// 
			// MaxY
			// 
			this->MaxY->Location = System::Drawing::Point(255, 99);
			this->MaxY->Name = L"MaxY";
			this->MaxY->Size = System::Drawing::Size(41, 22);
			this->MaxY->TabIndex = 9;
			// 
			// MaxX
			// 
			this->MaxX->Location = System::Drawing::Point(76, 99);
			this->MaxX->Name = L"MaxX";
			this->MaxX->Size = System::Drawing::Size(41, 22);
			this->MaxX->TabIndex = 3;
			// 
			// InterYText
			// 
			this->InterYText->AutoSize = true;
			this->InterYText->Location = System::Drawing::Point(189, 81);
			this->InterYText->Name = L"InterYText";
			this->InterYText->Size = System::Drawing::Size(52, 12);
			this->InterYText->TabIndex = 7;
			this->InterYText->Text = L"Interval Y";
			// 
			// InterXText
			// 
			this->InterXText->AutoSize = true;
			this->InterXText->Location = System::Drawing::Point(10, 82);
			this->InterXText->Name = L"InterXText";
			this->InterXText->Size = System::Drawing::Size(52, 12);
			this->InterXText->TabIndex = 6;
			this->InterXText->Text = L"Interval X";
			// 
			// IniYText
			// 
			this->IniYText->AutoSize = true;
			this->IniYText->Location = System::Drawing::Point(189, 18);
			this->IniYText->Name = L"IniYText";
			this->IniYText->Size = System::Drawing::Size(43, 12);
			this->IniYText->TabIndex = 5;
			this->IniYText->Text = L"Initial Y";
			// 
			// IniXText
			// 
			this->IniXText->AutoSize = true;
			this->IniXText->Location = System::Drawing::Point(10, 18);
			this->IniXText->Name = L"IniXText";
			this->IniXText->Size = System::Drawing::Size(43, 12);
			this->IniXText->TabIndex = 4;
			this->IniXText->Text = L"Initial X";
			// 
			// MinY
			// 
			this->MinY->Location = System::Drawing::Point(191, 99);
			this->MinY->Name = L"MinY";
			this->MinY->Size = System::Drawing::Size(41, 22);
			this->MinY->TabIndex = 8;
			// 
			// MinX
			// 
			this->MinX->Location = System::Drawing::Point(12, 99);
			this->MinX->Name = L"MinX";
			this->MinX->Size = System::Drawing::Size(41, 22);
			this->MinX->TabIndex = 2;
			// 
			// IniY
			// 
			this->IniY->Location = System::Drawing::Point(191, 33);
			this->IniY->Name = L"IniY";
			this->IniY->Size = System::Drawing::Size(139, 22);
			this->IniY->TabIndex = 1;
			// 
			// IniX
			// 
			this->IniX->Location = System::Drawing::Point(12, 33);
			this->IniX->Name = L"IniX";
			this->IniX->Size = System::Drawing::Size(139, 22);
			this->IniX->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->OptimizeButton);
			this->groupBox1->Controls->Add(this->rB_Conjugate);
			this->groupBox1->Controls->Add(this->rB_Quasi);
			this->groupBox1->Controls->Add(this->rB_Steep);
			this->groupBox1->Controls->Add(this->rB_Newton);
			this->groupBox1->Controls->Add(this->rB_Powell);
			this->groupBox1->Location = System::Drawing::Point(2, 298);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(475, 104);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Method";
			// 
			// OptimizeButton
			// 
			this->OptimizeButton->Location = System::Drawing::Point(334, 62);
			this->OptimizeButton->Name = L"OptimizeButton";
			this->OptimizeButton->Size = System::Drawing::Size(75, 23);
			this->OptimizeButton->TabIndex = 5;
			this->OptimizeButton->Text = L"Optimize";
			this->OptimizeButton->UseVisualStyleBackColor = true;
			this->OptimizeButton->Click += gcnew System::EventHandler(this, &MyForm::OptimizeButton_Click);
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
			this->rB_Conjugate->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rB_Conjugate_CheckedChanged);
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
			this->rB_Quasi->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rB_Quasi_CheckedChanged);
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
			this->rB_Steep->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rB_Steep_CheckedChanged);
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
			this->rB_Newton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rB_Newton_CheckedChanged);
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
			this->rB_Powell->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rB_Powell_CheckedChanged);
			// 
			// EquationText
			// 
			this->EquationText->AutoSize = true;
			this->EquationText->Location = System::Drawing::Point(3, 404);
			this->EquationText->Name = L"EquationText";
			this->EquationText->Size = System::Drawing::Size(47, 12);
			this->EquationText->TabIndex = 10;
			this->EquationText->Text = L"Equation";
			// 
			// EquBox
			// 
			this->EquBox->Location = System::Drawing::Point(3, 419);
			this->EquBox->Multiline = true;
			this->EquBox->Name = L"EquBox";
			this->EquBox->ReadOnly = true;
			this->EquBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->EquBox->Size = System::Drawing::Size(474, 209);
			this->EquBox->TabIndex = 11;
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
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Both;
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
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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
			loadFile = true;	//	judge at button click
			EquBox->Text = "";
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
		//當Input textbox中的輸入改變時，便會進入此函式

		//判斷輸入自元為'\n'，並防止取到字串-1位置
		if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
		{
			//將使用者輸入字串(在userInput中)，依空白作切割
			array<String^> ^userCommand = userInput->Split(' ');

			try {
				if (userCommand[0] == "use" && userCommand->Length == 2) {
					// Get postEquation
					int k = int::Parse(userCommand[1]); // string to int
					std::vector<std::string> equations = dataManager->GetEquations();

					if (k < equations.size() && k >= 0) {
						UseEquation = gcnew String(equations[k].c_str());
						FunctionIndex = k;
						Output->Text += "**  Using  " + FunctionIndex.ToString() + ":  " + UseEquation + "  **" + Environment::NewLine;
					}
					else if (equations.size() == 0) {
						Output->Text += "Please Load Equation File First" + Environment::NewLine;
						UseEquation = "Error";
					}
					else {
						Output->Text += "Equation not Found" + Environment::NewLine;
						UseEquation = "Error";
					}

				}
				else if (userCommand->Length == 1 && userCommand[0] == "/help") {
					Output->Text += "Nothing I can Help" + Environment::NewLine;
				}
				else if (userCommand->Length == 2 && userCommand[0] == "/c" && userCommand[1] == "o") {
					Output->Text = "";
				}
				else if (userCommand->Length == 2 && userCommand[0] == "/c" && userCommand[1] == "i") {
					Input->Text = "";
					IniX->Text = "";
					IniY->Text = "";
					MinX->Text = "";
					MinY->Text = "";
					MaxX->Text = "";
					MaxY->Text = "";
				}
				else if (userCommand->Length == 1 && userCommand[0] == "/c") {
					Input->Text = "";
					IniX->Text = "";
					IniY->Text = "";
					MinX->Text = "";
					MinY->Text = "";
					MaxX->Text = "";
					MaxY->Text = "";
					Output->Text = "";
				}
				else {
					Output->Text += "Error Command" + Environment::NewLine;
				}
			}
			catch (...) {
				Output->Text += "Error Fomat." + Environment::NewLine;
				UseEquation = "Error";
			}
			userInput = "";
		}
		else
		{
			//將使用者輸入字串(在Text box中)，依'\n'作切割
			array<String^> ^userCommand = Input->Text->Split('\n');
			//並將最後一行，作為目前使用者輸入指令
			userInput = userCommand[userCommand->Length - 1];
		}
	}

	private: System::Void rB_Powell_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Powell->Checked) {
			Method = enPowells;
		}
	}
	private: System::Void rB_Steep_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Steep->Checked) {
			Method = enSteep_Descent;
		}
	}
	private: System::Void rB_Conjugate_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Conjugate->Checked) {
			Method = enConjugate_Gradient;
		}
	}
	private: System::Void rB_Quasi_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Quasi->Checked) {
			Method = enQuasi_Newton;
		}
	}
	private: System::Void rB_Newton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rB_Newton->Checked) {
			Method = enNewton;
		}
	}

	private: System::Void OptimizeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			if (loadFile == false || UseEquation == "Error") {
				Output->Text += "Error File loaded" + Environment::NewLine;
			}
			else if (IniX->Text != "" && IniY->Text != "" &&MinX->Text != "" &&MinY->Text != "" && Input->Text != "") {

				std::vector<std::string>postEquation = dataManager->GetPostEquations(FunctionIndex);
				Equation f;
				f.SetEquation(postEquation);

				double x = double::Parse(IniX->Text);
				double y = double::Parse(IniY->Text);
				double xMin = double::Parse(MinX->Text);
				double yMin = double::Parse(MinY->Text);
				double xMax = double::Parse(MaxX->Text);
				double yMax = double::Parse(MaxY->Text);

				if (xMin > xMax || yMin > yMax) {
					Output->Text += "Min must Smaller than Max" + Environment::NewLine;
				}
				else if (x < xMin || x > xMax || y < yMin || y > yMax) {
					Output->Text += "Foolish Interval and Initial" + Environment::NewLine;
				}
				else {
					if (Method == 0) {
						Output->Text += "-----  Powell’s Method  -----" + Environment::NewLine;
						f.Powell(x, y, xMin, xMax, yMin, yMax, Output);
					}
					else if (Method == 1) {
						Output->Text += "-----  Newton Method  -----" + Environment::NewLine;
						f.Newton(x, y, xMin, xMax, yMin, yMax, Output);
					}
					else if (Method == 2) {
						Output->Text += "-----  Steep Method  -----" + Environment::NewLine;
						f.Steepest_Descent(x, y, xMin, xMax, yMin, yMax, Output);	// Example call;
					}
					else if (Method == 3) {
						Output->Text += "-----  Quasi Method  -----" + Environment::NewLine;
						f.Quasi_Newton(x, y, xMin, xMax, yMin, yMax, Output);
					}
					else {
						Output->Text += "-----  Conjugate Method  -----" + Environment::NewLine;
						f.Conjugate(x, y, xMin, xMax, yMin, yMax, Output);
					}
				}
			}
			else {
				Output->Text += "Every TextBox Should be Initial" + Environment::NewLine;
			}
		}
		catch (...) {
			Output->Text += "Error Input." + Environment::NewLine;
		}
	}

	};
}