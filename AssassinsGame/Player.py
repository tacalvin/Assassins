#! /usr/bin/python3
class Player:
	def __init__(self,name,email,target,killer,pin,kills,status):
		self.status = status
		self.name = name
		self.email= email
		self.target = target
		self.killer = killer
		self.pin = pin
		self.kills = kills
	
	def kill(pin,self,target):
		if self.status == true:
			target.die(pin,self)
			print ("killed")

	def die(pin,killer):
		if pin == self.pin and self.killer == killer:
			self.status = False
			return True	
	
def main():
	print ("Hellow")
	p1 = Player(self,"calvin","tacalvin@yahoo.com",p2,p3,"1",0,True)
	p2 = Player(self,"bill","tacalvin@yahoo.com",p3,p1,"2",0,True)
	p3 = Player(self,"joe","tacalvin@yahoo.com",p1,p2,"3",0,True)
	
	p1.kill(p3.pin,self,p3)
