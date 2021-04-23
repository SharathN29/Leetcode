# https://leetcode.com/problems/moving-average-from-data-stream/

class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.queue = collections.deque(maxlen=size)

    def next(self, val: int) -> float:
        queue = self.queue
        queue.append(val)
        return float(sum(queue) / len(queue))


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
