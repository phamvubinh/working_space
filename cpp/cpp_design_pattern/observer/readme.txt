### Observer

Observer define a one to many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

The pattern has behavioral purpose and applies to the objects

## When to use
* When an abstraction has two aspects, one denpendent on the other
* When a change to one objcet requires changing others, and you don't know how many objects need to be changed
* When an object should be able to notify other objects without making assumptions about who these objects are