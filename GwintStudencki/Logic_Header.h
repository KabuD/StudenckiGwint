#ifndef LOGIC_HEADER_H
#define LOGIC_HEADER_H
#include "Table_Header.h"
struct RoundScore
{
	int teachers;
	int students;
};

class Logic : public Table
{
private:

	vector<RoundScore>score;
	RoundScore round;
	bool endOfRound;
	bool endGAME;

	int StudentsMeleePoints;
	int StudentsRangedPoints;
	int StudentsSiegePoints;

	int TeachersMeleePoints;
	int TeachersRangedPoints;
	int TeachersSiegePoints;
	
	int StudentScore;
	int TeacherScore;

	int sizeOfStudent;
	int sizeOfTeacher;

	bool passStudents;
	bool passTeachers;
	int passCount;

	int SWonRounds;
	int TWonRounds;

	bool ifcurtain;
	int whichCurtain;

	TTF_Font * font;
	SDL_Color fontColor;
	SDL_Color cardNumberColor;

	SDL_Surface* StudentMeleePointSurface;
	SDL_Surface* StudentRangedPointSurface;
	SDL_Surface* StudentSiegePointSurface;

	SDL_Surface* teachersMeleePointSurface;
	SDL_Surface* teachersRangedPointSurface;
	SDL_Surface* teachersSiegePointSurface;

	SDL_Surface* StudentScoreSurface;
	SDL_Surface* TeacherScoreSufrace;

	SDL_Surface* sizeOfStudentSurface;
	SDL_Surface* sizeOfTeacherSurface;

	SDL_Texture*  StudentMeleePointTexture;
	SDL_Texture*  StudentRangedPointTexture;
	SDL_Texture*  StudentSiegePointTexture;

	SDL_Texture*  teachersMeleePointTexture;
	SDL_Texture*  teachersRangedPointTexture;
	SDL_Texture*  teachersSiegePointTexture;

	SDL_Texture* StudentScoreTexture;
	SDL_Texture* TeacherScoreTexture;

	SDL_Texture* sizeOfStudentTexture;
	SDL_Texture* sizeOfTeacherTexture;


	SDL_Rect rect_StudentMeleePoint;
	SDL_Rect rect_StudentRangedPoint;
	SDL_Rect rect_StudentSiegePoint;
	SDL_Rect rect_TeachersMeleePoint;
	SDL_Rect rect_TeachersRangedPoint;
	SDL_Rect rect_TeachersSiegePoint;

	SDL_Rect rect_TeacherScore;
	SDL_Rect rect_StudentScore;

	SDL_Rect rect_sizeOfStudent;
	SDL_Rect rect_sizeOfTeacher;

public:
	Logic();
	//when someone pushes space
	void playerPass();
	//when someone clicks on card
	void playerChange();
	//if passCount =2 then it does the endround thing 
	void checkIfEndRound();
	//if score.size() is at least 2 it checks if someone won and if it should end the game
	void checkIfEndGame();
	// handles mouse, game ending and keyboard
	int getEvent(SDL_Event * e);
	//returns which curtain should be displayed
	int returnCurtain();
    //loads images needed for curtains
	void loadCurtains();
	//func for showin curtain in main loop
	void showCurtain(int whichOne);
	// chceck if and what card was clicked
	void ifclicked(double _x, double _y);
	// puts card on it's designated place
	void setOnTable(Cards * e, int whichOne);
	// adds points to row
	void addPointsAfterSettingOnTable(Cards * e);
	// checks what kind of ability card has and does its thing 
	void checkAbility(Cards *e);
	// what happens when checkAbility confirms a SPY
	void CardWithSpyAbility(Cards * e);
	//what happens when checkAbility confirms ALL4ONE
	void CardWithAllForOneAbility(Cards *e);
	//loads all surfaces and textures for counters
	void loadCounter();
	// tells score in the end of a round
	void viewPointScore();
	// gets all elements in the field to Used vectors
	void giveAllFieldCardsToUsed();
	// deletes bonuses from one for all buff
	void deleteAllBonuses();
	// activates when studenpass & teacherpass
	void deciedeWhoWinsTheRound();
	//checks if theres end of round 
	~Logic();
};

#endif