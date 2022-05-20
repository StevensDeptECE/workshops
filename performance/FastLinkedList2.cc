#include <memory.h>
#include <memory>
#include <cstdint>
using namespace std;

/*
	Linked lists are optimal when inserting in the middle of lists.
	vector is optimal when inserting at the end
	But Linked lists use many allocations of small chunks of memory.

	Each new takes 8 bytes extra to store the size of the chunk, and the
	pointer ot the next element is another 8 bytes. For small objects,
	that can be a huge percentage of the data.

	What if you preallocate nodes in a giant array and just link them together?

	The following example is going to show faster performance than
	list<> for small values (integer)

	For simplicity, it is assumed that your type T either is a simple type without a constructor, or has a constructor T() that does not initialize objects.

	Without this, the code would get more complicated.
	We would have to allocate a chunk of char* memory and only initialize
	the objects using placement new.
 */
template<typename T>
class FastLinkedList {
private:
	struct Node {
		T val;
		uint32_t next;
		Node(const T& v, uint32_t next) : val(v), next(next) {}
	};
	uint32_t capacity;
	uint32_t size;
	Node* nodes;
	uint32_t head;

	/*
		Checkgrow has been written inline unreasonably fast.
		The main point is not how fast it is, but how infrequently 
		it needs to be called.
	 */
	void checkGrow() {
		if (size < capacity)
			return;
		// need to grow
		const Node* temp = nodes;
		nodes = (Node*)malloc(capacity *2 * sizeof(Node));
		memcpy(nodes, temp, capacity * sizeof(Node)); //Note: not ok for T with constructors, pointers
		free ((char*)temp);
		capacity *= 2;
	}
public:
	FastLinkedList(uint32_t capacity)
		: capacity(capacity),
			nodes((Node*)malloc(capacity*sizeof(Node))), size(0), head(0) {}

	void addStart(const T& v) {
		checkGrow();
		nodes[size] = Node(v, head); head = size++;
	}
	
	// insert in the list after position pos
	void insertAfter(uint32_t pos, const T& v) {
		nodes[size] = Node(v, nodes[pos].next);
		nodes[pos].next = size;
		size++;
	}
	~FastLinkedList() {
		for (int i = 0; i < size; i++)
			nodes[i].val.~T(); // manually call destructor
		free((char*)nodes);
	}
};

int main() {
	constexpr int n = 100000000; //10e8
	FastLinkedList<int> a(2*n);
	for (int i = 0; i < n; i++)
		a.addStart(i);
	for (int i = 0; i < n; i++)
		a.insertAfter(n/2, i);
}
