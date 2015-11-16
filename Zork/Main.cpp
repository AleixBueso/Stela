#include <iostream>
#include <string>
#include <time.h>

#include "Config.h"

using namespace std;

int main(int argc, char* argv)
{
	Config();
	
	bool end = false;

	cout << "============================== Welcome to Stela ================================" << endl;
	cout << endl;
	cout << "Intro" << endl;
	cout << YourRoom.Name << endl;
	cout << YourRoom.Description << endl;
	cout << "What are you going to do?" << endl;

	while (end != true)
	{
		string order;
		getline(cin, order);

		if (order == "take")
		{
			if (Character->RoomItems.getFirst() != NULL)
			{
				string item_to_pick = "null";
				cout << "Which item do you want to take?" << endl;
				getline(cin, item_to_pick);
				if (PickUp(item_to_pick))
				{
					cout << "You got " << item_to_pick << endl;
				}
				else
					cout << "There's nothing called like that in here." << endl;
			}

			else
				cout << "There's nothing you can take in here" << endl;

			order = "/0";
		}

		else if (order == "drop")
		{
			string item_to_drop = "null";
			if (items.getFirst())
			{
				cout << "Which item do you want to drop?" << endl;
				getline(cin, item_to_drop);
				if (Drop(item_to_drop))
				{
					cout << "You dropped " << item_to_drop << " at " << Character->Name << endl;
				}
				else
					cout << "You don't have that item." << endl;
			}
				
			else
				cout << "You don't have any droppable items" << endl;
		}

		else if (order == "inventory")
		{
			if (items.getFirst())
			{
				cout << "Currently you have " << items.count() << " items" <<endl;
				p2List_item<Item*>* tmp = items.getFirst();

				for (unsigned int i = 0; i < items.count(); i++)
				{
					cout << "You have: " << tmp->data->Name << endl;
					tmp = tmp->next;
				}
			}
			else
				cout << "Currently you have no items" << endl;
		}
		
			else if (order == "room items")
		{
			if (Character->RoomItems.getFirst())
			{
				cout << "Currently in the room there are " << Character->RoomItems.count() << " items" << endl;

				p2List_item<Item*>* tmp = Character->RoomItems.getFirst();
				for (unsigned int i = 0; i < Character->RoomItems.count(); i++)
				{
					cout << "There is: " << tmp->data->Name << endl;
					tmp = tmp->next;
				}
			}
			else
				cout << "Currently there're no items in the room." << endl;
		}

		else if (order == "exits")
		{
			cout << Character->ExitsDescription << endl;
		}

		else if (order == "look")
		{
			cout << Character->Description << endl;
		}

		else if (order == "help")
		{
			cout << "The list of recognizable commands are: " << endl;
			cout << "pick up item" << endl;
			cout << "drop item" << endl;
			cout << "inventory" << endl;
			cout << "exits" << endl;
			cout << "description" << endl;
			cout << "go north" << endl;
			cout << "go east" << endl;
			cout << "go south" << endl;
			cout << "go west" << endl;
			cout << "quit" << endl;
		}

		else if (order == "go north" && Character->North != NULL){
			Character = Character->North;
			cout << "Heading North..." << endl;
			cout << Character->Name << endl;
		}

		else if (order == "go east" && Character->East != NULL){
			Character = Character->East;
			cout << "Heading East..." << endl;
			cout << Character->Name << endl;
		}

		else if (order == "go west" && Character->West != NULL){
			Character = Character->West;
			cout << "Heading West..." << endl;
			cout << Character->Name << endl;
		}

		else if (order == "go south" && Character->South != NULL){
			Character = Character->South;
			cout << "Heading South..." << endl;
			cout << Character->Name << endl;
		}

		else if (order == "quit"){
			cout << "Ferewell" << endl;
			end = true;
		}

		else if (order == "01000101011000"){
			cout << "Win!!" << endl;
			end = true;
		}
	
		else{
			cout << "I'm afraid you can't do that..." << endl;
		}
	}
	system("Pause");
	return 0;
}

