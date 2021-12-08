#include <string>
#include <iostream>

struct Question {
	std::string Question_Text;
	std::string Answer_1;
	std::string Answer_2;
	std::string Answer_3;
	std::string Answer_4;
	int Correct_Answer;
	int Question_Score;
	void setValues(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
	void askQuestion();
	int check();
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

};
