class TestItrator:
    value = 0
    def next(self):
        self.value+=1
        if self.value>10:
            raise StopIteration
        return self.value
    def __iter__(self):
        return self

if __name__ == '__main__':
    ti = TestItrator()
    print ti
    li = list(ti)
    print li
    # nested = [[1,2],[3,4],[5]]
    