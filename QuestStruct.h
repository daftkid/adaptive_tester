#pragma once

using namespace System;
using namespace System::Collections;

public value struct QuestStruct {
	String^ question;
	int coefficient;
	String^ first_answer;
	String^ second_answer;
	String^ third_answer;
	String^ fourth_answer;
	int correct_answer;
};

public value struct TestList {
	String^ test_name;
	String^ test_path;
};

public ref class GlobalVars
{
	public: String^ password;
	public: Generic::List<TestList>^ test_list = gcnew Generic::List<TestList>;
};

