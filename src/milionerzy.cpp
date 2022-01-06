#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int Guess;
int Total;

bool game_over() {
	cout << "Twoje punkty spadly ponizej 0, to koniec gry" << endl;
	return 0;
}

// Question Class
class Question {
public:
	string Question_Text;
	string Correct;
	int Correct_Answer;
	int Question_Score;
	vector <string> Wrong;
	// Function to ask questions
	void askQuestion();
};

// Driver code
int main()
{
	string Start;
	cout << "Czy jesteś gotowy na quiz "
		<< "? tak/nie" << endl;
	cin >> Start;

	if (Start == "tak") {
		cout << endl;
		cout << "Powodzenia!" << endl;
	}
	else {
		cout << "Dowidzenia!" << endl;
		return 0;
	}



	// Objects of Question Class
	Question q1;
	q1.Question_Text = "Jakiego koloru jest zolty maluch: ";
	srand((unsigned)time(0));
	q1.Correct_Answer = (rand() % 4);
	q1.Correct = "Zoltego";
	q1.Wrong.push_back("Czerwonego");
	q1.Wrong.push_back("Zielonego");
	q1.Wrong.push_back("Niebieskiego");
	q1.Wrong.push_back("Czarnego");
	q1.Question_Score = 10;

	Question q2;
	q2.Question_Text = "Jakiej rośliny dodaje się aby uzyskać herbatę earl gray : ";
	srand((unsigned)time(0));
	q2.Correct_Answer = (rand() % 4);
	q2.Correct = "Bergamotki";
	q2.Wrong.push_back("Róży");
	q2.Wrong.push_back("Mięty");
	q2.Wrong.push_back("Niebieskiego");
	q2.Wrong.push_back("Wanilii");
	q2.Question_Score = 10;

	vector<Question>vQuestion = { q1, q2 };

	vQuestion.at(0).askQuestion();


	// pytanie, odp, odp, odp, odp, numer popr odp, wartosc
	//q2.setValues("Jakiej rośliny dodaje się aby uzyskać herbatę earl gray : ", "Bergamotki", "Róży", "Mięty", "Wanilii", 1, 10);
	//q3.setValues("Ile nóg ma stonoga : ", "Dziesięć", "Cztery", "Dziewiędziesiąt", "Sto", 1, 10);
	//q4.setValues("Jak ma na imię prezydent polski : ", "Duda", "Kamil", "Andrzej", "Jarosław", 3, 10);
	//q5.setValues("Ile lat ma doda : ", "37", "50", "29", "42", 1, 10);
	//q6.setValues("Które z tych państw nie leży w Europie : ", "Polska", "Finlandia", "Rosja", "Australia", 4, 10);
	//q7.setValues("Łacińska nazwa na kota domowego : ", "cattus domesticus", "domesticus cattus", "canis cattus", "domesticus canis", 2, 10);
	//q8.setValues("Ile godzin ma doba : ", "12", "168", "24", "26", 3, 10);
	//q9.setValues("W którym roku po raz pierwszy wyemitowano Milionerów w Polsce : ", "1999", "1994", "2001", "2004", 1, 10);
//	q10.setValues("Jak się nazywa stolica Polski : ", "Warszawa","Łódź", "Poznań", "Gdańsk", 1, 10);

	q2.askQuestion();


	// Display the total score
	cout << "Twój wynik = " << Total
		<< " na 100" << endl;

	// Display the results

	// If the player pass the quiz
	if (Total >= 70) {
		cout << "Gratulacje zdałeś quiz" << endl;
	}

	// Otherwise
	else {
		cout << "Niestety nie zdałeś."
			<< endl;
		cout << "Powodzenia następnym razem."
			<< endl;
	}
	return 0;
}

// Function to ask questions
void Question::askQuestion()
{
	cout << endl;
	int nums[4] = { 0, 1, 2, 3 };
	random_shuffle(nums, nums + 4);
	srand((unsigned)time(0));
	// Print the questions
	cout << Question_Text << endl;
	for (int index = 0; index < 4; index++) {
		if (Correct_Answer == index)
			cout << index + 1 << " " << Correct << endl;
		else
				cout << index + 1 << " " << Wrong.at(nums[index]) << endl;
	}

	cout << endl;

	// Display the answer
	cout << "Jaka jest twoja odpowiedz (cyfra)"
		<< endl;
	cin >> Guess;

	// If the answer is correct
	if (Guess == Correct_Answer+1) {
		cout << endl;
		cout << "Prawda !" << endl;

		// Update the correct score
		Total = Total + Question_Score;
		cout << "Wynik = " << Question_Score << " na " << Question_Score << "!" << endl;
		cout << endl;
	}

	// Otherwise
	else {
		cout << endl;
		cout << "Fałsz !" << endl;
		cout << "Wynik = 0 " << " na " << Question_Score << "!" << endl;
		cout << "Poprawna odpowiedź = " << Correct_Answer << "." << endl;
		cout << endl;
		Total = Total - Question_Score;
		if (Total < 0)
			game_over();
	}
}
