#include "Logic_Header.h"

Logic::Logic()
{
	endOfRound = false;
	endGAME = false;
	whosTurn = STUDENT_TEAM;

	passStudents = false;
	passTeachers = false;
	passCount = 0;

	StudentsMeleePoints = 0;
	StudentsRangedPoints = 0;
	StudentsSiegePoints = 0;
	TeachersMeleePoints = 0;
	TeachersRangedPoints = 0;
	TeachersSiegePoints = 0;

	TeacherScore = 0;
	StudentScore = 0;

	sizeOfStudent = 10;
	sizeOfTeacher = 10;

	SWonRounds = 0;
	TWonRounds = 0;

	ifcurtain = true;
	whichCurtain = CURTAIN_STUDENTTURN;

	font = NULL;
	font = TTF_OpenFont("Bolditalic.ttf", 800);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	fontColor = { 1, 1, 1 };
	cardNumberColor = { 255, 165, 0 };

	StudentMeleePointSurface = NULL;
	StudentRangedPointSurface = NULL;
	StudentSiegePointSurface = NULL;
	teachersMeleePointSurface = NULL;
	teachersRangedPointSurface = NULL;
	teachersSiegePointSurface = NULL;

	StudentScoreSurface=NULL;
	TeacherScoreSufrace=NULL;

	sizeOfStudentSurface = NULL;
	sizeOfTeacherSurface = NULL;

	StudentMeleePointTexture = NULL;
	StudentRangedPointTexture = NULL;
	StudentSiegePointTexture = NULL;
	teachersMeleePointTexture = NULL;
	teachersRangedPointSurface = NULL;
	teachersSiegePointSurface = NULL;

	StudentScoreTexture=NULL;
    TeacherScoreTexture=NULL;

	sizeOfStudentTexture = NULL;
	sizeOfTeacherTexture = NULL;


	rect_StudentMeleePoint = { 430, ROW_STUDENTS_MELEE+32, 30, 30 };
	rect_StudentRangedPoint = { 430, ROW_STUDENTS_RANGED+28, 30, 30 };
	rect_StudentSiegePoint = { 430, ROW_STUDENTS_SIEGE+30, 30, 30 };
	rect_TeachersMeleePoint = { 430, ROW_TEACHERS_MELEE+35, 30, 30 };
	rect_TeachersRangedPoint = { 430, ROW_TEACHERS_RANGED+30, 30, 30 };
	rect_TeachersSiegePoint = { 430, ROW_TEACHERS_SIEGE+30, 30, 30 };

	rect_TeacherScore = { 362, 264, 30, 30 };
	rect_StudentScore = { 362, 597, 30, 30 };

	rect_sizeOfStudent = { 230, 577, 30, 30 }; 
	rect_sizeOfTeacher = { 230, 295, 30, 30 };
}

void Logic::playerPass()
{
	switch (passCount)
	{
	case 0:
	{
			  switch (visible)
			  {
			  case TEACHERS_TEAM:
			  {
									ifcurtain = true;
									whichCurtain = CURTAIN_TEACHERPASS;
									visible = STUDENT_TEAM;
									passTeachers = true;
									break;
			  }
			  case STUDENT_TEAM:
			  {
								   ifcurtain = true;
								   whichCurtain = CURTAIN_STUDENTPASS;
								   visible = TEACHERS_TEAM;
								   passStudents = true;
								   break;
			  }
			  }
			  passCount = 1;
			  break;
	}
	case 1:
	{
			  passCount = 2;
			  break;
	}
	}
	cout << "Curtain: " << whichCurtain << endl;
	cout << "IfCurtain" << ifcurtain << endl;
}

