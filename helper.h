#include <vector>
#include <cstdio>
#include <string>
#include <chrono>
//#define NUM 50

using namespace std;	


class Piccolissimo { //Robot class

	public:
	float x_val,y_val,z_val; //robot positions
	float x_control,y_control,z_control; //control values for positional updates
	int x_pol,y_pol,z_pol; //polarity parameters
	int type,count=0; //robot type (trjectory, dock, etc...), count for "sleeping"
    int score[NUM]; //desync arrays
	int order[NUM];
	int i,j; //looping variables
	int syncflag = 1;
	int startflag = 0;
	int alpha = 0;
	int d_forward,d_back; //equalizing algorithm variables 
	float x_del1,y_del1,z_del1;
	float x_del2,y_del2,z_del2;
	double delta = 0.0, delta_current=0.0;
	int t_mod_previous=0;


	struct message{ //message passing structure
		int m_num;
		int m_index;
		string m;

	};
	message m_struct;
	
//	string m;
//	int m_num, m_index; 
	int traj_index; //trajectory index
	std::vector<float> x_traj; //trajectory variables
    std::vector<float> y_traj;
	std::vector<float> z_traj;


	chrono::duration<double> before = (std::chrono::duration<double>) 0.0;
	chrono::duration<double> after = (std::chrono::duration<double>) 0.0;
	chrono::duration<double> before_old = (std::chrono::duration<double>) 0.0;
	chrono::duration<double> after_old = (std::chrono::duration<double>) 0.0;
	chrono::duration<double>  current = (std::chrono::duration<double>) 0.0;
	//chrono::duration<double>  start_local = (std::chrono::duration<double>) 0.0;
	chrono::time_point<chrono::system_clock> start_local;


	void trans_x();
	void trans_y();
	void trans_z(); //translate methods
	void m_trans(string data); //string data transfers
	void m_count(); //message count tracking
	void load_trajx(std::vector<float> data); //loading trajectories
    void load_trajy(std::vector<float> data);
    void load_trajz(std::vector<float> data);
    void traj_plan(); //trajectory planning updates
    void init_traj(int index); //initial trajectory conditions
	void commutate(); //reset cyclical trajectory
	void dock(); //docking mode
	void undock(); //launching to trajectory
	void trajectory(); //trajectory mode
	int send_index(); //send trajectory index
	int send_index_robot();  //send robot index
	void slow(); //slowing desync method
	void accel(); //speed up desync method
	void sleep(int tsleep); //sleep mode
	void sense_dock(); //determine whether to dock
	void construct_desync(); //construct arrays
	void desync_check(); //check whether robots are out of sync
	void calculate_delta(int n); //determine forward backward index delta difference
	void landing(float x, float y, float z); //land robot 
	void launching(float launchx, float launchy, float launchz); //relaunch the robot
	chrono::duration<double> timing(chrono::time_point<chrono::system_clock> time_0);
	void init_dock(float x, float y, float z);
	void desync_delta();
	void desync_handle();
	int send_signal();
	chrono::duration<double> time_traj(chrono::time_point<chrono::system_clock> t0);
	void start_time();



};

std::vector<float> traj_x(float offset); //Trajectory generation
std::vector<float> traj_y(float offset); //Trajectory generation
std::vector<float> traj_z(float offset); //Trajectory generation

std::vector<float> square_x(); //Square generation
std::vector<float> square_y(); //Square generation
std::vector<float> square_z(); //Square generation


//Square  without bottom side
std::vector<float> square_x1();
std::vector<float> square_y1();
std::vector<float> square_z1();

//Updated bath
std::vector<float> snake_path_x();
std::vector<float> snake_path_y();
std::vector<float> snake_path_z();