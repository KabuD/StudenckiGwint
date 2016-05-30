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

	font = NULL;
	font = TTF_OpenFont("Bolditalic.ttf", 800);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	fontColor = { 1, 1, 1 };

	StudentMeleePointSurface = NULL;
	StudentRangedPointSurface = NULL;
	StudentSiegePointSurface = NULL;
	teachersMeleePointSurface = NULL;
	teachersRangedPointSurface = NULL;
	teachersSiegePointSurface = NULL;

	StudentMeleePointTexture = NULL;
	StudentRangedPointTexture = NULL;
	StudentSiegePointTexture = NULL;
	teachersMeleePointTexture = NULL;
	teachersRangedPointSurface = NULL;
	teachersSiegePointSurface = NULL;

	rect_StudentMeleePoint = { 430, ROW_STUDENTS_MELEE+30, 30, 30 };
	rect_StudentRangedPoint = { 430, ROW_STUDENTS_RANGED+30, 30, 30 };
	rect_StudentSiegePoint = { 430, ROW_STUDENTS_SIEGE+30, 30, 30 };
	rect_TeachersMeleePoint = { 430, ROW_TEACHERS_MELEE+35, 30, 30 };
	rect_TeachersRangedPoint = { 430, ROW_TEACHERS_RANGED+30, 30, 30 };
	rect_TeachersSiegePoint = { 430, ROW_TEACHERS_SIEGE+30, 30, 30 };
}
void Logic::playerPass()
{
	switch (visible)
	{
	case TEACHERS_TEAM:
	{
						  visible = STUDENT_TEAM;
						  passTeachers = true;
						  break;
	}
	case STUDENT_TEAM:
	{
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
									viewPointScore();
								}
								return 1;

				  }
				  case 'y':
				  {
							 // ifcurtain = false;
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

	switch (e->getMembership())
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
	reloadPoints(); // updates points if ability is used 
	loadCounter(); // updates points
}
void Logic::addPointsAfterSettingOnTable(Cards * e)
{
	switch (e->getMembership())
	{
	case STUDENT_TEAM:
	{
						 if (e->getType() == TYPE_MELEE)
						 {
							 int allPoints = 0;
							 for (int i = 0; i < StudentsMelee.size(); i++)
							 {
								 allPoints += StudentsMelee[i]->getPoints();
							 }
							 StudentsMeleePoints = allPoints;
						 }
							
						 if (e->getType() == TYPE_RANGED)
						 {
							 int allPoints = 0;
							 for (int i = 0; i < StudentsRanged.size(); i++)
							 {
								 allPoints += StudentsRanged[i]->getPoints();
							 }
							 StudentsRangedPoints = allPoints;
						 }
						 if (e->getType() == TYPE_SIEGE)
						 {
							 int allPoints = 0;
							 for (int i = 0; i < StudentsSiege.size(); i++)
							 {
								 allPoints += StudentsSiege[i]->getPoints();
							 }
							 StudentsSiegePoints = allPoints;
						 }
						 break;

	}
	case TEACHERS_TEAM:
	{
						  if (e->getType() == TYPE_MELEE)
						  {
							  int allPoints = 0;
							  for (int i = 0; i < TeachersMelee.size(); i++)
							  {
								  allPoints += TeachersMelee[i]->getPoints();
							  }
							  TeachersMeleePoints = allPoints;
						  }
						  if (e->getType() == TYPE_RANGED)
						  {
							  int allPoints = 0;
							  for (int i = 0; i < TeachersRanged.size(); i++)
							  {
								  allPoints += TeachersRanged[i]->getPoints();
							  }
							  TeachersRangedPoints = allPoints;
						  }
						  if (e->getType() == TYPE_SIEGE)
						  {
							  int allPoints = 0;
							  for (int i = 0; i < TeachersSiege.size(); i++)
							  {
								  allPoints += TeachersSiege[i]->getPoints();
							  }
							  TeachersSiegePoints = allPoints;
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
	case ABILITY_SPY: // setting done in setOnTable func by few ifs. dunno how to make it here
	{
						  CardWithSpyAbility(e);
						  break;
	}
	case ABILITY_ALL4ONE:
	{
							CardWithAllForOneAbility(e);
							break;
	}
	case ABILITY_MEDIC:
	{
						  //TODO
						  break;
	}
	}
}
void Logic::CardWithSpyAbility(Cards * e)
{
	if (e->getMembership() == STUDENT_TEAM)
	{
		drawOneCard(STUDENT_TEAM);
		drawOneCard(STUDENT_TEAM);
	}
	if (e->getMembership() == TEACHERS_TEAM)
	{
		drawOneCard(TEACHERS_TEAM);
		drawOneCard(TEACHERS_TEAM);
	}
}
void Logic::CardWithAllForOneAbility(Cards *e)
{
	switch (e->getMembership())
	{
	case STUDENT_TEAM:
	{

						 if (e->getType() == 1)
						 {
							 int howManyOfAKind = 0; //checking how many of same card are there 
							 for (int i = 0; i < StudentsMelee.size(); i++)
							 {
								 if (StudentsMelee[i]->getName() == e->getName())
								 {
									 howManyOfAKind += 1;
								 }
							 }

							 e->multiplyPoints(howManyOfAKind);

							 for (int i = 0; i < StudentsMelee.size(); i++)
							 {
								 if (StudentsMelee[i]->getName() == e->getName())
								 {
									 StudentsMelee[i]->multiplyPoints(howManyOfAKind);
								 }
							 }
						 }
						 if (e->getType() == 2)
						 {
							 int howManyOfAKind = 0; //checking how many of same card are there 
							 for (int i = 0; i < StudentsRanged.size(); i++)
							 {
								 if (StudentsRanged[i]->getName() == e->getName())
								 {
									 howManyOfAKind += 1;
									 StudentsRanged[i]->multiplyPoints(1);
								 }
							 }

							 e->multiplyPoints(howManyOfAKind);

							 for (int i = 0; i < StudentsRanged.size(); i++)
							 {
								 if (StudentsRanged[i]->getName() == e->getName())
								 {
									 StudentsRanged[i]->multiplyPoints(howManyOfAKind);
								 }
							 }
						 }
						 if (e->getType() == 3)
						 {
							 int howManyOfAKind = 0; //checking how many of same card are there 
							 for (int i = 0; i < StudentsSiege.size(); i++)
							 {
								 if (StudentsSiege[i]->getName() == e->getName())
								 {
									 howManyOfAKind += 1;
									 StudentsSiege[i]->multiplyPoints(1);
								 }
							 }

							 e->multiplyPoints(howManyOfAKind);

							 for (int i = 0; i < StudentsSiege.size(); i++)
							 {
								 if (StudentsSiege[i]->getName() == e->getName())
								 {
									 StudentsSiege[i]->multiplyPoints(howManyOfAKind);
								 }
							 }
						 }
						 break;
	}
	case TEACHERS_TEAM:
	{

						  if (e->getType() == 1)
						  {
							  int howManyOfAKind = 0; //checking how many of same card are there 
							  for (int i = 0; i < TeachersMelee.size(); i++)
							  {
								  if (TeachersMelee[i]->getName() == e->getName())
								  {
									  howManyOfAKind += 1;
									  TeachersMelee[i]->multiplyPoints(1);
								  }
							  }

							  e->multiplyPoints(howManyOfAKind);

							  for (int i = 0; i < TeachersMelee.size(); i++)
							  {
								  if (TeachersMelee[i]->getName() == e->getName())
								  {
									  TeachersMelee[i]->multiplyPoints(howManyOfAKind);
								  }
							  }
						  }
						  if (e->getType() == 2)
						  {
							  int howManyOfAKind = 0; //checking how many of same card are there 
							  for (int i = 0; i < TeachersRanged.size(); i++)
							  {
								  if (TeachersRanged[i]->getName() == e->getName())
								  {
									  howManyOfAKind += 1;
									  TeachersRanged[i]->multiplyPoints(1);
								  }
							  }

							  e->multiplyPoints(howManyOfAKind);

							  for (int i = 0; i < TeachersRanged.size(); i++)
							  {
								  if (TeachersRanged[i]->getName() == e->getName())
								  {
									  TeachersRanged[i]->multiplyPoints(howManyOfAKind);
								  }
							  }
						  }
						  if (e->getType() == 3)
						  {
							  int howManyOfAKind = 0; //checking how many of same card are there 
							  for (int i = 0; i < TeachersSiege.size(); i++)
							  {
								  if (TeachersSiege[i]->getName() == e->getName())
								  {
									  howManyOfAKind += 1;
									  TeachersSiege[i]->multiplyPoints(1);
								  }
							  }

							  e->multiplyPoints(howManyOfAKind);

							  for (int i = 0; i < TeachersSiege.size(); i++)
							  {
								  if (TeachersSiege[i]->getName() == e->getName())
								  {
									  TeachersSiege[i]->multiplyPoints(howManyOfAKind);
								  }
							  }
						  }
						  break;
	}
	}
}
void Logic::loadCounter()
{
	string pointsInString = to_string(StudentsMeleePoints);
	StudentMeleePointSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);
	pointsInString = to_string(StudentsRangedPoints);
	StudentRangedPointSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);
	pointsInString = to_string(StudentsSiegePoints);
	StudentSiegePointSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);
	pointsInString = to_string(TeachersMeleePoints);
	teachersMeleePointSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);
	pointsInString = to_string(TeachersRangedPoints);
	teachersRangedPointSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);
	pointsInString = to_string(TeachersSiegePoints);
	teachersSiegePointSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);

	StudentMeleePointTexture = SDL_CreateTextureFromSurface(renderer, StudentMeleePointSurface);
	StudentRangedPointTexture = SDL_CreateTextureFromSurface(renderer, StudentRangedPointSurface);
	StudentSiegePointTexture = SDL_CreateTextureFromSurface(renderer, StudentSiegePointSurface);
	teachersMeleePointTexture = SDL_CreateTextureFromSurface(renderer, teachersMeleePointSurface);
	teachersRangedPointTexture = SDL_CreateTextureFromSurface(renderer, teachersRangedPointSurface);
	teachersSiegePointTexture = SDL_CreateTextureFromSurface(renderer, teachersSiegePointSurface);
}
void Logic::viewPointScore()
{
	SDL_RenderCopy(renderer, StudentMeleePointTexture, NULL, &rect_StudentMeleePoint);
	SDL_RenderCopy(renderer, StudentRangedPointTexture, NULL, &rect_StudentRangedPoint);
	SDL_RenderCopy(renderer, StudentSiegePointTexture, NULL, &rect_StudentSiegePoint);
	SDL_RenderCopy(renderer, teachersMeleePointTexture, NULL, &rect_TeachersMeleePoint);
	SDL_RenderCopy(renderer, teachersRangedPointTexture, NULL, &rect_TeachersRangedPoint);
	SDL_RenderCopy(renderer, teachersSiegePointTexture, NULL, &rect_TeachersSiegePoint);
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

		SDL_DestroyTexture(StudentMeleePointTexture);
		SDL_DestroyTexture(StudentRangedPointTexture);
		SDL_DestroyTexture(StudentSiegePointTexture);

		SDL_DestroyTexture(teachersMeleePointTexture);
		SDL_DestroyTexture(teachersRangedPointTexture);
		SDL_DestroyTexture(teachersSiegePointTexture);

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
}

