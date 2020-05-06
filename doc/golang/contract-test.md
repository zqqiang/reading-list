# [Contract Tests vs Functional Tests](https://docs.pact.io/consumer/contract_tests_not_functional_tests)

Contract tests focus on the messages that flow between a consumer and provider  
while functional tests also ensure that the correct side effects have occured

A contract test does not check for side effects

We've gone past the contract testing at this point,  
we're actually testing that the User Service implements the validation rules correctly:  
this is functional testing, and it should be covered by the User Service in its own codebase.

The issue here is that these scenarios are going too far and create an unnecessarily tight contract

When writing a test for an interaction, ask yourself what you are trying to cover.  
Contracts should be about catching:

bugs in the consumer  
misunderstanding from the consumer about end-points or payload  
breaking changes by the provider on end-points or payload

in short, your Pact scenarios should not dig into the business logic of the Provider  
but should stick with verifying that Consumer and Provider  
have a shared understanding of what requests and responses will be.

write scenarios about how the validation fails, not why the validation fails.
