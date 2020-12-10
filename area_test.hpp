#ifndef _AREATEST_
#define _AREATEST_

#include <iostream>
#include "area.hpp"

TEST(AreaTest, AddingRoom) {
	Area* Base = new Area(0, "A1", "Start", 0);
	Base->AddNorthRoom(0, "A2", "Second", 0);
	Base->North->AddEastRoom(0, "A3", "Third", 0);

	

	Area* AreaPntr = Base;
	AreaPntr = AreaPntr->North;
	AreaPntr = AreaPntr->East;


	string ref = "A3";
	EXPECT_EQ(ref, AreaPntr->Refcode());	
} 

TEST(AreaTest, FillMap) {
	Area* Base = 0;
	Area* Pntr = 0;
	Base = Base->beginMap();
	Pntr = Base;

	string RM1;
	string RM2;
	string RM3;

	Pntr = Pntr->North;
	Pntr = Pntr->North;
	Pntr = Pntr->North;
	RM1 = Pntr->Refcode();

	Pntr = Pntr->West;
	RM2 = Pntr->Refcode();
	
	Pntr = Pntr->East;
	Pntr = Pntr->North;
	Pntr = Pntr->East;
	RM3 = Pntr->Refcode();

	EXPECT_EQ(RM1, "A3");
	EXPECT_EQ(RM2, "C1");
	EXPECT_EQ(RM3, "D1");
}
#endif
