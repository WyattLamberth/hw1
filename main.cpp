#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "ArgumentManager.h"

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
    node *head;
  public:
    list(){
      head = nullptr;
    }

    node* top(){
      return head;
    }

    bool isEmpty(){
      return head = nullptr;
    }

    int size(node *n){
      if (n == nullptr)
        return 0;

      return 1 + size(n->next);
    }

    void print(){
      node *cu = head;

      while(cu->next != nullptr){
        std::cout << "[name: " << cu->name << "; age: " << cu->age << "; deposit: " << cu->deposit << "; number of drinks: " << cu->drinks << "]";
        cu = cu->next;
      }
      std::cout << std::endl;
    }

    void push(string _name, int _age, int _deposit, int _drinks){
      node *temp = new node;
      temp->name = _name;
      temp->age = _age;
      temp->deposit = _deposit;
      temp->drinks = _drinks;

      temp->next = head;
      head = temp;
    }

    void append(string _name, int _age, int _deposit, int _drinks){
      node *temp = new node;
      temp->name = _name;
      temp->age = _age;
      temp->deposit = _deposit;
      temp->drinks = _drinks;
      
      if (isEmpty()){
        head = temp;
      }
      else{
        node *cu = head;
        while (cu->next != nullptr){
          // hopefully will handle duplicates...
          if (cu->name == temp->name && cu->age == temp->age){
            cu->deposit = temp->deposit;
            cu->drinks = temp->drinks;
            break;
          }
          else cu = cu->next;
        }
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

    while (getline(fin, in)){
      cleanInput(in);
      cout << in << endl;
      string name;
      string age;
      string deposit;
      string drinks;
      
    }
    
  }