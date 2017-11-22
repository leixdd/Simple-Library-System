#include <iostream>
#include <Windows.h>
#include <String.h>
#include <vector>
#include "graphs.h"
#include <sstream>
#include <algorithm> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//Declaring the Global Variables 


//Books in the library
vector<string> books;
vector<int> quantity;


//Books to be borrow
vector<int> access_book_id;
vector<string> book_n;
vector<string> borrower;


//By Default there were 3 books was set to the array 

string def_lib[3][2] = {
	{
		"Integral Calculus", "1"
	},
	{
		"Differential Calculus", "2"
	},
	{
		"Economics", "3"
	}
	
};

void init(){
	for(int i = 0; i < 3; i++){
		books.push_back(def_lib[i][0]); 
		quantity.push_back(atoi(def_lib[i][1].c_str()));
	}
}

bool add_books(string book, int quantityz){
	
	books.push_back(book);
	quantity.push_back(quantityz);
	return true;
}

bool remove_book(int book_id){
	books.erase(books.begin()+book_id);
	quantity.erase(quantity.begin()+book_id);
	
	return true;
}

bool borrow_book(int book_id, string name){
	int qqty = quantity.at(book_id);
	qqty -= 1;
	quantity.at(book_id) = qqty;
	book_n.push_back(books.at(book_id));
	borrower.push_back(name);
	
	return true;
}

bool return_book(string name){
	int qqty;
	for(int i = 0; i < borrower.size(); i++){
		if(borrower.at(i) == name){
			for(int j = 0; j < books.size(); j++){
				if(book_n.at(i) == books.at(j)){
					qqty = quantity.at(j);
					qqty += 1;
					quantity.at(j) = qqty;
					book_n.erase(book_n.begin()+i);
					borrower.erase(borrower.begin()+i);
					return true;
				}
			}
		}
	}
	
}

