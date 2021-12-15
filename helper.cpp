


#include "helper.h"
#include <iostream>
#define GRID_PTS 200 //trajectory grid point number
#define NUM 50

using namespace std;



std::vector<float> snake_path_x()
{
    int i;
    std::vector<float> pathx;

    for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.01*GRID_PTS);
    }
    for(i=GRID_PTS;i>0;i--){
        pathx.push_back((float) 0.01*i);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.01*i);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.01*GRID_PTS);
    }
    for(i=GRID_PTS;i>0;i--){
        pathx.push_back((float) 0.01*i);
    }
    
    for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.01*i);
    }
    
       for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.01*GRID_PTS);
    }
    for(i=GRID_PTS;i>0;i--){
        pathx.push_back((float) 0.01*i);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.01*i);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.01*GRID_PTS);
    }
    for(i=GRID_PTS;i>0;i--){
        pathx.push_back((float) 0.01*i);
    }
    
    for(i=0;i<GRID_PTS/8;i++){
        pathx.push_back((float) 0.0);
    }

    for(i=0;i>-GRID_PTS/8;i--){
        pathx.push_back((float) 0.01*i);
    }

    for(i=GRID_PTS;i>0;i--){
        pathx.push_back((float) -0.01*GRID_PTS/8);
    }

    for(i=-GRID_PTS/8;i<GRID_PTS;i++){
        pathx.push_back((float) 0.01*i);
    }

    return pathx;

}


std::vector<float> snake_path_y()
{
    int i;
    std::vector<float> pathy;

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*i);
    }
    for(i=GRID_PTS;i>0;i--){
        pathy.push_back((float) 0.01*GRID_PTS/8);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*GRID_PTS/8 + 0.01*i);
    }
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*GRID_PTS/4);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*GRID_PTS/4+0.01*i);
    }
    for(i=GRID_PTS;i>0;i--){
        pathy.push_back((float) 0.01*GRID_PTS*3/8);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*3*GRID_PTS/8+0.01*i);
    }
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*GRID_PTS/2);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*GRID_PTS/2+0.01*i);
    }
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*5*GRID_PTS/8);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*5*GRID_PTS/8+0.01*i);
    }    
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*6*GRID_PTS/8);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*6*GRID_PTS/8+0.01*i);
    }
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*7*GRID_PTS/8);
    }
    
    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*7*GRID_PTS/8+0.01*i);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathy.push_back((float) 0.01*GRID_PTS);
    }

    for(i=GRID_PTS;i>0;i--){
        pathy.push_back((float) 0.01*i);
    }


    for(i=-GRID_PTS/8;i<GRID_PTS;i++){
        pathy.push_back((float) 0.0);
    }


    return pathy;

}

std::vector<float> snake_path_z()
{
    int i;
    std::vector<float> pathz;
    
    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=GRID_PTS;i>0;i--){
        pathz.push_back((float) -6.0);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=GRID_PTS;i>0;i--){
        pathz.push_back((float) -6.0);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=GRID_PTS;i>0;i--){
        pathz.push_back((float) -6.0);
    }
    
    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=GRID_PTS;i>0;i--){
        pathz.push_back((float) -6.0);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }

    for(i=0;i<GRID_PTS/8;i++){
        pathz.push_back((float) -6.0);
    }

    for(i=GRID_PTS;i>0;i--){
        pathz.push_back((float) -6.0);
    }


    for(i=-GRID_PTS/8;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }


    return pathz;

}

std::vector<float> square_x1() //Square XYZ trajectory. Starts at  x=2.00
{
    int i;
    std::vector<float> pathx; 
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.01*GRID_PTS);
    }
    for(i=GRID_PTS;i>0;i--){
        pathx.push_back((float) 0.01*i);
    }
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.0);
    }
    return pathx;
}

std::vector<float> square_y1() //starts at y=0
{
    int i;
    std::vector<float> pathy; 

    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*i);
    }
    for(i=GRID_PTS;i>0;i--){
        pathy.push_back((float) 0.01*GRID_PTS);
    }
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*GRID_PTS-0.01*i);
    }
    return pathy;
}

std::vector<float> square_z1() //starts at z= -6.0
{
    int i;
    std::vector<float> pathz; 

    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=GRID_PTS;i>0;i--){
        pathz.push_back((float) -6.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }
    return pathz;
}

