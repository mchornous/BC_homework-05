
#include "port.h"
#include "vintage_port.h"

#include <iostream>


int main() {
	Port p("brand", "style", 1);
	Port p2("brand2", "style2", 2);
	Port p3("brand3", "style3", 3);
	Port copyPort(p);
	p2 = p3;
//	copyPort = p;
	const Port& copyPort2= p;
	p3+=5;
	p3-= 2;
	p2.Show();
	std::cout << p3;

	VintagePort vp();
	const char* brand = "Port";
	const char* nn = "The Noble";
	VintagePort vp_init(brand, 1, nn, 5);
	VintagePort vp_copy(vp_init);
	Port port = vp_copy;
	Port&  rp = vp_init;
	rp.Show();
	Port*  pp = &vp_init;
	pp->Show();
	vp_copy.Show();
	vp_init.Show();
	vp_copy.Show();
    port.Show();
	VintagePort vp_a();
	vp_init = vp_copy;
		std::cout << vp_init;

}
