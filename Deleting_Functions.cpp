#include "Header.h"

void main_deleting_options()
{
  clear_Terminal();
  if (Sptr == nullptr)
    {
        typeText(" your linked list is empty, nothing to delete\n");
        display_linked_list();
    }
  else 
    {
       while (true)
        {
          clear_Terminal();    
          typeText("\n+-------------------------------------------+\n");
          typeText("|     How many nodes you need to delete     |\n");
          typeText("|-------------------------------------------|\n");
          typeText("|  1 -> Delete Entire List                  |\n");
          typeText("|-------------------------------------------|\n");
          typeText("|  2 -> Delete specific number of nodes     |\n");
          typeText("|-------------------------------------------|\n");
          typeText("|  3 -> Exit                                |\n");
          typeText("+-------------------------------------------+\n");

          typeText("Enter your choice : ");
          int choice;
          cin >> choice;
          if(choice == 1)
            {
            clear_Terminal();
            delete_all();
            return;
            }
          else if (choice == 2)
            {
              while (true)
              {
                clear_Terminal();    
                int total = count_nodes();
                int number_to_delete = 0;
                typeText("\nLook that is your linked list:\n");
                display_linked_list();
                typeText("\n How many nodes you need to delete?\n");
                typeText(" Enter integer number from 1 to " + to_string(total) + "\n");
                cin >> number_to_delete;

                if (number_to_delete <= 0)
                  {
                      typeCText(" Deleting negative number !?\n why not i'll think about that \n", RED);
                  }
                else if (number_to_delete == 0)
                  {
                      typeCText("Deleting zero nodes !?\n Assume that are done  \n", RED);
                      typeCText(" Go back to main menu \n", RED);
                      return;
                  }
                else if (number_to_delete > total)
                  {
                      typeCText("Number exceeds list size\n", RED);
                      typeCText("Enter a valid number in the next time \n", RED);
                  }
                else if (number_to_delete == total)
                  {
                      typeText("Deleting entire list...\n");
                      delete_all();
                      return;
                  }
                  else if (number_to_delete < total && number_to_delete > 0)
                  {
                    for (int i = 0; i < number_to_delete; i++)
                      {
                          typeText(" Deleting node " + to_string(i + 1) + " from "+ to_string(total-i) + "\n");
                          choose_where_Delete();
                      }
                      typeCText(" Done deleting " + to_string(count_nodes()-total) + " nodes \n", GREEN);
                      typeCText(" Now your list looks like this \n", GREEN);
                      display_linked_list();

                      return;
                  }
              }
            }
          else if (choice == 3)
            {
              clear_Terminal();
              return;
            }
          else
            {
              typeCText("Enter a valid option\n", RED);
              clear_Terminal();
            } 
        }
    }
  return ;
}

void choose_where_Delete()
{
    while (true)
    {
        typeText("\n+-------------------------------------------+\n");
        typeText("|     Choose you need delete from where     |\n");
        typeText("|-------------------------------------------|\n");
        typeText("|  1 -> Delete from Beginning               |\n");
        typeText("|-------------------------------------------|\n");
        typeText("|  2 -> Delete from End                     |\n");
        typeText("|-------------------------------------------|\n");
        typeText("|  3 -> Delete from Specific Position       |\n");
        typeText("|-------------------------------------------|\n");
        typeText("|  4 -> Delete a Specific Element           |\n");
        typeText("|-------------------------------------------|\n");
        typeText("|  5 -> Exit                                |\n");
        typeText("+-------------------------------------------+\n");

        typeText("Enter your option : ");

        int option;
        cin >> option;

        switch (option)
        {
            case 1: delete_from_head(); return;
            case 2: delete_from_end(); return;
            case 3: delete_by_index(); return;
            case 4: delete_by_data(); return;
            case 5: return;
            default: typeText("Enter a valid option\n");
        }
    }
}
// deleteing functions
void delete_from_head()
{
  if (Sptr == nullptr)
    {
      typeText(" your linked list is empty, nothing to delete\n");
      display_linked_list();

    }
  else 
    {
      node* Temp = Sptr ;
      Sptr = Sptr->next ;
      delete Temp ;
      typeCText(" Node deleted successfully \n",GREEN);
      typeCText(" Look !! It's a magic \n",GREEN);
    }
  return;
}
void delete_from_end()
{
    node* befor_last = find_befor_last_node();
    if (befor_last == nullptr)
    {
        typeText("your linked list is empty, nothing to delete\n");
    }
    else if (befor_last == Sptr)
    {
        typeText(" Deleting the only node you have and keeping your list empty and Sptr = nullptr\n");
        delete_from_head();
    }
    else
    {
      node* Temp = befor_last->next->next ;
      delete Temp ;
      befor_last->next = nullptr;
      typeCText(" Node deleted successfully \n",GREEN);
      typeCText(" Look !! It's a magic \n",GREEN);
    }
  display_linked_list();

  return ;
}
void delete_by_data()
{
  int needed_data = 0 ;
  typeText(" Enter data you want to delete it's node : \n");
  cin >> needed_data ;  
  node* node_defore_needed_node = find_before_specific_node(needed_data);
  node* node_defore_last_node = find_last_node();
  if (node_defore_needed_node == nullptr)
    {
      display_linked_list();
    }
  else if (node_defore_needed_node == Sptr && Sptr->data == needed_data)
    { 
      cout<<" your data in the first node in your list \n";
      delete_from_head();
    }
  else if (node_defore_needed_node == node_defore_last_node )
    {
      typeText(" your data is in the last node in your list \n");
      delete_from_end();
    }
  else 
    {
      node_defore_needed_node->next = node_defore_needed_node->next->next ;
      delete node_defore_needed_node->next ;
      display_linked_list();

    }
  return ;
}
void delete_by_index()
{
 if (Sptr == nullptr)
  {
    typeText("your linked list is empty, nothing to delete\n");
    display_linked_list();
  }
 else 
  {
    int nubmer_of_nodes = count_nodes();
    int needed_index = 0 ;
    typeText(" Take care the indexes start from 0 to " + to_string(nubmer_of_nodes - 1) + "  \n");
    typeText(" Enter index of node you want to delete : \n");
    cin >> needed_index ;
    while (needed_index < 0 || needed_index > nubmer_of_nodes)
      {
        typeCText(" How you need to delete node in index " + to_string(needed_index) + " \n", RED);
        typeCText(" Enter a valid index \n", RED);
        cin >> needed_index ;
      }
    if (needed_index == 0)
      {
        delete_from_head();
      }
    else if (needed_index == nubmer_of_nodes - 1)
      {
        delete_from_end();
      }
    else 
      {
        node* Befor_need = Sptr->next ;
        for (int i = 0 ; i < needed_index - 1 ; i++)
          {
            Befor_need = Befor_need->next ;
          }
        if (Befor_need)
          {
            node* node_to_delete = Befor_need->next ;
            Befor_need->next = Befor_need->next->next ;
            delete node_to_delete ;
            typeCText(" Node deleted successfully \n",GREEN);
            typeCText(" Look !! It's a magic \n",GREEN);
          }
        display_linked_list();
      }
  }
return;
}
void delete_all()
{
  typeCText(" Let's Deleting all nodes in your linked list \n");
  while (Sptr != nullptr)
    {
      delete_from_end();
    }
  typeCText(" All nodes deleted successfully \n",GREEN);
  return ;
}