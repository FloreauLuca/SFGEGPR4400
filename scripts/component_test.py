from SFGE import *
import sys
import random

class ComponentTest(Component):
    def init(self):
        #print("Init ComponentTest with "+str(self.game_object))
        self.timer = Timer(1.0,1.0)
        
        
    def update(self, dt):
        print("Hello update from Python with dt: "+str(dt))
        self.timer.update(dt)
        if(self.timer.is_over()):
            print("Timer over, reset")
            self.timer.reset()
    
    def __del__(self):
        sys.stderr.write("DELETING COMPONENT TEST PYTHON\n")
        sys.stderr.flush()
            