std::vector<float> square_x() //Square XYZ trajectory
{
    int i;
    std::vector<float> pathx; 
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.01*i);
    }
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.01*GRID_PTS);
    }
    for(i=GRID_PTS;i>0;i--){
        pathx.push_back((float) 0.01*i);
    }
    for(i=0;i<GRID_PTS;i++){
        pathx.push_back((float) 0.0);
    }
    return pathx;
}

std::vector<float> square_y()
{
    int i;
    std::vector<float> pathy; 

    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*i);
    }
    for(i=GRID_PTS;i>0;i--){
        pathy.push_back((float) 0.01*GRID_PTS);
    }
    for(i=0;i<GRID_PTS;i++){
        pathy.push_back((float) 0.01*GRID_PTS-0.01*i);
    }
    return pathy;
}

std::vector<float> square_z()
{
    int i;
    std::vector<float> pathz; 
    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }
    for(i=GRID_PTS;i>0;i--){
        pathz.push_back((float) -6.0);
    }
    for(i=0;i<GRID_PTS;i++){
        pathz.push_back((float) -6.0);
    }
    return pathz;
}

std::vector<float> traj_x(float offset){ //Linear trajectory
    
    int k;

    std::vector<float> pathx; 

    pathx.push_back(offset);

    for(k=1;k<GRID_PTS+1;k++){
        //pathx.push_back(-.5 + (float) 0.01*k);
        pathx.push_back(offset);
    }

    for(k=1;k<GRID_PTS+1;k++){
        pathx.push_back(offset);

    }

    for(k=1;k<GRID_PTS+1;k++){
        //pathx.push_back(.5 - (float) 0.01*k);
        pathx.push_back(offset);
    }    

    return pathx;

}

std::vector<float> traj_y(float offset){
    
    int k;
    int j;

    std::vector<float> pathy; 

    pathy.push_back(offset);

    for(k=1;k<GRID_PTS+1;k++){
        pathy.push_back(offset + (float) 0.01*k);

    }
    j = k;
    for(k=1;k<GRID_PTS+1;k++){
        pathy.push_back(offset+ (float) 0.01*j);

    }

    for(k=1;k<GRID_PTS+1;k++){
        pathy.push_back(offset + 0.01*j -(float) 0.01*k);

    }    

    return pathy;

}

std::vector<float> traj_z(float offset){
    
    int k;

    std::vector<float> pathz; 

    pathz.push_back(offset);

    for(k=1;k<GRID_PTS+1;k++){
        pathz.push_back(offset);

    }
    for(k=1;k<GRID_PTS+1;k++){
        pathz.push_back(offset);

    }
    for(k=1;k<GRID_PTS+1;k++){
        pathz.push_back(offset);

    }    
    return pathz;
}

void Piccolissimo::trans_x (){ //these methods implement the random movement aspect of the main program. These values are sent to the "master_controller"
	if (x_pol>0){
	x_control=0.01;
	} else{
	x_control=-0.01;
	}
}

void Piccolissimo::trans_y (){
	if (y_pol>0){
	y_control=0.01;
	} else{
	y_control=-0.01;
	}
}

void Piccolissimo::trans_z (){
	if (z_pol>0){
	z_control=0.01;
	} else{
	z_control=-0.01;
	}
}

void Piccolissimo::m_trans(string data){ //message transfer
	m_struct.m = data;
}

void Piccolissimo::m_count(){ //message transfer count
	m_struct.m_num++;
}

void Piccolissimo::load_trajx(std::vector<float> data){ //load trajectory x data points
    x_traj = data;
}

void Piccolissimo::load_trajy(std::vector<float> data){ //load trajectory y data points
    y_traj = data;
}

void Piccolissimo::load_trajz(std::vector<float> data){ //load trajectory z points
    z_traj = data;
}

void Piccolissimo::dock(){ //initiate sequence
    type = 0;
    cout<<"DOCK! \n";
}

void Piccolissimo::traj_plan(){ //plan motion update when in trajectory mode

    if(type==2){

        traj_index++;

        if(traj_index==(int) x_traj.size()){
        
        commutate();
        
        } 
        //cout<<"Robot # "<<m_struct.m_index<<"\n";
        //cout << "Trajectory index: " << traj_index << "\n";
        
        x_control = x_traj[traj_index] - x_val;    
        y_control = y_traj[traj_index] - y_val;
        z_control = z_traj[traj_index] - z_val;
        

    }

    if (type == 0) {
        traj_index=0;
    }

/*
    cout << "xyz traj: \n";
    cout << x_traj[traj_index] << "\n";
    cout << y_traj[traj_index] << "\n";
    cout << z_traj[traj_index] << "\n";

    cout << "xyz val: \n";
    cout << x_val<< "\n";
    cout << y_val<< "\n";
    cout << z_val<< "\n";

    cout << "xyz control: \n";
    cout << x_control<< "\n";
    cout << y_control<< "\n";
    cout << z_control << "\n";    */
    
}

