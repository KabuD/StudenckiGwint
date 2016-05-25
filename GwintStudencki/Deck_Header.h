#ifndef DECK_HEADER_H
#define DECK_HEADER_H

#include "Cards_Header.h"

int TEACHERS_TEAM = 1;
int STUDENT_TEAM = 2;
int NOT_VISIBLE_CARD = 0;
int VISIBLE_CARD = 1;
int ABILITY_NONE = 0;
int ABILITY_ALL4ONE = 1;
int ABILITY_SPY = 2;
int ABILITY_MEDIC = 3;
int TYPE_MELEE = 1;
int TYPE_RANGED = 2;
int TYPE_SIEGE = 3;

class Deck
{
protected:
	SDL_Renderer *renderer;
	vector<Cards*>Students;
	vector<Cards*>Teachers;
public:
	Deck(SDL_Renderer *_renderer)
	{
		renderer = _renderer;

		//  STUDENT'S DECK
		Students.push_back(new Cards(1, "karty/student.png", 4, TYPE_MELEE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(2, "karty/student.png", 4, TYPE_MELEE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(3, "karty/student.png", 4, TYPE_MELEE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(4, "karty/cwaniak.png", 2, TYPE_MELEE, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(5, "karty/notatki.png", 5, TYPE_RANGED, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(6, "karty/notatki.png", 5, TYPE_RANGED, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(7, "karty/notatki.png", 5, TYPE_RANGED, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(8, "karty/starosta.png", 4, TYPE_MELEE, STUDENT_TEAM, ABILITY_SPY));
		Students.push_back(new Cards(9, "karty/korepetytor.png", 1, TYPE_SIEGE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(10, "karty/korepetytor.png", 1, TYPE_SIEGE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(11, "karty/korepetytor.png", 1, TYPE_SIEGE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(12, "karty/zzeszlychlat.png", 6, TYPE_RANGED, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(13, "karty/matlab.png", 5, TYPE_RANGED, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(14, "karty/etrapez.png", 8, TYPE_SIEGE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(15, "karty/etrapez.png", 8, TYPE_SIEGE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(16, "karty/redbull.png", 8, TYPE_SIEGE, STUDENT_TEAM, ABILITY_MEDIC));
		Students.push_back(new Cards(17, "karty/typowystudent.png", 5, TYPE_MELEE, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(18, "karty/imprezowicz.png", 2, TYPE_MELEE, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(19, "karty/pomocnygrzes.png", 4, TYPE_RANGED, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(20, "karty/tenodpytan.png", 4, TYPE_MELEE, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(21, "karty/pomocnikwykladowcy.png", 1, TYPE_SIEGE, STUDENT_TEAM, ABILITY_SPY));
		Students.push_back(new Cards(22, "karty/tenodprzekladania.png", 4, TYPE_MELEE, STUDENT_TEAM, ABILITY_SPY));
		Students.push_back(new Cards(23, "karty/nawalony.png", 1, TYPE_MELEE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(24, "karty/nawalony.png", 1, TYPE_MELEE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(25, "karty/nawalony.png", 1, TYPE_MELEE, STUDENT_TEAM, ABILITY_ALL4ONE));
		Students.push_back(new Cards(26, "karty/sesja.png", 6, TYPE_SIEGE, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(27, "karty/sesja.png", 6, TYPE_SIEGE, STUDENT_TEAM, ABILITY_NONE));
		Students.push_back(new Cards(28, "karty/wscieklystudent.png", 4, TYPE_MELEE, STUDENT_TEAM, ABILITY_NONE));


		// TEACHER'S DECK
		Teachers.push_back(new Cards(51, "karty/egzamin.png", 10, TYPE_RANGED, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(52, "karty/egzamin.png", 10, TYPE_RANGED, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(53, "karty/wejsciowka.png", 2, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(54, "karty/wejsciowka.png", 2, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(55, "karty/wejsciowka.png", 2, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(56, "karty/wejsciowka.png", 2, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(57, "karty/sprawozdanie.png", 3, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(58, "karty/sprawozdanie.png", 3, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(59, "karty/latwykolos.png", 9, TYPE_RANGED, TEACHERS_TEAM, ABILITY_SPY));
		Teachers.push_back(new Cards(60, "karty/trudnymaterial.png", 6, TYPE_RANGED, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(61, "karty/slabywyklad.png", 10, TYPE_SIEGE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(62, "karty/projektzinfy.png",10, TYPE_SIEGE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(63, "karty/prostecwiczenia.png", 7, TYPE_RANGED, TEACHERS_TEAM, ABILITY_SPY));
		Teachers.push_back(new Cards(64, "karty/obowiazkowezadania.png", 2, TYPE_MELEE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(65, "karty/kolokwium.png", 5, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(66, "karty/kolokwium.png", 5, TYPE_MELEE, TEACHERS_TEAM, ABILITY_ALL4ONE));
		Teachers.push_back(new Cards(67, "karty/wkurzonyprowadzacy.png", 6, TYPE_RANGED, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(68, "karty/odpowiedzustna.png", 3, TYPE_MELEE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(69, "karty/ujemnepunkty.png", 3, TYPE_SIEGE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(70, "karty/drinz.png", 1, TYPE_SIEGE, TEACHERS_TEAM, ABILITY_MEDIC));
		Teachers.push_back(new Cards(71, "karty/trudnyprzyklad.png", 3, TYPE_MELEE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(72, "karty/egzaminpoprawkowy.png", 5, TYPE_MELEE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(73, "karty/kolokwiumpoprawkowe.png", 4, TYPE_MELEE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(74, "karty/egzaminkomisyjny.png", 4, TYPE_RANGED, TEACHERS_TEAM, ABILITY_SPY));
		Teachers.push_back(new Cards(75, "karty/prowadzacy.png", 4, TYPE_MELEE, TEACHERS_TEAM, ABILITY_NONE));
		Teachers.push_back(new Cards(76, "karty/egzaminustny.png", 6, TYPE_RANGED, TEACHERS_TEAM, ABILITY_NONE));
	}
	void Draw()
	{
		for (auto &a : Students)
		{
			a->Draw(renderer);
		}
		for (auto &a : Teachers)
		{
			a->Draw(renderer);
		}
		
	}
	~Deck()
	{
		Students.clear();
		Teachers.clear();
	}
};

#endif