void Logic::playerChange()
{
	if (!passStudents && !passTeachers) // if both teams didnt push space
	{
		switch (visible)
		{
		case TEACHERS_TEAM:
		{
							  ifcurtain = true;
							  whichCurtain = CURTAIN_STUDENTTURN;
							  visible = STUDENT_TEAM;
							  break;
		}
		case STUDENT_TEAM:
		{
							 ifcurtain = true;
							 whichCurtain = CURTAIN_TEACHERTURN;
							 visible = TEACHERS_TEAM;
							 break;
		}
		}
	}
	if (passStudents) // if student pushed space
	{
		visible = TEACHERS_TEAM;
	}
	if (passTeachers) // if teacher pushed space
	{
		visible = STUDENT_TEAM;
	}
}

void Logic::checkIfEndRound()
{
	if (passCount == 2)
	{
		deciedeWhoWinsTheRound();
		giveAllFieldCardsToUsed();
		deleteAllBonuses();
		reloadPoints();
		passCount = 0;
	}
}

void Logic::checkIfEndGame()
{
	if (!endGAME) // to make sure this isn t made infinite times
	{
		if (SWonRounds == 2 || TWonRounds == 2)
		{
			if (score.size() == 3)
			{
				StudentsMeleePoints = score[0].students;
				TeachersMeleePoints = score[0].teachers;

				StudentsRangedPoints = score[1].students;
				TeachersRangedPoints = score[1].teachers;

				StudentsSiegePoints = score[2].students;
				TeachersSiegePoints = score[2].teachers;
			}
			if (score.size() == 2)
			{
				StudentsMeleePoints = score[0].students;
				TeachersMeleePoints = score[0].teachers;

				StudentsRangedPoints = score[1].students;
				TeachersRangedPoints = score[1].teachers;

				StudentsSiegePoints = 0;
				TeachersSiegePoints = 0;
			}
			rect_StudentMeleePoint = { 760, 556, 30, 30 };
			rect_TeachersMeleePoint = { 760, 500, 30, 30 };
			rect_StudentRangedPoint = { 890, 556, 30, 30 };
			rect_TeachersRangedPoint = { 890, 500, 30, 30 };
			rect_StudentSiegePoint = { 1010, 556, 30, 30 };
			rect_TeachersSiegePoint = { 1010, 500, 30, 30 };
			loadCounter();
			endGAME = true;
		}
	}
	if (SWonRounds == 2)
	{
		SDL_RenderCopy(renderer, image_sWonGame, NULL, &curtain_rect);
	}
	if (TWonRounds == 2)
	{
		SDL_RenderCopy(renderer, image_tWonGame, NULL, &curtain_rect);
	}
}

void Logic::loadCurtains()
{
	curtain_rect = { 63, -43, 1600, 900 };

	image_studentsWin = NULL;
	image_studentsWin = IMG_LoadTexture(renderer, "karty/curtain/swr.png");

	image_teachersWin = NULL;
	image_teachersWin = IMG_LoadTexture(renderer, "karty/curtain/twr.png");


	image_teachersTurn = NULL;
	image_teachersTurn = IMG_LoadTexture(renderer, "karty/curtain/tturn.png");
	image_teachersPass = NULL;
	image_teachersPass = IMG_LoadTexture(renderer, "karty/curtain/tpass.png");

	image_studentsTurn = NULL;
	image_studentsTurn = IMG_LoadTexture(renderer, "karty/curtain/sturn.png");
	image_studentsPass = NULL;
	image_studentsPass = IMG_LoadTexture(renderer, "karty/curtain/spass.png");

	image_sWonGame = NULL;
	image_sWonGame = IMG_LoadTexture(renderer, "karty/curtain/swg.png");

	image_tWonGame = NULL;
	image_tWonGame = IMG_LoadTexture(renderer, "karty/curtain/twg.png");

}

