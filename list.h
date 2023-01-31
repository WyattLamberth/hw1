#include <string>
#include <iostream>
#include <fstream>

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
    node **pp = &head;
  public:
    list(){
      head = nullptr;
    }

    node* top(){
      return head;
    }
    node** head_ref(){
      return pp;
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

    void printFile(ofstream &fout){
      node *cu = head;

      while(cu->next != nullptr){
        fout << "[name: " << cu->name << "; age: " << cu->age << "; deposit: " << cu->deposit << "; number of drinks: " << cu->drinks << "]" << std::endl;
        cu = cu->next;
      }
      fout << std::endl;
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
        cout << "test head = temp" << endl;
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

      cout << temp->name << endl;

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

      if (isEmpty()){
        push(_name, _age, _deposit, _drinks);
      }
      else if (pos > size(head_ref)){
        cout << "test1" << endl;
        append(_name, _age, _deposit, _drinks);
      }
      else if (pos <= 0){
        cout << "test2" << endl;
        push(_name, _age, _deposit, _drinks);
      }
      else{
        for (int i = 0; i < pos - 1; i++){
          cu = cu->next;
        }
        cout << "test3" << endl;
        temp->next = cu->next;
        cu->next = temp;
      }
      
    }

    void sort(string s){

      if (s.find("name") != string::npos){
        node *cu = head;
        node *index = nullptr;
        node *temp = new node;

        cout << "sorting by name..." << endl;
  
        while (cu->next != nullptr){
          index = cu->next;
          while (index->next != nullptr){
            if (cu->name > index->name){
              swap(*cu, *index);
              swap(cu->next, index->next);
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
  
        while (cu->next != nullptr){
          index = cu->next;
          while (index->next != nullptr){
            if (cu->age > index->age){
              swap(*cu, *index);
              swap(cu->next, index->next);
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
  
        while (cu->next != nullptr){
          index = cu->next;
          while (index->next != nullptr){
            if (cu->deposit > index->deposit){
              swap(*cu, *index);
              swap(cu->next, index->next);
              print();
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
  
        while (cu->next != nullptr){
          index = cu->next;
          while (index->next != nullptr){
            if (cu->drinks > index->drinks){
              swap(*cu, *index);
              swap(cu->next, index->next);
            }
            index = index->next;
          }
          cu = cu->next;
        }
      }
      
    }

  

};