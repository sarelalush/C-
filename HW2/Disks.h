//
// Created by sarel on 08/04/2021.
//

#ifndef HW2_DISKS_H
#define HW2_DISKS_H

enum colorDisk{Black,White};
class Disks {
    private:
        colorDisk color;
        int numberOfDisks;
    public:
        Disks();
        //this function return number of disks
        //input: none
        // output : number of disks
        int getNumberOfDisks()const;
        //this function set number of disks
        //input: disks number
        // output : none
        void setNumberOfDisks(int num);
        //this function return color of disks
        //input: none
        // output : color disks
        colorDisk getColorOfDisks()const;
        //this function set color of disks
        //input: color
        // output : None
        void setColorOfDisks(colorDisk num);
        //this function increment number of disks
        //input: none
        // output : None
        void incNumberOfDisks();
        //this function decrement number of disks
        //input: none
        // output : None
        void decNumberOFDisks();
};


#endif //HW2_DISKS_H
