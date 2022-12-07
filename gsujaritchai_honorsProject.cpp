#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

const int WIDTH = 12;

void printMenu();
void add();
void remove();
void printAllItem(); //Print all the items
void formatOutput(); //Format all output to 2 decimal places
void manageStaff(); //manage staff
void addStaff();
void removeStaff();
void printAllStaff();

vector<string> item;
vector<int> quantity;
vector<double> price;
map<string, double> staff;
//Array implementation
string menu[5] = {"Add item", "Delete item", "View all items", "Manage staff", "End program"}; 

//possible solutions: map(dictionary)

/*
class Product{
public:
  string name;
  int amount, price;
  vector<string> cart;

  void add(string x){
    cout << ""
    cart.push_back(x);
  }
  Product produce;
  produce.name = "carrot";
  produce.amount = 6;
  produce.price = 3;
  
};
*/

int main(){
  int choice, i = 0;
  formatOutput();
  cout << "Welcome to Metamart inventory management system" << endl;

  while (i != -1){
    printMenu();
    cin >> choice;
    if(choice == 1){
      //add item
      add();
    }
    else if(choice == 2){
      //remove item
      remove();
    }
    else if (choice == 3){
      //print out all available items
      printAllItem();
    }
    else if (choice == 4){
      //manage staff
      manageStaff();
    }
    else if(choice == 5){
      cout << "Thank you for using our service, good bye" << endl;
    }
    else{
      cout << "Invalid output, please re-enter your choice" << endl;
    }
    cout << "\nEnter -1 to exit, else enter any number to continue: ";
    cin >> i;
  }//end of while loop
}

void printMenu(){
  cout << "_______________________________\n\nMenu: " << endl;
  
  int arraySize = sizeof(menu)/sizeof(menu[0]);

  for(int i = 0; i < arraySize; i++){
    cout << i + 1 << ". " << menu[i] << endl;
  }
    
  cout << "\nYour choice: ";
}

void add(){
  string name;
  int num;
  double cost;
  
  cout << "\nEnter the name of the item" << "\nItem name: ";
  cin.ignore(); //so it won't skip getline()
  getline(cin, name); //in case the name is more than one word
  item.push_back(name);

  cout << "\nEnter the quantity of the item" << "\nItem amount: ";
  cin >> num;
  quantity.push_back(num);

  cout << "\nEnter the price of the item" << "\nItem price: $";
  cin >> cost;
  price.push_back(cost);

  char x;
  cout << "\nContinue? [Y/N]" << endl;
  cin >> x;
  if (x == 'Y' || x == 'y'){
    add();
  }
  else {
    printAllItem();
  }
}
void remove(){
  int object;
  //Print out all items for user to choose which item to remove (ex: 1 for 1. shampoo)
  cout << "\nAll item: \n";
  for(int i = 0; i < item.size(); i++){
    cout << i+1 << ". "<< item.at(i) << endl;
  }
  
  cout << "Enter the number of item you wish to remove" << "\nYour choice: ";
  cin >> object;
  int x = object - 1;
   
  item.erase(item.begin() + x);
  quantity.erase(quantity.begin() + x);
  price.erase(price.begin() + x);
  
  char choice;
  cout << "\nContinue? [Y/N]" << endl;
  cin >> choice;
  if (choice == 'Y' || choice == 'y'){
    remove();
  }
  else{
    cout << "\n";
    printAllItem();
  }
}
//print all item added
void printAllItem(){

  //check if vector is empty
  if (item.empty()){
    cout << "No item available" << endl;
  }
  else{
    cout << "item" << setw(17) << "quantity"
    << setw(13) << "price" << endl;
    for(int i = 0; i < item.size(); i++){
      cout << item.at(i) << setw(WIDTH) << quantity.at(i) 
      << setw(WIDTH) << "$" << price.at(i) << endl;
    }
  }
}

void formatOutput(){
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
}

void manageStaff(){
  int choice;
  
  cout << "\nChoose from the following option:\n" 
  << "\t1. Add staff\n\t2. Remove staff\n\t3. View all staff & salary"
  << "\nYour choice: ";
  cin >> choice;
  if (choice == 1)
  {
    addStaff();
  } 
  else if(choice == 2)
  {
    removeStaff();
  }
  else if(choice == 3){
    printAllStaff();
  }
  else{
    cout << "Invalid input" << endl;
    manageStaff();
  }
}

void addStaff(){
  string name, input;
  double salary;
  
  //Get staff's name and salary using dictionary (map) until user enter 'x' to end
  cout << "\nEnter staff name: ";
  cin.ignore();
  getline(cin, name);
  cout << "Enter his/her annual salary: $";
  cin >> salary;
  staff[name] = salary;
  
  char choice;
  cout << "\nContinue? [Y/N]" << endl;
  cin >> choice;
  if (choice == 'Y' || choice == 'y'){
    addStaff();
  }
  else{
    printAllStaff();
  }
    
}

//Remove staff along with salary
void removeStaff(){
  string name;

  //Print our list of staff prior to removal for user to select
  printAllStaff();
  
  cout << "Enter the name of the staff you wish to remove: ";
  cin >> name;
  staff.erase(name);

  //Print our list of staff after removal
  printAllStaff();
}

//Print out all the staff's name and their salary
void printAllStaff(){
  //check if vector is empty
  if (staff.empty()){
    cout << "No staff registered" << endl;
  }
  else{
    cout << "\nStaff name\t\tsalary" << endl;
    for (auto i = staff.begin(); i != staff.end(); ++i) {
      cout << (*i).first << setw(WIDTH) << (*i).second << endl;
    }
    /*while(staff.begin() != staff.end()){
      cout << staff.begin()->first << "\t\t$" << staff.begin()->second << '\n';
      staff.erase(staff.begin());
    }*/
    cout << "\nTotal staff: " << staff.size() << endl;
  }
}

/*
Credit:
1. https://www.tutorialspoint.com/how-to-print-out-the-contents-of-a-vector-in-cplusplus
2. https://stackoverflow.com/questions/15079057/arrays-vs-vectors-introductory-similarities-and-differences
3. https://iq.opengenus.org/ways-to-remove-elements-from-vector-cpp/
4. https://www.educative.io/answers/how-to-iterate-through-a-vector-in-cpp
5. https://stackoverflow.com/questions/15151480/simple-dictionary-in-c
6. https://cplusplus.com/reference/map/map/empty/
7. https://www.quora.com/What-are-some-alternatives-for-if-statements-in-C++
8. https://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c
9. https://stackoverflow.com/questions/21567291/why-does-stdgetline-skip-input-after-a-formatted-extraction
*/

/*
vector.size() Returns the number of elements in vector.
vector.begin() Returns an iterator pointing to the first element in vector.
vector.end() Returns an iterator pointing to the theoretical element that follows the last element in the vector.
vector.push_back(val) Push element (val) into the vector from back.
vector.empty() Returns whether vector is empty.
*/