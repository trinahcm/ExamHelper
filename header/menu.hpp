#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "header/schedule.hpp"
#include "header/exam.hpp"
#include "header/folder.hpp"

using namespace std;

class Menu {
    private:
        string fileName;
        Schedule* curr;
        Quiz* currQuiz;

    public:
        void mainMenu() {
            char input = ' ';
            printMainMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' || input != 'b' || input != 'c' || input != 'd' || input != 'e' ||
                   input != 'f' || input != 'g') {
                cout << "Invalid Input. Choose an option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a') {
                string folderName;
                cout << "Enter the name of your folder: ";
                getline(cin, folderName);
                cout << endl;
                addFolder(folderName);
            }
            else if (input == 'b') {
                int numID;
                cout << "Enter the ID number of the folder you want to remove: ";
                cin >> numID;
                cout << endl;
                removeFolder(numID);
            }
            else if (input == 'c') {
                int numID;
                string newName;

                cout << "Enter the ID number of the folder you want to rename: ";
                cin >> numID;
                cout << endl;

                cout << "Enter new folder name: ";
                getline(cin, newName);
                cout << endl;
                renameFolder(numID, newName);
            }
            else if (input == 'd') {
                string name;
                string date;

                cout << "Enter exam name: ";
                getline(cin, name);
                cout << endl;

                cout << "Enter exam date: ";
                getline(cin, date);
                cout << endl;
                addExam(name, date);
            }
            else if (input == 'e') {
                int numID;
                cout << "Enter the ID number of the exam you want to remove: ";
                cin >> numID;
                cout << endl;
                removeExam(numID);
            }
            else if (input == 'f') {
                string newName = "";
                string newDate = "";
                int numID;
                char choice = ' ';

                cout << "Enter the ID number of the exam you want to remove: ";
                cin >> numID;
                cout << endl;

                cout << "What would you like to change?" << endl
                     << "a - Rename Exam" << endl
                     << "b - Change Exam Date" << endl
                     << "c - Both" << endl;
                cin >> choice;
                cout << endl;
                
                while (choice != 'a' || choice != 'b' || choice != 'c') {
                    cout << "Invalid Input. Choose a valid option: ";
                    cin >> input;
                    cout << endl;
                }
                
                if (choice == 'a') {
                    cout << "Enter new Exam name: ";
                    getline(cin, newName);
                    cout << endl;
                }
                else if (choice == 'b') {
                    cout << "Enter new Exam date: ";
                    getline(cin, newDate);
                    cout << endl;
                }
                else if (choice == 'c') {
                    cout << "Enter new Exam name: ";
                    getline(cin, newName);
                    cout << endl;
                    cout << "Enter new Exam date: ";
                    getline(cin, newDate);
                    cout << endl;
                }
                editExam(newName, newDate, numID);
            }
            else if (input == 'g') {
                exit(0);
            }
        }

        void quizMenu() {
            char input = ' ';
            printQuizMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' || input != 'b' || input != 'c' || input != 'd' ||
                   input != 'e' || input != 'f') {
                cout << "Invalid Input. Choose an option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a') {
                int quizInput;
                cout << "Which practice quiz would you like to take?" << endl
                     << "1 - Multiple Choice" << endl
                     << "2 - Fill in the Blank" << endl
                     << endl
                     << "Choose an option: ";
                cin >> quizInput;
                cout << endl;

                while (quizInput != 1 || quizInput != 2) {
                    cout << "Invalid Input. Choose an option: ";
                    cin >> quizInput;
                    cout << endl << endl;
                }

                if (quizInput == 1) {
                    setQuizMultipleChoice();
                    startQuiz(FlashcardList* set);
                }
                else if (quizInput == 2) {
                    setQuizFillIn();
                    startQuiz(FlashcardList* set);
                }
            }
            else if (input == 'b') {
                displayFlashCards();
            }
            else if (input == 'c') {
                string term;
                string definition;

                cout << "Enter term: ";
                getline(cin, term);
                cout << endl;

                cout << "Enter definition: ";
                getline(cin, definition);
                cout << endl;
                addFlashCards(term, definition)
            }
            else if (input == 'd') {
                int index;

                cout << "Enter index of flashcard to be removed: ";
                cin >> index;
                cout << endl;

                removeFlashCards(index);
            }
            else if (input == 'e') {
                int index;
                string newTerm;
                string newDefinition;

                cout << "Enter the index of term you want to edit : ";
                cin >> index;
                cout << endl;

                cout << "Enter new term name: ";
                getline(cin, newTerm);
                cout << endl;

                cout << "Enter new definition: ";
                getline(cin, newDefinition);
                cout << endl;
                editFlashCards(newTerm, newDefinition, index);
            }
            else if (input == 'f') {
                exit(0);
            }
        }

        void printMainMenu() {
            cout << "EXAM HELPER MENU" << endl
                 << "-----------------------------" << endl;
            print();
            cout << "-----------------------------" << endl
                 << "a - Add Folder" << endl
                 << "b - Delete Folder" << endl
                 << "c - Rename Folder" << endl
                 << "d - Add Exam" << endl
                 << "e - Delete Exam" << endl
                 << "f - Edit Exam" << endl
                 << "g - Exit Exam Helper" << endl << endl
                 << "Choose an option: ";
        }

        void printQuizMenu() {
//          print exam name
            cout << "-----------------------------" << endl
                 << "a - Practice Quizzes" << endl
                 << "b - Display Flashcards" << endl
                 << "c - Add Flashcards" << endl
                 << "d - Delete Flashcards" << endl
                 << "e - Edit Flashcards" << endl
                 << "f - Exit Exam Helper" << endl << endl
                 << "Choose an option: ";
        }
};

#endif
