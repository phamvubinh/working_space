#Factory method

Define an interface for creating an object, but let subclasses decide which class to instantiate
Factory method lets a class defer instantiation to subclasses. THe pattern has creational purpose
and applies to classes where deals with relationships through inheritence ie. they are static-fixed at compile time. 
In constrast to Abstract Factory, Factory method contain method to produce only one type of product.

# when to use
* a class cant anticipate the class of objects it must create
* a class wants its subclasses to specify the objects it creates
* classes delegate responsbility to one of serveral helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate