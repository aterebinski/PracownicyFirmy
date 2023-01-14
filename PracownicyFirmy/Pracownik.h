#pragma once
#include "Pracownik.h"
namespace PracownicyFirmy {

	using namespace System;
	ref class Pracownik
	{
	public:
		int id, idStanowiska, idLokalizacji;
		String^ imie;
		String^ nazwisko;
		float pensja;

	};
}
