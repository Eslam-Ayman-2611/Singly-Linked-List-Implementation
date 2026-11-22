#include"Header.h"

// inserting Chooice 
void main_inserting_options()
{
 clear_Terminal(); 
 while (true)
 {
    typeText("\n+-------------------------------------------+\n");
    typeText("|      Choose where to insert the node      |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  1 -> Insert at Beginning                 |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  2 -> Insert at End                       |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  3 -> Insert at Specific Position         |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  4 -> Insert After a Specific Element     |\n");
    typeText("|-------------------------------------------|\n");
    typeText("|  5 -> Exist                               |\n");
    typeText("+-------------------------------------------+\n");

    int option ;
    typeText(" Enter your option : \n");
    cin >> option ;

        if (option >=1 && option <=5)
        {
                switch(option)
            {
                case 1 : insert_at_head();
                break;
                case 2 : insert_at_end();
                break;
                case 3 : insert_in_index();
                break;
                case 4 : insert_after_data();
                break;
                case 5 : return;
                break;
                default: typeCText(" Enter a valid option \n",RED);  
            }
            return ;
        }
        else 
        {
            typeCText(" Enter a valid option \n",RED);
            clear_Terminal();
        }
 } 
    return ;
}

// insert at head
void insert_at_head()
{
    clear_Terminal();
    if (Sptr== nullptr)
        {
            typeText("\n That's your first node \n ");
            node *Temp = new node ;
            Temp->next = Sptr;
            Sptr = Temp ;
            typeText("\n Enter data to that node :\n"); 
            cin >> Temp ->data;
            typeCText(" your node added sucessfully \n",GREEN);

        }
    else 
        {
            node *Temp = new node ;
            Temp->next = Sptr;
            Sptr = Temp ;
            typeText("\n Enter data to that node :\n"); 
            cin >> Temp ->data;
            typeCText(" your node added sucessfully \n",GREEN);
        }
    display_linked_list();
    return ;
}

// insert at end
void insert_at_end()
{
    clear_Terminal();
    if (Sptr== nullptr)
        {    
            typeText("\n That's your first node \n ");
            node *Temp = new node ;
            Temp->next = Sptr;
            Sptr = Temp ;
            typeText("\n Enter data to that node :\n"); 
            cin >> Temp ->data;
        }
    else 
        {
            node *last= find_last_node();
            node *Temp = new node ;
            last->next = Temp ;
            Temp->next = nullptr;
            typeText(" Enter data to that node : \n"); 
            cin >> Temp ->data;
        }
    typeCText(" your node added sucessfully \n",GREEN);
    display_linked_list();
    return ; 
}
// insert in index 
void insert_in_index()
{
    clear_Terminal();
    typeText("\n Let's insert at Specific index ");
    int needed_index ;
    int index_of_last_node = (count_nodes()-1);

    typeText(" we have " + to_string(index_of_last_node+1) + " nodes \n");
    typeText(" you could insert at index 0 to "+ to_string (index_of_last_node+1) + " \n");
    typeText(" Please enter the index you want to insert at \n");
    cin >> needed_index ;

    if (needed_index<0)
        {   
            typeCText(" How you want to add here !!?     \n",RED);
            typeCText(" as a punish go to main choice  \n",RED);
            options();
        }
    else if (needed_index==0)
        {
            insert_at_head();
        }
    else if (needed_index==index_of_last_node+1)
        {
            insert_at_end();
        }
    else
        {
            node *Temp = new node ;
            node *needed = Sptr;
            for (int i = 0; i < needed_index-1; i++)
            {
                needed = needed->next;
            }
            Temp->next = needed->next;
            needed->next = Temp ;
            typeText(" Enter data to that node : \n"); 
            cin >> Temp ->data;
            typeCText(" your node added sucessfully in index " + to_string(needed_index) + " \n",GREEN);
            display_linked_list();   
        }
    return ;
}

// insert after index
void insert_after_data()
{
    clear_Terminal();
    typeText("\n Let's insert after specific data \n");
    typeText(" Please enter the data you want to insert after \n");
    int needed_data = 0 ;
    cin >> needed_data ;
    
    node *needed = find_specific_node(needed_data);
    if (needed==nullptr)
    {
        typeText(" there is no node with this data \n");
    }
    else 
    {
        node *New = new node ;
        New->next = needed->next;
        needed->next = New ;
        typeText(" Enter data to that node : \n"); 
        cin >> New ->data;
        typeCText(" your node added sucessfully \n",GREEN);
        display_linked_list();   
    }
    return ;
}