import matrix_lib
class P_controller:
    Kp=1
    def P_action(error):
        return Kp*error
class I_controller:
    Ki=1
    totalError=0
    def I_action(error):
        totalError+=error;
        return Ki*totalError
class D_controller:
    Kd=1
    prev_error=0
    def P_action(error):
        error_dif=error-prev_error
        prev_error=error
        return Kd*error_dif
class PID_controller:
    def total_action(P_controller,I_controller,D_controller,error):
        return P_controller.P_action(error)+I_controller.I_action(error)+D_controller.D_action(error)



