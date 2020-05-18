# OpenTracing

## Overview

Microservices provides a powerful architecture, but not without its own challenges, especially with regards to debugging and observing distributed transactions across complex networks — simply because there are no in-memory calls or stack traces to do so.

Distributed tracing provides a solution for describing and analyzing the cross-process transactions.

## What is Distributed Tracing?

Distributed tracing, also called distributed request tracing, is a method used to profile and monitor applications, especially those built using a microservices architecture.

Distributed tracing helps pinpoint where failures occur and what causes poor performance.

## What is a Span?

The “span” is the primary building block of a distributed trace, representing an individual unit of work done in a distributed system.

Each component of the distributed system contributes a span.

Spans can (and generally do) contain “References” to other spans, which allows multiple Spans to be assembled into one complete Trace - a visualization of the life of a request as it moves through a distributed system.

## Tracers

OpenTracing abstracts away the differences among numerous tracer implementations.  
This means that instrumentation would remain the same irrespective of the tracer system being used by the developer.
