# Protocol Buffer

## What are protocol buffers?

Protocol buffers are Google's mechanism for serializing structured data.  
Smaller, faster, and simpler than XML.

You define how you want your data to be structured once,  
then you can use special generated source code to easily write and read your structured data  
to and from a variety of data streams and using a variety of languages.

# gRPC

## Overview

In gRPC, a client application can directly call a method on a server application  
on a different machine as if it were a local object, making it easier for you  
to create distributed applications and services.

gRPC is based around the idea of defining a service,  
specifying the methods that can be called remotely with their parameters and return types.

On the server side, the server implements this interface  
and runs a gRPC server to handle client calls. 

On the client side, the client has a stub that provides the same methods as the server.

## Working with Protocol Buffers

By default, gRPC uses Protocol Buffers, Google’s mature open source mechanism  
for serializing structured data (although it can be used with other data formats such as JSON).