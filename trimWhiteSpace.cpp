/* This function trims leading and trailing white space from a char array or C string.
Inner whitespace is left in tact */ 

void trim(char str[STRING_SIZE]){
   unsigned int k = strlen(str) - 1; // used to index last non null character of C string
	 unsigned int counter = 0; // count total white space
	 unsigned int i = 0;
	 while(str[i] != '\0'){
	    if(isspace(str[i])){
			  counter++;
		 }
		  i++;
	 }
	 bool execute = true;
   // executing the below code prevents segment faults on and edge case but it isnt necessary for an n spaces long all whitespace string where n >= 1
	 if(counter == strlen(str)){ // executes for strings which are all whitespace like the empty string
	   char temp[1] = "";
		 strcpy(str,temp); // make it a null string
		 execute == false;
	 }
	  // create selection block for strings with white space, other strings should be unaltered, all whitespace string taken care of above
	 if((str[0] == ' ' || str[0] == '\n' || str[0] == '\t' || str[k] == ' ' || str[k] == '\n' || str[k] == '\t') && execute ){
     while(k > 0){
			 if(!isalpha(str[k])){
				 k--;
			 }
			 else{
				 break;
			 }
		 }
      str[k + 1] = '\0'; // erase remaining parts of string that contain whitespace

			// count leading white space characters
			unsigned int count = 0;

			while(isspace(str[count])){
				count++;
			}
      unsigned int index = 0;
			 while(str[index + count] != '\0'){
				 str[index] = str[index + count]; // replace str[index] = str[index + num white space char], for C string "  abc", str[0] = str[2] and so on
				 index += 1;
			 }

			str[strlen(str)  - count] = '\0'; // erases remaining part once it has been copied


  } // end white space processing

} // end trim function