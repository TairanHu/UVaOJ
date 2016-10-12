


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node
{
    char c;
    Node *next;
};

typedef struct Node Link_Node;

int main()
{
    string temp;
    int flag_head = 0;
    int flag_rear = 0;
    //getline(cin, temp);

    while(getline(cin, temp))
    {
        int k = 0;

        while(temp[k] == '[' || temp[k] == ']')
        {
            k++;
        }
        Link_Node *front1 = new Link_Node;
        front1->c = temp[k];
        front1->next = NULL;
        Link_Node *p = front1;

        Link_Node *head = new Link_Node;
        //head->next = front;
        head->next = NULL;
        Link_Node *head_p = head;


        for(int i = k+1; i < temp.size(); i++)
        {

            if(temp[i] == '[')
            {
                flag_head = 1;
                flag_rear = 0;
                //i++;
                continue;
            }
            else if(temp[i] == ']')
            {
                flag_head = 0;
                flag_rear = 1;
                //i++;
                continue;
            }
            //cout << "hello_haha" <<endl;

            if(flag_head)
            {
                //cout << "hello" <<endl;
                Link_Node *New_Node = new Link_Node;
                New_Node->c = temp[i];
                New_Node->next = NULL;
                head_p->next = New_Node;
                head_p = New_Node;
                //i++;
                continue;
            }
            else if(flag_rear)
            {
                //cout << "world" <<endl;
                flag_rear = 0;
                //Link_Node *New_Node = new Link_Node;
                //New_Node = front;
                head_p->next = front1;
                front1 = head->next;
                head_p = head;
            }


            Link_Node *New_Node = new Link_Node;
            New_Node->c = temp[i];
            New_Node->next = NULL;
            p->next = New_Node;
            p = New_Node;
        }

        Link_Node *tt = front1;
        while(tt)
        {
            cout << tt->c;
            tt = tt->next;
        }

        cout << endl;

    }
    //cout << temp;
    return 0;

}