int main() {
	
	init();
	string name_bz;
	int choice, cur_y, temp_qq,qy;
	string temp_name; 
	bool rt = false;
	loox:
	system("cls");
	cur_y = 0;
	ChangeForetextColor(0,true);
	gotoxyz("Library System", cur_y += 5);
	
	
	gotoxyz("1. Add New Books", cur_y += 5);
	gotoxyz("2. Remove  Books ", cur_y += 1);
	gotoxyz("3. Borrow  Books", cur_y += 1);
	gotoxyz("4. Return  Books ", cur_y += 1);
	gotoxyz("5. View    Books", cur_y += 1);
	gotoxyz("99. To Exit", cur_y += 2);
	
	gotoxyz("Enter the number of the action: ", cur_y += 4);
	ChangeForetextColor(1,true);
	cin>>choice;
	if(cin.fail()){
		cin.clear();
		cin.ignore(1024, '\n');
		goto loox;
	}else{
		switch(choice){
			case 1:
				system("cls");
				cur_y = 0;
				
				ChangeForetextColor(1,true);
				gotoxyz("Add New Books", cur_y += 5);
				ChangeForetextColor(0,true);
				gotoxyz("To stop adding enter 99", cur_y += 2);
				gotoxyz("Example: Integral_Calculus", cur_y += 2);
				temp_name = ""; temp_qq = 0;
				while(temp_name != "99"){
					ChangeForetextColor(0,true);
					gotoxyz("Name of the book: ", cur_y += 5);
					ChangeForetextColor(1,true);
					cin>>temp_name;
					if(temp_name == "99"){
						break;
					}
					string ms = temp_name;
					ChangeForetextColor(0,true);
					gotoxyz("Quantity of the book: ", cur_y += 1);
					ChangeForetextColor(1,true);
					cin>>temp_qq;
					if(cin.fail()){
						cin.clear();
						cin.ignore(1024, '\n');
						do{
							if(cin.fail()){
								cin.clear();
								cin.ignore(1024, '\n');
							}
							ChangeForetextColor(0,true);
							gotoxyz("Quantity of the book: ", cur_y += 1);
							ChangeForetextColor(1,true);
							cin>>temp_qq;
						}while(cin.fail());
					}
					add_books(ms, temp_qq);
				}
				break;
			case 2:
				int idb;
				
				idb = 0;
				
				while(idb != 99){
					system("cls");
					cur_y = 0;
					ChangeForetextColor(2, true);
					gotoxyz("Remove Books", cur_y += 5);
					gotoxyz("To stop removing enter 99", cur_y += 2);
					gotoxyz("", cur_y += 2);
					ChangeForetextColor(0,true);

					gotoxyza("ID", 8, cur_y += 5);
					gotoxyza("Book name", 18, cur_y);
					gotoxyza("Quantity", 57, cur_y);
					gotoxyz("", cur_y += 2);
					for(int i = 0; i < books.size(); i++){
						stringstream ss1;
					    ss1 << i;
					
					    string str12;
					    ss1 >> str12;
						gotoxyza(str12, 8, cur_y += 1);
						gotoxyza(books.at(i), 18, cur_y);
					    int zi = quantity.at(i);
					    stringstream ss;
					    ss << zi;
					
					    string str1;
					    ss >> str1;
						gotoxyza(str1, 61, cur_y);	
					}
	
						ChangeForetextColor(0,true);
						gotoxyz("Enter the id of the book: ", cur_y += 5);
						ChangeForetextColor(1,true);
	
					
					cin>>idb;
					if(cin.fail()){
						cin.clear();
						cin.ignore(1024, '\n');
						do{
							if(cin.fail()){
								cin.clear();
								cin.ignore(1024, '\n');
							}
							ChangeForetextColor(0,true);
							gotoxyz("Enter the id of the book: ", cur_y += 5);
							ChangeForetextColor(1,true);
							cin>>idb;
						}while(cin.fail());
					}else if(idb == 99){
						break;
					} else if(idb > books.size() - 1){
						idb = 98;
					}else{
						remove_book(idb);
					}
														
				}
				cout<<endl <<endl;
				system("pause");
				break;
			case 3:
				int idn;
				
				idn = 0;
				
				while(idn != 99){
					system("cls");
					cur_y = 0;
					ChangeForetextColor(2, true);
					gotoxyz("Borrow a Books", cur_y += 5);
					gotoxyz("To stop removing enter 99", cur_y += 2);
					gotoxyz("", cur_y += 2);
					ChangeForetextColor(0,true);

					gotoxyza("ID", 8, cur_y += 5);
					gotoxyza("Book name", 18, cur_y);
					gotoxyza("Quantity", 57, cur_y);
					gotoxyz("", cur_y += 2);
					for(int i = 0; i < books.size(); i++){
						int zi = quantity.at(i);
						if(zi != 0){
							stringstream ss1;
						    ss1 << i;
						
						    string str12;
						    ss1 >> str12;
							gotoxyza(str12, 8, cur_y += 1);
							gotoxyza(books.at(i), 18, cur_y);
						    
						    stringstream ss;
						    ss << zi;
						
						    string str1;
						    ss >> str1;
							gotoxyza(str1, 61, cur_y);	
						}
					}
	
						ChangeForetextColor(0,true);
						gotoxyz("Enter the id of the book: ", cur_y += 5);
						ChangeForetextColor(1,true);
	
					
					cin>>idn;
					if(cin.fail()){
						cin.clear();
						cin.ignore(1024, '\n');
						do{
							if(cin.fail()){
								cin.clear();
								cin.ignore(1024, '\n');
							}
							ChangeForetextColor(0,true);
							gotoxyz("Enter the id of the book: ", cur_y += 5);
							ChangeForetextColor(1,true);
							cin>>idn;
						}while(cin.fail());
					}else if(idn == 99){
						break;
					} else if(idn > books.size() - 1){
						idb = 98;
					}else{
						char xz[9999];
						ChangeForetextColor(0,true);
						gotoxyz("Enter your name: ", cur_y += 5);
						ChangeForetextColor(1,true);
						cin >> xz;
						borrow_book(idn, xz);
					}
														
				}
				cout<<endl <<endl;
				system("pause");				
				break;
			case 4:
				system("cls");
				cur_y = 0;
				
				ChangeForetextColor(4, true);
				gotoxyz("Return a Book", cur_y += 5);
				ChangeForetextColor(0,true);
				gotoxyz("Must be identical", cur_y += 5);
				gotoxyz("to what you've entered in the past", cur_y += 1);		
				gotoxyz("Enter your name: ", cur_y += 2);
				ChangeForetextColor(1,true);
				cin >> name_bz;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1024, '\n');
					do{
						if(cin.fail()){
							cin.clear();
							cin.ignore(1024, '\n');
						}
						ChangeForetextColor(0,true);
						gotoxyz("Enter your name: ", cur_y += 2);
						ChangeForetextColor(1,true);
						cin >> name_bz;
					}while(cin.fail());
				}
				rt = return_book(name_bz);				
				if(rt){
					gotoxyz("Successfully Returned", cur_y += 2);
				}else{
					gotoxyz("Your name wasn't found'", cur_y += 2);
				}
				cout<<endl <<endl;
				system("pause");
				break;
			case 5:
				system("cls");
				cur_y = 0;
				ChangeForetextColor(5, true);
				gotoxyz("View All Books", cur_y += 5);
				ChangeForetextColor(0,true);
				gotoxyz("Book name                       Quantity", cur_y += 5);
				gotoxyz("", cur_y += 2);
				for(int i = 0; i < books.size(); i++){
					gotoxyza(books.at(i), 18, cur_y += 1);
					    int zi = quantity.at(i);
					    stringstream ss;
					    ss << zi;
					
					    string str1;
					    ss >> str1;
					gotoxyza(str1, 57, cur_y);	
				}
				cout<<endl <<endl;
				system("pause");
				break;
			case 99:
				break;
			default:
				goto loox;
				break;
				
		}			
	}
	
	if(choice != 99){
		goto loox;
	}

	
	system("pause");
	return 0;
}
