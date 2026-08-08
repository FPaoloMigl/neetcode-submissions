class Node:
    def __init__(self, value, next_node=None):
        self.value = value
        self.next = next_node

class LinkedList:
    
    def __init__(self):
        # to keep track of the linked list we need to pointers
        # tail and head plus we can use a dummy node to 
        # avoid edge case
        self.head = Node(-1)
        self.tail = self.head # both at the same position

    
    def get(self, index: int) -> int:
        # to iterate over the linked list at index "index"
        # we need to set curr node
        curr = self.head.next # because in case we are at the dummy node we need to skip it
        i = 0

        while curr:
            if i == index:
                return curr.value
            i += 1
            curr = curr.next
        return -1 #Index out of bounds

    def insertHead(self, val: int) -> None:
        # here we'll understand the advantage of dummy node
        new_node = Node(val)
        new_node.next = self.head.next
        self.head.next = new_node
        if not new_node.next: # if list is empty
            self.tail = new_node

    # This works for both empty and not empty list
    def insertTail(self, val: int) -> None:
        self.tail.next = Node(val)
        # here we move our pointer
        self.tail = self.tail.next

    def remove(self, index: int) -> bool:
        curr = self.head # H --> Node --> Node --> Tail
        i = 0

        while curr and i < index:
            i += 1
            curr = curr.next
    
        # i == index
        # remove the node
        # curr is the node before the target, while curr.next is the target node
        if curr and curr.next:
            if curr.next == self.tail: # edge case in which the target is the tail
                                        # so we update the tail
                self.tail = curr
            curr.next = curr.next.next
            return True
        return False

    def getValues(self) -> List[int]:
        output = []
        curr = self.head.next
        
        while curr:
            output.append(curr.value)
            curr = curr.next
        return output
