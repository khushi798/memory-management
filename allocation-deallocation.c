/*In Cython, memory management is similar to C but with some additional features and conventions.
# Here are some important code snippets for memory allocation and deallocation in Cython:
#ALLOCATION*/

cdef int* myInt = <int*> malloc(sizeof(int))
//or
cdef int* myInt = <int*> PyMem_Malloc(sizeof(int))

//DEALLOCATION

free(myInt)
// or
PyMem_Free(myInt)

/*It's important to note that when using malloc or PyMem_Malloc to allocate memory in Cython,
it is the developer's responsibility to manually deallocate the memory using free or PyMem_Free
when it is no longer needed.

In Cython, it is also possible to use the cdef keyword to define variables that have a fixed memory
location, like in C. It is important to be careful when using cdef variables because they will not 
be garbage collected, so it is important to make sure they are deallocated when they are no longer 
needed.

*/
cdef int* myInt = <int*> malloc(sizeof(int))
cdef int* myInt2 = <int*> malloc(sizeof(int))
myInt2 = myInt
free(myInt)
// myInt2 still points to the memory that was freed, resulting in a memory leak.

/*In addition, Cython provides a way to use Python memory management by using memoryview. Memoryview 
is a built-in Cython type that allows you to work with memory in a more Pythonic way. It allows you to 
create an object that points to a specific memory location, which is automatically managed by Python's 
garbage collector.*/

cdef int[:] myInt = <int[:1]> PyMem_Malloc(sizeof(int))
// myInt is a memoryview, it will be automatically garbage collected.

/*It is important to note that when using memoryview, the memory is automatically managed by 
Python's garbage collector, so there is no need to explicitly deallocate the memory.

You should also be aware of the Python's Global Interpreter Lock (GIL) and it's impact on memory 
allocation and deallocation when working with Cython. Make sure to release the GIL
when doing heavy memory allocation or deallocation by using the nogil context manager.*/

cdef int* myInt
with nogil:
    myInt = <int*> malloc(sizeof(int))
    # do something with myInt
free(myInt)





