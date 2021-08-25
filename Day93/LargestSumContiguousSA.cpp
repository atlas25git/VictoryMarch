
void updateUtil(int arr[], int index, int low, int high, int idx, int value)
{
	if (low == high) 
	{
		tree[index].sum = value;
		tree[index].prefixsum = value;
		tree[index].suffixsum = value;
		tree[index].maxsum = value;
	} 
	else
	{
		int mid = (low + high) / 2;
		
		//if node to be updated is in left subtree.
		if (idx <= mid)
		    updateUtil(arr, 2 * index + 1, low, mid, idx, value);
		//else node to be updated is in right subtree.
		else 
		    updateUtil(arr, 2 * index + 2, mid + 1, high, idx, value);
		
		tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;
		tree[index].prefixsum = max(tree[2 * index + 1].prefixsum, tree[2 * index + 1].sum + tree[2 * index + 2].prefixsum);
		tree[index].suffixsum = max(tree[2 * index + 2].suffixsum, tree[2 * index + 2].sum + tree[2 * index + 1].suffixsum);
		tree[index].maxsum = max(tree[index].prefixsum, max(tree[index].suffixsum, max(tree[2 * index + 1].maxsum, max(tree[2 * index + 2].maxsum, tree[2 * index + 1].suffixsum + tree[2 * index + 2].prefixsum))));
	}
}

node queryUtil(int arr[], int index, int low, int high, int l, int r)
{
    node result;
    //initially all the values are equal to INT_MIN.
    result.sum = result.prefixsum = result.suffixsum = result.maxsum = INT_MIN;
    
    //if segment of this node is outside the given range, we return result.
    if (r < low || high < l)
    return result;
    
    //if segment of this node is a part of given range, we return tree[index].
    if (l <= low && high <= r)
    return tree[index];
    
    //if a part of this segment overlaps with the given range, we call
    //the function recursively for the children nodes accordingly.
    int mid = (low + high) / 2;
    if (l > mid) 
    return queryUtil(arr, 2 * index + 2, mid + 1, high, l, r);
    if (r <= mid) 
    return queryUtil(arr, 2 * index + 1, low, mid, l, r);
    
    node left = queryUtil(arr, 2 * index + 1, low, mid, l, r);
    node right = queryUtil(arr, 2 * index + 2, mid + 1, high, l, r);
    
    //finding the maximum and returning it.
    result.sum = left.sum + right.sum;
    result.prefixsum = max(left.prefixsum, left.sum + right.prefixsum);
    result.suffixsum = max(right.suffixsum, right.sum + left.suffixsum);
    
    result.maxsum = max(result.prefixsum,max(result.suffixsum,max(left.maxsum,
                    max(right.maxsum,left.suffixsum + right.prefixsum))));
    return result;
}

//Function to update a value in input array and segment tree.
void update(int arr[], int arrSize, int index, int value) 
{
	arr[index-1]=value;
	
	//updating the value of nodes in segment tree.
	updateUtil(arr, 0, 0, arrSize-1, index-1, value);
}

//Funciton to return the Maximum-Sum in the range.
int query(int arr[], int n, int l, int r)
{
	return queryUtil(arr, 0, 0, n-1, l-1, r-1).maxsum;
}

