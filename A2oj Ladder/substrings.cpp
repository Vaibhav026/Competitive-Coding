#include <bits/stdc++.h>
using namespace std;

long int ans = 0;
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, char key[],int ll)
{
    struct TrieNode *pCrawl = root;
 	
    for (int i = 0; i < ll; i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]){
        	//cout << "vv";
            pCrawl->children[index] = getNode();
            ans++;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// // Returns true if key presents in trie, else
// // false
// bool search(struct TrieNode *root, string key)
// {
//     struct TrieNode *pCrawl = root;
 
//     for (int i = 0; i < key.length(); i++)
//     {
//         int index = key[i] - 'a';
//         if (!pCrawl->children[index])
//             return false;
 
//         pCrawl = pCrawl->children[index];
//     }
 
//     return (pCrawl != NULL && pCrawl->isEndOfWord);
// }
 
// Driver
int main()
{
    
 
    struct TrieNode *root = getNode();
 
    string s;

 	cin >> s;

 	int l = s.length();

 	string isgood;

 	cin >> isgood;

    int k;

    cin >> k;

    int bad ;
    int z;

    
    char s2[l];

    int index = 0;
    for(int i=0;i<l;i++){

    	bad = 0 ;
    	index = 0 ;
    	

    	for(int j=i;j<l;j++)
    	{	
    		z = s[j] - 'a' + 1;
    		
    		if(isgood[z-1] == '0')
    			bad++;


			if(bad > k)
    		{	

    			if(index!=0)
    			{ 
    			  s2[index] = '\0';
    			  //cout << s2[0] << endl;
    			    
    			  // // cout << ll << endl;
    			   
    			   int ll = strlen(s2);
    			    // for(int x=0;x<ll;x++)
    			    // cout << s2[x];


    			    cout  << endl;
    			  insert(root,s2,ll);


    			}
    			break;
    		}
    		else
    		{
    			s2[index] = s[j];
    			//cout << s[j] << " "<<endl;
    			index++;
			}

			if(j == l-1 && bad<=k)
			insert(root,s2,index);	
    	}
    
    }

    cout << ans;

    return 0;
}