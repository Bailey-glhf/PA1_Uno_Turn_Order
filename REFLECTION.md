Reflection Questions

1. Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?


    Concat only needs to work between lists of the same representation because arrays do not 
    work with the nodes and points and likewise linklists would not be able to read in without 
    the nodes and pointers. Without the dynamic cast it would crash. To prevent a crash while
    having it work between different types we would have to manually loop through and copyeach 
    value from either list into the other type.

2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.


    To walk through reverse() for linked list the three pointers are previous, current, and next.
    Current is used for selecting nodes, next is keeping the rest of the list connected while we
    start flipping pointers, and previous is used to flip the pointers back where it came from.
    Losing track of current would mean losing our spot in the list, losing track of next will
    mean losing track of the original list all together, and losing track of previous means we 
    could mess up the pointer direction and not actually end up reversing.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?


    AddAnywhere's valid range is from 0 to size inclusive, at 0 it performs addFront and at size addBack
    outside of this range it prints an Invalid error message. DeleteAnywhere's valid range is from 0 to 
    size-1 inclusive, at 0 it performs deleteFront and at size-1 deleteBack outside of this range it prints 
    another Invalid error message. Both return early after error message without altering list to prevent 
    crash or messing up the list data.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if LinkedList still 
   tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?


    I actually did include a tail pointer for my LinkedList concat function, but I will go back an
    implement the code without a tail pointer. Without a tail addFront and deleteFront never need
    to walk back because they alter the list from the head pointer but with concat we need to make
    alterations by adding to the back of the list. Without a tail you have to walk to the end taking O(n) 
    with a loop but with a tail we can point it at our added lists head and just update the pointers and 
    size with O(1). Including a tail pointer would mean updating addFront, deleteFront, addBack, deleteBack,
    reverse functions and any functions that call of those who make use of the tail pointer.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.


    In the ArrayList addAnywhere when you insert you have to start at the right most end of the array and
    shift the last element to the right. Then do the same with the next element to the left moving
    inward until you've shifted over the element from the position you want to insert at. This makes
    room for the new insert but by starting at the end first for the shift it also makes sure that we
    don't end up overwriting our List data before we've had a chance to shift it.
    
6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.


    In main the reverse card is played at tableOne->reverse();. If the reverse call was missing then
    the list would never reverse and the print function would display as it did on the previous print.
    When reverse is called in LinkedList the line that actually reverses the pointers is
    current->next = previousOne; and within ArrayList the line that swaps the elements is
    data_[i] = data_[size_ - 1 - i];. Arraylist still requires temp variable to save elements and 
    LinkedList still requires additional pointers to track nodes in order to fully complete a 
    reverse. Without these lines the reverse function could lose data or break the LinkedList or
    overwrite data on the ArrayList.