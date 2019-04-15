# flyweight
- Flyweight pattern has structural purppose, applies to objects and uses sharing to support large numbers of fine-grained objects effeciently.
- The pattern can be used to reduce memory usage when you need to create a large number of similiar object

# when to use
- when one instance of a class can be used to provide many "virtual instances"
- when all of the following are true:
  + an application uses a large number of objects
  + storage costs are high because of the sheer quantity of objects
  + most object state can be made extrinsic
  + many groups of objects maybe replaced by reatively few shared objects one extrinsic state is removed
  + the application doesn't depent on object identity