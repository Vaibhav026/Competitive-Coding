
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include <vector>
#include<cstring>

#include<stack>

using namespace std;

 


struct node

{ 
    char data; 
    bool end;
    long int endindex;
    vector <int> indexes;

    node* child[27];

    node()
    {
        for (int i = 0; i <=26 ; i++)
        child[i] = NULL;
        
        end = false;
        endindex = -1;
    }

};

 

/* 

 * trie class Declaration

 */

class trie

{ 

    private: 

        node *root;

    public: 

        trie() 

        { 

            root = new_node('0');

        }

 

        node *new_node(char data) 

        {   

            node *Q = new node; 

            Q->data = data; 

            Q->end = false;
            
            Q->endindex = -1;
            
            return Q; 

        }

 

        void add(string S,long int index,int l) 

        { 

            node *cur = root; 

            for (int i = 0; i < l; i++)

            {

                if (!cur->child[S[i] - 'a'+1]) 
                cur->child[S[i] - 'a'+1] = new_node(S[i]);

                cur = cur->child[S[i] - 'a'+1]; 

                (cur->indexes).push_back(index);
            }

            cur->end = true;
            
            if(cur->endindex!=-1)
            cur->endindex = min(index,cur->endindex);
            else
            cur->endindex = index;
        }

        void min_lex(node* curr,long int max)
        {   
            if(curr->end && (curr->endindex)<=max)
            {   return;
            }    
            for(int i=1;i<=26;i++)
            {
                if(curr->child[i] && ((curr->child[i])->indexes)[0]<=max)
                {   cout<<(curr->child[i])->data;
                    min_lex(curr->child[i],max);
                    return;
                }    
            }
            
        }

        void check(node *cur, string S, int i,long int max,int l) 

        {   
            
            if (cur && (cur->indexes)[0] <= max)  
           { 
                cout<<cur->data; 

                if (i < l) 
                {  
                    if( !(cur->child[S[i] - 'a'+1]) ||  ((cur->child[S[i] - 'a'+1])->indexes)[0]>max)
                    {  
                        min_lex(cur,max);
                        return;
                    }    

                    check(cur->child[S[i] - 'a'+1], S, i + 1,max,l); 
                }
                else
                {
                    if(cur->end && cur->endindex<=max)
                    return;
                    else
                    {
                        min_lex(cur,max);
                        return;
                    }    
                }    

            }
            

        }
       

        

        void checkroot(string S,long int max,int l) 

        { 

            if (root && S.length() > 0 && S[0] >= 'a') 
            {   
                if( !root->child[S[0] - 'a'+1] ||  ((root->child[S[0] - 'a'+1])->indexes)[0]>max )
                min_lex(root,max); 
                else
                check(root->child[S[0] - 'a'+1],S,1,max,l); 
            }
             

        }

};



int main()
{   
    long int n;
    cin>>n;

    long int q;

    trie dict;
    string s;
    for(long int i=1;i<=n;i++)
    {
        cin>>s;
        dict.add(s,i,s.length());
    }    
    
    cin >> q;

    long int r;
    string  query; 
    
    int l;    
    while(q--)
    {   
        cin >> r;
        cin >> query;

        l = query.length();

        dict.checkroot(query,r,l);
        cout<<endl;
    }    
    


    return 0;
}


