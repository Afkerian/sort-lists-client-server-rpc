#sort-list-client-server-rpc

all:	client server 

client:	client.c 
	cc -o client client.c

server:	server.c 
	cc -o server server.c

clean:
	rm	server  client
