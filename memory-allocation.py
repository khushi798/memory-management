
#stack memory 
#The methods/method calls and the references are stored in stack memory .
#work of a stack matrix
#The allocation happens on contiguous blocks of memory. We call it stack memory allocation
#because the allocation happens in the function call stack. The size of memory to be allocated
#is known to the compiler and whenever a function is called, its variables get memory allocated on the stack.
#Here is one example:
def func():
		
	# All these variables get memory
	# allocated on stack
	a = 20
	b = []
	c = ""


#Heap memory
#The memory is allocated during the execution of instructions written by programmers.
# The variables are needed outside of method or function calls or are shared within multiple
# functions globally are stored in Heap memory.
#Here is one example:

# This memory for 10 integers
# is allocated on heap.
a = [0]*10
