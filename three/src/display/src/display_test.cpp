#include "../../../include/funcTest.h"
#include "../../../include/display/display.h"


int t_plane(){
	
	Display* dis = new Display();

	while(1){
		dis->updateFrame();
		usleep(20000);
	}
	delete dis;
	return 0;
}

int main(int argc, char* argv[]){
	FuncTest ft;
	
	// add function
	ADD_TEST_FUN(ft, t_plane);


	int pass_count=0;
	if (argc == 1){
		// test all module
		pass_count =  ft.testRun();
	}else{
		for (int i=1; i < argc; i++){
			std::cout << "running function: " << argv[i] << " ..." << std::endl;
			int r = ft.selectTestFunRun(argv[i]);
			if (r==0) pass_count++;
		}
	}
	std::cout << "total:" << ft.numOfTestFun() <<" " << "pass:" << pass_count << std::endl;

	return 0;
}
