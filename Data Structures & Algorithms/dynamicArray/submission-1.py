class DynamicArray:
    
    def __init__(self, capacity: int):
        self.capacity = capacity # member variables
        self.size = 0 # used to track how many values in the array
        self.arr = [0] * self.capacity

    def get(self, i: int) -> int:
        return self.arr[i]

    def set(self, i: int, n: int) -> None:
        self.arr[i] = n

    def pushback(self, n: int) -> None:
        # check if the array is full to prevent Out Of Bound
        if self.size == self.capacity:
            self.resize()
        
        self.arr[self.size] = n
        self.size += 1

    def popback(self) -> int:
        # soft deletion because it doesn't remove the element
        self.size -= 1
        return self.arr[self.size]

    def resize(self) -> None:
        self.capacity = 2 * self.capacity
        new_arr = [0] * self.capacity

        # copy the values in the new array
        for i in range(self.size):
            new_arr[i] = self.arr[i]
        self.arr = new_arr




    def getSize(self) -> int:
        return self.size
    
    def getCapacity(self) -> int:
        return self.capacity