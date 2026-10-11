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
3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?


    answer
4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if LinkedList still 
   tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?


    answer
5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.


    answer
6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.


    answer