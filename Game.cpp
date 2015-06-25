//  The MIT License(MIT)
//
//  Copyright(c) 2015 Jamie Johnson
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files(the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions :
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.

#include "Game.h"

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Player Name Setup
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::playerSetup()
{	
	/*     -------------------These commented parts will be readded when I'm further along... 
	string tempName;
	cout << "Please enter Player 1 Name. \n";
	getline(cin, tempName);
	P1->setName(tempName);
	cout << "Please enter Player 2 Name. \n";
	getline(cin, tempName);
	P2->setName(tempName);
	*/
	//ColonyCard(int num, string name, string type, int resource, int actNum, int vicPts) 
	Card* tempCard;
	tempCard = new ColonyCard(-1, "Colony: Alioth VIII", 1, 0, 1, 1);
	P1->getColonyZone()->insertNode(tempCard);
	tempCard = new ColonyCard(-1, "Colony: Megrez VII", 1, 2, 1, 1);
	P2->getColonyZone()->insertNode(tempCard);
	//M		colony	Carbon	1	N/A	0	1	Colony: Alioth VIII
	//S		colony	Fuel	1	N / A	0	1	Colony: Megrez VII

	P1->setName("Player1");// Default names for bugtesting
	P2->setName("Player2");// Default names for bugtesting
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Checks for win condition and toggles the current player
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::gameLoop()
{
	string choice = "";  // temp until win condition is set
	while (toupper(choice[0]) != 'Q')  // mimics the checkwin loop.
	{
//		cPlyr == P1 ? cPlyr = P2 : cPlyr = P1;	// toggles between players
		cout << "CheckWin will be here.\n";
		gameTurn();
		cout << "Q to Toggle Win Condition\n";
		cin >> choice;
	}
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Calls each Phase in order
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::gameTurn()
{
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			productionPhase(i);
			break;
		case 1:
			flightPhase(i);
			break;
		case 2:
			tradeBuildToggle(i);
			break;
		}
	}
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Displays a prompt with important player info on it
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::phasePrompt(int pNum)
{
	cout << endl << "Carbon " << cPlyr->getStarship()->getResQty(Carbon) << "/" << cPlyr->getStarship()->getRCap()
		<< "  |  Fuel " << cPlyr->getStarship()->getResQty(Fuel) << "/" << cPlyr->getStarship()->getRCap()
		<< "  |  Ore " << cPlyr->getStarship()->getResQty(Ore) << "/" << cPlyr->getStarship()->getRCap()		
		<< "  |  Science " << cPlyr->getStarship()->getResQty(Science) << "/" << cPlyr->getStarship()->getRCap()
		<< "  |  TradeGood " << cPlyr->getStarship()->getResQty(TradeGood) << "/" << cPlyr->getStarship()->getRCap()
		<< "  |  Wheat " << cPlyr->getStarship()->getResQty(Wheat) << "/" << cPlyr->getStarship()->getRCap()
		<< "  |  Astro " << cPlyr->getStarship()->getAstro() << endl << endl
		<< cPlyr->getName() << "'s " << cPlyr->getPhaseName(pNum) << " Phase.\n";
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Menu Selector for the flight phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::menuSelector(int move, int& action, Card* cCard, int pNum, bool& keepFlying)
{
	bool moves = (move < cPlyr->getStarship()->getMaxDistance());
	bool actions = (action < cPlyr->getStarship()->getMaxActions());
	
	if (moves && actions)
		tfMenu(move, action, cCard, pNum, keepFlying);
	else if (!moves && actions)
		tMenu(move, action, cCard, pNum, keepFlying);
	else
		oMenu(move, action, cCard, pNum, keepFlying);
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Menu for Flight Phase -  Fly, End Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::fMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show)
{
	string option;
	do{
		cout << "\nCurrent Planet\n";
		if (show)
			cCard->printCard();
		cout << "<F> - Fly to Next Planet.\n";
		cout << "<G> - Game Menu.\n";
		cout << "<E> - End Flight Phase.\n\n";
		cout << endl;
		cout << "Movement " << move << "/" << cPlyr->getStarship()->getMaxDistance()
			<< "  |  Actions " << action << "/" << cPlyr->getStarship()->getMaxActions() << endl;
		phasePrompt(1);
		cin >> option;

		switch (toupper(option[0]))
		{
		case 'F':
			break;
		case 'G':
			gameMenu(1);
			break;
		case 'E':
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'E' && toupper(option[0]) != 'F');

	if (toupper(option[0]) == 'E')
		keepFlying = false;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//   Menu for Flight Phase -  Trade, Fly, End Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::tfMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show)
{
	string option;
	do{
		cout << "\nCurrent Planet\n";
		if (show)
			cCard->printCard();
		cout << "<T> - Trade Resources\n";
		cout << "<F> - Fly to Next Planet\n";
		cout << "<M> - Game Menu.\n";
		cout << "<E> - End Flight Phase.\n\n";
		cout << endl;
		cout << "Movement " << move << "/" << cPlyr->getStarship()->getMaxDistance()
			<< "  |  Actions " << action << "/" << cPlyr->getStarship()->getMaxActions() << endl;
		phasePrompt(1);
		cin >> option;

		switch (toupper(option[0]))
		{
		case 'T':
			if(buySellResources(1, cCard))
				action++;
			break;
		case 'M':
			gameMenu(1);
			break;
		case 'F':
			break;
		case 'E':
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'E' && toupper(option[0]) != 'F' && action < cPlyr->getStarship()->getMaxActions());

	if (toupper(option[0]) == 'E')
		keepFlying = false;	
	
	if (action == cPlyr->getStarship()->getMaxActions())
		oMenu(move, action, cCard, pNum, keepFlying);
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//   Menu for Flight Phase -  Trade, End Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::tMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show)
{
	string option;
	do{
		cout << "\nCurrent Planet\n";
		if (show)
			cCard->printCard();
		cout << "<T> - Trade Resources\n";
		cout << "<M> - Game Menu.\n";
		cout << "<E> - End Flight Phase.\n\n";
		cout << endl;
		cout << "Movement " << move << "/" << cPlyr->getStarship()->getMaxDistance()
			<< "  |  Actions " << action << "/" << cPlyr->getStarship()->getMaxActions() << endl;
		phasePrompt(1);
		cin >> option;

		switch (toupper(option[0]))
		{
		case 'T':
			if (buySellResources(1, cCard))
				action++;
			break;
		case 'M':
			gameMenu(1);
			break;
		case 'E':
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'E' && action < cPlyr->getStarship()->getMaxActions());

	if (toupper(option[0]) == 'E')
		keepFlying = false;

	if (action == cPlyr->getStarship()->getMaxActions())
		oMenu(move, action, cCard, pNum, keepFlying);
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Menu for Flight Phase -  End Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::oMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show)
{
	string option;
	do{
		cout << "\nCurrent Planet\n";
		if (show)
			cCard->printCard();
		cout << "<G> - Game Menu.\n";
		cout << "<E> - End Flight Phase.\n\n";
		cout << "Movement " << move << "/" << cPlyr->getStarship()->getMaxDistance()
			<< "  |  Actions " << action << "/" << cPlyr->getStarship()->getMaxActions() << endl;
		phasePrompt(1);
		cin >> option;
		switch (toupper(option[0]))
		{
		case 'G':
			gameMenu(pNum);
			break;
		case 'F':
			break;
		case 'E':
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'E');

	if (toupper(option[0]) == 'E')
		keepFlying = false;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Game Menu (not for Flight Phase) - Game, End Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::gMenu(int pNum)
{
	string option;
	do{
		cout << "<G> - Game Menu.\n";
		cout << "<E> - End Phase.\n";
		phasePrompt(pNum);
		cin >> option;
		switch (toupper(option[0]))
		{
		case 'G':
			gameMenu(pNum);
			break;
		case 'E':
			clearScreen();
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'E');
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Adventure Reward Menu
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::advRewards(Card* cCard, int pNum)
{
	cout << "Adventure Completed!\n";
	if (cCard->getRecRcvd())
		winMenu(cCard->getRecRcvd());
	if (cCard->getAstros())
	{
		int tAstros = cCard->getAstros();
		cout << "You receive " << tAstros << " astro.\n";
		cPlyr->getStarship()->modAstro(tAstros);
	}
	if (cCard->getFame())
	{
		int tFame = cCard->getFame();
		cout << "You receive " << tFame << " fame point(s).\n";
		//cPlyr->getStarship()->; ///////////////////////////////////////////////////////////////////////
	}
	if (cCard->getVicPts())
	{
		int tVic = cCard->getVicPts();
		cout << "You receive " << tVic << " victory point(s)\n";
		//cPlyr->getStarship()->; ///////////////////////////////////////////////////////////////////////
	}
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Adventure Planet Menu
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
bool Game::adventureMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying)
{
	bool flag = false;
	int counter = 1;
	int choice = 0;
	int numOCards = 0;
	int actions[3] = { -1, -1, -1 };
	clearScreen();
	cout << "\nCurrent Planet\n";
	cCard->printCard();
	cout << "Available Adventure Planet Actions:\n\n";
	for (int i = 0; i < 3; i++)
	{
		if (cCard->getName() == getUniverse()->getAdvCard(i)->getName())
		{
			flag = true;
			cout << counter << ".  Adventure Card " << endl << endl;
			getUniverse()->getAdvCard(i)->printCard();
			actions[i] = counter;
			numOCards++;
			counter++;
		}
	}
	if (flag)
	{
		cout << counter << ".  Do Nothing\n\n";
		phasePrompt(pNum);
		choice = getValidNum(counter, 1);
		if (choice == counter)
			flag = false;
		else
		{
			for (int i = 0; i < 3; i++)
			{
				if (choice = actions[i])
					choice = i;
			}
			string req = getUniverse()->getAdvCard(choice)->getRequirement();
			cCard = getUniverse()->getAdvCard(choice);
			if (req == "None")
			{
				advRewards(cCard, pNum);
				action++;
			}
			else
			{
				stringstream ss;
				int numReq1 = 0;
				string typeReq1;
				int numReq2 = 0;
				string typeReq2;
				string buffer;
				string more = "no";
				ss << req;
				ss >> buffer;
				numReq1 = stoi(buffer);
				ss >> typeReq1;
				ss >> more;
				if (more != "no")
				{
					ss >> buffer;
					numReq2 = stoi(buffer);
					ss >> typeReq2;
					cout << "\nChecking Multiple Conditions Here\n";
					///////////////////////////////////// need to check for both conditions //////////////////////////////////////////////////////
				}
				else
				{
					if (typeReq1 == "Cannon")
					{
						if (numReq1 >= cPlyr->getStarship()->totalLasers())
						{
							cout << "You have enough cannons to accomplish this action.\n";
							flag = true;
							action++;
						}
						else
							cout << "You do NOT have enough cannons to accomplish this action.\n";
					}
					else if (typeReq1 == "Booster")
					{
						if (numReq1 >= cPlyr->getStarship()->totalBoosters())
						{
							cout << "You have enough boosters to accomplish this action.\n";
							flag = true;
							action++;
						}
						else
							cout << "You do NOT have enough boosters to accomplish this action.\n";
					}
					else if (typeReq1 == "Astro")
					{
						if (cPlyr->getStarship()->modAstro(0 - numReq1))
						{
							cout << "You have enough astro to accomplish this action.\n";
							flag = true;
							action++;
						}
					}
					else
					{						
						int typeReqInt = 0;
						if (typeReq1 == "Science")
							typeReqInt = 3;
						else if (typeReq1 == "TradeGoods")
							typeReqInt = 4;						
						else
							typeReqInt = 5;

						if (cPlyr->getStarship()->modResource(0 - numReq1, typeReqInt))
						{
							advRewards(cCard, pNum);
							flag = true;
							action++;
						}
					}
				}
			}
		}
	}
	else
		cout << "No Actions Available\n";

	/////////////////////////////////////////// recursively call function if more than one card is available/////////////////////////////////////

	return flag;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Production Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::productionPhase(int pNum)
{
	int rtdLnCt = 0;
	int choice = 0;
	Card* rtdAry[10];
	int dieRoll = rollSpeedDie();
	clearScreen();
	cout << "\tDie Rolls a " << dieRoll << endl;
	cPlyr->getStarship()->calcMaxDistance(dieRoll);
	if (P1->getColonyZone()->findColonyResources(dieRoll, rtdAry, rtdLnCt))
	{
		cout << P1->getName() << " Has Resource(s) Available!!\n\n";
		if (rtdLnCt == 1)
		{
			if (P1->getStarship()->modResource(1, rtdAry[0]->getResource()))
				cout << P1->getStarship()->getResName(rtdAry[0]->getResource()) << " added\n\n";
			else
				cout << "Not Added\n\n";
		}	
		else
		{
			for (int i = 0; i < rtdLnCt; i++)
				cout << endl << "<" << i + 1 << "> " << rtdAry[i]->getResource() << endl;
			cout << endl;
			choice = getValidNum(rtdLnCt);
			cout << rtdAry[choice - 1]->getResource() << " added\n\n";
		}
	}
	else
		cout << P1->getName() << ": No Resource Available!!\n\n";

	if (P2->getColonyZone()->findColonyResources(dieRoll, rtdAry, rtdLnCt))
	{
		cout << P2->getName() << " Has Resource(s) Available!!\n\n";
		if (rtdLnCt == 1)
		{
			if(P2->getStarship()->modResource(1, rtdAry[0]->getResource()))
				cout << P2->getStarship()->getResName(rtdAry[0]->getResource()) << " added\n\n";
			else
			cout << "Not Added\n\n";
		}
		else
		{
			for (int i = 0; i < rtdLnCt; i++)
				cout << endl << "<" << i + 1 << "> " << rtdAry[i]->getResource() << endl;
			cout << endl;
			choice = getValidNum(rtdLnCt);
			cout << rtdAry[choice - 1]->getResource() << " added\n\n";
		}
	}
	else
		cout << P2->getName() << ": No Resource Available!!\n\n";
	gMenu(pNum);
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Flight Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::flightPhase(int pNum)
{
	int move = 0;										// Current move num
	int action = 0;									// Current action num 
	int choice = 0;									// Current choice
	int cIndex = 0;									// Current card index in stack	
	Card** cCard;
	bool keepFlying = true;								// certain events trigger this as well as the user
	string establishChoice;	
	bool show = false;									// toggle to not show planet graphic (default setting is true)

	displayFlightSectors();								// displays a graphic of the flight sectors
	cout << "\nMovement " << move << "/" << cPlyr->getStarship()->getMaxDistance()
		<< "  |  Actions " << action << "/" << cPlyr->getStarship()->getMaxActions() << endl;
	phasePrompt(pNum);
	cout << "\nChose a flight sector\n\n";				
	choice = getValidNum(4, 1);	
	cCard = universe->getSector(choice);

	while (move < cPlyr->getStarship()->getMaxDistance() && action < cPlyr->getStarship()->getMaxActions() && keepFlying) 
	{	 	
		clearScreen();
		move++;
		if (cCard[cIndex]->getType() != pirate)
		{
			switch (cCard[cIndex]->getType())
			{
			case trade:
				if (cPlyr->getStarship()->haveShip('T') && cCard[cIndex]->getPts())
				{
					if (establishPost(cCard[cIndex], cIndex, choice, move, action))
					{
						if (move < cPlyr->getStarship()->getMaxDistance() && action < cPlyr->getStarship()->getMaxActions())
							fMenu(move, action, cCard[cIndex], pNum, keepFlying);
						else
							oMenu(move, action, cCard[cIndex], pNum, keepFlying);
					}
					else
						menuSelector(move, action, cCard[cIndex], pNum, keepFlying);
				}
				else
					menuSelector(move, action, cCard[cIndex], pNum, keepFlying);
				break;
			case colony:
				if (cPlyr->getStarship()->haveShip('C') && cCard[cIndex]->getPts())
					establishPost(cCard[cIndex], cIndex, choice, move, action);

				if (move < cPlyr->getStarship()->getMaxDistance() && action < cPlyr->getStarship()->getMaxActions())
					fMenu(move, action, cCard[cIndex], pNum, keepFlying);
				else
					oMenu(move, action, cCard[cIndex], pNum, keepFlying);
				break;
			case adventure: 
				if (adventureMenu(move, action, cCard[cIndex], pNum, keepFlying))
					oMenu(move, action, cCard[cIndex], pNum, keepFlying, show);
				else 
					if (move < cPlyr->getStarship()->getMaxDistance())
						fMenu(move, action, cCard[cIndex], pNum, keepFlying, show);
					else
						oMenu(move, action, cCard[cIndex], pNum, keepFlying, show);
				break;
			case lost:
				if (move < cPlyr->getStarship()->getMaxDistance())
					fMenu(move, action, cCard[cIndex], pNum, keepFlying);
				else
					oMenu(move, action, cCard[cIndex], pNum, keepFlying);
				break;
			default:
				cout << "error.  This should NEVER show up\n";
				getline(cin, establishChoice);
			}
		}
		else
		{
			int pResult = piratePhase(move, action, cCard[cIndex]);   

			if (pResult == 1) // If Player Defeats Pirate
			{
				cout << "Pirate removed from sector!\n";
				cout << "\tAdding card from extra stack to replace pirate.\n";
				getUniverse()->addCardtoSector(choice, cIndex);			
				cout << "\tAdding a fame point.\n"; //////////////////////  Need to check for Hero of the People
				cout << "\tAdd reward for defeating pirate\n";
				winMenu();
				cout << "\nCurrent Planet\n";
				if (move < cPlyr->getStarship()->getMaxDistance())
					fMenu(move, action, cCard[cIndex], pNum, keepFlying);
				else
					oMenu(move, action, cCard[cIndex], pNum, keepFlying);
			}
			else if (pResult == 2) // If Pirate Defeats Player
			{
				if (cCard[cIndex]->getResult() == "N/A")
					cout << "You lose nothing but...\n";
				else
					cout << "You will lose a " << cCard[cIndex]->getResult() << "...\n";   ///////////////////  Add in once modules are added.
				cout << "\tFlight Phase Ended\n\n"; 
				keepFlying = false;
			}
			else // If Player Bribes Pirate
			{
				cout << "Bribe Successful.  The Pirate Lets you Pass.\n\n";

				if (move < cPlyr->getStarship()->getMaxDistance())
					fMenu(move, action, cCard[cIndex], pNum, keepFlying, show);
				else
					oMenu(move, action, cCard[cIndex], pNum, keepFlying, show);	
			}
		}
		cIndex++;
	}
//	cout << "\nSHUFFLING DECK\n\n";
//	getUniverse()->shuffleDeck(universe->getSector(choice), 10);
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Establish Trade Colony Choice
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
bool Game::establishPost(Card* cCard, int cIndex, int secNum, int move, int& action)
{
	bool flag = false;
	bool choice;
	cout << "\nCurrent Planet\n";
	cCard->printCard();
	if (cCard->getPts() > 0)
	{
		cout << "Movement " << move << "/" << cPlyr->getStarship()->getMaxDistance()
			<< "  |  Actions " << action << "/" << cPlyr->getStarship()->getMaxActions() << endl;
		phasePrompt(1);
		if (cCard->getType() == 0)
		{ 
			cout << "Would you like to establish a trading post with this planet?  ";
			choice = getYesOrNo();
			
			if (choice)
			{
				clearScreen();
				cout << "Trade Post Added to Player's Zone!\n";
				cPlyr->getTradeZone()->insertNode(cCard);
				cout	<< "\tAdding card from extra stack to replace current card\n";
				getUniverse()->addCardtoSector(secNum, cIndex);
				cout << "\tRemoving Trade Ship from Hanger\n";
				cPlyr->getStarship()->removeTradeShip();
				cout << "\tAdding a friendship point.\n\n";//////////////////////////////////////  Need to check for Friend of the People
				action++;
				flag = true;
			}
		}
		else
		{
			cout << "Would you like to establish a colony with this planet?  ";
			choice = getYesOrNo();
			if (choice)
			{
				cout << "Colony Added to Player's Zone!\n";
				cPlyr->getColonyZone()->insertNode(cCard);
				cout << "\tAdding card from extra stack to replace current card\n\n";
				getUniverse()->addCardtoSector(secNum, cIndex);
				cout << "\tRemoving Colony Ship from Hanger\n";
				cPlyr->getStarship()->removeColonyShip();
				cout << "\tAdding a victory point.\n\n"; ////////////////////////////////////////////////////////// Add Victory Pt
				action++;
				flag = true;
			}
		}
	}
	return flag;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Pirate Menu
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
int Game::piratePhase(int move, int action, Card* cCard)
{
	int flag = 0;
	string option;

	clearScreen();
	cout << "A Pirate is waiting for you!!!\n\n"
		<< "\tThey will let you pass for "
		<< cCard->getCost() << " Astros!!!\n\n";
	do{
		cout << "<B> - Bribe the Pirate.\n";
		cout << "<F> - Fight the Pirate.\n";
		cout << "<S> - Print Starship.\n\n";
		phasePrompt(1);
		cin >> option;

		switch (toupper(option[0]))
		{
		case 'S':
			cPlyr->getStarship()->printShip();
			break;
		case 'B':
			clearScreen();
			cout << "You chose to BRIBE the pirate!!\n\n";
			if (cPlyr->getStarship()->modAstro(0 - cCard->getCost()))  
				flag = 3;
			break;
		case 'F':
			clearScreen();
			cout << "You chose to FIGHT the pirate!\n\n";
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'F' && flag != 3);

	if (toupper(option[0]) == 'F')
		pirateFight(cCard) ? flag = 1 : flag = 2;		

	return flag;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Pirate Fight
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
bool Game::pirateFight(Card* cCard)
{
	bool flag = true;
	int tempDie = rollCombatDie();
	int pTotal = cCard->getCannons() + tempDie;

	cout << "Pirate has " << cCard->getCannons() << " cannons...\n\n";
	cout << "\t...and rolls a " << tempDie << " for a total of ";
	cout << pTotal << "!!!\n\n";

	tempDie = rollCombatDie();
	int plTotal = cPlyr->getStarship()->totalLasers() + tempDie;

	cout << "You have " << cPlyr->getStarship()->totalLasers() << " cannons...\n\n";
	cout << "\t...and roll a " << tempDie << " for a total of ";
	cout << plTotal << "!!!\n\n";

	if (pTotal <= plTotal)
	{
		cout << "You win!!!\n";
	}
	else
	{
		cout << "You lose!!!\n";
		flag = false;
	}
	return flag;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Resource Menu 
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::winMenu(int numRec)
{
	bool flag;
	int choice;
	for (int i = 0; i < numRec; i++)
	{
		flag = false;
		do{
			cout << "Please select " << i + 1 << " of " << numRec << " resource(s) as reward.\n";
			cout << "<1> - Carbon\n";
			cout << "<2> - Fuel\n";
			cout << "<3> - Ore\n";
			cout << "<4> - Science\n";
			cout << "<5> - TradeGoods.\n";
			cout << "<6> - Wheat.\n";
			cout << "<7> - None.\n\n";
			phasePrompt(1);
			choice = getValidNum(7, 1);
			if (cPlyr->getStarship()->modResource(1, choice - 1))
				flag = true;

		} while (!flag && choice != 7);
	}
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Trading and Building Toggle
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::tradeBuildToggle(int pNum)
{
	int choice = 0;
	clearScreen();
	cout << "This is the Trading and Building Phase\n\n";
	cout << "Which phase would you like to enter first?\n\n"
		<< "<1> - Trade Phase\n"
		<< "<2> - Build Phase\n";
	phasePrompt(4);
	choice = getValidNum(2, 1);
	
	if (choice == 1)
	{
		tradePhase(2);
		buildPhase(3);
	}
	else
	{
		buildPhase(3);		
		tradePhase(2);
	}
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Trading Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::tradePhase(int pNum)
{
	clearScreen();
	int trade = 0;
	string option;
	Card* rtdAry[10];
	int rtdLnCt = 0;
	int choice = 0;
	cout << "\tTrade Phase\n\n";
	do{
		cout << "<T> - Trade Resources.\n";
		cout << "<G> - Game Menu.\n";
		cout << "<E> - End Trade Phase.\n";
		phasePrompt(pNum);
		cin >> option;
		switch (toupper(option[0]))
		{
		case 'G':
			gameMenu(pNum);
			break;
		case 'T':
			if (cPlyr->getTradeZone()->getTradeResources(rtdAry, rtdLnCt))
			{
				clearScreen();
				cout << "Which Resource would you like to trade?\n\n";
				for (int i = 0; i < rtdLnCt; i++)
					cout << "<" << i + 1 << "> " << rtdAry[i]->getResName(rtdAry[i]->getResource()) << endl;
				cout << "<" << rtdLnCt + 1 << "> No Trade" << endl << endl;
				phasePrompt(pNum);
				choice = getValidNum(rtdLnCt + 1);
				if (choice != rtdLnCt + 1)
				{
					if (buySellResources(pNum, rtdAry[choice - 1]))
						trade++;
				}
			}
			else
				cout << P1->getName() << ": No Trade Planets Available!!\n\n";
			break;
		case 'E':
			clearScreen();
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'E' && trade < 2);

}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  buySellResources
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
bool Game::buySellResources(int pNum, Card* cCard)
{
	bool flag = false;
	int limit = cCard->getLimit();
	int num = 0;
	int cost = cCard->getCost();
	string choice;
	cin.ignore();
	cin.clear();
	//  Buy or Sell
	clearScreen();
	cCard->printCard();
	cout << "This planet offers " << cCard->getResName(cCard->getResource()) << " for " << cCard->getCost() << " astro.\n\n";
	if (cCard->getTransaction() == "Both")	// If the card allows either Selling or Buying
	{
		do
		{
			cout << "Would you like to Buy or Sell?\n\n";
			cout << "<B> - Buy\n";
			cout << "<S> - Sell\n";
			phasePrompt(pNum);
			getline(cin, choice);
		} while (toupper(choice[0]) != 'B' && toupper(choice[0]) != 'S');

		if (toupper(choice[0]) == 'B')
			cost = cCard->getCost();			
		else
			num = 0 - num;
	}
	else if (cCard->getTransaction() == "Buy")	// If Card Only allows Buying
	{
		cout << "For Buying Only\n";
		choice = "B";
		cost = cCard->getCost();
	}
	else  // If Card only allows Selling
	{
		cout << "For Selling Only\n";
		choice = "S";
		num = 0 - num;
	}

	// How many
	if (limit == 0)
		limit = cPlyr->getStarship()->getRCap(); //////
	clearScreen();
	cCard->printCard();
	cout << "How much " << cCard->getResName(cCard->getResource()) << " would you like to trade\n";
	phasePrompt(pNum);
	num = getValidNum(limit, 0);

	if (toupper(choice[0]) == 'S')
		num = 0 - num;

//	clearScreen();
	if (num != 0)
		if (cPlyr->getStarship()->modResource(num, cCard->getResource(), cost))
			flag = true;

	return flag;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Building Phase
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::buildPhase(int pNum)
{
	string option;
	cout << "\tBuild Phase\n\n";
	do{
		cout << "<B> - Build.\n";
		cout << "<G> - Game Menu.\n";
		cout << "<E> - End Build Phase.\n";
		phasePrompt(pNum);
		cin >> option;
		switch (toupper(option[0]))
		{
		case 'B':
			cout << "Build Menu Here\n";
			break;
		case 'G':
			gameMenu(pNum);
			break;
		case 'E':
			clearScreen();
			break;
		default:
			cout << "Command Not Understood.\n";
		}
	} while (toupper(option[0]) != 'E');
	cout << "End of Build Phase.\n\n";
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Initialize Speed Die
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::initSDie()
{
	speedDie[0] = 1;
	speedDie[1] = 1;
	speedDie[2] = 2;
	speedDie[3] = 2;
	speedDie[4] = 3;
	speedDie[5] = 3;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Initialize Combat Die
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::initCDie()
{
	combatDie[0] = 1;
	combatDie[1] = 2;
	combatDie[2] = 2;
	combatDie[3] = 3;
	combatDie[4] = 3;
	combatDie[5] = 4;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Validates a number between a range
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
int Game::getValidNum(int high, int low)
{
	int n;
	bool success;

	do
	{
		cout << "Please enter a number (" << low << " to " << high << "): ";
		cin >> n ? success = true : success = false;
		cin.clear();          // to clear the error flag
		cin.ignore(80, '\n'); // to discard the unwanted input from the input buffer
	} while (!success || n < low || n > high);

	return n;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Validates yes or no response
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
bool Game::getYesOrNo()
{
	char n;
	bool success = true;
	do
	{
		cout << "Y / N\n";
		cin >> n ? success = true : success = false;
		cin.clear();          // to clear the error flag
		cin.ignore(80, '\n'); // to discard the unwanted input from the input buffer
	} while (!success || toupper(n) != 'Y' && toupper(n) != 'N');

	if (toupper(n) == 'N')
		success = false;

	return success;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Clears the screen
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::clearScreen()
{
	for (int n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Display Flight Sectors
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::displayFlightSectors()
{
	cout << "   ___________________________            ___________________________            ___________________________            ___________________________\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |            _            |            |        _  _  _          |            |       _  _  _  _        |            |              _          |\n";
	cout << "   |         _ (_)           |            |      _(_)(_)(_)_        |            |     _(_)(_)(_)(_)_      |            |           _ (_)         |\n";
	cout << "   |        (_)(_)           |            |     (_)       (_)       |            |    (_)          (_)     |            |        _ (_)(_)         |\n";
	cout << "   |           (_)           |            |              _(_)       |            |             _  _(_)     |            |     _ (_)   (_)         |\n";
	cout << "   |           (_)           |            |            _(_)         |            |            (_)(_)_      |            |    (_) _  _ (_) _       |\n";
	cout << "   |           (_)           |            |         _ (_)           |            |     _           (_)     |            |    (_)(_)(_)(_)(_)      |\n";
	cout << "   |         _ (_) _         |            |      _ (_) _  _  _      |            |    (_)_  _  _  _(_)     |            |             (_)         |\n";
	cout << "   |        (_)(_)(_)        |            |     (_)(_)(_)(_)(_)     |            |      (_)(_)(_)(_)       |            |             (_)         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |                         |            |                         |            |                         |            |                         |\n";
	cout << "   |_________________________|            |_________________________|            |_________________________|            |_________________________|\n";
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Game Menu
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Game::gameMenu(int pNum)
{
	clearScreen();
	cout << "<A> - Adventure Planet List.\n";	
	cout << "<C> - Colony Planet List.\n";	
	cout << "<S> - Print Starship.\n";
	cout << "<T> - Trade Planet List.\n";
	string option;

	phasePrompt(pNum);
	cin >> option;
	clearScreen();
	switch (toupper(option[0]))
	{
	case 'A':
		getUniverse()->printCurrentAdventure();
		break;
	case 'C':
		cPlyr->getColonyZone()->displayListForward();
		break;
	case 'T':
		cPlyr->getTradeZone()->displayListForward();
		break;
	case 'S':
		cPlyr->getStarship()->printShip();
		break;
	default:
		cout << "Command Not Understood.\n";
	}

}