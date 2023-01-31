#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ArgumentManager.h"
#include <vector>
#include <regex>
#include "list.h"

using namespace std;

// fixing string input
void cleanInput(string &s){
  s.erase(remove(s.begin(), s.end(), ';'), s.end());
  s.erase(remove(s.begin(), s.end(), '\n'), s.end());
  s.erase(remove(s.begin(), s.end(), '\r'), s.end());
  s.erase(remove(s.begin(), s.end(), '['), s.end());
  s.erase(remove(s.begin(), s.end(), ']'), s.end());
}
void fixC(string &s){
  s.erase(remove(s.begin(), s.end(), '\n'), s.end());
  s.erase(remove(s.begin(), s.end(), '\r'), s.end());
}

void doCommand(string c, list &l){
  if (c.find("Remove") != string::npos){
    if (c.find("name")!= string::npos){
      c.erase(remove(c.begin(), c.end(), '('), c.end());
      c.erase(remove(c.begin(), c.end(), ')'), c.end());
      string attribute = c.substr(c.find("name") + 6, c.length());
      l.rName(attribute);
    }
    else if (c.find("age")!= string::npos){
      c.erase(remove(c.begin(), c.end(), '('), c.end());
      c.erase(remove(c.begin(), c.end(), ')'), c.end());
      string attribute = c.substr(c.length() - 3, c.length());
      int a = stoi(attribute);
      l.rAge(a);
    }
    else if (c.find("deposit")!= string::npos){
      c.erase(remove(c.begin(), c.end(), '('), c.end());
      c.erase(remove(c.begin(), c.end(), ')'), c.end());
      string attribute = c.substr(c.length() - 4, c.length());
      //cout << attribute << endl;
      int dep = stoi(attribute);
      //cout << dep << endl;
      l.rDeposit(dep);
    }
    else if (c.find("drinks")!= string::npos){
      c.erase(remove(c.begin(), c.end(), '('), c.end());
      c.erase(remove(c.begin(), c.end(), ')'), c.end());
      string attribute = c.substr(c.length() - 1, c.length());
      int d = stoi(attribute);
      l.rDrinks(d);
    }
  }
  else if (c.find("Sort") != string::npos){
    if (c.find("name") != string::npos){
      l.sort("name");
    }
    else if (c.find("age") != string::npos){
      l.sort("age");
    }
    else if (c.find("deposit") != string::npos){
      l.sort("deposit");
    }
    else if (c.find("drinks") != string::npos){
      l.sort("drinks");
    }
  }
  else if (c.find("Add") != string::npos){
      string num = c.substr(c.find('(') + 1, c.find(')') - 5);
    
      int index = stoi(num);
      string in = c.substr(c.find('['), c.length());
      cleanInput(in);
      string name;
      string age_s;
      int age;
      string deposit_s;
      int deposit;
      string drinks_s;
      int drinks;
      string temp;

      name = in.substr(6, in.length() - 47);
      temp = in.substr(in.length() - 35, in.length() - 45);
      age_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      age = std::stoi(age_s);
      temp = in.substr(in.length() - 24, in.length() - 46);
      deposit_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      deposit = std::stoi(deposit_s);
      temp = in.substr(in.length() - 3, in.length());
      drinks_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      drinks = std::stoi(drinks_s);

      cout << name << endl;

      l.addAtIndex(index, name, age, deposit, drinks);
    
      
  }
}

int main(int argc, char *argv[]) {

    ArgumentManager am(argc, argv);

    //ifstream fin(am.get("input"));
    //ifstream cfin("command1.txt");
  
    ifstream fin("input1.txt");
    ifstream cfin("command1.txt");
    ofstream fout("output1.txt");

    string in;

    list people;

    string name;
    string age_s;
    int age;
    string deposit_s;
    int deposit;
    string drinks_s;
    int drinks;
    string temp;

    bool emptyC = cfin.peek() == EOF;
    bool emptyF = fin.peek() == EOF;

    if (!emptyF){
      while (getline(fin, in)){
      cleanInput(in);
      //cout << in << endl;
      
      name = in.substr(6, in.length() - 47);
      //cout << name << " ";
      
      temp = in.substr(in.length() - 35, in.length() - 45);
      age_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      age = std::stoi(age_s);
      //cout << age << " ";
      
      temp = in.substr(in.length() - 24, in.length() - 46);
      deposit_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      deposit = std::stoi(deposit_s);
      //cout << deposit << " ";
      
      temp = in.substr(in.length() - 3, in.length());
      drinks_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      drinks = std::stoi(drinks_s);
      //cout << drinks << endl;
      
      people.append(name, age, deposit, drinks);
      //people.print();
    }
      people.append(name, age, deposit, drinks);
      people.print();
      }
    // last person that the loop doesnt get for some reason...

    if (!emptyC){
      string command;
      while(getline(cfin, command)){
        fixC(command);
        cout << command << endl;
        doCommand(command, people);
        people.print();
      }
      doCommand(command, people);
    }
    people.printFile(fout);
    

  }