void Logic::showCurtain(int whichOne)
{
	if (ifcurtain)
	{
		if (whichOne == CURTAIN_TEACHERPASS){ SDL_RenderCopy(renderer, image_teachersPass, NULL, &curtain_rect); }
		if (whichOne == CURTAIN_STUDENTPASS){ SDL_RenderCopy(renderer, image_studentsPass, NULL, &curtain_rect); }
		if (whichOne == CURTAIN_STUDENTTURN){ SDL_RenderCopy(renderer, image_studentsTurn, NULL, &curtain_rect); }
		if (whichOne == CURTAIN_TEACHERTURN){ SDL_RenderCopy(renderer, image_teachersTurn, NULL, &curtain_rect); }
		if (whichOne == CURTAIN_STUDENTWIN){ SDL_RenderCopy(renderer, image_studentsWin, NULL, &curtain_rect); }
		if (whichOne == CURTAIN_TEACHERWIN){ SDL_RenderCopy(renderer, image_teachersWin, NULL, &curtain_rect); }
		if (whichOne == CURTAIN_TGAME){ SDL_RenderCopy(renderer, image_tWonGame, NULL, &curtain_rect); }
		if (whichOne == CURTAIN_SGAME){ SDL_RenderCopy(renderer, image_sWonGame, NULL, &curtain_rect); }
	}
}

int Logic::returnCurtain()
{
	return whichCurtain;
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
					   break;
			}
				  case ' ': //spacja
				  {
						
							if(!ifcurtain && !endGAME) playerPass();
							break;

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
			if (!endOfRound && !ifcurtain && !endGAME) // if not end of round and no curtain on screen 
			{
				ifclicked(x, y);
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
								  playerChange();
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
								 playerChange();
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
						 sizeOfStudent = StudentsBase.size();
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
						  sizeOfTeacher = TeachersBase.size();
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
						 StudentScore = StudentsMeleePoints + StudentsRangedPoints + StudentsSiegePoints;
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
						  TeacherScore = TeachersMeleePoints + TeachersRangedPoints + TeachersSiegePoints;
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
	loadCurtains(); // stops the bug which makes curtains disappear after using spy card. dunno why this is happening
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

	pointsInString = to_string(TeacherScore);
	TeacherScoreSufrace = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);
	pointsInString = to_string(StudentScore);
	StudentScoreSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), fontColor);

	pointsInString = to_string(sizeOfStudent);
	sizeOfStudentSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), cardNumberColor);
	pointsInString = to_string(sizeOfTeacher);
	sizeOfTeacherSurface = TTF_RenderText_Solid(font, pointsInString.c_str(), cardNumberColor);

	StudentMeleePointTexture = SDL_CreateTextureFromSurface(renderer, StudentMeleePointSurface);
	StudentRangedPointTexture = SDL_CreateTextureFromSurface(renderer, StudentRangedPointSurface);
	StudentSiegePointTexture = SDL_CreateTextureFromSurface(renderer, StudentSiegePointSurface);

	teachersMeleePointTexture = SDL_CreateTextureFromSurface(renderer, teachersMeleePointSurface);
	teachersRangedPointTexture = SDL_CreateTextureFromSurface(renderer, teachersRangedPointSurface);
	teachersSiegePointTexture = SDL_CreateTextureFromSurface(renderer, teachersSiegePointSurface);

	TeacherScoreTexture = SDL_CreateTextureFromSurface(renderer, TeacherScoreSufrace);
	StudentScoreTexture = SDL_CreateTextureFromSurface(renderer, StudentScoreSurface);

	sizeOfStudentTexture = SDL_CreateTextureFromSurface(renderer, sizeOfStudentSurface);
	sizeOfTeacherTexture = SDL_CreateTextureFromSurface(renderer, sizeOfTeacherSurface);
}

void Logic::viewPointScore()
{
	SDL_RenderCopy(renderer, StudentMeleePointTexture, NULL, &rect_StudentMeleePoint);
	SDL_RenderCopy(renderer, StudentRangedPointTexture, NULL, &rect_StudentRangedPoint);
	SDL_RenderCopy(renderer, StudentSiegePointTexture, NULL, &rect_StudentSiegePoint);
	SDL_RenderCopy(renderer, teachersMeleePointTexture, NULL, &rect_TeachersMeleePoint);
	SDL_RenderCopy(renderer, teachersRangedPointTexture, NULL, &rect_TeachersRangedPoint);
	SDL_RenderCopy(renderer, teachersSiegePointTexture, NULL, &rect_TeachersSiegePoint);
	SDL_RenderCopy(renderer, StudentScoreTexture, NULL, &rect_StudentScore);
	SDL_RenderCopy(renderer, TeacherScoreTexture, NULL, &rect_TeacherScore);
	SDL_RenderCopy(renderer, sizeOfStudentTexture, NULL, &rect_sizeOfStudent);
	SDL_RenderCopy(renderer, sizeOfTeacherTexture, NULL, &rect_sizeOfTeacher);
}

