1. open two terminals 
2. in one of them run `make`, two exe files will be created - client & server 
3. in the same one, run `./server`, the output will be a PID - copy it
4. in the second terminal run `./client <PID> 2 <random_number>`  
	some lines will be printed in the first terminal
5. in the second terminal run `./client <PID> 10 1`  
	in the first terminal will be printed the number of SIGINT signals recived  
expected output - the number that was printed in the server is less than the number sent in step 4.  

* code run example can be found in the PDF file
