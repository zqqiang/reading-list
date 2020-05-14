# Deno.js

A secure runtime for JavaScript and TypeScript (TypeScript is a typed superset of JavaScript that compiles to plain JavaScript).  
The Node.js author Ryan Dahl leave and create the Deno.js which means de-node.js.

## Features

Secure by default. No file, network, or environment access, unless explicitly enabled.  
Ships only a single executable file.

## Node.js design shortcomings

a poorly designed module system, with centralized distribution;  
lots of legacy APIs that must be supported;  
and a lack of security.

## The way Deno improves

By default, Deno won’t let a program access disk, network, subprocesses, or environmental variables.  
It always dies on uncaught errors, unlike Node.js, which will allow execution to proceed after an uncaught error, with results that may not be predictable.  
Deno modules can be hosted anywhere – there is no centralized repository for third-party modules.

Dahl wrote his prototype of Deno primarily in the Go language, but discovered potential conflicts between the garbage collectors in Go and V8.  
He and his collaborators then rewrote Deno proper with V8, Rust, and the Rust asynchronous I/O package Tokio.  
They implemented the Deno standard library in TypeScript.

Rust (Deno’s core was written in Rust, Node’s in C++)  
Tokio (the event loop written in Rust)  
TypeScript (Deno supports both JavaScript and TypeScript out of the box)  
V8 (Google’s JavaScript runtime used in Chrome and Node, among others)

Deno, just like browsers, loads modules by URLs. No more package.json and node_modules.  
By using URLs, Deno packages can be distributed without a centralized registry such as npm.
