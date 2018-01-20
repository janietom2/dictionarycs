import java.util.Random; 
public class BTreeTest{
	
	
	/* Methods */
	
	
	  public static void printAscending(BTreeNode T){
		   //Prints all keys in the tree in ascending order

			  if (T.isLeaf){
					for(int i =0; i<T.n;i++)
						System.out.print(T.key[i]+" ");
				}
				else{
					for(int i =0; i<T.n;i++){
						printAscending(T.c[i]);
						System.out.print(T.key[i]+" ");
					}
					printAscending(T.c[T.n]);

				}
		   }
	  
	  public static void printAscendingDepth(BTreeNode T, int d ){
		   //Prints all keys in the tree in ascending order
		  	 
		  	  if(d == 0) {
		  		for(int i =0; i<T.n;i++)
					System.out.print(T.key[i]+" ");
		  
		  	  }
		  
			  if (T.isLeaf){
					return;
				}
				else{
					for(int i =0; i<T.n;i++){
						printAscendingDepth(T.c[i], d-1);
						System.out.print(T.key[i]+" ");
					}
					printAscendingDepth(T.c[T.n], d-1);

				}
		   }
	  
	  public static boolean search(BTreeNode T, int k) {
		  
		  int i = 0;
		  
		  while( i < T.n && k > T.key[i] )
			  i++;
		  
		  if( i == T.n || k > T.key[i] ) {
			  if(T.isLeaf) {
				  return false;
			  } else {
				  return search(T.c[i], k);
			  }
		  }
		  
		  return true;
		  
	  }
	  
	  public static int min_in_tree(BTreeNode T) {
		  
		  if(T.isLeaf) {
			  return T.key[0];
		  } else {
			  return min_in_tree(T.c[0]);
		  }
		  
	  }
	  
	  public static int min_in_tree_depth(BTreeNode T, int d) {
		  
		  if( d == 0 ) {
			  return T.key[0];
		  } else {
			  
			  if(T.isLeaf)
				  return -1;
			  else
				  return min_in_tree_depth(T.c[0], d-1);
		  }
		  
		  
	  }
	  
	  public static int max_in_tree(BTreeNode T) {
		  
		  if(T.isLeaf) {
			  return T.key[T.n];
		  } else {
			  return min_in_tree(T.c[T.n]);
		  }
		  
	  }
	  
	  public static int max_in_tree_depth(BTreeNode T, int d) {
		  
		  if( d == 0 ) {
			  return T.key[T.n];
		  } else {
			  
			  if(T.isLeaf)
				  return -1;
			  else
				  return max_in_tree_depth(T.c[T.n], d-1);
		  }
		  
		  
	  }
	  
	  public static int numbersOfKeysDepth(BTreeNode T, int d) {
		  
		  if( d == 0 ) {
			  return T.n;
		  }
		  
		  return numbersOfKeysDepth(T.c[])
		  
	  }
	
	
	/* Methods */
	

  
 

//   public static void printKey(BTreeNode t) {
//
//	   if(t.isLeaf) {
//		   for (int i = 0; i < t.n; i++) {
//			   System.out.println(t.key[i]);
//		   }
//	   } else{
//	   		for (int i = 0; i <= t.c[0].n; i++){
//	   			printKey(t.c[0].c[i]);
//				System.out.println("****************");
//			}
//	   }
//
//   }
  
  

   public static void main(String[] args)   {
	   int [] S = {6, 3, 16, 11, 7, 17, 14, 8, 5, 19, 15, 1, 2, 4, 18, 13, 9, 20, 10, 12, 21};

	   BTree B = new BTree(3);

	   for (int i=0;i<S.length;i++) {
		   
			   B.insert(S[i]);
		    //B.printNodes();
            //System.out.println("*********************");
       }

      BTreeNode T = B.root;
      
      
      System.out.println(min_in_tree_depth(T, 5));
      
	   printAscending(T);


//      //Build B-tree with random elements
//      Random rn = new Random();
//      BTree R = new BTree(4);
//
//      for (int i=0;i<30;i++) {
//		  R.insert(rn.nextInt(100));
//		  R.printNodes();
//		  System.out.println("*********************");
//      }
//
//      T = R.root;
//      printAscending(T);
//
//
	}
}