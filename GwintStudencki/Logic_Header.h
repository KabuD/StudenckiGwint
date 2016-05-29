#ifndef LOGIC_HEADER_H
#define LOGIC_HEADER_H
#include "Table_Header.h"
class Logic : public Table
{
private:
	bool endOfRound;
	bool ifcurtain;

	int StudentsMeleePoints;
	int StudentsRangedPoints;
	int StudentsSiegePoints;
	int TeachersMeleePoints;
	int TeachersRangedPoints;
	int TeachersSiegePoints;

	SDL_Texture * stopper;

	bool passStudents;
	bool passTeachers;
public:
	Logic();
	SDL_Texture * getTexture()
	{
		return stopper;
	}
	//checks if theres "curtain" on screen. used in main 
	bool getIfCurtain();
	//when someone pushes space
	void playerPass();
	// handles mouse, game ending and keyboard
	int getEvent(SDL_Event * e);
	// chceck if and what card was clicked
	void ifclicked(double _x, double _y);
	// puts card on it's designated place
	void setOnTable(Cards * e, int whichOne);
	// adds points to row
	void addPointsAfterSettingOnTable(Cards * e);
	// 
	void checkAbility(Cards *e);
	// tells score in the end of a round
	void pointScore();
	~Logic();
};

#endif