#### 1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one? Name exactly what each one frees, and name the two new calls back in the program responsible for putting them on the heap in the first place.
In LinkedList::deleteFront(), it takes two separate delete calls as the data and the node itself need to be deleted separately.
The first delete (delete doomed->data) is responsible in freeing the data the pointer (doomed) points to.
Meanwhile, the second delete below it (delete doomed) is responsible for freeing the actual node that doomed points to.
The two new calls responsible for putting them on the heap in the first place are "new int ()" (puts the data on the heap) and "new Node&lt;T&gt; value" (puts the node in the heap). 

#### 2. ArrayList never had a destructor before today. Explain, in your own words, why switching from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what would happen if you forgot to write one. Would you get a compiler error? Why or why not?
By switching from T data[CAPACITY] to T* data[CAPACITY] through the addition of an asterisk, we go from creating an array that stores actual objects/values of type T to creating an array of pointers that point to objects of type T.
This makes a destructor necessary because the pointers may be pointing to objects that will need to be destroyed in order to free up memory.
If you forgot to write a destructor, it would not cause a compiler error.
However, it would lead to unnecessary data/resources being stored in memory, which can make the program inefficient.

#### 3. search() and addFront() both take a T*, but they treat that pointer completely differently. Explain the difference in terms of ownership: which one is allowed to delete what you hand it, and which one is never allowed to?
The T* value taken in by addFront() is taken ownership of by the function and is used to create a node using that specified value, while the T* value taken in by search() is not taken ownership of by the function strictly used as a reference of what specific node the function is looking for in an array.
Therefore, addFront() is allowed to delete what you hand it, while search() is never allowed to.

#### 4. You swapped LinkedList&lt;T&gt; for ArrayList&lt;T&gt; inside makeList() and reran main.cpp without changing a single line there. What two mechanisms, by name, made that possible?
The two mechanisms that made that swap possible without changing a single line were: inheritance and polymorphism.
Inheritance was possible with the use of List&lt;T&gt;, and both ArrayList&lt;T&gt; and LinkedList&lt;T&gt; inheriting from it, allowing either to be treated as a List&lt;T&gt;.
On the other hand,  std::unique_ptr and std::make_unique create a unique pointer than can point to either an ArrayList&lt;T&gt; or a LinkedList&lt;T&gt;, allowing the pointer to refer to different derived classes and demonstrating polymorphism.

#### 5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have thought to add on your own (explicit, override, virtual, const, or any other). Describe, in your own words and without copying the guide’s wording, the smallest example you can think of where leaving it out would cause a real problem.
One keyword from the Key Terms glossary that I had to add today was "explicit", which in short, helps prevent vague and ambiguous  code as it stops implicit type conversions through constructors from occurring.
For instance, its use can solve the problem of passing a T* (a pointer) somewhere that expects a Node&lt;T&gt; (an actual node).
More specifically, a constructor can be written to accept a T*, but due to the absence of "explicit", C++ can automatically use the constructor to create a Node&lt;T&gt; from that T*, so by utilizing "explicit", it ensures that the conversion is done intentionally.

