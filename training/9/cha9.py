
__metaclass__ = type
class Bird:
    count = 0
    def __init__(self):
        self.hungry=True
        self.count+=1
        print ('my count is ', self.count)
    def eat(self):
        if self.hungry:
            print ('Ahhhhh.....')
            self.hungry=False
        else:
            print ('I dont need')

class SongBird(Bird):
    def __init__(self):
        super(SongBird,self).__init__()
        self.sound = 'Squawk!'
    def sing(self):
        print (self.sound)

if __name__ == '__main__':
    sb=SongBird()
    print Bird.count
    sb.sing()
    sb.eat()
    sb.eat()
    sb1=SongBird()
    print Bird.count
    sb1.eat()
    sb1.eat()