
NODE.JS

Node is an open source runtime environment for executing JavaScript code outside the browser.
Node is often used to build backend services also known as API's (Application Programming
Interfaces). This power the client applications such as Web Apps and Mobile Apps. 

Tose client applications need to communicate with the backend service to supply all demands.
Node is used to build highly-scalable, data-intensive and real-time apps. 
It's great for prototyping and agile developement.
It's superfast and highly scalable and uses JavaScript (both in frontend and backend).

NODE ARCHITEECTURE

Every browser has a JS engine that transforms JS code into machine code. Each browser has it's
own JS engine.
	Edge uses chackra
	Motzilla uses SpiderMonkey
	Chrome uses v8

Node is a C++ program has V8 engine embedded + some additional features that allow other
functionalities.
Node is not a programming language or framework, it's a runtime environment for executing
JavaScript code. 


HOW NODE WORKS

Node has Asynchronous (non blocking) architecture. That means that a single thread is used to
handle multiple requests.

When a request is received on the server, a thread is allocated to serve that requests. 
In node you have a sinnglee thread to handle all requests. When a request araises, that single
thread is used to handle that request. It it needs to query a database, our thread doen't need 
to waint for the database to return the data. Instead, while the database is executing our query, that thread will be used to serve another client.

When the database prepares the result, it puts a message in what we call an Event Queue.
Node is continously monitoring this queue in the background. When it finds an event in this
queue it will take it out and process it.

This kinf of architecture makes node ideal for building applications that include a lot of disk
or network access (I/O-intensive apps). 