#include "Logic_Header.h"

Logic::Logic()
{
	endOfRound = false;
	ifcurtain = true;
	mPosition.x = 0;
	mPosition.y = 0;
	whosTurn = STUDENT_TEAM;

	passStudents = false;
	passTeachers = false;


	StudentsMeleePoints = 0;
	StudentsRangedPoints = 0;
	StudentsSiegePoints = 0;
	TeachersMeleePoints = 0;
	TeachersRangedPoints = 0;
	TeachersSiegePoints = 0;

}
void Logic::playerPass()
{
	switch (visible)
	{
	case TEACHERS_TEAM:
	{
						  stopper = NULL;
						  stopper = IMG_LoadTexture(renderer, "student.png");
						  visible = STUDENT_TEAM;
						  passTeachers = true;
						  break;
	}
	case STUDENT_TEAM:
	{
						 stopper = NULL;
						 stopper = IMG_LoadTexture(renderer, "prowadzacy.png");
						 visible = TEACHERS_TEAM;
						 passStudents = true;
						 break;
	}
	}
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

								playerPass();
								if (passStudents && passTeachers)
								{
									endOfRound = true;
								}
								if (endOfRound)
								{
									pointScore();
								}
								return 1;

				  }
				  case 'y':
				  {
							  ifcurtain = false;
							  break;
				  }
			}
		}
		if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (!endOfRound)
			{
				ifclicked(x, y);
				ifcurtain = true;
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
	checkAbility(e); 

	switch (e->getMebership())
	{
	case STUDENT_TEAM:
	{
						 if (e->getType() == TYPE_MELEE)
						 {
							 if (e->getAbility() != ABILITY_SPY)
							 {
								 StudentsMelee.push_back(e);
								 doneStudentsMelee = false;
								 addPointsAfterSettingOnTable(e);
							 }
							 else
							 {
								 e->changeMembership();
								 TeachersMelee.push_back(e);
								 doneTeachersMelee = false;
								 addPointsAfterSettingOnTable(e);
							 }
							 StudentsBase.erase(StudentsBase.begin() + whichOne);
							 doneStudentBase = false;
						 }
						 if (e->getType() == TYPE_RANGED)
						 {
							 if (e->getAbility() != ABILITY_SPY)
							 {
								 StudentsRanged.push_back(e);
								 doneStudentsRanged = false;
								 addPointsAfterSettingOnTable(e);
							 }
							 else
							 {
								 e->changeMembership();
								 TeachersRanged.push_back(e);
								 doneTeachersRanged = false;
								 addPointsAfterSettingOnTable(e);
							 }
							 StudentsBase.erase(StudentsBase.begin() + whichOne);
							 doneStudentBase = false;
						 }
						 if (e->getType() == TYPE_SIEGE)
						 {
							 if (e->getAbility() != ABILITY_SPY)
							 {
								 StudentsSiege.push_back(e);
								 doneStudentsSiege = false;
								 addPointsAfterSettingOnTable(e);
							 }
							 else
							 {
								 e->changeMembership();
								 TeachersSiege.push_back(e);
								 doneTeachersSiege = false;
								 addPointsAfterSettingOnTable(e);
							 }
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
	case TEACHERS_TEAM:
	{

						  if (e->getType() == TYPE_MELEE)
						  {
							  if (e->getAbility() != ABILITY_SPY)
							  {
								  TeachersMelee.push_back(e);
								  doneTeachersMelee = false;
								  addPointsAfterSettingOnTable(e);
							  }
							  else
							  {
								  e->changeMembership();
								  StudentsMelee.push_back(e);
								  doneTeachersMelee = false;
								  addPointsAfterSettingOnTable(e);
							  }
							  TeachersBase.erase(TeachersBase.begin() + whichOne);
							  doneTeachersBase = false;
						  }
						  if (e->getType() == TYPE_RANGED)
						  {
							  if (e->getAbility() != ABILITY_SPY)
							  {
								  TeachersRanged.push_back(e);
								  doneTeachersRanged = false;
								  addPointsAfterSettingOnTable(e);
							  }
							  else
							  {
								  e->changeMembership();
								  StudentsRanged.push_back(e);
								  doneStudentsRanged = false;
								  addPointsAfterSettingOnTable(e);
							  }
							  TeachersBase.erase(TeachersBase.begin() + whichOne);
							  doneTeachersBase = false;
						  }
						  if (e->getType() == TYPE_SIEGE)
						  {
							  if (e->getAbility() != ABILITY_SPY)
							  {
								  TeachersSiege.push_back(e);
								  doneTeachersSiege = false;
								  addPointsAfterSettingOnTable(e);
							  }
							  else
							  {
								  e->changeMembership();
								  StudentsSiege.push_back(e);
								  doneStudentsSiege = false;
								  addPointsAfterSettingOnTable(e);
							  }
							  TeachersBase.erase(TeachersBase.begin() + whichOne);
							  doneTeachersBase = false;
						  }
						  if (!passStudents)
						  {
							  whosTurn = STUDENT_TEAM;
							  visible = STUDENT_TEAM;
						  }
						  break;
	}
	}
}
void Logic::addPointsAfterSettingOnTable(Cards * e)
{
	switch (e->getMebership())
	{
	case STUDENT_TEAM:
	{

						 if (e->getType() == 1)
						 {
							 StudentsMeleePoints += e->getPoints();
						 }
						 if (e->getType() == 2)
						 {
							 StudentsRangedPoints += e->getPoints();
						 }
						 if (e->getType() == 3)
						 {
							 StudentsSiegePoints += e->getPoints();
						 }
						 break;
	}
	case TEACHERS_TEAM:
	{

						  if (e->getType() == 1)
						  {
							  TeachersMeleePoints += e->getPoints();
						  }
						  if (e->getType() == 2)
						  {
							  TeachersRangedPoints += e->getPoints();
						  }
						  if (e->getType() == 3)
						  {
							  TeachersSiegePoints += e->getPoints();
						  }
						  break;
	}
	}
}
void Logic::checkAbility(Cards * e)
{
	switch (e->getAbility())
	{
	case ABILITY_NONE:
	{
						 break;
	}
	case ABILITY_SPY: // already done in setOnTable func by few ifs. dunno how to make it here
	{
						break;
	}
	case ABILITY_ALL4ONE:
	{
							//TODO
						  break;
	}
	case ABILITY_MEDIC:
	{
						  //TODO
						  break;
	}
	}
}
void Logic::pointScore()
{
	cout << "Teachers Melee: " << TeachersMeleePoints << endl;
	cout << "Teachers Ranged: " << TeachersRangedPoints << endl;
	cout << "Teachers Siege: " << TeachersSiegePoints << endl;
	cout << "Students Melee: " << StudentsMeleePoints << endl;
	cout << "Students Ranged: " << StudentsRangedPoints << endl;
	cout << "Students Siege: " << StudentsSiegePoints << endl;





}
bool Logic::getIfCurtain()
{
	return ifcurtain;
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
		SDL_DestroyTexture(image_score);
		SDL_DestroyTexture(image_studentsPass);
		SDL_DestroyTexture(image_studentsTurn);
		SDL_DestroyTexture(image_teachersTurn);
		SDL_DestroyTexture(image_teachersPass);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
}

