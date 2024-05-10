# minitalk
## A project exploring sending and receiving Unix signals.

I completed this project as part of my studies at Hive Helsinki. 

To compile, run 'make'. The makefile will create two executables (*server* and *client*). Run *server* first and copy the process ID (PID) displayed in the terminal. Then, run *client* in another terminal with the PID and message to be sent. The server will then print out the message and remain open to receive more messages until it is closed with ctl+z.

To compile the bonuses, run 'make bonus'. The executables *server_bonus* and *server_client* will be created and can be run as above. The server will send a signal back to the client to confirm receipt of the message and the client will print out a confirmation message.
