#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ArgumentManager.h"
#include <vector>
#include <regex>

using namespace std;

//[name: value; age: value; deposit: value; number of drinks: value] 
struct node{
  string name;
  int age;
  int deposit;
  int drinks;
  node *next;
};

class list{
  private:
    node *head = new node;
  public:
    list(){
      head = nullptr;
    }

    node* top(){
      return head;
    }

    bool isEmpty(){
      return (head == nullptr);
    }

    int size(node *n){
      if (n == nullptr)
        return 0;

      return 1 + size(n->next);
    }

    void print(){
      node *cu = head;

      while(cu->next != nullptr){
        std::cout << "[name: " << cu->name << "; age: " << cu->age << "; deposit: " << cu->deposit << "; number of drinks: " << cu->drinks << "]" << std::endl;
        cu = cu->next;
      }
      std::cout << std::endl;
    }

    // removes all nodes with the same name as input
    void rName(string _name){
      node *cu = head;
      node *prev = nullptr;
      node *last = new node;

      while(cu->next->next != nullptr){
        cu = cu->next;
      }

      last = cu->next;
      if (last->name == _name){
        //cout << last->age << endl;
        cu->next = nullptr;
        delete(last);
      }

      cu = head;
      while (cu->next != nullptr){
        if (cu->name == _name){
          if (prev == nullptr){
            head = cu = cu->next;
          }
          else{
            cu = prev->next = cu->next;
          }
        }
        prev = cu;
        cu = cu->next;
      }
    }

    // removes all nodes with the same age as input
    void rAge(int _age){
      node *cu = head;
      node *prev = nullptr;
      node *last = new node;

      while(cu->next->next != nullptr){
        cu = cu->next;
      }

      last = cu->next;
      if (last->age == _age){
        //cout << last->age << endl;
        cu->next = nullptr;
        delete(last);
      }

      cu = head;

      while (cu->next != nullptr){
        if (cu->age == _age){
          if (prev == nullptr){
            head = cu = cu->next;
          }
          else{
            if (prev == nullptr){
            head = cu = cu->next;
          }
          else{
            cu = prev->next = cu->next;
          }
          }
        }
        prev = cu;
        cu = cu->next;
      }
    }

    // removes all nodes with the same deposit as input
    void rDeposit(int _deposit){
      node *cu = head;
      node *prev = nullptr;
      node *last = new node;

      while(cu->next->next != nullptr){
        cu = cu->next;
      }

      last = cu->next;
      if (last->deposit == _deposit){
        //cout << last->age << endl;
        cu->next = nullptr;
        delete(last);
      }

      cu = head;
      while (cu->next != nullptr){
        if (cu->deposit == _deposit){
          if (prev == nullptr){
            head = cu = cu->next;
          }
          else{
            cu = prev->next = cu->next;
          }
        }
        prev = cu;
        cu = cu->next;
      }
    }

    // removes all nodes with the same drinks as input
    void rDrinks(int _drinks){
      node *cu = head;
      node *prev = nullptr;
      node *last = new node;

      while(cu->next->next != nullptr){
        cu = cu->next;
      }

      last = cu->next;
      if (last->drinks == _drinks){
        //cout << last->age << endl;
        cu->next = nullptr;
        delete(last);
      }

      cu = head;
      while (cu->next != nullptr){
        if (cu->drinks == _drinks){
          if (prev == nullptr){
            head = cu = cu->next;
          }
          else{
            cu = prev->next = cu->next;
          }
        }
        prev = cu;
        cu = cu->next;
      }
    }

    void push(string _name, int _age, int _deposit, int _drinks){
      node *temp = new node;
      node *cu = head;
      temp->name = _name;
      temp->age = _age;
      temp->deposit = _deposit;
      temp->drinks = _drinks;

      // check for duplicates
      if (!isEmpty()){
        while (cu->next != nullptr){
          if (temp->name.find(cu->name) != string::npos){
            if (temp->age == cu->age){
              cout << temp->name << " is a duplicate" << endl;
              cu->deposit = temp->deposit;
              cu->drinks = temp->drinks;
              return;
            }
          }
          cu = cu->next;
        }
      }

      // reset cu
      cu = head;

      temp->next = cu;
      head = temp;
    }

    void append(string _name, int _age, int _deposit, int _drinks){

      node *temp = new node;
      node *cu = new node;
      cu = head;

      temp->name = _name;
      temp->age = _age;
      temp->deposit = _deposit;
      temp->drinks = _drinks;

      // check for duplicates
      // LFGGGGGG IT WORKS
      if (!isEmpty()){
        while (cu->next != nullptr){
          if (temp->name.find(cu->name) != string::npos){
            if (temp->age == cu->age){
              cout << temp->name << " is a duplicate" << endl;
              cu->deposit = temp->deposit;
              cu->drinks = temp->drinks;
              return;
            }
          }
          cu = cu->next;
        }
      }
      
      //reset cu and add normally
      cu = head;
      if (isEmpty()){
        head = temp;
      }
      else{
        while (cu->next != nullptr){
          cu = cu->next;
        }
          cu->next = temp;
      }
      
    }

