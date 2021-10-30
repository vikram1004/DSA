// global head pointer
struct Node *head = NULL;

// function to delete first node: uses approach 2.1
// See http://ideone.com/ClfQB for complete program and output
void deleteFirst()
{
	if(head != NULL)
	{
	// store the old value of head pointer	
	struct Node *temp = head;
		
	// Change head pointer to point to next node
	head = head->next;

	// delete memory allocated for the previous head node
	free(temp);
	}
}
