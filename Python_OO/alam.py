from clock import *

class AlarmClock(Clock):

    def __init__(self,hours,mins,secs,aHour,aMin,aSec):
        super().__init__(hours,mins,secs)
        self.aHour = aHour
        self.aMin = aMin
        self.aSec = aSec

    #def tick(self):
        
        if self.hours == self.aHour and self.mins == self.aMin and self.secs == self.aSec:
           print("Alarm, get up!!!")
        super().tick()

    def __repr__(self):
        return f"alarm clock: {super().__repr__()}"

if __name__=='__main__':
    c = AlarmClock(10,20,50,10,20,55)
    c2 = Clock(11,55,10)

    arr = [c,c2]

    while True:
        for clock in arr:
            print(clock)
            clock.tick()
            time.sleep(1)