    void addAtIndex(int pos, string _name, int _age, int _deposit, int _drinks){

      node *temp = new node;
      node *cu = new node;
      cu = head;

      temp->name = _name;
      temp->age = _age;
      temp->deposit = _deposit;
      temp->drinks = _drinks;

      if (!isEmpty()){
        while (cu->next != nullptr){
          if (temp->name.find(cu->name) != string::npos){
            if (temp->age == cu->age){
              cout << temp->name << " is a duplicate" << endl;
              cu->deposit = temp->deposit;
              cu->drinks = temp->drinks;
              return;
            }
          }
          cu = cu->next;
        }
      }

      // reset cu
      cu = head;
      node *head_ref = head;

      if (isEmpty())
        head = temp;
      else if (pos > size(head_ref)){
        while (cu->next != nullptr){
          cu = cu->next;
        }
        cu->next = temp;
      }
      else{
        for (int i = 1; i < pos - 1; i++){
          cu = cu->next;
        }
        temp->next = cu->next;
        cu->next = temp;
      }
      
    }

    void swap(node *a, node *b){
      node *temp = new node;

      temp->name = a->name;
      temp->age = a->age;
      temp->deposit = a->deposit;
      temp->drinks = a->drinks;

      a->name = b->name;
      a->age = b->age;
      a->deposit = b->deposit;
      a->drinks = b->drinks;

      b->name = temp->name;
      b->age = temp->age;
      b->deposit = temp->deposit;
      b->drinks = temp->drinks;
      
    }

    void sort(string s){

      if (s.find("name") != string::npos){
        node *cu = head;
        node *index = nullptr;
        node *temp = new node;
  
        while (cu != nullptr){
          index = cu->next;
          while (index != nullptr){
            if (cu->name > index->name){
              swap(cu, index);
            }
            index = index->next;
          }
          cu = cu->next;
        }
      }
      else if (s.find("age") != string::npos){
        node *cu = head;
        node *index = nullptr;
        node *temp = new node;
  
        while (cu != nullptr){
          index = cu->next;
          while (index != nullptr){
            if (cu->age > index->age){
              swap(cu, index);
            }
            index = index->next;
          }
          cu = cu->next;
        }
      }
      else if (s.find("deposit") != string::npos){
        node *cu = head;
        node *index = nullptr;
        node *temp = new node;
  
        while (cu != nullptr){
          index = cu->next;
          while (index != nullptr){
            if (cu->deposit > index->deposit){
              swap(cu, index);
            }
            index = index->next;
          }
          cu = cu->next;
        }
      }
      else if (s.find("drinks") != string::npos){
        node *cu = head;
        node *index = nullptr;
        node *temp = new node;
  
        while (cu != nullptr){
          index = cu->next;
          while (index != nullptr){
            if (cu->drinks > index->drinks){
              swap(cu, index);
            }
            index = index->next;
          }
          cu = cu->next;
        }
      }
      
    }

};

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
  s.erase(remove(s.begin(), s.end(), '('), s.end());
  s.erase(remove(s.begin(), s.end(), ')'), s.end());
}


void doCommand(string c, list &l){
  if (c.find("Remove") != string::npos){
    if (c.find("name")!= string::npos){
      string attribute = c.substr(c.find("name") + 6, c.length());
      l.rName(attribute);
    }
    else if (c.find("age")!= string::npos){
      string attribute = c.substr(c.length() - 3, c.length());
      int a = stoi(attribute);
      l.rAge(a);
    }
    else if (c.find("deposit")!= string::npos){
      string attribute = c.substr(c.length() - 4, c.length());
      //cout << attribute << endl;
      int dep = stoi(attribute);
      //cout << dep << endl;
      l.rDeposit(dep);
    }
    else if (c.find("drinks")!= string::npos){
      string attribute = c.substr(c.length() - 1, c.length());
      int d = stoi(attribute);
      l.rDrinks(d);
    }
  }
}

int main(int argc, char *argv[]) {
  
    ifstream fin("input1.txt");
    ifstream cfin("command1.txt");

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

    // grab/parse input file and populate linked list
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

    // last person that the loop doesnt get for some reason...
    people.append(name, age, deposit, drinks);
    people.print();

    string command;
    while(getline(cfin, command)){
      fixC(command);
      //cout << command << endl;
      doCommand(command, people);
    }

    people.print();
    

  }