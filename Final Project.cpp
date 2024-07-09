#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class Videos {
public:
	int videoID;
	string title;
	string genre;
	string production;
	int numOfCopies;
	
	Videos(int id, string t, string g, string p, int c)
		: videoID(id), title(t), genre(g), production(p), numOfCopies(c) {} //body of the constructor
};

class videosIndex {
private:
	vector<Videos> videos;
	int currentID;
	
	int videosIndexID(int id) {
		for (int i = 0; i < videos.size(); ++i) {
			if (videos[i].videoID == id)
				return i;
		}
			return -1;
	}

public:
	videosIndex() : currentID(1) {}
	
	void insertVideo(string title, string genre, string production, int numOfCopies) {
		videos.push_back(Videos(currentID++, title, genre, production, numOfCopies));
	}
	
	void videoRent(int id) {
		int index = videosIndexID(id);
		if (index != -1 && videos[index].numOfCopies > 0) {
			videos[index].numOfCopies--;
			cout <<"Video rented successfully!" << endl;
		} else {
			cout <<"Video not available!" << endl;
		}
	}
	
	void videoReturn(int id) {
		int index = videosIndexID(id);
		if (index != -1) {
			videos[index].numOfCopies++;
			cout <<"Video returned successfully!" << endl;
		} else {
			cout <<"Video not found!" << endl;
		}
	}
	
	void showVideoDetails(int id) {
		int index = videosIndexID(id);
		if (index != -1) {
			cout << "Video ID: " << videos[index].videoID << endl;
			cout << "Title: " << videos[index].title << endl;
			cout << "Genre: " << videos[index].genre << endl;
			cout << "Production: " << videos[index].production << endl;
			cout << "Copies: " << videos[index].numOfCopies << endl;
		} else {
			cout <<"Video not found!" << endl;
		}
	}
	
	void displayAllVideos() {
		for (const auto& video : videos) {
			cout << "Video ID: " << video.videoID << ", Title: " << video.title
			 	 << ", Genre: " << video.genre << ", Production: " << video.production
			 	 << ", Copies: " << video.numOfCopies << endl;
		}
	}
	
	bool isVideoIn(int id) {
		return videosIndexID(id) != -1;
	}
	
	void saveToFile(const string& filename) {
		ofstream outFile(filename);
		for (const auto& video : videos) {
			outFile << video.videoID << ","
					<< video.title << ","
					<< video.genre << ","
					<< video.production << ","
					<< video.numOfCopies << endl;
		}
		outFile.close();
	}
	
	void loadFromFile(const string& filename) {
		ifstream inFile(filename);
		string line;
		while (getline(inFile, line)) {
			size_t pos = 0;
			string token;
			vector<string> data;
			while ((pos = line.find(',')) != string::npos) {
				token = line.substr(0, pos);
				data.push_back(token);
				line.erase(0, pos + 1);
			}
			data.push_back(line);
			videos.push_back(Videos(stoi(data[0]), data[1], data[2], data[3], stoi(data[4])));
		}
		inFile.close();
	}
};

void showMenu() {
	cout << "1. Insert a new video" << endl;
	cout << "2. Rent a video" << endl;
	cout << "3. Return a video" << endl;
	cout << "4. Show the details of a particular video" << endl;
	cout << "5. Display all the videos in store" << endl;
	cout << "6. Check whether a particular video is in the store" << endl;
	cout << "7. Save data to file" << endl;
	cout << "8. Load data from file" << endl;
	cout << "9. Exit" << endl;
	cout << "Enter your choice: ";
}

void clearScreen() {
    system("cls");
}

int main() {
	videosIndex store;
	int choice, id;
	string title, genre, production, filename;
	int numOfCopies;
	
	 do {
	 	clearScreen();
        showMenu();
        cin >> choice;
        cin.ignore();
        clearScreen();
        switch (choice) {
        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter genre: ";
            getline(cin, genre);
            cout << "Enter production: ";
            getline(cin, production);
            cout << "Enter number of copies: ";
            cin >> numOfCopies;
            store.insertVideo(title, genre, production, numOfCopies);
            break;
        case 2:
            cout << "Enter video ID to rent: ";
            cin >> id;
            store.videoRent(id);
            break;
        case 3:
            cout << "Enter video ID to return: ";
            cin >> id;
            store.videoReturn(id);
            break;
        case 4:
            cout << "Enter video ID to show details: ";
            cin >> id;
            store.showVideoDetails(id);
            break;
        case 5:
            store.displayAllVideos();
            break;
        case 6:
            cout << "Enter video ID to check: ";
            cin >> id;
            if (store.isVideoIn(id)) {
                cout << "Video is in the store." << endl;
            } else {
                cout << "Video is not in the store." << endl;
            }
            break;
        case 7:
            cout << "Enter filename to save data: ";
            cin >> filename;
            store.saveToFile(filename);
            break;
        case 8:
            cout << "Enter filename to load data: ";
            cin >> filename;
            store.loadFromFile(filename);
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
     if (choice != 9) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 9);

    return 0;
}

	