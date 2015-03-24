// Playground - noun: a place where people can play

import UIKit

class PID {
	var value : Double = 0.0
	var goal : Double = 0.0
	
	var p_gain : Double = 0.0
	var i_gain : Double = 0.0
	var d_gain : Double = 0.0
	
	
	/// Internal Parameters
	var lastError : Double = 0.0
	var error : Double = 0.0
	var adjustment : Double = 0.0

	var p : Double = 0.0
	var i : Double = 0.0
	var d : Double = 0.0

	func update() {
		calculateError()
		calculateP()
		calculateI()
		calculateD()
		mix()
	}
	
	func calculateError() {
		lastError = error
		error = goal - value
	}
	
	func calculateP() {
		p = error
	}
	
	func calculateI() {
		i += error
	}
	
	func calculateD() {
		d = error - lastError
	}
	
	func mix() {
		var adjustedP = p * p_gain
		var adjustedI = i * i_gain
		var adjustedD = d * d_gain
		adjustment = adjustedP + adjustedI + adjustedD
	}
};

func Min(A: Double, B: Double) -> Double {
	if abs(A) < abs(B) {
		return A
	}
	else if abs(B) < abs(A) {
		return B
	}
	
	return 0.0
}

class Plant {
	var location : Double = 0.0
	var goal : Double {
		set {
			self.pid.goal = newValue
		}
		get {
			return self.pid.goal
		}
	}
	
	var velocity : Double = 0.0
	
	var accelerationMax : Double = 50.0
	var deccelerationMax : Double = -50.0
	
	var drag : Double = 0.05
	
	private var pid : PID
	
	init() {
		pid = PID()
		pid.p_gain = 100
//		pid.i_gain = 1
		pid.d_gain = 1000
	}
	
	func transfer(input: Double, deltaTime: Double) {
		var acceleration = (input < 0) ? Min(input * deltaTime, deccelerationMax) : Min(input * deltaTime, accelerationMax)
		
		var _velocity = (velocity + acceleration) * (1.0 - drag)
		velocity = _velocity
		
		var _location = location + (velocity * deltaTime)
		location = _location
	}
	
	func update(deltaTime: Double) {
		pid.value = location
		pid.update()
		transfer(pid.adjustment, deltaTime: deltaTime)
	}
};




//// Test usage
var particle = Plant()
particle.goal = 100

var lastTime = NSDate.timeIntervalSinceReferenceDate()
var startTime = lastTime

for i in 0...100{
	var currentTime = NSDate.timeIntervalSinceReferenceDate()
	var deltaTime = currentTime - lastTime
	particle.update(deltaTime)
	lastTime = currentTime
	
//	particle.goal += 5
	particle.drag = (0.1 * (Double(arc4random()) / Double(UINT_MAX)))
	
	if	i == 50 {
//		particle.goal = 0
	}
}

var length = NSDate.timeIntervalSinceReferenceDate() - startTime


