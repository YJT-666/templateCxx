#include <unistd.h>
#include "../../../include/display/display.h"

int main(){
	Display* dis = new Display();	

	while(1){
		dis->updateFrame();
		usleep(20000);
	}
	delete dis;
	return 0;
}
