#pragma once
namespace PracownicyFirmy {
	using namespace System;
	//using namespace System::Collections;

	public ref class ComboBoxItem
	{
	public:
		ComboBoxItem(String^ text, Object^ value)
		{
			_text = text;
			_value = value;
		}
		String^ _text = "";
		Object^ _value;
		
		/*
	public: property String^ Text
	{
		String^ get()
		{
			return _text;
		}
		void set(String^ value)
		{
			_text = value;
		}
	}
	public:  property Object^ Value
	{
		Object^ get()
		{
			return _value;
		}
		void set(Object^ value)
		{
			_value = value;
		}
	}
		*/
	public:  String^ ToString() override
	{
		return _text;
	}
	
	};


}