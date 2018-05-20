#pragma once

#include "Login.h"
#include "LoginAdmin.h"

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnExit;
	protected: 
	private: System::Windows::Forms::Button^  btnRunTest;
	private: System::Windows::Forms::Button^  btnCreateTest;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  creaet_test_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createtestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  start_test_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  exit_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  help_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  manua_lToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  about_ToolStripMenuItem;

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
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnRunTest = (gcnew System::Windows::Forms::Button());
			this->btnCreateTest = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->creaet_test_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createtestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->start_test_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exit_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->help_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manua_lToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->about_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(35, 146);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(215, 31);
			this->btnExit->TabIndex = 2;
			this->btnExit->Text = L"Выйти";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &StartForm::btnExit_Click);
			// 
			// btnRunTest
			// 
			this->btnRunTest->Location = System::Drawing::Point(35, 85);
			this->btnRunTest->Name = L"btnRunTest";
			this->btnRunTest->Size = System::Drawing::Size(215, 45);
			this->btnRunTest->TabIndex = 1;
			this->btnRunTest->Text = L"Пройти тест";
			this->btnRunTest->UseVisualStyleBackColor = true;
			this->btnRunTest->Click += gcnew System::EventHandler(this, &StartForm::btnRunTest_Click);
			// 
			// btnCreateTest
			// 
			this->btnCreateTest->Location = System::Drawing::Point(35, 34);
			this->btnCreateTest->Name = L"btnCreateTest";
			this->btnCreateTest->Size = System::Drawing::Size(215, 45);
			this->btnCreateTest->TabIndex = 0;
			this->btnCreateTest->Text = L"Создать тест";
			this->btnCreateTest->UseVisualStyleBackColor = true;
			this->btnCreateTest->Click += gcnew System::EventHandler(this, &StartForm::btnCreateTest_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->creaet_test_ToolStripMenuItem,
					this->help_ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->TabStop = true;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// creaet_test_ToolStripMenuItem
			// 
			this->creaet_test_ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->createtestToolStripMenuItem,
					this->toolStripMenuItem1, this->start_test_ToolStripMenuItem, this->toolStripMenuItem2, this->exit_ToolStripMenuItem
			});
			this->creaet_test_ToolStripMenuItem->Name = L"creaet_test_ToolStripMenuItem";
			this->creaet_test_ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->creaet_test_ToolStripMenuItem->Text = L"Тест";
			// 
			// createtestToolStripMenuItem
			// 
			this->createtestToolStripMenuItem->Name = L"createtestToolStripMenuItem";
			this->createtestToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->createtestToolStripMenuItem->Text = L"Создать тест";
			this->createtestToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::btnCreateTest_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(139, 6);
			// 
			// start_test_ToolStripMenuItem
			// 
			this->start_test_ToolStripMenuItem->Name = L"start_test_ToolStripMenuItem";
			this->start_test_ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->start_test_ToolStripMenuItem->Text = L"Пройти тест";
			this->start_test_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::btnRunTest_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(139, 6);
			// 
			// exit_ToolStripMenuItem
			// 
			this->exit_ToolStripMenuItem->Name = L"exit_ToolStripMenuItem";
			this->exit_ToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->exit_ToolStripMenuItem->Text = L"Выйти";
			this->exit_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::btnExit_Click);
			// 
			// help_ToolStripMenuItem
			// 
			this->help_ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->manua_lToolStripMenuItem,
					this->about_ToolStripMenuItem
			});
			this->help_ToolStripMenuItem->Name = L"help_ToolStripMenuItem";
			this->help_ToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->help_ToolStripMenuItem->Text = L"Помощь";
			// 
			// manua_lToolStripMenuItem
			// 
			this->manua_lToolStripMenuItem->Name = L"manua_lToolStripMenuItem";
			this->manua_lToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->manua_lToolStripMenuItem->Text = L"Руководство пользователя";
			// 
			// about_ToolStripMenuItem
			// 
			this->about_ToolStripMenuItem->Name = L"about_ToolStripMenuItem";
			this->about_ToolStripMenuItem->Size = System::Drawing::Size(221, 22);
			this->about_ToolStripMenuItem->Text = L"О программе";
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 186);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnRunTest);
			this->Controls->Add(this->btnCreateTest);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Adaptive tester";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void btnCreateTest_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ loginAdmin = gcnew LoginAdmin(this);
		loginAdmin->Show();
		this->Hide();
		}
	private: System::Void btnRunTest_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ loginForm = gcnew Login(this);
		loginForm->Show();
		this->Hide();
	}
};
}
