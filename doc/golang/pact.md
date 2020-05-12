# Pact

Pact is a code-first tool for testing HTTP and message integrations using contract tests.  
Contract tests assert that inter-application messages conform to a shared understanding that is documented in a contract.

## How Pact works

Before we deploy to production we need make sure our application works correctly with integrated application.  
Traditionally we run integration tests using live deployed applications.

We also can use simulator version of the other application.  
But this does not give us confidence to release because we can't make sure everything works as real world.

Pack solves this problem by keeping the two sets of tests in sync by use of a contract.  
Durning consumer tests each request made to simulator is recorded in to a contract file, along with its expected response.

A pack simulated consumer then replays each request against real application and compare the actual response with expected one.  
If they are the same we have verified and have confidence.

## Contract testing

technique for testing an integration point by checking each application in isolation  
to ensure the messages it sends or receives conform to a shared understanding that is documented in a "contract".

Contract testing is immediately applicable anywhere where you have two services that need to communicate.  
Contract testing is the killer app for microservice development and deployment.
