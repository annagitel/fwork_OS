to run the program:
1. open terminal and run `ps aux`, pick ine of the last processes and copy its PID
2. open another terminal and run `make`, a "check_pid" exe file will be created
3. run `./check_pid <process_pid> ` where process_pid is the PID you chose in step 1  
expected outputs: "Process <process_pid> exists"
4. run `./check_pid <process_pid> ` where process_pid is just a random number   
expected outputs: "ESRCH returned. <process_pid> does not exist"

* code run example can be found in the PDF file
