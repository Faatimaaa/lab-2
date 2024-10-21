#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>  

using namespace std;


class LibraryItem {
public:
	virtual void display() const = 0; 
	virtual ~LibraryItem() = default;  
};

class Book : public LibraryItem {
private:
	char title[100];
	char author[100];
	int pages;

public:
	Book(const char* t, const char* a, int p) {
		strncpy(title, t, sizeof(title));
		strncpy(author, a, sizeof(author));
		pages = p;
	}

	void display() const override {
		cout << "Book: " << title << " by " << author << ", Pages: " << pages << endl;
	}

	int getPages() const {
		return pages;
	}

	const char* getTitle() const {
		return title;
	}
};


class Newspaper : public LibraryItem {
private:
	char name[100];
	char date[11]; 
	char edition[50];

public:
	Newspaper(const char* n, const char* d, const char* e) {
		strncpy(name, n, sizeof(name));
		strncpy(date, d, sizeof(date));
		strncpy(edition, e, sizeof(edition));
	}

	void display() const override {
		cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
	}

	const char* getName() const {
		return name;
	}

	const char* getEdition() const {
		return edition;
	}
};


class Library {
private:
	vector<Book> books;
	vector<Newspaper> newspapers;

public:
	void addBook(const Book& book) {
		books.push_back(book);
	}

	void addNewspaper(const Newspaper& newspaper) {
		newspapers.push_back(newspaper);
	}

	void displayCollection() const {
		for (const auto& book : books) {
			book.display();
		}
		for (const auto& newspaper : newspapers) {
			newspaper.display();
		}
	}

	void sortBooksByPages() {
		sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
			return a.getPages() < b.getPages();
		});
	}

	void sortNewspapersByEdition() {
		sort(newspapers.begin(), newspapers.end(), [](const Newspaper& a, const Newspaper& b) {
			return strcmp(a.getEdition(), b.getEdition()) < 0;
		});
	}

	Book* searchBookByTitle(const char* title) {
		for (auto& book : books) {
			if (strcmp(book.getTitle(), title) == 0) {
				return &book;
			}
		}
		return nullptr;
	}

	Newspaper* searchNewspaperByName(const char* name) {
		for (auto& newspaper : newspapers) {
			if (strcmp(newspaper.getName(), name) == 0) {
				return &newspaper;
			}
		}
		return nullptr;
	}
};

int main() {
	
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);

	
	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

	
	Library library;

	
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);

	
	cout << "Before Sorting:\n";
	library.displayCollection();

	
	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout << "\nAfter Sorting:\n";
	library.displayCollection();

	
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else {
		cout << "\nBook not found.\n";
	}

	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else {
		cout << "\nNewspaper not found.\n";
	}

	return 0;
}
