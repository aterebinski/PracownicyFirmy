#pragma once
namespace PracownicyFirmy {
	using namespace System;
	//using namespace System::Collections;

	public ref class ComboBoxItem
	{
	public:
		ComboBoxItem(String^ id, String^ value)
		{
			this->id = id;
			this->value = value;
		}
	private:
		String^ id = "";
		String^ value;

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
			return value;
		}



		public: String^ getValue() {
			return value;
		}

	public: String^ getId() {
		return id;
	}

	};
}