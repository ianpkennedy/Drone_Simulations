//command line compile : g++ -g -Wall spheredraw.cpp helper.cpp -o -L/usr/lib -lGL -lGLU -lglut -lGLEW -lglfw -o test1234

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unistd.h>
#include <cstdbool>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include <cmath>
#include <iomanip>
#include <chrono>
#include "helper.h"
//#define NUM 50
#define GRID_PTS 200


using namespace std;

GLdouble radius=0.1; 

Piccolissimo pic_arr[NUM];

chrono::time_point<chrono::system_clock> start;

void display();
void reshape(int x, int y);
void clock(int); //Recursive movement update function
void createSphere(float x,float y,float z); //Sphere generation
void myinit();
void master_control(int i); //master controller that updates each
void master_control_collision(int i); //collision version of master update function
void init_pos(); //Randomizes initial position for randomized movement
void display_data(); //Debugging function that outputs print statements
void  equalize(); //This equalize function fully desynchronizes robots within a specific
void equalize2(); //This function desynchronizes the robot positions, with a landing/launching module. This function desynchronizes regardless of order and


//robot count

int main (int argc, char **argv)
{
	int i;
	srand (static_cast <unsigned> (time(0))); //seed for random position

	//Initialize primaruy trajectory into robot
	for(i=0;i<NUM;i++){
		pic_arr[i].load_trajx(snake_path_x());
		pic_arr[i].load_trajy(snake_path_y());
		pic_arr[i].load_trajz(snake_path_z());
	
		pic_arr[i].x_control = 0;
		pic_arr[i].y_control = 0;
		pic_arr[i].z_control = 0;

		pic_arr[i].x_pol = 1;
		pic_arr[i].y_pol = 1;
		pic_arr[i].z_pol = 1;
//		pic_arr[i].dock(); //Start in trajectory mode

		pic_arr[i].type = -1;
		pic_arr[i].m_struct.m_index = i;
		pic_arr[i].m_struct.m = "alpha";

	}

	//init_pos(); //Initial conditions.modify to be the start of the trajectory vector
	//UNCOMMENT TO START RANDOM MOTION

	for(i=0;i<NUM;i++){ //INITIAL CONDITIONS FOR TRAJECTORY MODE
		pic_arr[i].init_dock(2.0,0,-6.0);
	}

	start = chrono::system_clock::now();
   
    glutInit(&argc, argv);  
    glutInitWindowSize(500,500); //Create window
    glutCreateWindow("Trajectory mode");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    myinit();
    glutTimerFunc(0,clock,0);
    glutMainLoop();        
   
    return 0;
}
void display()
{
    int i;

    glClearColor(1,1,1,1);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // clear the identity matrix.
	
     
    for(i=0;i<NUM;i++){ //Create the robot function
   		createSphere(pic_arr[i].x_val,pic_arr[i].y_val,pic_arr[i].z_val); 
	} 

	glFlush(); 

	glutSwapBuffers();

}

void clock(int){ //Motion update function. It is called recursively

	int i,j;
	string temp;

	glutPostRedisplay();
	glutTimerFunc(30,clock,0); 
	
	//TRAJECTORY MODE PROTOCOL 

	auto current = chrono::system_clock::now();
	chrono::duration<double> delta = current-start;


	cout <<"start:    " << delta.count() <<"\n";

	for(i=0;i<NUM;i++){ //could internalize into the class

		if (delta.count() > 1.0*i + 0.5 ){
			
			pic_arr[i].trajectory();
			

		
		
		}

		if(pic_arr[i].type==2 and pic_arr[i].startflag==0){
//			pic_arr[i].dummy();
			pic_arr[i].start_time();
		}

		if (pic_arr[i].type==2 and pic_arr[i].startflag==1){
			pic_arr[i].time_traj(pic_arr[i].start_local);
		}

		//pic_arr[i].traj_plan(); //removed from the equalize2 function


	} // bring back the commutate function

	for (i=0;i<NUM;i++){master_control(i);}

	cout << " \n";
	//display_data();
	cout << "End of index position update \n \n \n \n \n \n \n";	

}