void Logic::giveAllFieldCardsToUsed()
{
	int size;

	size = StudentsMelee.size();

	for (int i = 0; i < size; i++)
	{
		StudentsUsed.push_back(StudentsMelee[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		StudentsMelee.pop_back();
	}

	size = StudentsRanged.size();

	for (int i = 0; i < size; i++)
	{
		StudentsUsed.push_back(StudentsRanged[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		StudentsRanged.pop_back();
	}
	size = StudentsSiege.size();

	for (int i = 0; i < size; i++)
	{
		StudentsUsed.push_back(StudentsSiege[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		StudentsSiege.pop_back();
	}
	size = TeachersMelee.size();

	for (int i = 0; i < size; i++)
	{
		TeachersUsed.push_back(TeachersMelee[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		TeachersMelee.pop_back();
	}
	size = TeachersRanged.size();

	for (int i = 0; i < size; i++)
	{
		TeachersUsed.push_back(TeachersRanged[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		TeachersRanged.pop_back();
	}
	size = TeachersSiege.size();

	for (int i = 0; i < size; i++)
	{
		TeachersUsed.push_back(TeachersSiege[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		TeachersSiege.pop_back();
	}
	doneTeachersUsed = false;
	doneStudentsUsed = false;
	showAndSetCards();
	cout << TeachersUsed.size() << " TU" << endl;
	cout << StudentsUsed.size() << " SU" << endl;
}

void Logic::deleteAllBonuses()
{
	for (int i = 0; i < StudentsUsed.size(); i++)
	{
		StudentsUsed[i]->getOldPoints();
	}
	///////////////////////////////////////////////////////////TEACHER USED
	for (int i = 0; i < TeachersUsed.size(); i++)
	{
		TeachersUsed[i]->getOldPoints();
	}
	reloadPoints();
}

void Logic::deciedeWhoWinsTheRound()
{
	if (TeacherScore >= StudentScore) // passive. if they have equal amount of points then teacher wins
	{
		ifcurtain = true;
		whichCurtain = CURTAIN_TEACHERWIN;
		cout << "wygral prowadzacy" << endl;
		visible = TEACHERS_TEAM; // who wins has first move
		TWonRounds += 1;
	}
	else
	{
		ifcurtain = true;
		whichCurtain = CURTAIN_STUDENTWIN;
		drawOneCard(STUDENT_TEAM); // passive, when student wins he gets one additional card
		loadCurtains(); // repairs the bug when student win and curtain doesnt show up. dunno why
		sizeOfStudent = StudentsBase.size();
		visible = STUDENT_TEAM; // who wins has first move
		SWonRounds += 1;
	}
	round.students = StudentScore;
	round.teachers = TeacherScore;
	score.push_back(round);

	StudentsMeleePoints = 0;
	StudentsRangedPoints = 0;
	StudentsSiegePoints = 0;

	TeachersMeleePoints = 0;
	TeachersRangedPoints = 0;
	TeachersSiegePoints = 0;

	StudentScore = 0;
	TeacherScore = 0;

	loadCounter();

	endOfRound = false;
	passStudents = false;
	passTeachers = false;
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
		SDL_DestroyTexture(image_studentsWin);
		SDL_DestroyTexture(image_teachersWin);
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

		SDL_DestroyTexture(TeacherScoreTexture);
		SDL_DestroyTexture(StudentScoreTexture);

		SDL_DestroyTexture(sizeOfStudentTexture);
		SDL_DestroyTexture(sizeOfTeacherTexture);

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
}


