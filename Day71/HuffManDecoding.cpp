string decodeHuffmanData(struct MinHeapNode* root, string bs)
{
    string ans;
    struct MinHeapNode* curr = root;
    //not a recursive fn simple string traversal
    //and thus just makse optimal choice based on current index's value
    //since the code is prefix free thus, we come back at root when a paricular
    //part has been decoded.
    for(int i=0;bs[i];i++)
        {
            if(bs[i]-'0')
                curr = curr->right;
            else curr = curr->left;
            
            //reached end
            if(!curr->left && !curr->right)
                ans += curr->data,curr=root;
        }
        return ans;
    
    
    return ans;
}


string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
	string ans = "";
	struct MinHeapNode* curr = root;
	
	//iterating over the string.
	for (int i=0; i<binaryString.size(); i++)
	{
	    //if character is "0" then moving to left child of parent node
	    //else to the right child.
		if (binaryString[i] == '0')
		curr = curr->left;
		else
		curr = curr->right;
		
		//if both the child of current node are null, we add the data 
		//at current node in our result and update current node.
		if (curr->left==NULL and curr->right==NULL)
		{
			ans += curr->data;
			curr = root;
		}
	}
	//returning the resultant string.
	return ans+'\0';
}