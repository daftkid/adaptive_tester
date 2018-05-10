#pragma once

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Result
	/// </summary>

	public ref class Result : public System::Windows::Forms::Form
	{
	private: Form ^ parent;
	public:
		Result(Form^ parent, String^ name, int score)
		{
			InitializeComponent();
			this->l_test_name->Text = name;
			this->l_test_score->Text = score.ToString();
			this->parent = parent;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  l_test_name;
	protected:

	protected: 
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  l_test_score;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btn_close;

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
			this->l_test_name = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->l_test_score = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// l_test_name
			// 
			this->l_test_name->AutoSize = true;
			this->l_test_name->Location = System::Drawing::Point(158, 36);
			this->l_test_name->Name = L"l_test_name";
			this->l_test_name->Size = System::Drawing::Size(91, 13);
			this->l_test_name->TabIndex = 7;
			this->l_test_name->Text = L"[название темы]";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(131, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Вы прошли тест по теме";
			// 
			// l_test_score
			// 
			this->l_test_score->AutoSize = true;
			this->l_test_score->Location = System::Drawing::Point(162, 72);
			this->l_test_score->Name = L"l_test_score";
			this->l_test_score->Size = System::Drawing::Size(42, 13);
			this->l_test_score->TabIndex = 5;
			this->l_test_score->Text = L"95/100";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Ваш результат:";
			// 
			// btn_close
			// 
			this->btn_close->Location = System::Drawing::Point(81, 106);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(123, 23);
			this->btn_close->TabIndex = 8;
			this->btn_close->Text = L"Закрыть";
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &Result::btn_close_Click);
			// 
			// Result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 141);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->l_test_name);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->l_test_score);
			this->Controls->Add(this->label1);
			this->Name = L"Result";
			this->Text = L"Result";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_close_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		this->parent->Show();
		this->Close();
	}
};
}
