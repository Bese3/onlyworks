import doctest
 
class Node:
    def __init__(self, data=None, next_node=None):
         self.__data = data
         self.__next_node = next_node
    @property
    def data(self):
        return self.__data
    @property
    def next_node(self):
        return self.__next_node
    @data.setter
    def data(self , value):
        if type(value) is not int:
            raise TypeError("data must be an integer")
        else:
            self.__data = value
    @next_node.setter
    def next_node(self , value):
        if not isinstance(value , Node):
            raise TypeError("next_node must be a Node object")
        else:
            self.__next_node = value
    def __str__(self):
        return ("" + str(self.__data) + "")
class SinglyLinkedList:
    def __init__(self):
        self.__head = Node()
    def append(self , value):
        new = Node(value)
        curr = self.__head
        while curr.next_node != None:
            curr = curr.next_node
        curr.next_node = new
        curr = new
    def size(self):
        size  = 0
        curr = self.__head
        while curr.next_node != None:
            curr = curr.next_node
            size +=1
        
        return size
    def appendleft(self , value):
        new = Node(value) 
        if self.__head.next_node is None:
            self.__head.next_node = new
            return 
        
        curr = self.__head.next_node        
        self.__head.next_node = new
        new.next_node = curr
    def appendmiddle(self, value):
        new = Node(value)
        if self.__head.next_node is None:
            self.__head.next_node = new
            return
        curr = self.__head.next_node
        new.next_node = curr.next_node
        curr.next_node = new
               
    def reverse(self):
        if self.__head.next_node is None:
            return
        prev  = Node()
        curr = self.__head
        while curr is not None:
            next = curr.next_node
            curr.next_node = prev
            prev = curr
            curr = next
        
        self.__head = prev
    def sorted_insert(self , value):
        new = Node(value)
        if self.__head.next_node is None:
            SinglyLinkedList.append(self , value)
            return
        
        curr = self.__head.next_node
      
        while curr.next_node is not None:
            if curr.next_node.data > new.data and curr.data < new.data:
                SinglyLinkedList.appendmiddle(self , value)
                # print("in the if")
                return
            curr = curr.next_node
        SinglyLinkedList.append(self , value)

        
  
    def __str__(self):
        list = []
        curr = self.__head
        while curr is not None:
            if (curr.data) != None:
               list.append(str(curr.data))
            curr = curr.next_node
        return str(list)
        # return ('\n' .join(list))         
    

