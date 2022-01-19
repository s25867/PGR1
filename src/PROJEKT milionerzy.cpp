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

class Question {
public:
	int skip = 0;
	string Question_Text;
	string Correct;
	int Correct_Answer;
	int Question_Score;
	vector <string> Wrong;
	void Answer();
	void Set();
	void True();
	void False();
	void RandomQ();
};

void Question::Set() {

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
	q2.Question_Text = "Jakiej rosliny dodaje się aby uzyskac herbate earl gray : ";
	q2.Correct_Answer = (rand() % 4);
	q2.Correct = "Bergamotki";
	q2.Wrong.push_back("Rozy");
	q2.Wrong.push_back("Miety");
	q2.Wrong.push_back("Uranu");
	q2.Wrong.push_back("Wanilii");
	q2.Question_Score = 10;

	Question q3;
	q3.Question_Text = "Ile nog ma stonoga : ";
	q3.Correct_Answer = (rand() % 4);
	q3.Correct = "Dziesiec";
	q3.Wrong.push_back("Cztery");
	q3.Wrong.push_back("Dwadziescia");
	q3.Wrong.push_back("Tysiac");
	q3.Wrong.push_back("Sto");
	q3.Question_Score = 10;

	Question q4;
	q4.Question_Text = "Jak ma na imię prezydent polski : ";
	q4.Correct_Answer = (rand() % 4);
	q4.Correct = "Andrzej";
	q4.Wrong.push_back("Duda");
	q4.Wrong.push_back("Kamil");
	q4.Wrong.push_back("Jarosław");
	q4.Wrong.push_back("Jan");
	q4.Question_Score = 10;

	Question q5;
	q5.Question_Text = "Do jakiego gatunku zwierzat nalezy kura: ";
	q5.Correct_Answer = (rand() % 4);
	q5.Correct = "Ptaki";
	q5.Wrong.push_back("Ssaki");
	q5.Wrong.push_back("Plazy");
	q5.Wrong.push_back("Gady");
	q5.Wrong.push_back("Ryby");
	q5.Question_Score = 10;

	vector<Question>vQuestion = { q1, q2, q3, q4, q5 };
	int i = 0;
	int nums[5] = { 0, 1, 2, 3, 4 };
	random_shuffle(nums, nums + 5);
	do {
		vQuestion.at(nums[i]).Answer();
		i++;
		if (i == 5) {
			i = 0;
		}
		cout << "Punkty: " << Total << endl;
	} while (Total >= 0);
	game_over();
}

void Question::True() {
	cout << endl;
	cout << "Prawda !" << endl;
	Total = Total + Question_Score;
	cout << "Zdobywasz " << Question_Score << " punktów!" << endl;
	cout << endl;
}

void Question::False() {
	cout << endl;
	cout << "Fałsz !" << endl;
	cout << "Tracisz " << Question_Score << " punktów!" << endl;
	cout << "Poprawna odpowiedź = " << Correct << "." << endl;
	cout << endl;
	Total = Total - Question_Score;
}

void Question::RandomQ() {
	cout << endl;
	int nums[4] = { 0, 1, 2, 3 };
	random_shuffle(nums, nums + 4);
	cout << Question_Text << endl;
	for (int index = 0; index < 4; index++) {
		if (Correct_Answer == index)
			cout << index + 1 << " " << Correct << endl;
		else
			cout << index + 1 << " " << Wrong.at(nums[index]) << endl;
	}

	cout << endl;

	cout << "Jaka jest twoja odpowiedz (cyfra)";
	if (skip == 0) {
		cout << ". Posiadasz jedno pominiecie pytania";
	}
		cout << endl;
		std::cin >> Guess;
}

bool Welcome() {
	string Start;
	cout << "Witaj w moim quizie, zasady sa proste" << endl
		<< endl
		<< "Uzywaj liczb 1 2 3 4 aby odpowiadac na pytania" << endl
		<< "Uzyj 6 aby ominac pytanie" << endl
		<< "Za kazde pytanie dostaje albo tracisz punkty" << endl
		<<	"Czy jesteś gotowy na quiz? " << " [tak/nie]" << endl;
	std::cin >> Start;

	if (Start == "tak") {
		cout << endl;
		cout << "Powodzenia!" << endl;
	}
	else {
		cout << "Dowidzenia!" << endl;
		return 0;
	}
}

	int main() {

		if (Welcome() == 0)
			return 0;

		Question qq;
		qq.Set();

		//q6.setValues("Które z tych państw nie leży w Europie : ", "Polska", "Finlandia", "Rosja", "Australia", 4, 10);
		//q7.setValues("Łacińska nazwa na kota domowego : ", "cattus domesticus", "domesticus cattus", "canis cattus", "domesticus canis", 2, 10);
		//q8.setValues("Ile godzin ma doba : ", "12", "168", "24", "26", 3, 10);
		//q9.setValues("W którym roku po raz pierwszy wyemitowano Milionerów w Polsce : ", "1999", "1994", "2001", "2004", 1, 10);
	//	q10.setValues("Jak się nazywa stolica Polski : ", "Warszawa","Łódź", "Poznań", "Gdańsk", 1, 10);

		return 0;
	}

void Question::Answer()
{
	RandomQ();

	if (Guess == 6) {
		if (skip == 0) {
			Total = Total;
			cout << "Omijasz to pytanie" << endl;
			cout << endl;
			skip++;
		}

		else {
			cout << "Wykorzystales juz to kolo ratunkowe" << endl; 
			Total = Total;
		}
	}

	else
	if (Guess == Correct_Answer + 1) {
		True();
	}

	else {
		False();
	}
}

