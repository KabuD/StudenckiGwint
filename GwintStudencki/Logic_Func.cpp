#include "Logic_Header.h"

Logic::Logic()
{
	endOfRound = false;
	accepted = false;
	mPosition.x = 0;
	mPosition.y = 0;
	whosTurn = STUDENT_TEAM;
}
int Logic::getEvent(SDL_Event * e)
{
	while (SDL_PollEvent(e) != 0)
	{
		if (e->type == SDL_KEYDOWN)
		{
			switch (e->key.keysym.sym)
			{
			      case 27: // esc
			{
					   return 0;
			}
				  case ' ': //spacja
				  {

							if (passStudents && passTeachers) endOfRound = true;

							if (!endOfRound)
							{
								if (visible == TEACHERS_TEAM)
								{
									visible = STUDENT_TEAM;
									passTeachers = true;
								}
								else
								{
									visible = TEACHERS_TEAM;
									passStudents = true;
								}
								return 1;
							}
				  }
				  case 'y':
				  {
							  accepted = true;
							  break;
				  }
			}
		}
		if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (!endOfRound && accepted)
			{
				ifclicked(x, y);
				accepted = false;
			}
			return 1;
		}
	}
	return 1;
}
void Logic::ifclicked(double _x, double _y)
{
	switch (visible)
	{
	case TEACHERS_TEAM:
	{
						  for (int i = 0; i < TeachersBase.size(); i++)
						  {
							  if (TeachersBase[i]->getX()<_x && TeachersBase[i]->getX() + 100>_x && TeachersBase[i]->getY() < _y && TeachersBase[i]->getY() - 100 < _y)
							  {
								  setOnTable(TeachersBase[i], i);
								  break;
							  }
						  }
						  break;
	}
	case STUDENT_TEAM:
	{
						 for (int i = 0; i < StudentsBase.size(); i++)
						 {
							 if (StudentsBase[i]->getX()<_x && StudentsBase[i]->getX() + 100>_x && StudentsBase[i]->getY() < _y && StudentsBase[i]->getY() - 100 < _y)
							 {
								 setOnTable(StudentsBase[i], i);
								 break;
							 }
						 }
						 break;
	}
	}
}
void Logic::setOnTable(Cards * e, int whichOne)
{
	switch (e->getMebership())
	{

	case STUDENT_TEAM:
	{
		{
			if (e->getType() == 1)
			{
				StudentsMelee.push_back(e);
				doneStudentsMelee = false;
				StudentsBase.erase(StudentsBase.begin() + whichOne);
				doneStudentBase = false;
			}
			if (e->getType() == 2)
			{
				StudentsRanged.push_back(e);
				doneStudentsRanged = false;
				StudentsBase.erase(StudentsBase.begin() + whichOne);
				doneStudentBase = false;
			}
			if (e->getType() == 3)
			{
				StudentsSiege.push_back(e);
				doneStudentsSiege = false;
				StudentsBase.erase(StudentsBase.begin() + whichOne);
				doneStudentBase = false;
			}
			if (!passTeachers)
			{

				whosTurn = TEACHERS_TEAM;
				visible = TEACHERS_TEAM;
			}
			break;
		}

	}
	case TEACHERS_TEAM:
	{

						  if (e->getType() == 1)
						  {
							  TeachersMelee.push_back(e);
							  doneTeachersMelee = false;
							  TeachersBase.erase(TeachersBase.begin() + whichOne);
							  doneTeachersBase = false;
						  }
						  if (e->getType() == 2)
						  {
							  TeachersRanged.push_back(e);
							  doneTeachersRanged = false;
							  TeachersBase.erase(TeachersBase.begin() + whichOne);
							  doneTeachersBase = false;
						  }
						  if (e->getType() == 3)
						  {
							  TeachersSiege.push_back(e);
							  doneTeachersSiege = false;
							  TeachersBase.erase(TeachersBase.begin() + whichOne);
							  doneTeachersBase = false;
						  }
						  if (!passStudents)
						  {
							  whosTurn = STUDENT_TEAM;
							  visible = STUDENT_TEAM;
							  break;
						  }

	}
	}
}

Logic::~Logic()
{
		Students.clear();
		Teachers.clear();
		for (int i = StudentsBase.size()-1; i >= 0; i--)
		{
			StudentsBase[i]->~Cards();
		}
		StudentsBase.clear();
		for (int i = 0; i < TeachersBase.size(); i++)
		{
			TeachersBase[i]->~Cards();
		}
		TeachersBase.clear();
		for (int i = 0; i < StudentsMelee.size(); i++)
		{
			StudentsMelee[i]->~Cards();
		}
		StudentsMelee.clear();
		for (int i = 0; i < StudentsRanged.size(); i++)
		{
			StudentsRanged[i]->~Cards();
		}
		StudentsRanged.clear();
		for (int i = 0; i < StudentsSiege.size(); i++)
		{
			StudentsSiege[i]->~Cards();
		}
		StudentsSiege.clear();
		for (int i = 0; i < TeachersMelee.size(); i++)
		{
			TeachersMelee[i]->~Cards();
		}
		TeachersMelee.clear();
		for (int i = 0; i < TeachersRanged.size(); i++)
		{
			TeachersRanged[i]->~Cards();
		}
		TeachersRanged.clear();
		for (int i = 0; i < TeachersSiege.size(); i++)
		{
			TeachersSiege[i]->~Cards();
		}
		TeachersSiege.clear();
		for (int i = 0; i < StudentsUsed.size(); i++)
		{
			StudentsUsed[i]->~Cards();
		}
		StudentsUsed.clear();
		for (int i = 0; i < TeachersUsed.size(); i++)
		{
			TeachersUsed[i]->~Cards();
		}
		TeachersUsed.clear();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
}