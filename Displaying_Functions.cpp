# include "Header.h"

string pointer_To_String(const void* pointer)
{
    if (pointer == nullptr) 
    {
      return "NULL";
    }
    else 
    {
      stringstream ss;
      ss << pointer;
      return ss.str();
    }
}

void printLeftLine(const string& text, size_t width)
{
    size_t pad = width - text.length();
    cout << "|" << text << string(pad, ' ') << "|\n";
}
void printCenteredLine(const string& text, size_t width)
{       
    if (text == "Sptr") 
        {
            size_t pad = width - text.length();
            cout << "|" << string(pad / 2, ' ');
            cout << RED<< text << RESET ;
            cout <<string(pad - pad / 2, ' ') << "|\n";
            return;
        }
    size_t pad = width - text.length();
    cout << "|" << string(pad / 2, ' ');
    cout << GREEN << text << RESET ;
    cout <<string(pad - pad / 2, ' ') << "|\n";
}
void printBox(const string& title, const string& line1, const string& line2, const string& line3)
{
    size_t width = title.length();
    if (line1.length() > width) width = line1.length();
    if (line2.length() > width) width = line2.length();
    if (line3.length() > width) width = line3.length();
    width += 4;

    cout << "+" << string(width, '-') << "+\n";
    printCenteredLine(title, width);
    cout << "|" << string(width, '-') << "|\n";
    printLeftLine(line1, width);
    printLeftLine(line2, width);
    printLeftLine(line3, width);
    cout << "+" << string(width, '-') << "+\n";
}

void printGlobalPointer()
{
    printBox(
        "Sptr",
        "Name: Start Pointer",
        "Address: " + pointer_To_String(&Sptr),
        "Content: " + pointer_To_String(Sptr)
    );
}

void printNodeInfo(node* currentNode, int nodeIndex)
{
    printBox(
        "Node " + to_string(nodeIndex),
        "Address: " + pointer_To_String(currentNode),
        "Value: " + to_string(currentNode->data),
        "Next: " + pointer_To_String(currentNode->next)
    );
}


void display_linked_list()
{

    printGlobalPointer();

    if (Sptr == nullptr)
      {   
          Continue();
          return;
      }
      else 
      {
          node* currentNode = Sptr;
          int nodeIndex = 0;
          cout << "        |\n        v\n";
          while (currentNode != nullptr)
              {
                  printNodeInfo(currentNode, nodeIndex++);
                  if (currentNode->next != nullptr)
                  {
                      cout << "        |\n        v\n";
                  }
                  currentNode = currentNode->next;
              }
          Continue();
          clear_Terminal();
          return;
        }
}


// 
void printGlobalPointerReversed(node* head)
{
    printBox(
        "Reversed",
        "Name: Reversed Head",
        "Address: " + pointer_To_String(&head),
        "Content: " + pointer_To_String(head)
    );
}

void display_reversed_list(node* Reversed)
{
    printGlobalPointerReversed(Reversed);

    if (Reversed == nullptr)
    {
        Continue();
        return;
    }
    else
    {
        node* currentNode = Reversed;
        int nodeIndex = 0;

        cout << "        |\n        v\n";

        while (currentNode != nullptr)
        {
            printNodeInfo(currentNode, nodeIndex++);

            if (currentNode->next != nullptr)
            {
                cout << "        |\n        v\n";
            }

            currentNode = currentNode->next;
        }

        Continue();
        clear_Terminal();
        return;
    }
}