#include "SDCardControlTask.hpp"

SDCardControlTask::SDCardControlTask()
    : ControlTask()
    {

        SD.begin(chipSelect);
        myFile = SD.open("data.txt", FILE_WRITE);
        
    }

void SDCardControlTask::execute(){

    if(myFile){
        // myFile.printf("------------------------------------------------\n");
        // myFile.printf("Control Cycle: %u\n", control_cycle_count);

        // myFile.printf("Euler: (");
        // myFile.print(euler_deg_p->get()(0));
        // myFile.print(",");
        // myFile.print(euler_deg_p->get()(1));
        // myFile.print(",");
        // myFile.print(euler_deg_p->get()(2));
        // myFile.print(")\n");

        // myFile.printf("Altitude:");
        // myFile.print(position_dp->get()(0));
        // myFile.printf("\n");

        // myFile.printf("Body Vertical Acceleration:");
        // myFile.print(lin_acc_vec_fp->get()(0)-acc_error_fp->get()(0));
        // myFile.printf("\n");

        // myFile.printf("Commanded Accelerations: (");
        // myFile.print(a_com_p->get()(0));
        // myFile.print(",");
        // myFile.print(a_com_p->get()(1));
        // myFile.print(",");
        // myFile.print(a_com_p->get()(2));
        // myFile.print(")\n");

        // myFile.printf("Fin Commands: (");
        // myFile.print(fin_commands_fp->get()(0));
        // myFile.print(",");
        // myFile.print(fin_commands_fp->get()(1));
        // myFile.print(",");
        // myFile.print(fin_commands_fp->get()(2));
        // myFile.print(",");
        // myFile.print(fin_commands_fp->get()(3));
        // myFile.print(")\n");

        // myFile.printf("Motor Commands: (");
        // myFile.print(thrust_commands_fp->get()(0));
        // myFile.print(",");
        // myFile.print(thrust_commands_fp->get()(1));
        // myFile.print(")\n");
    }
    myFile.flush();
}

void SDCardControlTask::actuate(){

}