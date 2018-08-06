#include <bits/stdc++.h>
using namespace std;

struct node
{
	int num;

	int val;
	struct node *left;
    struct node *right;
    int max;
    int min;

};

node* tree[100001];

struct node* newNode(int num)
{
  // Allocate memory for new node 
  struct node* node = (struct node*)malloc(sizeof(struct node));
 
  // Assign data to this node
  node->num = num;
 	
  node->val = 0; 		
  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int solve(node* root){

	if(root->left == NULL && root->right == NULL){

		root->min = root->val;
		root->max = root->val;
		return 0;
	}

	int l = solve(root->left);
	int r = solve(root->right);

	node* left = root->left;
	node* right = root->right;

	if(l == -1 || r == -1)
		return -1;


	if(left->max < right->min){
		root->min = left->min;
		root->max = right->max;
		return(l+r);
	}
	else if(right->max < left->min){
		root->min = right->min;
		root->max = left->max;
		return(l+r+1);
	}
	else
		return -1;

}

int main()
{
	int t;
	long int n,l,r,ans;

	cin >> t;


	for(int j=1;j<=100000;j++){
 		tree[j] = newNode(j);
 	}


	while(t--){

		cin >> n;

		for(long int i=1;i<=n;i++){

			cin >> l >> r;

			if(l != -1){
				tree[i]->left = tree[l];
				tree[i]->right = tree[r];
			}
			else{

				tree[i]->val = r;
			}
		}



		ans = solve(tree[1]);

		cout << ans << "\n";

		for(int i=1;i<=n;i++){
			tree[i]->left = NULL;
			tree[i]->right = NULL;
		}

	}


	return 0;
}