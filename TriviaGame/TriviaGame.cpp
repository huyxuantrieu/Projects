//triviaGame -  Huy Trieu



#include <iostream>
#include <stdio.h>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    int score = 0;
    string answer1, answer2, answer3, answer4, answer5;

    cout << "Welcome to Huy's Trivia Game!" << endl << "You will be given 5 questions. Please enter the letter that corresponds with your answer" << endl
        << "Each question is worth 20 points each. A final score of 60 is required to pass. Good luck!" << endl << endl;

    cout << "Question 1: Which is the 6th farthest planet from the sun in our solar system?" << endl << endl;

    do
    {
        do
        {
            cout << "Please enter a valid letter: "
                << endl << "a: Neptune" << endl << "b: Mars" << endl << "c: Saturn" << endl << "d: Jupiter" << endl << endl;
            getline(cin, answer1);

        } while (answer1 != "a" && answer1 != "A" && answer1 != "b" && answer1 != "B"
            && answer1 != "c" && answer1 != "C" && answer1 != "d" && answer1 != "D");

    } while (answer1.length() != 1);


    if (answer1 != "c" && answer1 != "C")
    {
        cout << "Incorrect" << endl << endl;
    }
    else
    {
        cout << "Correct" << endl << endl;
        score = score + 20;
    }


    cout << "Question 2: Which of these is not the one of the colors of the rainbow?" << endl << endl;

    do
    {
        do
        {
            cout << "Please enter a valid letter: "
                << endl << "a: Violet" << endl << "b: Yellow" << endl << "c: Blue" << endl << "d: Grey" << endl << endl;
            getline(cin, answer1);
        } while (answer1 != "a" && answer1 != "A" && answer1 != "b" && answer1 != "B"
            && answer1 != "c" && answer1 != "C" && answer1 != "d" && answer1 != "D");

    } while (answer1.length() != 1);


    if (answer1 != "d" && answer1 != "D")
    {
        cout << "Incorrect" << endl << endl;
    }
    else
    {
        cout << "Correct" << endl << endl;
        score = score + 20;
    }

    cout << "Question 3: In Greek mythology, who is the god/goddess of wisdom and military victory?" << endl << endl;

    do
    {
        do
        {
            cout << "Please enter a valid letter: "
                << endl << "a: Hermes" << endl << "b: Athena" << endl << "c: Demeter" << endl << "d: Artemis" << endl << endl;
            getline(cin, answer1);
        } while (answer1 != "a" && answer1 != "A" && answer1 != "b" && answer1 != "B"
            && answer1 != "c" && answer1 != "C" && answer1 != "d" && answer1 != "D");

    } while (answer1.length() != 1);


    if (answer1 != "b" && answer1 != "B")
    {
        cout << "Incorrect" << endl << endl;
    }
    else
    {
        cout << "Correct" << endl << endl;
        score = score + 20;
    }

    cout << "Question 4: How long can a snail sleep for?" << endl << endl;

    do
    {
        do
        {
            cout << "Please enter a valid letter: "
                << endl << "a: up to 5 years" << endl << "b: up to 1 year" << endl << "c: up to 3 years" << endl << "d: up to 7 years" << endl << endl;
            getline(cin, answer1);
        } while (answer1 != "a" && answer1 != "A" && answer1 != "b" && answer1 != "B"
            && answer1 != "c" && answer1 != "C" && answer1 != "d" && answer1 != "D");

    } while (answer1.length() != 1);


    if (answer1 != "c" && answer1 != "C")
    {
        cout << "Incorrect" << endl << endl;
    }
    else
    {
        cout << "Correct" << endl << endl;
        score = score + 20;
    }


    cout << "Question 5: Which is the largest continent by size?" << endl << endl;

    do
    {
        do
        {
            cout << "Please enter a valid letter: "
                << endl << "a: North America" << endl << "b: Asia" << endl << "c: Africa" << endl << "d: Antarctica" << endl << endl;
            getline(cin, answer1);
        } while (answer1 != "a" && answer1 != "A" && answer1 != "b" && answer1 != "B"
            && answer1 != "c" && answer1 != "C" && answer1 != "d" && answer1 != "D");

    } while (answer1.length() != 1);


    if (answer1 != "b" && answer1 != "b")
    {
        cout << "Incorrect" << endl << endl;
    }
    else
    {
        cout << "Correct" << endl << endl;
        score = score + 20;
    }

    cout << "BONUS QUESTION(10pts): Which is the largest state in the USA by size?" << endl << endl;

    do
    {
        do
        {
            cout << "Please enter a valid letter: "
                << endl << "a: California" << endl << "b: Texas" << endl << "c: Alaska" << endl << "d: Utah" << endl << endl;
            getline(cin, answer1);
        } while (answer1 != "a" && answer1 != "A" && answer1 != "b" && answer1 != "B"
            && answer1 != "c" && answer1 != "C" && answer1 != "d" && answer1 != "D");

    } while (answer1.length() != 1);


    if (answer1 != "c" && answer1 != "c")
    {
        cout << "Incorrect" << endl << endl;
    }
    else
    {
        cout << "Correct" << endl << endl;
        score = score + 10;
    }


    if (score > 60)
    {
        cout << "YOU PASSED. Your score was: " << score;
    }
    else
    {
        cout << "YOU FAILED. Your score was: " << score;
    }

    return 0;
}