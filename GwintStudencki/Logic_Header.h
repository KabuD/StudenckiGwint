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

	bool passStudents;
	bool passTeachers;
public:
	Logic();
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
	// checks what kind of ability card has and does its thing 
	void checkAbility(Cards *e);
	// what happens when checkAbility confirms a SPY
	void CardWithSpyAbility(Cards * e);
	//what happens when checkAbility confirms ALL4ONE
	void CardWithAllForOneAbility(Cards *e);
	// tells score in the end of a round
	void viewPointScore();
	~Logic();
};

#endif