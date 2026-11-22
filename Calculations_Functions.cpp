#include"Header.h"

void main_calculations_options()
{ 

  clear_Terminal(); 
    if(Sptr==nullptr)
    {
      typeCText(" your linkedlist is empty , You have nothing to calculate \n",RED);
    }
    else 
    {
      clear_Terminal();
      typeText(" By default we will calculate the sum and average for all nodes \n");
      typeText(" If you need to specifi and condition press 1 any thing other will continue with default \n");
      typeText(" Enter your option : \n");
      int option ;
      cin >> option ;
      clear_Terminal();
      display_linked_list();
      clear_Terminal();
      if ( option == 1 )
        {
          Sum_Average_All_nodes();
        }
      else 
        {
          typeCText("   Hmmm ....  \n , Let's do some real work  \n",GREEN);
          clear_Terminal();
          Sum_Average_specific_nodes();
        }
      clear_Terminal();
      } 
  return ;
}

void Sum_Average_All_nodes()
{
  int sum = 0 ;
  int counter = 0 ;
  float average = 0.00;
  node* looping = Sptr ;
  while (looping!= nullptr)
  {
    sum += looping->data;
    counter++;
    looping = looping->next;
  }
  typeText(" The sum of data in all your "+to_string(counter)+"nodes = "+to_string(sum));
  average = float(sum / counter);
  typeText(" The Average of data in all your "+to_string(counter)+"nodes = "+to_string(average));

  return ;
}

void Sum_Average_specific_nodes()
{
  clear_Terminal();
  while (true)
  {
    typeText("\n+-------------------------------------------+\n");
    typeText("|      Choose which condition you need       |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  1 -> even values Only                    |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  2 -> odd values Only                     |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  3 -> values that divide by number        |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  4 -> Exist                               |\n");
    typeText("+-------------------------------------------+\n");

    int option ;
    typeText(" Enter your option : \n");
    cin >> option ;

    switch(option)
      {
        case 1 : even_values(); return;
        break;
        case 2 : odd_values(); return;
        break;
        case 3 : specific_values(); return;
        break;
        case 4 : return;
        break;
        default: typeCText(" Enter a valid option \n",RED); 
        clear_Terminal();
        break;
      }
}
}
void even_values()
{
  int sum = 0 ;
  int counter = 0 ;
  float average = 0.00;
  node* loop = Sptr ;

  while (loop!=nullptr)
  {
    if( (loop->data %2) == 0)
    {
      sum = sum + loop->data;
      counter++;
    }
    loop = loop->next;
  }

  typeText(" The sum of data in all your "+to_string(counter)+" even nodes = "+to_string(sum));
  average = float(sum / counter);
  typeText(" The Average of data in all your "+to_string(counter)+" even nodes = "+to_string(average));
}

void odd_values()
{
  int sum = 0 ;
  int counter = 0 ;
  float average = 0.00;
  node* loop = Sptr ;

  while (loop!=nullptr)
  {
    if( (loop->data %2) == 1)
    {
      sum = sum + loop->data;
      counter++;
    }
    loop = loop->next;
  }
  typeText(" The sum of data in all your "+to_string(counter)+" odd nodes = "+to_string(sum));
  average = float(sum / counter);
  typeText(" The Average of data in all your "+to_string(counter)+" odd nodes = "+to_string(average));
  return ;
}
void specific_values()
{
  int Condition ;
  int sum = 0 ;
  int counter = 0 ;
  float average = 0.00;
  node* loop = Sptr ;
  typeText(" Enter the numer youneed to divisible by : ");
  cin >> Condition ;
  while (loop!=nullptr)
  {
    if( (loop->data %Condition) == 0)
    {
      sum = sum + loop->data;
      counter++;
    }
    loop = loop->next;
  }
  typeText(" The nodes compliant with your condition = "+to_string(counter)+"\n the sum of that nodes = "+to_string(sum));
  average = float(sum / counter);
    typeText(" The Average of data on them = "+to_string(average));
  return ;
}

