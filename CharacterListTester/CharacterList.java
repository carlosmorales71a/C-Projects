import javax.swing.JOptionPane;

public class CharacterList {
		// declare instance field
	private CharacterNode list;
	
	private class CharacterNode
	{
			// declare for a single
			// character's node
		public Character aCharacter;
		
			// declare the 'next' pointer
			// for that character's node		
		public CharacterNode next;	
		
		public CharacterNode(Character newCharacter)
		{
			aCharacter = newCharacter;
			next = null;
		}	// end constructor CharacterNode
		
		public String thisChar()
		{
			return aCharacter.thisChar2();
		}	// end method thisChar
	}	// end class CharacterNode
	
	public CharacterList()
	{
			//no linked list exist at this time
		list = null;
	}	// end method CharacterList
	
	public void add(Character newCharacter)
	{
			// current pointer (c) and trailer
			// pointer (t) are declared; as
			// well the newly created node
		CharacterNode c, t;
		CharacterNode node = new CharacterNode(newCharacter);
		
			// if the linked list is empty, this
			// new node will be the first node
			// in the linked list
		if (list == null)
		{
			list = node;
			System.out.println("This character was added " +
								"to the linked list: " +
								node.aCharacter);
		}	// end if statement
		
		else	// linked list is not empty
		{
			c =list;
			t= list;
			
			while (c !=null &&
					node.thisChar().compareTo(c.thisChar()) > 0)
			{
				t = c;	// set trailer pointer
				c = c.next;	// advance current pointer
							// to point to the node
			}	// end while loop
				
				// if 'list' and current pointer 'c'
				// are the same, then insert the new
				// node at the beginning of the
				// linked list
			if (list ==c)
			{
					// node.next point to the
					// beginning of the 'old'
					// linked list
				node.next = list;
				
					// 'node' is now the 'new'
					// first node is in the linked
					// list
				list = node;
			}	// end if statement	
			
			else
			{
					// new node must be inserted
					// into the middle of the linked
					// list
				node.next = t.next;
				t.next = node;
			}	// end else statement
			
			System.out.println("This character was added " +
							"to the linked list: " +
							node.aCharacter);
			
		}	// end outer else statement
	}	// end method add
	
	public void delete(String deleteCharacter)
	{
		CharacterNode c, t;
		
		c = list;
		t = list;
		
		while (c !=null &&
				deleteCharacter.compareTo(c.thisChar()) != 0)
		{
				// trailer 't' will be kept
				// behind the current pointer 'c'
			t = c;
						
				// advance the current pointer 'c'
				// to point to the next node in
				// linked list
			c = c.next;
		}	// end while loop
					
			// character does not exist
		if (c == null)
		{
			JOptionPane.showMessageDialog(null,
					"Sorry but the character " +
					deleteCharacter +
					" does not exist!",
					"Error",
					JOptionPane.ERROR_MESSAGE);
		} // end if statement
		
			// the node to be deleted is
			// the first node in the
			// linked list
		else if (t == list && c == list)
		{
			list = t.next;
			System.out.println("This character " +
						deleteCharacter +
						" has been deleted from " +
						"the linked list.");
		}	// end else if statement
		
			// node to be deleted exist within
			// the middle of the linked list
		else
		{
			t.next = c.next;
			System.out.println("This character " + 
							deleteCharacter + 
							" has been deleted from " +
							" the linked list.");
		}	// end else statement
						
	}	// end method delete
	
	public String buildList()
	{
		String result;
		CharacterNode c;
		
		c = list;
		result = "Here is your current linked list:\n\n";
		
			// traverse the entire linked list
			// and build up the info part of
		 	// each node as a string as
			// we visit each node
		while (c != null)
		{
			result = result + c.aCharacter + "\n";
			c = c.next;
		}	// end while loop
		
		return result;
		
	}	// end method buildList
		
}	// end method CharacterList
