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




#endif
