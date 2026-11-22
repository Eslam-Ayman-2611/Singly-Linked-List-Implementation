# include "Header.h"

void main_movement_options()
{
 clear_Terminal(); 
 if(Sptr==nullptr)
  {
    typeCText(" your linkedlist is empty , You have nothing to move \n",RED);
  }
  else if (Sptr->next==nullptr)
  {
    typeCText(" your linkedlist contain only one node , You have nothing to compare between \n",RED);
  }
 else 
  {
    typeText(" Look that's our linked list till now \n");
    display_linked_list();
    clear_Terminal();
    while (true)
    {
      typeText("\n+-------------------------------------------+\n");
      typeText("|      Choose which movement you need       |\n");
      typeText("|-------------------------------------------|\n");
      typeText("|  1 -> Move the largest to the end         |\n");
      typeText("|-------------------------------------------|\n");
      typeText("|  2 -> Move the smallest to the start      |\n");
      typeText("|-------------------------------------------|\n");
      typeText("|  3 -> Exist                               |\n");
      typeText("+-------------------------------------------+\n");

      int option ;
      typeText(" Enter your option : \n");
      cin >> option ;

          switch(option)
            {
              case 1 : Move_largest_to_end();
              break;
              case 2 : Move_smallest_to_beginning();
              break;
              case 3 : return;
              break;
              default: 
              typeCText(" Enter a valid option \n",RED); 
              clear_Terminal();
              break;
            }
    } 
  }
  display_linked_list();
  return ;
}

void Move_largest_to_end()
{

  node* Loop = Sptr -> next ;
  int largest = Loop->data ;
  while( Loop != nullptr )
    {
      if (largest < Loop->data)
      {
        largest = Loop->data;
      }
      Loop = Loop -> next ;
    }
    //now  largest contain the largest
    
    //let's make our pointers 
    node* last = find_last_node();
    node* largest_add = find_specific_node(largest);
    node* befor_largest_add = find_before_specific_node(largest);
    // magic
    befor_largest_add = largest_add->next ;
    last->next = largest_add ;
    largest_add->next= nullptr ;
}

void Move_smallest_to_beginning()
{
  node* Loop = Sptr -> next ;
  int smallest = Loop->data ;
  while( Loop != nullptr )
    {
      if (smallest > Loop->data)
      {
        smallest = Loop->data;
      }
      Loop = Loop -> next ;
    }
    // now we have the smallest on the smallest

  node* smallest_add = find_specific_node(smallest);
  node* befor_smallest_add = find_before_specific_node(smallest);
  // 
  befor_smallest_add->next = smallest_add->next ; 
  smallest_add ->next = Sptr ;
  Sptr = smallest_add ;
}

// reverse 
void reverse()
{
    if (Sptr == nullptr)
    {
        typeText("you haave no nodes to reverse \n");
    }
    else if (Sptr->next == nullptr)
    {
        typeText("you haave only one node how you need to reverse \n");
    }
    else
    {
        node* Reversed = nullptr;
        node* loop = Sptr;

        while (loop != nullptr)
        {
            node* temp = new node;
            temp->data = loop->data;
            temp->next = Reversed;
            Reversed = temp;
            loop = loop->next;
        }
        display_reversed_list(Reversed);
    }
}