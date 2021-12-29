#include <iostream>
#include <string>
using namespace std;

int Guess;
int Total;

// Question Class
class Question {
private:
	string Question_Text;
	string Answer_1;
	string Answer_2;
	string Answer_3;
	string Answer_4;
	int Correct_Answer;
	int Question_Score;

public:
	// Setter Function
	void setValues(string, string,
				string, string,
				string, int, int);

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
	Question q2;
	Question q3;
	Question q4;
	Question q5;
	Question q6;
	Question q7;
	Question q8;
	Question q9;
	Question q10;

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
		cout << "Wynik = " << Question_Score
			<< " na "
			<< Question_Score
			<< "!" << endl;
		cout << endl;
	}

	// Otherwise
	else {
		cout << endl;
		Total = Total - Question_Score;
		cout << "Fałsz !" << endl;
		cout << "Wynik = 0 "
			<< " na "
			<< Question_Score
			<< "!" << endl;
		cout << "Poprawna odpowiedź = "
			<< Correct_Answer
			<< "." << endl;
		cout << endl;
	}
}
