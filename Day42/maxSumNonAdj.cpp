pair<int, int> maxSumHelper(Node *root) 
{ 
    //if root is null, we return two zeroes in pair.
	if (root==NULL) 
	{ 
		pair<int, int> sum(0, 0); 
		return sum; 
	} 
	
	//calling function recursively for left and right subtrees.
	pair<int, int> sum1 = maxSumHelper(root->left); 
	pair<int, int> sum2 = maxSumHelper(root->right); 
	pair<int, int> sum; 

	//current node is included (Left and right children are not included). 
	sum.first = sum1.second + sum2.second + root->data; 

	//current node is excluded (Either left or right child is included).
	sum.second = max(sum1.first, sum1.second) + 
				max(sum2.first, sum2.second); 

	return sum; 
} 

//Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root) 
{ 
	pair<int, int> res = maxSumHelper(root);
	//returning the maximum between the elements in pair(res).
	return max(res.first, res.second); 
} 