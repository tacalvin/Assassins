#! /usr/bin/python3
class Player:
	def __init__(self,name,email,pin,kills,status):
		self.status = status
		self.name = name
		self.email= email
		self.pin = pin
		self.kills = kills
	def addAssassins(killer,target):
		self.killer = killer
		self.target = target
	def kill(pin,self,target):
		if self.status == true:
			target.die(pin,self)
			print ("killed")

	def die(pin,killer):
		if pin == self.pin and self.killer == killer:
			self.status = False
			return True	
	

print ("Hellow")
p1 = Player(self,"calvin","tacalvin@yahoo.com","1",0,True)

p2 = Player(self,"bill","tacalvin@yahoo.com","2",0,True)
p3 = Player(self,"joe","tacalvin@yahoo.com","3",0,True)
p1.addAssassins(p2,p3)
p2.addAssassins(p3,p1)
p3.addAssassins(p1,p2)
	
p1.kill(p3.pin,self,p3)
