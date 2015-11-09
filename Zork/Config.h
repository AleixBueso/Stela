#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "p2List.h"
using namespace std;

struct Item
{
	char* Name;
	char* Description;
} Stick, Metalic_Plate, Lighter;

struct Room
{
	char* Name;
	char* Description;
	char* ExitsDescription;

	Room* North;
	Room* East;
	Room* West;
	Room* South;

	p2List<Item*> RoomItems;

} YourRoom, Corridor, Bathroom;

Room* Character = &YourRoom;
p2List<Item*> items;

void Config()
{
	//Your Room
	YourRoom.Name = "Your Bedroom";
	YourRoom.Description = "All you can see is a small table, a large turned off screen and two doors,\n"
		"a bed where you were sleeping and not much more. There are no windows.\n" "The room is like a kind of bedroom, a metalic\n bedroom: metalic walls, metalic floor, everithing is metalic!\n "
		"On some walls it's written Exodus Industries. It seems to be the manufacturer\n of everithing what's in here.\n" "A strange thing you noticed is that everything is very dirty, there's lots\n of dust and sand.\n";
	YourRoom.ExitsDescription = "There are two doors: The first one, on the east, it seems to lead to the bathroom of my room, very small though. The second one, on the north seems like an exit.";
	YourRoom.North = &Corridor;
	YourRoom.East = &Bathroom;
	YourRoom.RoomItems.add(&Lighter);
	YourRoom.RoomItems.add(&Metalic_Plate);

	//Corridor
	Corridor.Name = "Corridor";
	Corridor.Description = "It is a long and close corridor with lots of doors on the right side. It seems like lots of rooms lie your's. There's nobody but clearly lots of people pass there because there's rubbish on the floor and metal pieces dropped all arround.";
	Corridor.ExitsDescription = "All the rooms except for yours need to be opened with a key so you can enter none, yor only options are to go to the East, through the corridor, or go ack to the South to your Room.";
	Corridor.South = &YourRoom;

	//Bathroom
	Bathroom.Name = "Bathroom";
	Bathroom.Description = "I'ts just a messy bathroom with a shower and a toilet.\n";
	Bathroom.ExitsDescription = "You can only go back to the West";
	Bathroom.West = &YourRoom;
	Bathroom.RoomItems.add(&Stick);

	//Items
	Stick.Name = "stick";
	Stick.Description = "It's a simple wooden stick";
	Lighter.Name = "lighter";
	Lighter.Description = "A simple lighter";
	Metalic_Plate.Name = "metalic plate";
	Metalic_Plate.Description = "A dirty metal plate.";
}

bool PickUp(string pickup_item)
	{
		bool ret = false;
		p2List_item<Item*>* tmp = Character->RoomItems.getFirst();

		for (int i = 0; i < Character->RoomItems.count(); i++)
		{
			if (tmp->data->Name == pickup_item)
			{
				ret = true;
				items.add(tmp->data);
				Character->RoomItems.del(tmp);
				break;
			}

			else
			{
				tmp = tmp->next;
				ret = false;
			}
		}	
		return ret;
	}

bool Drop(string drop_item)
{
	bool ret = false;
	p2List_item<Item*>* tmp = items.getFirst();

	for (int i = 0; i < items.count(); i++)
	{
		if (tmp->data->Name == drop_item)
		{
			ret = true;
			Character->RoomItems.add(tmp->data);
			items.del(tmp);
			break;
		}

		else
		{
			tmp = tmp->next;
			ret = false;
		}
	}
	return ret;
}

#endif // !__CONFIG_H__