void equalize2(){

	int i,j;
	string temp;
	
	for(i=0;i<NUM;i++){

		pic_arr[i].traj_plan();
		pic_arr[i].timing(start);
		pic_arr[i].construct_desync();
		
		if ((pic_arr[i].type==2)){
			for(j=0;j<NUM;j++){
				if((j==i) || (pic_arr[j].type!=2)){
					pic_arr[i].order[j] = -2; //omit non applicable cases
				}else{
					pic_arr[i].order[j] = pic_arr[j].send_index_robot();	//build the trajectory arrays
				}
			}

			j=0;

			while(pic_arr[i].order[j]!=-1 && j<NUM){	 //iterate through all other robots in trajectory mode			
				if(pic_arr[i].order[j]!=-2){
					pic_arr[i].score[j] = pic_arr[pic_arr[i].order[j]].send_index()-pic_arr[i].send_index();
					if(pic_arr[i].score[j] > 2*GRID_PTS){ //reorganize for periodicity
						pic_arr[i].score[j] = pic_arr[i].score[j]-4*GRID_PTS;
					} if(pic_arr[i].score[j] < -2*GRID_PTS){
						pic_arr[i].score[j] = pic_arr[i].score[j]+4*GRID_PTS;
					}		
				} 

			/*	if(j==pic_arr[i].order[j]){
					if (pic_arr[i].score[j]>0 && pic_arr[i].score[j]<pic_arr[i].d_forward){ // update the  delta forward and backward variable
						pic_arr[i].d_forward = pic_arr[i].score[j]; //these could also be internalized into the class
					} else if (pic_arr[i].score[j]<0 && pic_arr[i].score[j]>pic_arr[i].d_back){
						pic_arr[i].d_back = pic_arr[i].score[j];
					}
				}*/
				pic_arr[i].calculate_delta(j);
				j++;
			}
		
			cout<<"\n\n\n\n";	
		}
		pic_arr[i].desync_check();
	}
}

void display_data(){ //Debug function - iterate through all the 

	int i;
	cout << "DISPLAY DATA FUNCTION START\n";
	//Output positions and collision scenarios, and other robot class variables
	for (i=0;i<NUM;i++){
		
		cout << std::setprecision(3)<<"x y z control index: "<< i<< "\n" << pic_arr[i].x_control << "\n";
		cout << std::setprecision(3)<<pic_arr[i].y_control << "\n";
		cout<<  std::setprecision(3)<<pic_arr[i].z_control << "\n \n";

		cout <<std::setprecision(3)<< "Pic # "<< i <<" xval: "<<pic_arr[i].x_val << "\n";
		cout << std::setprecision(3)<<"Pic # "<< i <<" yval: " <<pic_arr[i].y_val << "\n";
		cout << std::setprecision(3)<<"Pic # "<< i <<" zval: " <<pic_arr[i].z_val << "\n";
		cout << std::setprecision(3)<<"Pic # " << i << " "<< pic_arr[i].m_struct.m << " Pic message index: " <<pic_arr[i].m_struct.m_index << "\n";
		cout << std::setprecision(3)<<"Pic transfer count " << pic_arr[i].m_struct.m_num << "\n";
		cout<< "Pic # " << i <<  " Type " << pic_arr[i].type<<"\n";
		cout << "delta  " << pic_arr[i].delta << "  alpha  " << pic_arr[i].alpha << " \n";
		cout << "delta current " << pic_arr[i].delta_current << " \n";
		cout << "syncflag  " << pic_arr[i].syncflag << "\n";
		cout << " pic " << i << "  type " << pic_arr[i].type << "  before " <<pic_arr[i].before.count() << " after " <<  pic_arr[i].after.count() << " current " << pic_arr[i].current.count() << "\n";
		cout << "  before old  " << pic_arr[i].before_old.count() << "  after old  " << pic_arr[i].after_old.count() << "\n";
		cout << "traj index " << pic_arr[i].traj_index << "\n";
		cout << "pic start flag  " << pic_arr[i].startflag << "\n";

		cout << "\n \n";

	}
	cout<< "DISPLAY DATA FUNCTION END \n";
}


void createSphere(float x,float y,float z){ //Generate sphere

    glLoadIdentity();
	gluLookAt(1,2,2.5,1,2,-4.6,0,1,0);  //View point
    
	
	//gluLookAt(12,3,0,0,0,-6,0,1,0);
	
	glTranslatef(x,y,z);

    //Draw sphere 
    glutSolidSphere(radius,20,20);
    // Flush buffers to screen
	
}

