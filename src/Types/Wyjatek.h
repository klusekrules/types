#pragma once
#include "TypyProste.h"

namespace STyp {

	//Makro wstawiajace nazwe pliku i lini� i dat� pliku.
	#define EXCEPTION_PLACE STyp::Tekst(__FILE__) , STyp::Tekst(__func__) , STyp::Ilosc(__LINE__) 

	/**
	* \brief Klasa wyj�tku parsera.
	*
	* Podstawowa klasa wyj�tku. S�u��ca jako klasa bazowa dla pozosta�ych wyj�tk�w
	* lub jako klasa do tworzenia wyj�tk�w nie posiadaj�cych w�asnego typu.
	* \author Daniel Wojdak
	* \version 2
	* \date 13-10-2014
	*/
	class TYPY_PROSTE_LIB Wyjatek :
		public std::exception,
		virtual public SLog::LoggerInterface
	{
	public:
		/**
		* \brief Konstruktor wyj�tku.
		*
		* Konstruktor og�lnego wyj�tku.
		* \param[in] plik - Plik w kt�rym wyst�pi� wyj�tek.
		* \param[in] funkcja - Funkcja w kt�rej wyst�pi� wyj�tek.
		* \param[in] linia - Linia w pliku w kt�rej wyst�pi� wyj�tek.
		* \param[in] sladStosu - �lad stosu w momencie wyst�pienia wyj�tku.
		* \param[in] id - Identyfikator wyj�tku.
		* \param[in] tytul - Tytu� wyj�tku.
		* \param[in] tresc - Opis Wyj�tku.
		* \param[in] debug - Dane opisuj�ce stan aplikacji.
		* \author Daniel Wojdak
		* \version 2
		* \date 13-10-2014
		*/
		Wyjatek(
			const Tekst& plik,
			const Tekst& funkcja,
			const Ilosc& linia,
			const Tekst& debug = Tekst(),
			const Identyfikator& id = Identyfikator(),
			const Tekst& tytul = Tekst(),
			const Tekst& tresc = Tekst()
			);

		/**
		* \brief Konstruktor kopiuj�cy.
		*
		* Domy�lny konstruktor kopiuj�cy.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		Wyjatek(const Wyjatek& obiekt) = default;

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		virtual ~Wyjatek() = default;

		/**
		* \brief Metoda generuj�ca komunikat.
		*
		* Metoda generuj�ca komunikat opisuj�cy sytuacje wyst�pienia wyj�tku.
		* \return Tekst opisuj�cy wyj�tek.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		virtual Tekst generujKomunikat() const;

		/**
		* \brief Metoda pobieraj�ca identyfikator.
		*
		* Metoda pobiera identyfikator wyj�tku.
		* \return Identyfikator wyj�tku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014		
		*/
		const Identyfikator& getNumerWyjaku() const;

		/**
		* \brief Metoda pobieraj�ca tytu�.
		*
		* Metoda pobiera tytu� wyj�tku.
		* \return Tytu� wyj�tku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const Tekst& getTytul() const;

		/**
		* \brief Metoda pobieraj�ca opis.
		*
		* Metoda pobiera opis wyj�tku.
		* \return Opis wyj�tku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const Tekst& getTresc() const;

		/**
		* \brief Metoda pobieraj�ca opis stanu aplikacji.
		*
		* Metoda pobiera opis stanu aplikacji.
		* \return Opis wyj�tku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const Tekst& getDebug() const;

		/**
		* \brief Metoda zwracaj�ca opis obiektu.
		*
		* Metoda zwraca opis obiektu.
		* \return Tekst opisuj�cy ca�y obiekt.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::string napis() const override;

		/**
		* \brief Metoda zwracaj�ca komunikat wyj�tku.
		*
		* Metoda zwraca komunikat wyj�tku.
		* \return Tekst opisuj�cy wyj�tek.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char * what() const override;

	protected:
		Identyfikator identyfikator_; /// Identyfikator wyj�tku.
		Tekst tytul_; /// Tytu� wyj�tku.
		Tekst tresc_; /// Opis wyj�tku.
		Tekst plik_; /// Plik, w kt�rym wyst�pi� wyj�tek. 
		Tekst funkcja_; /// Funkcja, w kt�rej wyst�pi� wyj�tek.
		Ilosc linia_; /// Linia, w kt�rej wyst�pi� wyj�tek.
		Tekst data_; /// Data kompilacji klasy.
		Tekst stack_; /// �lad stosu w momencie wyst�pienia wyj�tku.
		Tekst debug_; /// Dodatkowe dane o aplikacji.

		mutable Tekst komunikat_; /// Obiekt przechowuj�cy komunikat.
	};
}
