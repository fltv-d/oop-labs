#ifndef _DLL_H_
#define _DLL_H_

class Item
{
  friend class List;
private:
  Item *prev;
  Item *next;
public:
  Item(); 
  virtual ~Item();   
  Item *Next() const;  
  Item *Prev() const;
};                          

class List
{
private:
  Item *head;
  Item *tail;
  int count;    
public:
  List();
  ~List(); 
  void Add(Item *node);
  void Insert(Item *node, int number);
  Item *GetItem(int number) const;
  int GetIndex(const Item *node) const;
  Item *Remove(int number);
  void Delete(int number);
  int Count() const;
  void Clear(); 
  Item *Head() const; 
  Item *Tail() const;
};                            

#endif

