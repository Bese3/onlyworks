SinglyLinkedList = __import__('singly_linked_list').SinglyLinkedList
Node = __import__('singly_linked_list').Node

sll = SinglyLinkedList()
sl = Node()
sll.appendmiddle(2)
sll.append(3)
sll.append(4)
sll.append(6)
sll.append(8)
sll.appendleft(1)
sll.appendleft(0)



a = sll.size()
a = a + 1 - 1
print(sll)
# print(sl)
print("Size of Linked List is {:d}" .format(a))