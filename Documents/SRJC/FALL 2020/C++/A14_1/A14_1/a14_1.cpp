//Camille Copeland - Dave Harden - CS10B - Assignment 14.1 - file: a14_1.cpp - 12/11/2020

#include <iostream>
#include <vector>
using namespace std;

const int MAX_NAMESIZE = 24;

struct Highscore {
    char name[MAX_NAMESIZE];
    int score;
};

void readData(vector<Highscore>& scores);
void sortData(vector<Highscore>& scores);
vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& scores, vector<Highscore>::iterator& startingIndex);
void displayData(const vector<Highscore>& scores);

int main()
{
    vector<int>::size_type capacity;

    cout << "How many scores are you entering? ";
    cin >> capacity;

    vector<Highscore> highScores(capacity);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);
}





void readData(vector<Highscore>& scores)
{
    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++)
    {
        cout << "Enter the name for score: ";
        cin >> i->name;

        cout << "Enter the score for score: ";
        cin >> i->score;
        cin.ignore();
    }
    cout << endl;
}





void sortData(vector<Highscore>& scores) {
    vector<Highscore>::iterator largestIndex;
    Highscore tempRecord;

    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++) {
        largestIndex = indexOfLargest(scores, i);
        tempRecord = *largestIndex;
        *largestIndex = *i;
        *i = tempRecord;
    }
}





vector<Highscore>::iterator indexOfLargest(const vector<Highscore>& scores, vector<Highscore>::iterator& startingIndex) {
    vector<Highscore>::iterator targetIndex = startingIndex;

    for (vector<Highscore>::iterator count = targetIndex + 1; count != scores.end(); count++) {
        if (count->score > targetIndex->score) {
            targetIndex = count;
        }
    }
    return targetIndex;
}





void displayData(const vector<Highscore>& scores)
{
    cout << "Top Scorers: " << endl;
    for (vector<Highscore>::const_iterator i = scores.begin(); i < scores.end(); i++)
    {
        cout << i->name << ": " << i->score << endl;
    }
}





/*
OUTPUT EXAMPLES:
-------------------------------------------
How many scores are you entering? 5
Enter the name for score: Jeff
Enter the score for score: 550
Enter the name for score: Abed
Enter the score for score: 1000
Enter the name for score: Annie
Enter the score for score: 783
Enter the name for score: Britta
Enter the score for score: 2
Enter the name for score: Pearce
Enter the score for score: 1

Top Scorers:
Abed: 1000
Annie: 783
Jeff: 550
Britta: 2
Pearce: 1
-------------------------------------------
How many scores are you entering? 4
Enter the name for score: Camille
Enter the score for score: 27
Enter the name for score: Herman
Enter the score for score: 97
Enter the name for score: Steiner
Enter the score for score: 15
Enter the name for score: Nounours
Enter the score for score: 947

Top Scorers:
Nounours: 947
Herman: 97
Camille: 27
Steiner: 15
-------------------------------------------
How many scores are you entering? 5
Enter the name for score: Uhtred
Enter the score for score: 750
Enter the name for score: Beocca
Enter the score for score: 971
Enter the name for score: Hild
Enter the score for score: 1034
Enter the name for score: Aethelred
Enter the score for score: 7
Enter the name for score: Sihtric
Enter the score for score: 1579

Top Scorers:
Sihtric: 1579
Hild: 1034
Beocca: 971
Uhtred: 750
Aethelred: 7
-------------------------------------------
How many scores are you entering? 5
Enter the name for score: Rosa
Enter the score for score: 2349
Enter the name for score: Terry
Enter the score for score: 2031
Enter the name for score: Holt
Enter the score for score: 4985
Enter the name for score: Jake
Enter the score for score: 1093
Enter the name for score: Amy
Enter the score for score: 2349

Top Scorers:
Holt: 4985
Rosa: 2349
Amy: 2349
Terry: 2031
Jake: 1093
-------------------------------------------
How many scores are you entering? 4
Enter the name for score: Noodle
Enter the score for score: 859
Enter the name for score: twod
Enter the score for score: 348
Enter the name for score: Murdoc
Enter the score for score: 4958
Enter the name for score: Russell
Enter the score for score: 4059

Top Scorers:
Murdoc: 4958
Russell: 4059
Noodle: 859
twod: 348
-------------------------------------------
*/