void reshape(int x, int y)
{
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);

    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void myinit(){
	//GLfloat mat1[]={0.5,1.0,1.0}; //Shading
	//GLfloat mat2[]={50.0};
	//GLfloat light[]={1.0,0.5,1.0,0.0};
	
	//glMaterialfv(GL_FRONT,GL_SPECULAR,mat1);
	//glMaterialfv(GL_FRONT,GL_SHININESS,mat2);
	//glLightfv(GL_LIGHT0,GL_POSITION,light);
	
	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	//glDisable(GL_TEXTURE_2D);

}

void master_control(int i){ //Master control update function


	pic_arr[i].x_val+=pic_arr[i].x_control;
	pic_arr[i].y_val+=pic_arr[i].y_control;
	pic_arr[i].z_val+=pic_arr[i].z_control;
	
	
}

void master_control_collision(int i){ //Collision version of position update function

	pic_arr[i].x_val+=5*pic_arr[i].x_control;
	pic_arr[i].y_val+=5*pic_arr[i].y_control;
	pic_arr[i].z_val+=5*pic_arr[i].z_control;

}

void init_pos(){

	int i;

	for (i=0; i<NUM;i++) //Generate random initial conditions
	{
	float x = -1.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(2.0))); //initial position -> randomized
	float y = -1.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(2.0)));
	float z = -7.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(2.0)));

	float ux; //control effort
	float uy;
	float uz;

	int polx=0; //polarity
	int poly=0;
	int polz=0;

	while (polx==0 ){ //Randomized directional polarity
		polx = rand() % 3 - 1;
	}

	while (poly==0 ){
		poly = rand() % 3 - 1;
	}

	while (polz==0 ){
		polz = rand() % 3 - 1;
	}
	

	ux = (float) 0.01*polx; //initialize control effort
	uy = (float) 0.01*poly;
	uz = (float) 0.01*polz;

	pic_arr[i].x_val = x; //initialize position
	pic_arr[i].y_val = y;
	pic_arr[i].z_val = z;
	pic_arr[i].m_struct.m_index = i;

	pic_arr[i].x_control = ux; //initialize control effort 
	pic_arr[i].y_control = uy;
	pic_arr[i].z_control = uz;

	pic_arr[i].x_pol = polx; //intialize polarity
	pic_arr[i].y_pol = poly;
	pic_arr[i].z_pol = polz;

	}

	pic_arr[0].m_struct.m = "alpha"; //set up message passing structure data
	pic_arr[1].m_struct.m = "beta";
	pic_arr[2].m_struct.m = "gamma";
	pic_arr[3].m_struct.m = "delta"; 

}

void equalize(){ //The new and improved will calculate all delta of robots within trajectory mode, and then
//it will select the 2 smallest deltas  and run the "slow" based off of that. 

	int i,j,k;
	int delta,delta1,delta2; //positional deltas
	string temp;

	for(i=0;i<NUM;i++){
		pic_arr[i].traj_plan(); //update trajectory plan control effort
		if (pic_arr[i].type==2){
		    cout<< "pic "<<i<<" type: "<<pic_arr[i].type<<" \n";

			if(i==0){ //boundary case

				j = NUM-1;

				while (pic_arr[j].type!=2){
					j--;
					if (j<0){j=NUM-1;}
				}	
				k = 1;
				while (pic_arr[k].type!=2){
					k++;
					if(k>NUM-1){k=0;}
				}	
			}else if(i==NUM-1){ //boundary case
				j = NUM-2;
				while (pic_arr[j].type!=2){
					j--;
					if (j<0){j=NUM-1;}
				}				
				k = 0;
				while (pic_arr[k].type!=2){
					k++;
					if(k>NUM-1){k=0;}
				}				
			}else{
				j = i-1;
				while (pic_arr[j].type!=2){
					j--;
					if (j<0){j=NUM-1;}
				}
				k = i+1;
				while (pic_arr[k].type!=2){
					k++;
					if(k>NUM-1){k=0;}
				}
			}	
			delta1 = abs(pic_arr[k].send_index() - pic_arr[i].send_index()); //calculate the forward and backward positional deltas
			delta2 = abs(pic_arr[i].send_index() - pic_arr[j].send_index());

			//you can deal within going below 0 with indices, by "shifting" so that you get the real delta
			
			delta = delta1-delta2; //calculate net difference
			
			if(delta<0 && delta>-400){
				pic_arr[i].slow(); //slow trajectory planning update if out of sync
			}
			cout<<"Equalize..."<<"PIC "<< i<<" " << "delta " << delta<< "\n";
			cout << "Pic " << i << "\n";}
		/*
		if(pic_arr[i].y_val == pic_arr[i+1].y_val){ //Transfer data based off of vertical positioning
			temp = pic_arr[i].m_struct.m;
			pic_arr[i].m_trans(pic_arr[i+1].m_struct.m);
			pic_arr[i].m_count();
			pic_arr[i+1].m_trans(temp);
			pic_arr[i+1].m_count();
		}*/

	}
}

