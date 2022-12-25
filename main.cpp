#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct Node
{
    string str;
    Node* left, *right;
};

Node* newNode(string s)
{
    Node* temp = new Node;
    temp->str = s;
    temp->left = temp->right = NULL;
    return (temp);
}

ifstream fin("animals_data.txt");

void load(Node *&root)
{
    string s;
    getline(fin,s);
    if (s=="")
       return;
    root = newNode(s);
    load(root->left);
    load(root->right);
}

void save(Node *ob);

ofstream fout;

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node *root,*p;
    load(root);
    p=root;
    cout<<"Загадайте животное"<<endl;
    int x;
    while(p->left!=NULL)
    {
        cout<<p->str<<"? (0 - Нет, 1 - Да): ";
        cin>>x;
        if(x)
            p=p->left;
        else
            p=p->right;
    }
    cout<<"Это "<<p->str<<"? (0 - Нет, 1 - Да): ";
    cin>>x;
    if(x)
        cout<<"Я угадал!";
    else
    {
        cout<<"Я проиграла. Что это за животное? ";
        string s,q;
        getline(cin,s);
        getline(cin,s);
        cout<<"Введите вопрос, отличающий это животное от "<<p->str<<": ";
        getline(cin,q);
        Node *p1,*p2;
        p1=newNode(s);
        p2=newNode(p->str);
        p->str=q;
        p->left=p1;
        p->right=p2;
    }
    fout.open("animals_data.txt");
    save(root);
    fout.close();
    return 0;
}


void save(Node *ob)
{
    if(ob==NULL)
    {
        fout<<""<<endl;
        return;
    }
    fout<<ob->str<<endl;
    save(ob->left);
    save(ob->right);
}
