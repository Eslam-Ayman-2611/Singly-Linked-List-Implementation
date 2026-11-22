#include "Header.h"

void main_searching_options()
{
  if (Sptr == nullptr)
    {
      clear_Terminal();
      typeText(" your linked list is empty, There are nothing to search for look..\n");
      display_linked_list();
    }
  else 
    {
      while (true)
        {
          clear_Terminal();    
          typeText("\n+-------------------------------------------+\n");
          typeText("|     Choose you need search for what       |\n");
          typeText("|-------------------------------------------|\n");
          typeText("|  1 -> Search for a specific Data          |\n");
          typeText("|-------------------------------------------|\n");
          typeText("|  2 -> Search for the smallest value       |\n");
          typeText("|-------------------------------------------|\n");
          typeText("|  3 -> Search for the largest value       |\n");
          typeText("|-------------------------------------------|\n");
          typeText("|  4 -> Exit                                |\n");
          typeText("+-------------------------------------------+\n");

          typeText("Enter your choice : ");
          int choice;
          cin >> choice;
          if(choice == 1)
            {
              clear_Terminal();
              Search_specific_Data();
              return ;
            }
          else if(choice == 2)
            {
              clear_Terminal();
              search_for_smallest_value();
              return ;
            }
          else if (choice == 3)
            {
              clear_Terminal();
              search_for_largest_value();
              return ;
            }
          else if (choice == 4)
            {
              clear_Terminal();
              return;
            }
          else
            {
              typeCText("Enter a valid option\n", RED);
              Continue();
              clear_Terminal();
            }
        }           
    }
}
void Search_specific_Data()
{
  int needed_data = 0 ;
  int index = 0 ;
  bool flag = 0 ;
  typeText(" Enter data you want to search for : \n");
  cin >> needed_data ;  
  node* Loop = Sptr ;
  while (Loop != nullptr )
  {
    if ( Loop-> data == needed_data )
    {
      typeCText("Your data : "+ to_string(needed_data)+" found here in node number "+ to_string(index)+"\n",GREEN);
      printNodeInfo(Loop, index);
      flag=1;
    }
    index++;
    Loop = Loop-> next ;
  }
  if (flag == 0 )
  {
    typeCText("Your data : "+ to_string(needed_data)+" can't found\n",RED);
  }
  return ; 
}  

void  search_for_smallest_value()
{
  if (Sptr->next == nullptr )
  {
    typeText("you have only one element \n");
    display_linked_list();
    return ;
  }
  else
  { 
    node* Loop = Sptr -> next ;
    int smallest = Loop->data ;
    int index = 1 ; 
    while( Loop != nullptr )
    {
      if (smallest > Loop->data)
      {
        smallest = Loop->data;
      }
      Loop = Loop -> next ;
    }
    typeCText(" your smallest data is  = \n"+ to_string(smallest),GREEN);
    while (Loop != nullptr)
    {
      if (Loop -> data == smallest )
      {
        typeCText(" The smallest data : "+ to_string(smallest)+" appeared here in node number "+ to_string(index)+"\n",GREEN);
        printNodeInfo(Loop, index);
      }
      index++ ;
      Loop = Loop -> next ;
    }
  }
  return ;
}

void  search_for_largest_value()
{
    if (Sptr->next == nullptr )
  {
    typeText("you have only one element \n");
    display_linked_list();
    return ;
  }
  else
  { 
    node* Loop = Sptr -> next ;
    int largest = Loop->data ;
    int index = 1 ; 
    while( Loop != nullptr )
    {
      if (largest < Loop->data)
      {
        largest = Loop->data;
      }
      Loop = Loop -> next ;
    }
    typeCText(" your largest data is  = \n"+ to_string(largest),GREEN);
    while (Loop != nullptr)
    {
      if (Loop -> data == largest )
      {
        typeCText(" The largest data : "+ to_string(largest)+" appeared here in node number "+ to_string(index)+"\n",GREEN);
        printNodeInfo(Loop, index);
      }
      index++ ;
      Loop = Loop -> next ;
    }
  }
  return ;
}

//helper searching functions
node* find_befor_last_node()
{
    // cout<<" Lest's find last element \n";
    if (Sptr==nullptr)
    {
      cout<<" your linked list is empty \n";
      return nullptr;
    }
    if (Sptr->next==nullptr)
    {
      return Sptr ;
    }
    else 
    {
        node* last = Sptr ; 
        while (last-> next -> next !=nullptr)
        {
            last = last->next;
        }
        return last;
    }
}
node* find_specific_node(int needed_data)
{
  if (Sptr==nullptr)
    {
      cout<<" your linked list is empty \n";
      return nullptr;
    }
    else 
    {
        node* Temp = Sptr ;
        while (Temp!=nullptr)
        {
            if (Temp->data == needed_data)
            {
                return Temp ;
            }
            Temp = Temp->next;
        }
        cout<<" there is no node with this data \n";
        return nullptr ;
    }
}

node* find_before_specific_node(int needed_data)
{
  if (Sptr==nullptr)
    {
      cout<<" your linked list is empty \n";
      return nullptr;
    }
    else if (Sptr->data == needed_data)
    {
      return Sptr ;
    }
    else 
    {
        node* Temp = Sptr->next ;
        while (Temp->next!=nullptr)
        {
            if (Temp->next->data == needed_data)
            {
                return Temp ;
            }
            Temp = Temp->next;
        }
        cout<<RED<<" there is no node with data = "<<needed_data<<" \n";
        return nullptr ;
    }
}
node* find_last_node()
{
  if (Sptr == nullptr)
  {
    return nullptr;
  }
  else
  {
    node* last = Sptr;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    return last;
  }
}