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

    void push(string _name, int _age, int _deposit, int _drinks){
      node *temp = new node;
      node *cu = head;
      temp->name = _name;
      temp->age = _age;
      temp->deposit = _deposit;
      temp->drinks = _drinks;

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

      if (isEmpty()){
        head = temp;
      }
      else{
        while (cu->next != nullptr)
          cu = cu->next;

          cu->next = temp;
      }
      
    }

    
};

void cleanInput(string &s){
  s.erase(remove(s.begin(), s.end(), ';'), s.end());
  s.erase(remove(s.begin(), s.end(), '\n'), s.end());
  s.erase(remove(s.begin(), s.end(), '\r'), s.end());
  s.erase(remove(s.begin(), s.end(), '['), s.end());
  s.erase(remove(s.begin(), s.end(), ']'), s.end());
}

int main() {
  
    ifstream fin("input1.txt");

    string in;

    list people;

    while (getline(fin, in)){
      cleanInput(in);
      //cout << in << endl;
      string name;
      string age_s;
      int age;
      string deposit_s;
      int deposit;
      string drinks_s;
      int drinks;
      string temp;
      
      name = in.substr(6, in.length() - 47);
      cout << name << " ";
      
      temp = in.substr(in.length() - 35, in.length() - 45);
      age_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      age = std::stoi(age_s);
      cout << age << " ";
      
      temp = in.substr(in.length() - 24, in.length() - 46);
      deposit_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      deposit = std::stoi(deposit_s);
      cout << deposit << " ";
      
      temp = in.substr(in.length() - 3, in.length());
      drinks_s = std::regex_replace(temp, std::regex(R"([\D])"), "");
      drinks = std::stoi(drinks_s);
      cout << drinks << endl;

      people.append(name, age, deposit, drinks);
    }

    people.print();

  }