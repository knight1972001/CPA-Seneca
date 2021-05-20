Complete the following program by coding a class named Shipment and a global function named AddHST.
 
Your AddHST function receives in its parameters iterators to the beginning and end of a range of Trucks.
 
    for each Truck in the range, this function adds HST to the price data member and stores the result in the price_w_tax data member.
 
Your Shipment class includes the following members:
 
    an STL container that holds Truck objects
    a pointer to a function that receives a reference to an unmodifiable STL container of Truck objects and returns nothing
 
    a boolean flag that holds true only if all objects in the container have their tax calculated.
 
    an overloaded += operator that adds a Truck object to the container, sets the boolean flag to false and returns a reference to the current Shipment object only if the ratio of the payload to the price (payload/price) for that Truck object is greater than or equal to the cutoff ratio (payload/price >= PP_RATIO).
        if the ratio is less than the cutoff ratio, then this operator changes nothing and throws an exception.
        update main to handle the exception by printing a message as shown in the sample output below.
 
    a setDisplay function that receives the address of a callback function that displays requested data (byModel or byPayload), stores that address in the current object and returns nothing.
 
    a display function with no explicit parameters that returns nothing and displays the requested data using the callback function.
        If any data in the container has not been taxed, before printing anything, this function adds the tax using the AddHST function and two threads. Each thread processes half of the Truck objects from the container.
        If a callback function is not registered with the current object, this member function terminates the application with error code 33.
 
Lastly, upgrade the main function of the program to use a smart pointer