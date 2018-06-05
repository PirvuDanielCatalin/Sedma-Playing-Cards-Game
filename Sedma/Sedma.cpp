// Sedma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"

//enum
//{
//	Ace = 1,
//	Two,
//	Three,
//	Four,
//	Five,
//	Six,
//	Seven,
//	Eight,
//	Nine,
//	Ten,
//	Jack = 12,
//	Queen,
//	King
//};

//vector<string> values = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
//vector<string> suits = { "Spades","Diamonds","Clubs","Hearts" };


int main()
{
	Deck TwoPlayers;
	Player P1, P2;
	P1.create(TwoPlayers);
	P2.create(TwoPlayers);

	vector<Player> Players;
	Players.push_back(P1);
	Players.push_back(P2);

	Card downCard;
	int TempWinner = 0; //P1 starts
	int TempScore = 0;
	string value, suit;
	int position;

	int start = 1;
	int rounds = 0;

	while (TwoPlayers.getUsed() != TwoPlayers.getSize()) // Not all the cards were played
	{
		int StartPlayer = TempWinner;
		if (TempWinner == 0) 
		{
			cout << "!------------------------------------------------------------------!";
			cout << endl<<"\t\t\t ~ Player 1 ~";
			cout <<endl<< Players[0];

			cout <<endl<< "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: " ; cin >> suit;

			//P1 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[0].valide(value, suit); 
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[0].valide(value, suit);
			}
			
			Players[0].getHand()[position]->play_card(downCard, 0, TempWinner, TempScore);
			
			if (start) 
			{
				downCard = *Players[0].getHand()[position];
				start = 0;
			}
				
			Players[0].erase(position);
			//system("cls");
			cout << "\n\n\n";
			cout << "Down Card : " << downCard << endl;

			cout << endl << "\t\t\t ~ Player 2 ~";
			cout << endl << Players[1];

			cout << endl << "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: "; cin >> suit;

			//P2 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[1].valide(value, suit);
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[1].valide(value, suit);
			}

			Players[1].getHand()[position]->play_card(downCard, 1, TempWinner, TempScore);

			Players[1].erase(position);

			cout << "!------------------------------------------------------------------! \n\n";

		}
		else 
		{
			cout << "!------------------------------------------------------------------!";
			cout << endl << "\t\t\t ~ Player 2 ~";
			cout << endl << Players[1];

			cout << endl << "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: "; cin >> suit;

			//P2 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[1].valide(value, suit);
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[1].valide(value, suit);
			}

			Players[1].getHand()[position]->play_card(downCard, 1, TempWinner, TempScore);
			
			if (start)
			{
				downCard = *Players[1].getHand()[position];
				start = 0;
			}

			Players[1].erase(position);

			//system("cls");

			cout << "\n\n\n";
			cout << "Down Card : " << downCard << endl;

			cout << endl << "\t\t\t ~ Player 1 ~";
			cout << endl << Players[0];

			cout << endl << "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: "; cin >> suit;

			//P1 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[0].valide(value, suit);
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[0].valide(value, suit);
			}

			Players[0].getHand()[position]->play_card(downCard, 0, TempWinner, TempScore);
			cout << "!------------------------------------------------------------------! \n\n";

		}

		rounds++;

		string answer = "No";
		if (StartPlayer != TempWinner && Players[1 - TempWinner].CanContinue(downCard.get_value()))
		{
			cout << "Player " << 2 - TempWinner << "'s cards: " << Players[1 - TempWinner];
			cout << "\n\n Player " << 2 - TempWinner << ", do you continue ? < Yes / No > ";
			cin >> answer;
		}

		if (answer == "Yes")
		{
			TempWinner = 1 - TempWinner;
		}
		else
		{
			Players[TempWinner].AddScore(TempScore);

			Players[0].complete(TwoPlayers,rounds);
			Players[1].complete(TwoPlayers,rounds);

			TempScore = 0;
			downCard.set("0", "0");
			start = 1;
			rounds = 0;

		}
	}

	while (Players[0].remain() && Players[1].remain())
	{
		int StartPlayer = TempWinner;
		if (TempWinner == 0)
		{
			cout << "!------------------------------------------------------------------!";
			cout << endl << "\t\t\t ~ Player 1 ~";
			cout << endl << Players[0];

			cout << endl << "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: "; cin >> suit;

			//P1 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[0].valide(value, suit);
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[0].valide(value, suit);
			}

			Players[0].getHand()[position]->play_card(downCard, 0, TempWinner, TempScore);

			if (start)
			{
				downCard = *Players[0].getHand()[position];
				start = 0;
			}

			Players[0].erase(position);
			//system("cls");

			cout << "\n\n\n";
			cout << "Down Card : " << downCard << endl;

			cout << endl << "\t\t\t ~ Player 2 ~";
			cout << endl << Players[1];

			cout << endl << "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: "; cin >> suit;

			//P2 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[1].valide(value, suit);
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[1].valide(value, suit);
			}

			Players[1].getHand()[position]->play_card(downCard, 1, TempWinner, TempScore);

			Players[1].erase(position);
			cout << "!------------------------------------------------------------------! \n\n";

		}
		else
		{
			cout << "!------------------------------------------------------------------!";
			cout << endl << "\t\t\t ~ Player 2 ~";
			cout << endl << Players[1];

			cout << endl << "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: "; cin >> suit;

			//P2 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[1].valide(value, suit);
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[1].valide(value, suit);
			}

			Players[1].getHand()[position]->play_card(downCard, 1, TempWinner, TempScore);

			if (start)
			{
				downCard = *Players[1].getHand()[position];
				start = 0;
			}

			Players[1].erase(position);

			//system("cls");

			cout << "\n\n\n";
			cout << "Down Card : " << downCard << endl;

			cout << endl << "\t\t\t ~ Player 1 ~";
			cout << endl << Players[0];

			cout << endl << "Card: \n";
			cout << " Value: "; cin >> value;
			cout << " Suit: "; cin >> suit;

			//P1 chooses a card , it's validated ( It is a card from his hand ) and we get the position of the card in his hand
			position = Players[0].valide(value, suit);
			while (position == -1)
			{
				cout << endl << "Card: \n";
				cout << " Value: "; cin >> value;
				cout << " Suit: "; cin >> suit;
				position = Players[0].valide(value, suit);
			}

			Players[0].getHand()[position]->play_card(downCard, 0, TempWinner, TempScore);
			cout << "!------------------------------------------------------------------! \n\n";

		}

		rounds++;

		string answer = "No";
		if (StartPlayer != TempWinner && Players[1 - TempWinner].CanContinue(downCard.get_value()))
		{
			cout << "Player " << 2 - TempWinner << "'s cards: " << Players[1 - TempWinner];
			cout << "\n\n Player " << 2 - TempWinner << ", do you continue ? < Yes / No > ";
			cin >> answer;
		}

		if (answer == "Yes")
		{
			TempWinner = 1 - TempWinner;
		}
		else
		{
			Players[TempWinner].AddScore(TempScore);
			TempScore = 0;
			downCard.set("0", "0");
			start = 1;
			rounds = 0;
		}
	}



	if (Players[0].getScore() >= Players[1].getScore())
		cout << "!!! The winner is Player 1 !!!";
	else
		cout << "!!! The winner is Player 2 !!!";

	getchar();
	cout<<"Press any key to continue ...";
	getchar();
    return 0;
}

