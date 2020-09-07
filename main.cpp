#include <iostream>
#include <deque>

using namespace std;

int main() {

    int pushed = 0;
    int numberOfQuestion = 0;
    string question;
    string pushNumber;

    int lastWork = 0;
    int lastNum = 0;

    deque <int> queue;

    cin >> numberOfQuestion;

    for (int i = 0; i <= numberOfQuestion; i++) {

        getline(cin, question);

        if (question.compare(0, 4, "undo") == 0) {

            if(lastWork == 2){
                queue.pop_back();
            }

            if(lastWork == 3){
                queue.push_front(lastNum);
            }

        } else {

            if (question.compare(0, 2, "en") == 0) {

                pushNumber = question.substr(8, question.size() - 8);
                pushed = stoi(pushNumber);

                lastWork = 2;
                queue.push_back(pushed);
            }
            if (question.compare(0, 3, "pop") == 0) {

                lastWork = 3;
                lastNum = queue.front();

                cout << lastNum << endl;
                queue.pop_front();
            }
        }

    }

    return 0;
}