void Piccolissimo::init_traj(int index){ //initiate trajectory of robots

    x_val = x_traj[index];
    y_val = y_traj[index];
    z_val = z_traj[index];
    traj_index = index;
    
}

void Piccolissimo::init_dock(float x, float y, float z){

    x_val = x;
    y_val = y;
    z_val = z;
    traj_index = 0;

}


void Piccolissimo::commutate(){ //commutate robots when they reach end of cyclical trajectory

   cout << "COMMUTATE!\n";

    traj_index = 1;

    x_val = x_traj[traj_index];
    y_val = y_traj[traj_index];
    z_val = z_traj[traj_index];
    traj_index--;

   // cout << "yval comm " << y_val << "\n";
    x_control = 0;
    y_control = 0;
    z_control = 0;
}



void Piccolissimo::undock(){ //launch from docking mode
    type = 1;
    cout<<"UNDOCK! \n";

}

void Piccolissimo::trajectory(){//enter trajectory mode
    type = 2;
    cout<<"TRAJECTORY MODE!\n";
}

int Piccolissimo::send_index(){ //send the robot trajectory index for desync

//    cout<<"sent traj index\n";
    return traj_index;

}

void Piccolissimo::slow(){ //slow the robot in trajectory mode 
   
   if (type==2){
    cout<<"SLOWED!!!!!: "<<m_struct.m_index<<"\n";   
    traj_index--;
    x_control = 0;
    y_control = 0;
    z_control = 0;
   }
}


void Piccolissimo::accel(){ //increment trajectory planning
    if (type==2){
        cout<<"ACCEL!!!: "<<m_struct.m_index<<"\n";
        traj_plan();
    }

}


int Piccolissimo::send_index_robot(){ // send the robot index
    return m_struct.m_index;
}


void Piccolissimo::sleep(int tsleep){ //sleep for a specified amount of motion updates, during the landing sequence, for charging

    
    if(type==0){
        count++;
        cout<<"count: "<<count<<"\n";
    }

    if(count==tsleep){
        undock();
        count=0;
    }
}

void Piccolissimo::sense_dock(){ //check trajectory positioning for when to dock

    if(type==2 && traj_index==70){
        dock();
    }
}

void Piccolissimo::construct_desync(){     //initialize robot order and positional arrays

    for(i=0;i<NUM;i++){  
 		score[i] = 0; //These arrays could be internalized into the picolissimo class
		order[i] = -1; //see line above		
    }

    d_forward = 4*GRID_PTS;
    d_back = -4*GRID_PTS;
}

void Piccolissimo::desync_check(){ //check trajectory positioning for when to dock

    if(type==2 && (d_forward+d_back)<-2){  //implement "slow" to achieve desync
        slow();
    }
}

void  Piccolissimo::calculate_delta(int n){

	if(n==order[n]){
			if (score[n]>0 && score[n]<d_forward){ // update the  delta forward and backward variable
			d_forward = score[n]; //these could also be internalized into the class
		} else if (score[n]<0 && score[n]>d_back){
			d_back = score[n];
		}
	}
}

void Piccolissimo::landing(float x, float y, float z){
   
   x_del1 = x-x_val; //create spatial delta
   y_del1 = y-y_val;
   z_del1 = z-z_val;

   if(type==0){
       x_control = 0;
       y_control = 0;
       z_control = 0;
    }

   if ((type == 0) && (x_del1 < -0.01)){ //update control parameters for the robot
       x_control = -0.01;
   } else if((type==0) && (x_del1>0.01)){
       x_control = 0.01;
   }

    if ((type == 0) && (y_del1 < -0.01)){
       y_control = -0.01;
   } else if((type==0) && (y_del1>0.01)){
       y_control = 0.01;
   }

    if ((type == 0) && (z_del1 < -0.01)){
       z_control = -0.01;
   } else if((type==0) && (z_del1>0.01)){
       z_control = 0.01;
   }

    if(((abs(x_del1)+abs(y_del1)+abs(z_del1))<0.01) && type == 0){       
        sleep(1000); //transition to sleep mode - e.g charging
    }


}


