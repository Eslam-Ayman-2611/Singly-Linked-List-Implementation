#include"Header.h"

void main_sorting_options()
{
   clear_Terminal(); 
 if(Sptr==nullptr)
  {
    typeCText(" your linkedlist is empty , You have nothing to sort \n",RED);
  }
  else if (Sptr->next==nullptr)
  {
    typeCText(" your linkedlist contain only one node , You have nothing to Sort \n",RED);
  }
 else 
  {
    typeText(" By default we will use Ascending Order \n");
    typeText(" If you need Descending Order press 1 any thing other will continue with Ascending \n");
    typeText(" Enter your option : \n");
    int option ;
    cin >> option ;
    clear_Terminal();
    typeText(" Look that's our linked list till now \n");
    display_linked_list();
    clear_Terminal();
    if (option ==1 )
      {
        Descending_order_sorting();
      }
    else 
      {
        Ascending_order_sorting();
      }
    clear_Terminal();
    display_linked_list();
    } 
  return ;
}

void Ascending_order_sorting()
{
  node* current_node = nullptr;
  node* comparison_node = nullptr;

  for (current_node = Sptr;current_node->next != nullptr; current_node = current_node->next)
  {
    for (comparison_node = current_node->next ; comparison_node != nullptr ; comparison_node = comparison_node->next)
    {
      if (current_node->data > comparison_node->data)
      {
        int temp = current_node->data;
        current_node->data = comparison_node->data;
        comparison_node->data = temp;
      }
    }
  }

  typeCText(" Linked List Sorted Ascending Successfully \n", GREEN);
}

void Descending_order_sorting()
{
  node* current_node = nullptr;
  node* comparison_node = nullptr;

  for (current_node = Sptr; current_node->next != nullptr; current_node = current_node->next)
  {
    for (comparison_node = current_node->next; comparison_node != nullptr; comparison_node = comparison_node->next)
    {
      if (current_node->data < comparison_node->data)
      {
        int temp = current_node->data;
        current_node->data = comparison_node->data;
        comparison_node->data = temp;
      }
    }
  }

  typeCText(" Linked List Sorted Descending Successfully \n", GREEN);
}