#include "Deck_Header.h"

bool ifDrawed(int iLiczba, int tab[], int ile)
{
	if (ile <= 0)
		return false;

	int i = 0;
	do
	{
		if (tab[i] == iLiczba)
			return true;

		i++;
	} while (i < ile);

	return false;
}

Deck::Deck()
{
	passStudents = false;
	passTeachers = false;

	visible = STUDENT_TEAM;
	whosTurn = STUDENT_TEAM;

	doneStudentBase = false;
	doneTeachersBase = false;

    doneStudentsMelee = false;
	doneStudentsRanged = false;
	doneStudentsSiege = false;

	doneTeachersMelee = false;
	doneTeachersRanged = false;
	doneTeachersSiege = false;

	doneStudentsUsed = false;
    doneTeachersUsed = false;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
    window = NULL;
	window = SDL_CreateWindow("Gwint Studencki", WINDOW_x, WINDOW_y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


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
	Teachers.push_back(new Cards(62, "karty/projektzinfy.png", 10, TYPE_SIEGE, TEACHERS_TEAM, ABILITY_NONE));
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

void Deck::drawingStudentsCards()
{
	int cards[10];
	int drawed = 0;
	do
	{
		int liczba = rand() % Students.size() + 0;
		if (ifDrawed(liczba, cards, drawed) == false)
		{
			cards[drawed] = liczba;
			drawed++;
		}
	} while (drawed < 10);

	for (int i = 10; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (cards[j]<cards[j + 1])
			{
				int liczba;
				liczba = cards[j + 1];
				cards[j + 1] = cards[j];
				cards[j] = liczba;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		StudentsBase.push_back(Students[cards[i]]);
		Students.erase(Students.begin() + cards[i]);
	}

}

void Deck::drawingTeachersCards()
{
	int cards[10];
	int drawed = 0;
	do
	{
		int liczba = rand() % Teachers.size() + 0;
		if (ifDrawed(liczba, cards, drawed) == false)
		{
			cards[drawed] = liczba;
			drawed++;
		}
	} while (drawed < 10);

	for (int i = 10; i>0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (cards[j]<cards[j + 1])
			{
				int liczba;
				liczba = cards[j + 1];
				cards[j + 1] = cards[j];
				cards[j] = liczba;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		TeachersBase.push_back(Teachers[cards[i]]);
		Teachers.erase(Teachers.begin() + cards[i]);
	}
}

void Deck::loadDeckTexture()
{
	for (int i = 1; i < StudentsBase.size() + 1; i++)
	{
		StudentsBase[i - 1]->loadCardTexture(renderer);
		StudentsBase[i - 1]->loadPoints(renderer);
	}
	for (int i = 1; i < TeachersBase.size() + 1; i++)
	{
		TeachersBase[i - 1]->loadCardTexture(renderer);
		TeachersBase[i - 1]->loadPoints(renderer);
	}
}

void Deck::loadAndSetCards()
{
	////////////////////////////////////////////////////////////STUDENT S BASE
	for (int i = 1; i < StudentsBase.size()+1; i++)
	{
		if (!doneStudentBase)
		{
			StudentsBase[i - 1]->changeRow(756);
			StudentsBase[i - 1]->changePosInRow(100 + (i * 100));
			if(i==StudentsBase.size())doneStudentBase = true;
		}
		if (visible == STUDENT_TEAM)	StudentsBase[i - 1]->drawCard(renderer);
	}

	///////////////////////////////////////////////////////////TEACHERS S BASE
	for (int i = 1; i <TeachersBase.size() + 1; i++)
	{
		if (!doneTeachersBase)
		{
			TeachersBase[i - 1]->changeRow(756);
			TeachersBase[i - 1]->changePosInRow(100 + (i*100));
			if(i==TeachersBase.size())doneTeachersBase = true;
		}
	if(visible==TEACHERS_TEAM)	TeachersBase[i - 1]->drawCard(renderer);
	}

	///////////////////////////////////////////////////////////STUDENT S MELEE
	for (int i = 1; i < StudentsMelee.size() + 1; i++)
	{
		if (!doneStudentsMelee)
		{
			StudentsMelee[i - 1]->changeRow(441);
			StudentsMelee[i - 1]->changePosInRow(100 + (i * 100));
			if (i == StudentsMelee.size())doneStudentsMelee = true;
		}
		StudentsMelee[i - 1]->drawCard(renderer);
	}
	///////////////////////////////////////////////////////////STUDENT S RANGED
	for (int i = 1; i < StudentsRanged.size() + 1; i++)
	{
		if (!doneStudentsRanged)
		{
			StudentsRanged[i - 1]->changeRow(546);
			StudentsRanged[i - 1]->changePosInRow(100 + (i * 100));
			if (i == StudentsRanged.size())doneStudentsRanged = true;
		}
		StudentsRanged[i - 1]->drawCard(renderer);
	}
	///////////////////////////////////////////////////////////STUDENT S SIEGE
	for (int i = 1; i < StudentsSiege.size() + 1; i++)
	{
		if (!doneStudentsSiege)
		{
			StudentsSiege[i - 1]->changeRow(651);
			StudentsSiege[i - 1]->changePosInRow(100 + (i * 100));
			if (i == StudentsSiege.size())doneStudentsSiege = true;
		}
		StudentsSiege[i - 1]->drawCard(renderer);
	}
	///////////////////////////////////////////////////////////TEACHERS S MELEE
	for (int i = 1; i < TeachersMelee.size() + 1; i++)
	{
		if (!doneTeachersMelee)
		{
			cout << "i" << endl;
			TeachersMelee[i - 1]->changeRow(336);
			TeachersMelee[i - 1]->changePosInRow(100 + (i * 100));
			if (i == TeachersMelee.size())doneTeachersMelee = true;
		}
		TeachersMelee[i - 1]->drawCard(renderer);
	}
	///////////////////////////////////////////////////////////TEACHERS S RANGED
	for (int i = 1; i < TeachersRanged.size() + 1; i++)
	{
		if (!doneTeachersRanged)
		{
			cout << "i" << endl;
			TeachersRanged[i - 1]->changeRow(231);
			TeachersRanged[i - 1]->changePosInRow(100 + (i * 100));
			if (i == TeachersRanged.size())doneTeachersRanged = true;
		}
		TeachersRanged[i - 1]->drawCard(renderer);
	}
	///////////////////////////////////////////////////////////TEACHERS S RANGED
	for (int i = 1; i < TeachersSiege.size() + 1; i++)
	{
		if (!doneTeachersSiege)
		{
			cout << "i" << endl;
			TeachersSiege[i - 1]->changeRow(126);
			TeachersSiege[i - 1]->changePosInRow(100 + (i * 100));
			if (i == TeachersSiege.size())doneTeachersSiege = true;
		}
		TeachersSiege[i - 1]->drawCard(renderer);
	}

}

SDL_Renderer * Deck::getRenderer()
{
	return renderer;
}