//Muzalfa BiBi
//SU91-BIETM-F23-008
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Parent class
class Library {
protected:
    string name;
    string address;
    string books;
    string members;
    string staff;
public:
    virtual void Data(fstream& f ) {}
    void addBook(fstream& f, string c, string title, string author, string isbn, int publicationYear, string type, int n, string heading) {
        if (f.is_open()) {
        	system("cls");
        	f<<"Isbn: "<<isbn <<endl;
        	f<<"================================"<<endl;
            f<<"=============="<<heading <<"============="<<endl;
            f<<"================================"<<endl;
            f<<"Title: "<<title<<endl;
            f<<"Author: " <<author<<endl;
            f<<"Publication Year: "<<publicationYear<<endl;
            f<<"Type: "<<type<<endl;
            f<<"Add Book Successfully with "<<isbn<<endl;
            if (n==1)
                f<<"Genre: " <<c<<endl;
            else if (n==2)
                f << "Subject: " <<c<<endl;
            else
                f<<"Edition: "<<c<<endl;
        }
    }
    void removeBook(fstream& inFile, string& isbn) {
        if (!inFile.is_open()) {
            cout<<"File could not be opened!"<<endl;
            return;
        }
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.find("Isbn: "+isbn) !=string::npos) {
                found = true;
                for (int i=0;i<9;++i) getline(inFile,line); // Skip next 9 lines
            } else {
                tempFile<<line<<endl;
            }
        }
        inFile.close();
        tempFile.close();
        remove("Books.txt");
        rename("temp.txt", "Books.txt");
        if (found)
            cout<<"Book with ISBN "<<isbn<<" remove successfully!"<<endl;
        else
            cout<<"Book with ISBN "<<isbn<<" not found."<<endl;
    }
    void borrow(fstream& inFile,string& isbn) {
         if (!inFile.is_open()) {
             cout<<"File could not be opened!"<<endl;
              return;
            }
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;
     while (getline(inFile, line)) {
          if (line.find("Isbn: " + isbn) != string::npos) {
             found = true;
                 for (int i = 0; i < 9 ; ++i){
                     getline(inFile, line);
                     cout<<line<<endl;
                    }
            } 
           else{
               tempFile<<line<<endl;
            }
	    }
         inFile.close();
         tempFile.close();
         remove("Books.txt");
         rename("temp.txt", "Books.txt");
        if (found)
             cout<<"Successfully Return Book."<<endl;
        else
              cout<<"Book with ISBN " <<isbn<<" not found."<<endl;
    }
    void addMember(fstream& fl, string c, string na, string id, string membershipType, string borrowedBooks, int n, string heading) {
        if (fl.is_open()) {
        	system("cls");
        	fl<<"ID: " <<id<<endl;
        	fl<<"==========================================="<<endl;
            fl<<"=============="<<heading<<" Member=============="<<endl;
            fl<<"==========================================="<<endl;
            if (n == 1)
            fl << "Grade: "<<c<<endl;
            else
            fl<<"Department: "<<c<<endl;
            fl<<"Name: " << na << endl;
            fl<<"Membership Type: "<<membershipType<<endl;
            fl<<"Borrowed Books: "<<borrowedBooks<<endl;
            fl<<"Add Member Successfully with "<<id<<endl;
        }
    }
    void removeMember(fstream& inFile, string& id) {
        if (!inFile.is_open()) {
             cout<<"File could not be opened!"<<endl;
             return;
        }
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;
        while (getline(inFile,line)) {
            if (line.find("ID: "+id) != string::npos) {
                found = true;
                for (int i=0;i<5;++i) getline(inFile,line); // Skip next 5 lines
            } else {
                tempFile<<line<<endl;
            }
        }
        inFile.close();
        tempFile.close();
        remove("Members.txt");
        rename("temp.txt", "Members.txt");
        if (found)
             cout<<"Member with ID "<<id<<" removed successfully."<<endl;
        else
             cout<<"Member with ID "<<id<<" not found."<<endl;
    }
    void addStaff(fstream& fle, string nam, string id, string role, float salary, string heading) {
        if (fle.is_open()) {
        	 fle<< "ID: "<<id<<endl;
        	 fle<<"==================================="<<endl;
             fle<<"=============="<<heading<<"=============="<<endl;
             fle<<"==================================="<<endl;
             fle<<"Name: "<<nam<<endl;
             fle<<"Role: "<<role<<endl;
             fle<<"Salary: "<<salary<<endl;
             fle<<"Add Staff Successfully with "<<id<<endl;
        }
    }
    void removeStaff(fstream& inFile, string& id) {
        if (!inFile.is_open()) {
             cout<<"File could not be opened!"<<endl;
             return;
        }
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.find("ID: " + id) != string::npos) {
                found = true;
                for (int i=0;i<7;++i) getline(inFile,line); // Skip next 4 lines
            } else {
                tempFile<<line<<endl;
            }
        }
        inFile.close();
        tempFile.close();
        remove("Staff.txt");
        rename("temp.txt", "Staff.txt");
        if (found)
             cout<<"Staff with ID "<<id<<" remove successfully."<<endl;
        else
             cout<<"Staff with ID "<<id<<" not found."<<endl;
    }
    void listBooks(fstream& file) {
        if (file.is_open()) {
             string line;
             while (getline(file, line)) {
                 cout<<line<<endl;
                }
        }
    }
    void listMembers(fstream& file) {
        if (file.is_open()) {
             string line;
             while (getline(file, line)) {
                 cout<<line<<endl;
                }
        }
    }
    void listStaff(fstream& file) {
        if (file.is_open()) {
             string line;
             while (getline(file, line)) {
                 cout<<line<<endl;
                }
        }
    }
};
// Child class Book of parent class Library
class Book: public Library {
protected:
    string title;
    string author;
    string isbn;
    int publicationYear;
    string type;
public:
    void borrow() {
    	cout<<"Enter Isbn: ";
        cin>>isbn;
        cout<<"Enter Title: ";
        cin>>title;
        cout<<"Enter Author Name: ";
        cin>>author;
        cout<<"Enter Publication Year: ";
        cin>>publicationYear;
        cout<<"Enter Type: ";
        cin>>type;
    }
    void rBook(fstream& f) {
        cout << "Enter ISBN to remove book: ";
        cin>>isbn;
        removeBook(f, isbn);
    }
};
class Fiction: public Book {
protected:
    string genre;
public:
    void Data(fstream& f) {
        if (f.is_open()) {
        	f << "Isbn: " << "SU91-BIETM-F23-008" << endl;
        	f<<"====================================="<<endl;
            f<<"================Fiction=============="<<endl;
            f<<"====================================="<<endl;
            f<<"Title: Computer" << endl;
            f<<"Author: Muzalfa BiBi"<<endl;
            f<<"Publication Year: 2018"<<endl;
            f<<"Type: Coding"<<endl;
            f<<"Genre: FeMale"<<endl;
            f<<endl;
        }
    }
    void gener(fstream& f) {
    	cout<<"Enter all Detail for Add a Fiction Book!"<<endl;
        cout<<"Enter Genre: ";
        cin>>genre;
        Book::borrow();
        addBook(f, genre, title, author, isbn, publicationYear, type, 1, "Fiction");
    }
};
class Nonfiction: public Book {
public:
    string subject;
	public:
    void Data(fstream& f) {
        if (f.is_open()) {
        	f<< "Isbn: SU91-BIETM-F23-006" << endl;
            f<<"====================================="<<endl;
            f<<"==============NON-Fiction============"<<endl;
            f<<"====================================="<<endl;
            f<<"Title: Math"<<endl;
            f<<"Author: Mavia "<<endl;
            f<<"Publication Year: 2019"<<endl;
            f<<"Type: knowledge"<<endl;
            f<<"Genre: FeMale"<<endl;
            f<<endl;
        }
    }
    void subjec(fstream& f) {
    	cout<<"Enter all Detail for Add a Nonfiction Book!"<<endl;
        cout<<"Enter Subject: ";
        cin>>subject;
        Book::borrow();
        addBook(f, subject, title, author, isbn, publicationYear, type, 2, "Non Fiction");
    }
};
class Reference: public Book {
protected:
    string edition;
public:
    void Data(fstream& f) {
        if (f.is_open()) {
        	f << "Isbn: SU91-BIETM-F23-005" << endl;
            f<<"====================================="<<endl;
            f<<"===============Reference============="<<endl;
            f<<"====================================="<<endl;
            f<<"Title: Islamiyat"<<endl;
            f<<"Author: Aqsa"<<endl;
            f<<"Publication Year: 2020"<<endl;
            f<<"Type: Islamic"<<endl;
            f<<"Genre: FeMale"<<endl;
            f<<endl;
        }
    }
    void editio(fstream& f) {
    	cout<<"Enter all Detail for Add a Reference Book!"<<endl;
        cout<<"Enter Edition: ";
        cin>>edition;
        Book::borrow();
        addBook(f, edition, title, author, isbn, publicationYear, type, 3, "Reference");
    }
};
class Member: public Library {
protected:
    string name;
    string id;
    string membershipType;
    string borrowedBooks;
public:
    virtual void remove(fstream& fl, string& i) {}
    void borrowBook() {
    	cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Membership Type: ";
        cin>>membershipType;
        cout<<"Enter Borrow Books (if you borrow books otherwise enter No): ";
        cin>>borrowedBooks;
    }
    void rBook(fstream& f) {
        cout<<"Enter Member ID to Remove it: ";
        cin>>id;
        removeMember(f, id);
    }
    
};
class Student: public Member {
protected:
    string grade;
public:
    void Data(fstream& fl) {
        if (fl.is_open()) {
        	fl<<"ID: SU91-BIETM-F23-008"<<endl;
        	fl<<"=================================================="<<endl;
            fl<<"===============Student Member====================="<<endl;
            fl<<"=================================================="<<endl;
            fl<<"Grade: 1st"<<endl;
            fl<<"Name: Muzalfa"<<endl;
            fl<<"Membership Type: Silver"<<endl;
            fl<<"Borrowed Books: No"<<endl;
            fl<<endl;
        }
    }
    void remove(fstream& fl, string& i) {
        removeMember(fl, i);
    }
    void gra(fstream& fl) {
        cout<<"Enter Grade: ";
        cin>>grade;
        Member::borrowBook();
        addMember(fl, grade, name, id, membershipType, borrowedBooks, 1, "Student");
    }
};
class Faculty: public Member {
protected:
    string department;
public:
    void Data(fstream& f) {
        if (f.is_open()) {
        	f << "ID: suf5-002" << endl;
        	f<<"============================================"<<endl;
            f<<"===============Faculty Member==============="<<endl;
            f<<"============================================"<<endl;
            f<<"Department: Computer"<<endl;
            f<<"Name: Ali"<<endl;
            f<<"Membership Type: Gold"<<endl;
            f<<"Borrowed Books: Yes"<<endl;
            f<<endl;
        }
    }
    void remove(fstream& f, string& i) {
        removeMember(f, i);
    }
    void dept(fstream& fl) {
        cout << "Enter Department: ";
        cin>>department;
        Member::borrowBook();
        addMember(fl, department, name, id, membershipType, borrowedBooks, 2, "Faculty");
    }
};
class Staff: public Library {
protected:
    string name;
    string id;
    string role;
    float salary;
public:
   virtual void calculateSalary() {
    	cout << "Enter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Role: ";
        cin>>role;
        cout<<"Enter Salary: ";
        cin>>salary;
        if(role=="Librarian"||role=="librarian"){
        	cout<<"======your Salary is "<<salary+1000<<"====="<<endl;
		}
		else if(role=="Assistant"||role=="assistant"){
        	cout<<"=====your Salary is "<<salary+5000<<"====="<<endl;
		}
		else
		cout<<"You Enter wrong Role!"<<endl;
    }
};
    class Librarian:public Staff{
    	public:
    void Data(fstream& fl) {
        if (fl.is_open()) {
        	fl<<"ID: 001"<<endl;
        	fl<<"======================================"<<endl;
            fl<<"=============Staff Librarian=========="<<endl;
            fl<<"======================================"<<endl;
            fl<<"Name: Ali"<<endl;
            fl<<"Role: Librarian"<<endl;
            fl<<"Salary: 50000"<<endl;
            fl<<endl;
        }
    }
    void remove(fstream& fl, string& i) {
	  Staff::removeStaff(fl, i);}
    void addStaff(fstream& fl) {
        Staff::calculateSalary();
        Staff::addStaff(fl, name, id, role, salary, "Librarian");
    }
};
class Assistant:public Staff{
	public:
    void Data(fstream& fi) {
        if (fi.is_open()) {
        	fi<< "ID: 002"<<endl;
        	fi<<"======================================"<<endl;
            fi<<"=============Staff Assistant=========="<<endl;
            fi<<"======================================"<<endl;
            fi<<"Name: Usman"<<endl;
            fi<<"Role: Assistant"<<endl;
            fi<<"Salary: 70000"<<endl;
            fi<<endl;
        }
    }
    void remove(fstream& fi, string& i) {
        Staff::removeStaff(fi, i);}
    void addStaf(fstream& fi) {
        Staff::calculateSalary();
        Staff::addStaff(fi, name, id, role, salary, "Assistant");
    }
};
class Transaction:public Library{
	protected:
	int transactionId;
	int memberId;
	double bookIsbn; 
	int borrowDate;
	int returnDate;
	double fine;
	public:
	void calculateFine(){
		cout<<"Enter Transaction Id:";
		cin>>transactionId;
		cout<<"Enter Member Id:";
		cin>>memberId;
		cout<<"Enter Book Isbn:";
		cin>>bookIsbn;
		do{
			
			cout<<"Enter borrow Date:";
		    cin>>borrowDate;
			if(borrowDate>31){
			cout<<"You Enter wrong Date!";
			}
		}while(borrowDate>31);
		do{
			cout<<"Enter Return Date:";
		    cin>>returnDate;
			if(returnDate>31){
			cout<<"You Enter wrong Date!";
			}
		}while(returnDate>31);
        if (returnDate>=borrowDate) {
            if (returnDate<=(borrowDate + 5))
                fine = 0;
            else if (returnDate <= (borrowDate + 10))
                fine = 100;
            else
                fine=2000;
        } else
            fine = 1500;		
	}
	void generateReport(fstream& fli){
		if(fli.is_open()){
        	fli<<"======================================"<<endl;
            fli<<"==================REPORT=============="<<endl;
            fli<<"======================================"<<endl;
            fli<<"Fine: "<<fine<<endl;
            fli<<"Transaction Id: "<<transactionId<<endl;
            fli<<"Member ID: " <<memberId<<endl;
            fli<<"Book Isbn:" <<bookIsbn<<endl;
            fli<<"borrow Date:"<<borrowDate<<endl;
            fli<<"Return Date:"<<returnDate<<endl;
            fli<<endl;
	}
	        cout<<"======================================"<<endl;
            cout<<"==================REPORT=============="<<endl;
            cout<<"======================================"<<endl;
            cout<<"Fine: "<<fine<<endl;
            cout<<"Transaction Id: "<<transactionId<<endl;
            cout<<"Member ID: " <<memberId<<endl;
            cout<<"Book Isbn:" <<bookIsbn<<endl;
            cout<<"borrow Date:"<<borrowDate<<endl;
            cout<<"Return Date:"<<returnDate<<endl;
            cout<<endl;
}
};
int main() {
    Book b;
    Fiction f;
    Nonfiction nf;
    Reference r;
    Member m;
    Student s;
    Faculty t;
    Staff S;
    Librarian L;
    Assistant A;
    Transaction tr;
    Library *l;
    
    // Data entry to files
    fstream bookFile("Books.txt", ios::out | ios::app);
    fstream memberFile("Members.txt", ios::out | ios::app);
    fstream staffFile("Staff.txt", ios::out | ios::app);
    fstream transactionFile("Transaction.txt", ios::out | ios::app);
    
	l= &f;
    l->Data(bookFile);
    l = &nf;
    l->Data(bookFile);
    l = &r;
    l->Data(bookFile);
    l= &s;
    l->Data(memberFile);
    l = &t;
    l->Data(memberFile);
    l=&S;
    l->Data(staffFile);
    l =&A;
    l->Data(staffFile);
    l=& L;
    l->Data(staffFile);
    l=&tr;
    l->Data(transactionFile);
    bookFile.close();
    memberFile.close();
    staffFile.close();
    transactionFile.close();
	    // Main menu
    int choice;
    do {	
        cout<<"\n\n\t\t\t====================================================";
        cout<<"\n\n\t\t\t============LIBRARY MANAGEMENT SYSTEM===============";
        cout<<"\n\n\t\t\t====================================================";
        cout<<"\n\n\t\t\t\t\t ! What Task you perform !";
        cout<<"\n\t\t\t\t\t 1. List Books"<<endl;
        cout<<"\n\t\t\t\t\t 2. List Members"<<endl;
        cout<<"\n\t\t\t\t\t 3. List Staff"<<endl;
        cout<<"\n\t\t\t\t\t 4. Add Fiction Book"<<endl;
        cout<<"\n\t\t\t\t\t 5. Add Nonfiction Book"<<endl;
        cout<<"\n\t\t\t\t\t 6. Add Reference Book"<<endl;
        cout<<"\n\t\t\t\t\t 7. Remove Book"<<endl;
        cout<<"\n\t\t\t\t\t 8. Return Book"<<endl;
        cout<<"\n\t\t\t\t\t 9. Add Student Member"<<endl;
        cout<<"\n\t\t\t\t\t 10. Add Faculty Member"<<endl;
        cout<<"\n\t\t\t\t\t 11. Remove Member"<<endl;
        cout<<"\n\t\t\t\t\t 12. Add Staff"<<endl;
        cout<<"\n\t\t\t\t\t 13. Remove Staff"<<endl;
        cout<<"\n\t\t\t\t\t 14. calculate Salary"<<endl;
        cout<<"\n\t\t\t\t\t 15. Fine and Report"<<endl;
        cout<<"\n\t\t\t\t\t 0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        fstream file;
        string id;
        switch (choice) {
            case 1:
                file.open("Books.txt", ios::in);
                l->listBooks(file);
                file.close();
                break;
            case 2:
                file.open("Members.txt", ios::in);
                l->listMembers(file);
                file.close();
                break;
            case 3:
                file.open("Staff.txt", ios::in);
                l->listStaff(file);
                file.close();
                break;
            case 4:
                file.open("Books.txt", ios::out | ios::app);
                f.gener(file);
                file.close();
                break;
            case 5:
                file.open("Books.txt", ios::out | ios::app);
                nf.subjec(file);
                file.close();
                break;
            case 6:
                file.open("Books.txt", ios::out | ios::app);
                r.editio(file);
                file.close();
                break;
            case 7:
                file.open("Books.txt", ios::in | ios::out);
                cout<<"Enter ibsan to remove: ";
                cin>>id;
                l->removeBook(file,id);
                file.close();
                break;
            case 8:
                file.open("Books.txt", ios::in | ios::out);
                cout<<"Enter isban for borrow book: ";
                cin>>id;
                l->borrow(file,id);
                file.close();
                break;
            case 9:
                file.open("Members.txt", ios::out | ios::app);
                s.gra(file);
                file.close();
                break;
            case 10:
                file.open("Members.txt", ios::out | ios::app);
                t.dept(file);
                file.close();
                break;
            case 11:
                file.open("Members.txt", ios::in | ios::out);
                cout<<"Enter member ID to remove: ";
                cin>>id;
                l->removeMember(file,id);
                file.close();
                break;
            case 12:
                file.open("Staff.txt", ios::out | ios::app);
                A.addStaf(file);
                file.close();
                break;
            case 13:
                file.open("Staff.txt", ios::in | ios::out);
                cout<<"Enter Staff ID to remove: ";
                cin>>id;
                A.remove(file, id);
                file.close();
                break;
            case 14:
            	file.open("Staff.txt", ios::in | ios::out);
                cout<<"ENter Detail to calculate Salary!"<<endl;
                 S.calculateSalary();
                file.close();
                break;
            case 15:
                file.open("Transaction.txt", ios::in | ios::out);
                cout<<"Enter Transaction Detail to see its Report: "<<endl;
                tr.calculateFine();
                tr.generateReport(file);
                file.close();
                break;
            case 0:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    } while (choice != 0);
    return 0;
}