void Piccolissimo::launching(float launchx, float launchy, float launchz)
{
   x_del2 = launchx-x_val; //calculate "target" position
   y_del2 = launchy-y_val;
   z_del2 = launchz-z_val;

    if(type==1){
        x_control = 0; //reset control values
        y_control = 0;
        z_control = 0;
        syncflag = 1;
        alpha=0;
    }


   if ((type == 1) && (x_del2 < -0.01)){ //determine appropriate control values
       x_control = -0.01;
   } else if((type==1)&& (x_del2>0.01)){
       x_control = 0.01;
   }

    if ((type == 1) && (y_del2 < -0.01)){
       y_control = -0.01;
   } else if((type==1) && (y_del2>0.01)){
       y_control = 0.01;
   }

    if ((type == 1) && (z_del2 < -0.01)){
       z_control = -0.01;
   } else if((type==1)&& (z_del2>0.01)){
       z_control = 0.01;
   }

    if(((abs(x_del2)+abs(y_del2)+abs(z_del2))<0.03) && type==1){//return to trajectory mode when returning to trajectory
        trajectory(); //hard code the appropriate position?
    }
    
    //z_control = 0;

}

chrono::duration<double> Piccolissimo::timing(chrono::time_point<chrono::system_clock> time_0){

    auto fire = chrono::system_clock::now();
	chrono::duration<double> rcv = fire-time_0;
	cout << "The current clock time is.....     " << rcv.count() << "\n";
    double timef = (double) rcv.count();
    int timed = (int) timef;
    int timedx = (int) 100*timef;
    int time_mod = timedx % 10000;
    //cout << "timef:   " << timef << " timed " << timed << " timedx " << timedx << " time_mod " << time_mod << "\n";
 

    

    return rcv;
}

chrono::duration<double> Piccolissimo::time_traj(chrono::time_point<chrono::system_clock> t0){

    int dt;
    auto fire = chrono::system_clock::now();
    chrono::duration<double> current = fire-t0; 
    double time = (double) current.count();




    int t_scale = (int) 100*time;
    int t_mod  =  t_scale % 10000;
    cout << "robot " << m_struct.m_index  <<" time:   " << time <<"\n";
    // " t_scale " << t_scale << " t_mod " << t_mod << "\n";

    dt = t_mod - t_mod_previous;

    if(dt>0 and dt<5){
        traj_plan();
    }

    t_mod_previous = t_mod;    

    return current;             

}

void Piccolissimo::start_time(){

    start_local = chrono::system_clock::now();
    startflag=1;
    
}

void Piccolissimo::desync_delta(){

    if(before.count() - before_old.count() > .1 && after.count()-after_old.count() > .1 ){ //You only do this once per cycle
        
        delta =  after.count() -before.count();
        delta_current = after.count()-current.count(); // you can use this for the amount of time you break or slow down for

        if (m_struct.m_index == 0){

            delta = 0.0;
            delta_current = 0.0;
        }/*else  if (m_struct.m_index == 0){

            delta=0.1;
        }*/

        before_old = before;
        after_old = after;
        syncflag = 0; //Not synced!

    }


}
int Piccolissimo::send_signal(){

    int signal = 0;

    if(type == 2){
        if(m_struct.m_index==0){
            if ( (   (abs(after.count()-after_old.count())) < 0.1) ){
                signal = 1;
                cout<<"SENT SIGNAL!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
   
            }
        }
        if(m_struct.m_index>0 and abs(delta_current) < 0.1){
           if ( (   (abs(before.count()-before_old.count())) < 0.1) ){
               signal = 1;
               cout<<"SENT SIGNAL!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
  
           }
        }
    }

    return signal;
}



void Piccolissimo::desync_handle(){

    if (type == 2){
        if(startflag==1){
           if (delta_current > 0.1){  
                delta_current -= 0.02*(m_struct.m_index+1)/(alpha);
           }
          
           if (delta_current < -0.1 ){  
                delta_current += 0.02*(m_struct.m_index+1.0)/(alpha);
           }
        }
        
        if (delta_current > 0.1){
            traj_index--;
            x_control=0.0;
            y_control=0.0;
            z_control=0.0;
            cout<<"DECELERATING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        }
        if (delta_current < -0.1 ){
            traj_index--;
            x_control=0.0;
            y_control=0.0;
            z_control=0.0;
            cout<<"DECELERATING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        }
        
        alpha = 0; //reset alpha for next cycle

    }

}



