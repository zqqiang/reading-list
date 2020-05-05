# Distributed Monolith Antipattern

[Don’t Build a Distributed Monolith](https://www.microservices.com/talks/dont-build-a-distributed-monolith/)

## Goal

Not couple your systems with binary dependencies

# part 1

### shared libraries and network clients

Shared libraries are often called “the platform”. They’re often called “the core” or “platform core”  
The network clients are the official variety, the form that you cannot talk to the service unless you use their official client

### smell of monolith

You have hundreds of libraries that are required to run a system

### some ideas

However, over time, you will find that there are different services that are served better by different languages, or there are different skill sets that you can hire or who feel more comfortable in different languages

Individual team adopt a new technology or platform without convincing a central authority

### benefits of microservice architecture

We can avoid coupling the producer, the service, from the consumers, so that when one changes the other ones don’t all have to change

### solutions

Contracts and protocols  
In particular, just like our programming languages have interfaces and APIs  
Services should hide all their implementation details and expose data contracts and network protocols

## part 2

### protocols and contracts

The key is that the existence of the protocols and the contracts allow new stacks to be built

### Swagger

It is actually evolving into the OpenAPI initiative
It is actually very powerful and comes with a lot of tools for creating documentation and  
browsing it and playing with the APIs, and generating clients in lots of different languages

### Quark

Quark by DataWire, who’s hosting us today, is doing some really interesting work in this one

### beyond request/response

And so something that I’m exploring a lot is being able to move beyond just a request/response get,  
and being able to represent in our definitions single responses, multi-responses, a finite number of Ns,  
so if it’s always a page of 10, or infinite response streams for push subscriptions.

### architecture for the whole system

I’m not okay with it taking these systems and saying,  
“My entire company’s entire architecture is going to basically adopt one of these huge frameworks.”
