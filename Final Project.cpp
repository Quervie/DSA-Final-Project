#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Book{
	private://data
		list<int> bookID;
		list<int> nofCopies;
		list<string> bookTitle;
		list<string> author;
		list<string> genre;
	
	public:
		//no constructor
		void insertBook(){
			int id, copies;
			string title, auth, genr;
			
			cout << "Book ID:\t";
			cin >> id;
			bookID.push_back(id);
			cin.ignore();
			
			cout << "Book Title:\t";
			getline(cin, title);
			bookTitle.push_back(title);
			
			cout << "Author:\t";
			getline(cin, auth);
			author.push_back(auth);
			
			cout << "Genre:\t";
			getline(cin, genr);
			genre.push_back(genr);
			
			cout << "No. Of Copies:\t";
			cin >> copies;
			nofCopies.push_back(copies);
			cin.ignore();
			}
			
		void rentBook(){
			int id, copies;
			string title, auth, genr;
			
			cout << "Book ID:\t";
			cin >> id;

		}
};
int main(){

	
}