//I think that what he meany was a t


//Sources and Useful Ressources:
/*Computer Graphics Programming in OpenGL with C++
https://www.codemiles.com/c-opengl-examples/draw-a-solid-sphere-using-opengl-t9008.html?mobile=desktop
https://www.youtube.com/watch?v=NT-0Q2Psp2Y
www.tutorialspoint.com/cplusplus/
cplusplus.com/reference/valawway/sqrt/
https://community.khronos.org/t/glulookat-usage/71373
https://www.google.com/search?q=glulookat+default+values&oq=glulookat+defau&aqs=chrome.1.69i57j0i22i30.5779j0j7&sourceid=chrome&ie=UTF-8
https://www.programmersought.com/article/78621108436/
http://www.lighthouse3d.com/tutorials/glut-tutorial/keyboard-example-moving-around-the-world/
https://www.gamedev.net/forums/topic/65364-how-to-use-glulookat/
https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluLookAt.xml
https://www.cplusplus.com/doc/tutorial/classes/
https://tutorialink.com/cpp/array-of-objects-in-cpp.cpp
https://www.geeksforgeeks.org/c-classes-and-objects/
https://stackoverflow.com/questions/686353/random-float-number-generation
https://en.cppreference.com/w/cpp/numeric/random/RAND_MAX
https://www.w3schools.com/cpp/cpp_constructors.asp
https://www.w3schools.com/cpp/cpp_data_types_string.asp
https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
https://www.geeksforgeeks.org/vector-in-cpp-stl/
https://www.geeksforgeeks.org/advantages-of-vector-over-array-in-c/
https://stackoverflow.com/questions/8403468/error-vector-does-not-name-a-type/8403491
https://www.softwaretestinghelp.com/cpp-sleep/
https://stackoverflow.com/questions/11507607/c-expected-primary-expression-before/11507659
https://www.cplusplus.com/doc/tutorial/structures/
https://www.geeksforgeeks.org/chrono-in-c/
https://stackoverflow.com/questions/37701323/extern-auto-variable-has-no-initializer
https://stackoverflow.com/questions/18668570/opengl-flickering-while-rendering-multiple-objects
*/


	/*for(i=0;i<NUM;i++){
		pic_arr[i].traj_plan();
		if (pic_arr[i].type==2){
		    cout<< "pic "<<i<<" type: "<<pic_arr[i].type<<" \n";
			if(i==0){
				j = NUM-1;
				while (pic_arr[j].type!=2){
					j--;
					if (j<0){j=NUM-1;}
				}	
				k = 1;
				while (pic_arr[k].type!=2){
					k++;
					if(k>NUM-1){k=0;}
				}	
			}else if(i==NUM-1){
				j = NUM-2;
				while (pic_arr[j].type!=2){
					j--;
					if (j<0){j=NUM-1;}
				}				
				k = 0;
				while (pic_arr[k].type!=2){
					k++;
					if(k>NUM-1){k=0;}
				}				
			}else{
				j = i-1;
				while (pic_arr[j].type!=2){
					j--;
					if (j<0){j=NUM-1;}
				}
				k = i+1;
				while (pic_arr[k].type!=2){
					k++;
					if(k>NUM-1){k=0;}
				}
			}	
			delta1 = abs(pic_arr[k].send_index() - pic_arr[i].send_index());
			delta2 = abs(pic_arr[i].send_index() - pic_arr[j].send_index());
			//you can deal within going below 0 with indices, by "shifting" so that you get the real delta
			delta = delta1-delta2;
			if(delta<0 && delta>-400){
				pic_arr[i].slow();
			}
			cout<<"Equalize..."<<"PIC "<< i<<" " << "delta " << delta<< "\n";
			cout << "Pic " << i << "\n";}
		
		if(pic_arr[i].y_val == pic_arr[i+1].y_val){
			temp = pic_arr[i].m_struct.m;
			pic_arr[i].m_trans(pic_arr[i+1].m_struct.m);
			pic_arr[i].m_count();
			pic_arr[i+1].m_trans(temp);
			pic_arr[i+1].m_count();
		}
	}*/


	/*if((abs(score[j])<delta1) && (abs(score[j])<delta2)){
					delta1 = score[j];
				} else if((abs(score[j]) < delta1) && (abs(score[j]) > delta2)){
					delta1 = score[j];
				}  else if ((abs(score[j]) > delta1) && (abs(score[j]) < delta2)){
					delta2 = score[j];
				}*/

						 /*	if(delta2<delta1){
				dtemp=delta1;
				delta1=delta2;
				delta2=dtemp; (4*GRID_PTS/(m+1))-1>d_forward
			}*/
			//delta  = delta2+delta1;


 		 //	if( ((4*GRID_PTS/(m+1))-5)>d_forward || ((4*GRID_PTS/(m+1))+5)<d_forward ){
 		 //		pic_arr[i].accel();
		 //	}

		 	//Random Motion:
	/*for(i=0;i<NUM;i++){ //Movement algorithm
		for(j=i+1;j<NUM;j++){	// Robot checking for other instances within a certain range
			if (sqrt((pic_arr[i].x_val-pic_arr[j].x_val)*(pic_arr[i].x_val-pic_arr[j].x_val) + (pic_arr[i].y_val-pic_arr[j].y_val)*(pic_arr[i].y_val-pic_arr[j].y_val) + (pic_arr[i].z_val-pic_arr[j].z_val)*(pic_arr[i].z_val-pic_arr[j].z_val))<2*radius){
				
				cout << "enter collision protocol \n";	

				pic_arr[i].x_pol = -pic_arr[i].x_pol; //Prepare for robots to switch directions
				pic_arr[i].y_pol = -pic_arr[i].y_pol;
				pic_arr[i].z_pol = -pic_arr[i].z_pol;

				pic_arr[j].x_pol = -pic_arr[j].x_pol;
				pic_arr[j].y_pol = -pic_arr[j].y_pol;
				pic_arr[j].z_pol = -pic_arr[j].z_pol;

				pic_arr[j].trans_x(); //Control effort
				pic_arr[j].trans_y();
				pic_arr[j].trans_z();
				master_control_collision(j);

				pic_arr[i].trans_x(); //Control effort
				pic_arr[i].trans_y();
				pic_arr[i].trans_z();

				temp = pic_arr[i].m_struct.m;
				pic_arr[i].m_trans(pic_arr[j].m_struct.m);
				pic_arr[i].m_count();

				pic_arr[j].m_trans(temp);
				pic_arr[j].m_count();
				master_control_collision(i);

				cout << "COLLISION \nCOLLISION \n \n \n";
			}
		}	
	}*/
	
	/*
	for(i=0;i<NUM;i++){ //switch directions at limits 
		
		if(pic_arr[i].x_val>1.0){
		pic_arr[i].x_pol = -pic_arr[i].x_pol; 
		}
		if(pic_arr[i].x_val<-1.0){
		pic_arr[i].x_pol = -pic_arr[i].x_pol;
		}
		if(pic_arr[i].y_val>1.0){
		pic_arr[i].y_pol = -pic_arr[i].y_pol;
		}
		if(pic_arr[i].y_val<-1.0){
		pic_arr[i].y_pol = -pic_arr[i].y_pol;
		}
		if(pic_arr[i].z_val>-5.0){
		pic_arr[i].z_pol = -pic_arr[i].z_pol;
		}
		if(pic_arr[i].z_val<-7.0){
		pic_arr[i].z_pol = -pic_arr[i].z_pol;
		}
		// DEFAULT RANDOM MOVEMENT - UNCOMMENT TO REVERT TO RANDOOM MOTION
		//pic_arr[i].trans_x(); //Control effort
		//pic_arr[i].trans_y();
		//pic_arr[i].trans_z();
		//master_control(i); //Movement	
	}	*/