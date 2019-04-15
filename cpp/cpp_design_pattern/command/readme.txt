#Command 

Comand pattern excapsulates a request as an object, thereby letting you parameterize clients with different request, queue or log requests, and support undoable operations. The pattern has a behavioral purpose and deals with relationships between objects.

#when to use
* want to parameterize objects by an action to perform
* want to specify, queue, and execute requests at different times
* support undo
* support logging changes so that they can be reapplied in case of a system crash 
* structure a system around high level operations built on primitives operations