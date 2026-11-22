#include"Header.h"

void welcome_message()
{
  cout << CYAN << "\n=================================================\n" << RESET;
  typeCText("   Welcome DR Asmaa to the linked list program   \n", BOLD);
  cout << CYAN << "=================================================\n" << RESET;
    
  int number_of_nodes = 0 ;
  typeText("\n\n   How many nodes you need to create ?\n");
  typeText("   Enter positive integer number : \n");
  cin>> number_of_nodes ;
  while(number_of_nodes<=0)
    {
      typeCText(" Don't play with me \n",RED);
      typeCText(" you can't create a linked list with this number of nodes \n",RED);
      typeText("   Enter positive integer number : \n");
      cin>> number_of_nodes ;
    }
  if (number_of_nodes==1)
    {
        creat_linked_list();  
    }
  if (number_of_nodes!=1)
    {
      for (int i = 0 ; i < number_of_nodes ; i++)
        {
          if (i == 0)
          {
          creat_linked_list();
          }
          else 
          {
          typeText("  you will add node number " + to_string(i+1) + " \n");
          main_inserting_options();
          }
        }
    }

  options();
  return ;
}


// main options
void options()
{
    while (true)
    {   
        typeText("\n  \n+---------------------------------------------+\n");
        typeCText("|",BOLD);
        typeCText("                Main options",CYAN);
        typeCText("                 |\n",BOLD);
        typeText("|---------------------------------------------|\n");
        typeText("|  1 -> Add a new node                        |\n");
        typeText("|---------------------------------------------|\n");
        typeText("|  2 -> Delete a node(s)                      |\n");
        typeText("|---------------------------------------------|\n");
        typeText("|  3 -> Find value(s)                         |\n"); // Search for a specific element and display the element and its position if found. 
        typeText("|---------------------------------------------|\n");
        typeText("|  4 -> Move node(s)                          |\n");
        typeText("|---------------------------------------------|\n");
        typeText("|  5 -> Display the linked list               |\n");
        typeText("|---------------------------------------------|\n");
        typeText("|  6 -> Sort the linked list                  |\n");
        typeText("|---------------------------------------------|\n");
        typeText("|  7 -> Reverse the linked list               |\n");
        typeText("|---------------------------------------------|\n");
        typeText("|  8 -> calculations on linked list           |\n");
        typeText("|---------------------------------------------|\n");
        typeText("|  9 -> Exit                                  |\n");
        typeText("+---------------------------------------------+\n");
        typeText("\n choose an option : \n");
        
        int option ;
        cin >> option ;
        switch(option)
        {
            case 1 : main_inserting_options();//Done
            break;
            case 2 : main_deleting_options();//Done
            break;
            case 3 : main_searching_options();//Done
             break;
            break;
            case 4 : main_movement_options();
            break;
            case 5 : display_linked_list();
            break;
            case 6 : main_sorting_options();////need editing
            break;
            case 7 : reverse();////need editing
            break;
            case 8 : main_calculations_options();////need editing
            break;
            case 9 : Exit(); return;
            break;
            default: cout<<" Please enter a valid option \n";
            clear_Terminal();
        }
    }
}

int count_nodes()
{
    if (Sptr==nullptr)
    {
      return 0;
    }
    else 
    {
        int count = 0 ;
        node* Temp = Sptr ;

        while (Temp!=nullptr)
        {
            count++;
            Temp = Temp->next;
        }
        cout<<" The number of nodes in your linked list is : "<<count<<endl;
        return count ;
    }
    return 0;
}

void creat_linked_list()
{   
    clear_Terminal();
    node *Temp = new node ;
    Sptr = Temp ;
    Temp->next = nullptr;
    typeText("\n That will be the first node in our linked list "); 
    typeText("\n Enter data to that node : \n"); 
    cin >> Temp ->data;
    typeText("\n your node sucessfully added look ! \n\n"); 
    display_linked_list();
    return ;
}
void Exit()
{
  typeCText("  are you sure you need to Exit \n", BOLD);
  typeCText("  To Exit press 1 \n To return back press any thing else   \n", BOLD);
  typeText( " Enter your option : \n"); 
  int option = 0 ;
  if (option == 1 )
    {
     typeCText("       Good bay       \n", CYAN);
    }
    else 
    {
        options();
    }
    return ;
}
