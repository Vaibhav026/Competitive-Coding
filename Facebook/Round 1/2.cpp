#include <bits/stdc++.h>
using namespace std;



std::vector<int> preorder;

std::vector<int> postorder;
	
std::vector<int> adj[2005];

int label[2005];

bool visited[2005];


void dfs(int i,int val){

	visited[i] = true;
	label[i] = val;

	int s = adj[i].size();

	int m;

	for(int j=0;j<s;j++){

		m = adj[i][j];

		if(!visited[m])
			dfs(m,val);
	}
}
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

node* tree[2005];
/* newNode() allocates a new node with the given data and NULL left and 
   right pointers. */
struct node* newNode(int data)
{
  // Allocate memory for new node 
  struct node* node = (struct node*)malloc(sizeof(struct node));
 
  // Assign data to this node
  node->data = data;
 
  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}


void pre_order(node* root){
	if(root == NULL)
		return;

	preorder.push_back(root->data);

	pre_order(root->left);
	pre_order(root->right);
}

void post_order(node* root){
	if(root == NULL)
		return;

	post_order(root->left);
	post_order(root->right);
	postorder.push_back(root->data);

}
int main()
{	
	#ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
	#endif

 	int t;

 	int n,k;

 	cin >> t;


 	
 	int a,b,l;

 	for(int j=1;j<=2000;j++){
 		tree[j] = newNode(j);
 	}

 	for(int i=1;i<=t;i++){

			
 		
 		for(int j=0;j<=2004;j++){
 			
 			visited[j] = false;
 			adj[j].clear();
 		}

 		cin >> n >> k;

 		for(int j=1;j<=n;j++){

 			cin >> a >> b;

 			if(a != 0){
 				tree[j]->left = tree[a];
 			}

 			if(b != 0){
 				tree[j]->right = tree[b];
 			}


 		}
 		cout << "Case #"<<i<<": ";
 		

 		
 		pre_order(tree[1]);

 		post_order(tree[1]);

 		int x,y;

 		l =1;

 		for(int j=0;j<n;j++){

 			x = preorder[j];
 			y = postorder[j];

 			adj[x].push_back(y);
 			adj[y].push_back(x);

 		}

 		int connected_components = 0;


 		for(int j=1;j<=n;j++){

 			if(!visited[j]){

 				connected_components++;
 				
 				dfs(j,l);
 				
 				l++;
 			}

 			if(l == k+1)
 				l=1;

 		}
 		
 		
 		if( connected_components < k){
 			cout << "Impossible";
 		}
 		else{

 			for(int j=1;j<=n;j++)
 				cout << label[j] << " ";
 		}

 		cout << endl;

 		preorder.clear();
 		postorder.clear();


 		for(int j=1;j<=n;j++){
 			
 			tree[j]->left = NULL;
 			tree[j]->right = NULL;
 		}
 	}



	return 0;
}