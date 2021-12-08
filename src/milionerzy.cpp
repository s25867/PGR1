#include <question.h>
#include <iostream>
#include <string>
using namespace std;

int Guess;
int Total;

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


	// Objects of Question 
	// pytanie, odp, odp, odp, odp, numer popr odp, wartosc
	q1.setValues("Jakiego koloru jest żółty maluch: ", "Czerwonego",
				"Zielonego", "Żółtego",
				"Niebieskiego", 3, 10);
	q2.setValues("Jakiej rośliny dodaje się aby uzyskać herbatę earl gray : ", "Bergamotki",
				"Róży", "Mięty",
				"Wanilii", 1, 10);
	q3.setValues("Ile nóg ma stonoga : ", "Dziesięć",
				"Cztery", "Dziewiędziesiąt",
				"Sto", 1, 10);
	q4.setValues("Jak ma na imię prezydent polski : ", "Duda",
				"Kamil", "Andrzej",
				"Jarosław", 3, 10);
	q5.setValues("Ile lat ma doda : ", "37",
				"50", "29",
				"42", 1, 10);
	q6.setValues("Które z tych państw nie leży w Europie : ", "Polska",
				"Finlandia", "Rosja",
				"Australia", 4, 10);
	q7.setValues("Łacińska nazwa na kota domowego : ", "cattus domesticus",
				"domesticus cattus", "canis cattus",
				"domesticus canis", 2, 10);
	q8.setValues("Ile godzin ma doba : ", "12",
				"168", "24",
				"26", 3, 10);
	q9.setValues("W którym roku po raz pierwszy wyemitowano Milionerów w Polsce : ", "1999",
				"1994", "2001",
				"2004", 1, 10);
	q10.setValues("Jak się nazywa stolica Polski : ", "Warszawa",
				"Łódź", "Poznań",
				"Gdańsk", 1, 10);

	q1.askQuestion();
	q1.check();
	q2.askQuestion();
	q3.askQuestion();
	q4.askQuestion();
	q5.askQuestion();
	q6.askQuestion();
	q7.askQuestion();
	q8.askQuestion();
	q9.askQuestion();
	q10.askQuestion();

	// Display the total score
	cout << "To koniec pytań, twój wynik = " << Total << endl;

	// If the player pass the quiz
	if (Total >= 100) {
		cout << "Gratulacje zdałeś quiz" << endl;
		return 0;
}

	// Otherwise
	else
	if (Total < 0) {
		cout << "Niestety, ale przegrałeś!" << endl;
		return 0;
}
	return 0;
}

// Function to set the values of
// the questions
void Question::setValues(
	string q, string a1,
	string a2, string a3,
	string a4, int ca, int pa)
{
	Question_Text = q;
	Answer_1 = a1;
	Answer_2 = a2;
	Answer_3 = a3;
	Answer_4 = a4;
	Correct_Answer = ca;
	Question_Score = pa;
}

//Check if won/lost during quiz
int Question::check()
{
        if (Total >= 100) {
                cout << "Gratulacje zdałeś quiz" << endl;
        	return 0;
}

        else
        if (Total < 0) {
                cout << "Twoje punkty wynoszą " << Total << ". To koniec, przegrałeś!" << endl;
        	return 0;
}
return 0;
}
// Function to ask questions
void Question::askQuestion()
{
	cout << endl;

	// Print the questions
	cout << Question_Text << endl;
	cout << "1. " << Answer_1 << endl;
	cout << "2. " << Answer_2 << endl;
	cout << "3. " << Answer_3 << endl;
	cout << "4. " << Answer_4 << endl;
	cout << endl;

	// Display the answer
	cout << "Jaka jest twoja odpowiedź (cyfrą)"
		<< endl;
	cin >> Guess;

	// If the answer is correct
	if (Guess == Correct_Answer) {
		cout << endl;
		cout << "Prawda !" << endl;

		// Update the correct score
		Total = Total + Question_Score;
		cout << "Zobyłeś " << Question_Score << " punktów!" << endl;
		cout << endl;
	}

	// Otherwise
	else {
		cout << endl;
		cout << "Fałsz !" << endl;
		cout << "Tracisz " << Question_Score << " punktów!" << endl;
		cout << "Poprawna odpowiedź = "
			<< Correct_Answer
			<< "." << endl;
		Total = Total - Question_Score;
		cout << endl;
	}
}

