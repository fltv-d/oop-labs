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
  ~Item();   
  Item *Next() const;  
  Item *Prev() const;
};                          

class List
{
private:
  Item *head;
  Item *tail;
  unsigned int count;    
public:
  List();
  ~List(); 
  void Add(Item *node);
  void Insert(Item *node, unsigned int number);
  Item *GetItem(unsigned int number) const;
  unsigned int GetIndex(const Item *node) const;
  Item *Remove(unsigned int number);
  void Delete(unsigned int number);
  unsigned int Count() const;
  void Clear(); 
  Item *Head() const; 
  Item *Tail() const;
};                            

#endif

