class Node:
    def __init__(self, data, next_node=None):
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
        return ("<" + str(self.__data) + ">")
class SinglyLinkedList:
    def __init__(self):
        self.__head = None

    def sorted_insert(self, value):
      
        new = Node(value)
        if self.__head is None:
            self.__head = new
        elif self.__head.data > value:
            new.next_node = self.__head
            self.__head = new
        else:
            tmp = self.__head
            while (tmp.next_node is not None and
                    tmp.next_node.data < value):
                tmp = tmp.next_node
            new.__next_node = tmp.next_node
            tmp.next_node = new

        print(self.__head) 

        
    def __str__(self):
        list = []
        curr = self.__head
        while curr is not None:
            list.append(str(curr.data))
            curr = curr.next_node
        return ('\n' .join(list))         

