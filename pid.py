class P_controller:
    def __init__(self):
        self.Kp=0.1
    def P_action(self,error):
        return self.Kp*error
class I_controller:
    def __init__(self):
        self.Ki=0.1
        self.totalError=0
    def I_action(self,error):
        self.totalError+=error;
        return self.Ki*self.totalError
class D_controller:
    def __init__(self):
        self.Kd=0.1
        self.prev_error=0
    def D_action(self,error,t):
        error_dif=error-self.prev_error
        self.prev_error=error
        return self.Kd*error_dif/t
class PID_controller:
    def total_action(self,P_controller,I_controller,D_controller,error,timestep):
        return P_controller.P_action(error)+I_controller.I_action(error)+D_controller.D_action(error,timestep)



