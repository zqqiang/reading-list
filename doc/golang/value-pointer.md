# [Design Philosophy On Data And Semantics](https://www.ardanlabs.com/blog/2017/06/design-philosophy-on-data-and-semantics.html)

Value semantics keep values on the stack, which reduces pressure on the Garbage Collector (GC).  
However, value semantics require various copies of any given value to be stored, tracked and maintained.

Pointer semantics place values on the heap, which can put pressure on the GC.
However, pointer semantics are efficient because only one value needs to be stored, tracked and maintained.

A consistent use of value/pointer semantics, for a given type of data,  
is critical if you want to maintain integrity and readability throughout your software.  
Why? Because, if you are changing the semantics for a piece of data as it is passed between functions,  
you are making it difficult to maintain a clear and consistent mental model of the code.

## Debugging

The hardest bugs are those where your mental model of the situation is just wrong,  
so you can’t see the problem at all

If you have a problem in production, what are you going to ask for?  
That’s right, the logs. If the logs are not working for you during development,  
they are certainly not going to work for you when that production bug hits.  
Logs require having a mental model of the code base, such that you can read code to find bugs.

## Readability

C is the best balance I’ve ever seen between power and expressiveness.  
You can do almost anything you want to do by programming fairly straightforwardly  
and you will have a very good mental model of what’s going to happen on the machine;  
you can predict reasonably well how quickly it’s going to run, you understand what’s going on

I believe this quote by Brian applies just as well to Go.  
Maintaining this “mental model” is everything.

These are the cornerstones of well-written software that allow it to be maintained  
and last over time. Writing code that maintains a consistent use of value/pointer semantics  
for a given type of data is an important way to achieve this.

## Data Oriented Design

If you don’t understand the data, you don’t understand the problem.  
This is because all problems are unique and specific to the data you are working with.  
When the data is changing, your problems are changing.  
When your problems are changing, the algorithms (data transformations) needs to change with it.

A “less is more” attitude is critical to solving problems  
with fewer layers, statements, generalizations, less complexity and less effort.

## Data (With Capability)

Methods are valid when it is practical or reasonable for a piece of data to have a capability.

The purpose of methods is to give a piece of data capability.

## Built-In Types

Go’s built-in types represent numeric, textual and boolean data.  
These types should be handled using value semantics.

## Reference Types

Reference types represent the slice, map, interface, function and channel types in the language.  
These types should be using value semantics  
because they have been designed to stay on the stack and minimize heap pressure.

### List 11

When a function shares a value with you, you should assume that  
you are not allowed to make a copy of the value pointed to by the pointer.  
If you do, results will be undefined.

## Conclusion

The consistent use of value/pointer semantics is something I look for in code reviews.  
It helps you keep code consistent and predictable over time.  
It also allows everyone to maintain a clear and consistent mental model of the code.  
As the code base and the team gets larger, consistent use of value/pointer semantics  
becomes even more important.
